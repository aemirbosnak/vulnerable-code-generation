//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
// Welcome to my XML Parser example program!
// This program reads in an XML file and prints out the element names and values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent an XML element
typedef struct {
   char *name; // Name of the element
   char *value; // Value of the element (if any)
} xml_element;

// Define a function to parse an XML file
void parse_xml_file(char *filename) {
   // Open the file for reading
   FILE *file = fopen(filename, "r");
   if (!file) {
      printf("Error: Unable to open file %s\n", filename);
      return;
   }

   // Initialize a stack to keep track of the element hierarchy
   xml_element *stack[1000];
   int top = -1;
   
   // Read through the file line by line
   char line[1000];
   while (fgets(line, sizeof(line), file)) {
      // Strip any whitespace from the line
      char *trimmed_line = strtok(line, " \t\n");

      // If the line starts with "<", it's the beginning of an element
      if (strncmp(trimmed_line, "<", 1) == 0) {
         // Create a new xml_element struct for the element
         xml_element *elem = malloc(sizeof(xml_element));

         // Extract the name of the element
         char *name = strtok(trimmed_line + 1, ">"); // Skip the '<' character
         elem->name = strdup(name);

         // If the element has a value, read it from the next line
         if (name[strlen(name) - 1] != '/') {
            fgets(line, sizeof(line), file); // Read the next line
            trimmed_line = strtok(line, " \t\n"); // Trim the whitespace
            
            // The value should be the entire line
            int i = 0;
            for (i = 0; i < strlen(trimmed_line); i++) {
               if (trimmed_line[i] == '<') {
                  break;
               }
            }
            trimmed_line[i] = '\0'; // Remove the trailing '<'
            
            // Save the value in the xml_element struct
            elem->value = strdup(trimmed_line);
         } else {
            elem->value = NULL;
         }

         // Push the element onto the stack
         stack[++top] = elem;
      } else if (strncmp(trimmed_line, "</", 2) == 0) {
         // If the line starts with "</", it's the end of an element
         char *name = strtok(trimmed_line + 2, ">"); // Skip the '</' characters
         xml_element *elem = stack[top--];
         
         if (strcmp(name, elem->name) != 0) {
            printf("Error: Mismatched element tag %s (expected %s)\n", name, elem->name);
            return;
         }
         
         // Print out the element name and value
         printf("%s: %s\n", elem->name, elem->value ? elem->value : "");
         free(elem->name);
         free(elem->value);
         free(elem);
      }
   }

   fclose(file);
}

int main(int argc, char **argv) {
   // Check if the filename was provided as a command-line arg
   if (argc != 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return 1;
   }

   // Call the parse_xml_file function on the specified file
   char *filename = argv[1];
   parse_xml_file(filename);
   
   // We're done!
   return 0;
}