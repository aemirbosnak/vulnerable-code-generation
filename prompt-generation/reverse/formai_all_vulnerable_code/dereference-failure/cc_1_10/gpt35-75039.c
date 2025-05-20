//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_attribute {
    char* name;
    char* value;
    struct xml_attribute* next;
} xml_attribute;

typedef struct xml_node {
    char* tag;
    char* value;
    xml_attribute* attributes;
    struct xml_node* child;
    struct xml_node* next;
} xml_node;

xml_node* parse_xml(char* xml_string);
xml_attribute* parse_attributes(char* attribute_string);
void free_attributes(xml_attribute* attributes);
void free_nodes(xml_node* node);

xml_node* parse_xml(char* xml_string) {
    xml_node* root = (xml_node*)malloc(sizeof(xml_node));
    root->tag = NULL;
    root->value = NULL;
    root->attributes = NULL;
    root->child = NULL;
    root->next = NULL;
    
    xml_node* current_node = root;
    
    char* token;
    char* current_tag;
    char* current_value;
    char* current_attributes;
    int is_closing_tag = 0;
    int is_self_closing_tag = 0;
    
    token = strtok(xml_string, "<>");
    
    while (token != NULL) {
        if (strcmp(token, "") == 0) {
            token = strtok(NULL, "<>");
            continue;
        }
        
        if (token[0] == '/') {
            is_closing_tag = 1;
            current_tag = strtok(token, "/");
            current_value = NULL;
        } else if (token[strlen(token) - 1] == '/') {
            is_self_closing_tag = 1;
            current_tag = token;
            current_value = NULL;
        } else {
            is_closing_tag = 0;
            is_self_closing_tag = 0;
            current_tag = token;
            current_value = strtok(NULL, "<>");
        }
        
        xml_node* new_node = (xml_node*)malloc(sizeof(xml_node));
        new_node->tag = (char*)malloc(strlen(current_tag) + 1);
        strcpy(new_node->tag, current_tag);
        
        if (current_value != NULL) {
            new_node->value = (char*)malloc(strlen(current_value) + 1);
            strcpy(new_node->value, current_value);
        } else {
            new_node->value = NULL;
        }
        
        if (is_closing_tag) {
            free(new_node);
            current_node = current_node->next;
            continue;
        }
        
        if (is_self_closing_tag) {
            new_node->child = NULL;
            new_node->next = NULL;
            new_node->attributes = parse_attributes(current_tag + 1);
            current_node->next = new_node;
            current_node = new_node;
            continue;
        }
        
        new_node->attributes = parse_attributes(current_value);
        new_node->child = NULL;
        new_node->next = NULL;
        
        if (current_node->child == NULL) {
            current_node->child = new_node;
        } else {
            xml_node* current_child = current_node->child;
            while (current_child->next != NULL) {
                current_child = current_child->next;
            }
            current_child->next = new_node;
        }
        
        current_node = new_node;
        
        token = strtok(NULL, "<>");
    }
    
    return root;
}

xml_attribute* parse_attributes(char* attribute_string) {
    xml_attribute* root = NULL;
    xml_attribute* current_attribute = NULL;
    
    char* token;
    token = strtok(attribute_string, " ");
    
    while (token != NULL) {
        if (strcmp(token, "") == 0) {
            token = strtok(NULL, " ");
            continue;
        }
        
        xml_attribute* new_attribute = (xml_attribute*)malloc(sizeof(xml_attribute));
        new_attribute->name = (char*)malloc(strlen(token) + 1);
        strcpy(new_attribute->name, token);
        
        token = strtok(NULL, " =\"");
        token = strtok(NULL, " =\"");
        
        new_attribute->value = (char*)malloc(strlen(token) + 1);
        strcpy(new_attribute->value, token);
        
        new_attribute->next = NULL;
        
        if (root == NULL) {
            root = new_attribute;
            current_attribute = new_attribute;
        } else {
            current_attribute->next = new_attribute;
            current_attribute = new_attribute;
        }
        
        token = strtok(NULL, " ");
    }
    
    return root;
}

void free_attributes(xml_attribute* attributes) {
    if (attributes == NULL) {
        return;
    }
    
    free_attributes(attributes->next);
    free(attributes->name);
    free(attributes->value);
    free(attributes);
}

void free_nodes(xml_node* node) {
    if (node == NULL) {
        return;
    }
    
    free_nodes(node->child);
    free_nodes(node->next);
    free_attributes(node->attributes);
    free(node->tag);
    free(node->value);
    free(node);
}

int main() {
    char xml_string[] = "<!-- This is a comment -->\n<root attribute1=\"value1\" attribute2=\"value2\"><child><grandchild attribute3=\"value3\">Hello, world!</grandchild></child><selfclosingtag attribute4=\"value4\"/></root>";
    
    xml_node* root = parse_xml(xml_string);
    
    printf("Root tag: %s\n", root->tag);
    printf("Root attribute1: %s\n", root->attributes->value);
    printf("Root attribute2: %s\n", root->attributes->next->value);
    printf("Child tag: %s\n", root->child->tag);
    printf("Grandchild tag: %s\n", root->child->child->tag);
    printf("Grandchild attribute3: %s\n", root->child->child->attributes->value);
    printf("Grandchild value: %s\n", root->child->child->value);
    printf("Self-closing tag attribute4: %s\n", root->child->next->attributes->value);
    
    free_nodes(root);
    
    return 0;
}