//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
}

void parse_json(const char *json) {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    const char *ptr = json;

    while (*ptr) {
        // Find the start of the key
        if (*ptr == '"') {
            ptr++; // Move past the first "
            char *key_start = key;

            while (*ptr != '"' && *ptr != '\0') {
                *key_start++ = *ptr++;
            }
            *key_start = '\0'; // Null-terminate the key
            ptr++; // Move past the closing "

            // Find the colon and skip whitespace
            while (*ptr && *ptr != ':') {
                ptr++;
            }
            ptr++; // Skip the colon

            // Skip whitespace
            while (*ptr && isspace((unsigned char)*ptr)) {
                ptr++;
            }

            if (*ptr == '"') {
                ptr++; // Move past the first "
                char *value_start = value;

                while (*ptr != '"' && *ptr != '\0') {
                    *value_start++ = *ptr++;
                }
                *value_start = '\0'; // Null-terminate the value
                ptr++; // Move past the closing "

                // Output the key-value pair
                printf("Key: %s, Value: %s\n", key, value);
            } else {
                printf("Unexpected format - expected a string value after key: %s\n", key);
                break;
            }
        } else {
            ptr++;
        }
    }
}

int main() {
    char json_input[MAX_JSON_SIZE];

    printf("Welcome to the JSON Parser!\n");
    printf("Please enter a JSON string (max %d characters):\n", MAX_JSON_SIZE);
    
    // Get user input
    if (fgets(json_input, sizeof(json_input), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(json_input);
        if (len > 0 && json_input[len - 1] == '\n') {
            json_input[len - 1] = '\0';
        }
        
        // Trim any excess whitespace
        trim_whitespace(json_input);
        
        printf("Parsing the JSON string: %s\n", json_input);
        parse_json(json_input);
    } else {
        printf("An error occurred while reading input.\n");
    }
  
    printf("Thank you for using the surprise JSON Parser! 🎉\n");
    return 0;
}