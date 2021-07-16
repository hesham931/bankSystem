/*
Hesham ashraf mousa(139593)
Section 7
Assignment code (linked list):
*/
#include<iostream>
using namespace std;
struct information {
	//this struct for customers information
	int id;
	string name;
};
class Node {
public:
	Node* link;
	Node* back;
	information* list;
	Node() {
		list = new information();
	}
};
class bankCustomers {
	Node* first;
	Node* last;
	int length;
	
public:
	bankCustomers();
	bankCustomers(const bankCustomers&);
	const bankCustomers& operator=(bankCustomers*&);//overloading function
	~bankCustomers();
	void insertLast(int, string);//insert last
	void insertFirst(int, string);
	void insertOrdered(int, int, string);
	void deleteFirst();
	void deleteLast();
	void deleteById(int);
	void deleteByName(string);
	void clearList();
	void print();
	void copyList(bankCustomers*&);
	void searchById(int);
	void searchByName(string);
	bool isEmpty();
	int getLength();
};
bankCustomers::bankCustomers() {
	first = 0;
	last = 0;
	length = 0;
}
bankCustomers::bankCustomers(const bankCustomers& old) {
	if (isEmpty()) {
		Node* c, * p, * node;
		node = new Node();

		c = old.first;
		node->list->id = c->list->id;
		node->list->name = c->list->name;
		first = node;
		first->back = 0;
		p = node;
		c = c->link;

		while (c != 0) {}
	}
	else {
		cout << "you can't copy this object beacuse it's empty list.\n";
	}
}
const bankCustomers& bankCustomers::operator=(bankCustomers*& old) {
	if (this != old) {
		clearList();
		copyList(old);
	}
	else
		cout << "You can't the same object.\n";

	return *this;
}
bankCustomers::~bankCustomers() {
	clearList();
}
void bankCustomers::insertLast(int id, string name) {
	Node* node;
	node = new Node();

	node->list->id = id;
	node->list->name = name;
	node->link = 0;
	node->back = 0;

	if (isEmpty()) {
		first = node;
		last = node;
	}
	else {
		last->link = node;
		node->back = last;
		last = node;
	}
	length++;
}
void bankCustomers::insertFirst(int id, string name) {
	Node* node;
	node = new Node();

	node->list->id = id;
	node->list->name = name;
	node->link = 0;
	node->back = 0;

	if (isEmpty()) {
		first = node;
		last = node;
	}
	else {
		node->link = first;
		first->back = node;
		first = node;
	}
	length++;
}
void bankCustomers::insertOrdered(int index, int id, string name) {
	//suppose that the index in list = index - 1.
	index--;
	Node *node;
	node = new Node();

	node->list->id = id;
	node->list->name = name;

	if (isEmpty()) {
		first = node;
		last = node;
	}
	else if (index == 0) { insertFirst(id, name); }
	else if (index == length) { insertLast(id, name); }
	else {
		Node* c;
		c = first;
		for (int i = 0; i < index - 1; i++)
			c = c->link;//now the pointer c point to node befor the node we will inserted it by 1.

		node->link = c->link;
		c->link = node;
		node->back = c;
		node->link->back = node;
	}
	length++;
}
void bankCustomers::deleteFirst() {
	if (!isEmpty()) {
		Node* c;
		c = first;

		if (first == last)
			first = last = 0;
		else {
			first = first->link;
			first->back = 0;
		}
		delete c;
		length--;
	}
	else
		cout << "You can't delete in this list beacuse it's empty.\n";
}
void bankCustomers::deleteLast() {
	if (!isEmpty()) {
		Node* c;
		c = last;

		if (first == last)
			first = last = 0;
		else {
			last = c;
			last->link = 0;
		}
		delete c;
		length--;
	}
	else
		cout << "You can't delete in this list beacuse it's empty.\n";
}
void bankCustomers::deleteById(int id) {
	if (!isEmpty()) {
		if (first->list->id == id)
			deleteFirst();
		else if (last->list->id == id)
			deleteLast();
		else {
			Node* c, * p;
			c = first;

			while (c->list->id != id && c != 0)
				c = c->link;
			if (c != 0) {
				p = c->back;
				p->link = c->link;
				c->link->back = p;
				delete c;
				length--;
			}
		}
	}
	else cout << "The list empty.\n";
}
void bankCustomers::deleteByName(string name) {
	if (!isEmpty()) {
		if (first->list->name == name)
			deleteFirst();
		else if (last->list->name == name)
			deleteLast();
		else {
			Node* c, * p;
			c = first;

			while (c->list->name != name && c != 0)
				c = c->link;
			if (c != 0) {
				p = c->back;
				p->link = c->link;
				c->link->back = p;
				delete c;
				length--;
			}
		}
	}
	else cout << "The list empty.\n";
}
void bankCustomers::clearList() {
	if (isEmpty()) {
		Node* c;

		while (first != NULL) {
			c = first;
			first = first->link;
			first->back = 0;
			delete c;
		}
		length = 0;
		first = 0;
		last = 0;
	}
	else
		cout << "This list can't be deleted beacuse it's empty.\n";
}
void bankCustomers::print(){
	if (!isEmpty()) {
		Node* c;
		int i = 0;
		c = first;

		while (c != 0) {
			cout << "The customer number \"" << i + 1 << "\" name : " << c->list->name << ".\nThe customer id = " << c->list->id << ".\n";
			i++;
			c = c->link;
		}
	}
	else
		cout << "You can't print the information beacuse the list empty.\n";
}
bool bankCustomers::isEmpty() { return (first == NULL); }
int bankCustomers::getLength() { return length; }
void bankCustomers::searchById(int id) {
	if (!isEmpty()) {
		Node* c;
		c = first;

		while (c != 0) {
			if (c->list->id == id) {
				cout << "The id : \"" << c->list->id << "\" exist for the : \"" << c->list->name << "\" customers.\n";
				break;
			}
			cout << "The id \"" << id << "\" not exist!!.\n";
		}
	}
	else
		cout << "You can't search for any id beacuse the list empty.\n";
}
void bankCustomers::searchByName(string name) {
	if (!isEmpty()) {
		Node* c;
		c = first;

		while (c != 0) {
			if (c->list->name == name) {
				cout << "The name : \"" << c->list->name << "\" exist for the : \"" << c->list->id << "\" customers.\n";
				break;
			}
			cout << "The id \"" << name << "\" not exist!!.\n";
		}
	}
	else
		cout << "You can't search for any id beacuse the list empty.\n";
}
void bankCustomers::copyList(bankCustomers*& old){
	if (this != old) {
		if(isEmpty()){
			Node* c, * p, * node;
			node = new Node();

			c = old->first;
			node->list->id = c->list->id;
			node->list->name = c->list->name;
			first = node;
			first->back = 0;
			p = node;
			c = c->link;

			while(c != 0){}
		}
		else {
			cout << "you can't copy this object beacuse it's empty list.\n";
		}
	}
	else {
		cout << "You can't copy this object beacuse it's the same object.\n";
	}
}
int main() {
	int id;
	string name;
	bankCustomers *obj1;
	obj1 = new bankCustomers;

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

		obj1->insertLast(id, name);
	}

	cout << "The test of (insertLast) function :\n";
	obj1->print();
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
	
	obj1->insertOrdered(4, 1234567895, "hesham");
	cout << "The test of (insertAt) function :\n";
	obj1->print();

	/*
	The test of (insertOrdered) function :
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
	
	obj1->deleteById(1234567895);
	obj1->deleteByName("hasan");
	cout << "The of (delete) by name and id functions :\n";
	obj1->print();
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