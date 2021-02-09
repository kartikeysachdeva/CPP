#include "ShapeList.h"
//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

// sets head to nullptr
ShapeList :: ShapeList() {
	head = NULL;
}

// deletes all list nodes starting with head plus associated Shapes
ShapeList :: ~ShapeList() {
	while (head) {
		ShapeNode* current = head->getNext();
		delete head;
		head = current;
	}
	head = NULL;
}
                                    
// returns the head pointer
ShapeNode* ShapeList :: getHead() const {
	return head;
}

// sets the head pointer to ptr
void ShapeList :: setHead(ShapeNode* ptr) {
	head = ptr;
}

// finds a shape node with the specified shape name
// returns a pointer to the node if found, otherwise
// returns nullptr if the node is not found
ShapeNode* ShapeList :: find(string name) const { 
	ShapeNode* current = head;
	while(current) {
		if (current->getShape()->getName() == name)
			return current;
		current = current->getNext();	
	}
	
	return NULL;
}

// inserts the node pointed to by s at the end
// of the list; s should never be nullptr
void ShapeList :: insert(ShapeNode* s) {
	if (s == NULL)
		return;
			
	if (head == NULL) {
		head = s;
		return;
	}
	
	ShapeNode* current = head;
	while(current->getNext()) {
		current = current->getNext();
	}
	current->setNext(s);
}

// removes the node with the shape called name
// returns a pointer to the removed node or
// nullptr is a node with name does not exist
ShapeNode* ShapeList :: remove(string name) {
	if (head == NULL)
		return NULL;
		
	ShapeNode* current = head;
	ShapeNode* prev = head;
	// handle the case of first node deletion
	if (head->getShape()->getName() == name) {
		head = (head->getNext());
		prev->setNext(NULL);
		return prev;
	}
	
	while(current) {
		if (current->getShape()->getName() == name) {
			prev->setNext(current->getNext());
			current->setNext(NULL);
			return current;
		}
		prev = current;
		current = current->getNext();
	}
	
	return NULL;
}

// prints the list
void ShapeList :: print() const {
	ShapeNode* current = head;
	while(current) {
		current->print();
		current = current->getNext();
	}
}

