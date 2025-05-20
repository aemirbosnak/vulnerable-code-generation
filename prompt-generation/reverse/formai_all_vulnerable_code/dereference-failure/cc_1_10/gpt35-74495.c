//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 50
#define MAX_ATTRIBUTE_SIZE 50
#define MAX_ATTRIBUTE_VALUE_SIZE 100
#define MAX_CHILDREN 50
#define MAX_DATA_SIZE 100

typedef struct Attribute {
    char key[MAX_ATTRIBUTE_SIZE];
    char value[MAX_ATTRIBUTE_VALUE_SIZE];
} Attribute;

typedef struct Node {
    char tag[MAX_TAG_SIZE];
    Attribute attributes[MAX_CHILDREN];
    int num_attributes;
    struct Node* children[MAX_CHILDREN];
    int num_children;
    char data[MAX_DATA_SIZE];
} Node;

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(size + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);
    return buffer;
}

void parse_attributes(char* attribute_string, Node* node) {
    char* key_value = strtok(attribute_string, "\" ");
    while (key_value) {
        strcpy(node->attributes[node->num_attributes].key, key_value);
        key_value = strtok(NULL, "\" ");
        strcpy(node->attributes[node->num_attributes].value, key_value);
        node->num_attributes++;
        key_value = strtok(NULL, "\" ");
    }
}

void parse_node(char* node_string, Node* parent) {
    char* token = strtok(node_string, "<>");
    Node* curr_node = NULL;
    char* attribute_string = NULL;
    while (token) {
        if (token[0] == '/') {
            return;
        } else {
            if (token[0] != ' ' && token[0] != '\n' && token[0] != '\r') {
                curr_node = (Node*)malloc(sizeof(Node));
                parent->children[parent->num_children++] = curr_node;
                strcpy(curr_node->tag, token);
                attribute_string = strstr(token, " ");
                if (attribute_string) {
                    attribute_string++;
                    parse_attributes(attribute_string, curr_node);
                }
            } else {
                if (curr_node) {
                    if (!curr_node->data[0]) {
                        strcpy(curr_node->data, token);
                    }
                } else {
                    if (!parent->data[0]) {
                        strcpy(parent->data, token);
                    }
                }
            }
        }
        token = strtok(NULL, "<>");
    }
}

Node* parse_xml(const char* xml_string) {
    Node* root = NULL;
    Node* curr_node = NULL;
    char* token = strtok(xml_string, "<>");
    while (token) {
        if (token[0] == '/') {
            curr_node = curr_node->children[0];
        } else {
            if (token[0] != ' ' && token[0] != '\n' && token[0] != '\r') {
                Node* new_node = (Node*)malloc(sizeof(Node));
                if (!root) {
                    root = new_node;
                } else {
                    curr_node->children[curr_node->num_children++] = new_node;
                }
                strcpy(new_node->tag, token);
                char* attribute_string = strstr(token, " ");
                if (attribute_string) {
                    attribute_string++;
                    parse_attributes(attribute_string, new_node);
                }
                curr_node = new_node;
            } else {
                if (curr_node) {
                    if (!curr_node->data[0]) {
                        strcpy(curr_node->data, token);
                    }
                }
            }
        }
        token = strtok(NULL, "<>");
    }
    return root;
}

void print_node(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("<%s", node->tag);
    for (int i = 0; i < node->num_attributes; i++) {
        printf(" %s=\"%s\"", node->attributes[i].key, node->attributes[i].value);
    }
    printf(">\n");

    if (node->data[0]) {
        for (int i = 0; i < depth + 1; i++) {
            printf(" ");
        }
        printf("%s\n", node->data);
    }

    for (int i = 0; i < node->num_children; i++) {
        print_node(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("</%s>\n", node->tag);
}

int main() {
    char* xml_string = read_file("example.xml");
    if (!xml_string) {
        return 1;
    }

    Node* root = parse_xml(xml_string);
    if (!root) {
        return 1;
    }

    print_node(root, 0);

    free(xml_string);
    return 0;
}