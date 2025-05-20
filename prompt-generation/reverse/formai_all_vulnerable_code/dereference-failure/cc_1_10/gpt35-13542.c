//FormAI DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char str1[] = "Art is a lie that tells the truth";
  char str2[] = "Picasso";
  char str3[] = "painting";
  int len;

  // Print the original strings 
  printf("Original String 1: %s\n", str1);
  printf("Original String 2: %s\n", str2);
  printf("Original String 3: %s\n", str3);

  // Concatenate str2 and str3 in str1
  strcat(str1, " - ");
  strcat(str1, str2);
  strcat(str1, " was famous for his ");
  strcat(str1, str3);

  // Print the modified string1
  printf("\nModified String 1: %s\n", str1);

  // Copy str1 to str2
  strcpy(str2, str1);

  // Print the copied string2
  printf("Copied String 2: %s\n", str2);

  // Find and print the length of str1 and str3
  len = strlen(str1);
  printf("\nLength of String 1 '%s': %d\n", str1, len);

  len = strlen(str3);
  printf("Length of String 3 '%s': %d\n", str3, len);

  // Modify string3 using strchr
  char *p = strchr(str3, 'i');

  while (p != NULL){
    *p = '?';
    p = strchr(p+1, 'i');
  }

  // Print the modified string3
  printf("\nModified String 3: %s\n", str3);

  return 0;
}