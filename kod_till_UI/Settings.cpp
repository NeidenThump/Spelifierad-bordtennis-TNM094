#include "Settings.h"
#include "MainFrame.h"
#include <wx/wx.h>

Settings::Settings(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Placeholder; logga/titel", wxPoint(50, 50), wxSize(300, 50), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	wxButton* buttonTillbaka = new wxButton(panel, wxID_ANY, "Tillbaka", wxPoint(1, 1), wxDefaultSize);
	buttonTillbaka->Bind(wxEVT_CLOSE_WINDOW, &Settings::OnBackClicked, this);

	wxCheckBox* useRobot = new wxCheckBox(panel, wxID_ANY, "Använd roboten", wxPoint(50, 150), wxDefaultSize);

	wxButton* kalibreraBild = new wxButton(panel, wxID_ANY, "Kalibrera: bild (projektor)", wxPoint(50, 250), wxDefaultSize);
	wxButton* kalibreraLjud = new wxButton(panel, wxID_ANY, "Kalibrera: Ljud (mikrofoner)", wxPoint(50, 350), wxDefaultSize);
	

	CreateStatusBar();
}

void Settings::OnBackClicked(wxCloseEvent& evt) {

	evt.Skip();
	Close();
	//wxLogMessage("Button Clicked!");
}
