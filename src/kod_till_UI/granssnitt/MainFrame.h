#pragma once
#include <wx/wx.h>


class MainFrame : public wxFrame
{

public:
	MainFrame(const wxString& title);

private:
	//void OnKeyEvent(wxKeyEvent& evt);
	void OnInstClicked(wxCommandEvent& evt);
	void OnAboutClicked(wxCommandEvent& evt);
	void OnButtonClick(wxCommandEvent& event);

};






//class MainFrame : public wxFrame
//{
//
//public:
//	MainFrame(const wxString& title);
//
//private:
//	void OnAnyButtonClicked(wxCommandEvent& evt);
//	void OnButton1Clicked(wxCommandEvent& evt);
//	void OnButton2Clicked(wxCommandEvent& evt);
//	void OnClose(wxCloseEvent& evt)
//
//	//void OnSliderChanged(wxCommandEvent& evt);
//	//void OnTextChanged(wxCommandEvent& evt);
//
//	//Static event-handling
//	/*wxDECLARE_EVENT_TABLE();*/
//
//};

