#include "MainFrame.h"
#include "Settings.h"
#include "About.h"
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/statbmp.h>


MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	
	//Lägg alla elemtent på panelen
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	//Bakgrundsfärg
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));
	// Load bitmap image - logga
	wxBitmap logga(wxT("../Spelifierad-bordtennis-TNM094/bilder/projection_pong.bmp"), wxBITMAP_TYPE_BMP);
	wxImage logga_bitmap = logga.ConvertToImage();
	// Resize image, original; 794 1123
	logga_bitmap = logga_bitmap.Scale(250, 250, wxIMAGE_QUALITY_HIGH);
	// Create a static bitmap control and set the bitmap
	wxStaticBitmap* logga_static = new wxStaticBitmap(panel, wxID_ANY, logga_bitmap, wxPoint(50,0), wxDefaultSize);

	/*
	* Spelaknapp
	*/
	// Load bitmap image
	wxBitmap bitmapSpela(wxT("../Spelifierad-bordtennis-TNM094/bilder/spela_btn.bmp"), wxBITMAP_TYPE_BMP);
	wxImage spela_bitmap = bitmapSpela.ConvertToImage();
	// Resize image, original; 794 1123
	spela_bitmap = spela_bitmap.Scale(199, 281, wxIMAGE_QUALITY_HIGH);
	// Create button with BMP image
	wxBitmapButton* buttonSpela = new wxBitmapButton(panel, wxID_ANY, wxBitmap(spela_bitmap), wxPoint(75, 250), wxDefaultSize, wxBORDER_NONE);
	buttonSpela->Bind(wxEVT_BUTTON, &MainFrame::OnButtonSpelaClicked, this);
	buttonSpela->Bind(wxEVT_ENTER_WINDOW, &MainFrame::OnMouseEnter, this);
	buttonSpela->Bind(wxEVT_LEAVE_WINDOW, &MainFrame::OnMouseLeave, this);

	/*
	* Inställningsknapp - i mån av tid!!!
	// Add text label
	settings_label = new wxStaticText(panel, wxID_ANY, wxT("Inställningar"), wxPoint(450, 360), wxDefaultSize, wxALIGN_CENTER);
	settings_label->SetFont(wxFont(wxFontInfo(12).Bold()));
	//settings_label->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);

	// Create button with BMP image
	wxBitmapButton* buttonInst = new wxBitmapButton(panel, wxID_ANY, wxBitmap(racket_bitmap), wxPoint(350, 250), wxDefaultSize, wxBORDER_NONE);
	buttonInst->Bind(wxEVT_BUTTON, &MainFrame::OnInstClicked, this);*/

	/*
	* Informationsknapp
	*/
	// Load bitmap image
	wxBitmap bitmapAbout(wxT("../Spelifierad-bordtennis-TNM094/bilder/about_btn.bmp"), wxBITMAP_TYPE_BMP);
	wxImage About_bitmap = bitmapAbout.ConvertToImage();
	// Resize image, original; 794 1123
	About_bitmap = About_bitmap.Scale(199, 281, wxIMAGE_QUALITY_HIGH);
	// Create button with BMP image
	wxBitmapButton* buttonInfo = new wxBitmapButton(panel, wxID_ANY, wxBitmap(About_bitmap), wxPoint(350, 250), wxDefaultSize, wxBORDER_NONE);
	buttonInfo->Bind(wxEVT_BUTTON, &MainFrame::OnAboutClicked, this);
	// Bind mouse enter and leave events
	buttonInfo->Bind(wxEVT_ENTER_WINDOW, &MainFrame::OnMouseEnter, this);
	buttonInfo->Bind(wxEVT_LEAVE_WINDOW, &MainFrame::OnMouseLeave, this);

	CreateStatusBar();

	/*
	*Dekorationer
	*/

	//horizental line (image)
	// Load bitmap image
	wxBitmap horizontal(wxT("../Spelifierad-bordtennis-TNM094/bilder/horisontell_linje.bmp"), wxBITMAP_TYPE_BMP);
	// Create a static bitmap control and set the bitmap
	wxStaticBitmap* horizontal_static1 = new wxStaticBitmap(panel, wxID_ANY, horizontal, wxPoint(0, 550), wxDefaultSize);
	wxStaticBitmap* horizontal_static2 = new wxStaticBitmap(panel, wxID_ANY, horizontal, wxPoint(600, 550), wxDefaultSize);
	wxStaticBitmap* horizontal_static3 = new wxStaticBitmap(panel, wxID_ANY, horizontal, wxPoint(1200, 550), wxDefaultSize);

	// Create a vertical line (image)
	// Load bitmap image
	wxBitmap vertical(wxT("../Spelifierad-bordtennis-TNM094/bilder/vertikal_linje.bmp"), wxBITMAP_TYPE_BMP);
	// Create a static bitmap control and set the bitmap
	wxStaticBitmap* vertical_static1 = new wxStaticBitmap(panel, wxID_ANY, vertical, wxPoint(600, 0), wxDefaultSize);
	wxStaticBitmap* vertical_static2 = new wxStaticBitmap(panel, wxID_ANY, vertical, wxPoint(600, 600), wxDefaultSize);

	// Bollar
	// Load bitmap image
	wxBitmap bitmapBoll(wxT("../Spelifierad-bordtennis-TNM094/bilder/pingis_boll_bla_mindre.bmp"), wxBITMAP_TYPE_BMP);
	wxImage boll_bitmap = bitmapBoll.ConvertToImage();
	// Resize image, original; 794 1123
	boll_bitmap = boll_bitmap.Scale(35, 50, wxIMAGE_QUALITY_HIGH);
	// Create a static bitmap control and set the bitmap
	wxStaticBitmap* bitmapBoll_static1 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(690, 150), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static2 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(750, 200), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static3 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(670, 270), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static4 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(700, 350), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static5 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(750, 270), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static6 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(690, 400), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static7 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(730, 430), wxDefaultSize);
	wxStaticBitmap* bitmapBoll_static8 = new wxStaticBitmap(panel, wxID_ANY, boll_bitmap, wxPoint(750, 50), wxDefaultSize);
	
}

/*
*
Funktioner/event
*
*
*/

/*To open s new window/frame where you can read about the game*/
void MainFrame::OnAboutClicked(wxCommandEvent& evt) {
	About* about = new About("Om spelet");
	about->SetClientSize(800, 600);
	about->Center();
	//about->SetScrollbar(wxVERTICAL, 0, 16, 50);
	about->Show(true);
}
/*To start the game*/
void MainFrame::OnButtonSpelaClicked(wxCommandEvent& event) {
	// Path to your SDL2 executable
	wxString sdl2Executable = wxT("APP.exe");

	// Command-line argument to enable rendering
	wxString renderArgument = wxT("--render");

	// Construct command to start SDL2 application with rendering enabled
	wxString command = sdl2Executable + wxT(" ") + renderArgument;

	// Launch SDL2 application
	wxExecute(command);
}
/*Change cursor to hand - to amplify that "this is a button"*/
void MainFrame::OnMouseEnter(wxMouseEvent& event) {
	// Change cursor to hand cursor when mouse enters
	SetCursor(wxCursor(wxCURSOR_HAND));
}
/*Change cursor back to indicate that you are no longer hoovering a button*/
void MainFrame::OnMouseLeave(wxMouseEvent& event) {
	// Reset cursor when mouse leaves
	SetCursor(wxNullCursor);
}
