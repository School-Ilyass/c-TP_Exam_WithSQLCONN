#include <iostream>
#include <string>
#include <vector>
#include "./headers/sqlConnection.h"

using namespace std;

class Produit{

    private:
        int id;
        string nom;
        string desc;
        float PU;
        double qte;
        vector <Produit> ProduitList;
    
    public:
        Produit(){}
        Produit(int id,string nom,string desc,float PU,double qte){
            this -> id = id;
            this -> nom = nom;
            this -> desc = desc;
            this -> PU = PU;
            this -> qte = qte;
        }

        // Setters
        void setID(int id){this -> id = id;}
        void setNom(string nom){this -> nom = nom;}
        void setDesc(string desc){this -> desc = desc;}
        void setPU(float PU){this -> PU = PU;}
        void setQte(double qte){this -> qte = qte;}

        // Getters
        int getID(){return this -> id;}
        string getNom(){return this -> nom;}
        string getDesc(){return this -> desc;}
        float getPU(){return this -> PU;}
        double getQte(){return this -> qte;}


        // Operators
         bool operator==(const Produit& other) const {
        return id == other.id; 
        }

        // SQLInsert
        void ProduitMySqlInsert(){

        }

        // SQLSelect
        void ProduitMySqlSelect(){
            
        }
};

class Client{

    private:
        int id;
        string nom;
        string prenom;
        string addresse;
    
    public:
        Client(){}
        Client(int id,string nom,string prenom,string addresse){
            this -> id = id;
            this -> nom = nom;
            this -> prenom = prenom;
            this -> addresse = addresse;
        }

        // Setters
        void setID(int id){this -> id = id;}
        void setNom(string nom){this -> nom = nom;}
        void setPrenom(string desc){this -> prenom = prenom;}
        void setAddresse(string desc){this -> addresse = addresse;}

        // Getters
        int getID(){return this -> id;}
        string getNom(){return this -> nom;}
        string getPrenom(){return this -> prenom;}
        string getAddresse(){return this -> addresse;}
};

class Facture{

    private:
        int id;
        int client;
        vector<Produit> Produits;
        string date;
        bool etat;
    public:
        Facture(){}
        Facture(int id,int client,vector<Produit> Produits,string date,int etat){
            this -> id = id;
            this -> client = client;
            this -> Produits = Produits;
            if(date == "0"){

                time_t now = time(0);
                tm* localtm = localtime(&now);

                char date[20]; 
                strftime(date, 20, "%d/%b/%Y", localtm);

                this -> date = date;

            }
            else{this -> date = date;}
            this -> etat = etat;
        }

        // Setters
        void setID(int id){this -> id = id;}
        void setClient(int client){this -> client = client;}
        void setProduits(vector<Produit> Produits){this -> Produits = Produits;}
        void setDate(string date){
            if(date == "0"){

                time_t now = time(0);
                tm* localtm = localtime(&now);

                char date[20]; 
                strftime(date, 20, "%d/%b/%Y", localtm);

                this -> date = date;

            }
            else{this -> date = date;}
            }
        void setEtat(int etat){this -> etat = etat;}

        // Getters
        int getID(){return this -> id;}
        int getClient(){return this -> client;}
        vector<Produit> getProduits(){return this -> Produits;}
        string getDate(){return this -> date ;}
        bool getEtat(){return this -> etat;}

       
        // Methods
        int checkProduitFacture(Produit p ){
            for (Produit item : Produits){
                // this -> Produits = 
                if(item == p){
                    return 0;
                }
            }
            return 1;
        }
};



