//
//  main.c
//  TriangleStructProcessor
//
//  Created by Nesha Escoffery Markland on 4/26/26.
//

#include <stdio.h>
#include "triangle.h"

int main(void) {
   FILE *inputFile;
   FILE *outputFile;

   Triangle t;

   int record = 1;
   int validCount = 0;
   int invalidCount = 0;

   inputFile = fopen("input.txt", "r");
   outputFile = fopen("output.csv", "w");

   if (inputFile == NULL || outputFile == NULL) {
       printf("Error opening file.\n");
       return 1;
   }

   fprintf(outputFile, "Triangle Results File\n");
   fprintf(outputFile, "Record,Side1,Side2,Side3,Valid,Perimeter,Area,Notes\n");

   while (fscanf(inputFile, "%lf %lf %lf",
                 &t.side1, &t.side2, &t.side3) == 3) {

       t.isValid = isValidTriangle(t);

       if (t.isValid) {
           t.perimeter = calculatePerimeter(t);
           t.area = calculateArea(t);

           fprintf(outputFile,
                   "%d,%.2lf,%.2lf,%.2lf,Yes,%.2lf,%.2lf,Valid Triangle\n",
                   record, t.side1, t.side2, t.side3,
                   t.perimeter, t.area);

           validCount++;
       } else {
           fprintf(outputFile,
                   "%d,%.2lf,%.2lf,%.2lf,No,0.00,0.00,Does not form a triangle\n",
                   record, t.side1, t.side2, t.side3);

           invalidCount++;
       }

       record++;
   }

   printf("Total Records Processed: %d\n", record - 1);
   printf("Valid Triangles: %d\n", validCount);
   printf("Invalid Triangles: %d\n", invalidCount);

   fclose(inputFile);
   fclose(outputFile);

   return 0;
}
