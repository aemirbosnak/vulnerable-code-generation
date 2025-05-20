//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct {
    char* name;
    char** attributes;
    int attributeCount;
} xmlTag;

void parseTag(char* input, xmlTag* tag) {
    char* currentToken;
    char* parsedToken;

    currentToken = strtok(input, "<>");

    if (currentToken != NULL && currentToken[0] != '/') {
        tag->name = strdup(currentToken);
    }

    while (currentToken != NULL) {
        if (currentToken[0] == '/') {
            break;
        }

        parsedToken = strdup(currentToken);

        tag->attributes = (char**)realloc(tag->attributes, sizeof(char*) * (tag->attributeCount));
        tag->attributes[(tag->attributeCount)] = parsedToken;

        (tag->attributeCount)++;
        currentToken = strtok(NULL, " \"'/<>");
    }
}

int main() {
    char inputBuffer[MAX_BUFFER];
    xmlTag currentTag;
    int i;

    currentTag.attributes = (char**)malloc(sizeof(char**) * 1);
    currentTag.attributeCount = 0;

    while (fgets(inputBuffer, MAX_BUFFER, stdin) != NULL) {
        parseTag(inputBuffer, &currentTag);
        printf("Tag: %s\n", currentTag.name);

        for (i = 0; i < currentTag.attributeCount; i++) {
            printf("Attribute %d: %s\n", i, currentTag.attributes[i]);
        }

        currentTag.attributeCount = 0;

        free(currentTag.name);
        free(currentTag.attributes);
        currentTag.attributes = (char**)malloc(sizeof(char**) * 1);
    }

    return 0;
}