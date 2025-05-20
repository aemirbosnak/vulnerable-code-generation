//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 32
#define MAX_ATTRIBUTES_LENGTH 512
#define MAX_ATTRIBUTE_KEY_LENGTH 32
#define MAX_ATTRIBUTE_VALUE_LENGTH 256
#define MAX_NODE_VALUE_LENGTH 1024

typedef struct attribute {
    char key[MAX_ATTRIBUTE_KEY_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
} attribute_t;

typedef struct node {
    char tag[MAX_TAG_LENGTH];
    attribute_t attributes[MAX_ATTRIBUTES_LENGTH];
    size_t num_attributes;
    char value[MAX_NODE_VALUE_LENGTH];
    struct node* children[10];
    size_t num_children;
} node_t;

void xml_parse_node(FILE* fp, node_t* node);
void print_node(node_t* node);

int main() {
    FILE* fp = fopen("example.xml", "r");
    if(!fp) {
        printf("Couldn't open file!\n");
        return 1;
    }

    node_t* root = (node_t*)malloc(sizeof(node_t));
    xml_parse_node(fp, root);

    print_node(root);

    fclose(fp);
    free(root);

    return 0;
}

void xml_parse_node(FILE* fp, node_t* node) {
    char buffer[MAX_TAG_LENGTH] = {0};
    size_t i = 0;

    // Parse tag
    if(fscanf(fp, "<%[^>]> ", buffer) == 1) {
        strncpy(node->tag, buffer, MAX_TAG_LENGTH);

        // Parse attributes
        while(fscanf(fp, "%[^=]=\"%[^\"]\" ", buffer, node->attributes[i].value) == 2) {
            strncpy(node->attributes[i].key, buffer, MAX_ATTRIBUTE_KEY_LENGTH);
            ++i;

            if(i >= MAX_ATTRIBUTES_LENGTH) {
                printf("Too many attributes!\n");
                exit(1);
            }
        }
        node->num_attributes = i;

        // Parse node value
        if(fgets(buffer, MAX_NODE_VALUE_LENGTH, fp)) {
            buffer[strcspn(buffer, "\n")] = '\0'; // remove trailing \n
            strncpy(node->value, buffer, MAX_NODE_VALUE_LENGTH);
        }

        // Parse children
        while(fscanf(fp, "<%[^>]> ", buffer) == 1 && buffer[0] != '/') {
            node_t* child = (node_t*)malloc(sizeof(node_t));
            xml_parse_node(fp, child);
            node->children[node->num_children++] = child;

            if(node->num_children >= 10) {
                printf("Too many children!\n");
                exit(1);
            }
        }
    }
}

void print_node(node_t* node) {
    printf("<%s", node->tag);

    for(size_t i = 0; i < node->num_attributes; ++i) {
        printf(" %s=\"%s\"", node->attributes[i].key, node->attributes[i].value);
    }

    if(node->num_children == 0) {
        if(strlen(node->value) != 0) {
            printf(">%s</%s>\n", node->value, node->tag);
        }
        else {
            printf("/>\n");
        }
    }
    else {
        printf(">\n");
        for(size_t i = 0; i < node->num_children; ++i) {
            print_node(node->children[i]);
        }
        printf("</%s>\n", node->tag);
    }
}