//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define MAX_INDENT 4

// Function to print a newline and indent
void new_line(int indent);

// Function to print an HTML tag
void print_tag(char *tag_name, char *attr_str);

// Function to print an HTML attribute
void print_attr(char *attr_name, char *attr_value);

// Function to print a string with indentation
void print_string(char *str);

int main() {
  // Get the input HTML code from the user
  char *input_html = malloc(1024);
  printf("Enter the input HTML code: ");
  fgets(input_html, 1024, stdin);

  // Beautify the HTML code
  char *output_html = malloc(1024);
  int indent = 0;
  char *token = strtok(input_html, " ");
  while (token != NULL) {
    // Check if the token is a tag
    if (strncmp(token, "<", 1) == 0) {
      // Print the opening tag with indentation
      new_line(indent);
      print_tag(token, NULL);
      indent++;
    } else if (strncmp(token, "</", 1) == 0) {
      // Print the closing tag with indentation
      new_line(indent);
      print_tag(token + 2, NULL);
      indent--;
    } else {
      // Print the text content with indentation
      new_line(indent);
      print_string(token);
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Print the closing tag with indentation
  new_line(indent);
  print_tag("", NULL);

  // Print the output HTML code
  printf("%s\n", output_html);

  // Free the memory
  free(input_html);
  free(output_html);

  return 0;
}

// Function to print a newline and indent
void new_line(int indent) {
  for (int i = 0; i < indent; i++) {
    printf("    ");
  }
  printf("\n");
}

// Function to print an HTML tag
void print_tag(char *tag_name, char *attr_str) {
  printf("<%s", tag_name);
  if (attr_str != NULL) {
    printf(" %s", attr_str);
  }
  printf(">\n");
}

// Function to print an HTML attribute
void print_attr(char *attr_name, char *attr_value) {
  printf(" %s=\"%s\"", attr_name, attr_value);
}

// Function to print a string with indentation
void print_string(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == '\n') {
      printf("\n%s", str + i + 1);
      i++;
    } else {
      printf("%c", str[i]);
    }
  }
}