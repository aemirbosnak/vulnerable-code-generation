//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

struct xmlElement {
    char* tagName;
    char* attributes;
    char* data;
    int numChildren;
    struct xmlElement* children[SIZE];
};

struct xmlElement* createElement(char* tagName, char* attributes, char* data) {
    struct xmlElement* element = (struct xmlElement*) malloc(sizeof(struct xmlElement));
    element->tagName = tagName;
    element->attributes = attributes;
    element->data = data;
    element->numChildren = 0;
    return element;
}

void addChild(struct xmlElement* parent, struct xmlElement* child) {
    parent->children[parent->numChildren++] = child;
}

void printElement(struct xmlElement* element, int level) {
    for(int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("<%s", element->tagName);
    if(element->attributes) {
        printf(" %s", element->attributes);
    }
    if(element->numChildren == 0 && !element->data) {
        printf("/>\n");
    } else {
        printf(">\n");
        if(element->data) {
            for(int i = 0; i < level+1; i++) {
                printf("\t");
            }
            printf("%s\n", element->data);
        }
        for(int i = 0; i < element->numChildren; i++) {
            printElement(element->children[i], level+1);
        }
        for(int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("</%s>\n", element->tagName);
    }
}

int main() {
    char* xmlString = "<html><head><title>Sample Page</title></head><body><h1>Welcome to my page!</h1><p>This is some sample text.</p></body></html>";
    char* tagName;
    char* attributes;
    char* data;
    struct xmlElement* rootElement = NULL;
    struct xmlElement* currentElement = NULL;
    int inTagName = 0;
    int inAttributes = 0;
    int inData = 0;
    int inQuote = 0;
    char currentChar;
    char attributeBuffer[SIZE];
    int attributeBufferIndex = 0;
    char dataBuffer[SIZE];
    int dataBufferIndex = 0;
    int i = 0;
    while(xmlString[i]) {
        currentChar = xmlString[i];
        if(currentChar == '<' && !inData) {
            inTagName = 1;
            if(currentElement) {
                struct xmlElement* childElement = createElement(tagName, attributes, data);
                addChild(currentElement, childElement);
                currentElement = childElement;
            } else {
                rootElement = createElement(tagName, attributes, data);
                currentElement = rootElement;
            }
            tagName = NULL;
            attributes = NULL;
            data = NULL;
            attributeBufferIndex = 0;
            dataBufferIndex = 0;
        } else if(currentChar == '>' && !inQuote) {
            if(inData) {
                data = (char*) malloc(dataBufferIndex+1);
                strncpy(data, dataBuffer, dataBufferIndex);
                data[dataBufferIndex] = '\0';
                inData = 0;
                dataBufferIndex = 0;
            }
            inTagName = 0;
            inAttributes = 0;
        } else if(currentChar == '/' && xmlString[i+1] == '>') {
            if(inData) {
                data = (char*) malloc(dataBufferIndex+1);
                strncpy(data, dataBuffer, dataBufferIndex);
                data[dataBufferIndex] = '\0';
                inData = 0;
                dataBufferIndex = 0;
            }
            if(currentElement) {
                struct xmlElement* childElement = createElement(tagName, attributes, data);
                addChild(currentElement, childElement);
            } else {
                rootElement = createElement(tagName, attributes, data);
            }
            tagName = NULL;
            attributes = NULL;
            data = NULL;
            attributeBufferIndex = 0;
            dataBufferIndex = 0;
            inTagName = 0;
            inAttributes = 0;
            i++;
        } else if(currentChar == '"' || currentChar == '\'') {
            inQuote = !inQuote;
        } else if(inTagName) {
            if(!tagName) {
                tagName = (char*) malloc(SIZE);
                strncpy(tagName, xmlString+i, 1);
                tagName[1] = '\0';
            } else {
                strncat(tagName, xmlString+i, 1);
            }
        } else if(inAttributes) {
            if(currentChar == '"' || currentChar == '\'') {
                inQuote = !inQuote;
            } else if(currentChar == ' ' && !inQuote) {
                attributeBuffer[attributeBufferIndex++] = '\0';
                if(!attributes) {
                    attributes = (char*) malloc(SIZE);
                    strncpy(attributes, attributeBuffer, attributeBufferIndex);
                    attributes[attributeBufferIndex] = '\0';
                } else {
                    strcat(attributes, " ");
                    strcat(attributes, attributeBuffer);
                }
                attributeBufferIndex = 0;
            } else {
                attributeBuffer[attributeBufferIndex++] = currentChar;
            }
        } else {
            inData = 1;
            dataBuffer[dataBufferIndex++] = currentChar;
        }
        i++;
    }
    printElement(rootElement, 0);
    return 0;
}