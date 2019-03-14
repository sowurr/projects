
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <direct.h>
using namespace std;
class book
{
public:
	friend int add_book(book);
	book()
	{
		book_name = 'a';
		ISBN = "0";
		book_writer = "a";
		book_field = "a";
	}
	int set(string book, string shabak, string writer, string field)
	{
		book_name = book;
		ISBN = shabak;
		book_writer = writer;
		book_field = field;
		return 0;
	}
	string get(int x)
	{
		if (x == 1) return book_name;
		else if (x == 2)return ISBN;
		else if (x == 3)return book_writer;
		else if (x == 4)return book_field;
	}

private:
	string book_name;
	string ISBN;
	string book_writer;
	string book_field;
	bool loan;

};
class library :public book
{
public:
	int set()
	{

	}
	int get()
	{

	}
private:

};
int save_in_database(book *book, int x)
{
	if(x==1)
	{
		ofstream books("books.txt", ios::app);
	books << book->get(1) << " " << book->get(2) << " " << book->get(3) << " " << book->get(4) <<" "<<"Not-Loan"<<endl;
	return 0;
	}	
}
int check_numbers(int x)
{
	int n = 0;
	while (x != 0)
	{
		x = x / 10;
		n++;
	}
	return n;
}
int add_library(library *lib)
{
	return 0;
}
int add_book(book *bookie)
{
	string shabak;
	string name, writer, field;
	cout << "Please Enter Book Name : ";
	cin >> name;
	cout << "Please Enter Book ISBN : ";
	cin >> shabak;
	cout << "Please Enter Book Writer Name : ";
	cin >> writer;
	cout << "Please Enter Book Field : ";
	cin >> field;
	bookie->set(name, shabak, writer, field);
	save_in_database(bookie,1);
	return 0;
}
int loan_book()
{
	// function that search and loan the book
	return 0;
}
int show_cat()
{
	return 0;
}
int delete_library()
{
	return 0;
}
int show_everything()
{
	return 0;
}
int delete_book()
{
	return 0;
}
int serach_in_library()
{
	return 0;
}
int main()
{
	book books;
	int n;
	cout << "Hello plz enter the right number : ";
	while (cin >> n)
	{
		if (n == 1)
		{
			add_library(&books);
			continue;
		}
		else if (n == 2)
		{
			mkdir("D:\Games\Codes");
			add_book(&books);
			continue;
		}
		else if (n == 3)
		{
			continue;
		}
		else if (n == 4)
		{
			loan_book();
			continue;
		}
		else if (n == 5)
		{
			show_cat();
			continue;
		}
		else if (n == 6)
		{
			delete_library();
			continue;
		}
		else if (n == 7)
		{
			show_everything();
			continue;
		}
		else if (n == 8)
		{
			delete_book();
			continue;
		}
		else if (n == 9)
		{
			serach_in_library();
			continue;
		}
		else if (n == 10)
		{
			cout << "GOOD BYE :-)";
			return 0;
		}
		else
		{
			cout << "PLEASE ENTER TRUE NUMBER !!!!!!!!!!!!" << endl;
			continue;
		}
	}
	return 0;
}
