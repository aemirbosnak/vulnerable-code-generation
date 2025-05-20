//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Happy Encryption Program!\n\n");

  // Get user input for the message to encrypt
  char message[100];
  printf("Please enter the message you would like to encrypt:\n");
  fgets(message, 100, stdin);

  // Determine the length of the message
  int len = strlen(message);

  // Create a new string to hold the encrypted message
  char encrypted_message[len];

  // Loop through each character of the message
  for (int i = 0; i < len; i++) {
    // Shift the character by 3 places
    char c = message[i];
    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' + 3) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + 3) % 26 + 'A';
    }
    encrypted_message[i] = c;
  }

  // Print the encrypted message
  printf("\nYour encrypted message is:\n");
  printf("%s\n", encrypted_message);

  // Prompt the user to save the message to a file
  char choice[2];
  printf("\nWould you like to save your encrypted message to a file? (y/n)\n");
  fgets(choice, 2, stdin);

  // If the user selects y, save the file
  if (choice[0] == 'y') {
    char file_name[20];
    printf("\nPlease enter a name for your file:\n");
    fgets(file_name, 20, stdin);

    // Concatenate the file extension .txt onto the file name
    strcat(file_name, ".txt");

    // Open the file in write mode
    FILE *f = fopen(file_name, "w");

    // Write the encrypted message to the file
    fputs(encrypted_message, f);

    // Close the file
    fclose(f);

    printf("\nYour file has been saved!\n");
  } else {
    printf("\nThank you for using the Happy Encryption Program!\n");
  }
  
  return 0;
}