//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* tag;
    char** attributes;
    char** values;
} XMLTag;

XMLTag* parseTag(char* line) {
    XMLTag* tag = malloc(sizeof(XMLTag));
    tag->attributes = malloc(sizeof(char*)*10);
    tag->values = malloc(sizeof(char*)*10);
    char* ptr = strtok(line, " ");
    tag->tag = ptr;
    int i = 0;
    while(ptr != NULL) {
        ptr = strtok(NULL, " ");
        if(ptr != NULL) {
            char* equals = strchr(ptr, '=');
            *equals = '\0';
            tag->attributes[i] = ptr;
            tag->values[i] = equals+1;
            i++;
        }
    }
    return tag;
}

void freeTag(XMLTag* tag) {
    free(tag->attributes);
    free(tag->values);
    free(tag);
}

int main() {
    FILE *file = fopen("example.xml", "r");
    char line[256];
    bool tagOpen = false;
    XMLTag* currentTag;
    while(fgets(line, sizeof(line), file)) {
        if(line[0] == '<') {
            if(line[1] != '/') {
                currentTag = parseTag(line+1);
                tagOpen = true;
            }
            else {
                printf("Closing tag: %s\n", line+2);
                freeTag(currentTag);
                tagOpen = false;
            }
        }
        else if(tagOpen) {
            printf("Attribute: %s=%s\n", currentTag->attributes[0], currentTag->values[0]);
        }
    }
    fclose(file);
    return 0;
}