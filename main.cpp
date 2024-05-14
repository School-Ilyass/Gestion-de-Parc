#include <iostream>
#include <string>
#include <vector>

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

class AddDialog : public wxDialog
{
public:
    AddDialog(wxWindow* parent);
    wxString GetText() const { return textCtrl->GetValue(); }

private:
    void OnSubmit(wxCommandEvent& event);
    void OnCancel(wxCommandEvent& event);

    wxTextCtrl* textCtrl;
};

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnAdd(wxCommandEvent& event);

    wxTextCtrl* textCtrl;
};

enum
{
    ID_Hello = 1,
    ID_Add,
    ID_TextCtrl
};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

AddDialog::AddDialog(wxWindow* parent)
    : wxDialog(parent, wxID_ANY, "Add Item")
{
    wxStaticText* label = new wxStaticText(this, wxID_ANY, "Enter item:");
    textCtrl = new wxTextCtrl(this, wxID_ANY);

    wxButton* submitButton = new wxButton(this, wxID_OK, "Submit");
    wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(label, 0, wxALL, 5);
    sizer->Add(textCtrl, 0, wxEXPAND | wxALL, 5);
    sizer->Add(submitButton, 0, wxALL, 5);
    sizer->Add(cancelButton, 0, wxALL, 5);

    SetSizerAndFit(sizer);

    submitButton->Bind(wxEVT_BUTTON, &AddDialog::OnSubmit, this);
    cancelButton->Bind(wxEVT_BUTTON, &AddDialog::OnCancel, this);
}

void AddDialog::OnSubmit(wxCommandEvent& event)
{
    textCtrl->Clear();
    EndModal(wxID_OK);
}

void AddDialog::OnCancel(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenu* menuJeu = new wxMenu;
    menuJeu->Append(ID_Add, "&Add");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    menuBar->Append(menuJeu, "&Jeu");

    CreateStatusBar();
    SetMenuBar(menuBar);
    SetStatusText("Parc Jeu");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnAdd, this, ID_Add);

    textCtrl = new wxTextCtrl(this, ID_TextCtrl, wxEmptyString, wxDefaultPosition,
                             wxDefaultSize, wxTE_PROCESS_ENTER);
    textCtrl->SetFocus();
    textCtrl->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnAdd, this);

    wxButton* submitButton = new wxButton(this, ID_Add, "Submit");

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(textCtrl, 1, wxEXPAND | wxALL, 5);
    sizer->Add(submitButton, 0, wxALL, 5);

    SetSizer(sizer);
    Layout();
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a sample wxWidgets application.", "About", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnAdd(wxCommandEvent& event)
{
    AddDialog dialog(this);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString text = dialog.GetText();
        textCtrl->AppendText(text + "\n");
    }
}

wxIMPLEMENT_APP(MyApp);








// class Jeu
// {
//     protected:
//         string nom;
//         int ageMinimum; 
//     public:
//     Jeu(string nom , int ageMinimum){
//         this -> nom = nom;
//         this -> ageMinimum = ageMinimum;
//     }
//     virtual void afficher(){
//         cout << "--------------------------" << endl;
//         cout << "Nom du Jeu : " << nom << endl;
//         cout << "Age minimum : " << ageMinimum << endl;
//         cout << "--------------------------" << endl;
//     }
// };

// class JeuExterieur : public Jeu{
//     private : 
//         double surface;
//     public :
    
//         JeuExterieur(string nom , int ageMinimum , double surface) : Jeu( nom ,  ageMinimum){
//             this -> surface = surface;
//         }
//         void afficher() override {
//             cout << "--------------------------" << endl;
//             cout << "Nom du Jeu : " << nom << endl;
//             cout << "Age minimum : " << ageMinimum << endl;
//             cout << "Surface : " << surface << endl;
//             cout << "--------------------------" << endl;
//         }
// };


// class JeuInterieur : public Jeu{
//     private : 
//         int capaciteMax;
//     public :
    
//         JeuInterieur(string nom , int ageMinimum , int capaciteMax) : Jeu( nom ,  ageMinimum){
//             this -> capaciteMax = capaciteMax;
//         }
//         void afficher() override {
//             cout << "--------------------------" << endl;
//             cout << "Nom du Jeu : " << nom << endl;
//             cout << "Age minimum : " << ageMinimum << endl;
//             cout << "capaciteMax : " << capaciteMax << endl;
//             cout << "--------------------------" << endl;
//         }
// };




// class ParcJeux{
//     private : 
//         vector<Jeu*> jeux;
//         int capaciteMax;
//         // pas de capacite max car j'utilise un vecteur  
//     public :
    
//         ParcJeux(int capaciteMax ){
//             this -> jeux = jeux;
//             this -> capaciteMax = capaciteMax;
//         }
//         ParcJeux(int capaciteMax , vector<Jeu*> jeux){
//             if(jeux.size() < capaciteMax){
//                 this -> jeux = jeux;
//                 this -> capaciteMax = capaciteMax;
//             }
//             else{
//                 cout << "CAPACITE MAX !!!!!! " << endl;
//             }
//         }
//         void AjouterJeux(Jeu* Jeu){
//             if(jeux.size() < capaciteMax){
//                 jeux.push_back(Jeu);
//             }
//             else{
//                 cout << "CAPACITE MAX !!!!!! " << endl;
//             }

//         }
//         void afficherJeux(){
//             for(Jeu* jeu : jeux){
//                 jeu -> afficher();
//             }
//         }
// };



// int main(){
//     Jeu TICTACTOE("TICTACTOE" , 3);
//     JeuInterieur Scrable("Scrable" , 5 , 2);
//     JeuInterieur Monopoly("Monopoly" , 5 , 5);
//     ParcJeux Parc1(2);

//     Parc1.AjouterJeux(&TICTACTOE);
//     Parc1.AjouterJeux(&Scrable);
//     Parc1.AjouterJeux(&Monopoly);

//     Parc1.afficherJeux();
//     return 0;
// };