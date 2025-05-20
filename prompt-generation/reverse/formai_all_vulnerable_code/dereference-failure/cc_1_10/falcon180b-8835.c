//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_CHILDREN 50
#define MAX_ATTRIBUTES 10

typedef struct element {
    char name[MAX_ELEMENTS];
    int num_children;
    struct element *children[MAX_CHILDREN];
    int num_attributes;
    struct attribute *attributes[MAX_ATTRIBUTES];
} Element;

typedef struct attribute {
    char name[MAX_ELEMENTS];
    char value[MAX_ELEMENTS];
} Attribute;

Element *create_element(char *name) {
    Element *element = malloc(sizeof(Element));
    strcpy(element->name, name);
    element->num_children = 0;
    element->num_attributes = 0;
    return element;
}

Element *add_child(Element *parent, Element *child) {
    parent->children[parent->num_children++] = child;
    return child;
}

Attribute *add_attribute(Element *element, char *name, char *value) {
    Attribute *attribute = malloc(sizeof(Attribute));
    strcpy(attribute->name, name);
    strcpy(attribute->value, value);
    element->attributes[element->num_attributes++] = attribute;
    return attribute;
}

void print_element(Element *element, int level) {
    printf("%*s<%s", level*4, "", element->name);
    for (int i = 0; i < element->num_attributes; i++) {
        Attribute *attribute = element->attributes[i];
        printf(" %s=\"%s\"", attribute->name, attribute->value);
    }
    printf(">\n");
    for (int i = 0; i < element->num_children; i++) {
        print_element(element->children[i], level+1);
    }
    if (element->num_children == 0 && element->num_attributes == 0) {
        printf("%*s</%s>\n", level*4, "", element->name);
    }
}

int main() {
    Element *root = create_element("root");
    Element *child1 = create_element("child1");
    Element *child2 = create_element("child2");
    add_child(root, child1);
    add_child(root, child2);
    add_attribute(root, "attribute1", "value1");
    add_attribute(child1, "attribute2", "value2");
    add_attribute(child2, "attribute3", "value3");
    print_element(root, 0);
    return 0;
}