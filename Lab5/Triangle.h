//
//  Triangle.h
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef Triangle_h
#define Triangle_h

// This class implements the triangle Shape objects.
// ECE244 Student: Write the definition of the class here.

class Triangle : Shape {
private:
    float x1, y1, x2, y2, x3, y3;   // The vertices of the triangle

public:
    // Constructor
    Triangle (string n, float x1, float y1, float x2, float y2, float x3, float y3);
    
    // Destructor
    virtual ~Triangle();
    
    // Accessor
    float getX1() const;       // Returns the x coordinate of vertex 1 of the triangle
    float getY1() const;       // Returns the y coordinate of vertex 1 of the triangle
    float getX2() const;       // Returns the x coordinate of vertex 2 of the triangle
    float getY2() const;       // Returns the y coordinate of vertex 2 of the triangle
	float getX3() const;       // Returns the x coordinate of vertex 3 of the triangle
    float getY3() const;       // Returns the y coordinate of vertex 3 of the triangle
	    
	// Mutator
    void setX1(float in);       // sets the x coordinate of vertex 1 of the triangle
    void setY1(float in);       // sets the y coordinate of vertex 1 of the triangle
    void setX2(float in);       // sets the x coordinate of vertex 2 of the triangle
    void setY2(float in);       // sets the y coordinate of vertex 2 of the triangle
	void setX3(float in);       // sets the x coordinate of vertex 3 of the triangle
    void setY3(float in);       // sets the y coordinate of vertex 3 of the triangle
	    
	// Utility methods
    virtual void draw() const;     // Draws the triangle; for the assignment it
                                   // prints the information of the triangle
    
    virtual float computeArea() const;   // Computes the area of the triangle

	virtual Shape* clone() const;  // Clones the object
};

#endif /* Triangle_h */

