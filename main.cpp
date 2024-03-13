#include "heersp.h"
int main()
{
    Product newproduct;
    int yes;
    vendor newvendor;
    string id, name, email, role;
    int password;
    int enteredPassword;
    int choice;

    do
    {
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\t\t=============================\n";
        cout << "\t\t|      Welcome to MyShop     |\n";
        cout << "\t\t=============================\n";
        cout << "\t\t|          MAIN MENU         |\n";
        cout << "\t\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
        cout << "\t\t| 1. Customer                |\n";
        cout << "\t\t| 2. Admin                   |\n";
        cout << "\t\t| 3. Vendor                  |\n";
        cout << "\t\t| 0. Exit Program            |\n"; 
        cout << "\t\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
        cout << "\t\tEnter your choice: ";
        while (!(cin >> choice))
        {
            cout << "\n[ERROR] > Wrong Input! Enter Again: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        system("pause");
        system("cls");

        switch (choice)
        {
        case 1:
        {

            customer newcustomer;
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\t\t\t\t\t\t==============================\n";
            cout << "\t\t\t\t\t\t|       Customer Mode        |\n";
            cout << "\t\t\t\t\t\t==============================\n";
            cout << "\t\t\t\t\t\t| 1. Registered user         |\n";
            cout << "\t\t\t\t\t\t| 2. New user                |\n";
            cout << "\t\t\t\t\t\t==============================\n";
            cout << "\t\t\t\t\t\tEnter your choice: ";
            while (!(cin >> yes))
            {
                cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
            while (yes != 1 && yes != 2)
            {
                cout << "\t\t\t\t\tINVALID CHOICE. ENTER 1. IF YES & 2. FOR NO\n";
                cin >> yes;
            }
            if (yes == 1)
            {
                ofstream datafile("customer1.txt", ios::app);
                bool isLoggedIn = false;
                while (!isLoggedIn)
                {
                    ofstream datafile("customer1.txt", ios::app);
                    cout << "\t\t\t\t\tENTER YOUR NAME: \n\t\t\t\t\t";
                    cin >> name;
                    cout << "\t\t\t\t\tENTER YOUR PASSWORD:\n \t\t\t\t\t";
                    cin >> enteredPassword;
                    isLoggedIn = newcustomer.login(enteredPassword);
                    system("pause");
                    system("cls");
                    if (!isLoggedIn)
                    {
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\n";
                        cout << "\t\t\t\t\t\tINCORRECT PASSWORD. WOULD YOU LIKE TO TRY AGAIN OR CREATE A NEW ACCOUNT?\n";
                        cout << "\t\t\t\t\t\t============================\n";
                        cout << "\t\t\t\t\t\t| 1. Try again              |\n";
                        cout << "\t\t\t\t\t\t| 2. Create new account     |\n";
                        cout << "\t\t\t\t\t\t============================\n";
                        cout << "\t\tEnter your choice: ";
                        int choice1;
                        while (!(cin >> choice1))
                        {
                            cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                        if (choice1 == 2)
                        {
                            cout << "\t\tEnter ID: ";
                            cin >> id;
                            cout << "\t\tEnter Name: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "\t\tEnter Password: ";
                            cin >> password;
                            cout << "\t\tEnter Email: ";
                            cin >> email;
                            role = "customer";
                            newcustomer.createAccount(id, name, password, email, role);
                            system("pause");
                            system("cls");
                            break;

                        }
                    }
                }
            }
            else
            {
                cout << "\t\t\t\t\tEnter ID: ";
                cin >> id;
                cout << "\t\t\t\t\tEnter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\t\t\tEnter Password: ";
                cin >> password;
                cout << "\t\t\t\t\tEnter Email: ";
                cin >> email;
                role = "customer";
                newcustomer.createAccount(id, name, password, email, role);
                system("pause");
                system("cls");
            }


            int customerChoice;
            do
            {
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\t\t\t\t\t==============================\n";
                cout << "\t\t\t\t\t|        CUSTOMER MENU       |\n";
                cout << "\t\t\t\t\t==============================\n";
                cout << "\t\t\t\t\t| 1. View products           |\n";
                cout << "\t\t\t\t\t| 2. Add to cart             |\n";
                cout << "\t\t\t\t\t| 3. Remove from cart        |\n";
                cout << "\t\t\t\t\t| 4. Checkout                |\n";
                cout << "\t\t\t\t\t| 5. reset password          |\n";
                cout << "\t\t\t\t\t| 6. reset user name         |\n";
                cout << "\t\t\t\t\t| 7. user details            |\n";
                cout << "\t\t\t\t\t==============================\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 14);
                cout << "===========================================================================================================================\n";
                cout << "MY CART=[99]                                  ABOUT US=[90]                                             BACK=[0]\n";
                cout << "============================================================================================================================\n";
                SetConsoleTextAttribute(hConsole, 7);
                while (!(cin >> customerChoice))
                {
                    cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                  system("pause");
                    system("cls");
                switch (customerChoice)
                {

                case 1:
                {
                    int cc;
                    string cato;
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\t\t\t\t\tChoose Filter: " << endl;
                    cout << "\t\t\t\t\t1. View All Products." << endl;
                    cout << "\t\t\t\t\t2. View By Catagory." << endl;
                    cout << "\t\t\t\t\t3. View By Name." << endl;
                    cout << "\t\t\t\t\t> ";
                    while (!(cin >> cc))
                    {
                        cout << "\n\t\t\t\t\t\t[ERROR] > Wrong Input! Enter Again: ";
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                        switch (cc)
                        {
                        case 1: {newcustomer.viewProducts();
                            break;
                        }
                        case 2: 
                        { 
                            system("cls");
                            cout << "\n\t\t\t\t--------------------------------";
                            cout << "\n\t\t\t\t\tChoose Catagory:"; 
                            cout << "\n\t\t\t\t\t1. Western wear";
                            cout << "\n\t\t\t\t\t2. Summer Wear";
                            cout << "\n\t\t\t\t\t3. Bottom wear";
                            cout << "\n\t\t\t\t\t4. Sleep wears";
                            cout << "\n\t\t\t\t\t5. Foot Wears";
                            cout << "\n\t\t\t\t\t6. Winter Wear";
                            cout << "\n\t\t\t\t\t7. Kids Wear";
                            cout << "\n\t\t\t\t\t8. Accessories\n";
                            cout << "\n\t\t\t\t--------------------------------\n>";
                            while (!(cin >> cc))
                            {
                                cout << "\n\t\t\t\t\t\t[ERROR] > Wrong Input! Enter Again: ";
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                            switch (cc)
                            {
                            case 1:
                                cato = "WESTERN-WEAR";
                                break;
                            case 2: 
                                cato = "SUMMER-WEAR";
                                break;
                            case 3:
                                cato = "BOTTOM-WEAR";
                                break;
                            case 4:
                                cato = "SLEEP-WEAR"; 
                                break;
                            case 5:
                                cato = "FOOT-WEAR";
                                break;
                            case 6: 
                                cato = "WINTER-WEAR";
                                break;
                            case 7: 
                                cato = "KIDS-WEAR";
                                break;
                            case 8: 
                                cato = "OTHERS";
                                break;
                            }
                            newcustomer.viewProdbycato(cato); 
                            break; 
                        }
                        case 3: 
                        {
                            string nam;
                            cout << "\n\t\t\t\t\t\t--------------------------------";
                            cout << "\n\t\t\t\t\tEnter Name of Product:";
                            cout << "\n\t\t\t\t\t\t--------------------------------";
                            cin.ignore();
                            getline(cin, nam);
                            newcustomer.viewProdbyname(nam); 
                            break; 
                        }
                        }
                    system("pause");
                    system("cls");
                    break;
                }
               
                case 2:
                {
                    newcustomer.addToCart();
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    newcustomer.removeFromCart();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    newcustomer.placeOrder();
                    newcustomer.generate();
                    newcustomer.clear_cart();
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    int newPassword;
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------";
                    cout << "\n\t\t\t\t\t\t\tENTER NEW PASSWORD:\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------\n\t\t\t\t\t\t\t\t";
                    cin >> newPassword;
                    newcustomer.resetPassword(newPassword);
                    cout << "\t\t\t\t\t\t\tPASSWORD RESETTED:)\n";
                    system("pause");
                    system("cls");
                    break;
                }
                case 6:
                {
                    string newUsername;
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------";
                    cout << "\n\t\t\t\t\t\tENTER NEW NAME: ";
                    cout << "\n\t\t\t\t\t\t--------------------------------\n\t\t\t\t\t\t";
                    cin.ignore();
                    getline(cin, newUsername);
                    newcustomer.changeUsername(newUsername);
                    cout << "\t\t\t\t\t\tUSER NAME IS CHANGED.\n";
                    system("pause");
                    system("cls");
                    break;
                }
                case 7:
                {
                    newcustomer.displayDetails();
                    system("pause");
                    system("cls");
                    break;
                }
                case 99:
                {
                    newcustomer.viewItems();
                    system("pause");
                    system("cls");
                    break;
                }
                case 90:
                {
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------";
                    cout << "\n\t\t\t\t\t\tPROJECT DONE BY: HEER";
                    cout << "\n\t\t\t\t\t\tROLL NUMBER =22I-2371";
                    cout << "\n\t\t\t\t\t\tCONTACT=XXXXXXXXXXXXXXX";
                    cout << "\n\t\t\t\t\t\t--------------------------------";
                    system("pause");
                    system("cls");
                    break;
                }
                case 0:
                {
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------";
                    cout << "\n\t\t\t\t\t\tThank you for using MyShop!\n";
                    cout << "\n\t\t\t\t\t\t--------------------------------\n";
                    newcustomer.clear_cart();
                    system("pause");
                    system("cls");
                    break;

                }
                }
            } while (customerChoice != 0);
            system("cls");
            break;
        }
         case 2:
         {
             admin newadmin;

             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\t|       Admin  Mode          |\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\t| 1. Registered user         |\n";
             cout << "\t\t\t\t\t\t| 2. New user                |\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\tEnter your choice: ";
             while (!(cin >> yes))
             {
                 cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                 cin.clear();
                 cin.ignore(100, '\n');
             }
             while (yes != 1 && yes != 2)
             {
                 cout << "\t\tINVALID CHOICE. ENTER 1. IF YES & 2. FOR NO\n";
                 cin >> yes;
             }
             if (yes == 1)
             {
                 bool isLoggedIn = false;
                 while (!isLoggedIn)
                 {

                     cout << "\t\tENTER YOUR PASSWORD:\n \t\t";
                     cin >> enteredPassword;
                     isLoggedIn = newadmin.login(enteredPassword);
                     system("pause");
                     system("cls");
                     if (!isLoggedIn)
                     {
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\t\t\t\t\t\tINCORRECT PASSWORD. WOULD YOU LIKE TO TRY AGAIN OR CREATE A NEW ACCOUNT?\n";
                         cout << "\t\t\t\t\t\t============================\n";
                         cout << "\t\t\t\t\t\t| 1. Try again              |\n";
                         cout << "\t\t\t\t\t\t| 2. Create new account     |\n";
                         cout << "\t\t\t\t\t\t============================\n";
                         cout << "\t\t\t\t\t\tEnter your choice: ";
                         int choice1;
                         while (!(cin >> choice1))
                         {
                             cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                             cin.clear();
                             cin.ignore(100, '\n');
                         }
                         if (choice1 == 2)
                         {
                             cout << "\t\t\t\t\t\tEnter ID: ";
                             cin >> id;
                             cout << "\t\t\t\t\t\tEnter Name: ";
                             cin.ignore();
                             getline(cin, name);
                             cout << "\t\t\t\t\t\tEnter Password: ";
                             cin >> password;
                             cout << "\t\t\t\t\t\tEnter Email: ";
                             cin >> email;
                             role = "Admin";
                             newadmin.createAccount(id, name, password, email, role);
                             system("pause");
                             system("cls");
                             break;

                         }
                     }
                 }
             }
             else
             {
                 cout << "\t\t\t\t\t\tEnter ID: ";
                 cin >> id;
                 cout << "\t\t\t\t\t\tEnter Name: ";
                 cin.ignore();
                 getline(cin, name);
                 cout << "\t\t\t\t\t\tEnter Password: ";
                 cin >> password;
                 cout << "\t\t\t\t\t\tEnter Email: ";
                 cin >> email;
                 role = "Admin";
                 newadmin.createAccount(id, name, password, email, role);
                 system("pause");
                 system("cls");
             }


             int adminChoice1;
             do
             {
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\t\t\t\t\t\t|        ADMIN    MENU       |\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\t\t\t\t\t\t| 1. order product           |\n";
                 cout << "\t\t\t\t\t\t| 2. Update product          |\n";
                 cout << "\t\t\t\t\t\t| 3. Remove product          |\n";
                 cout << "\t\t\t\t\t\t| 4. View products           |\n";
                 cout << "\t\t\t\t\t\t| 5. add product             |\n";
                 cout << "\t\t\t\t\t\t| 6. Add vendor              |\n";
                 cout << "\t\t\t\t\t\t| 7. reset password          |\n";
                 cout << "\t\t\t\t\t\t| 8. reset user name         |\n";
                 cout << "\t\t\t\t\t\t| 9. user details            |\n";
                 cout << "\t\t\t\t\t\t| 10. Customer Invoice       |\n";
                 cout << "\t\t\t\t\t\t| 11. Vendor Invoice         |\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\n\n\n\n\n\n\n\n\n\n\n";
                 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                 SetConsoleTextAttribute(hConsole, 5);
                 cout << "===========================================================================================================================\n";
                 cout << "ABOUT US=[90]                                                                                                     BACK=[0]\n";
                 cout << "============================================================================================================================\n";
                 SetConsoleTextAttribute(hConsole, 7);
                 cout << "\t\t\t\t\t\tEnter your choice: ";
                 while (!(cin >> adminChoice1))
                 {
                     cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                     cin.clear();
                     cin.ignore(100, '\n');
                 }
                 system("pause");
                 system("cls");
                 switch (adminChoice1)
                 {
                 case 1: {
                     string name, cato;
                     int quantity,c;

                     cout << "\t\t\t\t\t\t\t\tChoose Catagory: ";
                     cout << "\n\t\t\t\t\t\t\t1. Western wear";
                     cout << "\n\t\t\t\t\t\t\t2. Summer Wear";
                     cout << "\n\t\t\t\t\t\t\t3. Bottom wear";
                     cout << "\n\t\t\t\t\t\t\t4. Sleep wears";
                     cout << "\n\t\t\t\t\t\t\t5. Foot Wears";
                     cout << "\n\t\t\t\t\t\t\t6. Winter Wear";
                     cout << "\n\t\t\t\t\t\t\t7. Kids Wear";
                     cout << "\n\t\t\t\t\t\t\t8. Accessories\n";
                     while (!(cin >> c))
                     {
                         cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                         cin.clear();
                         cin.ignore(100, '\n');
                     }
                     switch (c) {
                     case 1:
                         cato = "WESTERN-WEAR";
                         break;
                     case 2:
                         cato = "SUMMER-WEAR";
                         break;
                     case 3:
                         cato = "BOTTOM-WEAR";
                         break;
                     case 4: 
                         cato = "SLEEP-WEAR";
                         break;
                     case 5:
                         cato = "FOOT-WEAR";
                         break;
                     case 6:
                         cato = "WINTER-WEAR";
                         break;
                     case 7:
                         cato = "KIDS-WEAR";
                         break;
                     case 8:
                         cato = "OTHERS"; 
                         break;
                     }
                     cout << "\t\t\t\t\t\t\tEnter product name you want: ";
                     cin.ignore();
                     getline(cin, name);
                     cout << "\t\t\t\t\t\t\tEnter product quantity you want: ";
                     cin >> quantity;
                     orderbook odb(name, cato, quantity, false);
                     odb.order_stock();
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 2:
                 {
                     cout << "\t\t\t\t\t\t\t\tEnter product name to update: ";
                     cin.ignore();
                     getline(cin, name);
                     newadmin.updateProduct(name);
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 3:
                 {
                     string name;
                     cout << "\t\t\t\t\t\t\t\tEnter product name to remove : ";
                     cin.ignore();
                     getline(cin, name);
                     newadmin.removeProduct(name);
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 4:
                 {
                     cout << "\t\t\t\t\t\t\t\tProduct List:" << endl;
                     newadmin.viewProducts();
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 5:
                 {
                     newadmin.addProduct();
                     ofstream outfile("orderbook.txt");
                     outfile << "";
                     outfile.close();
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 6:
                 {
                     cout << "\t\t\t\t\t\tEnter ID: ";
                     cin >> id;
                     cout << "\t\t\t\t\t\tEnter Name: ";
                     cin.ignore();
                     getline(cin, name);
                     cout << "\t\t\t\t\t\tEnter Password: ";
                     cin >> password;
                     cout << "\t\t\t\t\t\tEnter Email: ";
                     cin >> email;
                     role = "Vendor";
                     newvendor.createAccount(id, name, password, email, role);
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 7:
                 {
                     int newPassword;
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     cout << "\n\t\t\t\t\t\t\tENTER NEW PASSWORD:\n";
                     cout << "\n\t\t\t\t\t\t--------------------------------\n\t\t\t\t\t\t\t\t";
                     cin >> newPassword;
                     newadmin.resetPassword(newPassword);
                     cout << "\t\t\t\t\t\tPASSWORD RESETTED:)\n";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 8:
                 {
                     string newUsername;
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     cout << "\n\t\t\t\t\t\tENTER NEW NAME: ";
                     cout << "\n\t\t\t\t\t\t--------------------------------\n\t\t\t\t\t\t\t\t";
                     cin.ignore();
                     getline(cin, newUsername);
                     newadmin.changeUsername(newUsername);
                     cout << "\t\tADMIN NAME IS CHANGED.\n";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 9:
                 {
                     newadmin.displayDetails();
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 10:
                 {
                     newadmin.details.print_details("customer_Invoice.txt");
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 11:
                 {
                     newadmin.details.print_details("Vendor_Invoice.txt");
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 90:
                 {
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     cout << "\n\t\t\t\t\t\tPROJECT DONE BY: HEER";
                     cout << "\n\t\t\t\t\t\tROLL NUMBER =22I-2371";
                     cout << "\n\t\t\t\t\t\tCONTACT=XXXXXXXXXXXXXXX";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 0:
                 {
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\t\t\t\t\t\t\tALL CHANGES HAVE BEEN MADE!\n";
                     system("pause");
                     system("cls");
                 }
                 }
             } while (adminChoice1 != 0);
             system("cls");
             break;
         }
         case 3:
         {
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\t|       Vendor  Mode         |\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\t| 1. Registered user         |\n";
             cout << "\t\t\t\t\t\t==============================\n";
             cout << "\t\t\t\t\t\tEnter your choice: ";
             while (!(cin >> yes))
             {
                 cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                 cin.clear();
                 cin.ignore(100, '\n');
             }
             while (yes != 1)
             {
                 cout << "\t\t\t\t\t\tINVALID CHOICE. ENTER 1. IF YES & 2. FOR NO\n";
                 while (!(cin >> yes))
                 {
                     cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                     cin.clear();
                     cin.ignore(100, '\n');
                 }
             }
             if (yes == 1)
             {
                 bool isLoggedIn = false;
                 while (!isLoggedIn)
                 {
                     cout << "\t\t\t\t\t\tENTER YOUR PASSWORD:\n \t\t";
                     cin >> enteredPassword;
                     isLoggedIn = newvendor.login(enteredPassword);
                     system("pause");
                     system("cls");
                     if (!isLoggedIn)
                     {
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\n";
                         cout << "\t\t\t\t\t\tINCORRECT PASSWORD. WOULD YOU LIKE TO TRY AGAIN OR CREATE A NEW ACCOUNT?\n";
                         cout << "\t\t\t\t\t\t============================\n";
                         cout << "\t\t\t\t\t\t| 1. Try again              |\n";
                         cout << "\t\t\t\t\t\t============================\n";
                         cout << "\t\t\t\t\t\tEnter your choice: ";
                         int choice1;
                         while (!(cin >> choice1))
                         {
                             cout << "\n[ERROR] > Wrong Input! Enter Again: ";
                             cin.clear();
                             cin.ignore(100, '\n');
                         }
                         
                     }
                 }
             }
         

             int vendorChoice1;
             do
             {
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\t\t\t\t\t\t|        VENDOR    MENU       |\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\t\t\t\t\t\t| 1. Restock products         |\n";
                 cout << "\t\t\t\t\t\t| 2. reset password           |\n";
                 cout << "\t\t\t\t\t\t| 3. reset user name          |\n";
                 cout << "\t\t\t\t\t\t| 4. Vendor details           |\n";
                 cout << "\t\t\t\t\t\t==============================\n";
                 cout << "\n\n\n\n\n\n\n\n";
                 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                 SetConsoleTextAttribute(hConsole, 3);
                 cout << "===========================================================================================================================\n";
                 cout << "ABOUT US=[90]                                                                                                     BACK=[0]\n";
                 cout << "============================================================================================================================\n";
                 SetConsoleTextAttribute(hConsole, 7);
                 cout << "\t\t\t\t\t\tEnter your choice: ";
                 while (!(cin >> vendorChoice1))
                 {
                     cout << "\n\t\t\t\t[ERROR] > Wrong Input! Enter Again: ";
                     cin.clear();
                     cin.ignore(100, '\n');
                 }
                 system("pause");
                 system("cls");
                 switch (vendorChoice1)
                 {

                 case 1:
                      {
                         newvendor.confirm();
                         newvendor.gen_invoice();
                          system("pause");
                          system("cls");
                          break;
                      }
                 case 2:
                 {
                     int newPassword;
                     cout << "\t\t\t\t\t\tENTER NEW PASSWORD: ";
                     cin >> newPassword;
                     newvendor.resetPassword(newPassword);
                     cout << "\t\t\t\t\ttPASSWORD RESETTED:)\n";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 3:
                 {
                     string newUsername;
                     cout << "\t\t\t\t\t\tENTER NEW NAME: ";
                     cin.ignore();
                     getline(cin, newUsername);
                     newvendor.changeUsername(newUsername);
                     cout << "\t\t\t\t\t\tVENDOR NAME IS CHANGED.\n";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 4:
                 {
                     newvendor.displayDetails();
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 90:
                 {
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     cout << "\n\t\t\t\t\t\tPROJECT DONE BY: HEER";
                     cout << "\n\t\t\t\t\t\tROLL NUMBER =22I-2371";
                     cout << "\n\t\t\t\t\t\tCONTACT=XXXXXXXXXXXXXXX";
                     cout << "\n\t\t\t\t\t\t--------------------------------";
                     system("pause");
                     system("cls");
                     break;
                 }
                 case 0:
                 {
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\n";
                     cout << "\t\t\t\t\t\tALL CHANGES HAVE BEEN MADE!\n";
                     system("pause");
                     system("cls");
                     break;
                 }
                 }
             } while (vendorChoice1 != 0);
         }
        }

        }while (choice != 0);
        invoice obj;
        obj.cal_grand("customer_Invoice.txt");
        obj.cal_grand("Vendor_Invoice.txt");
    return 0;
}
