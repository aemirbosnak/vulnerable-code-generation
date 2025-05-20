//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {

  char str1[] = "Hello";
  char str2[] = "World";
  int len1 = strlen(str1);
 
  // concatenating two strings
  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);
 
  // converting string to uppercase
  for(int i = 0; str1[i]; i++){
    if(str1[i] >= 'a' && str1[i] <= 'z'){
         str1[i] = str1[i] - 32;
    }
  }
  printf("Uppercase string: %s\n", str1);
  
  // finding the length of the string after concatenating
  int len2 = strlen(str1);
  printf("Length of the Concatenated string: %d\n", len2);
  
  // counting the number of vowels in the string
  int num_of_vowels=0;
  for(int i=0;i<len2;++i){
    if(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' || str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U' ){
      ++num_of_vowels;
    }
  }
  printf("Number of vowels in string: %d\n", num_of_vowels);
  
  // splitting the concatenated string into two equal parts
  char first_half[len2/2+1];
  strncpy(first_half, str1, len2/2);
  first_half[len2/2]='\0';
  printf("First half of string: %s\n", first_half);
  
  char second_half[len2/2+1];
  strncpy(second_half, str1+len2/2, len2/2);
  second_half[len2/2]='\0';
  printf("Second half of string: %s\n", second_half);

  // sorting the characters in the second half of the string in descending order
  for(int i = 0; i < strlen(second_half); i++){
    for(int j = i+1; j < strlen(second_half); j++){
      if(second_half[j] > second_half[i]){
        char temp = second_half[i];
        second_half[i] = second_half[j];
        second_half[j] = temp;
      }
    }
  }
  printf("Second half of string after sorting: %s\n", second_half);

  // replacing the vowels in the first half of the string with '*'
  for(int i = 0; i < strlen(first_half); i++){
      if(first_half[i] == 'a' || first_half[i] == 'e' || first_half[i] == 'i' || first_half[i] == 'o' || first_half[i] == 'u' || first_half[i] == 'A' || first_half[i] == 'E' || first_half[i] == 'I' || first_half[i] == 'O' || first_half[i] == 'U'){
            first_half[i] = '*';
      }
  }
  printf("First half of string after replacing vowels with '*': %s\n", first_half);

  
  return 0;
}