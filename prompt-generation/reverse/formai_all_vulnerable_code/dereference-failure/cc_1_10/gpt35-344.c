//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* tag;
    char* content;
} Element;

void parseXML(char* xml, Element* elements, int* numElements) {
    char* tagStart = NULL;
    char* tagEnd = NULL;
    char* contentStart = NULL;
    char* contentEnd = NULL;
    
    int numTags = 0;
    
    while (*xml) {
        if (*xml == '<') {
            tagStart = xml + 1;
            while (*xml != '>') {
                xml++;
            }
            tagEnd = xml;
            int tagLen = tagEnd - tagStart;
            
            if (*(xml - 1) != '/') {
                contentStart = xml + 1;
                while (*xml != '<') {
                    xml++;
                }
                contentEnd = xml - 1;
            }
            
            Element e = {
                .tag = (char*) calloc(tagLen + 1, sizeof(char)),
                .content = NULL,
            };
            
            memcpy(e.tag, tagStart, tagLen);
            
            if (contentStart != NULL && contentStart < contentEnd) {
                int contentLen = contentEnd - contentStart + 1;
                e.content = (char*) calloc(contentLen + 1, sizeof(char));
                memcpy(e.content, contentStart, contentLen);
            }
            
            elements[numTags++] = e;
        }
        xml++;
    }
    
    *numElements = numTags;
}

void printElements(Element* elements, int numElements) {
    for (int i = 0; i < numElements; i++) {
        printf("[%s] - %s\n", elements[i].tag, elements[i].content);
    }
}

int main() {
    char* xml = "<person><name>John Doe</name><age>25</age></person>";
    Element elements[3];
    int numElements = 0;
    
    parseXML(xml, elements, &numElements);
    
    printElements(elements, numElements);
    
    return 0;
}