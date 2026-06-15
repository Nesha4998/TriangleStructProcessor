//
//  triangle.h
//  TriangleStructProcessor
//
//  Created by Nesha Escoffery Markland on 4/26/26.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef struct {
   double side1;
   double side2;
   double side3;
   double perimeter;
   double area;
   int isValid;
} Triangle;

int isValidTriangle(Triangle t);
double calculatePerimeter(Triangle t);
double calculateArea(Triangle t);

#endif
