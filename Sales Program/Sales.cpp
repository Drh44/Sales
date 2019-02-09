//Author: Dylan Hesser
//Date: 7/5/18
/* This program will read a specific file and gather
sale numbers for a specified amount of people. It will
then output said information to a new file. */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
//These variables are global so that functions can alter them and they stay the same outside of the function's scope
double average, grandTotal, total, grandAverage;
ifstream inStream; 
ofstream outStream;

void intro ()
   {
       cout << "Hello, this program will allow you to view a file called theSales.txt and get information from it! \nIt will showcase statistics on weeks of data for different people!"  << endl ;
   }
//The open output file function will allow any real file to be used for the output
void openOutputFile (ofstream& off, string outputFile)
   {
       cout << "What is the name of the output file: ";
       cin >> outputFile;
       off.open(outputFile);
       if (outStream.fail())
        {   
            cout<< "Output file opening failed.\n";
            exit(1);
        }
   }
//These two output variables are easy to find out and don't need to be changed at a constant rate, so they have their own function.
void writeToOutput (ofstream& off,int totalNames,int weekCount)
   {
     off << "The grand total is : " << grandTotal << endl;
     off << "The grand Average is : " << grandAverage << endl;
     off << "The total number of people is " << totalNames << endl  ;
     off << "The total number of weeks that had sales were: " << weekCount << endl;
   }
//this function will calculate the total, average, grand average, and grand total of the input file
void Statistics (int day1, int day2, int day3, int day4, int day5, int weekCount)
   {
     total =  day1 + day2 + day3 + day4 + day5 ;
     average = total / (5) ;
     grandTotal = grandTotal + total;
     grandAverage = grandTotal / (5 * weekCount) ;
   }
//This is the output to the output file
void writeFile (ofstream& off, string lastName)
   {
     off  << lastName << " sales for the week: " << total << " The average for the week: " << average << endl;
   }
/*This is where most of the work is done. This will take the input file with the data
and read each line to gather the numbers needed for each variable. Since there is a loop
needed anyways for the weeks, I went ahead and called my other functions into this function. */    
void readFileAndGetOutput (ifstream& in ,string lastName, string firstName)
   {
     int i, j ,totalNames,weekCount = 0, day1, day2, day3, day4, day5, weeks = 0;
     in >> totalNames;
     for ( i=0; i < totalNames; i++ )
      {
         in >> lastName >> firstName;
         in >> weeks ;
   
         for ( j = 0; j < weeks; j++)
          {
             in >> day1 >> day2 >> day3 >> day4 >> day5 ;
             weekCount++;
             Statistics (day1, day2, day3, day4, day5, weekCount);
             writeFile (outStream , lastName);
          }
       }
       writeToOutput (outStream, totalNames, weekCount);
   }
//Main is now just a few lines of code due to readFile being most of the code needed.
int main () 
   {
     string lastName, firstName, outputFile;
     intro();
     inStream.open("theSales.txt");
     if (inStream.fail())
        {   
            cout<< "Input file opening failed.\n";
            exit(1);
        }
     openOutputFile (outStream, outputFile);
     readFileAndGetOutput (inStream, lastName, firstName);
     return 0;
   }