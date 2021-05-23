///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/statline.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
#include <wx/log.h>
#include <wx/filedlg.h>

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxPanel* OriginalImage;
	wxStaticText* Saturation_Text;
	wxSlider* SetSaturation;
	wxStaticLine* m_staticline1;
	wxStaticText* Choose_Text;
	wxChoice* Choice;
	wxStaticLine* m_staticline2;
	wxStaticText* SetValue_Text;
	wxTextCtrl* Value_Text;
	wxStaticText* Validation_Text;
	wxStaticLine* m_staticline3;
	wxStaticText* SetBlur_Text;
	wxSlider* SetBlur;
	wxButton* ApplyChanges;
	wxPanel* ResultImage;
	wxMenuBar* m_menubar1;
	wxMenu* File;
	wxMenu* Details;

	// Virtual event handlers, overide them in your derived class
	virtual void Frame_OnCLose(wxCloseEvent& event) { event.Skip(); }
	virtual void OriginalImage_OnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void ValueText_OnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void ApplyChanges_OnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void ResultImage_OnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void LoadFile(wxCommandEvent& event) { event.Skip(); }
	virtual void SaveFile(wxCommandEvent& event) { event.Skip(); }
	virtual void AboutProject(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(966, 514), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};
