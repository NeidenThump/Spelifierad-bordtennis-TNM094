#include "About.h"
#include "MainFrame.h"
#include <wx/wx.h>

About::About(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Placeholder; logga/titel", wxPoint(50, 50), wxSize(300, 50), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	wxStaticText* OmSpelet = new wxStaticText(panel, wxID_ANY, "Om spelet", wxPoint(400, 50), wxSize(300, 50), wxALIGN_CENTER);
	OmSpelet->SetBackgroundColour(*wxLIGHT_GREY);



	CreateStatusBar();
}