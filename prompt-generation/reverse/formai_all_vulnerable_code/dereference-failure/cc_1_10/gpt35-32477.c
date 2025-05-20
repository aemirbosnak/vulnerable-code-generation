//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a JSON string and return a key-value pair
char* parse_json(char* json_string, char* key) {
    char* value = NULL;

    // Search for the given key within the JSON string
    char* key_location = strstr(json_string, key);

    // If the key is found, extract the value
    if (key_location != NULL) {
        // Move the pointer to the beginning of the value
        char* value_location = key_location + strlen(key);

        // Skip any leading white space
        while (*value_location == ' ' || *value_location == '\n'
                || *value_location == '\t' || *value_location == ':') {
            value_location++;
        }

        // Check if the value is a string
        if (*value_location == '\"') {
            // Extract the string by finding the closing quote
            char* end_quote = strchr(value_location + 1, '\"');
            if (end_quote != NULL) {
                int string_length = end_quote - value_location - 1;
                value = (char*) malloc(string_length + 1);
                strncpy(value, value_location + 1, string_length);
                value[string_length] = '\0';
            }
        }
        // Check if the value is a number
        else if (*value_location >= '0' && *value_location <= '9') {
            // Extract the number by finding the end of the numeric string
            char* end_number = value_location;
            while ((*end_number >= '0' && *end_number <= '9')
                    || *end_number == '.') {
                end_number++;
            }
            int number_length = end_number - value_location;
            value = (char*) malloc(number_length + 1);
            strncpy(value, value_location, number_length);
            value[number_length] = '\0';
        }
    }

    return value;
}

int main() {
    // Example JSON string
    char* json_string = "{ \"name\": \"John Smith\", \"age\": 30, \"city\": \"New York\" }";

    // Get the value for the "name" key
    char* name = parse_json(json_string, "name");
    printf("Name: %s\n", name);

    // Get the value for the "age" key
    char* age = parse_json(json_string, "age");
    printf("Age: %s\n", age);

    // Get the value for the "city" key
    char* city = parse_json(json_string, "city");
    printf("City: %s\n", city);

    free(name);
    free(age);
    free(city);

    return 0;
}