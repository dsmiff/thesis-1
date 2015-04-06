import ROOT as r

f_asymp = r.TFile.Open("CLs_asymptotic_T2cc_2012dev_0b_le3j_0b_ge4j_1b_ge4j_1b_le3j_xsLimit_relative.root")
f_toys = r.TFile.Open("500toys/CLs_frequentist_T2cc_2012dev_0b_le3j_0b_ge4j_1b_ge4j_1b_le3j_xsLimit_relative.root")

h_asymp = f_asymp.Get("ExpectedUpperLimit_relative")
h_toys = f_toys.Get("ExpectedUpperLimit_relative")

h_test = h_toys.Clone()
h_toys.Divide(h_asymp)

canv = r.TCanvas()

h_toys.Draw("colztext")

canv.Print("out_limit_test.pdf")