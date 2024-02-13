#include<time.h>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


int speciesmenu();
string chosenspecies;

class pet{
  public:
    int health; // 0-100, 0 is dead.
    int hunger; // 0-100, 100 is full
    int energy;
    string name;
    string getname();
    pet();//prototype constructor
    void print();
    //---actions with pet---
    int feed();
    int walk();
    int nap();
    int train();
    // trick to require training
    int play();
	int play_choice();
    int trick_choice();//trick menu prototype
    int trick();
	int trick_prof; // 0-100, 100 means pet can do trick
    // random events
    int gets_lost();
    int bad_dream();
    int oops_trick();
};

int main(){
  int choice;
  pet p1;
  int speciesIndex = speciesmenu();
  switch(speciesIndex){
	case 1: chosenspecies = "dog";
	break;
	case 2:
	chosenspecies = "cat";
	break;
	case 3:
	chosenspecies = "turtle";
	break;
	case 4:
	chosenspecies = "hedgehog";
	break;
	case 5:
	chosenspecies = "ferret";
	break;
	default:
	cout << "Somehow you don't have a species...\n";
	}
 while (p1.health > 0 && p1.hunger > 0 && p1.energy > 0) {
   p1.print();

//menu for choices, include option to add submenu for game interactions
  cout << "\n";
  cout << "What would you like to do?\n";
  cout << "(Please note that if your pet's health\n";
  cout << " hunger or energy reach 0, the game ends.)\n\n";
  cout << "(1) Feed your pet\n";
  cout << "(2) Take your pet for a walk?\n";
  cout << "(3) Let your pet take a nap?\n";
  cout << "(4) Play with your pet?\n";
  cout << "(5) Let your pet attempt a trick?\n";
  cout << "(6) Exit the program.\n";
  cin >> choice;
    cout << "----------------------------------------------------------\n\n";
 
	switch(choice){
	  case 1:
		p1.feed();
		cout << "\n";
		break;
	  case 2:
		p1.walk();
		cout << "\n";
		break;
	  case 3:
		p1.nap();
		cout << "\n";
		break;
	  case 4:
		p1.play_choice();
		cout << "\n";
		break;
	  case 5:
		p1.trick();
		cout << "\n";
		break;
	  case 6:
		return 0;
		break;
	  default:
		cout << "Please enter a correct number (1-6).\n";
	}
   }
if(p1.hunger <=0 || p1.health <=0 || p1.energy <=0){
	cout << "Your pet " << p1.name << " has died.\n";
	cout << "The program will now exit.\n\n\n";
	return 0;
	}
}


//constructor
pet::pet(){
 cout << "Generating a new pet.\n";
 cout << "What would you like to name your pet?\n";
 int speciesmenu();
 health = 50;
 hunger = 50;
 energy = 75;
 trick_prof = 0;
 getname();
 cout << "\n";
}


//-- user choice for pet type
int speciesmenu(){
  int choice;
 	cout << "Please make your choice for a species:\n";
	cout << "(1) Dog \n";
	cout << "(2) Cat \n";
	cout << "(3) Turtle \n";
	cout << "(4) Hedgehog \n";
	cout << "(5) Ferret \n";
  do{
	cin >> choice;
	cout << "\n";
	cout << "----------------------------------------------------------\n\n";
	if(choice < 1 || choice > 5){
	  cout << "Please enter a correct number \n";
	  } // run this code until choice is >1 or <5
	}while(choice < 1 || choice > 5);
    return choice;
  cout << "\n";
}


// user input name
string pet::getname(){
	cin >> name;
	return name;
	};


// print pet name and stats
void pet::print(){
  	cout << "Your pet " << name << " the " << chosenspecies << " has " << hunger << " hunger points left.\n";
  	cout << "It has " << health << " health points left.\n";
  	cout << "It has " << energy << " energy left.\n";
  	 }; //prototype



//----------------pet interaction functions-----------------------------------------


// feed the pet, increase health + reduce hunger
int pet::feed(){
	cout << "You fed your pet.\n";
	if(hunger < 100){
		hunger += 10;
		if(health < 100){
		health += 10;
		}
		return health;
		return hunger;
	}else{
	cout << "Your pet doesn't need food right now\n";
	return health;
	return hunger;
	}
}


int pet::walk(){
	if(hunger >= 10 && energy >= 15){
		hunger -= 10;
		energy -= 15;
	}
	srand(time(0));
	int roll = rand() % 5;
	cout << "You took " << name << " for a walk.\n";
     switch(roll){
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		gets_lost();
		break;
	}
	return hunger;
	return energy;
	return health;
}


int pet::nap(){
	srand(time(0));
	int roll = rand() % 5;
	cout << "You let " << name << " take a nap.\n";
	switch(roll){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			bad_dream();
			break;
		case 4:
			break;
	return energy;
	}
	if(energy < 95){
		energy += 15;
	return energy;
	}else{
	cout << name << " has way to much energy to nap right now!\n";
	return energy;
	}
}


int pet::train(){
  if(trick_prof < 100){
	cout << "You took " << name << " out to train\n";
	if(hunger >= 20  && energy >= 15){
		hunger -= 20;
		energy -= 15;
		trick_prof += 20;
		return hunger;
		return energy;
		return trick_prof;
	}else{
	cout << name << " needs downtime before training!\n";
	return energy;
	return hunger;
	return trick_prof;
	}

  }else{
	cout << name << " is ready to do a trick!\n";
return trick_prof;
return hunger;
return energy;
	}
}

int pet::trick(){
	srand(time(0));
	int roll = rand() %5;
	if(trick_prof == 100){
	  cout << "You took " << name << " out to do a trick\n";
	switch(roll){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			oops_trick();
			break;
		return health;
		return hunger;
		return energy;
		}
		if(hunger >= 0 && energy >= 10){
		  cout << name << " did a super cool trick!\n";
		  hunger -= 10;
		  energy -= 20;
		return hunger;
		return energy;
		}else{
		  cout << name << " needs downtime before trying a trick.\n";
			return hunger;
			return energy;
		}
	}else{
	  cout << name << " needs to train more before doing a trick.\n";
	return hunger;
	return energy;
	}
}


//----------Random Events------------------------------------------------

int pet::gets_lost(){
	cout << name << " got lost and caught in brambles on a walk!\n";
	cout << "-10 health! \n";
	health -= 10;
	return health;
	return energy;
}


int pet::bad_dream(){
	cout << name << " had a bad dream while napping.\n";
	cout << "-15 energy\n";
	if(energy >= 16){
		energy -= 15;
	}
	return energy;
}


int pet::oops_trick(){
	cout << name << " had an accident and got hurt while doing a trick!\n";
	cout << "-15 health and -5 energy.\n";
	energy -= 5;
	health -= 15;
	return health;
	return energy;
}


int pet::play_choice(){
	int choice;
	cout << "Would you like to (1)  train " << name << endl;
	cout << "to do a trick or (2)  play fetch?\n";
	cin >> choice;
	switch(choice){
		case 1:
		  train();
		  break;
		case 2:
		  play();
		  break;
		default:
		  cout << "Please enter a correct choice (1 or 2)\n";
		  break;
	}
return hunger;
}


int pet::play(){
	if(hunger >= 10 && energy >= 10){
		cout << "You played fetch with " << name << endl;
		hunger -= 10;
		energy -= 10;
		}
	return hunger;
	return energy;
}

