

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  cout<<"hello! this program will help you calculate the time it takes sound to travel \n";
  cout<<"through different materials. enter a letter to continue. if you would like to quit enter Q.\n";
  char choice; cin>>choice;
  choice = toupper(choice);
  
  //intialize a variable for the input file inFile
  ifstream inFile;
  //open file, TT13_L4_Box_In.txt, for input
  inFile.open("TT13_L4_Box_In.txt");

  //initialize a variable to count the number of materials
  int count = 0;

	//make sure that the file opens successfully
	if (inFile) 
	{
    	cout << "open of TT13_L4_Box_In.txt was successful.\n";
    
    	while (!inFile.eof()) 
		{
      		string material;
      		int speed;
      		inFile >> material>>speed;
      		if (inFile.eof()) break;
      		count++;

		}
    	inFile.close();

  	} 
	//if the file does not open give good feedback for user
	else 
	{
    	cout << "Sorry, but file, TT13_L4_Box_In.txt, did not open for input.\n";
	}

	cout << count << " materials were listed in this file.\n";
	const int NUM_MATERIALS = count;
	vector <string> material(NUM_MATERIALS);
	vector <int> speed(NUM_MATERIALS);
	
	//open file, TT13_L4_Box_In.txt, for input
	inFile.open("TT13_L4_Box_In.txt");

	//make sure that the file opens successfully
	if (inFile) 
	{
    	cout << "open of TT13_L4_Box_In.txt was successful.\n";
    
    	while (!inFile.eof()) 
		{
			for(int c=0; c < NUM_MATERIALS; c++)
			{
				inFile >> material[c] >>speed[c];
				//professor thayer: i used this to test the values
	    		/*cout<<"material = "<<material[c]<<" speed = "<<speed[c]<<endl;
				cout<<"count = "<<c<<endl;*/
			
			if (inFile.eof()) break;
			}
		}
    	inFile.close();

  	} 
	//if the file does not open give good feedback for user
	else 
	{
    	cout << "Sorry, but file, TT13_L4_Box_In.txt, did not open for input.\n";
	}
	
	// use vector.at to get strings for each material, use string to get first letters for menu
	string material_1 = material.at(0), material_2 = material.at(1), material_3 = material.at(2);
	string material_4 = material.at(3), material_5 = material.at(4), material_6 = material.at(5);
	// get the first letter using string[]
	char char_1 = material_1[0], char_2 = material_2[0], char_3 = material_3[0], char_4 = material_4[0]; 
	char char_5 = material_5[0], char_6 = material_6[0]; 
	
	//professor thayer: i used this to test the values or my variables
	/*cout<<"material_1 = "<< material_1<<" char_1 = "<< char_1<<" material_2 = "<< material_2
	<<" char_2 = "<< char_2<<" material_3 = "<< material_3<<" char_3 = "<< char_3<<endl;
	cout<<" material_4 = "<< material_4<<" char_4 = "<< char_4<<" material_5 = "<< material_5
	<<" char_5 = "<< char_5<<" material_2 = "<< material_6<<" char_6 = "<< char_6<<endl;*/
	
	
	//while loop to keep program running until the user indicates they want to stop
	while(choice!= 'Q')
	{
		//display menu and get user choice
		//create a function for menu?
		cout<<"\nplease enter a material: "<<char_1<<". "<<material[0]<<", "<<char_2<<". "<< material[1]
		<<", "<<char_3<<". "<<material[2]<<", "<<char_4<<". "<<material[3]<<", "<<char_5<<". "<<material[4]
		<<", "<<char_6<<". "<<material[5]<<", Q. Quit.\n\n";
		cin>>choice;
		choice = toupper(choice);
	
		double feet;	
		if (choice==char_1||choice==char_2||choice==char_3||choice==char_4||choice==char_5 ||choice==char_6)
		{
			cout<<"enter the number of feet your sound will move.\n";
			cin>>feet;
			if (feet<1)
			{
				cout<<"invalid input. please enter a positive value.\n";
				cin>>feet;
			}
		}
		//initialize sound_time variable
		//sound_time var will be used to store the time it takes sound to travel the distance	double sound_time;		
		double sound_time;
		while(choice==char_1||choice==char_2||choice==char_3||choice==char_4||choice==char_5 ||choice==char_6)
		{
			if (choice == char_1)
			{
				cout<<"you entered "<<material[0]<<endl; sound_time=feet/speed[0];
				break;
			}
			else if (choice == char_2)
			{
				cout<<"you entered "<<material[1]<<endl; sound_time=feet/speed[1];
				break;
			}
			else if (choice == char_3)
			{
				cout<<"you entered "<<material[2]<<endl; sound_time=feet/speed[2];
				break;
			}
			else if (choice == char_4)
			{
				cout<<"you entered "<<material[3]<<endl; sound_time=feet/speed[3];
				break;
			}
			else if (choice == char_5)
			{
				cout<<"you entered "<<material[4]<<endl; sound_time=feet/speed[4];
				break;
			}
			else if (choice == char_6)
			{
				cout<<"you entered "<<material[5]<<endl; sound_time=feet/speed[5];
				break;
			}
			else if (choice == 'Q')
			{
				cout<<"goodbye!\n";
				break;
			}
			else
				cout<<"invalid input.\n";			 	
		}
		
		//display the calculation
		//if clause prevents from printing when 'q' is selected
		if (choice==char_1||choice==char_2||choice==char_3||choice==char_4||choice==char_5 ||choice==char_6)
		cout<<"it will take sound "<<fixed<<showpoint<<setprecision(4)<<sound_time
		<<" seconds to move "<<fixed<<setprecision(2)<<feet<<" feet.\n";
	}

	return 0; 
}

/*hello! this program will help you calculate the time it takes sound to travel
through different materials. enter a letter to continue. if you would like to quit enter Q.
y
open of TT13_L4_Box_In.txt was successful.
7 materials were listed in this file.
open of TT13_L4_Box_In.txt was successful.

please enter a material: A. Air, W. Water, S. Steel, C. Copper, N. Nylon, I. Iron, Q. Quit.

a
enter the number of feet your sound will move.
800
you entered Air
it will take sound 0.7273 seconds to move 800.00 feet.

please enter a material: A. Air, W. Water, S. Steel, C. Copper, N. Nylon, I. Iron, Q. Quit.

w
enter the number of feet your sound will move.
-1
invalid input. please enter a positive value.
1000
you entered Water
it will take sound 0.2041 seconds to move 1000.00 feet.

please enter a material: A. Air, W. Water, S. Steel, C. Copper, N. Nylon, I. Iron, Q. Quit.

y

please enter a material: A. Air, W. Water, S. Steel, C. Copper, N. Nylon, I. Iron, Q. Quit.

q

--------------------------------
Process exited after 43.06 seconds with return value 0
Press any key to continue . . .*/
