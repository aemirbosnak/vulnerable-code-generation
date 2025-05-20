//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of characters for XML tags

typedef struct {
  char *tag_name;
  char *tag_value;
} xml_tag;

// This function parses an XML file and returns an array of xml_tag structs
xml_tag* parse_xml(char *filename, int *count) {

  // Open the file in read mode
  FILE *file = fopen(filename, "r");

  // Check if the file exists
  if (file == NULL) {
    printf("Error: File not found\n");
    exit(1);
  }

  char buffer[MAX_LENGTH];
  int tag_count = 0;
  xml_tag *tags = NULL;

  // Loop through each line of the file
  while (fgets(buffer, MAX_LENGTH, file) != NULL) {
    char *start = strstr(buffer, "<"); // Search for the start of a tag
    char *end = strstr(buffer, ">"); // Search for the end of a tag

    if (start != NULL && end != NULL) { // If both start and end tags are found
      int tag_length = end - start + 1; // Calculate tag length

      if (tag_length > 2 && tag_length < MAX_LENGTH) { // Check if tag is valid
        xml_tag new_tag;
        new_tag.tag_name = malloc(tag_length); // Allocate memory for tag name
        new_tag.tag_value = malloc(tag_length); // Allocate memory for tag value
        strncpy(new_tag.tag_name, start + 1, tag_length - 2); // Copy tag name to struct
        strncpy(new_tag.tag_value, end + 1, tag_length - 2); // Copy tag value to struct
        tags = realloc(tags, sizeof(xml_tag) * (tag_count + 1)); // Resize array of structs
        tags[tag_count] = new_tag; // Add new tag to array
        tag_count++; // Increment tag count
      }
    }
  }

  fclose(file); // Close the file
  *count = tag_count; // Set count parameter to number of tags

  return tags; // Return array of structs
}

int main() {

  int tag_count;
  xml_tag *tags = parse_xml("example.xml", &tag_count);

  // Print the tags in a funny style
  printf("I parsed %d XML tags! Here they are:\n\n", tag_count);
  for (int i = 0; i < tag_count; i++) {
    printf("Tag #%d: <%s>%s</%s>\n", i+1, tags[i].tag_name, tags[i].tag_value, tags[i].tag_name);
  }

  // Free allocated memory
  for (int i = 0; i < tag_count; i++) {
    free(tags[i].tag_name);
    free(tags[i].tag_value);
  }
  free(tags);

  return 0; // No errors ;)
}