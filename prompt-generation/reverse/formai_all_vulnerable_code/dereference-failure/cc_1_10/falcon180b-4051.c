//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

struct element {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    struct element *next;
};

struct element *head = NULL;

void add_element(char *name, char *value) {
    struct element *new_element = (struct element *)malloc(sizeof(struct element));
    strcpy(new_element->name, name);
    strcpy(new_element->value, value);
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        struct element *current_element = head;
        while (current_element->next!= NULL) {
            current_element = current_element->next;
        }
        current_element->next = new_element;
    }
}

void print_elements() {
    struct element *current_element = head;
    while (current_element!= NULL) {
        printf("Name: %s\nValue: %s\n", current_element->name, current_element->value);
        current_element = current_element->next;
    }
}

int main() {
    FILE *file = fopen("example.xml", "r");
    char line[MAX_VALUE_LEN];
    char *token = NULL;
    char *name = NULL;
    char *value = NULL;
    int in_element = 0;

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_VALUE_LEN, file)!= NULL) {
        if (line[0] == '<') {
            in_element = 1;
            token = strtok(line, " ");
            while (token!= NULL) {
                if (strcmp(token, "name") == 0) {
                    name = strtok(NULL, " ");
                } else if (strcmp(token, "value") == 0) {
                    value = strtok(NULL, " ");
                }
                token = strtok(NULL, " ");
            }
            add_element(name, value);
        } else if (line[0] == '>') {
            in_element = 0;
        }
    }

    if (in_element) {
        printf("Error: Unclosed element\n");
        return 1;
    }

    print_elements();

    return 0;
}