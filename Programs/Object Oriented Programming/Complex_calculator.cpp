#include <iostream>
#include <tgmath.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class complex
{
	private:
		double real,imag;
	public:
		
	complex()												//CONSTRUCTOR 1
	{
		real = 0;
		imag = 0;
	}
	
	complex(double r, double i)								//CONSTRUCTOR 2
	{
		real = r;
		imag = i;
	}
	
	complex operator *(complex c)							//MULTIPLICATION
		{
			complex te;
			te.real = real*c.real - imag*c.imag;
			
			te.imag = real*c.imag + imag*c.real;
			return te;
		}
		
	complex operator +(complex c)							//ADDITION
		{
			complex te;
			te.real = real + c.real;
			
			te.imag = imag + c.imag;
			return te;
		}	
		
	complex operator -(complex c)							//SUBTRACTION
		{
			complex te;
			te.real = real - c.real;
			
			te.imag = imag - c.imag;
			return te;
		}	
		
	complex operator /(complex c)							//DIVISION
		{
			complex te;
			te.real = (real*c.real + imag*c.imag)/(c.real*c.real + c.imag*c.imag);
			
			te.imag = (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag);
			return te;
		}
	
	complex operator +=(complex c)							//ASSIGNMENT OPERATOR +=
		{
			real += c.real;
			imag += c.imag;
		}
	
	complex operator -=(complex c)							//ASSIGNMENT OPERATOR -=
		{
			real -= c.real;
			imag -= c.imag;
		}
	
	complex operator *=(complex c)							//ASSIGNMENT OPERATOR *=
		{
			double newreal = real*c.real - imag*c.imag;
			double newimag = real*c.imag + imag*c.real;
			real = newreal;
			imag = newimag;
		}
	
	complex operator /=(complex c)							//ASSIGNMENT OPERATOR /=
		{
			double newreal = (real*c.real + imag*c.imag)/(c.real*c.real + c.imag*c.imag);
			double newimag = (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag);
			real = newreal;
			imag = newimag;
		}
									
	complex operator <(complex c)							//COMPARISON <
		{
			if (sqrt(real*real + imag*imag) < sqrt(c.real*c.real + c.imag*c.imag)) {
				cout << "TRUE" << endl;
			} else {
				cout << "FALSE" << endl;
			}
		}
			
	complex operator <=(complex c)							//COMPARISON <=
		{
			if (sqrt(real*real + imag*imag) <= sqrt(c.real*c.real + c.imag*c.imag)) {
				cout << "TRUE" << endl;
			} else {
				cout << "FALSE" << endl;
			}
		}				
			
	complex operator >(complex c)							//COMPARISON >
		{
			if (sqrt(real*real + imag*imag) > sqrt(c.real*c.real + c.imag*c.imag)) {
				cout << "TRUE" << endl;
			} else {
				cout << "FALSE" << endl;
			}
		}		
				
	complex operator >=(complex c)							//COMPARISON >=
		{
			if (sqrt(real*real + imag*imag) >= sqrt(c.real*c.real + c.imag*c.imag)) {
				cout << "TRUE" << endl;
			} else {
				cout << "FALSE" << endl;
			}
		}
	
	complex operator ++()									//UNARY OPERATOR ++
		{
			++real;
		}

	complex operator --()									//UNARY OPERATOR --
		{
			--real;
		}
	
	double getreal()										//GETTER REAL
	{
		return real;
	}
	
	double getimag()										//GETTER IMAG
	{
		return imag;
	}
	
	void setreal(double r)									//SETTER REAL
	{
		real = r;
	}
	
	void setimag(double i)									//SETTER IMAG
	{
		imag = i;
	}
};

int main(int argc, char** argv) {
	
	
	complex *c1;
	complex *c2;
	complex *c3;
	c1 = new complex;
	c2 = new complex;
	c3 = new complex;
	double temp;
	string oper;
	char operchar1;
	char operchar2;
	
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                                                     |" << endl;
	cout << "|        WELCOME TO COMPLEX NUMBERS CALCULATOR        |" << endl;
	cout << "|                                                     |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|   Please enter real and imaginary part              |" << endl;
	cout << "|   of first complex number,                          |" << endl;
	cout << "|   then choose desired operation                     |" << endl;
	cout << "|   by entering appropriate operator                  |" << endl;
	cout << "|   and enter second complex number.                  |" << endl;
	cout << "|   Possible operations:                              |" << endl;
	cout << "|   - addition: enter +                               |" << endl;
	cout << "|   - subtraction: enter -                            |" << endl;
	cout << "|   - multiplication: enter *                         |" << endl;
	cout << "|   - division: enter /                               |" << endl;
	cout << "|   - comparison: enter <, <=, > or >=                |" << endl;
	cout << "|   - incrementation of real part: enter ++           |" << endl;
	cout << "|   - decrementation of real part: enter ++           |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
	
	while (1)
	{
		cout << endl;	
		cout << "Enter real part of first complex number:" << endl;
		cin >> temp;
		c1->setreal(temp);
		cout << "Enter imaginary part of first complex number:" << endl;
		cin >> temp;
		c1->setimag(temp);	
		cout << "Enter symbol of desired operation:" << endl;
		cin >> oper;
		
		if ((oper != "++") and (oper != "--"))
		{
			cout << "Enter real part of second complex number:" << endl;
			cin >> temp;
			c2->setreal(temp);
			cout << "Enter imaginary part of second complex number:" << endl;
			cin >> temp;
			c2->setimag(temp);
		}
		
		if (oper.length() == 2)  //dwuznakowy oper
		{
			operchar1 = oper.at(0);
			operchar2 = oper.at(1); 
			switch(operchar2)  //switch na drugi znak
			{
				case '=':
					switch(operchar1) //switch na pierwszy znak dla =
					{
						case '<':
							cout << "Statement (" << c1->getreal() 
							<< " , " << c1->getimag() 
							<< "i) <= (" << c2->getreal() 
							<< " , " << c2->getimag() << "i) is:" << endl;
							*c1<=*c2;
							break;
						case '>':
							cout << "Statement (" << c1->getreal() 
							<< " , " << c1->getimag() 
							<< "i) >= (" << c2->getreal() 
							<< " , " << c2->getimag() << "i) is:" << endl;
							*c1>=*c2;
							break;
						default:
							cout << "Something went wrong, please try again" << endl;
							break;
					}
					break;
				case '+':
					switch(operchar1) //switch na pierwszy znak dla +
					{
					case '+':
						cout << "Incremented number (" << c1->getreal() << " , " << c1->getimag() << "i) equals:" << endl;
						++*c1;
						cout << "(" << c1->getreal() << " , " << c1->getimag() << "i)" << endl;
						break;
					default:
						cout << "Something went wrong, please try again" << endl;
						break;
					}
					break;
				case '-':
					switch(operchar1) //switch na pierwszy znak dla -
					{
					case '-':
						cout << "Decremented number (" << c1->getreal() << " , " << c1->getimag() << "i) equals:" << endl;
						--*c1;
						cout << "(" << c1->getreal() << " , " << c1->getimag() << "i)" << endl;
						break;
					default:
						cout << "Something went wrong, please try again" << endl;
						break;
					}
					break;
				default: 				//error
					cout << "Something went wrong, please try again" << endl;
					break;
			}
		} else if (oper.length() == 1) { //jednoznakowy oper
			operchar1 = oper.at(0);
			switch(operchar1)
			{
				case '+':
					*c3 = *c1 + *c2;
					cout << "(" << c1->getreal() << " , " << c1->getimag()
					<< "i) + (" << c2->getreal() << " , " << c2->getimag()
					<< "i) = (" << c3->getreal() << " , " << c3->getimag() << "i)" << endl;
					break;
				case '-':
					*c3 = *c1 - *c2;
					cout << "(" << c1->getreal() << " , " << c1->getimag()
					<< "i) - (" << c2->getreal() << " , " << c2->getimag()
					<< "i) = (" << c3->getreal() << " , " << c3->getimag() << "i)" << endl;
					break;
				case '*':
					*c3 = *c1 * *c2;
					cout << "(" << c1->getreal() << " , " << c1->getimag()
					<< "i) * (" << c2->getreal() << " , " << c2->getimag()
					<< "i) = (" << c3->getreal() << " , " << c3->getimag() << "i)" << endl;
					break;
				case '/':
					*c3 = *c1 / *c2;
					cout << "(" << c1->getreal() << " , " << c1->getimag()
					<< "i) / (" << c2->getreal() << " , " << c2->getimag()
					<< "i) = (" << c3->getreal() << " , " << c3->getimag() << "i)" << endl;
					break;
				case '<':
					cout << "Statement (" << c1->getreal() 
					<< " , " << c1->getimag() 
					<< "i) < (" << c2->getreal() 
					<< " , " << c2->getimag() << "i) is:" << endl;
					*c1<*c2;
					break;
				case '>':
					cout << "Statement (" << c1->getreal() 
					<< " , " << c1->getimag() 
					<< "i) > (" << c2->getreal() 
					<< " , " << c2->getimag() << "i) is:" << endl;
					*c1>*c2;
					break;
				default:
					cout << "Something went wrong, please try again" << endl;
					break;
				
			}
		} else {
			cout << "Something went wrong, please try again" << endl;
		}
	cout << "\n\n\n" << endl;
	}
	while (0) 
	{
	complex c10(1,2);
	complex *c11;	
	c11 = new complex;
	c11->setreal(3);
	c11->setimag(4);
	
		
	cout << "(" << c11->getreal() << " , " << c11->getimag() << ')' << endl;
	*c11 /= c10;
	cout << "(" << c11->getreal() << " , " << c11->getimag() << ')' << endl;
	break;
	}	
	return 0;
}
