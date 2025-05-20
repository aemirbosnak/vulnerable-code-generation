//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  // Initialize a 2D array of strings to store phone numbers
  char **phoneBook = NULL;
  int numEntries = 0;

  // Create a loop to add entries to the phone book
  while (1) {
    // Get the name of the person
    char name[20];
    printf("Enter the name of the person: ");
    scanf("%s", name);

    // Get the phone number of the person
    char number[20];
    printf("Enter the phone number of the person: ");
    scanf("%s", number);

    // Allocate memory for the phone book entry
    phoneBook = realloc(phoneBook, (numEntries + 1) * sizeof(char *));
    phoneBook[numEntries] = malloc(20 * sizeof(char));

    // Store the name and phone number in the phone book entry
    strcpy(phoneBook[numEntries], name);
    strcpy(phoneBook[numEntries], number);

    // Increment the number of entries
    numEntries++;

    // Check if the user wants to add another entry
    char answer;
    printf("Do you want to add another entry? (Y/N): ");
    scanf("%c", &answer);

    // Break out of the loop if the user does not want to add another entry
    if (answer == 'N') {
      break;
    }
  }

  // Print the phone book
  printf("Phone Book:\n");
  for (int i = 0; i < numEntries; i++) {
    printf("%s - %s\n", phoneBook[i], phoneBook[i + 1]);
  }

  // Free the memory allocated for the phone book entries
  for (int i = 0; i < numEntries; i++) {
    free(phoneBook[i]);
  }

  // Free the memory allocated for the phone book
  free(phoneBook);

  return 0;
}