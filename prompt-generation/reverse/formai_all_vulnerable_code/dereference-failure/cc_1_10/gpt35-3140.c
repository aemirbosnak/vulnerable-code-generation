//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the JSON structure
typedef struct JSON {
    struct JSON* parent;
    char* key;
    char* value;
    bool is_object;
    bool is_array;
    int num_children;
    struct JSON** children;
} JSON;

// Helper function to allocate memory for a new JSON element
JSON* new_json() {
    JSON* new = (JSON*) malloc(sizeof(JSON));
    new->parent = NULL;
    new->key = NULL;
    new->value = NULL;
    new->is_object = false;
    new->is_array = false;
    new->num_children = 0;
    new->children = NULL;
    return new;
}

// Helper function to free memory for a JSON element
void free_json(JSON* json) {
    if (json->key != NULL) {
        free(json->key);
    }
    if (json->value != NULL) {
        free(json->value);
    }
    for (int i = 0; i < json->num_children; i++) {
        free_json(json->children[i]);
    }
    if (json->children != NULL) {
        free(json->children);
    }
    free(json);
}

// Helper function to parse a string value from the input
char* parse_string(char* input, int* index) {
    char* value = (char*) malloc(sizeof(char));
    int i = *index;
    int j = 0;
    while (input[i] != '\"') {
        if (input[i] == '\\') {
            // Handle escape characters
            i++;
            switch (input[i]) {
                case '\"':
                    value[j] = '\"';
                    break;
                case '\\':
                    value[j] = '\\';
                    break;
                case '/':
                    value[j] = '/';
                    break;
                case 'b':
                    value[j] = '\b';
                    break;
                case 'f':
                    value[j] = '\f';
                    break;
                case 'n':
                    value[j] = '\n';
                    break;
                case 'r':
                    value[j] = '\r';
                    break;
                case 't':
                    value[j] = '\t';
                    break;
                case 'u':
                    // Not handling Unicode characters in this example
                    value[j] = '?';
                    break;
            }
        } else {
            value[j] = input[i];
        }
        i++;
        j++;
        value = (char*) realloc(value, (j+1)*sizeof(char));
    }
    value[j] = '\0';
    *index = i;
    return value;
}

// Helper function to parse a JSON element from the input
JSON* parse_json(char* input, int* index, JSON* parent) {
    JSON* json = new_json();
    json->parent = parent;
    int i = *index;
    while (input[i] != '\0') {
        if (input[i] == '{') {
            json->is_object = true;
            i++;
            while (input[i] != '}') {
                if (input[i] == '\"') {
                    // Parse key
                    i++;
                    char* key = parse_string(input, &i);
                    json->key = key;
                } else if (input[i] == ':') {
                    // Parse value
                    i++;
                    if (input[i] == '{') {
                        json->children = (JSON**) realloc(json->children, (json->num_children+1)*sizeof(JSON*));
                        json->children[json->num_children] = parse_json(input, &i, json);
                        json->num_children++;
                    } else if (input[i] == '[') {
                        json->is_array = true;
                        json->children = (JSON**) realloc(json->children, (json->num_children+1)*sizeof(JSON*));
                        json->children[json->num_children] = parse_json(input, &i, json);
                        json->num_children++;
                    } else if (input[i] == '\"') {
                        json->value = parse_string(input, &i);
                    } else {
                        // Parse number or boolean
                        int j = i;
                        while (input[j] != ',' && input[j] != '}' && input[j] != ']') {
                            j++;
                        }
                        char* value = (char*) malloc((j-i)*sizeof(char));
                        strncpy(value, input+i, j-i);
                        value[j-i] = '\0';
                        json->value = value;
                        i = j-1;
                    }
                }
                i++;
            }
            *index = i;
        } else if (input[i] == '[') {
            json->is_array = true;
            i++;
            while (input[i] != ']') {
                if (input[i] == '{') {
                    json->children = (JSON**) realloc(json->children, (json->num_children+1)*sizeof(JSON*));
                    json->children[json->num_children] = parse_json(input, &i, json);
                    json->num_children++;
                } else if (input[i] == '\"') {
                    json->children = (JSON**) realloc(json->children, (json->num_children+1)*sizeof(JSON*));
                    json->children[json->num_children] = new_json();
                    json->children[json->num_children]->value = parse_string(input, &i);
                    json->num_children++;
                } else {
                    // Parse number or boolean
                    int j = i;
                    while (input[j] != ',' && input[j] != ']' && input[j] != '}') {
                        j++;
                    }
                    char* value = (char*) malloc((j-i)*sizeof(char));
                    strncpy(value, input+i, j-i);
                    value[j-i] = '\0';
                    json->children = (JSON**) realloc(json->children, (json->num_children+1)*sizeof(JSON*));
                    json->children[json->num_children] = new_json();
                    json->children[json->num_children]->value = value;
                    json->num_children++;
                    i = j-1;
                }
                i++;
            }
            *index = i;
        } else if (input[i] == ',') {
            *index = i;
            return json;
        }
        i++;
    }
    *index = i;
    return json;
}

int main() {
    // Example JSON input
    char* input = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"pets\":[{\"name\":\"Fido\",\"breed\":\"Golden Retriever\"},{\"name\":\"Fluffy\",\"breed\":\"Persian Cat\"}],\"favorite_food\":\"Pizza\"}";

    // Parse the input
    int index = 0;
    JSON* root = parse_json(input, &index, NULL);

    // Print the parsed JSON
    printf("{\n");
    printf("  \"key\": %s,\n", root->key);
    printf("  \"value\": %s,\n", root->value);
    printf("  \"is_object\": %d,\n", root->is_object);
    printf("  \"is_array\": %d,\n", root->is_array);
    printf("  \"num_children\": %d,\n", root->num_children);
    printf("  \"children\": [\n");
    for (int i = 0; i < root->num_children; i++) {
        JSON* child = root->children[i];
        if (child->is_object) {
            printf("    {\n");
            printf("      \"key\": %s,\n", child->key);
            printf("      \"value\": %s,\n", child->value);
            printf("      \"is_object\": %d,\n", child->is_object);
            printf("      \"is_array\": %d,\n", child->is_array);
            printf("      \"num_children\": %d,\n", child->num_children);
            printf("      \"children\": [\n");
            for (int j = 0; j < child->num_children; j++) {
                printf("        {\n");
                printf("          \"key\": %s,\n", child->children[j]->key);
                printf("          \"value\": %s\n", child->children[j]->value);
                if (j == child->num_children-1) {
                    printf("        }\n");
                } else {
                    printf("        },\n");
                }
            }
            if (i == root->num_children-1) {
                printf("      }\n");
            } else {
                printf("      },\n");
            }
        } else if (child->is_array) {
            printf("    {\n");
            printf("      \"key\": %s,\n", child->key);
            printf("      \"value\": %s,\n", child->value);
            printf("      \"is_object\": %d,\n", child->is_object);
            printf("      \"is_array\": %d,\n", child->is_array);
            printf("      \"num_children\": %d,\n", child->num_children);
            printf("      \"children\": [\n");
            for (int j = 0; j < child->num_children; j++) {
                printf("        {\n");
                printf("          \"key\": %s,\n", child->children[j]->key);
                printf("          \"value\": %s\n", child->children[j]->value);
                if (j == child->num_children-1) {
                    printf("        }\n");
                } else {
                    printf("        },\n");
                }
            }
            if (i == root->num_children-1) {
                printf("      }\n");
            } else {
                printf("      },\n");
            }
        } else {
            printf("    {\n");
            printf("      \"key\": %s,\n", child->key);
            printf("      \"value\": %s\n", child->value);
            if (i == root->num_children-1) {
                printf("    }\n");
            } else {
                printf("    },\n");
            }
        }
    }
    printf("  ]\n");
    printf("}\n");

    // Free the parsed JSON
    free_json(root);

    return 0;
}