//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of tokens allowed
#define MAX_TOKENS 100

// Define the maximum length of each token
#define MAX_TOKEN_LENGTH 100

// Define the XML tag struct
typedef struct {
   char tag_name[MAX_TOKEN_LENGTH];
   char tag_contents[MAX_TOKEN_LENGTH];
} xml_tag;

// Define the main function
int main(void) {
   // Dynamically allocate memory for the tokens
   char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
   for (int i = 0; i < MAX_TOKENS; i++) {
      tokens[i] = (char*)malloc(MAX_TOKEN_LENGTH * sizeof(char));
   }

   // Define the XML input string
   char* xml_input = "<root><name>John</name><age>25</age></root>";

   // Initialize a stack of XML tags
   xml_tag stack[MAX_TOKENS];
   int stack_size = 0;

   // Initialize a position in the XML input string
   int pos = 0;

   // Loop through the XML input string
   while (xml_input[pos] != '\0') {
      // If the character is a left angle bracket
      if (xml_input[pos] == '<') {
         // Increase the position and continue to the next iteration of the loop
         pos++;
         continue;
      }

      // If the character is a right angle bracket
      if (xml_input[pos] == '>') {
         // Parse the tag
         char* token = strtok(tokens[0], "/");
         strcpy(stack[stack_size].tag_name, token);
         strcpy(stack[stack_size].tag_contents, tokens[0]);
         stack_size++;

         // Reset the token buffer
         memset(tokens[0], '\0', MAX_TOKEN_LENGTH);

         // Increase the position and continue to the next iteration of the loop
         pos++;
         continue;
      }

      // If the character is a forward slash
      if (xml_input[pos] == '/') {
         // Pop the last tag off the stack
         stack_size--;

         // Increase the position and continue to the next iteration of the loop
         pos++;
         continue;
      }

      // Add the character to the token buffer
      strncat(tokens[0], &xml_input[pos], 1);

      // Increase the position
      pos++;
   }

   // Print the parsed XML tags
   for (int i = 0; i < stack_size; i++) {
      printf("Tag name: %s\n", stack[i].tag_name);
      printf("Tag contents: %s\n", stack[i].tag_contents);
   }

   // Free the memory allocated for tokens
   for (int i = 0; i < MAX_TOKENS; i++) {
      free(tokens[i]);
   }
   free(tokens);

   // Return 0 to indicate successful execution
   return 0;
}