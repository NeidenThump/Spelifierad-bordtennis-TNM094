#include "About.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/listctrl.h>

About::About(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	auto panel = new wxScrolled<wxPanel>(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));
	panel->SetScrollRate(0, FromDIP(10));

	//To scroll
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// Load bitmap image - logga
	wxBitmap logga(wxT("../Spelifierad-bordtennis-TNM094/bilder/projection_pong.bmp"), wxBITMAP_TYPE_BMP);
	wxImage logga_bitmap = logga.ConvertToImage();
	// Resize image, original; 794 1123
	logga_bitmap = logga_bitmap.Scale(150, 150, wxIMAGE_QUALITY_HIGH);

	// Create a static bitmap control and set the bitmap
	wxBitmapButton* logga_button = new wxBitmapButton(panel, wxID_ANY, logga_bitmap, wxPoint(25, 0), wxDefaultSize, wxBORDER_NONE);
	logga_button->Bind(wxEVT_BUTTON, &About::OnBackClicked, this);
	logga_button->Bind(wxEVT_ENTER_WINDOW, &About::OnMouseEnter, this);
	logga_button->Bind(wxEVT_LEAVE_WINDOW, &About::OnMouseLeave, this);
	sizer->Add(logga_button);
	 
	//Text om Spelet
	//rubrik
	wxStaticText* OmSpelet = new wxStaticText(panel, wxID_ANY, "Om spelet", wxDefaultPosition, wxSize(300, 50), wxALIGN_CENTER);
	OmSpelet->SetBackgroundColour(wxColor(38, 97, 153, 100));
	OmSpelet->SetFont(wxFont(wxFontInfo(24).Bold()));
	sizer->Add(OmSpelet, 0, wxALIGN_CENTRE, FromDIP(10));

	//text
	wxString SpeletsSyfte = "ProjectionPong är ett spel som har skapats i kursen Medietekniskt kandidatprojekt, TNM094, vilken ges vid Linköpings universitet. Spelet har som syfte, att underlätta bordtennisträning på ett innovativt sätt.";
	wxStaticText* SpeletsSyfte_Static = new wxStaticText(panel, wxID_ANY, SpeletsSyfte, wxDefaultPosition, wxSize(650, 200), wxALIGN_CENTER);
	SpeletsSyfte_Static->SetBackgroundColour(wxColor(38, 97, 153, 100));
	SpeletsSyfte_Static->SetFont(wxFont(wxFontInfo(14).Family(wxFONTFAMILY_SCRIPT)));
	sizer->Add(SpeletsSyfte_Static, 0, wxALIGN_CENTRE, FromDIP(10));

	//Instruntioner om hur man spelar
	//rubrik
	wxStaticText* How_play = new wxStaticText(panel, wxID_ANY, "Såhär spelar du", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	How_play->SetBackgroundColour(wxColor(38, 97, 153, 100));
	How_play->SetFont(wxFont(wxFontInfo(24).Bold()));
	sizer->Add(How_play, 0, wxALIGN_CENTRE, FromDIP(10));

	//text
	wxString Instruktioner = "Se till att mikrofonerna står utplacerade vid bordets hörn och att projektorn är positionerad fyra meter över bordet. Sätt på roboten, mikrofonerna och projektorn. Tryck på startknappen vid applikationens startsida. Projektorn kommer att projicera måltavlor på bordet, och det är spelrens uppgift att träffa dessa med pingisbollar. Men se upp, om du missar 15 gånger i rad är det game over! Lycka till!";
	wxStaticText* Instruktioner_Static = new wxStaticText(panel, wxID_ANY, Instruktioner, wxDefaultPosition, wxSize(650, 200), wxALIGN_CENTER);
	Instruktioner_Static->SetBackgroundColour(wxColor(38, 97, 153, 100));
	Instruktioner_Static->SetFont(wxFont(wxFontInfo(14).Family(wxFONTFAMILY_SCRIPT)));
	sizer->Add(Instruktioner_Static, 0, wxALIGN_CENTRE, FromDIP(10));

	//Information om oss och kontaktuppgifter
	//rubrik
	wxStaticText* Om_oss = new wxStaticText(panel, wxID_ANY, "Vi som har gjort spelet", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
	Om_oss->SetBackgroundColour(wxColor(38, 97, 153, 100));
	Om_oss->SetFont(wxFont(wxFontInfo(24).Bold()));
	sizer->Add(Om_oss, 0, wxALIGN_CENTRE, FromDIP(10));

	//text
	wxString Info = "Här ska det stå lite info om oss och kontaktuppgifter. Vi vill tacka Peter Westerdahl för hjälpen med tillgång till material, att styra upp användartester och allmänn handledning när det gäller bordtennisträning. Vi vill också tacka Karl-Johan Palmerius för vägledningen när det gäller bland annat ljudlokalisering.";
	wxStaticText* Info_Static = new wxStaticText(panel, wxID_ANY, Info, wxDefaultPosition, wxSize(650, 200), wxALIGN_CENTER);
	Info_Static->SetBackgroundColour(wxColor(38, 97, 153, 100));
	Info_Static->SetFont(wxFont(wxFontInfo(14).Family(wxFONTFAMILY_SCRIPT)));
	sizer->Add(Info_Static, 0, wxALIGN_CENTRE, FromDIP(10));

	//Lista med kontaktuppgiter
	wxListCtrl* kontakt = new wxListCtrl(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
	kontakt->SetBackgroundColour(wxColor(38, 97, 153, 100));

	// Add first column       
	wxListItem col0;
	col0.SetId(0);
	col0.SetText(_("Förnamn"));
	col0.SetWidth(150);
	kontakt->InsertColumn(0, col0);

	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText(_("Efternamn"));
	col1.SetWidth(150);
	kontakt->InsertColumn(1, col1);

	// Add third column     
	wxListItem col2;
	col2.SetId(2);
	col2.SetText(_("Mailadress"));
	col2.SetWidth(150);
	kontakt->InsertColumn(2, col2);

/*Elias	El Hanach	eliel224@student.liu.se	eliel224
Elin	Bergström	elibe803@student.liu.se	elibe803
Josephine	Zettervall	josze195@student.liu.se	josze195
Pedram	Abbasnejad	pedab341@student.liu.se	pedab341
Tobias	Svensson	tobsv650@student.liu.se	tobsv650*/

	long itemIndex1 = kontakt->InsertItem(0, "1");
	long itemIndex2 = kontakt->InsertItem(1, "1");
	long itemIndex3 = kontakt->InsertItem(2, "1");
	long itemIndex4 = kontakt->InsertItem(3, "1");
	long itemIndex5 = kontakt->InsertItem(4, "1");

	kontakt->SetItem(0, 0, wxT("Elias"));
	kontakt->SetItem(1, 0, wxT("Elin"));
	kontakt->SetItem(2, 0, wxT("Josephine"));
	kontakt->SetItem(3, 0, wxT("Pedram"));
	kontakt->SetItem(4, 0, wxT("Tobias"));
	kontakt->SetItem(0, 1, wxT("El Hanach"));
	kontakt->SetItem(1, 1, wxT("Bergström"));
	kontakt->SetItem(2, 1, wxT("Zettervall"));
	kontakt->SetItem(3, 1, wxT("Abbasnejad"));
	kontakt->SetItem(4, 1, wxT("Svensson"));
	kontakt->SetItem(0, 2, wxT("eliel224@student.liu.se"));
	kontakt->SetItem(1, 2, wxT("elibe803@student.liu.se"));
	kontakt->SetItem(2, 2, wxT("josze195@student.liu.se"));
	kontakt->SetItem(3, 2, wxT("pedab341@student.liu.se"));
	kontakt->SetItem(4, 2, wxT("tobsv650@student.liu.se	"));

	sizer->Add(kontakt, 0, wxALIGN_CENTRE);

	//LiU-logga - länk till hemsida?
		// Load bitmap image - logga
	wxBitmap logga_liu(wxT("../Spelifierad-bordtennis-TNM094/bilder/LiU_logga.bmp"), wxBITMAP_TYPE_BMP);
	wxImage liu_bitmap = logga_liu.ConvertToImage();
	// Resize image, original; 400 200
	liu_bitmap = liu_bitmap.Scale(200, 100, wxIMAGE_QUALITY_HIGH);
	
	// Create a static bitmap control and set the bitmap
	wxBitmapButton* liu_btn = new wxBitmapButton(panel, wxID_ANY, liu_bitmap, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	liu_btn->Bind(wxEVT_BUTTON, &About::OnLiuClicked, this);
	//liu_btn->Bind(wxEVT_ENTER_WINDOW, &About::OnMouseEnter, this);
	//liu_btn->Bind(wxEVT_LEAVE_WINDOW, &About::OnMouseLeave, this);
	sizer->Add(liu_btn, 0, wxALIGN_CENTRE, FromDIP(10));

	//To scroll
	panel->SetSizer(sizer);
	//Messages?
	CreateStatusBar();
}
/*
*
Funktioner/event
*
*
*/
void About::OnBackClicked(wxCommandEvent& evt) {
	//Close window when logo is  clicked
	Close();
}
void About::OnLiuClicked(wxCommandEvent& evt) {
	//Go to LiU website when button is clicked
	bool wxLaunchDefaultBrowser(const wxString & = "https://liu.se/", int flags = 0);
}
void About::OnMouseEnter(wxMouseEvent& event) {
	// Change cursor to hand cursor when mouse enters
	SetCursor(wxCursor(wxCURSOR_HAND));
}
void About::OnMouseLeave(wxMouseEvent& event) {
	// Reset cursor when mouse leaves
	SetCursor(wxNullCursor);
}