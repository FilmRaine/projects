#include<iostream>
#include<fstream>
#include<array>

using namespace std;
ifstream infile;
string month;
int day, year;
double precip, snowIn;


//Functions-------------------------------------------------------
double findLowestTemperature(const double temperatures[], int size){
	double lowestTemp = temperatures[0];
	for(int i = 1; i < size; i++){
		if (temperatures[i] < lowestTemp) {
			lowestTemp = temperatures[i];
		}
	}
	return lowestTemp;
}

//average Low 
double calculateAverageLow(const double lowTemperatures[], int size){
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += lowTemperatures[i];
	}
	return sum / size;
}

//daily snow change
void calculateDailySnowDepthChange(const double snowDepth[], int size){
	for(int i = 1; i < size; i++){
		double dailychange = snowDepth[i] - snowDepth[i-1];
		cout << "Day " << i << ": " << dailychange << " inches" << endl;
	}
}


//main------------------------------------------------------------------

int main(){
	ifstream infile("weather.txt"); //opens "weather.txt"


	const int numEntries = 31; // size of array
	int day[numEntries];
	string month[numEntries];
	int year[numEntries];
	double highTemperatures[numEntries];
	double lowTemperatures[numEntries];
	double precip[numEntries];
	double snowIn[numEntries];
	double snowDepth[numEntries];

	for (int i = 0; i < numEntries; i++){ //reads in each value of the file
		infile >> day[i];
		infile >> month[i];
		infile >> year[i];
		infile >> highTemperatures[i];
		infile >> lowTemperatures[i];
		infile >> precip[i];
		infile >> snowIn[i];
		infile >> snowDepth[i];
	}

	infile.close(); // close the file

	double lowestTemperature = findLowestTemperature(lowTemperatures, numEntries);
	double averageLowTemperature = calculateAverageLow(lowTemperatures, numEntries);
	cout << "Lowest recorded temperature: " << lowestTemperature << " degrees" << endl; // print lowest temp
	cout << "Average daily low temperature: " << averageLowTemperature << " degrees" << endl; // print average low
	cout << "Daily change in total snow depth: " << endl;
	calculateDailySnowDepthChange(snowDepth, numEntries); //prints how much change in snowfall from previous day

	return 0;

}

