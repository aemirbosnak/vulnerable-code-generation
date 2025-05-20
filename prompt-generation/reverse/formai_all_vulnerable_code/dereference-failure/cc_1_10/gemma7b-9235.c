//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct JsonParser {
    Node *root;
    char **parse_string;
    int parse_string_length;
} JsonParser;

JsonParser *jsonParser_init(char **parse_string, int parse_string_length) {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->root = NULL;
    parser->parse_string = parse_string;
    parser->parse_string_length = parse_string_length;
    return parser;
}

void jsonParser_parse(JsonParser *parser) {
    char *string_start = parser->parse_string;
    char **keys = NULL;
    int keys_length = 0;
    char **values = NULL;
    int values_length = 0;

    // Parse the JSON string
    while (*string_start) {
        // Detect key-value pairs
        if (*string_start == '"') {
            keys = realloc(keys, (keys_length + 1) * sizeof(char *));
            keys[keys_length++] = strdup(string_start + 1);
        }
        // Detect commas
        else if (*string_start == ',') {
            values = realloc(values, (values_length + 1) * sizeof(char *));
            values[values_length++] = strdup(string_start + 1);
        }
        // Detect closing brace
        else if (*string_start == '}') {
            // Create a node
            Node *node = malloc(sizeof(Node));
            node->data = malloc(values_length * sizeof(char *));
            node->next = NULL;

            for (int i = 0; i < values_length; i++) {
                node->data[i] = strdup(values[i]);
            }

            if (parser->root == NULL) {
                parser->root = node;
            } else {
                parser->root->next = node;
            }

            keys_length = 0;
            values_length = 0;
        }

        string_start++;
    }
}

int main() {
    char **parse_string = malloc(100 * sizeof(char));
    parse_string[0] = "{";
    parse_string[1] = "\"name\": \"John Doe\",";
    parse_string[2] = "\"age\": 30}";
    parse_string[3] = "";

    JsonParser *parser = jsonParser_init(parse_string, 4);
    jsonParser_parse(parser);

    Node *node = parser->root;
    while (node) {
        printf("Key: %s, Value: %s\n", node->data[0], node->data[1]);
        node = node->next;
    }

    return 0;
}