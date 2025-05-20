//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
// Romeo and Juliet's Database Indexing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structure of our system */
struct Index {
   int data;
   char* name;
};

/* Function prototypes */
void add_data(struct Index arr[], int size);
void print_data(struct Index arr[], int size);
int search_data(struct Index arr[], int size, char* query);

int main() {

   /* Variables */
   int size;
   char input[100];

   /* Introduction */
   printf("Welcome to Romeo and Juliet's Database Indexing System!\n");
   
   /* Get size of database */
   printf("Enter the number of records you want to store: ");
   fgets(input, 100, stdin);
   size = atoi(input);

   /* Allocate memory for database */
   struct Index* arr = malloc(size * sizeof(struct Index));

   /* Add data to database */
   add_data(arr, size);

   /* Print all data in database */
   printf("Data in the database:\n");
   print_data(arr, size);

   /* Search for specific data in database */
   printf("Enter a name to search for: ");
   fgets(input, 100, stdin);
   input[strcspn(input, "\n")] = 0; // Remove newline character from input
   int index = search_data(arr, size, input);
   
   if (index == -1) {
      printf("Sorry, the name \"%s\" was not found.\n", input);
   }
   else {
      printf("%s was found! His/Her data is as follows:\n", input);
      printf("Data: %d\n", arr[index].data);
   }

   /* Free allocated memory */
   free(arr);

   /* Exit program */
   return 0;
}

/* Function to add data */
void add_data(struct Index arr[], int size) {
   char input[100];

   for (int i = 0; i < size; i++) {
      printf("\nEnter data for record %d:\n", i + 1);

      /* Get data */
      printf("Enter an integer: ");
      fgets(input, 100, stdin);
      arr[i].data = atoi(input);

      printf("Enter a name: ");
      fgets(input, 100, stdin);
      input[strcspn(input, "\n")] = 0; // Remove newline character from input
      arr[i].name = malloc(strlen(input) * sizeof(char));
      strcpy(arr[i].name, input);
   }
}

/* Function to print data */
void print_data(struct Index arr[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%s: %d\n", arr[i].name, arr[i].data);
   }
}

/* Function to search for data */
int search_data(struct Index arr[], int size, char* query) {
   for (int i = 0; i < size; i++) {
      if (strcmp(query, arr[i].name) == 0) {
         return i;
      }
   }
   return -1;
}