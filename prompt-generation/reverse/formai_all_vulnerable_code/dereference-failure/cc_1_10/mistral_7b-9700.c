//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//-------------------------------------------------------------------------
// Functions
//-------------------------------------------------------------------------

int parse_name(char **line) {
  char *name_start = *line;
  char name[100];
  int len = 0;

  // Skip whitespace
  while (isspace(**line)) (*line)++;

  // Parse name
  while (!isspace(**line) && **line && len < 100) {
    name[len++] = **line++;
  }

  name[len] = '\0';
  *line -= len;

  printf("Name: %s\n", name);
  return len + 1;
}

int parse_address(char **line) {
  char *address_start = *line;
  int len = 0;

  // Skip "Address:" or "Addresses:"
  while (strncmp(*line, "Address: ", 7) && strncmp(*line, "Addresses: ", 9)) (*line)++;
  *line += 7; // Address:
  *line += strlen(": ");

  // Parse address
  while (!isspace(**line) && **line && len < 100) {
    (*line)++;
    len++;
  }

  printf("Address: %.*s\n", len, *line - len - address_start);
  *line -= len;

  return len + 1;
}

int parse_phone(char **line) {
  char *phone_start = *line;
  char phone[20];
  int len = 0;

  // Skip "Phone:" or "Phones:"
  while (strncmp(*line, "Phone: ", 6) && strncmp(*line, "Phones: ", 7)) (*line)++;
  *line += 6; // Phone:
  *line += strlen(": ");

  // Parse phone
  while (isdigit(**line) && **line && len < 20) {
    phone[len++] = **line++;
  }

  phone[len] = '\0';
  printf("Phone: %s\n", phone);

  return len + 1;
}

//-------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------

int main() {
  FILE *file = fopen("resume.txt", "r");
  char line[1024] = {};
  char *line_ptr = line;

  if (file) {
    while (fgets(line, sizeof(line), file)) {
      int pos = 0;
      int parsed_len = 0;

      // Name
      pos = parse_name(&line_ptr);
      parsed_len += pos;

      // Address
      pos = parse_address(&line_ptr);
      parsed_len += pos;

      // Phone
      pos = parse_phone(&line_ptr);
      parsed_len += pos;

      // Print remaining text
      printf("Remaining text: %.*s\n", (int)(sizeof(line) - parsed_len), line);
    }

    fclose(file);
  } else {
    printf("Error opening file.\n");
  }

  return 0;
}