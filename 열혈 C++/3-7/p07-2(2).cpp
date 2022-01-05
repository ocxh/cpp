#include<iostream>
#include<cstring>
using namespace std;

class Book
{
	private:
		char* title;
		char* isbn;
		int price;
	public:
		Book(char *title, char *isbn, int price):price(price)
		{
			this->title = new char[strlen(title)];
			this->isbn = new char[strlen(isbn)];
			strcpy(this->title, title);
			strcpy(this->isbn, isbn);
		}
		void ShowBookInfo()
		{
			cout<<"제목: "<<title<<endl;
			cout<<"ISBN: "<<isbn<<endl;
			cout<<"가격: "<<price<<endl; 
		}
		~Book()
		{
			delete []title;
			delete []isbn;
		}
};

class EBook : public Book
{
	private:
		char *DRMKey;
	public:
		EBook(char* title, char* isbn, int price, char* DRMKey): Book(title,isbn,price)
		{
			this->DRMKey = new char[strlen(DRMKey)];
			strcpy(this->DRMKey, DRMKey);
		}
		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout<<"인증키: "<<DRMKey<<endl;
		}
		~EBook()
		{
			delete []DRMKey;
		}
};

int main()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 C++", "555-12345-890-1", 10000,"fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
	return 0;
}
