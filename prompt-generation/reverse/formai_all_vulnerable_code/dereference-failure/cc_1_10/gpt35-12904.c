//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME 50
#define MAX_ATTR_NAME 50
#define MAX_ATTR_VALUE 100
#define MAX_NODE_VALUE 100

typedef struct Attribute {
    char name[MAX_ATTR_NAME];
    char value[MAX_ATTR_VALUE];
} Attribute;

typedef struct Node {
    char name[MAX_NODE_NAME];
    char value[MAX_NODE_VALUE];
    Attribute* attributes;
    int num_attributes;
    struct Node* children;
    int num_children;
} Node;

void free_node(Node* node);
Node* parse_node(char* xml, int* index);
char* get_attribute_value(Node* node, char* attr_name);
void print_attributes(Node* node);
void print_nodes(Node* node);
Node* find_node_by_name(Node* root, char* name);

void free_node(Node* node) {
    if (node->attributes) {
        free(node->attributes);
    }
    if (node->children) {
        for (int i = 0; i < node->num_children; i++) {
            free_node(node->children + i);
        }
        free(node->children);
    }
}

Node* parse_node(char* xml, int* index) {
    Node* node = calloc(1, sizeof(*node));
    int i = *index;
    int j;
    
    // get node name
    for (j = 0; xml[i] != '>' && xml[i] != ' ' && j < MAX_NODE_NAME; i++, j++) {
        node->name[j] = xml[i];
    }
    node->name[j] = '\0';
    
    // get attributes
    while (xml[i] != '>') {
        // skip spaces
        while (xml[i] == ' ') {
            i++;
        }
        // check if attribute
        if (xml[i] != '/') {
            node->num_attributes++;
            node->attributes = realloc(node->attributes, sizeof(*node->attributes) * node->num_attributes);
            Attribute* attr = &node->attributes[node->num_attributes - 1];
            // get attribute name
            for (j = 0; xml[i] != '=' && xml[i] != ' ' && j < MAX_ATTR_NAME; i++, j++) {
                attr->name[j] = xml[i];
            }
            attr->name[j] = '\0';
            // skip spaces and =
            while (xml[i] == ' ' || xml[i] == '=') {
                i++;
            }
            // check if value in double quotes
            if (xml[i] == '\"') {
                i++;
                // get attribute value
                for (j = 0; xml[i] != '\"' && j < MAX_ATTR_VALUE; i++, j++) {
                    attr->value[j] = xml[i];
                }
                attr->value[j] = '\0';
                i++;
            }
        }
        else {
            break;
        }
    }
    
    // check if self-closing tag
    i++;
    if (xml[i] == '/') {
        i += 2;
        return node;
    }
    
    // get node value
    int k = 0;
    node->num_children = 0;
    node->children = NULL;
    while (xml[i] != '<') {
        node->value[k++] = xml[i++];
    }
    node->value[k] = '\0';
    
    // get child nodes
    while (xml[i] == '<') {
        // check if closing tag
        if (xml[i + 1] == '/') {
            i += strlen(node->name) + 2;
            break;
        }
        i++;
        Node* child = parse_node(xml, &i);
        node->num_children++;
        node->children = realloc(node->children, sizeof(*node->children) * node->num_children);
        node->children[node->num_children - 1] = *child;
        free(child);
    }
    
    *index = i;
    return node;
}

char* get_attribute_value(Node* node, char* attr_name) {
    for (int i = 0; i < node->num_attributes; i++) {
        if (strcmp(node->attributes[i].name, attr_name) == 0) {
            return node->attributes[i].value;
        }
    }
    return NULL;
}

void print_attributes(Node* node) {
    for (int i = 0; i < node->num_attributes; i++) {
        printf("%s=\"%s\" ", node->attributes[i].name, node->attributes[i].value);
    }
}

void print_nodes(Node* node) {
    printf("<%s ", node->name);
    print_attributes(node);
    if (node->num_children == 0 && strlen(node->value) == 0) {
        printf("/>\n");
    }
    else {
        printf(">\n");
        if (strlen(node->value) > 0) {
            printf("%s\n", node->value);    
        }
        for (int i = 0; i < node->num_children; i++) {
            print_nodes(&node->children[i]);
        }
        printf("</%s>\n", node->name);
    }
}

Node* find_node_by_name(Node* root, char* name) {
    if (strcmp(root->name, name) == 0) {
        return root;
    }
    for (int i = 0; i < root->num_children; i++) {
        Node* node = find_node_by_name(&root->children[i], name);
        if (node != NULL) {
            return node;
        }
    }
    return NULL;
}

int main() {
    char xml[] = "<animals>\n"
                 "    <dog breed=\"golden retreiver\">\n"
                 "        <name>Max</name>\n"
                 "        <age>3</age>\n"
                 "    </dog>\n"
                 "    <cat breed=\"siamese\">\n"
                 "        <name>Fluffy</name>\n"
                 "        <age>5</age>\n"
                 "    </cat>\n"
                 "</animals>\n";
    
    int index = 0;
    Node* root = parse_node(xml, &index);
    
    Node* dog_node = find_node_by_name(root, "dog");
    char* dog_breed = get_attribute_value(dog_node, "breed");
    printf("Dog's breed: %s\n", dog_breed);
    
    print_nodes(root);
    
    free_node(root);
    return 0;
}