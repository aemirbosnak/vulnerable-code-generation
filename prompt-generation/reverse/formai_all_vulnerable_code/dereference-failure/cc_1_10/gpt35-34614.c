//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
// Let's start by including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure for storing JSON data
typedef struct {
  char *name;
  char *value;
} JsonData;

// Define a function to parse JSON data
JsonData *parse_json(char *data) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  char current_char;
  char current_name[256];
  char current_value[1024];
  JsonData *json_data = (JsonData*) malloc(sizeof(JsonData) * 10);

  // Loop through the string character by character
  while (data[i] != '\0') {
    current_char = data[i];

    // If we encounter a quote, we're starting a JSON object
    if (current_char == '\"') {
      j = i + 1;
      while (data[j] != '\"') {
        current_name[k] = data[j];
        j++;
        k++;
      }
      current_name[k] = '\0';
      k = 0;

      // Skip any whitespace between the object's name and value
      while (isspace(data[j])) {
        j++;
      }

      // If the next character is a colon, we're starting a value
      if (data[j] == ':') {
        j++;
        while (isspace(data[j])) {
          j++;
        }

        // If the value is a string, parse it accordingly
        if (data[j] == '\"') {
          j++;
          while (data[j] != '\"') {
            current_value[l] = data[j];
            j++;
            l++;
          }
          current_value[l] = '\0';
          l = 0;
        } 
        // If the value is not a string, just copy it
        else {
          while (data[j] != ',' && data[j] != '\0') {
            current_value[l] = data[j];
            j++;
            l++;
          }
          current_value[l] = '\0';
          l = 0;
        }
      } 
      else {
        printf("Error: expected colon after object name\n");
        return NULL;
      }

      json_data[k].name = strdup(current_name);
      json_data[k].value = strdup(current_value);
      k++;
    }
    i++;
  }

  // Set a null terminator for the last value 
  json_data[k].name = NULL;
  json_data[k].value = NULL;

  return json_data;
}

// Define a function to print JSON data
void print_json(JsonData *json) {
  int i = 0;
  
  while (json[i].name != NULL && json[i].value != NULL) {
    printf("%s: %s\n", json[i].name, json[i].value);
    i++;
  }
}

int main() {
  char *data = "{\"name\": \"John Smith\", \"age\": 42, \"city\": \"New York\"}";
  JsonData *parsed_data = parse_json(data);

  if (parsed_data == NULL) {
    printf("Error: unable to parse JSON data\n");
  } else {
    print_json(parsed_data);
  }

  return 0;
}