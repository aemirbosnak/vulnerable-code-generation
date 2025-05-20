//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Element;

typedef struct {
    Element elements[MAX_ELEMENTS];
    int numElements;
} XMLParser;

XMLParser* createXMLParser() {
    XMLParser* parser = (XMLParser*) malloc(sizeof(XMLParser));
    parser->numElements = 0;
    return parser;
}

void destroyXMLParser(XMLParser* parser) {
    for (int i = 0; i < parser->numElements; i++) {
        free(parser->elements[i].name);
        free(parser->elements[i].value);
    }
    free(parser);
}

void addElement(XMLParser* parser, char* name, char* value) {
    if (parser->numElements >= MAX_ELEMENTS) {
        printf("Error: Too many elements.\n");
        return;
    }
    Element element;
    strcpy(element.name, name);
    strcpy(element.value, value);
    parser->elements[parser->numElements++] = element;
}

void printElements(XMLParser* parser) {
    for (int i = 0; i < parser->numElements; i++) {
        printf("%s = %s\n", parser->elements[i].name, parser->elements[i].value);
    }
}

int main() {
    XMLParser* parser = createXMLParser();
    addElement(parser, "name", "John Doe");
    addElement(parser, "age", "30");
    addElement(parser, "city", "New York");
    printElements(parser);
    destroyXMLParser(parser);
    return 0;
}