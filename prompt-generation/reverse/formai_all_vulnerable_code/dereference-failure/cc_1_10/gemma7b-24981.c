//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        struct JSON_Node* array;
        struct JSON_Node* object;
        char* string;
        int number;
    } data;
} JSON_Node;

JSON_Node* parse_json(char* json_string) {
    JSON_Node* root = NULL;
    int i = 0;
    int state = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (i < MAX_BUFFER_SIZE && json_string[i] != '\0') {
        switch (state) {
            case 0:
                if (json_string[i] == '{') {
                    root = malloc(sizeof(JSON_Node));
                    root->type = 'o';
                    root->data.object = NULL;
                    state = 1;
                } else if (json_string[i] == '[') {
                    root = malloc(sizeof(JSON_Node));
                    root->type = 'a';
                    root->data.array = NULL;
                    state = 2;
                } else if (json_string[i] == '"') {
                    state = 3;
                } else if (json_string[i] == 'n') {
                    state = 4;
                } else if (json_string[i] == ',') {
                    state = 5;
                }
                break;
            case 1:
                if (json_string[i] == '"') {
                    buffer[0] = '\0';
                    strncpy(buffer, json_string + i + 1, MAX_BUFFER_SIZE - 1);
                    root->data.object = malloc(sizeof(JSON_Node));
                    root->data.object->type = 's';
                    root->data.object->data.string = strdup(buffer);
                    state = 0;
                } else if (json_string[i] == '}') {
                    state = 0;
                }
                break;
            case 2:
                if (json_string[i] == '"') {
                    buffer[0] = '\0';
                    strncpy(buffer, json_string + i + 1, MAX_BUFFER_SIZE - 1);
                    root->data.array = malloc(sizeof(JSON_Node));
                    root->data.array->type = 's';
                    root->data.array->data.string = strdup(buffer);
                    state = 0;
                } else if (json_string[i] == ']') {
                    state = 0;
                }
                break;
            case 3:
                buffer[0] = '\0';
                strncpy(buffer, json_string + i + 1, MAX_BUFFER_SIZE - 1);
                root->data.string = strdup(buffer);
                state = 0;
                break;
            case 4:
                buffer[0] = '\0';
                strncpy(buffer, json_string + i + 1, MAX_BUFFER_SIZE - 1);
                root->data.number = atoi(buffer);
                state = 0;
                break;
            case 5:
                if (json_string[i] == ',') {
                    state = 0;
                }
                break;
        }
        i++;
    }

    return root;
}

int main() {
    char* json_string = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node* root = parse_json(json_string);

    printf("Name: %s\n", root->data.object->data.string);
    printf("Age: %d\n", root->data.object->data.number);

    return 0;
}