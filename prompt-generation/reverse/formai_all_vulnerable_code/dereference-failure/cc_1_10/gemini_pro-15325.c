//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Linus Torvalds
// Linus Torvalds style? OK then, here you go...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define some macros to make the code more readable
#define JSON_OBJECT_START "{"
#define JSON_OBJECT_END "}"
#define JSON_ARRAY_START "["
#define JSON_ARRAY_END "]"
#define JSON_COLON ":"
#define JSON_COMMA ","

// And a couple of helper functions
int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// The main JSON parsing function
void parse_json(char *json) {
    // Allocate a buffer for the current token
    char *token = malloc(1024);
    int token_len = 0;

    // Loop through the JSON string character by character
    while (*json) {
        // Skip whitespace
        while (is_whitespace(*json)) {
            json++;
        }

        // Check if we're at the start of an object
        if (*json == JSON_OBJECT_START) {
            printf("Found an object: ");
            json++;

            // Parse the object
            while (*json != JSON_OBJECT_END) {
                // Get the next token
                while (*json && *json != JSON_COLON && *json != JSON_COMMA) {
                    token[token_len++] = *json++;
                }
                token[token_len] = '\0';

                // Print the token
                printf("%s ", token);

                // Get the next character
                json++;

                // Check if the next character is a colon
                if (*json == JSON_COLON) {
                    // Get the next token
                    while (*json && *json != JSON_COMMA && *json != JSON_OBJECT_END) {
                        token[token_len++] = *json++;
                    }
                    token[token_len] = '\0';

                    // Print the token
                    printf("%s ", token);

                    // Get the next character
                    json++;
                }
            }

            // Print a newline
            printf("\n");
        }

        // Check if we're at the start of an array
        else if (*json == JSON_ARRAY_START) {
            printf("Found an array: ");
            json++;

            // Parse the array
            while (*json != JSON_ARRAY_END) {
                // Get the next token
                while (*json && *json != JSON_COMMA && *json != JSON_ARRAY_END) {
                    token[token_len++] = *json++;
                }
                token[token_len] = '\0';

                // Print the token
                printf("%s ", token);

                // Get the next character
                json++;
            }

            // Print a newline
            printf("\n");
        }

        // Check if we're at the start of a string
        else if (*json == '"') {
            // Get the next token
            while (*json && *json != '"') {
                token[token_len++] = *json++;
            }
            token[token_len] = '\0';

            // Print the token
            printf("%s ", token);

            // Get the next character
            json++;
        }

        // Check if we're at the start of a number
        else if (is_digit(*json)) {
            // Get the next token
            while (*json && is_digit(*json)) {
                token[token_len++] = *json++;
            }
            token[token_len] = '\0';

            // Print the token
            printf("%s ", token);
        }

        // Check if we're at the end of the JSON string
        else if (*json == '\0') {
            break;
        }

        // Otherwise, it's an invalid character
        else {
            printf("Invalid character: %c\n", *json);
            break;
        }

        // Reset the token buffer
        token_len = 0;
    }

    // Free the token buffer
    free(token);
}

int main() {
    // Get the JSON string from the user
    char *json = malloc(1024);
    printf("Enter a JSON string: ");
    gets(json);

    // Parse the JSON string
    parse_json(json);

    // Free the JSON string
    free(json);

    return 0;
}