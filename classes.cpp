#include "heersp.h"
user::user()
{
	this->no = new int;
	this->id = " ";
	this->name = " ";
	this->password = 0;
	this->email = " ";
	this->role = " ";
}
user::user(string _id, string _name, int _password, string _email, string _role)
{
	id = _id;
	name = _name;
	password = _password;
	email = _email;
	role = _role;
}
string user::getname()
{
	return name;
}
string user::getemail() {
	return email;
}
string user::getrole() {
	return role;
}
string user::getid() {
	return id;
}
int user::getpass() {
	return password;
}
void user:: setno(int value) 
{
	*no = value;  // Set the value of the dynamically allocated integer
}
int user::getno() const
{
	return *no;  // Retrieve the value of the dynamically allocated integer
}
void user::setname(string n) {
	name = n;
}
void user::setid(string i) {
	id = i;
}
void user::setemail(string em) {
	email = em;
}
void user::setrole(string ro) {
	role = ro;
}
void user::display() 
{
}
void user::setpass(int pass) {
	password = pass;
}
user::~user() 
{
	delete no;  // Deallocate the memory in the destructor
}
void customer::createAccount(string _id, string _name, int _password, string _email, string _role)
{
	setid(_id);
	setname(_name);
	setpass(_password);
	setemail(_email);
	setrole(_role);
	// Open the file in append mode and write the data
	ofstream datafile("customer1.txt", ios::app);
	if (datafile.is_open())
	{
		datafile << _id << "\t" << _name << "\t" << _password << "\t" << _email << "\t" << _role << endl;
		datafile.close(); // Close the file after writing
	}
	else
	{
		cout << "Unable to open the file for writing." << endl;
	}
}
bool customer::login(int _password)
{
	string id, name, email, role;
	int password;
	ifstream searchfile("customer1.txt", ios::in); 

	while (searchfile >> id >> name >> password >> email >> role)
	{
		if (password == _password)
		{
			cout << "\t\t\t\t\t\t----------------------------------------\n";
			cout << "\t\t\t\t\t\t                  WELCOME\n";
			cout << "\t\t\t\t\t\t-----------------------------------------\n";
			setid(id);
			setname(name);
			setpass(password);
			setemail(email);
			setrole(role);
			searchfile.close(); 
			return true;
		}
	}

	cout << "\t\t\t\t\t\twrong password\n";
	searchfile.close();
	return false;
}
void customer:: resetPassword(int _newPassword)
{
	setpass(_newPassword);
	saveToFile(); // Save changes to the text file
}
void customer::saveToFile()
{
	string id; string name; int password; string email; string role;
	ifstream infile("customer1.txt");
	ofstream datafile("temp.txt", ios::app);
	while (infile >> id >> name >> password >> email >> role) {
		if (getid() != id) {
			datafile << id << "\t" << name << "\t" << password << "\t" << email << "\t" << role << endl;
		}
		else if (getid() == id && getrole() == role && getemail() == email) {
			datafile << getid() << "\t" << getname() << "\t" << getpass() << "\t" << getemail() << "\t" << getrole() << endl;
		}
	}
	infile.close();
	datafile.close();
	remove("customer1.txt");
	rename("temp.txt", "customer1.txt");
}
void customer:: changeUsername(std::string _newUsername)
{
	setname(_newUsername);
	saveToFile(); // Save changes to the text file
}
void customer::displayDetails()
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
		cout << "\t\t\t\t\t\t---------------------\n";
		cout << "\t\t\t\t\t\tID: " << getid() << endl;
		cout << "\t\t\t\t\t\tName: " << getname() << endl;
		cout << "\t\t\t\t\t\tpassword: " << getpass() << endl;
		cout << "\t\t\t\t\t\tEmail: " << getemail() << endl;
		cout << "\t\t\t\t\t\tROLE: " << getrole() << endl;
	    cout << "\t\t\t\t\t\t---------------------\n";
}
customer::customer()
{
    address = "";
    phone = "";
    payment = 0;
}
void customer::setAddress(string _address)
{
    address = _address;
}
string customer::getAddress() 
{
    return address;
}
void customer::setPhone(string _phone) 
{
    phone = _phone;
}
string customer::getPhone()
{
    return phone;
}
void customer::addToCart() {
	string item; int quantity;
	cout << "\nEnter Name of Product: ";
	cin >> item;
	cout << "\nEnter Quantity of Product: ";
	cin >> quantity;
	if (obj.search_prod(item,quantity)) {
		addItem(item,quantity);
	}
	else
		cout << "Product not found (or) Out of Stock!\n";
}
void customer::clear_cart() {
	clear();
}
void customer::removeFromCart() {
	string item;
	cout << "\nEnter Name of Product: ";
	cin >> item;
	removeItem(item);
}
void customer::placeOrder() {
	int pass;
	string name;
	long phone;
	string address;
	string email;
	int zip;
	string country;
	string province;
	int ch;
	string promo;
	string payment;
	cin.ignore();
	cout << "\t\tEnter Name: ";
	getline(cin, name);
	cout << "\t\tEnter Email: ";
	getline(cin, email);
	cout << "\t\tEnter Address: ";
	getline(cin, address);
	cout << "\t\tEnter country: ";
	getline(cin, country);
	cout << "\t\tEnter Province: ";
	getline(cin, province);
	cout << "\t\tEnter Phone # ";
	cin >> phone;
	cout << "\t\tEnter Zip Code: ";
	cin >> zip;
	cout << "\t\tPayment Method\n";
	cout << "\t\t1.	COD\n";
	cout << "\t\t2.	Online\n";
	cout << "\t\t> ";
	cin >> ch;
	if (ch == 1)
		payment = "COD";
	else if (ch == 2) {
		payment = "Online";
		cin.ignore();
		string temp_data;
		int t;
		cout << "\t\tEnter Bank Name: ";
		getline(cin, temp_data);
		cout << "\t\tEnter Account # ";
		getline(cin, temp_data);
		cout << "\t\tEnter Security Code(CVV): ";
		cin >> t;
	}
	cout << "\t\tYou want to apply any promo code?";
	cout << "\n\t\t1.	Yes";
	cout << "\n\t\t2.	NO";
	cout << "\n\t\t> ";
	cin >> ch;
	if (ch == 1) {
		cout << "\t\tEnter Promo Code: ";
		cin >> promo;
	}
	else if (ch == 2)
		promo = "nill";
	cout << "Enter Your Password to Proceed: ";
	cin >> pass;
	if (getpass() == pass)
	{
		obj.updateQuatity();
		checkout(name, phone, address, email, zip, country, province, payment, promo);
	}
	else
		cout << "Wrong Password. Try Again!";
}
void customer::generate() {
	ifstream infile("cart.txt");
	string Name = "";
	int Price = 0;
	int Quantity = 0;
	int sk;
	while (infile >> sk >> Name >> Price >> Quantity)
	{
			cust.setname(Name);
			cust.setitems(Quantity);
			cust.settotal(Price);
			cust.setid(sk);
			cust.write_customer();
	}

	infile.close();
}

admin::admin()
{
}
void admin::createAccount(string _id, string _name, int _password, string _email, string _role)
{
	setid(_id);
	setname(_name);
	setpass(_password);
	setemail(_email);
	setrole(_role);
	// Open the file in append mode and write the data
	ofstream datafile("admin.txt", ios::app);
	if (datafile.is_open())
	{
		datafile << _id << "\t" << _name << "\t" << _password << "\t" << _email << "\t" << _role << endl;
		datafile.close(); // Close the file after writing
	}
	else
	{
		cout << "\t\t\t\t\t\tUnable to open the file for writing." << endl;
	}
}
bool admin::login(int _password)
{
	string id, name, email, role;
	int password;
	ifstream searchfile("admin.txt", ios::in);

	while (searchfile >> id >> name >> password >> email >> role)
	{
		if (password == _password)
		{
			cout << "\t\t\t\t\t\t----------------------------------------\n";
			cout << "\t\t\t\t\t\t                  WELCOME\n";
			cout << "\t\t\t\t\t\t-----------------------------------------\n";
			setid(id);
			setname(name);
			setpass(password);
			setemail(email);
			setrole(role);
			searchfile.close();
			return true;
		}
	}

	cout << "\t\twrong password\n";
	searchfile.close();
	return false;
}
void admin::resetPassword(int _newPassword)
{
	setpass(_newPassword);
	saveToFile(); 
}
void admin::saveToFile()
{
	string _id; string _name; int _password; string _email; string _role;
	ifstream infile("admin.txt");
	ofstream datafile("temp.txt",ios::app);
	while (infile >> _id >> _name >> _password >> _email >> _role) {
		if (getid() != _id) {
			datafile << _id << "\t" << _name << "\t" << _password << "\t" << _email << "\t" << _role << endl;
		}
		else if (getid() == _id && getrole() == _role && getemail() == _email) {
			datafile << getid() << "\t" << getname() << "\t" << getpass() << "\t" << getemail() << "\t" << getrole() << endl;
		}
	}
	infile.close();
	datafile.close();
	remove("admin.txt");
	rename("temp.txt", "admin.txt");
}
void admin::changeUsername(string _newUsername)
{
	setname(_newUsername);
	saveToFile(); // Save changes to the text file
}
void admin::displayDetails()
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
	cout << "\t\t\t\t\t\t---------------------\n";
	cout << "\t\t\t\t\t\tID: " << getid() << endl;
	cout << "\t\t\t\t\t\tName: " << getname() << endl;
	cout << "\t\t\t\t\t\tpassword: " << getpass() << endl;
	cout << "\t\t\t\t\t\tEmail: " << getemail() << endl;
	cout << "\t\t\t\t\t\tROLE: " << getrole() << endl;
	cout << "\t\t\t\t\t\t---------------------\n";
}


vendor::vendor()
{
}
void vendor::createAccount(string _id, string _name, int _password, string _email, string _role)
{
	setid(_id);
	setname(_name);
	setpass(_password);
	setemail(_email);
	setrole(_role);

	// Open the file in append mode and write the data
	ofstream datafile("vendor.txt", ios::app);
	if (datafile.is_open())
	{
		datafile << _id << "\t" << _name << "\t" << _password << "\t" << _email << "\t" << _role << endl;
		datafile.close(); // Close the file after writing
	}
	else
	{
		cout << "Unable to open the file for writing." << endl;
	}
}
bool vendor::login(int _password)
{
	string id, name, email, role;
	int password;
	ifstream searchfile("vendor.txt", ios::in);

	while (searchfile >> id >> name >> password >> email >> role)
	{
		if (password == _password)
		{
			cout << "\t\t\t\t\t\t----------------------------------------\n";
			cout << "\t\t\t\t\t\t                  WELCOME\n";
			cout << "\t\t\t\t\t\t-----------------------------------------\n";
			setid(id);
			setname(name);
			setpass(password);
			setemail(email);
			setrole(role);
			searchfile.close();
			return true;
		}
	}

	cout << "\t\twrong password\n";
	searchfile.close();
	return false;
}
void vendor::resetPassword(int _newPassword)
{
	setpass(_newPassword);
	saveToFile();
}
void vendor::saveToFile()
{
	string _id; string _name; int _password; string _email; string _role;
	ifstream infile("vendor.txt");
	ofstream datafile("temp.txt", ios::app);
	while (infile >> _id >> _name >> _password >> _email >> _role) {
		if (getid() != _id) {
			datafile << _id << "\t" << _name << "\t" << _password << "\t" << _email << "\t" << _role << endl;
		}
		else if (getid() == _id && getrole() == _role && getemail() == _email) {
			datafile << getid() << "\t" << getname() << "\t" << getpass() << "\t" << getemail() << "\t" << getrole() << endl;
		}
	}
	infile.close();
	datafile.close();
	remove("vendor.txt");
	rename("temp.txt", "vendor.txt");
}
void vendor::changeUsername(std::string _newUsername)
{
	setname(_newUsername);
	saveToFile(); // Save changes to the text file
}
void vendor::displayDetails()
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
	cout << "\t\t\t\t\t\t---------------------\n";
	cout << "\t\t\t\t\t\tID: " << getid() << endl;
	cout << "\t\t\t\t\t\tName: " << getname() << endl;
	cout << "\t\t\t\t\t\tpassword: " << getpass() << endl;
	cout << "\t\t\t\t\t\tEmail: " << getemail() << endl;
	cout << "\t\t\t\t\t\tROLE: " << getrole() << endl;
	cout << "\t\t\t\t\t\t---------------------\n";
}
void vendor::gen_invoice() {
	ifstream infile("orderbook.txt");
	string Name = "";
	string cata = "";
	bool status;
	int Price = 0;
	int Quantity = 0;
	int sk;
	while (infile >> sk >> Name >> Price >> Quantity >> cata >> status)
	{
		if (status == true)
		{
			vend.setname(Name);
			vend.setitems(Quantity);
			vend.settotal(Price * Quantity);
			vend.setid(sk);
			vend.write_vendor();
		}
	}

	infile.close();
}

Product::Product() 
{
	_name = "";
	price = 0.0f;
	quantity = 0;
	catagory = "";
	sku = 0;
}
Product::Product(string _name, float _price, int _quantity,string catagory,int sk)
{
	this->_name = _name;
	this->price = _price;
	this->quantity = _quantity;
	this->catagory = catagory;
	this->sku = sk;
}
string Product::getName() 
{
	return _name;
}
string Product::getcatagory() {
	return catagory;
}
float Product::getPrice()
{
	return price;
}
int Product::getsku() {
	return sku;
}
int Product::getQuantity() 
{
	return quantity;
}
void Product::addProduct() {
	ifstream infile("orderbook.txt");
	ofstream outfile("products.txt", ios::app);
	bool status;
	while (infile >> sku >> _name >> price >> quantity >> catagory >> status) {
		if (status == true) {
			cout << "\nName of product: " << _name;
			cout << "\nCatagory of product: " << catagory;
			cout << "\nQuantity of product: " << quantity;
			cout << "\nStatus of Product: " << status;
			cout << "\nPurchase price of Product: " << price;
			cout << "\nEnter Selling Price of product: "; cin >> price;
			outfile <<sku << "\t" << _name << "\t" << price << "\t" << quantity << "\t" << catagory << endl;
		}
	}
	infile.close();
	outfile.close();

	cout << "Product added successfully." << endl;
}
void Product::updateProduct(string name) {
	ifstream infile("products.txt");
	ofstream outfile("temp.txt",ios::app);

	while (infile >> sku >> _name >> price >> quantity >> catagory) {
		if (_name != name) {
			outfile << sku << "\t" << _name << "\t" << price << "\t" << quantity << "\t" << catagory << endl;
		}
		else {
			cout << "Enter updated price for " << _name << ": ";
			cin >> price;
			outfile << sku << "\t" << _name << "\t" << price << "\t" << quantity << "\t" << catagory << endl;
		}
	}

	infile.close();
	outfile.close();

	remove("products.txt");
	rename("temp.txt", "products.txt");

	cout << "Product updated successfully." << endl;
}
void Product::updateQuatity() {
	ifstream infile("cart.txt");
	ifstream ifile("products.txt");
	ofstream outfile("temp.txt", ios::app);

	string nme; float pr; int q,sk;
	while (ifile >> sku >> _name >> price >> quantity >> catagory) {  // Read from product.txt
		bool found = false;

		while (infile >> sk >> nme >> pr >> q) {  // Read from cart.txt
			if (_name == nme ) {
				outfile << sku << "\t" << nme << "\t" << price << "\t" << (quantity - q) << "\t" << catagory << endl;
				found = true;
			}
			
		}

		if (!found) {
			outfile << sku << "\t" << _name << "\t" << price << "\t" << quantity << "\t" << catagory << endl;
		}

		infile.clear();
		infile.seekg(0, ios::beg);
	}

	infile.close();
	ifile.close();
	outfile.close();

	remove("products.txt");
	rename("temp.txt", "products.txt");

	cout << "Product file updated successfully!" << endl;
}
void Product::removeProduct(string name) {
	ifstream infile("products.txt");
	ofstream outfile("temp.txt",ios::app);

	while (infile >> sku >> _name >> price >> quantity >> catagory) {
		if (_name != name) {
			outfile << sku << "\t" << _name << "\t" << price << "\t" << quantity << "\t" << catagory << endl;
		}
	}

	infile.close();
	outfile.close();

	remove("products.txt");
	rename("temp.txt", "products.txt");

	cout << "Product removed successfully." << endl;
}
void Product::viewProducts() 
{

	cout << "\t\tSKU #\t\t\tPRODUCT NAME\tPRODUCT PRICE\t\t PRODUCT QUANTITY\t\t PRODUCT CATAGORY\n";
	ifstream infile("products.txt");

	while (infile >> sku >> _name >> price >> quantity >> catagory)
	{
		cout <<"\t\t" << sku << "\t\t" << _name << " \t\t\t" << price << "\t\t\t " << quantity << "\t\t\t " << catagory << endl;
	}

	infile.close();
}
void Product::viewProdbycato(string cato)
{
	cout << "\t\tSKU #\t\t\tPRODUCT NAME\tPRODUCT PRICE\t\t PRODUCT QUANTITY\t\t PRODUCT CATAGORY\n";
	ifstream infile("products.txt");

	while (infile >> sku >> _name >> price >> quantity >> catagory)
	{
		if(catagory == cato)
		cout << "\t\t" << sku << "\t\t" << _name << " \t\t\t" << price << "\t\t\t " << quantity << "\t\t\t " << catagory << endl;
	}

	infile.close();
}
void Product::viewProdbyname(string nam) {
	cout << "\t\tSKU #\t\tPRODUCT NAME\t\tPRODUCT PRICE\t\t PRODUCT QUANTITY\t\t PRODUCT CATAGORY\n";
	ifstream infile("products.txt");

	while (infile >> sku>> _name >> price >> quantity >> catagory)
	{
		if (_name == nam)
			cout << "\t\t" << sku << "\t\t" << _name << " \t\t\t" << price << "\t\t\t " << quantity << "\t\t\t " << catagory << endl;
	}

	infile.close();
}
bool Product::search_prod(string it,int q) {
	bool chck = false;
	ifstream searchfile("products.txt", ios::in);
	while (!searchfile.eof())
	{
		searchfile >> sku >> _name >> price >> quantity >> catagory;
		if (_name == it && quantity>=q)
		{
			chck = true;
			break;
		}
		else {
			continue;
		}
	}
	cout << endl;
	searchfile.close();
	return chck;
}


Cart::Cart() {
	items = "\0";
}
void Cart::viewItems() {
	cout << "\t\tSKU #\t\tPRODUCT NAME\t\tPRODUCT PRICE\t\t PRODUCT QUANTITY\n";
	ifstream infile("cart.txt");
	string productName = "";
	float productPrice = 0;
	int productQuantity = 0;
	int sku;
	while (infile >> sku >> productName >> productPrice >> productQuantity)
	{
		cout << "\t\t" << sku << "\t" << productName << " \t\t\t" << productPrice << "\t\t\t " << productQuantity << endl;
	}

	infile.close();
}
void Cart::store(string file)
{
	ifstream infile("cart.txt");
	ofstream outfile(file, ios::app);
	string productName;
	float productPrice;
	int productQuantity;
	string prod_catagory;
	int sku;

	while (infile >> sku >> productName >> productPrice >> productQuantity >> prod_catagory)
	{
		outfile << "\t\t" << sku << "\t\t" << productName << "\t" << productPrice << "\t" << productQuantity << endl;
	}

	infile.close();
	outfile.close();
}
void Cart::addItem(string item,int q) {
	string name, cato;
	int pr, quan,sk;
	ifstream searchfile("products.txt", ios::in);
	ofstream outfile("cart.txt", ios::app);
	while (!searchfile.eof())
	{
		searchfile >> sk >> name >> pr >> quan >> cato;
		if (name == item)
		{
			outfile << sk << "\t" << name << "\t" << pr * q << "\t" << q << endl;
			outfile.close();
			break;
		}
		else {
			continue;
		}
	}
	cout << endl;
	searchfile.close();
}
void Cart::clear() {
	ofstream outfile("cart.txt");
	outfile << "";
	outfile.close();
}
void Cart::removeItem(string item) {
	ifstream infile("cart.txt");
	ofstream outfile("t.txt", ios::app);

	string productName;
	float productPrice;
	int productQuantity,sk;
	string prod_catagory;

	while (infile >> sk >> productName >> productPrice >> productQuantity >> prod_catagory) {
		if (productName != item) {
			outfile << sk << "\t" << productName << "\t" << productPrice << "\t" << productQuantity << endl;
		}
	}

	infile.close();
	outfile.close();
	remove("cart.txt");
	rename("t.txt", "cart.txt");

	cout << "Product removed successfully." << endl;
}
float Cart::calculateTotal() {
	ifstream infile("cart.txt");
	string productName;
	float productPrice;
	int productQuantity,sk;
	string prod_catagory;
	float total = 0;
	while (infile >> sk >> productName >> productPrice >> productQuantity)
	{
		total += productPrice;
	}

	infile.close();
	return total;
}
void Cart::checkout(string name, long ph, string addr, string eml, int zip, string country, string prov,string pay,string promo) 
{
	int g_total;
	chrono::system_clock::time_point now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	char timeString[26];
	ctime_s(timeString, sizeof(timeString), &currentTime);
	int total = calculateTotal();
	float discount = 0;
	if (promo == "heer")
	{
		discount = total * 0.3;
	}
	srand(time(0));
	long long randomNumber = 0;
	for (int i = 0; i < 10; i++) {
		int digit = rand() % 10;
		randomNumber = (randomNumber * 10) + digit;
	}
	system("CLS");
	cout << "\t\t==================== BILL =================================================================" << endl;
	cout << "\t\tOrder No.   " << randomNumber << "              Date/Time:   " << timeString << endl;
	cout << "\t\t===========================================================================================" << endl;
	cout << "\t\tCustomer Details:" << endl;
	cout << "\t\tName: " << name << endl;
	cout << "\t\tPhone: " << ph << endl;
	cout << "\t\tAddress: " << addr << endl;
	cout << "\t\tEmail: " << eml << endl;
	cout << "\t\tZip: " << zip << endl;
	cout << "\t\tCountry: " << country << endl;
	cout << "\t\tProvince: " << prov << endl;
	cout << endl;
	cout << "\t\t===========================================================================================" << endl;
	cout << "\t\t                      ITEMS" << endl;
	cout << "\t\t===========================================================================================" << endl;
	viewItems();
	cout << "\t\t--------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t\t============================================================================================" << endl;
	cout << "\t\t                     TOTALS" << endl;
	cout << "\t\t============================================================================================" << endl;
	cout << "\t\tSubtotal:       pkr. " << total << endl;
	cout << "\t\tTax:                 10%" << endl;
	cout << "\t\tShipping:       pkr. 200" << endl;
	cout << "\t\tDiscount:       pkr. " << discount << endl;
	g_total = ((total * 0.1) + total + 200) - discount;
	cout << "\t\tGrand Total:    pkr. " << g_total << endl;
	cout << endl;
	cout << "\t\t=============================================================================================" << endl;
	cout << "\t\tPayment Method: " << pay << endl;
	cout << "\t\t---------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t\tThank you for shopping with us! Your order will arrive in 24 hrs" << endl;
	cout << "\t\t==============================================================================================" << endl;


	ofstream outfile(name + "reciept.txt", ios::app);
	outfile << "\t\t=================================== BILL =================================================" << endl;
	outfile << "\t\tOrder No. " << randomNumber << "   Date/Time: " << timeString << endl;
	outfile << "\t\t==========================================================================================" << endl;
	outfile << "\t\tCustomer Details:" << endl;
	outfile << "\t\tName: " << name << endl;
	outfile << "\t\tPhone: " << ph << endl;
	outfile << "\t\tAddress: " << addr << endl;
	outfile << "\t\tEmail: " << eml << endl;
	outfile << "\t\tZip: " << zip << endl;
	outfile << "\t\tCountry: " << country << endl;
	outfile << "\t\tProvince: " << prov << endl;
	outfile << endl;
	outfile << "\t\t===========================================================================================" << endl;
	outfile << "\t\t                      ITEMS" << endl;
	outfile << "\t\t===========================================================================================" << endl;
	store(name + "reciept.txt");
	outfile << "\t\t-------------------------------------------------------------------------------------------" << endl;
	outfile << endl;
	outfile << "\t\t===========================================================================================" << endl;
	outfile << "\t\t                     TOTALS" << endl;
	outfile << "\t\t===========================================================================================" << endl;
	outfile << "\t\tSubtotal:       pkr. " << total << endl;
	outfile << "\t\tTax:                 10%" << endl;
	outfile << "\t\tShipping:       pkr. 200" << endl;
	outfile << "\t\tDiscount:       pkr. " << discount << endl;
	g_total = ((total * 0.1) + total + 200) - discount;
	outfile << "\t\tGrand Total:    pkr. " << g_total << endl;
	outfile << endl;
	outfile << "\t\t============================================================================================" << endl;
	outfile << "\t\tPayment Method: " << pay << endl;
	outfile << endl;
	outfile << "\t\t============================================================================================" << endl;
	outfile << endl;
	outfile << "\t\tThank you for shopping with us!" << endl;
	outfile << "\t\t============================================================================================" << endl;
	outfile.close();
}

invoice::invoice() {
	id = 0;
	time[0] = '\0';
	name = "";
	total_items = 0;
	total_price = 0;
	sub_total = 0;
}
invoice::invoice(int id, string name, int items, int t_price) {
	this->time[0] = '\o';
	this->id = id;
	this->name = name;
	this->total_items = items;
	this->total_price = t_price;
	sub_total = 0;

}
void invoice::setname(string name)
{
	this->name = name;
}
void invoice::setitems(int it) 
{
	this->total_items = it;
}
void invoice::settotal(int t) 
{
	this->total_price = t;
}
void invoice::setgrand(int g)
{
	this->sub_total = g;
}
int invoice::getid() 
{
	return id;
}
string invoice::gettime() 
{
	return time;
}
string invoice::getname()
{
	return name;
}
int invoice::getitems()
{
	return total_items;
}
int invoice::getprice()
{
	return total_price;
}
int invoice::getgrand() 
{
	return sub_total;
}
void invoice::setid(int i) 
{
	this->id = i;
}
void invoice::write_vendor()
{
	ofstream outfile("Vendor_Invoice.txt", ios::app);
	chrono::system_clock::time_point now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	ctime_s(time, sizeof(time), &currentTime);
	outfile << id << "\t" << name << "\t" << total_items << "\t" << total_price << "\t" << time;
	outfile.close();
}
void invoice::write_customer() 
{
	ofstream outfile("customer_Invoice.txt", ios::app);
	chrono::system_clock::time_point now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	ctime_s(time, sizeof(time), &currentTime);
	outfile << id << "\t" << name << "\t" << total_items << "\t" << total_price << "\t" << time;
	outfile.close();
}
void invoice::clear(string file) {
	ofstream outfile(file + ".txt");
	outfile << "";
	outfile.close();
}
void invoice::cal_grand(string file) {
	ifstream infile(file);
	int i,ti,tp;
	string n;
	int g = 0;
	int it = 0;
	string time;
	while (infile >> i >> n >> ti >> tp >> time >> time >> time >> time >> time) {
		if (n != "Grand-Total") {
			g += tp;
			it += ti;
		}
	}
	infile.close();
	ofstream outfile(file, ios::app);
	outfile << 0 << "\t" << "Grand-Total" << "\t" << it << "\t" << g << "\t" << "-" << "\t" << "-" << "\t" << "-" << "\t" << "-" << "\t" << "-\n";
	outfile.close();
}
void invoice::print_details(string file) {
	ifstream infile(file);
	int i, ti, tp;
	string n;
	int g = 0;
	int it = 0;
	string t1,t2,t3,t4,t5;
	cout << endl << endl;
	cout << "\tSKU #\t\t\tProduct Name\tT.Quantity\tT.Price\t\tTime\n";
	while (infile >> i >> n >> ti >> tp >> t1 >> t2 >> t3 >> t4 >> t5) {
		if (n != "Grand-Total") {
			cout << "\t" << i << "\t\t" << n << "\t\t" << ti << "\t\t" << tp << "\t\t" << t1 << " " << t2 << " " << t3 << " " << t4 << " " << t5 << endl << endl;
		}
		if (n == "Grand-Total") {
			cout << "\t----------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t\tGrand Total of ITEMS: " << ti;
			cout << "\t\tGrand Total of PRICE: " << tp << endl;
			cout << "\t----------------------------------------------------------------------------------------------------------" << endl << endl;
		}

	}
}


orderbook::orderbook() {
	name = "";
	catagory = "";
	quantity = 0;
	status = false;
	price = 0;
	sk = 0;
}
orderbook::orderbook(string name, string cato, int quan, bool stat) {
	this->name = name;
	this->catagory = cato;
	this->quantity = quan;
	this->status = stat;
	this->price = 0;
	srand(static_cast<unsigned>(time(nullptr)));
	this->sk = (10000000 + rand() % 90000000);
}
void orderbook::order_stock() {
	ofstream outfile("orderbook.txt", ios::app);
	outfile << sk << "\t" << name << "\t" << price << "\t" << quantity << "\t" << catagory << "\t" << status << endl;
	outfile.close();
}
void orderbook::confirm() {
	ifstream infile("orderbook.txt");
	ofstream outfile("temp.txt", ios::app);
	while (infile >> sk >> name >> price >> quantity >> catagory >> status)
	{
		if (status == false)
		{
			status = true;
		}
		cout << "\n\t\t\t\tName of product: " << name;
		cout << "\n\t\t\t\tCatagory of product: " << catagory;
		cout << "\n\t\t\t\tQuantity of product: " << quantity;
		cout << "\n\t\t\t\tStatus of Product: " << status;
		cout << "\n\t\t\t\tEnter Price of product: "; cin >> price;
		outfile << sk << "\t" << name << "\t" << price << "\t" << quantity << "\t" << catagory << "\t" << status << endl;
	}

	infile.close();
	outfile.close();
	remove("orderbook.txt");
	rename("temp.txt", "orderbook.txt");
}
