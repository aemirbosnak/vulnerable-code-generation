//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_LINES 50  
#define MAX_LENGTH 100 

// HTML Tags
const char *tags[] = {"html", "head", "title", "body", "h1", "h2", "h3", "h4", "h5", "h6", "p", "strong", "em", "ul", "ol", "li", "a", "img", "div", "span", "table", "tr", "td", "th"};

// Indentation Settings
int indent = 0;  
int indent_width = 4;  
char indent_char = ' ';  

// Helper function to insert indentation
void insert_indentation(FILE *output_file) {
  int i;
  for (i = 0; i < indent; i++) {
    fputs(&indent_char, output_file);
  }
}

// Main function to beautify HTML code
void beautify_html(char *html_file, char *output_file) {
  FILE *input_file = fopen(html_file, "r");
  FILE *output = fopen(output_file, "w");

  if (input_file == NULL) {
    printf("Could not open input file '%s'\n", html_file);
    return;
  }
  if (output == NULL) {
    printf("Could not open output file '%s'\n", output_file);
    return;
  }

  // Read line by line
  char line[MAX_LENGTH];
  int tag[MAX_LENGTH] = {0};
  int open_tags[MAX_LINES] = {0};
  int open_tags_count = 0;

  while (fgets(line, MAX_LENGTH, input_file)) {
    int i, j, k;
    int len = strlen(line);

    // Analyze line
    for (i = 0; i < len; i++) {
      if (line[i] == '<') {
        for (j = i + 1; j < len; j++) {
          if (line[j] == '>') {
            // End of tag found
            char tag_name[MAX_LENGTH];
            memset(tag_name, 0, MAX_LENGTH);
            sscanf(&line[i + 1], "%s", tag_name);

            // Check if it's a tag or a comment
            int is_tag = 0;
            if (tag_name[0] != '!') {
              for (k = 0; k < 23; k++) {
                if (!strcmp(tag_name, tags[k])) {
                  is_tag = 1;
                  break;
                }
              }
            }

            // Update tag stack
            if (!is_tag) {
              tag[i] = -1;
            } else if (tag_name[0] == '/') {
              if (open_tags_count > 0 && !strcmp(&tag_name[1], tags[open_tags[open_tags_count - 1]])) {
                tag[i] = open_tags[open_tags_count - 1];
                open_tags_count--;
              }
            } else {
              tag[i] = open_tags_count;
              open_tags[open_tags_count] = k;
              open_tags_count++;  
            }

            i = j;
            break;
          }
        }
      }
    }

    // Output line with indentation
    insert_indentation(output);
    fputs(line, output);

    // Update indentation level
    for (i = 0; i < len; i++) {
      if (line[i] == '<' && tag[i] != -1 && (i == 0 || line[i - 1] != '!')) {
        if (line[i + 1] == '/') {
          indent -= indent_width;
        } else {
          indent += indent_width;
        }
      }
    }
  }

  fclose(input_file);
  fclose(output);
}

// Test program with multiplayer style
int main() {
  char input_file[20];
  char output_file[20];
  int i;

  printf("Welcome to the HTML Beautifier!\n");
  printf("This program will read an HTML file and output a beautified version of it.\n");

  do {
    printf("\nEnter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    beautify_html(input_file, output_file);

    printf("\nSuccess! The beautified HTML code has been saved to file '%s'.\n", output_file);
    printf("Do you want to beautify another HTML file? (1 for yes, 0 for no): ");
    scanf("%d", &i);
  } while (i != 0);

  printf("\nThank you for using the HTML Beautifier!\n");
  return 0;
}