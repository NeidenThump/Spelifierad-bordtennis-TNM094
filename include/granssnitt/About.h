#pragma once
#include <wx/wx.h>

class About : public wxFrame
{
public:
	About(const wxString& title);

private:
	void OnBackClicked(wxCommandEvent& evt);
	void OnLiuClicked(wxCommandEvent& evt);
	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);
};

