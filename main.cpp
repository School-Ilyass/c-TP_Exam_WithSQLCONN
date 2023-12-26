#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "./headers/main.h"
#include "./include/mysql/jdbc.h"

#include "./headers/sqlConnection.h"

using namespace std;

// void ShowFacture(Facture &f){
//     cout << " Affichage de Facture" << endl << " ------------------ Numero Facture :" << f.getID() << " ------------------ " <<endl; 
//     cout << " Client ID :" << f.getClient()  <<endl; 
    
//     cout << " Produit : "; 

//     for(Produit p : f.getProduits()){
//     cout << endl << "          " << " Nom : " << p.getNom() << endl; 
//     cout << "          " << " QTE : " << p.getQte() << endl; 
//     cout << "          " << " PU : " << p.getPU() << endl; 
//     }
//     cout << " Date :"  << f.getDate() <<endl; 
//     cout << " Facture Etat : "  << f.getEtat() <<endl; 
//     cout << "-------------------------------------------------------" << endl ;
// }

// void FactureMaker(Facture &facture , vector<Produit> Produits){
//     int temp;
//     string temptext;

//     cout << "Set ID : ";
//     cin >> temp;
//     facture.setID(temp);

//     cout << "Set Cliend ID : ";
//     cin >> temp;
//     facture.setClient(temp);

//     facture.setProduits(Produits);

//     //Product Vetor Setting 
//     cout << "Set Date (Write 0 if you want system date): ";
//     cin >> temptext;
//     facture.setDate(temptext);

//     cout << "Set Facture State : ";
//     cin >> temp;
//     facture.setEtat(temp);
// }







int main(){

    // SQLSelect();
    // SQLSelectProduit();
    // SQLSelectFacture();
    // SQLSelectClient();

    vector<Produit> ProduitList;

    SQLSelectProduit();

    return 0;


    // vector<Produit> ProduitTemp;

    // int choix = 0;

    // do{
    //     cout << "1 - Make Facture" << endl;
    //     cout << "2 - Show Facture" << endl;

    //     cout << "3 - Make Client" << endl;
    //     cout << "4 - Show Client" << endl;

    //     cout << "5 - Make Produit" << endl;
    //     cout << "6 - show Produit" << endl;


    //     cout << "--> ";
    //     cin >> choix;
    // }
    // while( choix > 0);


    // Produit tomate(1,"Tomate","Marocaine",3.2,100);
    // Produit patate(1,"Patate","Espagnole",5,100);

    // Client Ilyass(1,"Ilyass","Baba","Sale, Chmaou");

    // ProduitTemp.push_back(ref(tomate));
    // ProduitTemp.push_back(ref(patate));

    // Facture Facture2(2,Ilyass.getID(), ref(ProduitTemp) ,"" , 0 );
    // Facture Facture1(1,Ilyass.getID(), ref(ProduitTemp) ,"" , 0 );
    

    // FactureMaker(ref(Facture1) , ProduitTemp);
    
    // ShowFacture(Facture1);


    }