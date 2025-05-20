//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This XML parser program is a curious soul that loves to know every single detail about the XML file it is parsing

int main() {
   char input[1000], buffer[1000], tag[1000], value[1000], *start, *end, *tag_start, *tag_end, *value_start, *value_end;
   int i, j;
   
   printf("Please enter the XML input:\n");
   fgets(input, 1000, stdin); // Get input from user
   
   start = input; // Set pointer to the start of input
   
   while (*start != '\0') { // Check for end of string
       
       // Copy a tag into buffer
       tag_start = strchr(start, '<'); // Find start of tag
       tag_end = strchr(start, '>'); // Find end of tag
       
       if (tag_start != NULL && tag_end != NULL) { // If both pointers are not NULL
           strncpy(buffer, tag_start, tag_end - tag_start + 1); // Copy tag into buffer
           buffer[tag_end - tag_start + 1] = '\0'; // Add null terminator
           
           // Extract tag name
           tag_start++; // Move pointer to start of tag name
           tag_end--; // Move pointer to end of tag name
           strncpy(tag, tag_start, tag_end - tag_start + 1); // Copy tag name into tag array
           tag[tag_end - tag_start + 1] = '\0'; // Add null terminator
           
           printf("Tag Name: %s\n", tag);
           
           // Check if tag has a value
           if (*(tag_end + 1) != '\0' && *(tag_end + 1) != '<' && strchr(tag_end + 1, '<') != NULL) { // If tag has a value
               value_start = strchr(tag_end + 1, '"') + 1; // Find start of value
               value_end = strchr(value_start, '"'); // Find end of value
               
               if (value_start != NULL && value_end != NULL) { // If both pointers are not NULL
                   strncpy(value, value_start, value_end - value_start + 1); // Copy value into value array
                   value[value_end - value_start + 1] = '\0'; // Add null terminator
                   
                   printf("Tag Value: %s\n", value);
               }
           } else { // If tag does not have a value
               printf("Tag has no value.\n");
           }
       }
       
       // Move pointer to next tag
       end = strchr(start, '>'); // Find end of current tag
       if (end != NULL) { // If pointer is not NULL
           end++; // Move pointer to beginning of next tag
           start = end; // Set start pointer to next tag
       } else { // If pointer is NULL
           start++; // Move pointer to next character
       }
   }
   
   return 0;
}