//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintPhoneBookEntry(char **phoneBook, int index) {
  printf("Name: %s\n", phoneBook[index]);
  printf("Phone Number: %s\n", phoneBook[index + 1]);
  printf("Email: %s\n", phoneBook[index + 2]);
}

int main() {
  char **phoneBook = NULL;
  int size = 0;

  // Allocate memory for the phone book
  phoneBook = (char **)malloc(sizeof(char *) * 10);
  for (int i = 0; i < 10; i++) {
    phoneBook[i] = (char *)malloc(20);
  }

  // Create some sample phone book entries
  phoneBook[0] = "John Doe";
  phoneBook[1] = "123-456-7890";
  phoneBook[2] = "john.doe@gmail.com";

  phoneBook[3] = "Jane Doe";
  phoneBook[4] = "456-789-0123";
  phoneBook[5] = "jane.doe@yahoo.com";

  phoneBook[6] = "Bill Smith";
  phoneBook[7] = "321-546-9870";
  phoneBook[8] = "bill.smith@hotmail.com";

  phoneBook[9] = "Mary Johnson";
  phoneBook[10] = "654-987-2345";
  phoneBook[11] = "mary.johnson@aol.com";

  // Print the phone book entries
  for (int i = 0; i < 10; i++) {
    PrintPhoneBookEntry(phoneBook, i);
  }

  // Free the memory allocated for the phone book
  for (int i = 0; i < 10; i++) {
    free(phoneBook[i]);
  }
  free(phoneBook);

  return 0;
}