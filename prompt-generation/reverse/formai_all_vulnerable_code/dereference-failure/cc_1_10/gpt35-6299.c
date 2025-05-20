//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON node structure
typedef struct {
    char *key;
    char *value;
} json_node;

// Define the JSON parser function
void parse_json(char *json_string) {
    char *key = NULL;
    char *value = NULL;
    int key_len = 0;
    int value_len = 0;
    int i = 0;
    int j = 0;

    // Dynamically allocate memory for parsed data
    json_node *data = (json_node *)malloc(sizeof(json_node));

    if (data == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }

    // Loop through the JSON string
    while (json_string[i] != '\0') {
        // Check for the start of a key
        if (json_string[i] == '"') {
            // Move the pointer forward to the start of the key
            i++;

            // Loop through the string to find the end of the key
            while (json_string[i] != '"') {
                key_len++;
                key = (char *)realloc(key, key_len * sizeof(char));
                key[j] = json_string[i];
                j++;
                i++;
            }
            // Add terminating character for key
            key_len++;
            key = (char *)realloc(key, key_len * sizeof(char));
            key[j] = '\0';
            j = 0;
            i++;

            // Skip white space and colon
            while (json_string[i] == ' ' || json_string[i] == ':') {
                i++;
            }

            // Check for the start of a value
            if (json_string[i] == '"') {
                i++;

                // Loop through the string to find the end of the value
                while (json_string[i] != '"') {
                    value_len++;
                    value = (char *)realloc(value, value_len * sizeof(char));
                    value[j] = json_string[i];
                    j++;
                    i++;
                }
                // Add terminating character for value
                value_len++;
                value = (char *)realloc(value, value_len * sizeof(char));
                value[j] = '\0';
                j = 0;
                i++;
            }

            // Add the key and value to the data structure
            data = (json_node *)realloc(data, (i + 1) * sizeof(json_node));
            data[i].key = key;
            data[i].value = value;
            key_len = 0;
            value_len = 0;
            j = 0;
            key = NULL;
            value = NULL;
            i++;
        }
        else {
            i++;
        }
    }

    // Print out the parsed data
    for (i = 0; i < sizeof(data); i++) {
        printf("%s : %s\n", data[i].key, data[i].value);
    }

    // Free allocated memory
    free(key);
    free(value);
    free(data);

}

// Main function
int main(void) {
    char *json_string = "{\"name\": \"John Doe\", \"age\": \"30\", \"city\": \"New York\"}";

    // Call the JSON parser function
    parse_json(json_string);

    return 0;
}