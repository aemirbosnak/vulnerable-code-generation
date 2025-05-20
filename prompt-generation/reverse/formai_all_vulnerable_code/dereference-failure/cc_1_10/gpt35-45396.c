//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 50
#define MAX_ATTRIBUTE_NAME_LENGTH 50
#define MAX_ATTRIBUTE_VALUE_LENGTH 100
#define MAX_NUM_ATTRIBUTES 10

// Data structure to represent a single XML tag
typedef struct XmlTag {
    char name[MAX_TAG_NAME_LENGTH];
    int num_attributes;
    char attribute_names[MAX_NUM_ATTRIBUTES][MAX_ATTRIBUTE_NAME_LENGTH];
    char attribute_values[MAX_NUM_ATTRIBUTES][MAX_ATTRIBUTE_VALUE_LENGTH];
    struct XmlTag* children;
    int num_children;
} XmlTag;

// Recursive function to parse an XML file
XmlTag* parseXmlFile(FILE* xml_file) {
    XmlTag* root = (XmlTag*)malloc(sizeof(XmlTag));
    root->num_attributes = 0;
    root->children = NULL;
    root->num_children = 0;

    char current_char;
    char tag_name[MAX_TAG_NAME_LENGTH];
    int tag_name_index = 0;
    char attribute_name[MAX_ATTRIBUTE_NAME_LENGTH];
    int attribute_name_index = 0;
    char attribute_value[MAX_ATTRIBUTE_VALUE_LENGTH];
    int attribute_value_index = 0;
    int in_tag = 0;
    int in_attribute = 0;
    int in_attribute_value = 0;

    while ((current_char = fgetc(xml_file)) != EOF) {
        if (current_char == '<') {
            in_tag = 1;
        }
        else if (in_tag) {
            if (current_char == '/') {
                // End tag - return to parent node
                return root;
            }
            else if (current_char == '>') {
                // End of tag name
                in_tag = 0;
                tag_name[tag_name_index] = '\0';

                XmlTag* new_tag = (XmlTag*)malloc(sizeof(XmlTag));
                strcpy(new_tag->name, tag_name);
                new_tag->num_attributes = 0;
                new_tag->children = NULL;
                new_tag->num_children = 0;

                if (root->children == NULL) {
                    root->children = (XmlTag*)malloc(sizeof(XmlTag));
                }
                else {
                    root->children = (XmlTag*)realloc(root->children, (root->num_children + 1) * sizeof(XmlTag));
                }

                root->children[root->num_children++] = *new_tag;

                free(new_tag);
            }
            else if (current_char == ' ') {
                // Start of an attribute name
                in_attribute = 1;
            }
            else if (in_attribute) {
                if (current_char == '=') {
                    // End of attribute name - now looking for attribute value
                    in_attribute = 0;
                    in_attribute_value = 1;
                    attribute_name[attribute_name_index] = '\0';
                    attribute_name_index = 0;
                }
                else {
                    attribute_name[attribute_name_index++] = current_char;
                }
            }
            else if (in_attribute_value) {
                if (current_char == '\"') {
                    // End of attribute value
                    in_attribute_value = 0;
                    attribute_value[attribute_value_index] = '\0';
                    attribute_value_index = 0;

                    strcpy(root->children[root->num_children - 1].attribute_names[root->children[root->num_children - 1].num_attributes], attribute_name);
                    strcpy(root->children[root->num_children - 1].attribute_values[root->children[root->num_children - 1].num_attributes], attribute_value);
                    root->children[root->num_children - 1].num_attributes++;
                }
                else {
                    attribute_value[attribute_value_index++] = current_char;
                }
            }
            else {
                // Inside tag name
                tag_name[tag_name_index++] = current_char;
            }
        }
    }

    return root;
}

// Recursive function to print an XML tag and any children
void printXmlTag(XmlTag tag, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
    printf("<%s", tag.name);

    for (int i = 0; i < tag.num_attributes; i++) {
        printf(" %s=\"%s\"", tag.attribute_names[i], tag.attribute_values[i]);
    }
    printf(">\n");

    for (int i = 0; i < tag.num_children; i++) {
        printXmlTag(tag.children[i], indent_level + 1);
    }

    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
    printf("</%s>\n", tag.name);
}

int main() {
    FILE* xml_file = fopen("example.xml", "r");

    XmlTag* root = parseXmlFile(xml_file);
    fclose(xml_file);

    printXmlTag(*root, 0);

    return 0;
}