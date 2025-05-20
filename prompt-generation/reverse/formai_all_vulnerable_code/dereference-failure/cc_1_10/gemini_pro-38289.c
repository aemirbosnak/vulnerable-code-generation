//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A macro to allocate memory.
#define MALLOC(type, n) (type *)malloc(sizeof(type) * n)

// A structure to represent an HTML tag.
typedef struct HtmlTag {
  char *name;
  char **attributes;
  int num_attributes;
  char *content;
} HtmlTag;

// A function to create a new HTML tag.
HtmlTag *new_html_tag(char *name, char **attributes, int num_attributes, char *content) {
  HtmlTag *tag = MALLOC(HtmlTag, 1);
  tag->name = strdup(name);
  tag->attributes = MALLOC(char *, num_attributes);
  for (int i = 0; i < num_attributes; i++) {
    tag->attributes[i] = strdup(attributes[i]);
  }
  tag->num_attributes = num_attributes;
  tag->content = strdup(content);
  return tag;
}

// A function to free an HTML tag.
void free_html_tag(HtmlTag *tag) {
  free(tag->name);
  for (int i = 0; i < tag->num_attributes; i++) {
    free(tag->attributes[i]);
  }
  free(tag->attributes);
  free(tag->content);
  free(tag);
}

// A function to print an HTML tag.
void print_html_tag(HtmlTag *tag) {
  printf("<%s", tag->name);
  for (int i = 0; i < tag->num_attributes; i++) {
    printf(" %s", tag->attributes[i]);
  }
  printf(">%s</%s>\n", tag->content, tag->name);
}

// A function to beautify an HTML document.
char *beautify_html(char *html) {
  // Create a stack to store the tags.
  HtmlTag **stack = MALLOC(HtmlTag *, 100);
  int stack_size = 0;

  // Create a buffer to store the beautified HTML.
  char *buffer = MALLOC(char, 10000);
  int buffer_size = 0;

  // Iterate over the characters in the HTML document.
  int i = 0;
  while (html[i] != '\0') {
    // If the current character is the start of a tag.
    if (html[i] == '<') {
      // Find the end of the tag.
      int j = i + 1;
      while (html[j] != '>' && html[j] != '\0') {
        j++;
      }

      // Create a new HTML tag.
      char *name = strndup(html + i + 1, j - i - 1);
      char **attributes = NULL;
      int num_attributes = 0;
      char *content = NULL;

      // Parse the attributes of the tag.
      if (html[j] == '>') {
        j++;
        int k = j;
        while (html[k] != '<' && html[k] != '\0') {
          k++;
        }
        content = strndup(html + j, k - j);
      } else {
        int k = j + 1;
        while (html[k] != '>' && html[k] != '\0') {
          k++;
        }
        char *attributes_string = strndup(html + j + 1, k - j - 1);
        char *attribute;
        attributes = MALLOC(char *, 10);
        num_attributes = 0;
        attribute = strtok(attributes_string, " ");
        while (attribute != NULL) {
          attributes[num_attributes] = strdup(attribute);
          num_attributes++;
          attribute = strtok(NULL, " ");
        }
        free(attributes_string);
      }

      // Push the tag onto the stack.
      stack[stack_size] = new_html_tag(name, attributes, num_attributes, content);
      stack_size++;

      // Print the tag.
      print_html_tag(stack[stack_size - 1]);

      // Update the buffer.
      buffer_size += strlen(html + i);
      strncat(buffer, html + i, strlen(html + i));

      // Update the index.
      i = j;
    } else {
      // If the current character is not the start of a tag.
      // Print the character.
      buffer[buffer_size] = html[i];
      buffer_size++;

      // Update the index.
      i++;
    }
  }

  // Pop the tags from the stack and print them.
  while (stack_size > 0) {
    stack_size--;
    print_html_tag(stack[stack_size]);
  }

  // Free the stack.
  for (int i = 0; i < stack_size; i++) {
    free_html_tag(stack[i]);
  }
  free(stack);

  // Return the beautified HTML.
  return buffer;
}

// A function to read an HTML document from a file.
char *read_html_file(char *path) {
  // Open the file.
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("Error: Could not open file '%s'.\n", path);
    exit(1);
  }

  // Read the file into a buffer.
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char *buffer = MALLOC(char, file_size + 1);
  fread(buffer, file_size, 1, file);
  buffer[file_size] = '\0';

  // Close the file.
  fclose(file);

  // Return the buffer.
  return buffer;
}

// A function to write an HTML document to a file.
void write_html_file(char *path, char *html) {
  // Open the file.
  FILE *file = fopen(path, "w");
  if (file == NULL) {
    printf("Error: Could not open file '%s'.\n", path);
    exit(1);
  }

  // Write the HTML to the file.
  fwrite(html, strlen(html), 1, file);

  // Close the file.
  fclose(file);
}

// A function to beautify an HTML document and write it to a file.
void beautify_html_file(char *path) {
  // Read the HTML document from a file.
  char *html = read_html_file(path);

  // Beautify the HTML document.
  char *beautified_html = beautify_html(html);

  // Write the beautified HTML document to a file.
  write_html_file(path, beautified_html);

  // Free the HTML documents.
  free(html);
  free(beautified_html);
}

int main(int argc, char **argv) {
  // If no arguments are provided, print the usage.
  if (argc < 2) {
    printf("Usage: %s <html_file>\n", argv[0]);
    return 1;
  }

  // Beautify the HTML document.
  beautify_html_file(argv[1]);

  return 0;
}