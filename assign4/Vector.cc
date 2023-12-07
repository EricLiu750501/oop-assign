#include "Vector.h"
#include <cmath>
#include <iostream>
using std::ostream;

Vector::Vector() {
    this->initialize(2);
}

Vector::Vector(int dimension) {
    this->initialize(dimension);
}

Vector::Vector(int size, const double elements[]) {
   this->initialize(size); 
    for (int i=0;i<size;i++) {
        fElements[i] = elements[i];
    }
}

Vector::Vector(const Vector &source) {
//    *this = source;
    if (this == &source) {
        return /**this;*/ ;
    }
    this->allocSize = source.allocSize;
    this->fDimension = source.fDimension;
    if (this->fElements != nullptr) {
        delete[] this->fElements;
        this->fElements = nullptr;
    }
    this->fElements = new double[source.getDimension()];

    for (int i=0;i<fDimension;i++) {
        fElements[i] = source.fElements[i];
    }
}


Vector::~Vector() {
    if (fElements != nullptr) {
        delete[] this->fElements;
        fElements = nullptr;
    }
}

void Vector::setDimension(int dimension) {
    if (dimension > fDimension) {
        double *Temp = new double[dimension];
        for (int i=0;i<fDimension;i++) {
            Temp[i] = fElements[i];
        }
        if (fElements != nullptr) {
            delete[] this->fElements;
            fElements = nullptr;
        }
        fElements = Temp;
        fDimension = dimension;

    }
    else if (dimension == fDimension) {
        return;
    }
    else {
        fDimension = dimension;
    }
}

int Vector::getDimension() const {    
   return fDimension; 
}

void Vector::initialize(int size) {
    fElements = new double[size];
    fDimension = size;
}

double Vector::length() {
    double sum = 0;
    for (int i=0;i<fDimension;i++) {
        sum += fElements[i] * fElements[i];
    }
    return std::sqrt(sum);

}

double *Vector::getElements() const {
    return fElements;
}


/*               OPERATOR OVERLOADING               */

std::ostream &operator<<(std::ostream &s, const Vector &V) {
    s << "(";
    for (int i=0;i< V.getDimension() ;i++) {
        s << V.getElements()[i];
        if (i != V.getDimension() - 1) {
            s << ", ";
        }
    }
    s << ")";
    return s;
}

bool Vector::operator==(Vector V) {
    if (this->getDimension() != V.getDimension()) {
        return false;
    }
    else {
        for (int i=0;i<V.getDimension();i++) {
            if (this->fElements[i] != V.fElements[i]) {
                return false;
            }
        }
        return true;
    }
}
bool Vector::operator!=(Vector V) {
    
   if (this->getDimension() != V.getDimension()) {
        return true;
    }
    else {
        for (int i=0;i<V.getDimension();i++) {
            if (this->fElements[i] != V.fElements[i]) {
                return true;
            }
        }
        return false;
    }

}

Vector &Vector::operator=(const Vector &V) {
    if (this == &V) {
        return *this;
    }
    this->allocSize = V.allocSize;
    this->fDimension = V.fDimension;
    if (this->fElements != nullptr) {
        delete[] this->fElements;
        this->fElements = nullptr;
    }
    this->fElements = new double[V.getDimension()];

    for (int i=0;i<fDimension;i++) {
        fElements[i] = V.fElements[i];
    }
    return *this;
}

Vector Vector::operator+(Vector V) {
    if (this->getDimension() != V.getDimension()) {
        std::cout << "\nERROR!!!\n";
    }
    else {
        Vector Temp(V.getDimension());
        for (int i=0;i<Temp.getDimension();i++) {
            Temp.fElements[i] = this->fElements[i] + V.fElements[i];
        }
        return Temp;
    }
}
Vector& Vector::operator+=(Vector V) { 
    if (this->getDimension() != V.getDimension()) {
        std::cout << "\nERROR!!!\n";
    }
    else {
        for (int i=0;i<V.getDimension();i++) {
            this->fElements[i] += V.fElements[i];
        }
        return *this;
    }
}

// negation
Vector Vector::operator-() {
    Vector Temp(*this);
    for (int i=0;i<Temp.getDimension();i++) {
        Temp.getElements()[i] *= (-1);
    }
    return Temp;
}

// V1 - V2
Vector Vector::operator-(Vector V) {
    Vector Temp;
    if (this->getDimension() != V.getDimension()) {
        std::cout << "\nERROR!!!\n";
    }
    else {
        Vector Temp(V.getDimension());
        for (int i=0;i<Temp.getDimension();i++) {
            Temp.fElements[i] = this->fElements[i] - V.fElements[i];
        }
        return Temp;
    }
}
Vector& Vector::operator-=(Vector V) {
    if (this->getDimension() != V.getDimension()) {
        std::cout << "\nERROR!!!\n";
    }
    else {
        for (int i=0;i<V.getDimension();i++) {
            this->fElements[i] -= V.fElements[i];
        }
        return *this;
    }
}

Vector Vector::operator*(double mult) {
    Vector Temp(*this);
    for (int i=0;i<this->getDimension();i++) {
        Temp.fElements[i] *= mult;
    }
    return Temp;
}
Vector operator*(double scale, Vector v) {
    Vector Temp(v);
    for (int i=0;i<v.getDimension();i++) {
        Temp.getElements()[i] *= scale;
    }
    return Temp;
}

Vector& Vector::operator*=(double mult) {
    //*this = this->operator*(mult);
    for (int i=0;i<this->getDimension();i++) {
        this->fElements[i] *= mult;
    }
    return *this;
}   

double Vector::operator[](int index) {
    return this->fElements[index];
}
