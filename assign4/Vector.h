/* Copyright (c) 1996 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Vector.h
   PURPOSE
     Generic geometric vector
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Aug 27, 1996: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>

#ifndef _VECTOR_H
#define _VECTOR_H

// scalar multiplication
class Vector;
Vector operator* (double scale, Vector v); // M *V


std::ostream &operator<<(std::ostream &s, const Vector &V);


class Vector {

public:

    // default constrcutor
    Vector();

    // construct a vector of the give dimension
    Vector(int dimension);

    // constructor for easier initialization
    Vector(int size, const double elements[]);

    // copy constructor
    Vector(const Vector &source);

    // destructor
    ~Vector();

    // get the dimension of the vector
    int getDimension() const;

    /**
     * set the dimension of the vector
     * vector is trucated if the new dimension is shorter than the current one
     * vector is copied over if the new dimension is longer
     */
    void setDimension(int dimension);

    double length();
    double* getElements() const;

    /* operator overloading */
	 
    

    bool operator==(Vector V); // V1==V2
    bool operator!=(Vector V); // V1!=V2

    Vector &operator=(const Vector &V); //V1=V2
    
    Vector operator+(Vector V); // V1+V2
    Vector& operator+=(Vector V); // V1+=V2

    Vector operator-(Vector V); // V1-V2
    Vector& operator-=(Vector V); // V1-=V2

    // negation
    Vector operator- (); // -V1
    Vector operator*(double mult); // V *M
    Vector& operator*=(double mult);    // V*=M
    
    // Vec[index]
    double operator[](int index);

    


private:

    // initialization routine for allocating appropriate memory
    void initialize(int size);
    // current allocated number of elements >= fDimension
    int allocSize;
    // dimension of the vector
    int fDimension;
    // array of double for storing vector elements
    double *fElements;

};

#endif
