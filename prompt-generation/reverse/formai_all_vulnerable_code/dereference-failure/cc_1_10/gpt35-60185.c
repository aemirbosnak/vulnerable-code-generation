//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char *name;
    char **attributes;
    char **values;
    char *content;
    int num_attributes;
} XmlElement;

typedef struct {
    XmlElement **elements;
    int num_elements;
} XmlDocument;

XmlElement* createXmlElement(char *name) {
    XmlElement *element = malloc(sizeof(XmlElement));
    element->name = name;
    element->attributes = calloc(20, sizeof(char*));
    element->values = calloc(20, sizeof(char*));
    element->content = "";
    element->num_attributes = 0;
    return element;
}

void setAttribute(XmlElement *element, char *attribute, char *value) {
    if (element->num_attributes >= 20) {
        printf("Error: maximum number of attributes exceeded\n");
        return;
    }
    element->attributes[element->num_attributes] = attribute;
    element->values[element->num_attributes] = value;
    element->num_attributes++;
}

void setContent(XmlElement *element, char *content) {
    element->content = content;
}

void freeXmlElement(XmlElement *element) {
    free(element->attributes);
    free(element->values);
    free(element);
}

XmlDocument* createXmlDocument() {
    XmlDocument *document = malloc(sizeof(XmlDocument));
    document->elements = calloc(20, sizeof(XmlElement*));
    document->num_elements = 0;
    return document;
}

void addElement(XmlDocument *document, XmlElement *element) {
    if (document->num_elements >= 20) {
        printf("Error: maximum number of elements exceeded\n");
        return;
    }
    document->elements[document->num_elements] = element;
    document->num_elements++;
}

void freeXmlDocument(XmlDocument *document) {
    for (int i = 0; i < document->num_elements; i++) {
        freeXmlElement(document->elements[i]);
    }
    free(document->elements);
    free(document);
}

void parseElement(char *input, int index, XmlElement *element) {
    int start = index;
    while (input[index] != '>') {
        if (input[index] == '=') {
            char *attribute = calloc(50, sizeof(char));
            char *value = calloc(50, sizeof(char));
            strncpy(attribute, &input[start], index-start);
            index++;
            start = index;
            while (input[index] != '\"') {
                index++;
            }
            strncpy(value, &input[start+1], index-start-1);
            setAttribute(element, attribute, value);
        }
        index++;
    }
    if (input[index-1] == '/') {
        return;
    }
    index++;
    start = index;
    while (strncmp(&input[index], "</", 2) != 0) {
        index++;
    }
    char *content = calloc(100, sizeof(char));
    strncpy(content, &input[start], index-start);
    setContent(element, content);
}

XmlDocument* parseXml(char *input) {
    XmlDocument *document = createXmlDocument();
    int index = 0;
    while (index < strlen(input)) {
        if (strncmp(&input[index], "<", 1) == 0) {
            int start = index;
            while (strncmp(&input[index], ">", 1) != 0) {
                index++;
            }
            char *name = calloc(20, sizeof(char));
            strncpy(name, &input[start+1], index-start-1);
            XmlElement *element = createXmlElement(name);
            parseElement(input, index+1, element);
            addElement(document, element);
            index += strlen(element->content) + strlen(name) + 3;
        } else {
            index++;
        }
    }
    return document;
}

int main() {
    char *input = "<bookstore><book category=\"COOKING\"><title lang=\"en\">Everyday Italian</title><author>Giada De Laurentiis</author><year>2005</year><price>30.00</price></book><book category=\"CHILDREN\"><title lang=\"en\">Harry Potter</title><author>J.K. Rowling</author><year>2005</year><price>29.99</price></book></bookstore>";
    XmlDocument *document = parseXml(input);
    for (int i = 0; i < document->num_elements; i++) {
        printf("element name: %s\n", document->elements[i]->name);
        printf("element content: %s\n", document->elements[i]->content);
        for (int j = 0; j < document->elements[i]->num_attributes; j++) {
            printf("attribute: %s=%s\n", document->elements[i]->attributes[j], document->elements[i]->values[j]);
        }
    }
    freeXmlDocument(document);
    return 0;
}