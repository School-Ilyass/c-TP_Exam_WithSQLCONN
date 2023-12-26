#include <iostream>
#include "../include/mysql/jdbc.h"


using namespace std;

sql::Driver     *myDriver;
sql::Connection *myConn;
sql::Statement  *myStmt;
sql::ResultSet  *myRes;

sql::ResultSet* SqlConnection(string query){

    try{

        myDriver = get_driver_instance();
        myConn = myDriver->connect("tcp://127.0.0.1:3306" , "root" , "isba");

        myConn->setSchema("CPPExam");
        
        myStmt = myConn->createStatement();
        myRes = myStmt->executeQuery(query);


        // delete myRes;
        delete myStmt;
        delete myConn;
        return myRes;
    }
    catch(sql::SQLException &e){
        std::cout << "Filed Connect to nmySql database test" << std::endl;
        std::cout << "Error : " << e.what() << std::endl;
        std::cout << "Error Code : " << e.getErrorCode() << std::endl; 
        
        return nullptr; 
        };

    }

int SQLSelectProduit(){

        sql::ResultSet* MyResPTR = SqlConnection("SELECT * FROM Produit");

        if (MyResPTR == nullptr) {
            // error handling
            cout << "MyResPTR: Is null " << endl;

            return 1; 
            }
        cout << "MyResPTR: " << MyResPTR << endl;

        while (MyResPTR->next()) {
            int id = MyResPTR->getInt("id");
            string nom = MyResPTR->getString("nom");
            string prenom = MyResPTR->getString("description");
            string PU = MyResPTR->getString("PrixUnitaire");
            string QTE = MyResPTR->getString("Quantite");


            cout << "ID: " << id << endl;
            cout << "Name: " << nom << endl;
            cout << "Prenom: " << prenom << endl;
            cout << "PU: " << PU << endl;
            cout << "QTE: " << QTE << endl;
        }

        delete MyResPTR; // Clean up the result set

        return 0;

};


int SQLSelectClient(){

    sql::ResultSet* MyResPTR = SqlConnection("select * from Client");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;

        return 1; 
        }
    cout << "MyResPTR: " << MyResPTR << endl;

    while (MyResPTR->next()) {
        int id = MyResPTR->getInt("id");
        string nom = MyResPTR->getString("nom");
        string prenom = MyResPTR->getString("prenom");
        string adresse = MyResPTR->getString("adresse");


        cout << "ID: " << id << endl;
        cout << "Name: " << nom << endl;
        cout << "Prenom: " << prenom << endl;
        cout << "adresse: " << adresse << endl;
    }

    delete MyResPTR; // Clean up the result set

    return 0;
};


int SQLSelectFacture(){

    

    sql::ResultSet* MyResPTR = SqlConnection("select * from Facture");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;

        return 1; 
        }
    cout << "MyResPTR: " << MyResPTR << endl;

    while (MyResPTR->next()) {
        int id = MyResPTR->getInt("id");
        string client = MyResPTR->getString("client");
        string date = MyResPTR->getString("date");
        string etat = MyResPTR->getString("etat");


        cout << "ID: " << id << endl;
        cout << "client: " << client << endl;
        cout << "date: " << date << endl;
        cout << "date: " << date << endl;
    }

    delete MyResPTR; // Clean up the result set

    return 0;
};