//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include<stdio.h>
#include<string.h>

#define MAX_DEPTH 5

int depth = 0;

struct xml_element {
    char tag_name[20];
    char attributes[50];
    char value[1000];
    struct xml_element* child;
};

void print_tabs(int depth) {
    for(int i = 0; i < depth; i++) {
        printf("\t");
    }
}

struct xml_element* create_element(char* tag_name, char* attributes, char* value) {
    struct xml_element* element = (struct xml_element*) malloc(sizeof(struct xml_element));
    strcpy(element->tag_name, tag_name);
    strcpy(element->attributes, attributes);
    strcpy(element->value, value);
    element->child = NULL;

    return element;
}

void parse_element(struct xml_element* element) {
    print_tabs(depth);
    printf("<%s", element->tag_name);

    if(strlen(element->attributes) > 0) {
        printf(" %s", element->attributes);
    }

    if(element->child != NULL) {
        printf(">\n");
        depth++;
        parse_element(element->child);
        depth--;
        print_tabs(depth);
        printf("</%s>\n", element->tag_name);
    } else if(strlen(element->value) > 0) {
        printf(">%s</%s>\n", element->value, element->tag_name);
    } else {
        printf(" />\n");
    }
}

int main() {
    struct xml_element* root = create_element("bookstore", "", "");
    struct xml_element* book1 = create_element("book", "category=\"children\"", "");
    struct xml_element* book2 = create_element("book", "category=\"cooking\"", "");

    book1->child = create_element("title", "", "The Adventures of Tom Sawyer");
    book1->child->child = create_element("author", "", "Mark Twain");
    book2->child = create_element("title", "", "The Joy of Cooking");
    book2->child->child = create_element("author", "", "Irma S. Rombauer");

    root->child = book1;
    book1->child->child->child = book2;

    parse_element(root);
    return 0;
}