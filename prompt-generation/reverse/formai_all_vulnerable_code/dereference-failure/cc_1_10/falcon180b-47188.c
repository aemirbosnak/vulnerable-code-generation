//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME_LEN 100
#define MAX_NODE_VALUE_LEN 1000

typedef struct {
    char* name;
    char* value;
    struct xml_node* next;
} xml_node;

typedef struct {
    xml_node* head;
    xml_node* tail;
    int count;
} xml_document;

xml_document* xml_create_document() {
    xml_document* doc = (xml_document*)malloc(sizeof(xml_document));
    doc->head = NULL;
    doc->tail = NULL;
    doc->count = 0;
    return doc;
}

void xml_destroy_document(xml_document* doc) {
    xml_node* curr_node = doc->head;
    while (curr_node!= NULL) {
        xml_node* temp_node = curr_node;
        curr_node = curr_node->next;
        free(temp_node->name);
        free(temp_node->value);
        free(temp_node);
    }
    free(doc);
}

xml_node* xml_create_node(char* name, char* value) {
    xml_node* node = (xml_node*)malloc(sizeof(xml_node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

void xml_add_node(xml_document* doc, xml_node* node) {
    if (doc->head == NULL) {
        doc->head = node;
        doc->tail = node;
    } else {
        doc->tail->next = node;
        doc->tail = node;
    }
    doc->count++;
}

void xml_print_document(xml_document* doc) {
    xml_node* curr_node = doc->head;
    while (curr_node!= NULL) {
        printf("<%s>%s</%s>\n", curr_node->name, curr_node->value, curr_node->name);
        curr_node = curr_node->next;
    }
}

int main() {
    char xml_data[] = "<book><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author></book>";
    xml_document* doc = xml_create_document();
    char* token = strtok(xml_data, "<");
    while (token!= NULL) {
        char* name = strtok(NULL, ">");
        char* value = strtok(NULL, "<");
        if (name!= NULL && value!= NULL) {
            xml_node* node = xml_create_node(name, value);
            xml_add_node(doc, node);
        }
        token = strtok(NULL, "<");
    }
    xml_print_document(doc);
    xml_destroy_document(doc);
    return 0;
}