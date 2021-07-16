/*
Hesham ashraf mousa(139593)
Section 7
Assignment code (array based list):
*/
#include<iostream>
using namespace std;
struct information {
	//this struct for customers information
	int id;
	string name;
};
class bankCustomers {
	//list contains the customer information
	information *list;
	//number of customers
	int length;
	//the max number of customer in the list
	int max_size;
public:
	bankCustomers(int = 100);//max_size = 100
	bankCustomers(const bankCustomers&);
	const bankCustomers& operator=(const bankCustomers&);//overloading function
	~bankCustomers();
	void insert(int, string);//insert last
	void inserAt(int, int, string);
	void deleteById(int);
	void deleteByName(string);
	void clearList();
	void print() const;
	bool isEmpty();
	bool isFull();
	int getLength();
	int getMaxSize();
	int searchById(int);
	int searchByName(string);
};
bankCustomers::bankCustomers(int max_size) {
	if (max_size < 0 || max_size > 100)
		max_size = 100;
	else
		bankCustomers::max_size = max_size;

	length = 0;

	list = new information[bankCustomers::max_size];
}
bankCustomers::bankCustomers(const bankCustomers& old) {
	length = bankCustomers::length;
	max_size = old.max_size;

	list = new information[max_size];

	for (int i = 0; i < length; i++) {
		list[i].id = old.list[i].id;
		list[i].name = old.list[i].name;
	}
}
const bankCustomers& bankCustomers::operator=(const bankCustomers&old){
	if (this != &old) {
		delete []list;
		length = old.length;
		max_size = old.max_size;

		list = new information[max_size];
		for (int i = 0; i < length; i++){
			list[i].id = old.list[i].id;
			list[i].name = old.list[i].name;
		}
	}
	return *this;
}
bankCustomers::~bankCustomers() {
	length = 0;
	max_size = 0;
	delete[]list;
}
void bankCustomers::insert(int id , string name){
	if (!isFull()) {
		//note that if the id not exist,the function will return -1
		if (searchById(id) == -1) {
			list[length].id = id;
			list[length].name = name;

			length++;
		}
		else
			cout << "This id number its already exist.\n";
	}
	else {
		cout << "Sorry<but the list full\n";
	}
}
void bankCustomers::inserAt(int index, int id, string name) {
	//suppos that the index in the array = index -1.
	if (!isFull()) {
		if (index-1 >= 0 && index-1 < 100) {
			if (searchById(id) == -1) {
				for (int i = length; i > index - 1; i--)
					list[i] = list[i - 1];

				list[index-1].id = id;
				list[index-1].name = name;

				length++;
			}
			else
				cout << "This id number already exist.\n";
		}
		else
			cout << "This index illegal.\n";
	}
	else
		cout << "The list full.\n";
}
void bankCustomers::deleteById(int id) {
	if (!isEmpty()) {
		int index = searchById(id);//the index that have the id in the array
		if (index == -1) cout << "This id not exist.\n";
		else {
			//shiftting the array
			for (int i = index; i < length; i++) {
				list[i].id = list[i + 1].id;
				list[i].name = list[i + 1].name;
			}

			length--;
		}
	}
	else cout << "The list empty.\n";
}
void bankCustomers::deleteByName(string name){
	if (!isEmpty()) {
		int index = searchByName(name);
		if (index == -1) cout << "That name not exist.\n";
		else {
			//delete[index]list;
			for (int i = index; i < length; i++) {
				list[i].id = list[i + 1].id;
				list[i].name = list[i + 1].name;
			}
			length--;
		}
	}
	else cout << "The list empty.\n";
}
void bankCustomers::clearList() {
	delete[]list;
	length = 0;
	max_size = 0;
}
void bankCustomers::print() const {
	for (int i = 0; i < length; i++)
		cout << "The customer number \"" << i + 1 << "\" name : " << list[i].name << ".\nThe customer id = " << list[i].id << ".\n";
}
bool bankCustomers::isEmpty() { return (length == 0); }
bool bankCustomers::isFull() { return (length == max_size); }
int bankCustomers::getLength() { return length; }
int bankCustomers::getMaxSize() { return (length == max_size); }
int bankCustomers::searchById(int id) {
	if (!isEmpty()) {
		for (int i = 0; i < length; i++) {
			if (list[i].id == id)
				return i;
		}
	}
	return -1;
}
int bankCustomers::searchByName(string name) {
	if (!isEmpty()) {
		for (int i = 0; i < length; i++) {
			if (list[i].name == name)
				return i;
		}
	}
	return -1;
}
int main() {
	int id;
	string name;
	bankCustomers obj1;

	for (int i = 0; i < 5; i++) {
		/*
		suppose that the input:
		1234567890 mosa
		1234567891 ahmad
		1234567892 ebrahem
		1234567893 abood
		1234567894 hasan
		*/
		cin >> id >> name;

		obj1.insert(id, name);
	}

	cout << "The test of (insert) function :\n";
	obj1.print();
	/*
	The test of (insert) function :
	The customer number "1" name : mosa.
	The customer id = 1234567890.
	The customer number "2" name : ahmad.
	The customer id = 1234567891.
	The customer number "3" name : ebrahem.
	The customer id = 1234567892.
	The customer number "4" name : abood.
	The customer id = 1234567893.
	The customer number "5" name : hasan.
	The customer id = 1234567894.
	*/

	obj1.inserAt(4, 1234567895, "hesham");
	cout << "The test of (insertAt) function :\n";
	obj1.print();

	/*
	The test of (insertAt) function :
	The customer number "1" name : mosa.
	The customer id = 1234567890.
	The customer number "2" name : ahmad.
	The customer id = 1234567891.
	The customer number "3" name : ebrahem.
	The customer id = 1234567892.
	The customer number "4" name : hesham.
	The customer id = 1234567895.
	The customer number "5" name : abood.
	The customer id = 1234567893.
	The customer number "6" name : hasan.
	The customer id = 1234567894.
	*/

	obj1.deleteById(1234567895);
	obj1.deleteByName("hasan");
	cout << "The of (delete) by name and id functions :\n";
	obj1.print();
	/*
	The of (delete) by name and id functions :
	The customer number "1" name : mosa.
	The customer id = 1234567890.
	The customer number "2" name : ahmad.
	The customer id = 1234567891.
	The customer number "3" name : ebrahem.
	The customer id = 1234567892.
	The customer number "4" name : abood.
	The customer id = 1234567893.
	*/
	return 0;
}
