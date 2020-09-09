//Peter Klutchko 1/24/18
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inFile;
const int MAXCOUNTRIES = 250;

struct Country {
    float pop1950;
    float pop1970;
    float pop1990;
    float pop2010;
    float pop2015;
};

struct World {
    int numCountries;
    Country countries[MAXCOUNTRIES];
    float largestPop[3] = {0.0};
    string largestPopName[3];
    float fastestGrowthRate[4] = {0.0};
    string fastestGrowth[4];
    float futureCountries[10] = {0.0};
    string futureName[10];
}myWorld;

void topThree(string);
void fastestGrowth(string);
void prediction(string);

// the main function outputs a list of countries by reading the population.csv file.
// it also calls upon other functions to perform other tasks explained below.
int main()
{
    string country;
    int countryCounter = 0;
    
    inFile.open("population.csv");
    
    if(!inFile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    while(!inFile.eof() && countryCounter < MAXCOUNTRIES) {
        inFile >> myWorld.countries[countryCounter].pop1950;
        inFile >> myWorld.countries[countryCounter].pop1970;
        inFile >> myWorld.countries[countryCounter].pop1990;
        inFile >> myWorld.countries[countryCounter].pop2010;
        inFile >> myWorld.countries[countryCounter].pop2015;
        inFile.ignore();
        getline(inFile, country);
        
        if (myWorld.countries[countryCounter].pop2015 != 0) {
            cout << myWorld.countries[countryCounter].pop1950 << "  " << myWorld.countries[countryCounter].pop1970;
            cout << "  " << myWorld.countries[countryCounter].pop1990 << "  " << myWorld.countries[countryCounter].pop2010;
            cout << "  " << myWorld.countries[countryCounter].pop2015 << "  ";
            cout << country <<endl;
        }
        
        ++countryCounter;
    }
    
    inFile.close();
    
    
    inFile.open("population.csv");
    
    if(!inFile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    topThree(country);
    
    inFile.close();
    
    
    inFile.open("population.csv");
    
    if(!inFile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    fastestGrowth(country);
    
    inFile.close();
    
    
    inFile.open("population.csv");
    
    if(!inFile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }
    
    prediction(country);
    
    inFile.close();
    
    
    return 0;
}

//this function finds the top 3 largest countries
void topThree(string country)
{
    int countryCounter = 0;
    
    while(!inFile.eof() && countryCounter < MAXCOUNTRIES) {
        inFile >> myWorld.countries[countryCounter].pop1950;
        inFile >> myWorld.countries[countryCounter].pop1970;
        inFile >> myWorld.countries[countryCounter].pop1990;
        inFile >> myWorld.countries[countryCounter].pop2010;
        inFile >> myWorld.countries[countryCounter].pop2015;
        inFile.ignore();
        getline(inFile, country);
        
        if (myWorld.countries[countryCounter].pop2015 > myWorld.largestPop[2] && 
                                myWorld.countries[countryCounter].pop2015 < myWorld.largestPop[1]) {
            myWorld.largestPopName[2] = country;
            myWorld.largestPop[2] = myWorld.countries[countryCounter].pop2015;
        }
        if (myWorld.countries[countryCounter].pop2015 > myWorld.largestPop[1] && 
                                myWorld.countries[countryCounter].pop2015 < myWorld.largestPop[0]) {
            myWorld.largestPopName[1] = country;
            myWorld.largestPop[1] = myWorld.countries[countryCounter].pop2015;
        }
        if (myWorld.countries[countryCounter].pop2015 > myWorld.largestPop[0]) {
            myWorld.largestPopName[0] = country;
            myWorld.largestPop[0] = myWorld.countries[countryCounter].pop2015;
        }
        
        ++countryCounter;
    }
    
    cout << "\nThree Largest Countries by 2015 Population:\n";
    cout << "1. " << myWorld.largestPopName[0] << endl;
    cout << "2. " << myWorld.largestPopName[1] << endl;
    cout << "3. " << myWorld.largestPopName[2] << endl;
    
    return;
}

// this finds a country's growth rate per year-bracket and outputs the largest rate per bracket 
void fastestGrowth(string country)
{
    int countryCounter = 0;
    float firstBracket, secondBracket, thirdBracket, fourthBracket;
    
    while(!inFile.eof() && countryCounter < MAXCOUNTRIES) {
        inFile >> myWorld.countries[countryCounter].pop1950;
        inFile >> myWorld.countries[countryCounter].pop1970;
        inFile >> myWorld.countries[countryCounter].pop1990;
        inFile >> myWorld.countries[countryCounter].pop2010;
        inFile >> myWorld.countries[countryCounter].pop2015;
        inFile.ignore();
        getline(inFile, country);
        
        firstBracket = (myWorld.countries[countryCounter].pop1970 - myWorld.countries[countryCounter].pop1950) /
                        myWorld.countries[countryCounter].pop1950;
        secondBracket = (myWorld.countries[countryCounter].pop1990 - myWorld.countries[countryCounter].pop1970) /
                        myWorld.countries[countryCounter].pop1970;
        thirdBracket = (myWorld.countries[countryCounter].pop2010 - myWorld.countries[countryCounter].pop1990) /
                        myWorld.countries[countryCounter].pop1990;
        fourthBracket = (myWorld.countries[countryCounter].pop2015 - myWorld.countries[countryCounter].pop2010) /
                        myWorld.countries[countryCounter].pop2010;
        
        if (firstBracket > myWorld.fastestGrowthRate[0]) {
            myWorld.fastestGrowth[0] = country;
            myWorld.fastestGrowthRate[0] = firstBracket;
        }
        if (secondBracket > myWorld.fastestGrowthRate[1]) {
            myWorld.fastestGrowth[1] = country;
            myWorld.fastestGrowthRate[1] = secondBracket;
        }
        if (thirdBracket > myWorld.fastestGrowthRate[2]) {
            myWorld.fastestGrowth[2] = country;
            myWorld.fastestGrowthRate[2] = thirdBracket;
        }
        if (fourthBracket > myWorld.fastestGrowthRate[3]) {
            myWorld.fastestGrowth[3] = country;
            myWorld.fastestGrowthRate[3] = fourthBracket;
        }
    }
    
    cout << "\nFour Largest Growth Rates by Bracket:\n";
    cout << "1950-1970 - " << myWorld.fastestGrowth[0] << endl;
    cout << "1970-1990 - " << myWorld.fastestGrowth[1] << endl;
    cout << "1990-2010 - " << myWorld.fastestGrowth[2] << endl;
    cout << "2010-2015 - " << myWorld.fastestGrowth[3] << endl;
    
    cout << endl;
    
    return;
}

// this function chooses the top 10 countries that may become one of the next biggest three countries
void prediction(string country)
{
    int countryCounter = 0, listCounter = 0;
    int growthRate0, growthRate1, temp;
    
    while(!inFile.eof() && countryCounter < MAXCOUNTRIES) {
        inFile >> myWorld.countries[countryCounter].pop1950;
        inFile >> myWorld.countries[countryCounter].pop1970;
        inFile >> myWorld.countries[countryCounter].pop1990;
        inFile >> myWorld.countries[countryCounter].pop2010;
        inFile >> myWorld.countries[countryCounter].pop2015;
        inFile.ignore();
        getline(inFile, country);
        
        if (myWorld.countries[countryCounter].pop2015 = myWorld.largestPop[2])
            temp = myWorld.countries[countryCounter].pop2010;
            
        growthRate0 = (myWorld.countries[countryCounter].pop2015 - myWorld.countries[countryCounter].pop2010) /
                        myWorld.countries[countryCounter].pop2015;
        growthRate1 = (myWorld.largestPop[2] - temp) / myWorld.largestPop[2];
        
        if (myWorld.countries[countryCounter].pop2015 >= (myWorld.largestPop[2] * 0.25) && growthRate0 >= growthRate1
                                                                                                        && listCounter < 10) {
            myWorld.futureCountries[listCounter] = growthRate0;
            myWorld.futureName[listCounter] = country;
            ++listCounter;
        }
        
    }
    
    cout << "Top 10 candidates for the next biggest 3 countries:" << endl;
    
    for (int i = 0; i < listCounter; ++i) {
        cout << myWorld.futureName[i] << endl;
    }

    return;
}