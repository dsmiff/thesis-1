{
//=========Macro generated from canvas: Yields/Yields
//=========  (Wed Apr  2 22:56:40 2014) by ROOT version5.34/09
   TCanvas *Yields = new TCanvas("Yields", "Yields",1,1,900,576);
   gStyle->SetOptFit(1);
   Yields->SetHighLightColor(2);
   Yields->Range(75.79687,-1.25,1297.828,1.25);
   Yields->SetFillColor(0);
   Yields->SetBorderMode(0);
   Yields->SetBorderSize(2);
   Yields->SetTickx(1);
   Yields->SetTicky(1);
   Yields->SetFrameBorderMode(0);
   Yields->SetFrameBorderMode(0);
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(12);
   grae->SetName("Graph");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(3);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(1.5);
   grae->SetPoint(0,0,0);
   grae->SetPointError(0,0,0,0,0);
   grae->SetPoint(1,237.5,0.02531871);
   grae->SetPointError(1,0,0,0.06676014,0.06676014);
   grae->SetPoint(2,300,0.01031051);
   grae->SetPointError(2,0,0,0.03606425,0.03606425);
   grae->SetPoint(3,350,-0.1239197);
   grae->SetPointError(3,0,0,0.04906054,0.04906054);
   grae->SetPoint(4,425,-0.0496284);
   grae->SetPointError(4,0,0,0.0472417,0.0472417);
//   grae->SetPoint(5,525,0.06473905);
//   grae->SetPointError(5,0,0,0.05688366,0.05688366);
//   grae->SetPoint(6,625,-0.3221987);
//   grae->SetPointError(6,0,0,0.07301564,0.07301564);
//   grae->SetPoint(7,725,-0.1357763);
//   grae->SetPointError(7,0,0,0.1052051,0.1052051);
//   grae->SetPoint(8,825,-0.2590461);
//   grae->SetPointError(8,0,0,0.1409663,0.1409663);
//   grae->SetPoint(9,925,-0.2966973);
//   grae->SetPointError(9,0,0,0.1844283,0.1844283);
//   grae->SetPoint(10,1025,-0.1660279);
//   grae->SetPointError(10,0,0,0.2543967,0.2543967);
//   grae->SetPoint(11,1125,-0.3909427);
//   grae->SetPointError(11,0,0,0.2324808,0.2324808);
   grae->SetPoint(5,550,-0.08140);
   grae->SetPointError(5,0,0,0.18759,0.18759);
   grae->SetPoint(6,725,-0.1357763);
   grae->SetPointError(6,0,0,0.1052051,0.1052051);
   grae->SetPoint(7,825,-0.2590461);
   grae->SetPointError(7,0,0,0.1409663,0.1409663);
   grae->SetPoint(8,925,-0.2966973);
   grae->SetPointError(8,0,0,0.1844283,0.1844283);
   grae->SetPoint(9,1025,-0.1660279);
   grae->SetPointError(9,0,0,0.2543967,0.2543967);
   grae->SetPoint(10,1125,-0.3909427);
   grae->SetPointError(10,0,0,0.2324808,0.2324808);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","",100,0,1237.5);
   Graph_Graph6->SetMinimum(-1);
   Graph_Graph6->SetMaximum(1);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetTitle("H_{T} (GeV)");
   Graph_Graph6->GetXaxis()->SetRange(17,95);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelOffset(0.01);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetTitle("(N_{obs} - N_{pred}) / N_{pred}");
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelOffset(0.01);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelOffset(0.01);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph6);
   
   
   TF1 *fit = new TF1("fit","pol0",200,1175);
   fit->SetFillColor(19);
   fit->SetFillStyle(0);
   fit->SetLineColor(2);
   fit->SetLineWidth(2);
   fit->SetChisquare(31.21141);
   fit->SetNDF(10);
   fit->GetXaxis()->SetLabelFont(42);
   fit->GetXaxis()->SetLabelOffset(0.01);
   fit->GetXaxis()->SetLabelSize(0.05);
   fit->GetXaxis()->SetTitleSize(0.06);
   fit->GetXaxis()->SetTitleFont(42);
   fit->GetYaxis()->SetLabelFont(42);
   fit->GetYaxis()->SetLabelOffset(0.01);
   fit->GetYaxis()->SetLabelSize(0.05);
   fit->GetYaxis()->SetTitleSize(0.035);
   fit->GetYaxis()->SetTitleFont(42);
   fit->SetParameter(0,-0.0564502);
   fit->SetParError(0,0.01977423);
   fit->SetParLimits(0,0,0);
   grae->GetListOfFunctions()->Add(fit);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.815,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("#chi^{2} / ndf = 31.21 / 10");
   text = ptstats->AddText("p0       = -0.05645 #pm 0.01977 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   grae->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(grae->GetListOfFunctions());
   grae->Draw("ap");
   
   TF1 *fit = new TF1("fit","pol0",200,1175);
   fit->SetFillColor(19);
   fit->SetFillStyle(0);
   fit->SetLineColor(2);
   fit->SetLineWidth(2);
   fit->SetChisquare(31.21141);
   fit->SetNDF(10);
   fit->GetXaxis()->SetLabelFont(42);
   fit->GetXaxis()->SetLabelOffset(0.01);
   fit->GetXaxis()->SetLabelSize(0.05);
   fit->GetXaxis()->SetTitleSize(0.06);
   fit->GetXaxis()->SetTitleFont(42);
   fit->GetYaxis()->SetLabelFont(42);
   fit->GetYaxis()->SetLabelOffset(0.01);
   fit->GetYaxis()->SetLabelSize(0.05);
   fit->GetYaxis()->SetTitleSize(0.035);
   fit->GetYaxis()->SetTitleFont(42);
   fit->SetParameter(0,-0.0564502);
   fit->SetParError(0,0.01977423);
   fit->SetParLimits(0,0,0);
   fit->Draw("SAME");
      tex = new TLatex(0.12,0.84,"CMS, 18.493 fb^{-1}, #sqrt{s} = 8 TeV");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TPaveText *pt = new TPaveText(0.12,0.9,0.5,0.95,"blNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetTextSize(0.04);
   text = pt->AddText("#mu + jets (0-b-tag) #rightarrow #mu + jets (1-b-tag) (no #alpha_{T})");
   pt->Draw();
   Yields->Modified();
   Yields->cd();
   Yields->SetSelected(Yields);
}
