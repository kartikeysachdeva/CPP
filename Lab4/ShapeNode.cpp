#include "ShapeNode.h"
//
//  ShapeNode.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeNode class below

// sets myShape and next to nullptr
ShapeNode :: ShapeNode() {
	myShape = NULL;
	next = NULL;
}

// deletes the shape pointed to by myShape
ShapeNode :: ~ShapeNode() {
    if(myShape){
        delete myShape; 
        myShape=NULL; 
        }
}

// returns myShape
Shape* ShapeNode :: getShape() const {
	return myShape;
}

// sets myShape to ptr
void ShapeNode :: setShape(Shape* ptr) {
	myShape = ptr;
}

// returns next
ShapeNode* ShapeNode :: getNext() const {
	return next;
}

// sets next to ptr
void ShapeNode :: setNext(ShapeNode* ptr) {
	next = ptr;
}

// prints the ShapeNode
void ShapeNode :: print() const {
	myShape->draw();
}
