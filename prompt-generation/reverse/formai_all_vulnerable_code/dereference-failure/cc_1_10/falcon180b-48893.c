//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT_SIZE 1024

typedef struct element {
    char *name;
    char *value;
    struct element *next;
} element_t;

typedef struct {
    element_t *head;
    element_t *tail;
} element_list_t;

element_list_t *create_element_list(void) {
    element_list_t *list = (element_list_t *) malloc(sizeof(element_list_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_element(element_list_t *list, char *name, char *value) {
    element_t *elem = (element_t *) malloc(sizeof(element_t));
    elem->name = strdup(name);
    elem->value = strdup(value);
    elem->next = NULL;

    if (list->tail == NULL) {
        list->head = elem;
        list->tail = elem;
    } else {
        list->tail->next = elem;
        list->tail = elem;
    }
}

void print_element_list(element_list_t *list) {
    element_t *elem = list->head;

    while (elem!= NULL) {
        printf("Name: %s\nValue: %s\n", elem->name, elem->value);
        elem = elem->next;
    }
}

void destroy_element_list(element_list_t *list) {
    element_t *elem = list->head;

    while (elem!= NULL) {
        free(elem->name);
        free(elem->value);
        free(elem);
        elem = elem->next;
    }

    free(list);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer = NULL;
    size_t buffer_size = 0;
    char *line = NULL;
    size_t line_size = 0;
    element_list_t *element_list = create_element_list();

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &line_size, file))!= -1) {
        buffer = realloc(buffer, buffer_size + strlen(line));
        strcat(buffer, line);
        buffer_size += strlen(line);
        buffer[buffer_size - 1] = '\0';
    }

    fclose(file);

    char *token = strtok(buffer, "<");

    while (token!= NULL) {
        char *name = strtok(token, " ");
        char *value = strtok(NULL, " ");
        add_element(element_list, name, value);

        token = strtok(NULL, "<");
    }

    print_element_list(element_list);

    destroy_element_list(element_list);

    return 0;
}