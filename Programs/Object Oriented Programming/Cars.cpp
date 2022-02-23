#include <iostream>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class vehicle
{
	private:
		static int no_of_vehicles;
	protected:
		int year_of_production, no_of_km, velocity;
		string origin;
		
	public:
		vehicle()
		{
			no_of_vehicles++;
		}
		
		void setyear(int x)					//setters
		{
			year_of_production = x;
		}
		
		void setkm(int x)
		{
			no_of_km = x;
		}	
		
		void setvelocity(int x)
		{
			velocity = x;
		}
		
		void setorigin(string x)
		{
			origin = x;
		}
		
		int getyear()						//getters
		{
			return year_of_production;
		}
		
		int getkm()
		{
			return no_of_km;
		}
		
		int getvelocity()
		{
			return velocity;
		}
		
		string getorigin()
		{
			return origin;
		}
			
		virtual void display_properties()
		{
			cout << "year: " << year_of_production << ", no of km: "
			<< no_of_km << ", velocity"" " << velocity << " km/h, origin: " << origin << endl;
		}
		
		static int getcount()
		{
			return no_of_vehicles;
		}
};

class car : public vehicle
{
	private:
		int no_of_seats;
	public:
		car(int yop, int nok, int vel, string ori, int nos)
		{
			year_of_production = yop;
			no_of_km = nok;
			velocity = vel;
			origin = ori;
			no_of_seats = nos;
		}
		
		void setseats(int x)
		{
			no_of_seats = x;
		}
		
		int getseats()
		{
			return no_of_seats;
		}
		
		void display_properties()
		{
			cout << "seats: " << no_of_seats << ", " ;
			vehicle::display_properties();
		}

};

class truck : public vehicle
{
	private:
		int max_load;
	public:
		truck(int yop, int nok, int vel, string ori, int max)
		{
			year_of_production = yop;
			no_of_km = nok;
			velocity = vel;
			origin = ori;
			max_load = max;
		}
		
		void setload(int x)
		{
			max_load = x;
		}
		
		int getload()
		{
			return max_load;
		}
		
		void display_properties()
		{
			cout << "max load: " << max_load << ", " ;
			vehicle :: display_properties();
		}
};


int vehicle::no_of_vehicles = 0;

int main(int argc, char** argv) {

	vector <vehicle*> vec;
	
	cout << "Number or vehicles: " << vehicle::getcount() << endl;
	cout << endl << "Non-polimorphic access" << endl;
	
	car *fiat = new car(1997,102400,160,"Italy",5);
	car *volkswagen = new car(2013,10500,180,"Germany",5);
	truck *star = new truck(1983,213700,150,"Poland",3500);
	truck *suzuki = new truck(2004,201900,140,"Japan",2400);
	car skoda(1992,400300,120,"Czech",5);
	
	fiat->display_properties();
	volkswagen->display_properties();
	star->display_properties();
	suzuki->display_properties();	
	skoda.display_properties();
	
	cout << "Number or vehicles: " << vehicle::getcount() << endl;
	cout << "\n\n\n" << endl;
	
	
	
	cout << endl << "Polimorphic access" << endl;
	
	vec.push_back(new car(2001,123400,160,"France",5));
	vec.push_back(new car(2002,234500,160,"Spain",5));
	vec.push_back(new truck(2002,345600,160,"Norway",5));
	vec.push_back(new truck(2003,456700,160,"Sweden",5));
	
	for(int k; k<vec.size(); k++)
	{
		vec[k]->display_properties();
	}
	
	cout << "Number or vehicles: " << vehicle::getcount() << endl;
	
	return 0;
}
