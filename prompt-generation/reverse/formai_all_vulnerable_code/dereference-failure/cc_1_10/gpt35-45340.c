//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to reverse a string
char* str_reverse(char str[]) {
  int length = strlen(str);
  char* reversed_str = malloc((length+1) * sizeof(char));
  int i, j = 0;
  for(i = length-1; i >= 0; i--) {
    reversed_str[j] = str[i];
    j++;
  }
  reversed_str[j] = '\0';
  return reversed_str;
}

int main() {
  //Input string
  char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  str[strcspn(str, "\n")] = '\0'; //Removing '\n' from input string
  
  //Output string
  char* output_str = malloc((strlen(str)+1) * sizeof(char));
  
  //Reversing the string
  output_str = str_reverse(str);
  printf("Reverse of the string is: %s\n", output_str);

  //Counting vowels and replacing them with '*'
  int i, vowel_count = 0;
  for(i = 0; i < strlen(str); i++) {
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      output_str[i] = '*';
      vowel_count++;
    }
    else {
      output_str[i] = str[i];
    }
  }
  printf("Number of vowels in the string: %d\n", vowel_count);
  printf("Modified string: %s\n", output_str);

  //Adding '!' at the end of the string
  strcat(output_str, "!");
  printf("Final string: %s", output_str);

  free(output_str);
  return 0;
}