#include <iostream>
#include "../include/mysql/jdbc.h"
#include "../headers/main.h"

using namespace std;

sql::Driver* myDriver = nullptr;
sql::Connection* myConn = nullptr;
sql::Statement* myStmt = nullptr;
sql::ResultSet* myRes = nullptr;

sql::ResultSet* SqlConnection(string query) {
    try {
        myDriver = get_driver_instance();
        myConn = myDriver->connect("tcp://127.0.0.1:3306", "root", "isba");
        myConn->setSchema("CPPExam");
        
        myStmt = myConn->createStatement();
        myRes = myStmt->executeQuery(query);

        return myRes;
    } catch (sql::SQLException& e) {
        cout << "Failed to connect to MySQL database test" << endl;
        cout << "Error: " << e.what() << endl;
        cout << "Error Code: " << e.getErrorCode() << endl;

        return nullptr;
    }
}


// Select Query


int SQLSelectProduit() {
    sql::ResultSet* MyResPTR = SqlConnection("SELECT * FROM Produit");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;
        return 1;
    }

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
}

int SQLSelectClient() {
    sql::ResultSet* MyResPTR = SqlConnection("select * from Client");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;
        return 1;
    }

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
}

int SQLSelectFacture() {
    sql::ResultSet* MyResPTR = SqlConnection("select * from Facture");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;
        return 1;
    }

    while (MyResPTR->next()) {
        int id = MyResPTR->getInt("id");
        string client = MyResPTR->getString("client");
        string date = MyResPTR->getString("date");
        string etat = MyResPTR->getString("etat");

        cout << "ID: " << id << endl;
        cout << "client: " << client << endl;
        cout << "date: " << date << endl;
        cout << "etat: " << etat << endl;
    }

    delete MyResPTR; // Clean up the result set

    return 0;
}



// Insert Query

//string Name , string Desc , float PU , double QTE
int SQLInsertProduit(Produit &obj) {
    int NO = 0;
    try
    {
        /* code */
        string Query = "INSERT INTO Produit VALUES(" + to_string(obj.getID()) + ",'" + obj.getNom() + "','" + obj.getDesc() + "'," + to_string(obj.getPU()) + "," + to_string(obj.getQte()) + ");";
        sql::ResultSet* MyResPTR = SqlConnection(Query);

        cout << "Line Inserted " << '\n';

        delete MyResPTR; // Clean up the result set
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}

int SQLInsertClient(Client &obj) {
    int NO = 0;
    try
    {
        /* code */
        string Query = "INSERT INTO Client VALUES(" + to_string(obj.getID()) + ",'" + obj.getNom() + "','" + obj.getPrenom() + "'," + obj.getAddresse()  + ");";
        sql::ResultSet* MyResPTR = SqlConnection(Query);
    
        cout << "Line Inserted " << '\n';

        delete MyResPTR; // Clean up the result set
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}

int SQLInsertFacture() {
    sql::ResultSet* MyResPTR = SqlConnection("select * from Facture");

    if (MyResPTR == nullptr) {
        // error handling
        cout << "MyResPTR: Is null " << endl;
        return 1;
    }

    while (MyResPTR->next()) {
        int id = MyResPTR->getInt("id");
        string client = MyResPTR->getString("client");
        string date = MyResPTR->getString("date");
        string etat = MyResPTR->getString("etat");

        cout << "ID: " << id << endl;
        cout << "client: " << client << endl;
        cout << "date: " << date << endl;
        cout << "etat: " << etat << endl;
    }

    delete MyResPTR; // Clean up the result set

    return 0;
}




// Insert Query

//string Name , string Desc , float PU , double QTE
int SQLUpdateProduit(Produit &obj , int id) {
    int NO = 0;
    try
    {
        /* code */
        string Query = "UPDATE Produit SET nom = '" + obj.getNom() + ", description = '" + obj.getDesc() + "'," + to_string(obj.getPU()) + "," + to_string(obj.getQte()) + ");";
        sql::ResultSet* MyResPTR = SqlConnection(Query);

        cout << "Line Inserted " << '\n';

        delete MyResPTR; // Clean up the result set
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}

// int SQLInsertClient() {
//     sql::ResultSet* MyResPTR = SqlConnection("select * from Client");

//     if (MyResPTR == nullptr) {
//         // error handling
//         cout << "MyResPTR: Is null " << endl;
//         return 1;
//     }

//     while (MyResPTR->next()) {
//         int id = MyResPTR->getInt("id");
//         string nom = MyResPTR->getString("nom");
//         string prenom = MyResPTR->getString("prenom");
//         string adresse = MyResPTR->getString("adresse");

//         cout << "ID: " << id << endl;
//         cout << "Name: " << nom << endl;
//         cout << "Prenom: " << prenom << endl;
//         cout << "adresse: " << adresse << endl;
//     }

//     delete MyResPTR; // Clean up the result set

//     return 0;
// }

// int SQLInsertFacture() {
//     sql::ResultSet* MyResPTR = SqlConnection("select * from Facture");

//     if (MyResPTR == nullptr) {
//         // error handling
//         cout << "MyResPTR: Is null " << endl;
//         return 1;
//     }

//     while (MyResPTR->next()) {
//         int id = MyResPTR->getInt("id");
//         string client = MyResPTR->getString("client");
//         string date = MyResPTR->getString("date");
//         string etat = MyResPTR->getString("etat");

//         cout << "ID: " << id << endl;
//         cout << "client: " << client << endl;
//         cout << "date: " << date << endl;
//         cout << "etat: " << etat << endl;
//     }

//     delete MyResPTR; // Clean up the result set

//     return 0;
// }
