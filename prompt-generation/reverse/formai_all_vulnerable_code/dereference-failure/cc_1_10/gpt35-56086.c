//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char name[20];
   int age;
   float height;
   float weight;
} Person;

int main() {
   FILE *fp;
   char filename[20];
   char row[100];
   Person people[50];
   int count = 0;

   printf("Enter the filename: ");
   gets(filename);

   fp = fopen(filename, "r");
   if (fp == NULL) {
      perror("Error opening file");
      exit(1);
   }

   // Read each row in the CSV file and store the data in a Person struct
   while (fgets(row, 100, fp) != NULL) {
      char *token;
      token = strtok(row, ",");
      
      // Fill the Person struct with the data from the row
      strcpy(people[count].name, token);
      token = strtok(NULL, ",");
      people[count].age = atoi(token);
      token = strtok(NULL, ",");
      people[count].height = atof(token);
      token = strtok(NULL, ",");
      people[count].weight = atof(token);

      count++; // Move to next Person in the array
   }

   fclose(fp);

   // Print out all the people in the array
   for (int i = 0; i < count; i++) {
      printf("Name: %s\n", people[i].name);
      printf("Age: %d\n", people[i].age);
      printf("Height: %f\n", people[i].height);
      printf("Weight: %f\n", people[i].weight);
      printf("\n");
   }

   return 0;
}