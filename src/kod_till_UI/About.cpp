#include "About.h"
#include "MainFrame.h"
#include <wx/wx.h>

About::About(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));

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

	wxStaticText* OmSpelet = new wxStaticText(panel, wxID_ANY, "Om spelet", wxPoint(400, 50), wxSize(300, 50), wxALIGN_CENTER);
	OmSpelet->SetBackgroundColour(*wxLIGHT_GREY);

	

	CreateStatusBar();
}

void About::OnBackClicked(wxCommandEvent& evt) {
	Close();
	//wxLogMessage("Button Clicked!");
}
void About::OnMouseEnter(wxMouseEvent& event) {
	// Change cursor to hand cursor when mouse enters
	SetCursor(wxCursor(wxCURSOR_HAND));
}

void About::OnMouseLeave(wxMouseEvent& event) {
	// Reset cursor when mouse leaves
	SetCursor(wxNullCursor);
}