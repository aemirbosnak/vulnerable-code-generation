//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 256
#define MAX_JSON_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair pairs[MAX_JSON_LENGTH / 2]; // Arbitrary limit for pairs
    int count;
} JSONParser;

void init_parser(JSONParser *parser) {
    parser->count = 0;
}

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

int parse_json(const char *json, JSONParser *parser) {
    const char *ptr = json;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int in_key = 1, in_value = 0;
    int k_idx = 0, v_idx = 0;

    while (*ptr) {
        // Skip whitespace
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        // Check for quotes indicating string start
        if (*ptr == '"') {
            ptr++;
            if (in_key) {
                in_key = 0;
                k_idx = 0;
                while (*ptr && *ptr != '"') {
                    if (k_idx < MAX_KEY_LENGTH - 1) {
                        key[k_idx++] = *ptr;
                    }
                    ptr++;
                }
                key[k_idx] = '\0';
                in_value = 1;
            } else if (in_value) {
                in_value = 0;
                v_idx = 0;
                while (*ptr && *ptr != '"') {
                    if (v_idx < MAX_VALUE_LENGTH - 1) {
                        value[v_idx++] = *ptr;
                    }
                    ptr++;
                }
                value[v_idx] = '\0';
                // Store the key-value pair in the parser
                if (parser->count < MAX_JSON_LENGTH / 2) {
                    strcpy(parser->pairs[parser->count].key, key);
                    strcpy(parser->pairs[parser->count].value, value);
                    parser->count++;
                }
            }
        }
        ptr++;
    }

    return parser->count > 0; // Returns true if at least one pair was parsed
}

void print_json(const JSONParser *parser) {
    for (int i = 0; i < parser->count; i++) {
        printf("Key: %s, Value: %s\n", parser->pairs[i].key, parser->pairs[i].value);
    }
}

int main() {
    JSONParser parser;
    init_parser(&parser);
    
    char json_input[MAX_JSON_LENGTH];

    printf("Enter a JSON-like string (key-value pairs in format \"key\":\"value\"): ");
    fgets(json_input, sizeof(json_input), stdin);
    
    // Remove the potential newline character at the end
    json_input[strcspn(json_input, "\n")] = 0;

    // Trim input (just in case)
    trim_whitespace(json_input);

    if (parse_json(json_input, &parser)) {
        printf("Parsed JSON:\n");
        print_json(&parser);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}