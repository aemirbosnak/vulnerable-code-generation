//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME_LEN 100
#define MAX_NODE_VALUE_LEN 200

typedef struct {
    char name[MAX_NODE_NAME_LEN];
    char value[MAX_NODE_VALUE_LEN];
    struct node *next;
} node;

typedef struct {
    node *head;
} xml_doc;

node *create_node(char *name, char *value) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

xml_doc *create_xml_doc() {
    xml_doc *new_doc = (xml_doc *)malloc(sizeof(xml_doc));
    new_doc->head = NULL;
    return new_doc;
}

void add_node(xml_doc *doc, node *new_node) {
    if (doc->head == NULL) {
        doc->head = new_node;
    } else {
        node *curr_node = doc->head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void print_node(node *curr_node) {
    printf("name: %s, value: %s\n", curr_node->name, curr_node->value);
}

void print_xml_doc(xml_doc *doc) {
    node *curr_node = doc->head;
    while (curr_node!= NULL) {
        print_node(curr_node);
        curr_node = curr_node->next;
    }
}

int main() {
    xml_doc *doc = create_xml_doc();
    char xml_str[] = "<root><child name=\"John\">Doe</child></root>";
    int len = strlen(xml_str);
    int i = 0;
    while (i < len) {
        if (xml_str[i] == '<') {
            int j = i + 1;
            while (xml_str[j]!= '>') {
                j++;
            }
            char *name = (char *)malloc((j - i - 1) * sizeof(char));
            strncpy(name, &xml_str[i + 1], j - i - 2);
            name[j - i - 2] = '\0';
            char *value = (char *)malloc((len - j) * sizeof(char));
            strncpy(value, &xml_str[j + 1], len - j - 1);
            value[len - j - 1] = '\0';
            node *new_node = create_node(name, value);
            add_node(doc, new_node);
            free(name);
            free(value);
        }
        i++;
    }
    print_xml_doc(doc);
    return 0;
}