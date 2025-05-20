//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store a JSON object
typedef struct JsonObject {
    char *key;
    char *value;
} JsonObject;

// Function to parse a JSON object
void parseJson(char *jsonStr) {
    int len = strlen(jsonStr);
    int i = 0;
    int j = 0;
    JsonObject jsonObj;

    // Loop through the JSON string
    while (i < len) {
        switch (jsonStr[i]) {
            // If the character is a quote, parse the key string
            case '\"':
                i++;
                j = 0;
                while (jsonStr[i] != '\"') {
                    jsonObj.key[j] = jsonStr[i];
                    i++;
                    j++;
                }
                jsonObj.key[j] = '\0';
                break;

            // If the character is a colon, parse the value string
            case ':':
                i++;
                j = 0;
                while (isspace(jsonStr[i])) {
                    i++;
                }
                while (jsonStr[i] != ',' && jsonStr[i] != '}') {
                    jsonObj.value[j] = jsonStr[i];
                    i++;
                    j++;
                }
                jsonObj.value[j] = '\0';
                printf("Key: %s, Value: %s\n", jsonObj.key, jsonObj.value);
                break;

            // Ignore whitespace and commas
            case ' ':
            case '\n':
            case '\r':
            case '\t':
            case ',':
                break;

            // Ignore braces and brackets for now
            case '{':
            case '}':
            case '[':
            case ']':
                break;

            // Unexpected character
            default:
                printf("Unexpected character: %c\n", jsonStr[i]);
                break;
        }

        i++;
    }
}

// Test the JSON parser with a sample JSON string
int main() {
    char *jsonStr = "{\"name\": \"John Doe\", \"age\": 28, \"isMarried\": false}";

    parseJson(jsonStr);

    return 0;
}