//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1024
#define MAX_OBJ_DEPTH 10

typedef enum {OBJ, ARR} JsonType;

typedef struct {
    JsonType type;  // Type of the JSON object
    char *key;      // Key of the object being parsed
    char *value;    // Value of the object being parsed
    int level;      // Depth level of the object
} JSON;

int parse_object(char *json, int start, JSON *parsed_json, int level);

int parse_array(char *json, int start, JSON *parsed_json, int level) {
    int i = start + 1;    // Skipping the opening bracket
    char *value;          // Temporary storage for value of each element in array

    while (json[i] != ']') {
        value = malloc(MAX_STRING_LEN);
        memset(value, 0, MAX_STRING_LEN);

        // Parsing each element in the array
        if (parse_object(json, i, parsed_json, level+1)) {
            free(value);
            return -1;  // Error Parsing
        }

        parsed_json->type = ARR;    // Setting the object type
        parsed_json->value = value; // Setting the object value
        printf("%*s\"%d\": (%s)\n", parsed_json->level*4, "", i, parsed_json->value); // Displaying parsed object

        i += strlen(parsed_json->value) + 1; // Moving the index to the next element

        free(value);    // Freeing the temporary storage
    }

    return i;
}

int parse_object(char *json, int start, JSON *parsed_json, int level) {
    int i = start + 1;    // Skipping the opening brace
    parsed_json->level = level; // Setting the depth level of the object

    char *key;            // Temporary storage for key of the object
    char *value;          // Temporary storage for value of the object

    // Parsing key of the object
    key = malloc(MAX_STRING_LEN);
    memset(key, 0, MAX_STRING_LEN);
    while (json[i] != ':') {
        strncat(key, &json[i], 1); // Appending each character to the key
        i++;
    }

    parsed_json->key = key;   // Setting the object key

    // Parsing value of the object
    value = malloc(MAX_STRING_LEN);
    memset(value, 0, MAX_STRING_LEN);
    i += 2; // Skipping the colon and opening quote
    while (json[i] != '\"') {
        strncat(value, &json[i], 1); // Appending each character to the value
        i++;
    }

    parsed_json->value = value; // Setting the object value
    parsed_json->type = OBJ;    // Setting the object type

    printf("%*s\"%s\": (%s)\n", level*4, "", parsed_json->key, parsed_json->value); // Displaying parsed object

    // Parsing sub-objects
    if (json[i+1] == '{') {
        if (parse_object(json, i+1, parsed_json, level+1)) {
            return -1;  // Error Parsing the sub-object
        }
        i += strlen(parsed_json->value) + 1;
    }

    // Parsing sub-arrays
    else if (json[i+1] == '[') {
        if (parse_array(json, i+1, parsed_json, level+1)) {
            return -1;  // Error Parsing the sub-array
        }
        i += strlen(parsed_json->value) + 1;
    }

    return i;
}

int main() {
    char json[] = "{\n"
                  "    \"name\": \"John\",\n"
                  "    \"age\": 30,\n"
                  "    \"city\": \"New York\",\n"
                  "    \"pets\": [\n"
                  "        {\n"
                  "            \"type\": \"Dog\",\n"
                  "            \"name\": \"Fido\",\n"
                  "            \"age\": 3\n"
                  "        },\n"
                  "        {\n"
                  "            \"type\": \"Cat\",\n"
                  "            \"name\": \"Tom\",\n"
                  "            \"age\": 5\n"
                  "        }\n"
                  "    ]\n"
                  "}";

    JSON parsed_json;
    memset(&parsed_json, 0, sizeof(JSON));

    // Parsing the JSON string
    if (parse_object(json, 0, &parsed_json, 0)) {
        printf("Error parsing JSON!\n");
        return -1;
    }

    return 0;
}