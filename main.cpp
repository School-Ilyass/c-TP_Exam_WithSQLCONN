#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
// #include "./headers/main.h"
#include "./include/mysql/jdbc.h"
#include "./headers/sqlConnection.h"

using namespace std;



int main(){

    // vector<Produit> ProduitList;
    // SQLInsertProduit("hada produit" , " ma3rft mangol" , 10.0 , 1 );
    // SQLSelectProduit();

    int choix = 0;

    do {
        cout << "---------------Menu-------------" << endl;
        cout << "1 ) produit" << endl;
        cout << "2 ) client" << endl;
        cout << "3 ) facture" << endl;

        cin >> choix;

        if (choix == 1) {
            // creation d'objet  
            cout << "---------------Produit-------------" << endl;

            system("clear");

            char choix;

            cout << "a ) Ajouter un Produit" << endl;
            cout << "b ) Modifier un Produit" << endl;
            cout << "c ) Afficher les Produits" << endl;

            cout << "Choix : ";

            cin >> choix;

            if (choix == 'a')
            {
              /* code */
              int id;
              string nom;
              string desc;
              float PU;
              double qte;
              system("clear");


              cout << "--------------- Creation Produit -------------" << endl;

              cout << "ID : ";
              cin >> id;
              cout << "nom : ";
              cin >> nom;
              cout << "desc : ";
              cin >> desc;
              cout << "PU : ";
              cin >> PU;
              cout << "qte : ";
              cin >> qte;

              Produit p(id,nom,desc,PU,qte);
              SQLInsertProduit(ref(p));
            }

            if (choix == 'b')
            {
              /* code */

              system("clear");
              cout << "--------------- Select Produit -------------" << endl;
              SQLSelectProduit();


               /* code */
              int id;
              string nom;
              string desc;
              float PU;
              double qte;
              system("clear");

              
              cout << "Quelle ID ? " << endl;
              cout << "ID : ";
              cin >> id;


              system("clear");

              cout << "--------------- Modifier Produit NO " << id  << " ------------- "<< endl;

              cout << "nom : ";
              cin >> nom;
              cout << "desc : ";
              cin >> desc;
              cout << "PU : ";
              cin >> PU;
              cout << "qte : ";
              cin >> qte;

              Produit p(id,nom,desc,PU,qte);
              SQLUpdateProduit(ref(p) , id);



            }

            if (choix == 'c')
            {
              /* code */

              SQLSelectProduit();
            }
            

            // cout << "Selected produit" << endl;
        }
        else if (choix == 2) {
            system("clear");
            // cout << "Selected client" << endl;
        }
        else if (choix == 3) {
            system("clear");
            // cout << "Selected facture" << endl;
        }
    } while (choix >= 1);

//     // vector<Produit> ProduitTemp;

//     // int choix = 0;

//     // do{
//     //     cout << "1 - Make Facture" << endl;
//     //     cout << "2 - Show Facture" << endl;

//     //     cout << "3 - Make Client" << endl;
//     //     cout << "4 - Show Client" << endl;

//     //     cout << "5 - Make Produit" << endl;
//     //     cout << "6 - show Produit" << endl;


//     //     cout << "--> ";
//     //     cin >> choix;
//     // }
//     // while( choix > 0);


//     // Produit tomate(1,"Tomate","Marocaine",3.2,100);
//     // Produit patate(1,"Patate","Espagnole",5,100);

//     // Client Ilyass(1,"Ilyass","Baba","Sale, Chmaou");

//     // ProduitTemp.push_back(ref(tomate));
//     // ProduitTemp.push_back(ref(patate));

//     // Facture Facture2(2,Ilyass.getID(), ref(ProduitTemp) ,"" , 0 );
//     // Facture Facture1(1,Ilyass.getID(), ref(ProduitTemp) ,"" , 0 );
    

//     // FactureMaker(ref(Facture1) , ProduitTemp);
    
//     // ShowFacture(Facture1);


    return 0;
    }