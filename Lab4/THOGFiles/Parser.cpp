//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool shapeNameExists(const string inShapeName);
bool shapeGroupExists(const string inGroupName);
bool isNameValid(const string inStr);
bool isShapeTypeValid(const string inStr);
void processShapeCommand(stringstream &lineStream);
void processGroupCommand(stringstream &lineStream);
void processMoveCommand(stringstream &lineStream);
void processDeleteCommand(stringstream &lineStream);

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the pool group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
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
      	if (command == "shape") {
      		processShapeCommand(lineStream);
		}
		else if (command == "draw") {
			gList->print();
		}
		else if (command == "group") {
			processGroupCommand(lineStream);
		}
		else if (command == "move") {
			processMoveCommand(lineStream);
		}
		else if (command == "delete") {
			processDeleteCommand(lineStream);
		}
		    
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

bool isNameValid(const string inStr) {
	for (int ii = 0; ii < NUM_KEYWORDS; ++ii) {
		if (keyWordsList[ii] == inStr) {
			cout << "error: invalid name\n"; 
			return false;
		}
	}
	
	for (int ii = 0; ii < NUM_TYPES; ++ii) {
		if (shapeTypesList[ii] == inStr) {
			cout << "error: invalid name\n";
			return false;
		}
	}
	
	return true;
}

bool shapeNameExists(const string inShapeName) {
	for (GroupNode* current = gList->getHead(); current; current = current->getNext()) {
		ShapeList* pCurrentShapeList = current->getShapeList();
		for (ShapeNode* pShapeNode = pCurrentShapeList->getHead(); pShapeNode; pShapeNode = pShapeNode->getNext()) {
			if (pShapeNode->getShape()->getName() == inShapeName) {
				cout << "error: name " << inShapeName << " exists\n";
				return true;
			}
		}
	}
	
	return false;
}

bool shapeGroupExists(const string inGroupName) {
	for (GroupNode* current = gList->getHead(); current; current = current->getNext()) {
		if (current->getName() == inGroupName) {
			cout << "error: name " << inGroupName << " exists\n";
			return true;
		}
	}
	
	return false;
}


void processShapeCommand(stringstream &lineStream) {
	string shapeName, shapeType;
	int xLoc, xSize, yLoc, ySize;
	lineStream >> shapeName >> shapeType >> xLoc >> yLoc >> xSize >> ySize;
	
	if(!isNameValid(shapeName))
		return;
	
	if (shapeNameExists(shapeName))
		return;

	Shape *newShapePtr = new Shape(shapeName, shapeType, xLoc, yLoc, xSize, ySize);
	ShapeNode *newShapeNode = new ShapeNode();
	newShapeNode->setShape(newShapePtr);
	gList->getHead()->getShapeList()->insert(newShapeNode);
	cout << shapeName << ": " << shapeType << " ";
	cout << xLoc << " " << yLoc << " " << xSize << " " << ySize << endl;
}

void processGroupCommand(stringstream &lineStream) {
	string groupName;
	lineStream >> groupName;
	
	if(!isNameValid(groupName))
		return;
	
	if (shapeGroupExists(groupName))
		return;
	
	// Create the group and add it to the group list
    GroupNode* group = new GroupNode(groupName);
    gList->insert(group);
	cout << groupName << ": group\n";	
}

void processMoveCommand(stringstream &lineStream) {
	string shapeName, groupName;
	lineStream >> shapeName >> groupName;
	
	if(!isNameValid(shapeName) || !isNameValid(groupName))
		return;
	/*
	if (!shapeNameExists(shapeName) || !shapeGroupExists(groupName))
		return;
	*/
	ShapeNode* pRemovedShapeNode = nullptr;
	// remove from the current group;
	GroupNode* current = gList->getHead();
	while(current) {
		ShapeList* pShapeList = current->getShapeList();
		ShapeNode* pShapeNode = pShapeList->find(shapeName);
		if (pShapeNode) {
			pRemovedShapeNode = pShapeList->remove(shapeName);
			break;
		}
		current = current->getNext();
	}
	
	if (!current) {
		cout << "error: " << shapeName << " not found\n";
		return; 
	}
	
	//if (!pRemovedShapeNode)
	//	return;
		
	// add to the group
	current = gList->getHead();
	while(current && current->getName() != groupName)
		current = current->getNext();
	
	if (current == nullptr) {
		cout << "error: " << groupName << " not found\n";
		return;
	}
		
	current->getShapeList()->insert(pRemovedShapeNode);
	cout << "moved " << shapeName << " to " << groupName << endl;
}

void processDeleteCommand(stringstream &lineStream) {
	string groupShapeName;
	lineStream >> groupShapeName;
	
	if(!isNameValid(groupShapeName))
		return;
	
	// check for shape name and delete if found
	GroupNode* pGNCurrent = gList->getHead();
	GroupNode* pGNPrev = pGNCurrent;
	while(pGNCurrent) {
		if (pGNCurrent->getShapeList()->find(groupShapeName) != nullptr) {
			pGNCurrent->getShapeList()->remove(groupShapeName);
			cout << groupShapeName << ": deleted\n";
			return;
		}
		pGNCurrent = pGNCurrent->getNext();
	}
		
	// check for group name and delete if found	
	pGNCurrent = gList->getHead();
	pGNPrev = pGNCurrent;
	while(pGNCurrent && pGNCurrent->getName() != groupShapeName) {
		pGNPrev = pGNCurrent;
		pGNCurrent = pGNCurrent->getNext();
	}
	
	if (!pGNCurrent) {
		cout << "error: shape " << groupShapeName << " not found\n";
		return;	
	}
	
	// move the list of shapes to pool
	gList->getHead()->getShapeList()->insert(pGNCurrent->getShapeList()->getHead());
	
	// delete the shape list
	pGNCurrent->getShapeList()->setHead(nullptr);
	pGNPrev->setNext(nullptr);
	cout << groupShapeName << ": deleted\n";
}
