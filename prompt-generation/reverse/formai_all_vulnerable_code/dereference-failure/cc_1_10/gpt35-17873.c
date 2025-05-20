//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for storing JSON key-value pairs */
struct json_pair {
  char *key;
  char *value;
};

/* Function to parse JSON object */
struct json_pair *parse_json(char *json_str) {
  int i = 0;
  int j = 0;
  int obj_count = 0;
  int pair_count = 0;
  int is_key = 0;
  int is_value = 0;
  char curr_char = json_str[i];
  char *key_str;
  char *value_str;
  struct json_pair *json_pairs;

  /* Count number of objects */
  while (curr_char != '\0') {
    if (curr_char == '{') {
      obj_count++;
    }
    curr_char = json_str[++i];
  }

  /* Allocate memory for JSON pairs */
  json_pairs = (struct json_pair*) malloc(obj_count * sizeof(struct json_pair));

  /* Parse JSON key-value pairs */
  i = 0;
  curr_char = json_str[i];
  while (obj_count > 0 && curr_char != '\0') {
    if (curr_char == '{') {
      /* New object, reset pair count */
      pair_count = 0;
    } else if (curr_char == '"') {
      /* Start of key or value */
      j = 0;
      if (is_key == 0) {
        /* Reading key */
        is_key = 1;
        key_str = (char*) malloc(100 * sizeof(char));
      } else {
        /* Reading value */
        is_value = 1;
        value_str = (char*) malloc(100 * sizeof(char));
      }
    } else if (curr_char == ':') {
      /* End of key, start of value */
      is_value = 1;
    } else if (curr_char == ',') {
      /* End of value, start of new pair */
      json_pairs[obj_count-1].key = key_str;
      json_pairs[obj_count-1].value = value_str;
      pair_count++;
      is_key = 0;
      is_value = 0;
      if (pair_count < 2) {
        printf("Error: JSON pair has missing key/value\n");
      }
    } else if (curr_char == '}') {
      /* End of object, add final pair */
      json_pairs[obj_count-1].key = key_str;
      json_pairs[obj_count-1].value = value_str;
      pair_count++;
      if (pair_count < 2) {
        printf("Error: JSON pair has missing key/value\n");
      }
      obj_count--;
    } else {
      /* Reading key/value characters */
      if (is_key == 1) {
        key_str[j++] = curr_char;
      } else if (is_value == 1) {
        value_str[j++] = curr_char;
      }
    }
    curr_char = json_str[++i];
  }

  return json_pairs;
}

/* Main function */
int main() {
  char *json_str = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\"}";
  struct json_pair *json_pairs = parse_json(json_str);

  printf("JSON pairs:\n");
  for (int i = 0; i < 3; i++) {
    printf("%s: %s\n", json_pairs[i].key, json_pairs[i].value);
  }

  free(json_pairs);

  return 0;
}