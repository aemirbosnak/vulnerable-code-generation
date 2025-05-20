//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
/*
  XML Parser Example Program
  Written in Dennis Ritchie Style
  
  This program parse and validate an XML file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the XML file
char* read_file(const char* filename) {
  FILE* fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Unable to open %s file\n", filename);
    return NULL;
  }

  // Get file size
  fseek(fp, 0L, SEEK_END);
  int file_size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  char* xml_data = (char*) malloc(file_size);

  if (xml_data == NULL) {
    printf("Memory allocation error\n");
    fclose(fp);
    return NULL;
  }

  fread(xml_data, file_size, 1, fp);

  fclose(fp);

  return xml_data;
}

// Function to parse the XML data
void parse_xml_data(char* xml_data) {
  char* start = xml_data;
  char* end;

  while (*start) {
    // Check if this is a start tag
    if (*start == '<') {
      end = strchr(start, '>');

      if (end == NULL) {
        printf("Invalid XML data format\n");
        return;
      }

      // Check if this is a closing tag
      if (*(start + 1) == '/') {
        printf("Closing tag: %.*s\n", (int) (end - start) - 1, start + 2);
      } else {
        printf("Start tag: %.*s\n", (int) (end - start) - 1, start + 1);
      }

      start = end + 1;
    } else {
      // Check if this is an end tag
      if (*start == '/') {
        end = strchr(start, '>');

        if (end == NULL) {
          printf("Invalid XML data format\n");
          return;
        }

        printf("End tag: %.*s\n", (int) (end - start) - 1, start + 2);

        start = end + 1;
      } else {
        // This is a text data
        end = strchr(start, '<');

        if (end == NULL) {
          printf("Invalid XML data format\n");
          return;
        }

        printf("Text data: %.*s\n", (int) (end - start), start);

        start = end;
      }
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  char* xml_data = read_file(argv[1]);

  if (xml_data == NULL) {
    return 1;
  }

  parse_xml_data(xml_data);

  free(xml_data);

  return 0;
}