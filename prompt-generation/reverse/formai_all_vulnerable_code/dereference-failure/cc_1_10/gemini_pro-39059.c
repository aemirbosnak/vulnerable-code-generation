//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

// Function to remove leading whitespace from a string
char *ltrim(char *s)
{
  while (*s && isspace(*s))
    s++;
  return s;
}

// Function to remove trailing whitespace from a string
char *rtrim(char *s)
{
  char *end = s + strlen(s) - 1;
  while (end >= s && isspace(*end))
    end--;
  *(end + 1) = '\0';
  return s;
}

// Function to beautify HTML code
char *beautify_html(char *html)
{
  // Allocate memory for the beautified HTML code
  char *beautified_html = malloc(strlen(html) * 2);
  if (!beautified_html)
    return NULL;

  // Initialize the beautifier
  int indent_level = 0;
  char *line_start = html;
  char *line_end;

  // Iterate over each line of HTML code
  while (line_start)
  {
    // Find the end of the current line
    line_end = strchr(line_start, '\n');
    if (!line_end)
      line_end = html + strlen(html);

    // Remove leading and trailing whitespace from the line
    char *line = rtrim(ltrim(line_start));

    // Add the appropriate indentation to the line
    for (int i = 0; i < indent_level; i++)
      strcat(beautified_html, "  ");

    // Append the line to the beautified HTML code
    strcat(beautified_html, line);

    // Increment the indent level if the line is a start tag
    if (strstr(line, "<") && strstr(line, ">"))
      indent_level++;

    // Decrement the indent level if the line is an end tag
    if (strstr(line, "</"))
      indent_level--;

    // Move to the next line
    line_start = line_end + 1;
  }

  // Return the beautified HTML code
  return beautified_html;
}

// Main function
int main(int argc, char *argv[])
{
  // Check if the user provided an input file
  if (argc != 2)
  {
    printf("Usage: %s input_file\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read the input file into a string
  FILE *fp = fopen(argv[1], "r");
  if (!fp)
  {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);
  char *html = malloc(file_size + 1);
  if (!html)
  {
    perror("Error allocating memory for HTML code");
    return EXIT_FAILURE;
  }
  fread(html, 1, file_size, fp);
  fclose(fp);

  // Beautify the HTML code
  char *beautified_html = beautify_html(html);
  if (!beautified_html)
  {
    perror("Error beautifying HTML code");
    return EXIT_FAILURE;
  }

  // Print the beautified HTML code to the console
  printf("%s", beautified_html);

  // Free the allocated memory
  free(html);
  free(beautified_html);

  return EXIT_SUCCESS;
}