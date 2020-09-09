// Peter Klutchko 2/4/18

#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
    private:
        double length;
        double width;
        double area;
        double perimeter;
    public:
    Polygon();
        void setWidth(double w);
        void setLength(double l);
        
        double getWidth() const 
            {return width;}
        double getLength() const
            {return length;}
        double getArea() const
            {return width * length;}
        double getPerimeter() const
            {return width + length;}
};
#endif