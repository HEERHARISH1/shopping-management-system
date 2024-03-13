#pragma once
#include<iostream>
#include <windows.h>
#include <string>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
class orderbook {
private:
	int sk;
	string name;
	string catagory;
	int quantity;
	bool status;
	int price;
public:
	orderbook();
	orderbook(string, string, int, bool);
	void order_stock();
	void confirm();
};
class invoice {
private:
	int id;
	char time[26];
	string name;
	int total_items;
	int total_price;
	int sub_total;
public:
	invoice();
	invoice(int, string, int, int);
	void setname(string);
	void setitems(int);
	void settotal(int);
	void setgrand(int);
	int getid();
	void setid(int);
	string gettime();
	string getname();
	int getitems();
	int getprice();
	int getgrand();
	void write_vendor();
	void write_customer();
	void cal_grand(string);
	void clear(string);
	void print_details(string);
};
class user
{
protected:
	int* no;//dynamic
	string id;
	string name;
	int password;
	string email;
	string role;
	 
public:
	user();
	user(string _id, string _name, int _password, string _email, string _role);
	string getname();
	string getemail();
	string getrole();
	string getid();
	int getpass();
	void setno(int value);
	int getno()const;
	void setname(string);
	void setid(string);
	void setemail(string);
	void setrole(string);
	virtual void display();
	void setpass(int);
	~user();
};
class Product
{
private:
	user* obj;
	string catagory;
	string _name;
	float price;
	int quantity;
	int sku;
public:
	

	Product();
	Product(string _name, float _price, int _quantity,string catagory,int sk);
	string getName();
	int getsku();
	string getcatagory();
	float getPrice();
	int getQuantity();
	void addProduct();
	void updateProduct(string name);
	void updateQuatity();
	void removeProduct(string name);
	void viewProducts();
	void viewProdbycato(string);
	void viewProdbyname(string);
	bool search_prod(string,int);


};
class admin : public Product,user //inheritance
{
public:
	user* obj;
	admin();
	invoice details;
	void createAccount(string _id, string _name, int _password, string _email, string _role);
	bool login(int _password);
	void resetPassword(int _newPassword);
	void changeUsername(string _newUsername);
	void displayDetails();
	void saveToFile();
};
class vendor : public orderbook,user
{
private:
	user* obj;
	invoice vend;
public:
	vendor();
	void createAccount(string _id, string _name, int _password, string _email, string _role);
	bool login(int _password);
	void resetPassword(int _newPassword);
	void changeUsername(string _newUsername);
	void displayDetails();
	void saveToFile();
	void gen_invoice();
};
class Cart:public Product
{
private:
	string items;
	
public:
	Cart();
	void addItem(string item,int);
	void removeItem(string item);
	void viewItems();
	float calculateTotal();
	void checkout(string,long,string,string,int,string,string,string,string);
	void clear();
	void store(string);
	
};
class customer :public Cart,user
{
private:
	string address;
	string phone;
	float payment;
	Product obj;
	invoice cust;
public:
	customer();
	void setAddress(string _address);
	bool login(int _password);
	void resetPassword(int _newPassword);
	string getAddress();
	void setPhone(string _phone);
	string getPhone();
	void changeUsername(string _newUsername);
	void displayDetails();
	void saveToFile();
	void createAccount(string _id, string _name, int _password, string _email, string _role);
	void addToCart();
	void clear_cart();
	void removeFromCart();
	void placeOrder();
	void generate();
};
