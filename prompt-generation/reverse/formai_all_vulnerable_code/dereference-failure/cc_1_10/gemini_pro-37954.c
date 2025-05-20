//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function takes a character array as input and returns a new character array with all leading and trailing whitespace removed.
char* trim(char* str) {
  char* start = str;
  while (*start == ' ' || *start == '\t') {
    start++;
  }
  char* end = str + strlen(str) - 1;
  while (*end == ' ' || *end == '\t') {
    end--;
  }
  int len = end - start + 1;
  char* newstr = malloc(len + 1);
  strncpy(newstr, start, len);
  newstr[len] = '\0';
  return newstr;
}

// This function takes a character array as input and returns a new character array with all HTML tags removed.
char* strip_tags(char* str) {
  char* newstr = malloc(strlen(str) + 1);
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] == '<') {
      while (str[i] != '>' && str[i] != '\0') {
        i++;
      }
      if (str[i] == '\0') {
        break;
      }
    } else {
      newstr[j++] = str[i++];
    }
  }
  newstr[j] = '\0';
  return newstr;
}

// This function takes a character array as input and returns a new character array with all whitespace characters replaced with a single space character.
char* collapse_whitespace(char* str) {
  char* newstr = malloc(strlen(str) + 1);
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
      if (j > 0 && newstr[j - 1] != ' ') {
        newstr[j++] = ' ';
      }
    } else {
      newstr[j++] = str[i];
    }
    i++;
  }
  newstr[j] = '\0';
  return newstr;
}

// This function takes a character array as input and returns a new character array with all lines of text indented by two spaces.
char* indent(char* str) {
  char* newstr = malloc(strlen(str) * 2 + 1);
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n') {
      newstr[j++] = str[i++];
      newstr[j++] = ' ';
      newstr[j++] = ' ';
    } else {
      newstr[j++] = str[i++];
    }
  }
  newstr[j] = '\0';
  return newstr;
}

// This function takes a character array as input and returns a new character array with all HTML attributes removed.
char* strip_attributes(char* str) {
  char* newstr = malloc(strlen(str) + 1);
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ' && str[i + 1] == '=' && str[i + 2] == '"') {
      i += 3;
      while (str[i] != '"') {
        i++;
      }
      i++;
    } else {
      newstr[j++] = str[i++];
    }
  }
  newstr[j] = '\0';
  return newstr;
}

int main() {
  // Read the HTML code from a file.
  FILE* fp = fopen("input.html", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char* html = malloc(fsize + 1);
  fread(html, 1, fsize, fp);
  fclose(fp);

  // Beautify the HTML code.
  char* trimmed = trim(html);
  char* stripped_tags = strip_tags(trimmed);
  char* collapsed_whitespace = collapse_whitespace(stripped_tags);
  char* indented = indent(collapsed_whitespace);
  char* stripped_attributes = strip_attributes(indented);

  // Write the beautified HTML code to a file.
  fp = fopen("output.html", "w");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  fwrite(stripped_attributes, 1, strlen(stripped_attributes), fp);
  fclose(fp);

  // Free the allocated memory.
  free(html);
  free(trimmed);
  free(stripped_tags);
  free(collapsed_whitespace);
  free(indented);
  free(stripped_attributes);

  return EXIT_SUCCESS;
}