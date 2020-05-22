#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::Frame_OnCLose( wxCloseEvent& event )
{
	const wxString message = "Are you sure you want to exit?\nAll changes will be lost.";
	if (wxMessageDialog(NULL, message, "Warning!", wxOK | wxCANCEL).ShowModal() == wxID_OK)
		Destroy();
}

void GUIMyFrame1::SetSaturation_OnScrollThumbTrack( wxScrollEvent& event )
{
// TODO: Implement SetSaturation_OnScrollThumbTrack
}

void GUIMyFrame1::Choice_OnChoice( wxCommandEvent& event )
{
// TODO: Implement Choice_OnChoice
}

void GUIMyFrame1::Value_Slider_OnScrollThumbTrack( wxScrollEvent& event )
{
// TODO: Implement Value_Slider_OnScrollThumbTrack
}

void GUIMyFrame1::Value_Text_Changed( wxCommandEvent& event )
{
// TODO: Implement Value_Text_Changed
}

void GUIMyFrame1::LoadFile( wxCommandEvent& event )
{
// TODO: Implement LoadFile
}

void GUIMyFrame1::SaveFile( wxCommandEvent& event )
{
// TODO: Implement SaveFile
}

void GUIMyFrame1::AboutProject( wxCommandEvent& event )
{
	wxString about = "Selective Image Desaturation\n";
	about += "Computer Graphics Project\nMade by:\n";
	about += "Mateusz Barnacki\nWojciech Gomu\u0142ka\nBartosz Rogowski\n";
	about += "----------------------\n";
	about += "WFiIS IS AGH\n2020";
	about += "\n\nAll rights reserved.";
	wxMessageDialog(NULL, about, "About", wxOK).ShowModal();
}
