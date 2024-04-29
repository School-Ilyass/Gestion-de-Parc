
#include <iostream>
//#include "./headers/main.h"
#include <string>
#include <vector>
using namespace std;

class Jeu
{
    protected:
        string nom;
        int ageMinimum; 
    public:
    Jeu(string nom , int ageMinimum){
        this -> nom = nom;
        this -> ageMinimum = ageMinimum;
    }
    virtual void afficher(){
        cout << "--------------------------" << endl;
        cout << "Nom du Jeu : " << nom << endl;
        cout << "Age minimum : " << ageMinimum << endl;
        cout << "--------------------------" << endl;
    }
};

class JeuExterieur : public Jeu{
    private : 
        double surface;
    public :
    
        JeuExterieur(string nom , int ageMinimum , double surface) : Jeu( nom ,  ageMinimum){
            this -> surface = surface;
        }
        void afficher() override {
            cout << "--------------------------" << endl;
            cout << "Nom du Jeu : " << nom << endl;
            cout << "Age minimum : " << ageMinimum << endl;
            cout << "Surface : " << surface << endl;
            cout << "--------------------------" << endl;
        }
};


class JeuInterieur : public Jeu{
    private : 
        int capaciteMax;
    public :
    
        JeuInterieur(string nom , int ageMinimum , int capaciteMax) : Jeu( nom ,  ageMinimum){
            this -> capaciteMax = capaciteMax;
        }
        void afficher() override {
            cout << "--------------------------" << endl;
            cout << "Nom du Jeu : " << nom << endl;
            cout << "Age minimum : " << ageMinimum << endl;
            cout << "capaciteMax : " << capaciteMax << endl;
            cout << "--------------------------" << endl;
        }
};




class ParcJeux{
    private : 
        vector<Jeu*> jeux;
        int capaciteMax;
        // pas de capacite max car j'utilise un vecteur  
    public :
    
        ParcJeux(int capaciteMax ){
            this -> jeux = jeux;
            this -> capaciteMax = capaciteMax;
        }
        ParcJeux(int capaciteMax , vector<Jeu*> jeux){
            if(jeux.size() < capaciteMax){
                this -> jeux = jeux;
                this -> capaciteMax = capaciteMax;
            }
            else{
                cout << "CAPACITE MAX !!!!!! " << endl;
            }
        }
        void AjouterJeux(Jeu* Jeu){
            if(jeux.size() < capaciteMax){
                jeux.push_back(Jeu);
            }
            else{
                cout << "CAPACITE MAX !!!!!! " << endl;
            }

        }
        void afficherJeux(){
            for(Jeu* jeu : jeux){
                jeu -> afficher();
            }
        }
};



int main(){
    Jeu TICTACTOE("TICTACTOE" , 3);
    JeuInterieur Scrable("Scrable" , 5 , 2);
    JeuInterieur Monopoly("Monopoly" , 5 , 5);
    ParcJeux Parc1(2);

    Parc1.AjouterJeux(&TICTACTOE);
    Parc1.AjouterJeux(&Scrable);
    Parc1.AjouterJeux(&Monopoly);

    Parc1.afficherJeux();
    return 0;
};