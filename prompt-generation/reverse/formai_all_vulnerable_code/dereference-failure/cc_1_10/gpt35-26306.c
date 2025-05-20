//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1024

typedef struct {
    char* name;
    char* content;
    int level;
} Element;

typedef struct {
    Element* elements;
    int size;
    int capacity;
} ElementArray;

void add_element(ElementArray* array, Element* element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->elements = realloc(array->elements, sizeof(Element) * array->capacity);
    }
    array->elements[array->size++] = *element;
}

void free_elements(ElementArray* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->elements[i].name);
        free(array->elements[i].content);
    }
    free(array->elements);
    array->size = 0;
    array->capacity = 0;
}

void parse_element(char* line, Element* element, int level) {
    element->level = level;
    char* start_tag = strchr(line, '<');
    char* end_tag = strchr(start_tag, '>');

    int name_size = end_tag - start_tag - 1;
    element->name = malloc(sizeof(char) * (name_size + 1));
    strncpy(element->name, start_tag + 1, name_size);
    element->name[name_size] = '\0';

    char* content_start = end_tag + 1;
    char* content_end = strchr(content_start, '<');
    int content_size = content_end - content_start;
    element->content = malloc(sizeof(char) * (content_size + 1));
    strncpy(element->content, content_start, content_size);
    element->content[content_size] = '\0';
}

void print_element(Element* element) {
    printf("%*c<%s>%s</%s>\n", element->level * 4, ' ', element->name, element->content, element->name);
}

void print_elements(ElementArray* array) {
    for (int i = 0; i < array->size; i++) {
        print_element(&array->elements[i]);
    }
}

int main() {
    ElementArray array = { NULL, 0, 0 };

    FILE* file = fopen("example.xml", "r");
    char line[MAX_STRING_SIZE];

    int level = 0;
    while (fgets(line, MAX_STRING_SIZE, file)) {
        Element element;
        parse_element(line, &element, level);
        add_element(&array, &element);

        if (strchr(element.content, '<') != NULL) {
            level++;
        }
        if (strchr(element.content, '>') != NULL) {
            level--;
        }
    }

    fclose(file);

    print_elements(&array);

    free_elements(&array);

    return 0;
}