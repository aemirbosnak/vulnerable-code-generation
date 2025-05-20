//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256
#define MAX_ATTRIBUTE_COUNT 10
#define MAX_TAG_NAME_LENGTH 20

typedef struct xmlAttribute {
    char* name;
    char* value;
} xmlAttribute;

typedef struct xmlNode {
    char* tag_name;
    xmlAttribute* attributes[MAX_ATTRIBUTE_COUNT];
    int attribute_count;
    char* text;
    struct xmlNode** children;
    int child_count;
} xmlNode;

char* read_file(char* filename) {
    FILE* fp;
    char* buffer = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Unable to open file %s.", filename);
        exit(1);
    }
    fgets(buffer, MAX_BUFFER_SIZE, fp);
    fclose(fp);
    return buffer;
}

xmlAttribute* create_attribute(char* name, char* value) {
    xmlAttribute* attr = (xmlAttribute*)malloc(sizeof(xmlAttribute));
    attr->name = name;
    attr->value = value;
    return attr;
}

xmlNode* create_node(char* tag_name) {
    xmlNode* node = (xmlNode*)malloc(sizeof(xmlNode));
    node->tag_name = tag_name;
    node->attribute_count = 0;
    node->text = NULL;
    node->child_count = 0;
    return node;
}

void add_attribute(xmlNode* node, xmlAttribute* attribute) {
    if (node->attribute_count < MAX_ATTRIBUTE_COUNT) {
        node->attributes[node->attribute_count] = attribute;
        node->attribute_count++;
    }
}

void set_text(xmlNode* node, char* text) {
    node->text = text;
}

void add_child(xmlNode* parent, xmlNode* child) {
    parent->children = (xmlNode**)realloc(parent->children, (parent->child_count + 1) * sizeof(xmlNode*));
    parent->children[parent->child_count++] = child;
}

xmlNode* parse_xml(char* xml_string) {
    xmlNode* current_node = NULL;
    xmlNode* root_node = NULL;
    int i, j;
    char* tag_name = NULL;
    char* attribute_name = NULL;
    char* attribute_value = NULL;
    char* text = NULL;
    int in_tag = 0;
    int in_attribute_name = 0;
    int in_attribute_value = 0;
    int in_text = 0;
    xmlAttribute* attribute = NULL;

    for (i = 0; i < strlen(xml_string); i++) {
        if (xml_string[i] == '<') {
            in_tag = 1;
            in_text = 0;
            if (xml_string[i + 1] == '/') {
                current_node = (xmlNode*)current_node - 1;
            }
            else {
                tag_name = (char*)malloc(MAX_TAG_NAME_LENGTH * sizeof(char));
                for (j = i + 1; j < strlen(xml_string); j++) {
                    if (xml_string[j] == '>') {
                        tag_name[j - i - 1] = '\0';
                        break;
                    }
                    tag_name[j - i - 1] = xml_string[j];
                }
                current_node = create_node(tag_name);
                if (root_node == NULL) {
                    root_node = current_node;
                }
            }
        }
        else if (xml_string[i] == '=') {
            in_attribute_name = 0;
            in_attribute_value = 1;
        }
        else if (xml_string[i] == '"') {
            if (in_attribute_value) {
                in_attribute_value = 0;
                attribute_value[strlen(attribute_value) - 1] = '\0';
                attribute = create_attribute(attribute_name, attribute_value + 1);
                add_attribute(current_node, attribute);
            }
            else {
                in_attribute_name = 1;
            }
        }
        else if (xml_string[i] == ' ' || xml_string[i] == '/') {
            if (in_attribute_value) {
                attribute_value[strlen(attribute_value) - 1] = '\0';
                attribute = create_attribute(attribute_name, attribute_value + 1);
                add_attribute(current_node, attribute);
            }
            in_attribute_name = 1;
            in_attribute_value = 0;
        }
        else if (xml_string[i] == '>') {
            in_tag = 0;
            if (in_text) {
                in_text = 0;
                text[strlen(text) - 1] = '\0';
                set_text(current_node, text + 1);
            }
        }
        else {
            if (in_tag) {
                if (in_attribute_name) {
                    attribute_name = (char*)realloc(attribute_name, (strlen(attribute_name) + 1) * sizeof(char));
                    attribute_name[strlen(attribute_name)] = xml_string[i];
                }
                else if (in_attribute_value) {
                    attribute_value = (char*)realloc(attribute_value, (strlen(attribute_value) + 1) * sizeof(char));
                    attribute_value[strlen(attribute_value)] = xml_string[i];
                }
                else {
                    in_text = 1;
                    if (text == NULL) {
                        text = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
                    }
                    else {
                        text = (char*)realloc(text, (strlen(text) + 1) * sizeof(char));
                    }
                    text[strlen(text)] = xml_string[i];
                }
            }
        }
    }
    return root_node;
}

int main() {
    char* xml_string = read_file("example.xml");
    xmlNode* root_node = parse_xml(xml_string);
    printf("Root node tag name: %s\n", root_node->tag_name);
    printf("Root node attribute count: %d\n", root_node->attribute_count);
    printf("Root node text: %s\n", root_node->text);
    printf("Root node child count: %d\n", root_node->child_count);
    return 0;
}