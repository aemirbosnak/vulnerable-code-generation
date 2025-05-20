//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Surrealist C Database Simulation Program

int main() {
  printf("Welcome to the Surrealist C Database Simulation Program!\n");
  
  // Instantiate variables
  char* database[10] = {"cat", "sock", "star", "tree", "rainbow", "jay", "moon", "ocean", "mountain", "butterfly"};
  char* input = malloc(20 * sizeof(char));
  int i, index = 0, id = 0;
  srand(time(NULL));
  
  // Loop until user enters "exit"
  while (1) {
    printf("\nEnter a word to search the database or enter 'exit' to quit: ");
    scanf("%s", input);
    
    // Check if user wants to quit
    if (strcmp(input, "exit") == 0) break;
    
    // Iterate through the database to find a match
    for (i=0; i<10; i++) {
      if (strcmp(input, database[i]) == 0) {
        printf("\nFound match for '%s' at index %d with ID %d!\n", input, i, id);
        index = i;
        break;
      }
    }
    
    // If no match is found, add the word to the end of the database and generate a new ID for it
    if (i == 10) {
      printf("\nNo match found for '%s'. Adding to database...\n", input);
      database[id] = input;
      index = id;
      printf("New word '%s' added to database at index %d with ID %d.\n", input, id, id);
      id++;
    }
    
    // Retrieve the word from the database using the index and ID
    printf("Retrieving word '%s' from database at index %d with ID %d.\n", database[index], index, index);
    
    // Do something surreal with the word
    int j, k;
    char letter;
    printf("Performing surreal operation on word...\n");
    for (j=0; j<strlen(database[index]); j++) {
      for (k=0; k<3; k++) {
        letter = (char) (rand() % 26 + 97);
        if (j%2 == 0) {
          database[index][j] = toupper(letter);
        } else {
          database[index][j] = letter;
        }
      }
    }
    
    // Print the new, surreal version of the word
    printf("New, surreal version of '%s': %s\n", input, database[index]);
  }
  
  // Free dynamically allocated memory
  free(input);
  
  printf("\nThank you for using the Surrealist C Database Simulation Program!\n");
  
  return 0;
}