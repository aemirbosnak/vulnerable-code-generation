//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct json_node {
    char* name;
    char* value;
    struct json_node* next;
} JSONNode;

typedef struct json_obj {
    JSONNode* head;
} JSONObject;

void printJSONObject(JSONObject* object) {
    JSONNode* current = object->head;
    printf("{\n");
    while (current != NULL) {
        printf("\t%s: %s,\n", current->name, current->value);
        current = current->next;
    }
    printf("}\n");
}

JSONObject* parseXML(char* xml) {
    JSONObject* object = malloc(sizeof(JSONObject));
    object->head = NULL;

    // Assume XML input is structured like this:
    // <person>
    //     <name>John Smith</name>
    //     <age>30</age>
    // </person>

    // Parse XML tags and values
    char* start_tag = "<";
    char* end_tag = ">";
    char* start_tag_close = "</";
    char* end_tag_close = ">";

    char* current = xml;

    while (*current != '\0') {
        char* name = NULL;
        char* value = NULL;

        if (strncmp(current, start_tag, strlen(start_tag)) == 0) {
            // Found a tag
            current += strlen(start_tag);
            if (*current == '/') {
                // Tag is being closed
                current += strlen(start_tag_close);
            } else {
                // Tag is being opened
                name = current;
                while (*current != '\0' && strncmp(current, end_tag, strlen(end_tag)) != 0) {
                    current++;
                }
                *current = '\0';
                current++;

                // Recursively parse nested XML tags
                JSONObject* sub_object = parseXML(current);

                // Add sub-object to current object
                JSONNode* sub_node = malloc(sizeof(JSONNode));
                sub_node->name = name;
                sub_node->value = NULL;
                sub_node->next = sub_object->head;
                object->head = sub_node;
            }
        } else {
            // Found a value
            value = current;
            while (*current != '\0' && strncmp(current, start_tag_close, strlen(start_tag_close)) != 0) {
                current++;
            }
            *current = '\0';
            current++;

            // Add name-value pair to current object
            JSONNode* node = malloc(sizeof(JSONNode));
            node->name = name;
            node->value = value;
            node->next = object->head;
            object->head = node;
        }        
    }

    return object;
}

int main() {
    char* xml = "<person><name>John Smith</name><age>30</age></person>";
    JSONObject* object = parseXML(xml);
    printJSONObject(object);
    return 0;
}