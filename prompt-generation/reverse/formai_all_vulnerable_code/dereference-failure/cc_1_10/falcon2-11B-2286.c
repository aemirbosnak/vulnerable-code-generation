//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_node {
    char* key;
    char* value;
    struct json_node* next;
} json_node;

json_node* parse_json(FILE* fp) {
    json_node* head = NULL;
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, ":");

        json_node* new_node = malloc(sizeof(json_node));
        new_node->key = strdup(key);
        new_node->value = strdup(value);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            json_node* current = head;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    return head;
}

void print_json(json_node* head) {
    json_node* current = head;
    while (current!= NULL) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    FILE* fp = fopen("sample.json", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    json_node* head = parse_json(fp);
    print_json(head);

    fclose(fp);
    free(head);

    return 0;
}