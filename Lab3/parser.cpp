//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool checkStream(stringstream &lineStream, bool isLastArgument, bool isNewCommand) {
	
	static bool invalidArgument = false;
	if (isNewCommand)
		invalidArgument = false;
	 
	if (invalidArgument)
		return false;

		 
	if (lineStream.fail()) {     // check for any failure in the input
		if (lineStream.eof()) {  // check if enough arguments are passed
			cout << "Error: too few arguments\n";
			invalidArgument = true;
			return false;
		}
		else {
			cout << "Error: invalid argument\n"; // input is invalid
			invalidArgument = true;
			return false;
		}
	}

	if (isLastArgument && lineStream.peek() != EOF) { 
			cout << "Error: too many arguments\n";
			invalidArgument = true;
			return false;
	}
	
	invalidArgument = false;
	return true;
}

bool isShapeTypeValid(string type) {
	for (int ii = 0; ii < NUM_TYPES; ++ii) {
		if (type == shapeTypesList[ii]) {
			return true;
		}
	}
	
	cout << "Error: invalid shape type\n";
	return false;
}

bool isShapeNameValid(string name) {
		
	for (int ii = 0; ii < NUM_KEYWORDS; ++ii) {
		if (name == keyWordsList[ii]) {
			cout << "Error: invalid shape name\n";
			return false;
		}
	}
	
	for (int ii = 0; ii < NUM_TYPES; ++ii) {
		if (name == shapeTypesList[ii]) {
			cout << "Error: invalid shape name\n";
			return false;
		}
	}
	
	return true;
}

bool shapeExists(string name) {
	for (int ii = 0; ii < shapeCount; ++ii) {
		if (shapesArray[ii] && shapesArray[ii]->getName() == name) {
			cout << "Error: shape " << name << " exists\n";
			return true;
		}
	}
	
	return false;
}

int findShape(string name) {
	for (int ii = 0; ii < shapeCount; ++ii) {
		if (shapesArray[ii] && shapesArray[ii]->getName() == name) {
			return ii;
		}
	}
	
	return -1;
}

bool invalidValue(int xloc, int yloc, int xsize, int ysize, string shape) {
	int invalid = (xloc < 0 || yloc < 0 || xsize < 0 || ysize < 0);
	invalid = invalid || (shape == "circle" && (xsize != ysize));
	if (invalid)
		cout << "Error: invalid value\n";
		
	return invalid;
}


int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        // command: maxShapes value
		if (command == "maxShapes") {
        	int numShapes=0;
        	lineStream >> numShapes;
        	if (checkStream(lineStream, true, true)) {
        	//if (checkStream(lineStream, true, false)) {
        	/*if (lineStream.fail()) {     // check if value is passed as an integer
        		if (lineStream.eof()) {  // check if end of input is reached
        			cout << "Error: too few arguments\n";
				}
				else {
					cout << "Error: invalid argument\n"; // input is invalid
				}
			}
			else {
				if (lineStream.peek() != EOF) {   // check with enter key 
					cout << "Error: too many arguments\n";
				}
				else { // de-allocate memory if already exists */
        			if (shapesArray != NULL) {
        				for (int ii = 0; ii < shapeCount; ++ii) { 
							delete shapesArray[ii];
							shapesArray[ii] = 0;
						}
						delete []shapesArray;
					}	
					// allocate memory for value number of Shape object pointers
					if (numShapes < 0) {
						cout << "Error: invalid value\n";
					}
					else {
						max_shapes = numShapes;
						shapesArray = new Shape*[max_shapes];
        				for (int ii = 0; ii < max_shapes; ++ii) {
        					shapesArray[ii] = 0; // set the pointer to null
						}
						cout << "New database: max shapes is " << numShapes << "\n";
					}
				}
			//}
		}
		else if (command == "create") { // create name type loc loc size size
			string name, type;
			int    locx=0, locy=0, sizex=0, sizey=0;
			lineStream >> name;
			if (checkStream(lineStream, false, true)) {
				// check if the name is invalid
				if (isShapeNameValid(name)) {
					lineStream >> type;
					if (checkStream(lineStream, false, false)) {
						if (isShapeTypeValid(type)) {
							bool valid = true;
							lineStream >> locx;
                                                                                                                                if((checkStream(lineStream, false, false)))
                                                                                                                                    lineStream >> locy; 
                                                                                                                                else
                                                                                                                                    valid = false;
                                                                                                            if((valid && invalidValue(locx, locy, 0, 0, type)))
                                                                                                                              valid = false;
                                                                                                                              else
                                                                                                                              valid = true;
                                                                                                            if(valid && checkStream(lineStream, false, false)) 
                                                                                                                                 lineStream >> sizex ;
                                                                                                                                 else
                                                                                                                                 valid = false; 
						if (valid && checkStream(lineStream, false, false)) 
                                                                                                                                lineStream >> sizey;
                                                                                                                                else
                                                                                                                                valid = false;
						if (valid && !invalidValue(locx, locy, sizex, sizey, type)) {
								if (checkStream(lineStream, false, false)) {
									if (shapeCount == max_shapes)
											cout << "Error: shape array is full\n";
									else if (checkStream(lineStream, true, false)) {
										//if (shapeCount == max_shapes)
										//	cout << "Error: shape array is full\n";
										//else {
										 	if (!shapeExists(name)) {
												shapesArray[shapeCount] = new Shape(name, type, locx, sizex, locy, sizey);  
												++shapeCount;
												cout << "Created " << name << ": " << type;
												cout << " " << locx << " " << locy << " " << sizex << " " << sizey << "\n";
											}
										//}
									}
								}
							}
						}
					}
				}
			}
		}
        else if (command == "move") { // move name loc loc
			string name;
			int    locx=0, locy=0;
			lineStream >> name;
			if (checkStream(lineStream, false, true)) {
				// check if the name is invalid
				if (isShapeNameValid(name)) {
					int index = findShape(name);
					if (index == -1) {
						cout << "Error: shape " << name << " not found\n";
					}
					else {
						lineStream >> locx;
						if (checkStream(lineStream, false, false))
							lineStream >> locy;
						if (checkStream(lineStream, true, false)) {
							if (!invalidValue(locx, locy, 0, 0, "")) {
								shapesArray[index]->setXlocation(locx);
								shapesArray[index]->setYlocation(locy);
								cout << "Moved " << name << " to " << locx << " " << locy << "\n";
							}
						}
					}
				}
		    }
		}
		else if (command == "rotate") { // rotate name angle
			string name;
			int    angle=0;
			lineStream >> name;
			if (checkStream(lineStream, false, true)) {
				// check if the name is invalid
				if (isShapeNameValid(name)) {
					int index = findShape(name);
					if (index == -1) {
						cout << "Error: shape " << name << " not found\n";
					}
					else {
						lineStream >> angle;
						if(lineStream.peek()=='.'){
								cout << "Error: invalid argument\n";
						}else{
							if (angle < 0 || angle > 360) {
								cout << "Error: invalid value\n";
							}
							else {
								int index = findShape(name);
								if (index != -1) {
									shapesArray[index]->setRotate(angle);
									cout << "Rotated " << name << " by " << angle << " degrees\n";
								}
							}
							
						}
					}
				}
			}
		}
		else if (command == "draw") { // draw name/all
			string name;
			int index = 0, begin = 0, end = 0;
			bool allShapes = false;
			lineStream >> name;
			if (checkStream(lineStream, false, true)) {
				if (name != "all") {
					if (isShapeNameValid(name)) {
					//if (name != "all") {
						index = findShape(name);
						if (index == -1)
							cout << "Error: shape " << name << " not found\n";
						else if (checkStream(lineStream, true, false))
								begin = index, end = index + 1;
					}
				}
				else {
					begin = 0, end = shapeCount;
					allShapes = true;
					cout << "Drew all shapes\n";
				}
				for (int ii = begin; ii < end; ++ii) { 
					if (!allShapes)
						cout << "Drew ";
					if (shapesArray[ii] != NULL) {
						cout << shapesArray[ii]->getName() << ":";
						cout << " " << shapesArray[ii]->getType();
						cout << " " << shapesArray[ii]->getXlocation();
						cout << " " << shapesArray[ii]->getYlocation();
						cout << " " << shapesArray[ii]->getXsize();
						cout << " " << shapesArray[ii]->getYsize() << "\n";
					}
				}
			}
		}
		else if (command == "delete") {
			string name;
			int index = 0, begin = 0, end = 0;
			lineStream >> name;
			if (name != "all") {
				if (isShapeNameValid(name)) {
					if (checkStream(lineStream, false, true)) {
						int index = findShape(name);
						if (index == -1)
							cout << "Error: shape " << name << " not found\n";
						else if (checkStream(lineStream, true, false)) {
							delete shapesArray[index];
							shapesArray[index] = 0;
							cout << "Deleted shape " << name << "\n";
						}
					}
				}
			}
			else if (checkStream(lineStream, true, false)) {
				//if (checkStream(lineStream, true, false))
				cout << "Deleted: all shapes\n";
				for (int ii = 0; ii < shapeCount; ++ii) { 
					delete shapesArray[ii];
					shapesArray[ii] = 0;
				}
				delete []shapesArray;
				shapeCount = 0;
			}
		}
        else {
        	cout << "Error: invalid command\n"; 
    	}
        
        command = "";
        
		// Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

