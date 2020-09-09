// Peter Klutchko 2/4/18

#include "polygon.h"
#include <iostream>
#include <iomanip>
using namespace std;

// default constructor
Polygon::Polygon() {
    width = 0.0;
    length = 0.0;
    area = length * width;
    perimeter = length + width;
}

// constructor for width
void Polygon::setWidth(double w) {
    do {
        width = w;
        
        if (width < 0.0) {
            cout << "A polygon cannot have a negative width" << endl;
            cout << "Width: ";
            cin >> w;
        }
    }
    while (width < 0.0);
}

// constructor for length
void Polygon::setLength(double l) {
    do {
        length = l;
        
        if (length < 0.0) {
            cout << "A polygon cannot have a negative length" << endl;
            cout << "Length: ";
            cin >> l;
        }
    }
    while (length < 0.0);
}

void polyInput(double, double, int, Polygon); // this outputs the information held by the class
void drawPoly(double, double); // this is called by polyInput to draw the shape

int main()
{
    Polygon poly1; //first instance of the Polygon object declared here, etc.
    Polygon poly2; 
    Polygon poly3;
    double l; //holds length
    double w; //holds width
    int polyNum = 1; //tells the polyInput function which polygon it's on
    
    // user will input length and width here for each polygon
    // validation happens inside setWidth & setLength
    cout << "Length of Polygon 1: ";
    cin >> l;
    cout << "With of Polygon 1: ";
    cin >> w;
    polyInput(l, w, polyNum, poly1);
    ++polyNum;
    
    cout << "Length of Polygon 2: ";
    cin >> l;
    cout << "With of Polygon 2: ";
    cin >> w;
    polyInput(l, w, polyNum, poly2);
    ++polyNum;
    
    cout << "Length of Polygon 3: ";
    cin >> l;
    cout << "With of Polygon 3: ";
    cin >> w;
    polyInput(l, w, polyNum, poly3);
    
    return 0;
}

void polyInput(double l, double w, int polyNum, Polygon passedPoly) 
{
    passedPoly.setLength(l); //passes length to the length constructor
    passedPoly.setWidth(w); //passes width to the width constructor
    
    cout << endl;
    
    // these segments output the length, width, area, and perimeter
    cout << "Length of Polygon " << polyNum << ": ";
    if (passedPoly.getLength() < 10)
        cout << setw(4);
    else if (passedPoly.getLength() >= 100 )
        cout << setw(6);
    else
        cout << setw(5);
    cout << passedPoly.getLength() << endl;
    
    cout << "Width of Polygon " << polyNum << ": ";
    if (passedPoly.getWidth() < 10)
        cout << setw(5); 
    else if (passedPoly.getWidth() >= 100)
        cout << setw(7);
    else
        cout << setw(6);
    cout << passedPoly. getWidth() << endl;
    
    cout << "Area of Polygon " << polyNum << ": ";
    if (passedPoly.getArea() < 10)
        cout << setw(6);
    else if (passedPoly.getArea() >= 100)
        cout << setw(8);
    else if (passedPoly.getArea() >= 1000)
        cout << setw(9);
    else
        cout << setw(7);
    cout << passedPoly.getArea() << endl;
    
    cout << "Perimeter of Polygon " << polyNum << ": " << passedPoly.getPerimeter() << endl;
    cout << endl;
    
    drawPoly(l, w);
    
    return;
    
}

void drawPoly(double l, double w)
{
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < w; ++j) {
            if (l > 2 && i > 0 && i < l - 1 && j > 0  && j < w - 1)
                cout << " ";
            else
                cout << "*";
            
            if (j == w - 1)
                cout << endl;
            
        }
    }
    
    cout << endl;
    
    return;
    
}