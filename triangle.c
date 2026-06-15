//
//  triangle.c
//  TriangleStructProcessor
//
//  Created by Nesha Escoffery Markland on 4/26/26.
//

#include <stdio.h>
#include <math.h>
#include "triangle.h"

int isValidTriangle(Triangle t) {
   return (t.side1 > 0 && t.side2 > 0 && t.side3 > 0 &&
           t.side1 + t.side2 > t.side3 &&
           t.side1 + t.side3 > t.side2 &&
           t.side2 + t.side3 > t.side1);
}

double calculatePerimeter(Triangle t) {
   return t.side1 + t.side2 + t.side3;
}

double calculateArea(Triangle t) {
   double s = t.perimeter / 2.0;
   return sqrt(s * (s - t.side1) * (s - t.side2) * (s - t.side3));
}
