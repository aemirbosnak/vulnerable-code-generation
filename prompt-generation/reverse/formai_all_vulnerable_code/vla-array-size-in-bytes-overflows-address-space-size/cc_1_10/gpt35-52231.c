//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>

// Define the struct for our "database" entry
typedef struct {
  int id;
  char name[20];
  int age;
  char occupation[20];
} Entry;

int main() {
  int num_entries;
  printf("Welcome to the Happy Database Simulator!\n");
  printf("How many entries would you like to add? ");
  scanf("%d", &num_entries);
  
  // Create an array of entries to store all of our data
  Entry entries[num_entries];
  
  // Loop through each entry the user wants to add
  for (int i=0; i<num_entries; i++) {
    printf("\nEntry #%d\n", i+1);
    
    // Gather data for the entry
    printf("ID: ");
    scanf("%d", &entries[i].id);
    
    printf("Name: ");
    scanf("%s", entries[i].name);
    
    printf("Age: ");
    scanf("%d", &entries[i].age);
    
    printf("Occupation: ");
    scanf("%s", entries[i].occupation);
  }
  
  // Print out all the entries we collected
  printf("\nHere are all the entries in the database:\n");
  for (int i=0; i<num_entries; i++) {
    printf("\nEntry #%d\n", i+1);
    printf("ID: %d\n", entries[i].id);
    printf("Name: %s\n", entries[i].name);
    printf("Age: %d\n", entries[i].age);
    printf("Occupation: %s\n", entries[i].occupation);
  }
  
  printf("\nThanks for using the Happy Database Simulator! Have a nice day!\n");
  return 0;
}