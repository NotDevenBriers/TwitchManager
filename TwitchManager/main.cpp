#define _CRT_SECURE_NO_WARNINGS

#include "jsonBuilder.h"
#include <iostream>
#include <wx/wx.h>

class App : public wxApp {
public:
    bool OnInit() {
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(600, 400));
        wxFrame* window2 = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(200, 200));
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        wxStaticText* text = new wxStaticText(window, wxID_ANY, "Well Done!\nEverything seems to be working",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(text, 1, wxALIGN_CENTER);
        window->SetSizer(sizer);
        window->Show();
        //window2->SetSizer(sizer);
        window2->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);

int main() {

	//testing dynamic json building

    std::string title = "game analysis 1v1";
    int cost = 50000;

    std::string prompt = "Challenge the streamer";
    bool usePrompt = true;

    JsonBuilder builder;

    builder
        .add("title", title)
        .add("cost", cost)
        .addIf(usePrompt, "prompt", prompt)
        .addIf(true, "is_enabled", true);

    std::string jsonBody = builder.dump(4);

    std::cout << jsonBody << std::endl;


	return 0;
}