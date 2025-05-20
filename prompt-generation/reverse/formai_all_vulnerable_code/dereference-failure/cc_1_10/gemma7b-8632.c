//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSON_Node *object;
        struct JSON_Node *array;
    } data;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *current = NULL;
    int i = 0;

    while (json_string[i] != '\0') {
        switch (json_string[i]) {
            case '"':
                current = malloc(sizeof(JSON_Node));
                current->type = 's';
                current->data.string = malloc(MAX_BUFFER);
                i++;
                while (json_string[i] != '"') {
                    current->data.string[i - 1] = json_string[i];
                    i++;
                }
                current->data.string[i - 1] = '\0';
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case '{' :
                current = malloc(sizeof(JSON_Node));
                current->type = 'o';
                current->data.object = NULL;
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case '[' :
                current = malloc(sizeof(JSON_Node));
                current->type = 'a';
                current->data.array = NULL;
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case ',':
            case ':':
            case ']':
            case '}':
                i++;
                break;
            default:
                current = malloc(sizeof(JSON_Node));
                current->type = 'n';
                current->data.number = json_string[i] - '0';
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                i++;
                break;
        }
    }

    return head;
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *head = parse_json(json_string);

    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);

    return 0;
}