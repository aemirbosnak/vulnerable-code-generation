//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int indent_level;    // current indentation level
   char* input;         // input string to beautify
   char* output;        // beautified output string
} Beautifier;

// initialize a new Beautifier instance
Beautifier* new_beautifier(char* input) {
   Beautifier* beautifier = malloc(sizeof(Beautifier));
   beautifier->indent_level = 0;
   beautifier->input = input;
   beautifier->output = malloc(sizeof(char));
   *(beautifier->output) = '\0';
   return beautifier;
}

// append a string to the output of the Beautifier instance
void append(Beautifier* beautifier, char* string) {
   beautifier->output = realloc(beautifier->output, strlen(beautifier->output) + strlen(string) + 1);
   strcat(beautifier->output, string);
}

// increase the indentation level of the Beautifier instance
void increase_indent(Beautifier* beautifier) {
   beautifier->indent_level++;
}

// decrease the indentation level of the Beautifier instance
void decrease_indent(Beautifier* beautifier) {
   if (beautifier->indent_level > 0) {
      beautifier->indent_level--;
   }
}

// get the current indentation string based on the indentation level of the Beautifier instance
char* get_indent_str(Beautifier* beautifier) {
   char* indent_str = malloc(beautifier->indent_level * 3 + 1);
   memset(indent_str, ' ', beautifier->indent_level * 3);
   *(indent_str + beautifier->indent_level * 3) = '\0';
   return indent_str;
}

// beautify HTML source code
void beautify_html(Beautifier* beautifier) {
   char* current_char = beautifier->input;
   char* start_tag = NULL;
   int in_tag = 0;
   while (*current_char != '\0') {
      if (*current_char == '<') {
         in_tag = 1;
         start_tag = current_char;
      } else if (*current_char == '>') {
         in_tag = 0;
         if (*(current_char - 1) == '/') {  // self-closing tag
            decrease_indent(beautifier);
         }
         append(beautifier, "\n");
      } else if (!in_tag) {
         append(beautifier, current_char);
      }
      current_char++;
      if (*current_char == '\n' && !in_tag) {
         append(beautifier, get_indent_str(beautifier));
      }
   }
}

int main() {
   char* input = "<html><head><title>Example</title></head><body><h1>Hello World!</h1></body></html>";
   Beautifier* beautifier = new_beautifier(input);
   beautify_html(beautifier);
   printf("%s", beautifier->output);
   free(beautifier->output);
   free(beautifier);
   return 0;
}