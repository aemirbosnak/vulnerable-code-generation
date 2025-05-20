//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: modular
/* C Program to parse an XML file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* value;
} element;

typedef struct {
    element** elements;
    int num_elements;
} node;

bool read_next_token(char** input, char* token, int token_length) {
    char curr_char;
    int curr_pos = 0;

    // skip whitespace
    while (isspace(**input)) {
        (*input)++;
    }

    // check for end of token
    if (**input == '<') {
        token[curr_pos] = '<';
        curr_pos++;
        (*input)++;
    }
    else {
        return false;
    }

    // read tag name
    while (isalnum(**input)) {
        token[curr_pos] = **input;
        curr_pos++;
        (*input)++;
    }

    token[curr_pos] = '\0';
    return true;
}

bool parse_element(char** input, element* elem) {
    char* token = malloc(256 * sizeof(char));

    if (read_next_token(input, token, 256)) {
        // check for closing tag
        if (token[1] == '/') {
            free(token);
            return false;
        }
        else {
            elem->name = token;
            elem->value = malloc(256 * sizeof(char));

            // read element value
            char curr_char;
            int curr_pos = 0;
            while (**input != '<') {
                elem->value[curr_pos] = **input;
                curr_pos++;
                (*input)++;
            }
            elem->value[curr_pos] = '\0';
            return true;
        }
    }

    free(token);
    return false;
}

bool parse_node(char** input, node* node) {
    node->elements = malloc(256 * sizeof(element*));

    int num_elements = 0;

    while (true) {
        element* elem = malloc(sizeof(element));
        bool success = parse_element(input, elem);

        if (!success) {
            free(elem);
            break;
        }
        else {
            node->elements[num_elements] = elem;
            num_elements++;
        }
    }

    node->num_elements = num_elements;

    return true;
}

node* parse_xml(char* input) {
    node* root = malloc(sizeof(node));
    parse_node(&input, root);
    return root;
}

int main() {
    char* input = "<root><name>John</name><age>23</age></root>";
    node* root = parse_xml(input);

    for (int i = 0; i < root->num_elements; i++) {
        element* elem = root->elements[i];
        printf("Element %d: %s=%s\n", i, elem->name, elem->value);
    }

    return 0;
}