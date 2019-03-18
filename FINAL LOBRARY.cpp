#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <direct.h>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;
int i1=0,i2=0,i3=0;
string books_name[1000][4];
string libraries_name[1000][2];
string loans_book[1000][5];
void piano()
{
	 Beep(220,300);
  Beep(294,300);
  Beep(294,300);
  Beep(370,300);
  Beep(494,300);
  Beep(370,300);
  Beep(440,800);
  /* */
  Beep(440,300);
  Beep(494,300);
  Beep(440,300);
  Beep(370,300);
  Beep(392,300);
  Beep(370,300);
  Beep(330,800);
  /* */
  Beep(247,300);
  Beep(330,300);
  Beep(330,300);
  Beep(370,300);
  Beep(555,300);
  Beep(555,300);
  Beep(494,300);
  Beep(440,300);
  Beep(392,800);
  Beep(392,300);
  Beep(370,300);
  Beep(247,800);
  Beep(278,300);
  Beep(294,300);
  Beep(330,2600);
  /* */
  Beep(220,300);
  Beep(294,300);
  Beep(294,300);
  Beep(370,300);
  Beep(494,300);
  Beep(370,300);
  Beep(440,800);
  /* */
  Beep(440,300);
  Beep(494,300);
  Beep(440,300);
  Beep(370,300);
  Beep(392,300);
  Beep(370,300);
  Beep(330,800);
  /* */
  Beep(247,300);
  Beep(330,300);
  Beep(330,300);
  Beep(370,300);
  Beep(555,300);
  Beep(555,300);
  Beep(494,300);
  Beep(440,300);
  Beep(392,800);
  Beep(392,300);
  Beep(370,300);
  Beep(278,600);
  Beep(330,600);
  Beep(294,2600);
  /*Reff : */
  Beep(494,300);
  Beep(494,300);
  Beep(494,300);
  Beep(440,300);
  Beep(392,200);
  Beep(440,200);
  Beep(494,200);
  Beep(440,800);
  Beep(330,300);
  Beep(370,300);
  Beep(416,300);
  Beep(330,300);
  Beep(440,2000);
  /* */
  Beep(494,800);
  Beep(440,800);
  Beep(392,1600);
  /* */
  Beep(555,300);
  Beep(555,300);
  Beep(555,300);
  Beep(494,300);
  Beep(440,300);
  Beep(494,300);
  Beep(440,300);
  Beep(392,1400);
  /* */
  Beep(440,300);
  Beep(494,300);
  Beep(370,1100);
  Beep(330,300);
  Beep(294,1800);
  /* */
  Beep(494,800);
  Beep(440,800);
  Beep(392,1600);
  /* */
  Beep(555,300);
  Beep(555,300);
  Beep(555,300);
  Beep(494,300);
  Beep(440,300);
  Beep(494,300);
  Beep(440,300);
  Beep(392,1400);
  /* */
  Beep(440,300);
  Beep(494,300);
  Beep(370,1100);
  Beep(330,300);
  Beep(294,1800);
}
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
class library
{
public:
	friend int add_library(library);
	library(string x="a",string y="z")
	{
		name=x;
		zip_code=y;
	}
	int set(string names,string zip_codes)
	{
		name=names;
		zip_code=zip_codes;
	}
	string get( int x)
	{
		if(x==1)return name;
		else if(x==2)return zip_code;
	}
private:
	string name,zip_code;
};
int save_in_book_database(book *book)
{
	int p=1;
	ofstream books("books.txt", ios::app);
	//string books_name[1000][4];
	for(int j=0;j<4;j++)
	{
		books_name[i1][j]=book->get(p);
		p++;
	}
	for(int j=0;j<4;j++)
	{
		books<<books_name[i1][j]<<" - ";
		if(j==3)books<<endl;
	}
	p=0;
	i1++;
	return 0;	
}
int save_in_library_database(library *lib)
{
	int p=1;
	ofstream libe("libraries.txt", ios::app);
	//string libraries_name[1000][2];
	for(int j=0;j<2;j++)
	{
		libraries_name[i2][j]=lib->get(p);
		p++;
	}
	for(int j=0;j<2;j++)
	{
		libe<<libraries_name[i2][j]<<" - ";
		if(j==1)libe<<endl;
	}
	p=0;
	i2++;
	return 0;	
}
int save_in_library()
{
	return 0;
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
int search_in_books(string book)
{
	 
    //cout<<"book: "<<i1;
    
    for(int q=0;q<i1;q++)
    {
    //	cout<<"LEVEL 1"<<endl;
    //	system("pause");
    //	cout<<libraries_name[q][0];
    	if(books_name[q][0]==book)return 1;
	}
 
}
int search_in_libraries(string lib)
{
    //cout<<"library : "<<i2;
    
    for(int q=0;q<i2;q++)
    {
    	//cout<<"LEVEL 2"<<endl;
    	//system("pause");
    	if(libraries_name[q][0]==lib)return 1;
	}
}
int add_library(library *lib)
{
	string name,zip_code;
	system("CLS");
	cout<<"Please Enter Library Name : ";
	cin>>name;
	cout<<"Please Enter ZIPcode : ";
	cin>>zip_code;
	lib->set(name,zip_code);
	save_in_library_database(lib);
	return 0;
}
int add_book_to_library()
{
	string zip_code,isbn;
	int a,b;
	string book_name;
	string lib_name;
	cout<<"Please Enter Library Name : ";
	cin>>lib_name;
	cout<<"Please Enter Library ZIP Code : ";
	cin>>zip_code;
	cout<<"PLease Enter Book Name : ";
	cin>>book_name;
	cout<<"Please Enter Book ISBN : ";
	cin>>isbn;
	a=search_in_books(book_name);
	b=search_in_libraries(lib_name);
	if(a==1 && b==1)
	{
		ofstream save_in_libraries("save in libraries.txt", ios::app);
		for(int i=0;i<5;i++)
		{
			if(i==0)loans_book[i3][i]=lib_name;
			else if(i==1)loans_book[i3][i]=book_name;
			else if(i==2)loans_book[i3][i]=zip_code;
			else if(i==3)loans_book[i3][i]=isbn;
			else loans_book[i3][i]="NOT-LOAN";
		}
		i3++;
		save_in_libraries<<lib_name<<" : "<<book_name <<" : "<<zip_code<<" NOT-LOAN"<<endl;
	}
	else cout<<"no body can runaway from ali morad"<<endl;
    return 0;
}
int add_book(book *bookie)
{
	string shabak;
	string name, writer, field;
	system("CLS");
	cout << "Please Enter Book Name : ";
	cin >> name;
	cout << "Please Enter Book ISBN : ";
	cin >> shabak;
	cout << "Please Enter Book Writer Name : ";
	cin >> writer;
	cout << "Please Enter Book Field : ";
	cin >> field;
	bookie->set(name, shabak, writer, field);
	cout<<"HELLLLOOOOOOOO"<<endl;
	save_in_book_database(bookie);
	cout<<"HELLO"<<endl;
	return 0;
}
int loan_book()
{
	string bookname,libraryname;
	cout<<"book name : ";
	cin>>bookname;
	cout<<"library name : ";
	cin>>libraryname;
	ofstream empty("save in libraries.txt", ios::trunc);
	empty<<"";
	empty.close();
	for(int i=0;i<i3;i++)
	{
		
			if(loans_book[i][0]==libraryname && loans_book[i][1]==bookname)
			{
				 if(loans_book[i][2]=="LOANED")loans_book[i][2]="NOT-LOANED";
				 else loans_book[i][2]="LOANED";
			}
			ofstream bookss("save in libraries.txt", ios::app);
			bookss<<loans_book[i][0]<<" : "<<loans_book[i][1]<<" : "<<loans_book[i][2]<<endl;
			
	}
	// function that search and loan the book
	return 0;
}
int show_cat()
{
	string zipcode,field;
	cout<<"Please Enter Library ZIP Code : ";
	cin>>zipcode;
	cout<<"Please Enter Book Field : ";
	cin>>field;
	int a=search_in_libraries(zipcode);
	if(a==1)
	{
		for(int i=0;i<i1;i++)
		{
			if(books_name[i][3]==field)
			{
				cout<<books_name[i][0]<<"-"<<books_name[i][1]<<"-"<<books_name[i][2]<<"-"<<books_name[i][3]<<endl;
			}
		}
	}

	return 0;
}
int delete_library()
{
	string zipcode;
	cout<<"Please Enter The ZIP Code : ";
	cin>>zipcode;
	for(int i=0;i<i2;i++)
	{
		if(libraries_name[i][1]==zipcode)
		{
			libraries_name[i][0]="";
			libraries_name[i][1]="";
		}
	}
	ofstream libe("libraries.txt", ios::trunc);
	libe<<"";
	libe.close();
	for(int i=0;i<i2;i++)
	{
		ofstream libes("libraries.txt", ios::app);
		libes<<libraries_name[i][0]<<" - "<<libraries_name[i][1]<<endl;
	}
	return 0;
}
int show_everything()
{
	system("CLS");
	string zipcode;
	cout<<"Please Enter ZIP Code : ";
	cin>>zipcode;
	for(int i=0;i<i1;i++)
	{
		if(loans_book[i1][2]==zipcode)
		{
			cout<<loans_book[i][0]<<" - "<<loans_book[i][1]<<" - "<<loans_book[i][2]<<" - "<<loans_book[i][3]<<endl;
		}
	}
	
	return 0;
}
int delete_book()
{
	string zipcode;
	cout<<"Please Enter The ZIP Code : ";
	cin>>zipcode;
	for(int i=0;i<i1;i++)
	{
		if(books_name[i][1]==zipcode)
		{
			books_name[i][0]="";
			books_name[i][1]="";
			books_name[i][2]="";
			books_name[i][3]="";
		}
	}
	ofstream libe("books.txt", ios::trunc);
	libe<<"";
	libe.close();
	for(int i=0;i<i1;i++)
	{
		ofstream booksa("books.txt", ios::app);
		booksa<<books_name[i][0]<<" - "<<books_name[i][1]<<" - "<<books_name[i][2]<<" - "<<books_name[i][3]<<endl;
	}
	return 0;
}
int serach_in_library()
{
	string isbn,zipcode;
	cout<<"Please Enter ISBN : ";
	cin>>isbn;
	cout<<"Please Enter ZIP Code : ";
	cin>>zipcode;
	for(int i=0;i<i3;i++)
	{
		if(loans_book[i][2]==zipcode && loans_book[i][3]==isbn)
		{
			for(int j=0;j<i1;j++)
			{
				if(books_name[j][1]==isbn)
				{
					cout<<books_name[j][0]<<" - "<<books_name[j][1]<<" - "<<books_name[j][2]<<" - "<<books_name[j][3]<<" - "<<endl;
				}
			}
		}
	}
	return 0;
}
int main()
{ 
	cout<<"Programmers : "<<endl;
	cout<<"ALIREZA OMIDI"<<endl;
	cout<<"ALIREZA MOHAMMAD POUR"<<endl;
	piano();
	system("CLS");
	book books;
	library lib;
	int n;
	cout << "Hello plz enter the right number : "<<endl;
	while(1)
	{
			cout<<"1.Add Library"<<endl;
			cout<<"2.Add Book To A Library"<<endl;
			cout<<"3.Add Book"<<endl;
			cout<<"4.Loan Books"<<endl;
			cout<<"5.Show Categories"<<endl;
			cout<<"6.Delete Library"<<endl;
			cout<<"7.Show Everything"<<endl;
			cout<<"8.Delete Book"<<endl;
			cout<<"9.Search In Library"<<endl;
			cout<<"10.EXIT"<<endl;

				while (cin >> n)
	{
	
		if (n == 1)
		{
			add_library(&lib);
			cout<<"Library Is Add"<<endl;
			system("CLS");
			break;
		}
		else if (n == 2)
		{
			add_book_to_library();
			break;
		}
		else if (n == 3)
		{
			add_book(&books);
			system("CLS");
			break;
		}
		else if (n == 4)
		{
			loan_book();
			system("CLS");
			//for(int i=0;i<4;i++)cout<<books_name[i][0];
			break;
		}
		else if (n == 5)
		{
			show_cat();
			//cout<<"changed"<<endl;
			//system("CLS");
			break;
		}
		else if (n == 6)
		{
			delete_library();
			//for(int i=0;i<2;i++)cout<<libraries_name[i][0];
			break;
		}
		else if (n == 7)
		{
			show_everything();
			break;
		}
		else if (n == 8)
		{
			delete_book();
			break;
		}
		else if (n == 9)
		{
			serach_in_library();
			break;
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
		
	}

	return 0;
}
