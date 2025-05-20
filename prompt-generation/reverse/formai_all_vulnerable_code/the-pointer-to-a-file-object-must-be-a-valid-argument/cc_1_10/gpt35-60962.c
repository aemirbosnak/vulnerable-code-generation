//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Romeo and Juliet
// In fair Verona, where we base our code,
// A program was born, to parse a file that glowed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *tag;
    char *value;
    int level;
} Element;

Element *elements[100];
int elementCount = 0;

void parseXML(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1000];
    char *token;
    int level = 0;

    while (fgets(line, 1000, file)) {
        token = strtok(line, "><");
        while (token != NULL) {
            if (strcasecmp(token, "?xml") == 0) {
                // Do nothing, skip XML declaration
            } else if (*token == '/') {
                level--;
            } else {
                Element *el = (Element *)malloc(sizeof(Element));
                el->value = (char *)malloc(100);
                el->tag = (char *)malloc(100);
                strcpy(el->tag, token);
                strcpy(el->value, strtok(NULL, "><"));
                el->level = level;
                elements[elementCount++] = el;
                level++;
            }
            token = strtok(NULL, "><");
        }
    }

    fclose(file);
}

int main() {
    // Romeo, Romeo, wherefore art thou filename.txt?
    parseXML("filename.txt");

    // O happy dagger, here is thy output.
    int i, j;
    for (i = 0; i < elementCount; i++) {
        for (j = 0; j < elements[i]->level; j++) {
            printf("  ");
        }
        printf("<%s>%s</%s>\n", elements[i]->tag, elements[i]->value, elements[i]->tag);
    }

    // Parting is such sweet sorrow, let us free our memories.
    for (i = 0; i < elementCount; i++) {
        free(elements[i]->tag);
        free(elements[i]->value);
        free(elements[i]);
    }

    return 0;
}