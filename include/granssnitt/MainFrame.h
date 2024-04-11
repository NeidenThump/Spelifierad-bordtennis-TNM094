#pragma once
#include <wx/wx.h>


class MainFrame : public wxFrame
{

public:
	MainFrame(const wxString& title);

private:
	void OnAboutClicked(wxCommandEvent& evt);
	void OnButtonSpelaClicked(wxCommandEvent& event);
    void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);

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

