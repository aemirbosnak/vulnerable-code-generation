//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <ctype.h>

// Function to count the number of vowels in a string
int countVowels(char *str) { 
  int count = 0;
  char c;

  while ((c = *str++) != '\0') {
    switch(tolower(c)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        count++;
        break;
    }
  }

  return count;
}

// Function to check if a given string is a palindrome or not
int isPalindrome(char *str) {
  int len = strlen(str);

  // Remove non-alphanumeric characters and convert string to lowercase
  char cleanedStr[len];
  int j = 0;
  
  for (int i = 0; i < len; i++) {
    if (isalnum(*(str+i))) {
      cleanedStr[j] = tolower(*(str+i));
      j++;
    }
  }

  cleanedStr[j] = '\0';
  
  len = strlen(cleanedStr);

  // Check if string is a palindrome
  for (int i = 0; i < len/2; i++) {
    if (*(cleanedStr+i) != *(cleanedStr+len-i-1)) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char input[100];

  // Get user input
  printf("Please enter a string: ");
  fgets(input, 100, stdin);

  // Remove newline character from input
  input[strcspn(input, "\n")] = '\0';

  // Count the number of vowels in the input string
  int numVowels = countVowels(input);
  printf("Number of vowels in the string: %d\n", numVowels);

  // Check if the input string is a palindrome
  if (isPalindrome(input)) {
    printf("The string is a palindrome!\n");
  } else {
    printf("The string is not a palindrome!\n");
  }

  return 0;
}