//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSON_Node *array;
        struct JSON_Node *object;
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
                current->data.string = malloc(100);
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
            case ' ':
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

    while (head) {
        switch (head->type) {
            case 's':
                printf("String: %s\n", head->data.string);
                break;
            case 'n':
                printf("Number: %d\n", head->data.number);
                break;
        }
        head = head->next;
    }

    return 0;
}