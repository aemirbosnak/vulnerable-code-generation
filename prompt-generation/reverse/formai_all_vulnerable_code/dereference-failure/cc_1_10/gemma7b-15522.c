//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void parse_json(char *json_string) {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  int state = 0; // 0 for root, 1 for object, 2 for array
  int key_start = -1; // start index of key in object
  int value_start = -1; // start index of value in object

  for (i = 0; buffer[i] = json_string[i]; i++) {
    switch (state) {
      case 0:
        if (buffer[i] == '{') {
          state = 1;
          key_start = i;
        } else if (buffer[i] == '[') {
          state = 2;
          value_start = i;
        }
        break;
      case 1:
        if (buffer[i] == '}') {
          value_start = i;
          printf("Key: %s, Value: %s\n", buffer + key_start, buffer + value_start);
          state = 0;
        } else if (buffer[i] == ',') {
          value_start = i;
          printf("Key: %s, Value: %s\n", buffer + key_start, buffer + value_start);
          key_start = i;
        }
        break;
      case 2:
        if (buffer[i] == ']') {
          state = 0;
        } else if (buffer[i] == ',') {
          value_start = i;
          printf("Value: %s\n", buffer + value_start);
        }
        break;
    }
  }

  free(buffer);
}

int main() {
  char json_string[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
  parse_json(json_string);

  return 0;
}