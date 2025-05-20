//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* spellCheck(char *word) {

   int i, j, len;
   int flag = 0;
   char temp;
   char *wordCopy = malloc(strlen(word) + 1);

   // Copy word to a new string
   strcpy(wordCopy, word);

   len = strlen(wordCopy);

   // Check each character in the word
   for(i=0; i<len; i++) {
      for(j=i+1; j<len; j++){

         // If two characters are the same, remove one
         if(wordCopy[i] == wordCopy[j]) {
            flag++;

            // Shift each character to the left
            for(int k = j; k<len; k++){
               wordCopy[k] = wordCopy[k+1];
            }
         }
      }
   }

   // If one or more characters are removed, print suggestions
   if(flag > 0) {
      printf("\nDid you mean:\n");

      // Swap adjacent characters and print as a suggestion
      for(i=0; i<len-1; i++) {
         temp = wordCopy[i];
         wordCopy[i] = wordCopy[i+1];
         wordCopy[i+1] = temp;
         printf("%s\n", wordCopy);
         strcpy(wordCopy, word);
      }
   }

   // Deallocate memory for copy of word
   free(wordCopy);
   
   return word;
}

int main() {

   char str[100];

   printf("Enter a word to check its spelling: ");
   scanf("%s", str);

   // Convert string to lowercase
   for(int i = 0; str[i]; i++){
       str[i] = tolower(str[i]);
   }

   // Check spelling and print result
   printf("You entered: %s\n", spellCheck(str));

   return 0;
}