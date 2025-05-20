//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the json data structure
typedef struct {
    char *name;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int count;
} json_object;

// Helper function to remove whitespace from a string
char *strip_whitespace(char *string) {
    char *result = string;
    while (*string != '\0') {
        if (*string != ' ' && *string != '\t' && *string != '\n') {
            *result++ = *string;
        }
        string++;
    }
    *result = '\0';
    return string;
}

// Helper function to parse a json object from a string
json_object *parse_json(char *string) {
    json_object *result = (json_object *)malloc(sizeof(json_object));
    result->count = 0;
    result->pairs = (json_pair *)malloc(sizeof(json_pair) * 10);

    // Strip whitespace from the input string
    strip_whitespace(string);

    // Find the start of the object
    char *start = strchr(string, '{');

    // Loop through the object and parse pairs
    while (*start != '\0') {
        // Find the key
        char *key_start = strchr(start, '\"') + 1;
        char *key_end = strchr(key_start, '\"');
        char *key = (char *)malloc(key_end - key_start + 1);
        strncpy(key, key_start, key_end - key_start);
        key[key_end - key_start] = '\0';

        // Find the value
        char *value_start = strchr(key_end, ':') + 1;
        char *value_end;
        if (*value_start == '\"') {
            // The value is a string
            value_start++;
            value_end = strchr(value_start, '\"');
        } else if (*value_start == '{') {
            // The value is a nested object
            value_start++;
            value_end = strchr(value_start, '}');
        } else {
            // The value is a number
            value_end = value_start;
            while (*value_end >= '0' && *value_end <= '9') {
                value_end++;
            }
        }
        char *value = (char *)malloc(value_end - value_start + 1);
        strncpy(value, value_start, value_end - value_start);
        value[value_end - value_start] = '\0';

        // Add the pair to the object
        json_pair pair = {key, value};
        result->pairs[result->count] = pair;
        result->count++;

        // Move to the next pair
        start = value_end + 1;

        // Check if we've reached the end of the object
        if (*start == '}') {
            break;
        }
    }

    return result;
}

// Main function for testing the json parser
int main() {
    char *json_string = "{\"name\":\"John Doe\",\"age\":25,\"address\":{\"city\":\"New York\",\"state\":\"NY\"}}";
    json_object *object = parse_json(json_string);

    printf("name: %s\n", object->pairs[0].value);
    printf("age: %s\n", object->pairs[1].value);
    printf("city: %s\n", object->pairs[2].value);
    printf("state: %s\n", object->pairs[3].value);

    return 0;
}