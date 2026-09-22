//yasyour
// library included
#include <iostream>
#include "theheaderfile.h"
#include <string>
#include <cctype>
#include <fstream>
#include <cmath>
using namespace std;
// function prototypes
bool markLine(int** arr, int i, int j, int newX, int newY, int xt, int yt, int width, int length);
bool simulateLaser(int** arr, int width, int length, int choice, int maxbounces, int i, int j, int angle, int xt, int yt, int& bounces, int& startX, int& startY);
void WriteOutPut(int** arr, int width, int length, string edge, int maxbounces, int xt, int yt, bool hit, int bounce, int startX, int startY, int angle, int bounces, int choice, int i, int j);

// main function
int main() {
	 

	
        // variable declaration
	    int length, width, maxbounces, bounce = 0, bounces = 0, angle, choice = 0, i, j, xt, yt, newX, newY, startX = 0, startY = 0, menuchoice, x, y;
		bool allthedigits, hit=false; 
		double dx, dy;
		string edge, direction1, direction2;
		// program introduction and user inputs
		cout << endl;
		cout << "                          Laser Reflection Pathfinding in Photonics" << endl;
		cout << endl;
		for (int a = 0;a < 92; a++)  
		{
			cout << "=";
		}
		cout << endl;
		cout << endl;
		cout << "                                           Welcome!" << endl;
		cout << endl;
		cout << "Enter '1' if you want to proceed with the program" << endl;
		cout << "Enter '2' if you want to exit the program" << endl;
		cout << "Specify your choice: ";

		while (true) // menu choice validation loop
		{
			string input; // to store user input
			cin >> input;  // get user input
			allthedigits = true; // assume all characters are digits
			for (char c : input) // check each character
			{
				if (!isdigit(c))// if character is not a digit
				{
					allthedigits = false; // set flag to false
					break;// exit loop
				}

			}
			if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
			{
				menuchoice = stoi(input); // convert input to integer

				if (menuchoice == 1) // if user wants to proceed
					break; // exit loop
				if (menuchoice == 2) // if user wants to exit
				{
					cout << "You have exited the program"; // exit message
					return(0);// terminate program
				}
			}
			// if input is invalid, prompt user again
			cout << endl;
			cout << "Invalide choice" << endl;
			cout << "Enter '1' if you want to proceed with the program" << endl;
			cout << "Enter '2' if you want to exit the program" << endl;
			cout << "Specify your choice: ";
			
		}
		 
		// get grid dimensions from user
		cout << endl;
		cout << "Enter grid dimensions, note that length and width should mesure at least '7':" << endl;

		while (true) // width input validation loop
		{
			string input; // to store user input
			cout << "Width: "; // prompt user for width
			cin >> input; // get user input
			allthedigits = true; //	assume all characters are digits
			for (char c : input) // check each character
			{
				if (!isdigit(c)) // if character is not a digit
				{
					allthedigits = false; // set flag to false
					break; // exit loop
				}
			}

			if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
			{
				width = stoi(input); // convert input to integer
				if (width >= 7) // if width is valid
					break; // exit loop
			}
			// if input is invalid, prompt user again
			cout << endl;
			cout << "Error, please enter a valid positive integer greater than or equal to '7' for grid width" << endl;
		}

		while (true) // length input validation loop
		{
			string input; // to store user input
			cout << "Length: "; //	prompt user for length
			cin >> input; // get user input
			allthedigits = true; // assume all characters are digits
			for (char c : input) // check each character			
			{

				if (!isdigit(c)) // if character is not a digit
				{
					allthedigits = false; // set flag to false
					break; // exit loop
				}
			}

			if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
			{
				length = stoi(input); // convert input to integer	
				if (length >= 7) // if length is valid
					break; // exit loop
			}
			// if input is invalid, prompt user again
			cout << endl;
			cout << "Error, please enter a valid positive integer greater than or equal to '7' for grid length" << endl;
		}
		cout << endl;

		// get launching edge from user
		cout << "Specify your prefered launching edge by picking one of the following choices : " << endl;
		cout << "Enter '1' for Top Edge " << endl;
		cout << "Enter '2' for Bottom Edge " << endl;
		cout << "Enter '3' for Right Edge " << endl;
		cout << "Enter '4' for Left Edge " << endl;
		cout << "Specify your choice: ";

		while (true) // launching edge input validation loop
		{
			string input; // to store user input

			cin >> input; // get user input
			allthedigits = true; // assume all characters are digits
			for (char c : input) // check each character
			{
				if (!isdigit(c)) // if character is not a digit
				{
					allthedigits = false; // set flag to false
					break; // exit loop
				}

			}
			if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
				choice = stoi(input); // convert input to integer
			if (choice >= 1 && choice <= 4) // if choice is valid
			{
				if (choice == 1) // Top edge
					edge = "Top Edge"; // set edge string
				else if (choice == 2) // Bottom edge
					edge = "Bottom Edge"; // set edge string
				else if (choice == 3) // Right edge
					edge = "Right Edge"; // set edge string
				else if (choice == 4) // Left edge
					edge = "Left Edge"; // set edge string
				break;
			}
			// if input is invalid, prompt user again
			cout << endl;
			cout << "Error, please specify your preferred launching edge by choosing one the following : " << endl;
			cout << "Enter '1' for Top Edge " << endl;
			cout << "Enter '2' for Bottom Edge " << endl;
			cout << "Enter '3' for Right Edge " << endl;
			cout << "Enter '4' for Left Edge " << endl;
			cout << "Specify your choice: ";
		}
		cout << endl;

		// set direction strings based on launching edge choice to guide user for angle input
		switch (choice)
		{
		case 1: // case for Top edge
		{   
			direction1 = "Right"; //
			direction2 = "Left";
			break;
		}
		case 2: // case for Bottom edge
		{
			direction1 = "Right";
			direction2 = "Left";
			break;
		}
		case 3: // case for Right edge
		{
			direction1 = "Down";
			direction2 = "Up";
			break;
		}
		case 4: // case for Left edge
		{
			direction1 = "Down";
			direction2 = "Up";
			break;
		}


		}
		// prompt user for launch angle
		cout << "Enter your launch angle, note that 0 degrees is a straight beam perpendicular to your chosen edge:" << endl;
		cout << "If you wish the laser beam to go " << direction1 << ", your angle should be between 0 and 90 degrees " << endl;
		cout << "If you wish the laser beam to go " << direction2 << ", your angle should be between 0 and - 90 degrees " << endl;
		cout << "Launch Angle: ";

		while (true) // launch angle input validation loop
		{
			string input; // to store user input

			cin >> input; // get user input
			allthedigits = true; // assume all characters are digits

			for (int i = 0; i < input.length(); i++) // check each character
			{
				char c = input[i]; // get current character
				if (!isdigit(c)) // if character is not a digit
				{
					if (c == '-' && i == 0 && input.length() > 1) // check for negative sign at start
						continue; // valid negative sign
					else // invalid character
					{
						allthedigits = false; // set flag to false
						break;// exit loop
					}
				}
			}


			if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
			{
				angle = stoi(input); // convert input to integer
				if (angle > 0 && angle < 90) // valid angle for direction
					break; // exit loop
				else if 
					(angle > -90 && angle < 0) // valid angle for direction
					break; // exit loop
				else if (angle == 0 || angle == 90 || angle == -90) // valid angle for direction
					break; // exit loop
			}
			// if input is invalid, prompt user again
			cout << endl;
			cout << "Error, please enter a valid integer for launch angle" << endl;
			cout << "If you wish the laser beam to go " << direction1 << ", your angle should be between 0 and 90 degrees " << endl;
			cout << "If you wish the laser beam to go " << direction2 << ", your angle should be between 0 and - 90 degrees " << endl;
			cout << "Launch Angle: ";
		}
	

	cout << endl;
	// prompt user for maximum number of bounces
	cout << "Enter your maximum number of bounces: ";

	while (true) // maximum bounces input validation loop
	{
		string input; // to store user input

		cin >> input; // get user input
		allthedigits = true; // assume all characters are digits
		for (char c : input) // check each character
		{
			if (!isdigit(c)) // if character is not a digit
			{
				allthedigits = false; // set flag to false
				break; // exit loop
			}
		}

		if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
		{
			maxbounces = stoi(input); // convert input to integer
			if (maxbounces >= 0) // if maximum bounces is valid
				break; // exit loop
		}
		// if input is invalid, prompt user again
		cout << endl;
		cout << "Error, please enter a valid non-negative integer for maximum number of bounces: " << endl;
	}

	cout << endl;

	// prompt user for laser target coordinates
	cout << "Provide your laser target coordinates, note that your tagret should at least be:" << endl;
	cout << "Firstly: 3 cells away from the vertical edge" << endl;
	cout << "Secondly: 3 cells away from the horizontal edge" << endl;
	cout << "Target X coordinate: "; // prompt user for target X coordinate

	while (true) // target X coordinate input validation loop
	{
		string input;// to store user input
		cin >> input; // get user input
		allthedigits = true; // assume all characters are digits
		for (char c : input) // check each character
		{
			if (!isdigit(c)) // if character is not a digit
			{
				allthedigits = false;// set flag to false
				break;// exit loop
			}
		}

		if (allthedigits && !input.empty())// if all characters are digits and input is not empty
		{
			xt = stoi(input); // convert input to integer
			if (xt > 3 && xt < width - 3) // if target X coordinate is valid
				break; // exit loop
		}
		// if input is invalid, prompt user again
		cout << endl;
		cout << "Error, please enter a non-negative integer between '3' and " << "'" << width - 3 << "'" << " for target X coordinates" << endl;
		cout << "Target X coordinate: ";
	}
	// prompt user for target Y coordinate
	cout << "Tagret Y coordinate: ";

	while (true) // target Y coordinate input validation loop
	{
		string input; // to store user input
		cin >> input; // get user input
		allthedigits = true; // assume all characters are digits
		for (char c : input) // check each character
		{
			if (!isdigit(c)) // if character is not a digit
			{
				allthedigits = false; // set flag to false
				break; // exit loop
			}
		}

		if (allthedigits && !input.empty()) // if all characters are digits and input is not empty
		{
			yt = stoi(input);// convert input to integer
			if (yt > 3 && yt < length - 3) // if target Y coordinate is valid
				break;// exit loop
		}
		// if input is invalid, prompt user again
		cout << endl;
		cout << "Error, please enter a non-negative integer between '3' and " << "'" << length - 3 << "'" << " for target Y coordinates" << endl;
		cout << "Tagret Y coordinate: ";
	}
	cout << endl;


	// dynamic 2D array creation and initialization
	int** arr;
	arr = new int* [length]; // create array of pointers for rows
	for (i = 0; i < length; i++)  // create each row
	{
		arr[i] = new int[width]; // create columns for each row
	}
	for (i = 0; i < length; i++)  // initialize array elements to 0
	{
		for (j = 0; j < width; j++)  // for each column
		{
			arr[i][j] = 0; // set element to 0
		}
	}
	
	bounces = 0;
	WriteOutPut(arr, width, length, edge, maxbounces, xt, yt, hit, bounce, startX, startY, angle, bounces, choice, i, j); // call function to write output to file and display results
	
	for (i = 0;i < length;i++) // deallocate dynamic 2D array
	{
		delete[]arr[i]; // delete each row
	}
	delete[] arr; // delete array of pointers
	arr = NULL; // set pointer to NULL

	// program ending 
	cout << endl;
	for (int a = 0;a < 92; a++)
	{
		cout << "="; // print separator line
	}
	cout << endl;

	
	return(0); // terminate program
}
	 
// function definitions
void WriteOutPut(int** arr, int width, int length, string edge, int maxbounces, int xt, int yt, bool hit, int bounce, int startX, int startY, int angle, int bounces, int choice, int i, int j)  // function to write output to file and display results

	
{
	hit = false; // reset hit flag

	// Temporary array for tracing
	int** tempArr = new int* [length]; // create array of pointers for rows
	for (int y = 0; y < length; y++) // create each row
	{
		tempArr[y] = new int[width]; // create columns for each row
		for (int x = 0; x < width; x++) // initialize array elements to 0
			tempArr[y][x] = 0;  // clear temp array
	}

	// Loop through edge positions depending on choice
	if (choice == 1 || choice == 2) // top/bottom
	{
		int j = (choice == 1) ? 0 : length - 1; // set row based on edge choice
		for (int i = 0; i < width; i++) // loop through columns
		{
			// clear temp array
			for (int y = 0; y < length; y++)// for each row
				for (int x = 0; x < width; x++)// for each column
					tempArr[y][x] = 0;

			if (simulateLaser(tempArr, width, length, choice, maxbounces, i, j, angle, xt, yt, bounces, startX, startY)) // simulate laser
			{
				hit = true;
				break; // stop at first success
			}
			
		}
	}
	else // left/right
	{
		int i = (choice == 4) ? 0 : width - 1; // set column based on edge choice
		for (int j = 0; j < length; j++) // loop through rows
		{
			// clear temp array
			for (int y = 0; y < length; y++) // for each row
				for (int x = 0; x < width; x++) // for each column
					tempArr[y][x] = 0;// clear temp array

			if (simulateLaser(tempArr, width, length, choice, maxbounces, i, j, angle, xt, yt, bounces, startX, startY)) // simulate laser
			{
				hit = true; // set hit flag
				break; // stop at first success
			}
			
		}
	}
	
	
	// Copy temp array to main array (last attempt or successful attempt)
	for (int y = 0; y < length; y++) // for each row
		for (int x = 0; x < width; x++) // for each column
			arr[y][x] = tempArr[y][x]; // copy element

	// Free temp array
	for (int y = 0; y < length; y++) // for each row
		delete[] tempArr[y]; // delete each row
	delete[] tempArr; // delete array of pointers

	// Output
	ofstream outputf("UserInputData.txt"); // open output file
	if (outputf.fail()) // check if file opened successfully
	{
		cout << "Error opening file." << endl; // error message
		return;
	}
	// write user inputs to output file
	outputf << "Width: " << width << endl;
	outputf << "Length: " << length << endl;
	outputf << "Launching Edge: " << edge << endl;
	outputf << "Launching Angle: " << angle << endl;
	outputf << "Maximum Bounces: " << maxbounces << endl;
	outputf << "Laser Target X Coordinate: " << xt << endl;
	outputf << "Laser Target Y Coordinate: " << yt << endl << endl;

	if (hit)// if laser hits target
	{	// display success message
		cout << "The laser has successfully hit the target" << endl;
		cout << "Number of bounces: " << bounces << endl;
		cout << "Launching position: (" << startX << "," << startY << ")" << endl;
		// write success message to output file
		outputf << "The laser has successfully hit the target" << endl;
		outputf << "Number of bounces: " << bounces << endl;
		outputf << "Launching position: (" << startX << "," << startY << ")" << endl;
	}
	else
	{   // display failure message
		cout << "The laser has failed to hit the target within the maximum number of bounces." << endl;
		outputf << "The laser has failed to hit the target within the maximum number of bounces." << endl;// write failure message to output file
	}

	outputf << endl << "     Laser Path:" << endl << endl;
	cout << endl << "     Laser Path:" << endl << endl;

	for (int y = 0; y < length; y++) // for each row
	{
		cout << "     ";
		outputf << "     ";
		for (int x = 0; x < width; x++) // for each column
		{
			cout << arr[y][x] << " "; // display array element
			outputf << arr[y][x] << " "; // write array element to file
		}
		cout << endl;
		outputf << endl;
	}

	outputf.close(); // close output file
	cout << endl << "Note: 'UserInputData.txt' containing results has been created." << endl; // final message to user
}

bool simulateLaser(int** arr, int width, int length, int choice, int maxbounces, int i, int j, int angle, int xt, int yt, int& bounces, int& startX, int& startY) // function to simulate laser path
{   // variable declaration
			double   dx = 0, dy = 0, rad;
			double pi = 3.141592653589793238;
			rad = angle * pi / 180.0;
			
			
			startX = i; // store starting x coordinate
			startY = j;	// store starting y coordinate

			switch (choice) // set initial direction based on launching edge choice
			{
			case 1: // Top edge
				dx = sin(rad); // calculate x direction
				dy = cos(rad); // calculate y direction
				break;
			case 2: // Bottom edge
				dx = sin(rad);  // calculate x direction
				dy = -cos(rad);  // calculate y direction
				break;
			case 3: // Right edge
				dx = -cos(rad);  // calculate x direction
				dy = sin(rad);  // calculate y direction
				break;
			case 4: // Left edge
				dx = cos(rad);  // calculate x direction
				dy = sin(rad);  // calculate y direction
				break;
			default: // Invalid choice
				return false; 

			}
			
	
			for (int bounce = 0; bounce <= maxbounces; bounce++) // loop for each bounce
			{
				double tX, tY; // variables to store time to collision
				
				// distance to vertical wall
				if (dx > 0)  // moving right
					tX = (width - 1 - i) / dx; // time to right wall
				else if (dx < 0) // moving left
					tX = -i / dx; // time to left wall
				else // no horizontal movement
					tX = 1e9; // set to large value

				// distance to horizontal wall
				if (dy > 0) 
					tY = (length - 1 - j) / dy; // moving down
				else if (dy < 0) 
					tY = -j / dy; // moving up
				else 
					tY = 1e9; // no vertical movement

				double tMin = (tX < tY)?tX : tY; // minimum time to collision

				int newX = i + round(dx * tMin); // calculate new x coordinate
				int newY = j + round(dy * tMin); //	calculate new y coordinate

				// keep inside bounds
				if (newX < 0) 
					newX = 0; // left wall
				if (newX >= width)
					newX = width - 1; // right wall
				if (newY < 0)
					newY = 0; // top wall
				if (newY >= length)
					newY = length - 1;// bottom wall

				// draw line and check if target hit
				if (markLine(arr, i, j, newX, newY, xt, yt, width, length))
					return true;

				// reflect based on which wall was hit
				if (tX < tY) 
					dx = -dx;      // vertical wall
				else if (tY < tX) 
					dy = -dy; // horizontal wall
				else 
				{ 
					dx = -dx; 
				    dy = -dy; 
				} // corner

				
			
				// move to new starting point
				i = newX; // update x coordinate
				j = newY; // update y coordinate

				bounces = bounce; // update bounce count
				
			}
			return false; // target not hit within max bounces
}