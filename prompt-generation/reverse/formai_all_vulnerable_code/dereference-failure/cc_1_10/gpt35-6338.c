//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
 
void convert(char* s);
 
/* main */
int main() {
  char c;
  char str[MAX_STR_LEN];
  int i = 0;
 
  printf("Enter a string in C Alien Language: ");
 
  while((c = getchar()) != '\n' && i < MAX_STR_LEN) {
    str[i++] = c;
  }
  str[i] = '\0';
 
  /* Convert */
  convert(str);
 
  printf("Translation: %s\n", str);
 
  return 0;
}
 
/* convert() */
void convert(char* s) {
  int len = strlen(s);
 
  /* Swap the first and last characters */
  char temp = s[0];
  s[0] = s[len-1];
  s[len-1] = temp;
 
  /* Remove every other character */
  for(int i=0; i<len; i++) {
    if(i%2 == 0) {
      s[i] = '\0';
    }
  }
 
  /* Replace any occurrences of 'o' with 'a',
     and any occurrences of 'i' with 'u' */
  for(int i=0; i<len; i++) {
    if(s[i] == 'o') {
      s[i] = 'a';
    } else if(s[i] == 'i') {
      s[i] = 'u';
    }
  }
}