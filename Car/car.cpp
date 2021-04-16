// Chapter 7 - Programming Challenge 12, Car Class
// This program creates a Car class and uses it to simulate
// an accelerating and braking Car object.
#include <iostream>
#include <string>
using namespace std;

// Car class declaration
class Car
{
  private:
	int year;       // Model year of the Car
	string make;    // Make of the Car
	int speed;      // Current speed of the Car (mph)
   
  public:
	// Constructor with default parameters
	Car(int y = 2010, string m = "Unknown")
	{	year = y;
		make = m;
		speed = 0;
	}

	// Accessors (i.e. "get" functions)
	int getYear()
	{  return year;  }

	string getMake()
	{  return make;  }

	int getSpeed()
	{  return speed;  }

	// Mutators
	void accelerate()
	{  speed +=5;  }

	void brake()
	{	if (speed >= 5)
			speed -=5;
		else
			speed = 0;
	}
};
   
// ************************* main ***************************
int main()
{
	Car hotRod(2024, "Tesla Model S");        // Create a Car object

	// Describe the car (This line was not required by the problem specs.)
	cout << "I'm in my " << hotRod.getYear() << " " 
		 << hotRod.getMake() << " hot rod.\n\n";

	// Accelerate 
	cout << "I'm accelerating ... \n\n";
	for (int faster = 1; faster <= 10; faster++)
	{
		hotRod.accelerate();
		cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
	}

	// Now stop
	cout << "\nNow I'm braking ... \n\n";
	for (int slower = 1; slower <= 10; slower++)
	{
		hotRod.brake();
		cout << "Current speed: " << hotRod.getSpeed() << " mph. \n";
	}  
      
	return 0;
}
