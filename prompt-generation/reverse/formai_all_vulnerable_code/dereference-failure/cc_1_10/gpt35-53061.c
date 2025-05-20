//FormAI DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str1[100], str2[100];
   int len1, len2, i, j, k;
   
   printf("Enter the first string: ");
   scanf("%s", str1);
   printf("Enter the second string: ");
   scanf("%s", str2);
   
   //surreal string manipulation begins
   len1 = strlen(str1);
   len2 = strlen(str2);
   
   printf("\nManipulating the strings in a surreal way...\n");
   
   //swap the first and last characters of the first string
   printf("\nSwapping the first and last characters of the first string..\n");
   char temp = str1[0];
   str1[0] = str1[len1-1];
   str1[len1-1] = temp;
   
   // capitalize every other character in the second string
   printf("\nCapitalizing every other character in the second string..\n");
   for(i = 0; i < len2; i++) {
      if(i % 2 == 0) {
         str2[i] = toupper(str2[i]);
      }
   }
   
   // reverse the order of the words in the first string
   printf("\nReversing the order of the words in the first string..\n");
   char *result = strdup(str1);
   char *token = strtok(result, " ");
   char *words[10];
   i = 0;
   while(token != NULL) {
      words[i++] = token;
      token = strtok(NULL, " ");
   }
   for(j = i-1; j >= 0; j--) {
      printf("%s ", words[j]);
   }
   
   // insert the second string into the middle of the first string
   printf("\nInserting the second string into the middle of the first string..\n");
   for(k = len1/2, j = 0; j < len2; k++, j++) {
      str1[k] = str2[j];
   }
   
   // print the final results
   printf("\nFinal Result: First string: %s, Second string: %s\n", str1, str2);
   
   return 0;
}