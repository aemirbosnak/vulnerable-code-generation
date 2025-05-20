//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFERSIZE 1024

typedef struct Element {
    char* name;
    char* content;
    int numOfChild;
    struct Element** childElements;
} Element;

Element* CreateElement(char* name) {
    Element* ele = (Element*)malloc(sizeof(Element));
    ele->content = NULL;
    ele->name = name;
    ele->numOfChild = 0;
    ele->childElements = NULL;
    return ele;
}

void AddChildElement(Element* parent, Element* child) {
    parent->numOfChild++;
    parent->childElements = (Element**)realloc(parent->childElements, parent->numOfChild * sizeof(Element*));
    parent->childElements[parent->numOfChild - 1] = child;
}

void DisplayElement(Element* ele) {
    printf("<%s>", ele->name);
    if (ele->content != NULL) {
        printf("%s", ele->content);
    }
    else if (ele->numOfChild > 0) {
        for (int i = 0; i < ele->numOfChild; i++) {
            DisplayElement(ele->childElements[i]);
        }
    }
    printf("</%s>", ele->name);
}

void ParseElement(Element* ele, char* buffer) {
    char* token;
    if (ele == NULL) {
        ele = CreateElement(strtok(buffer, "<>"));
        ele->content = strtok(NULL, "<>");
        return;
    }
    while (token = strtok(NULL, "<>")) {
        if (token[0] == '/') {
            break;
        }
        else {
            Element* child = CreateElement(token);
            ParseElement(child, NULL);
            AddChildElement(ele, child);
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* filePointer;
    char* buffer = (char*)malloc(sizeof(char) * BUFFERSIZE);

    filePointer = fopen("data.xml", "r");
    if (filePointer == NULL) {
        printf("Cannot open file");
        exit(0);
    }

    Element* rootElement = NULL;

    while (!feof(filePointer)) {
        fgets(buffer, BUFFERSIZE, filePointer);
        ParseElement(rootElement, buffer);
    }

    fclose(filePointer);

    DisplayElement(rootElement);

    free(buffer);
    free(rootElement);
    return 0;
}