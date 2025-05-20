//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_attribute xml_attribute;
typedef struct xml_node xml_node;

struct xml_attribute {
    char *name;
    char *value;
    xml_attribute *next;
};

struct xml_node {
    char *name;
    xml_attribute *attributes;
    xml_node *children;
    xml_node *next;
};

xml_node* parse_xml(char *xml);
xml_node* create_node(char *name);
xml_attribute* create_attribute(char *name, char *value);
void parse_children(xml_node *parent, char *xml);
char* extract_tag(char *xml);
char* extract_attribute_name(char *xml, int *length);
char* extract_attribute_value(char *xml, int *length);
char* extract_node_value(char *xml);

int main() {
    char *xml = "<root><person age='30'>John Doe</person><person age='25'>Jane Doe</person></root>";
    xml_node *root = parse_xml(xml);
    printf("Root node: %s\n", root->name);
    xml_node *person = root->children;
    while (person) {
        printf("Person node: %s\n", person->name);
        xml_attribute *age = person->attributes;
        while (age) {
            printf("Age attribute: %s=%s\n", age->name, age->value);
            age = age->next;
        }
        printf("Person value: %s\n", extract_node_value((char *)person->children));
        person = person->next;
    }
    return 0;
}

xml_node* parse_xml(char *xml) {
    xml_node *root = create_node(NULL);
    parse_children(root, xml);
    return root;
}

xml_node* create_node(char *name) {
    xml_node *new_node = (xml_node *) malloc(sizeof(xml_node));
    new_node->name = name;
    new_node->attributes = NULL;
    new_node->children = NULL;
    new_node->next = NULL;
    return new_node;
}

xml_attribute* create_attribute(char *name, char *value) {
    xml_attribute *new_attribute = (xml_attribute *) malloc(sizeof(xml_attribute));
    new_attribute->name = name;
    new_attribute->value = value;
    new_attribute->next = NULL;
    return new_attribute;
}

void parse_children(xml_node *parent, char *xml) {
    while (*xml != '\0') {
        char *tag = extract_tag(xml);
        xml_node *child = create_node(tag);
        xml_attribute *attributes = child->attributes;
        while (*xml != '>') {
            if (*xml == '/') {
                xml++;
                break;
            }
            int name_len;
            char *name = extract_attribute_name(xml, &name_len);
            xml += name_len;
            xml++;
            int value_len;
            char *value = extract_attribute_value(xml, &value_len);
            xml += value_len;
            attributes->next = create_attribute(name, value);
            attributes = attributes->next;
        }
        xml++;
        if (*xml != '/') {
            parse_children(child, xml);
        }
        if (parent->children == NULL) {
            parent->children = child;
        } else {
            xml_node *temp = parent->children;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = child;
        }
        xml += strlen(tag) + 2;
    }
}

char* extract_tag(char *xml) {
    char *start = xml;
    while (*xml != '<') {
        xml++;
    }
    int len = xml - start - 1;
    char *tag = (char *) malloc(len + 1);
    strncpy(tag, start + 1, len);
    tag[len] = '\0';
    return tag;
}

char* extract_attribute_name(char *xml, int *length) {
    char *start = xml;
    while (*xml != '=') {
        xml++;
    }
    *length = xml - start;
    char *name = (char *) malloc(*length + 1);
    strncpy(name, start, *length);
    name[*length] = '\0';
    return name;
}

char* extract_attribute_value(char *xml, int *length) {
    char *start = xml + 1;
    while (*xml != '\"') {
        xml++;
    }
    *length = xml - start;
    char *value = (char *) malloc(*length + 1);
    strncpy(value, start, *length);
    value[*length] = '\0';
    return value;
}

char* extract_node_value(char *xml) {
    char *start = xml;
    while (*xml != '<') {
        xml++;
    }
    int len = xml - start;
    char *value = (char *) malloc(len + 1);
    strncpy(value, start, len);
    value[len] = '\0';
    return value;
}