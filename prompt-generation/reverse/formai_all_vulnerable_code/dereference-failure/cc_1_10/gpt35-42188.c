//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char* decToBin(int n) {
  // Allocate memory for binary number
  char* binaryNum = (char*)malloc(33);
  
  // Initializing index in binary number array
  int i = 0;
  while (n > 0) {
    binaryNum[i] = (n % 2) + '0';
    n = n / 2;
    i++;
  }

  // Adding null terminator at the end of binary number
  binaryNum[i] = '\0';

  // Reversing binary number
  int left = 0;
  int right = strlen(binaryNum) - 1;
  while (left < right) {
    char temp = binaryNum[left];
    binaryNum[left] = binaryNum[right];
    binaryNum[right] = temp;
    left++;
    right--;
  }

  // Return binary number
  return binaryNum;
}

// Function to convert binary to decimal
int binToDec(char* binaryNum) {
  // Initializing variables
  int decimalNum = 0;
  int base = 1;
  int len = strlen(binaryNum);

  // Converting binary number to decimal number
  for (int i = len - 1; i >= 0; i--) {
    if (binaryNum[i] == '1') {
      decimalNum += base;
    }
    base *= 2;
  }

  // Return decimal number
  return decimalNum;
}

// Main function
int main() {
  // Initializing variables
  int decimalNum, choice;
  char* binaryNum = (char*)malloc(33);

  // Displaying menu
  printf("Binary Converter\n");
  printf("----------------\n");
  printf("1. Convert decimal to binary\n");
  printf("2. Convert binary to decimal\n");
  printf("Enter your choice (1/2): ");
  scanf("%d", &choice);

  // Processing user choice
  switch (choice) {
    case 1:
      // Converting decimal to binary
      printf("Enter decimal number: ");
      scanf("%d", &decimalNum);
      binaryNum = decToBin(decimalNum);
      printf("Binary equivalent: %s\n", binaryNum);
      break;

    case 2:
      // Converting binary to decimal
      printf("Enter binary number (up to 32 bits): ");
      scanf("%s", binaryNum);
      decimalNum = binToDec(binaryNum);
      printf("Decimal equivalent: %d\n", decimalNum);
      break;

    default:
      printf("Invalid choice!\n");
      break;
  }

  // Freeing memory
  free(binaryNum);

  // Exiting program
  return 0;
}