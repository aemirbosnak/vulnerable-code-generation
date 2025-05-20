//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
  char message[MAX_LENGTH];
  int key, choice, i;

  printf("Enter the message to encrypt: ");
  fgets(message, MAX_LENGTH, stdin);

  printf("Enter the key to encrypt with: ");
  scanf("%d", &key);

  printf("\nEncrypt or decrypt message? (1 or 2): ");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("\nEncrypting message with statistical transposition...\n");

    // Calculate length of message
    int length = 0;
    while(message[length] != '\0') {
      length++;
    }

    // Remove newline character if present
    if(message[length - 1] == '\n') {
      message[length - 1] = '\0';
      length--;
    }

    // Calculate number of rows needed for the transposition
    int rows = (length / key) + 1;

    // Create 2D array to store transposed message
    char transposed[rows][key];

    // Initialize array with 'x' characters
    for(i = 0; i < rows; i++) {
      for(int j = 0; j < key; j++) {
        transposed[i][j] = 'x';
      }
    }

    // Transpose message into array
    int row = 0;
    int col = 0;
    for(i = 0; i < length; i++) {
      transposed[row][col] = message[i];

      col++;

      if(col == key) {
        col = 0;
        row++;
      }
    }

    // Print transposed message
    printf("\nTransposed message:\n");
    for(i = 0; i < rows; i++) {
      for(int j = 0; j < key; j++) {
        printf("%c ", transposed[i][j]);
      }
      printf("\n");
    }

    // Print encrypted message
    printf("\nEncrypted message:\n");
    for(int j = 0; j < key; j++) {
      for(i = 0; i < rows; i++) {
        printf("%c", transposed[i][j]);
      }
    }
    printf("\n");
  }
  else if(choice == 2) {
    printf("\nThis encryption method cannot be decrypted with only the key.\n");
  }
  else {
    printf("\nInvalid choice.\n");
  }

  return 0;
}