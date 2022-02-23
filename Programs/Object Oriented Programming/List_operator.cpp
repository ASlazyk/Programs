#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class rec
{
	private:
		string 	name;
		int 	tel;
		rec*	next;
	
	public:
		rec()
		{
			next = NULL;
		}
		
		void setname(string n)
		{
			name = n;
		}
		
		void settel(int t)
		{
			tel = t;
		}
		
		void setptr(rec* r)
		{
			next = r;
		}
		
		string getname()
		{
			return name;
		}
		
		int gettel()
		{
			return tel;
		}
		
		rec* getptr()
		{
			return next;
		}

};

class lista
{
	private:
		rec* glowa;
		
	public:
		lista()
		{
			glowa = NULL;
		}
		
	void dodaj(string n, int t)
	{
		rec* nowy = new rec;
		
		nowy->setname(n); 
		nowy->settel(t);
		
		nowy->setptr(glowa);
		glowa = nowy;
		
	}
	
	void wyswietl()
	{
		rec* temp;
		
		temp = glowa;
		
		while(temp != NULL)
		{
			cout << temp->getname() << ", " << temp->gettel() << endl;
			temp = temp->getptr();
		}
	}
	
	void append(string n, int t);
	void del(string n);
	void delall();
	bool szukaj(string n);
	
};

void lista::del(string n)
{
	rec* temp;
	temp = glowa;
	rec* temp_prev;
	temp_prev = glowa;
	while(temp != NULL)
	{
		if(n.compare(temp->getname()) == 0)
		{
			temp_prev->setptr(temp->getptr());
			delete temp;
			
		}
		temp_prev = temp;
		temp = temp->getptr();
	}
		
}

void lista::delall()
{
	rec* temp;
	temp = glowa;	
	while(glowa != NULL)
	{
		while(temp != NULL)
		{
			temp = temp->getptr();
		}
		delete temp;
	}
}

bool lista::szukaj(string n)
{
	rec* temp;
	temp = glowa;
	while(temp != NULL)
	{
		if(n.compare(temp->getname()) == 0)
		{
			cout << "found " << temp->getname()<< endl;
			return 1;
		}
		temp = temp->getptr();
	}
	cout << "not found " << n << endl; 
	return 0;
	
}


void lista::append(string n, int t) 
{
	rec* nowy = new rec;
	rec* temp;

	rec* temp_prev;
	temp = glowa;
	nowy->setname(n);
	nowy->settel(t);
	nowy->setptr(NULL);
	
	while (temp != NULL)
	{
		temp_prev = temp;
		temp = temp->getptr();
	}	
	temp_prev->setptr(nowy);
}

int main(int argc, char** argv) {
	
	lista* mojalista = new lista;
	
/*	mojalista->dodaj("Jan Kowalski", 1234567);
	mojalista->dodaj("Jan Nowak", 2345678);
	mojalista->dodaj("Donald Trump", 3456789);
	mojalista->append("Karol Wojtyla", 4567890);
	mojalista->wyswietl();
	cout << endl;
	
	mojalista->szukaj("Karol Wojtyla");
	mojalista->szukaj("Jan Pawel");
	cout << endl;
	
	mojalista->del("Jan Nowak");
	mojalista->wyswietl();
	cout << endl;
	
	mojalista->delall();
	mojalista->wyswietl();
	return 0;
*/
	int order;
	string NAME;
	int PHONE;
	char areyousure;
	
	cout << "+-----------------------------------------+" << endl;
	cout << "|                                         |" << endl;
	cout << "|   Welcome to our humble list operator   |" << endl;
	cout << "|                                         |" << endl;
	cout << "+-----------------------------------------+" << endl;
		
	while (1)
	{
		order = 9;
		while (order < 0 or order > 6)
		{
			cout << "Insert:" << endl;
			cout << "1 - to add record" << endl;
			cout << "2 - to append record" << endl;
			cout << "3 - to search for record" << endl;
			cout << "4 - to delete record" << endl;
			cout << "5 - to delete all records" << endl;
			cout << "6 - to print all records" << endl;
			cout << "0 - to quit" << endl;
			cin >> order;
			
		}
		cin.ignore();
		switch (order)
		{
			case 0:
				exit(0);
			case 1:
				cout << "Insert name:" << endl;
				getline(cin,NAME);
				cout << "Insert phone:" << endl;
				cin >> PHONE;
				mojalista->dodaj(NAME, PHONE);
				break;
			case 2:
				cout << "Insert name:" << endl;
				getline(cin,NAME);
				cout << "Insert phone:" << endl;
				cin >> PHONE;
				mojalista->append(NAME, PHONE);
				break;
			case 3:
				cout << "Insert name to search for:" << endl;
				getline(cin,NAME);
				mojalista->szukaj(NAME);
				break;
			case 4:
				cout << "Insert name" << endl;
				getline(cin,NAME);
				mojalista->del(NAME);
				break;
			case 5:
				cout << "Ar you sure? (y/n)" << endl;
				cin >> areyousure;
				if(areyousure == 'y')
				{
					mojalista->delall();
				}
				break;
			case 6:
				cout << "\n\n" << endl;
				mojalista->wyswietl();
				cout << "\n\n\n" << endl;
				break;
		}
	}
}
