//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 200

void sanitizeInput(char* input);

int main()
{
   char input[MAX_INPUT_LENGTH];

   printf("Enter input to be sanitized: ");
   fgets(input, sizeof(input), stdin);

   sanitizeInput(input);

   printf("Sanitized input: %s", input);

   return 0;
}

void sanitizeInput(char* input)
{
   char* p = input;
   while (*p != '\0')
   {
      if (!isalnum(*p) && !isspace(*p))
      {
         *p = ' ';
      }
      p++;
   }

   char* q = input;
   while (*q != '\0')
   {
      if (*q == ' ' && *(q + 1) == ' ')
      {
         memmove(q, q + 1, strlen(q + 1) + 1);
         continue;
      }
      q++;
   }

   if (input[strlen(input) - 1] == ' ')
   {
      input[strlen(input) - 1] = '\0';
   }
}