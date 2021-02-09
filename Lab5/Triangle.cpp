//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle :: Triangle (string n, float xx1, float yy1, float xx2, float yy2, float xx3, float yy3) : Shape(n, (xx1+xx2+xx3)/3, (yy1+yy2+yy3)/3) {
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
	x3 = xx3;
	y3 = yy3;
}

// Destructor
Triangle :: ~Triangle() {
	
}
    
// Accessor
float Triangle :: getX1() const {
	return x1;
}
float Triangle :: getY1() const {
	return y1;
}

float Triangle :: getX2() const {
	return x2;
}

float Triangle :: getY2() const {
	return y2;
}

float Triangle :: getX3() const {
	return x3;
}

float Triangle :: getY3() const {
	return y3;
}
    
// Mutator
void Triangle :: setX1(float in) {
	x1 = in;
}

void Triangle :: setY1(float in) {
	y1 = in;
}

void Triangle :: setX2(float in) {
	x2 = in;
}

void Triangle :: setY2(float in) {
	y2 = in;	
}

void Triangle :: setX3(float in) {
	x3 = in;	
}

void Triangle :: setY3(float in) {
	y3 = in;	
}
    
// Utility methods
void Triangle :: draw() const {
	// Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
     << x_centre << " " << y_centre
     << " " << x1 << " " << y1 << " "
	 << " " << x2 << " " << y2 << " "
	 << " " << x3 << " " << y3 << " " << computeArea()
     << endl;
}

float Triangle :: computeArea() const {
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2);
}

Shape* Triangle :: clone() const {
	return (new Triangle(*this));
}

