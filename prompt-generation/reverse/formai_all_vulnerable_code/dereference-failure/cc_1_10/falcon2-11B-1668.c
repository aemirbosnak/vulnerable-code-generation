//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUF_SIZE 256

typedef struct node {
    char* key;
    char* value;
    struct node* next;
} node;

typedef struct json_parser {
    node* head;
    node* tail;
    char buffer[BUF_SIZE];
    int len;
    bool is_valid;
} json_parser;

void json_parser_init(json_parser* jp) {
    jp->head = NULL;
    jp->tail = NULL;
    jp->len = 0;
    jp->is_valid = false;
}

void json_parser_push(json_parser* jp, char* key, char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (jp->head == NULL) {
        jp->head = new_node;
        jp->tail = new_node;
    } else {
        jp->tail->next = new_node;
        jp->tail = new_node;
    }

    jp->len++;
}

void json_parser_pop(json_parser* jp) {
    if (jp->len == 0) {
        return;
    }

    node* current = jp->head;
    node* next = current->next;

    if (next == NULL) {
        jp->head = NULL;
        jp->tail = NULL;
    } else {
        jp->head = next;
        jp->tail = next;
    }

    free(current->key);
    free(current->value);
    free(current);

    jp->len--;
}

void json_parser_validate(json_parser* jp) {
    if (jp->len < 2) {
        jp->is_valid = false;
    } else {
        node* current = jp->head;
        node* next = current->next;

        if (strcmp(current->key, "{")) {
            jp->is_valid = false;
        } else if (strcmp(next->key, "}")) {
            jp->is_valid = false;
        } else {
            jp->is_valid = true;
        }
    }
}

int main() {
    json_parser jp;
    json_parser_init(&jp);

    json_parser_push(&jp, "\"name\": \"John\"", "\"age\": 25");
    json_parser_push(&jp, "\"city\": \"New York\"", "\"country\": \"USA\"");

    json_parser_validate(&jp);
    printf("%s\n", jp.buffer);

    json_parser_pop(&jp);
    json_parser_pop(&jp);

    json_parser_validate(&jp);
    printf("%s\n", jp.buffer);

    return 0;
}