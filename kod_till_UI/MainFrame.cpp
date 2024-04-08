#include "MainFrame.h"
#include "Settings.h"
#include "About.h"
#include <wx/wx.h>
#include <wx/statline.h>


MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	//Bakgrundsfärg
	
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	panel->SetBackgroundColour(wxColor(38, 97, 153, 100));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "Placeholder; logga/titel", wxPoint(50, 50), wxSize(300, 50), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	// Load bitmap image
	wxBitmap bitmapRacket(wxT("../WXTest2/Pingisracket_fram_bla.bmp"), wxBITMAP_TYPE_BMP);
	// Load bitmap image
	wxBitmap bitmapBoll(wxT("../WXTest2/pingis_boll_bla_mindre.bmp"), wxBITMAP_TYPE_BMP);

	wxImage racket_bitmap;
	wxImage boll_bitmap;
	wxBitmapButton* buttonInst;
	wxBitmapButton* buttonSpela;
	wxStaticText* settings_label;
	wxStaticText* play_label;
	wxBitmapButton* buttonInfo;
	wxStaticText* Info_label;

	racket_bitmap = bitmapRacket.ConvertToImage();
	boll_bitmap = bitmapBoll.ConvertToImage();

	// Resize image, original; 794 1123
	racket_bitmap = racket_bitmap.Scale(199, 281, wxIMAGE_QUALITY_HIGH);

	// Resize image, original; 794 1123
	boll_bitmap = boll_bitmap.Scale(99, 140, wxIMAGE_QUALITY_HIGH);

	/*
	* Spelaknapp
	*/
	// Add text label
	play_label = new wxStaticText(panel, wxID_ANY, wxT("Spela"), wxPoint(200, 360), wxDefaultSize, wxALIGN_CENTER);
	play_label->SetFont(wxFont(wxFontInfo(12).Bold()));
	//play_label->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);

	// Create button with BMP image
	buttonSpela = new wxBitmapButton(panel, wxID_ANY, wxBitmap(racket_bitmap), wxPoint(75, 250), wxDefaultSize, wxBORDER_NONE);


	/*
	* Inställningsknapp
	*/

	// Add text label
	settings_label = new wxStaticText(panel, wxID_ANY, wxT("Inställningar"), wxPoint(450, 360), wxDefaultSize, wxALIGN_CENTER);
	settings_label->SetFont(wxFont(wxFontInfo(12).Bold()));
	//settings_label->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);

	// Create button with BMP image
	buttonInst = new wxBitmapButton(panel, wxID_ANY, wxBitmap(racket_bitmap), wxPoint(350, 250), wxDefaultSize, wxBORDER_NONE);
	buttonInst->Bind(wxEVT_BUTTON, &MainFrame::OnInstClicked, this);


	/*
	* Informationsknapp
	*/

	// Add text label
	Info_label = new wxStaticText(panel, wxID_ANY, wxT("Om spelet"), wxPoint(650, 400), wxDefaultSize, wxALIGN_CENTER);
	Info_label->SetFont(wxFont(wxFontInfo(12).Bold()));
	//Info_label->SetBackgroundStyle(wxBG_STYLE_TRANSPARENT);

	// Create button with BMP image
	buttonInfo = new wxBitmapButton(panel, wxID_ANY, wxBitmap(boll_bitmap), wxPoint(640, 350), wxDefaultSize, wxBORDER_NONE);
	buttonInfo->Bind(wxEVT_BUTTON, &MainFrame::OnAboutClicked, this);

	CreateStatusBar();

	/*
	*Dekorationer
	*/

	// Create a horizontal line
	wxStaticLine* line1 = new wxStaticLine(panel, wxID_ANY, wxPoint(0,150), wxSize(800, 15), wxLI_HORIZONTAL);
	line1->SetForegroundColour(*wxWHITE);

	// Create a vertical line
	wxStaticLine* line2 = new wxStaticLine(panel, wxID_ANY, wxPoint(600, 0), wxSize(15, 600), wxLI_VERTICAL);
	line2->SetForegroundColour(*wxWHITE);
}

void MainFrame::OnButtonClick(wxCommandEvent& event) {
	// Handle button click event
	wxMessageBox(wxT("Button clicked!"));
}

void MainFrame::OnInstClicked(wxCommandEvent& evt) {

	Settings* settings = new Settings("Inställningar");
	settings->SetClientSize(800, 600);
	settings->Center();
	settings->Show(true);

	//wxLogMessage("Button Clicked!");
}
void MainFrame::OnAboutClicked(wxCommandEvent& evt) {

	About* about = new About("Om spelet");
	about->SetClientSize(800, 600);
	about->Center();
	about->Show(true);

	//wxLogMessage("Button Clicked!");
}


/*

Keyboard

*/
//
//MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
//	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
//
//	wxButton* button1 = new wxButton(panel, wxID_ANY, "button 1", wxPoint(300, 150), wxSize(200, 100)); //wxWANTS_CHARS tar bort ljudet, men tar bort fokusknappar
//
//	wxButton* button2 = new wxButton(panel, wxID_ANY, "button 2", wxPoint(300, 350), wxSize(200, 100));
//
//	button1->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);
//
//	//panel->Bind(wxEVT_KEY_UP, &MainFrame::OnKeyEvent, this);
//	//panel->Bind(wxEVT_CHAR, &MainFrame::OnKeyEvent, this);
//
//	CreateStatusBar();
//}
//
//void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
//	
//	/*//Use uppercase characters!
//	if (evt.GetUnicodeKey() == 'A') {
//		wxLogStatus("A was pressed!");
//	}
//	else if (evt.GetKeyCode() == WXK_HOME) {
//		wxLogStatus("HOME was pressed!");
//	}
//	return;*/
//
//	if (evt.GetKeyCode() == WXK_DOWN || evt.GetKeyCode() == WXK_UP) {
//		wxWindow* window = (wxWindow*)evt.GetEventObject();
//		window->Navigate();
//	}
//
//	//Only works for letters and numbers
//	wxChar keyChar = evt.GetUnicodeKey();
//
//	if (keyChar == WXK_NONE) {
//		int keyCode = evt.GetKeyCode();
//		wxLogStatus("Key Event %c", keyCode);
//	}
//	else {
//		wxLogStatus("Key Event %c", keyChar);
//	}
//}
//


/*


Mouse Events

*/
//
//void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
//	//wxPoint mousePos = evt.GetPosition();
//	//Screencoordinates:
//	wxPoint mousePos = wxGetMousePosition();
//	mousePos = this->ScreenToClient(mousePos);
//	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
//	wxLogStatus(message);
//}
//
//MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
//	wxPanel* panel = new wxPanel(this);
//
//	wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(150, 50), wxSize(100, 35));
//
//	wxStatusBar* statusBar = CreateStatusBar();
//	statusBar->SetDoubleBuffered(true);
//
//	//See whole list of mouse events in documentation!
//	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
//	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
//}
//
//void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
//	//wxPoint mousePos = evt.GetPosition();
//	//Screencoordinates:
//	wxPoint mousePos = wxGetMousePosition();
//	mousePos = this->ScreenToClient(mousePos);
//	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
//	wxLogStatus(message);
//}
//
//
//
//









//MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
//	wxPanel* panel = new wxPanel(this);
//
//	wxButton* button1 = new wxButton(panel, wxID_ANY, "button 1", wxPoint(300, 275), wxSize(200, 50));
//
//	wxButton* button2 = new wxButton(panel, wxID_ANY, "button 2", wxPoint(300, 350), wxSize(200, 50));
//
//	//Kolla upp dokumentation för att veta vilket event som ska användas
//	//button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
//
//	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
//
//	//panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
//	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
//	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
//	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
//
//
//	CreateStatusBar();
//}
//
//void MainFrame::OnClose(wxCloseEvent& evt) {
//	wxLogMessage("Frame Cllosed");
//	//Skip in order for the frame to actually close
//	evt.Skip();
//}
//
//void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
//	wxLogMessage("Button Clicked!");
//}
//
//void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
//	wxLogStatus("Button 1 clicked!");
//	//Propagation
//	evt.Skip();
//}
//
//void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
//	wxLogStatus("Button 2 clicked!");
//	evt.Skip();
//}
//

/*
Custom  ID-rules:
1) Must be positive
2) Cannot be 0 or 1
3) Cannot be from wxID_LOWEST (4999) to wxID_HIGHEST (5999)
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

//Static event-handling
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()
*/

//bind
//MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
//	wxPanel* panel = new wxPanel(this);
//
//	wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(300, 275), wxSize(200, 50));
//	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
//	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));
//
//	//Kolla upp dokumentation för att veta vilket event som ska användas
//	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
//	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
//	textCtrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);
//
//	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
//
//	CreateStatusBar();
//}
//
//void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
//
//	wxLogStatus("Button Clicked!");
//}
//
//void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
//	wxString str = wxString::Format("Slider value: %d", evt.GetInt());
//	wxLogStatus(str);
//}
//
//void MainFrame::OnTextChanged(wxCommandEvent& evt) {
//	wxString str = wxString::Format("Text: %s", evt.GetString());
//	wxLogStatus(str);
//}



/* Controlls

#include "MainFrame.h"
#include <wx/wx.h>
//för wxSpinCtrl
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "checkBox", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText, cannot be changed", wxPoint(0, 150), wxSize(400,-1), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl, can be changed", wxPoint(500, 145),wxSize(200,-1), wxTE_PASSWORD); //-1 = default value

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	//Gauge borde kunna användas för "laddar", gauge->SetValue(Varibel)
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1), wxGA_VERTICAL);
	gauge->SetValue(50);

	wxArrayString choices;

	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	choice->Select(0);

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);

}*/
