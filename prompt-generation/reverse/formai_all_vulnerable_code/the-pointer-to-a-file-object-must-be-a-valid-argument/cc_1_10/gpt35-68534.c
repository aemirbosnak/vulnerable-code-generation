//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* define a structure to store the information of an XML tag */
typedef struct {
    char name[50];
    char value[100];
} XMLTag;

/* define a function to parse the opening tag of an XML element */
XMLTag parseOpenTag(char* line, int length) {
    XMLTag tag;
    int i = 0;
    
    /* get the tag name */
    while (line[i] != ' ' && line[i] != '>') {
        tag.name[i] = line[i];
        i++;
    }
    tag.name[i] = '\0';
    
    /* check if there are any attributes */
    if (line[i] == ' ') {
        while (line[i] != '>') {
            i++;
        }
    }
    
    /* set the tag value to an empty string */
    tag.value[0] = '\0';
    
    return tag;
}

/* define a function to parse the closing tag of an XML element */
char* parseCloseTag(char* line, int length) {
    char* tag = (char*) malloc(sizeof(char) * 50);
    int i = 0;
    
    /* get the tag name */
    while (line[i] != '>') {
        tag[i] = line[i+2];
        i++;
    }
    tag[i] = '\0';
    
    return tag;
}

/* define a function to extract the value from an XML element */
char* extractValue(char* line, int length) {
    return strtok(line, "<>");
}

/* define the main function */
int main() {
    FILE *filePointer;
    char line[100];
    XMLTag currentTag;
    bool inTag = false;
    
    /* open the file */
    filePointer = fopen("example.xml", "r");

    /* read the file line by line */
    while (fgets(line, sizeof(line), filePointer)) {
        int length = strlen(line);
        
        /* check if we are inside an XML tag */
        if (inTag) {
            if (line[1] != '/') {
                /* we are inside an opening tag */
                currentTag = parseOpenTag(line+1, length-2);
                printf("Found opening tag: %s\n", currentTag.name);
            } else {
                /* we are inside a closing tag */
                char* closeTagName = parseCloseTag(line, length-1);
                printf("Found closing tag: %s\n", closeTagName);
                
                /* check if the closing tag matches the opening tag */
                if (strcmp(currentTag.name, closeTagName) != 0) {
                    printf("Error: closing tag does not match opening tag\n");
                    return 1;
                }
                
                /* reset the current tag */
                currentTag.name[0] = '\0';
                currentTag.value[0] = '\0';
            }
            inTag = false;
        } else {
            /* we are outside an XML tag */
            char* value = extractValue(line, length);
            if (strlen(value) > 0) {
                printf("Found value: %s\n", value);
            }
            inTag = true;
        }
    }

    /* close the file */
    fclose(filePointer);

    return 0;
}