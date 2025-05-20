//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentInfo {
   int id;
   char *name;
   int age;
};

int main() {
   struct studentInfo *database;
   int max_size = 5;
  
   // Allocate memory for database 
   database = (struct studentInfo *)malloc(max_size*sizeof(struct studentInfo));
  
   // Intialize students 
   for(int i=0; i<max_size; i++) {
      database[i].id = i;
      database[i].name = (char*) malloc(20*sizeof(char));
      strcpy(database[i].name, "Student Name");
      database[i].age = 18+i;
   }
  
   // Print the initial database 
   printf("The initial database is:\n");
   for(int i=0; i<max_size; i++) {
      printf("Student ID: %d\n", database[i].id);
      printf("Name: %s\n", database[i].name);
      printf("Age: %d\n\n", database[i].age);
   }

   // Update student 3 
   printf("Updating student 3's information...\n");
   database[2].name = "Changed Name";
   database[2].age = 22;
   printf("Student 3's updated information:\n");
   printf("Name: %s\n", database[2].name);
   printf("Age: %d\n\n", database[2].age);

   // Remove student 4
   printf("Removing student 4...\n");
   free(database[3].name);
   for(int i=3; i<max_size; i++) {
      database[i] = database[i+1];
   }
   max_size--;
   database = (struct studentInfo *)realloc(database,max_size*sizeof(struct studentInfo));
   printf("Student 4 has been removed.\n");

   // Print the updated database 
   printf("The updated database is:\n");
   for(int i=0; i<max_size; i++) {
      printf("Student ID: %d\n", database[i].id);
      printf("Name: %s\n", database[i].name);
      printf("Age: %d\n\n", database[i].age);
   }

   // Free memory used by the database 
   for(int i=0; i<max_size; i++) {
      free(database[i].name);
   }
   free(database);
   printf("Memory used by the database has been freed.\n");

   return 0;
}