#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class total_books {
	int Data;
	string ISBN;
	string book_name;
	string writer;
	string subj;


	total_books *next;
	friend class tbooks_linkedlist;
};


//linked list total books
class tbooks_linkedlist {
public:
	tbooks_linkedlist() { first = NULL; }
	
	void add_tbook(string isbn , string bn , string wn , string subj );//add node to list
	
	void deletebook(string isbn );//delet node by value of data
	
	//void showlist();//print all node in list

	//search the linked list by value of data
	int search_tbooks(string isbn , string bn);

private:
	total_books *first;//stor first node of link
	total_books *last;//stor last node of link
};


//add node to list and fill node
void tbooks_linkedlist::add_tbook(string isbn, string bn, string wn, string subj)
{
	int data1;
	if (first == NULL)
	{
		//create first node
		total_books *temp = new total_books;
		temp->next = NULL;
		first = temp;
		first->ISBN = isbn;
		first->book_name = bn;
		first->writer = wn;
		first->subj = subj;
		last = first;
	}
	else
	{
		//create other node
		total_books *temp = new total_books;
		temp->next = NULL;
		last->next = temp;
		last = temp;
		last->ISBN = isbn;
		last->book_name = bn;
		last->writer = wn;
		last->subj = subj;
	}
}


//delete book from total books
void tbooks_linkedlist::deletebook(string isbn)
{
	total_books* temp;
	total_books* temp1;
	temp1 = temp = first;
	int not_exit_in_list = 0;
	if (first->ISBN == isbn)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
	else
	{
		while (temp != last)
		{
			temp = temp1->next;
			if (temp->ISBN == isbn)
			{
				if (temp == last)
				{
					temp1->next = NULL;
					delete temp;
					last = temp1;
					not_exit_in_list = 1;
					break;
				}
				else
				{
					temp1->next = temp->next;
					delete temp;
					not_exit_in_list = 1;
					break;
				}
			}
			temp1 = temp1->next;
		}
		if (not_exit_in_list == 0)
		{
			cout << "There is no book with ISBN= " << isbn << " in linked list." << endl;
		}
	}
}

//search total books
int tbooks_linkedlist::search_tbooks(string isbn, string bn) {
	total_books *temp;
	temp = first;
	if (first == NULL)
	{
		cout << "list of total books is empty" << endl;
	}
	while (temp != NULL)
	{
		if (temp->ISBN == isbn && temp->book_name == bn) {
			return 1;
		}
		temp = temp->next;
	}

}

/*book class
class book {
	int Data;
	string ISBN;
	string book_name;
	string writer;
	enum subject{};
	bool loan;

	book *next;
	friend class book_linkedlist;
};
*/


//linked list class
class book_linkedlist {
	int Data;
	string ISBN;
	string book_name;
	string writer;
	string subj ;
	bool loan;
	friend class library_linkedlist;
public:
	void getname(string name) {
		book_name = name;
	}
	void getwriter(string w) {
		writer = w;
	}
	void getisbn(string isbn) {
		ISBN = isbn;
	}
	string showname() {
		return book_name;
	}
	string showwriter() {
		return writer;
	}
	string showisbn() {
		return ISBN;
	}
	void getloan(bool t) {
		loan = t;
	}
	string showloan() {
		string x;
		if (loan == 1) {
			x = "loaned";
			return x;
		}
		else {
			x = "not loaned";
			return x;
		}
	}
	void getsubj(string subject) {
		subj = subject;
	}
	string showsubj() {
		return subj;
	}


	/*book_linkedlist *next;
public:
	book_linkedlist() { bfirst = NULL; }

	void getisbn(string isbn) {
		ISBN = isbn ;
	}

	//delet node by value of data
	void delete_book(int);

	void showlist();
	void search_data(int);


private:
	book_linkedlist *bfirst;
	book_linkedlist *blast;
	*/
};




/*delete book
void book_linkedlist::delete_book(int data1)
{
	book_linkedlist* temp;
	book_linkedlist* temp1;
	temp1 = temp = bfirst;
	int not_exist_in_list = 0;
	if (bfirst->Data == data1)
	{
		temp = bfirst;
		bfirst = bfirst->next;
		delete temp;
	}
	else
	{
		while (temp != blast)
		{
			temp = temp1->next;
			if (temp->Data == data1)
			{
				if (temp == blast)
				{
					temp1->next = NULL;
					delete temp;
					blast = temp1;
					not_exist_in_list = 1;
					break;
				}
				else
				{
					temp1->next = temp->next;
					delete temp;
					not_exist_in_list = 1;
					break;
				}
			}
			temp1 = temp1->next;
		}
		if (not_exist_in_list == 0)
		{
			cout << "There is not node with Data= " << data1 << " in linked list." << endl;
		}
	}
}
*/

/*library class
class library {
	int Data;
	string library_name;
	string p_code;

	library *next;
	friend class library_linkedlist;
	book *bfirst;
	book *blast;
	
};
*/

//linked list class
class library_linkedlist {
	string library_name;
	string p_code;

	library_linkedlist *next;
	//book_linkedlist *bfirst;
	//book_linkedlist *blast;

public:

	void getname(string name) {
		library_name = name;

	}

	string showname() {
		return library_name;
	}


	int bcounter = 0;
	string show() {
		return p_code;
	}

	library_linkedlist() {
		lfirst = NULL;
	}

	//add library to list
	void add_library(string ln , string pc);

	//delete library 
	void delete_library(string pc);


	int loan_book(string pc, string isbn);

	int showdetail1(string pc);

	/*
	void showlist();
	void search_data(int);
	*/

	//add node to list
	int add_book_to_library(string pc , string ISBN , string bname);
	vector <class book_linkedlist> vbook;


private:
	library_linkedlist *lfirst;
	library_linkedlist *llast;
};


//add library to list
void library_linkedlist :: add_library(string ln, string pc)
{
	if (lfirst == NULL)
	{
		//create first node
		
		library_linkedlist *temp = new library_linkedlist;
		temp->next = NULL;
		lfirst = temp;
		lfirst->library_name = ln ;
		lfirst->p_code = pc;
		llast = lfirst;
	}
	else
	{
		//create other node
		
		library_linkedlist *temp = new library_linkedlist;
		temp->next = NULL;
		llast->next = temp;
		llast = temp;
		lfirst->library_name = ln;
		lfirst->p_code = pc;
	}
}

//add book
int library_linkedlist::add_book_to_library(string pc, string ISBN, string bname)
{
	
	library_linkedlist *ptr = new library_linkedlist;
	ptr = lfirst;
	int exis = 0;
	while (ptr != NULL) {
		if (ptr->show == pc) {
			exis = 1;
			return 1;
		}
		ptr = ptr->next;
	}
	if (exis == 0) {
		cout << "there is no such library!" << endl;
		return 0;
	}

		/*book_linkedlist *bptr = new book_linkedlist;
		bptr = bfirst;

		if (bfirst == NULL)
		{

		book_linkedlist *temp = new book_linkedlist;
		temp->next = NULL;
		bfirst = temp;

		bfirst.getisbn(ISBN);

		blast = bfirst;
		}
		else
		{
		//create other node
		cout << "Enter Data:";
		cin >> data1;
		book_linkedlist *temp = new book_linkedlist;
		temp->next = NULL;
		blast->next = temp;
		blast = temp;
		blast->Data = data1;
		}*/



}

//loan book
int library_linkedlist::loan_book(string pc, string isbn) {
	library_linkedlist *ptr = new library_linkedlist;
	ptr = lfirst;
	int exis = 0;
	while (ptr != NULL) {
		if (ptr->show == pc) {
			exis = 1;
			return 1;
		}
		ptr = ptr->next;
	}
	if (exis == 0) {
		cout << "there is no such library!" << endl;
		return 0;
	}

}

//show detail1
int library_linkedlist::showdetail1(string pc) {
	library_linkedlist *ptr = new library_linkedlist;
	ptr = lfirst;
	int exis = 0;
	while (ptr != NULL) {
		if (ptr->show == pc) {
			exis = 1;
			return 1;
		}
		ptr = ptr->next;
	}
	if (exis == 0) {
		cout << "there is no such library!" << endl;
		return 0;
	}
}


//delete library
void library_linkedlist::delete_library(string pc)
{
	library_linkedlist* temp;
	library_linkedlist* temp1;
	temp1 = temp = lfirst;
	int not_exist_in_list = 0;
	if (lfirst->p_code == pc)
	{
		temp = lfirst;
		lfirst = lfirst->next;
		delete temp;
	}
	else
	{
		while (temp != llast)
		{
			temp = temp1->next;
			if (temp->p_code == pc)
			{
				if (temp == llast)
				{
					temp1->next = NULL;
					delete temp;
					llast = temp1;
					not_exist_in_list = 1;
					break;
				}
				else
				{
					temp1->next = temp->next;
					delete temp;
					not_exist_in_list = 1;
					break;
				}
			}
			temp1 = temp1->next;
		}
		if (not_exist_in_list == 0)
		{
			cout << "There is no library with postal code = " << pc << " in linked list." << endl;
		}
	}
}





int main() {

	while (1) {

		int n;
		cout << "Enter a number from 1 to 10 :" << endl;
		cin >> n;
		library_linkedlist l1;
		book_linkedlist b1;
		tbooks_linkedlist tb1;

		//Add a Library :
		if (n == 1) {
			//cout<<
			string name;
			string pcode;
			cout << "please enter the library name: ";
			cin >> name;
			cout << endl << "please enter the postal code: ";
			cin >> pcode;
			l1.add_library(name, pcode);

		}

		//add book to library
		if (n == 2) {
			string name;
			string isbn;
			string pc;
			int check = 0;
			l1.bcounter++;
			cout << "please enter the book name you wanna add: ";
			cin >> name;
			cout << endl << "please enter the ISBN of the book you wanna add: ";
			cin >> isbn;
			cout << endl << "please enter the library postal code: ";
			cin >> pc;
			int x;
			while (check == 0) {
				if (tb1.search_tbooks(isbn, name) == 1) {
					x = l1.add_book_to_library(pc, isbn, name);
					if (x == 1) {
						b1.getisbn(isbn);
						b1.getname(name);
						l1.vbook.push_back(b1);
						check++;
					}
				}
				else {
					cout << "we dont have that book yet!";
					cout << endl << "please enter the ISBN of the book you wanna add: ";
					cin >> isbn;
				}
			}
		}


		//add book to total books
		if (n == 3) {
			string isbn;
			string bn;
			string wn;
			string subj;
			cout << "please type the ISBN: ";
			cin >> isbn;
			cout << endl << "please type the book name: ";
			cin >> bn;
			cout << endl << "please type the writer name: ";
			cin >> wn;
			cout << endl << "please type the subject of the book: ";
			cin >> subj;

			tb1.add_tbook(isbn, bn, wn, subj);
		}


		//loan a book:
		if (n == 4) {
			string pc;
			string isbn;
			cout << "please enter the postal code of the library which the book is in : ";
			cin >> pc;
			cout << endl << "please enter the ISBN of the book you wanna loan: ";
			cin >> isbn;
			if (l1.loan_book == 1) {
				for (int i = 0; i < l1.bcounter; i++) {
					if (l1.vbook[i].showisbn == isbn) {
						l1.vbook[i].getloan(1);
					}
				}
			}
		}

		if (n == 5) {
			string pc;
			string subj;
			cout << "please enter the postal code of the library: ";
			cin >> pc;
			cout << endl << "please enter the subject: ";
			cin >> subj;
			if (l1.loan_book == 1) {
				for (int i = 0; i < l1.bcounter; i++) {
					if (l1.vbook[i].showsubj == subj) {
						cout << "ISBN is : " << l1.vbook[i].showisbn << endl << "name of the book is : " << l1.vbook[i].showname << endl;
						cout << "writer name is : " << l1.vbook[i].showwriter << endl;
					}
				}
			}
		}

		if (n == 6) {
			string pc;
			cout << "enter the postal code of the library you wanna delete: ";
			cin >> pc;
			l1.delete_library(pc);

		}

		if (n == 7) {

			string pc;
			if (l1.showdetail1(pc) == 1) {
				cout << "library name is : " << l1.showname << endl;
				for (int i = 0; i < l1.bcounter; i++) {
					cout << "book name: " << l1.vbook[i].showname << "  " << "book ISBN is : " << l1.vbook[i].showisbn << "  " << "book subject is : " << l1.vbook[i].showsubj << "  " << "book writer is: " << l1.vbook[i].showwriter << endl;
				}
			}

		}

		if (n == 8) {
			string isbn;
			cout << "please enter the ISBN of the book you wanna delete: ";
			cin >> isbn;
			tb1.deletebook(isbn);
		}

		if (n == 9) {
			string pc;
			string isbn;
			int check = 0;
			cout << "please enter the postal code of the library: ";
			cin >> pc;
			cout << endl << "please enter ISBn of the book: ";
			cin >> isbn;
			if (l1.showdetail1(pc) == 1) {
				for (int i = 0; i < l1.bcounter; i++) {
					if (l1.vbook[i].showisbn == isbn) {
						check++;
						cout << "subject is : " << l1.vbook[i].showsubj << endl << "name of the book is : " << l1.vbook[i].showname << endl;
						cout << "writer name is : " << l1.vbook[i].showwriter << endl << "loan: " << l1.vbook[i].showloan << endl;
					}
				}
			}
			if (check == 0) {
				cout << "we dont have that book!" << endl;
			}

		}


		if (n == 10) {
			return 0;
		}
	}


}
