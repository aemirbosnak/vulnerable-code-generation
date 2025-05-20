//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 50
#define MAX_TAG_VALUE_LENGTH 100

typedef struct xml_element_t {
    char tag_name[MAX_TAG_NAME_LENGTH];
    char tag_value[MAX_TAG_VALUE_LENGTH];
    struct xml_attribute_t* attributes;
    struct xml_element_t* children;
} xml_element;

typedef struct xml_attribute_t {
    char* name;
    char* value;
    struct xml_attribute_t* next;
} xml_attribute;

int parse_xml_element(xml_element* parent, char* xml_string, int index);
int parse_xml_attribute(xml_attribute** head, char* xml_string, int index);
void free_xml_element(xml_element* element);
void free_xml_attributes(xml_attribute* attributes);

xml_element* parse_xml(char* xml_string) {
    int index = 0;
    xml_element* root_element = calloc(1, sizeof(xml_element));
    parse_xml_element(root_element, xml_string, index);
    return root_element;
}

int parse_xml_element(xml_element* parent, char* xml_string, int index) {
    int i = index;
    int j = 0;
    while (xml_string[i] != '<') {
        i++;
    }
    i++;
    if (xml_string[i] == '/') {
        // end tag
        i++;
        while (xml_string[i] != '>') {
            i++;
        }
        return i + 1;
    }
    // start tag
    while (xml_string[i] != ' ' && xml_string[i] != '>') {
        parent->tag_name[j++] = xml_string[i++];
    }
    parent->tag_name[j] = '\0';

    // attributes
    xml_attribute* attributes = NULL;
    i = parse_xml_attribute(&attributes, xml_string, i);

    parent->attributes = attributes;
    if (xml_string[i] == '>') {
        // no children
        i++;
        parent->tag_value[0] = '\0';
        return i;
    }

    // children
    xml_element* children = calloc(1, sizeof(xml_element));
    parent->children = children;
    while (1) {
        i = parse_xml_element(children, xml_string, i);
        if (xml_string[i] == '/') {
            // end tag with no value
            i += 2;
            return i;
        }
        children->tag_value[0] = '\0';
        children->children = calloc(1, sizeof(xml_element));
        children = children->children;
    }

    return i;
}

int parse_xml_attribute(xml_attribute** head, char* xml_string, int index) {
    int i = index;
    while (xml_string[i] != '>') {
        if (xml_string[i] == ' ') {
            i++;
            int j = i;
            while (xml_string[i] != '=') {
                i++;
            }
            xml_string[i++] = '\0';
            char* attribute_name = &xml_string[j];

            j = i;
            while (xml_string[i] != '\"') {
                i++;
            }
            i++;
            while (xml_string[i] != '\"') {
                i++;
            }
            xml_string[i++] = '\0';
            char* attribute_value = &xml_string[j];

            xml_attribute* attribute = calloc(1, sizeof(xml_attribute));
            attribute->name = attribute_name;
            attribute->value = attribute_value;
            if (*head == NULL) {
                *head = attribute;
            } else {
                xml_attribute* current = *head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = attribute;
            }
        } else {
            i++;
        }
    }
    return i;
}

void free_xml_element(xml_element* element) {
    if (element == NULL) {
        return;
    }
    free_xml_attributes(element->attributes);
    free_xml_element(element->children);
    free(element);
}

void free_xml_attributes(xml_attribute* attributes) {
    if (attributes == NULL) {
        return;
    }
    free(attributes->name);
    free(attributes->value);
    free_xml_attributes(attributes->next);
    free(attributes);
}

int main() {
    char* xml_string = "<root>\n"
                       "    <person name=\"Alice\" age=\"25\">\n"
                       "        <email>alice@example.com</email>\n"
                       "    </person>\n"
                       "    <person name=\"Bob\" age=\"30\">\n"
                       "        <email>bob@example.com</email>\n"
                       "    </person>\n"
                       "</root>";

    xml_element* root_element = parse_xml(xml_string);
    printf("Root element tag name: %s\n", root_element->tag_name);

    xml_element* person_element = root_element->children;
    while (person_element != NULL) {
        printf("Person element tag name: %s\n", person_element->tag_name);
        xml_attribute* attribute = person_element->attributes;
        while (attribute != NULL) {
            printf("    %s=\"%s\"\n", attribute->name, attribute->value);
            attribute = attribute->next;
        }
        xml_element* email_element = person_element->children;
        while (email_element != NULL) {
            printf("    Email element tag name: %s\n", email_element->tag_name);
            printf("    Email element tag value: %s\n", email_element->tag_value);
            email_element = email_element->children;
        }
        person_element = person_element->children->children;
    }

    free_xml_element(root_element);
    return 0;
}