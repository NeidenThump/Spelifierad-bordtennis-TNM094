#pragma once
#include <wx/wx.h>

class Settings : public wxFrame
{

public:
	Settings(const wxString& title);

private:
	void OnBackClicked(wxCloseEvent& evt);

};

