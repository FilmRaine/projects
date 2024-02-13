#include<iostream>
#include<string>

using namespace std;
	string firstname,middlename,lastname;



int main(){

//----obtain the user's firstname
  cout << "Enter your first name: ";
  getline(cin, firstname);

//----obtain user's middlename, if applicable
  cout << "Enter your middle name (if applicable): ";
  getline(cin, middlename);

//----obtain user's lastname
  cout << "Enter your last name: ";
  getline(cin, lastname);

//declaring string for fullname
  
     string fullname;

//set first string to fullname to begin
  fullname += firstname + " " + middlename + " " + lastname;

//checking if middlename is empty, then adding it to fullname
  if(!middlename.empty()){
	fullname += " " + middlename;
  }

//checking if firstname is empty
 if(!firstname.empty()){
	fullname += " " + firstname;
	}

//declaring lastname, firstname middlename
	string formattedname;

//checking if lastname is empty
	if(!lastname.empty()){
	formattedname = lastname + ", " + firstname;//formats lastname first, then adds firstname.

		if(!middlename.empty()) {
			formattedname += " " + middlename;//checks for middlename, if it is present, adds it.
			}
	}

//declaring alphabetical string
	string sortedname;

//checking the values of each name, if they are lessthan/ equal to respectively

//---------------------------------------------------------------------------------------------------------------------

//checks where to put firstname
	if(firstname <= middlename && firstname <= lastname){
		sortedname = firstname;
		if (middlename <= lastname) {
			sortedname += " " + middlename + " " + lastname;
		} else {
			sortedname += " " + lastname + " " + middlename;
		}
	}
//checks where to put middlename
	if(middlename <= firstname && middlename <= lastname){
		sortedname = middlename;
		if(firstname <= lastname){
			sortedname += " " + firstname + " " + lastname;
		} else {
			sortedname += " " + lastname + " " + firstname;
		}
	}

//checks where to put lastname
	if(lastname <= firstname && lastname <= middlename){
		sortedname = lastname;
		if(firstname <= middlename){
			sortedname += " " + firstname + " " + middlename;
		} else {
			sortedname += " " + middlename + " " + firstname;
		}
	}

	//printing the names as required

	cout << "Full Name: " << fullname << endl;
	cout << "Formatted Name: " << formattedname << endl;
	cout << "Alphabetical Name: " << sortedname << endl;

	return 0;
}
