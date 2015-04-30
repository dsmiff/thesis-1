import ROOT as r
import numpy as np

r.gROOT.SetBatch(0)
r.gStyle.SetOptStat(0)

def hist_params():
    return 200, 0, 10.

def make_pdfs():
    mean = 0.5
    sigma = 0.7

    hbg = r.TH1D("bg", "bg", *hist_params())
    hsg = r.TH1D("sg", "sg", *hist_params())
    for i in range(50000):
        hbg.Fill(np.random.lognormal(mean, sigma))
        hsg.Fill(np.random.lognormal(mean, 1.4*sigma)+1.7)

    return hbg, hsg

def make_expected(bkg = None, sig = None):
    
    vals = []
    for i in range(1, bkg.GetNbinsX()+1):
        num = bkg.GetBinContent(i)
        cent = bkg.GetBinCenter(i)
        for i in range(int(num)):
            vals.append(cent)

    valsarray = np.array(vals)
    median = np.median(valsarray)
    quantiles = [np.percentile(valsarray, 32.), np.percentile(valsarray, 68.)]

    exp = bkg.Clone()
    expvals = bkg.Clone()
    for i in range(1, exp.GetNbinsX()+1):
        cent = exp.GetBinCenter(i)
        if i != exp.FindBin(median): exp.SetBinContent(i, 0.)
        if cent < quantiles[0]: expvals.SetBinContent(i, 0.)
        if cent > quantiles[1]: expvals.SetBinContent(i, 0.)

    return exp, expvals

def make_observed(bkg = None, sig = None):
    obsval = 2.

    obs = r.TH1D("obs", "obs", *hist_params())

    obs.Fill(obsval, 1.2*bkg.GetBinContent(bkg.FindBin(obsval)))

    bkgobs = bkg.Clone()
    sigobs = sig.Clone()

    for i in range(1, bkgobs.GetNbinsX()+1):
        if i < bkgobs.FindBin(obsval):
            bkgobs.SetBinContent(i, 0.)
        if i > sigobs.FindBin(obsval):
            sigobs.SetBinContent(i, 0.)

    return obs, bkgobs, sigobs

def main():

    mode = ["expected", "observed"][1]

    hbg, hsg = make_pdfs()

    canv = r.TCanvas()

    lg = r.TLegend(0.6, 0.64, 0.89, 0.89)

    hbg.Draw("hist")
    hbg.SetLineColor(r.kBlue)
    hbg.SetLineWidth(2)
    lg.AddEntry(hbg, "P(q_{#mu}  | b only)", "L")

    hbg.SetTitle("")
    hbg.GetXaxis().SetTitle("q_{#mu}")
    hbg.GetYaxis().SetTitle("Counts")

    hsg.Draw("histsame")
    hsg.SetLineColor(r.kOrange+2)
    hsg.SetLineWidth(2)
    lg.AddEntry(hsg, "P(q_{#mu}  | b+s only)", "L")

    if mode == "expected":
        hexp, hexprange = make_expected(bkg = hbg)

        hexprange.Draw("histsame")
        hexprange.SetFillColor(r.kViolet)
        hexprange.SetLineColor(r.kViolet)
        hexprange.SetMarkerColor(r.kViolet)
        hexprange.SetFillStyle(3001)
        # hexprange.SetFillColorAlpha(r.kViolet, 0.5)
        hexprange.SetLineStyle(2)
        lg.AddEntry(hexprange, "68%% prob bands")

        hexp.Draw("histsame")
        hexp.SetFillColor(r.kViolet+1)
        hexp.SetLineColor(r.kViolet+1)
        hexp.SetMarkerColor(r.kViolet+1)
        lg.AddEntry(hexp, "Median expected q_{#mu}")

        lg.Draw()
        lg.SetLineColor(0)
        lg.SetFillColor(0)

        canv.Print("tmp_exp.pdf")

    if mode == "observed":
        hobs, hbkgobs, hsigobs = make_observed(bkg = hbg, sig = hsg)
        
        lg.Clear()

        hbkgobs.Draw("histsame")
        hbkgobs.SetFillColor(r.kBlue)
        hbkgobs.SetLineColor(r.kBlue)
        hbkgobs.SetFillStyle(3001)
        # hbkgobs.SetLineStyle(2)
        lg.AddEntry(hbkgobs, "1-CL_{b}", "L")

        hsigobs.Draw("histsame")
        hsigobs.SetFillColor(r.kOrange+2)
        hsigobs.SetLineColor(r.kOrange+2)
        hsigobs.SetFillStyle(3001)
        # hsigobs.SetLineStyle(2)
        lg.AddEntry(hsigobs, "CL_{sb}", "L")

        hobs.Draw("histsame")
        hobs.SetLineColor(r.kBlack)
        # hobs.SetFillColor(r.kBlack)
        hobs.SetLineWidth(3)
        lg.AddEntry(hobs, "q_{#mu}  observed")

        lg.Draw()
        lg.SetLineColor(0)
        lg.SetFillColor(0)

        canv.Print("tmp_obs.pdf")

if __name__ == "__main__":
    main()



