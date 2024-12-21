/*readfile.cpp 
 *
 * CS 121.Bolden...........Jackson Staples
 * 4/23/2024 .................stap2053@vandals.uidaho.edu
 *
 * Program to intake a text file of tv shows. Functions to print 
 * list of shows, actors in a given show, shows in a date range,
 * or shows a given actor played
 *---------------------------------------------------------------------
*/ 
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<limits>

#include"actorlist.h"
#include"BSTree.h"



using namespace std; 


void GetSeriesName(char line[], char seriesName[]);
void GetYears(char line[], int & yStart, int & yEnd);


int main(){
    BinarySearchTree showTree;
    int nSeries = 0;
    
    int FuncChoice = 0;
    int beginning = 0;
    int ending = 0;
    string actor;
    string show;
    int check = 0;
    
    ifstream fIn( "Allmovies.txt", ios::in);

    if(!fIn){
        cout << "Unable to open \"tvDB\" data file" << endl;
        exit(-1);
    }

    const int MAX_LINE = 128;

    char line[MAX_LINE];
    char seriesName[MAX_LINE];
    char seriesCatagory[MAX_LINE/2];
    char seriesURL[MAX_LINE];
    char actorName[MAX_LINE/2];

    int yStart, yEnd;


    while(fIn.getline(line, MAX_LINE)){
        if(strlen(line) == 0){
            continue;
        }
        
        GetSeriesName(line, seriesName);
        GetYears(line, yStart, yEnd);

        fIn.getline(seriesCatagory, MAX_LINE/2);
        fIn.getline(seriesURL, MAX_LINE);

        
        ActorList newList;
        while(fIn.getline(line, MAX_LINE/2) && strlen(line) > 0){
            strcpy(actorName, line);   
            newList.Add(actorName); // add actor to list

        }
        showTree.AddNode(seriesCatagory, seriesName, yStart, yEnd, newList.getHead()); // create tree node with each actor list
    
        nSeries++;
    }

    fIn.close();
        cout << endl;
        cout << endl;

    
    while(check != 1)   {
        cout << "Please make a choice for what you would like to do \n";
        cout << "0 - Exit Program \n";
        cout << "1 - List shows in a user-given date range \n";
        cout << "2 - Print a list of all shows in the tree \n";
        cout << "3 - Print a list of all shows with a user-given actor \n";
        cout << "4 - Print a list of all actors in a user-given show \n";
        cout << "Enter a choice: ";
        cin >> FuncChoice;

        switch(FuncChoice){
            case 0:
                check = 1;
                break;
            case 1:
                cout << "Enter a beginning date: ";
                cin >> beginning;
                cout << "Enter an ending date: ";
                cin >> ending;
                showTree.findDateRange(showTree.getTreePtr(), beginning, ending ); // finds all shows between a certain start and end date
                break;
            case 2:
                showTree.PrintTree(); // prints list of all show  titles
                break;
            case 3:
                cout << "Enter an actor's name (case sensitive): ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, actor);
                showTree.SearchActor(showTree.getActorPtr(), actor); // finds all shows featuring an actor
                break;
            case 4:
                cout << "Enter a show title: ";
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // lists all actors in a given show
                getline(cin, show);
                showTree.fActorList(show);
                break;
          default:
            cout << "Invalid choice. Please try again." << endl;
            break;  
        }

    }
}


//------Functions--------------------------------------

void GetSeriesName(char line[], char seriesName[]){ // read string before open parend
    int yearStart;

    yearStart = IndexOf(line, '(' );
    GetSubString(line, 0, yearStart-1, seriesName);
}



void GetSubString(char s[], int start, int end, char result[]){ // get a string based on the starting index 
    int i;
    int iRes = 0;

    for(i = start; i < start+end; i++){
        result[iRes++] = s[i];
    }


    result[iRes] = '\0';
    RemoveBlanksFromString(result);
}

void RemoveBlanksFromString(char s[]){
    int sLen = strlen(s);

    for(int i =sLen; i >=0; i--){
        if(isalpha(s[i]) || isdigit(s[i])){ // checks if char is alpha or number
            break;
        }
        if(s[i] == ' ' || s[i] <= 32 || s[i] >= 127 ){ //parses for only ascii characters
            s[i] = '\0';
        }
    }
}


int IndexOf(char s[], char c){ //takes position of char
    int i = 0;
    
    while(s[i] != '\0' && s[i] != c){
        i++; 
    }
    return i;
}

void GetYears(char input[], int &yearStart, int &yearEnd) {
   // cout << "Entering GetYears()" << endl;

    char tmpString[10];
    int i = 0;
    int j = 0;

    // Find the start year
    while (input[i] != '\0' && !isdigit(input[i])) {
        i++;
    }

    while (input[i] != '\0' && isdigit(input[i])) {
        tmpString[j++] = input[i++];
    }
    tmpString[j] = '\0';
    yearStart = atoi(tmpString);

    // Find the end year
    j = 0;
    while (input[i] != '\0' && !isdigit(input[i])) {
        i++;
    }

    while (input[i] != '\0' && isdigit(input[i])) {
        tmpString[j++] = input[i++];
    }
    tmpString[j] = '\0';
    yearEnd = atoi(tmpString);

   // cout << "leaving GetYears()" << endl;
}
