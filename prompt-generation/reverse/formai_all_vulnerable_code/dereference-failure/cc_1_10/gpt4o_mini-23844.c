//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ELEMENTS 100

typedef struct {
    char *tag;
    char *content;
} XmlElement;

typedef struct {
    XmlElement elements[MAX_ELEMENTS];
    int count;
} XmlDocument;

void initializeDocument(XmlDocument *doc) {
    doc->count = 0;
}

void addElement(XmlDocument *doc, const char *tag, const char *content) {
    if (doc->count < MAX_ELEMENTS) {
        doc->elements[doc->count].tag = strdup(tag);
        doc->elements[doc->count].content = strdup(content);
        doc->count++;
    } else {
        fprintf(stderr, "Maximum number of elements reached\n");
    }
}

void freeDocument(XmlDocument *doc) {
    for (int i = 0; i < doc->count; i++) {
        free(doc->elements[i].tag);
        free(doc->elements[i].content);
    }
}

void parseLine(XmlDocument *doc, const char *line) {
    char *startTag = strchr(line, '<');
    char *endTag = strchr(line, '>');
    char *startContent = endTag + 1;
    char *endContent = strstr(startContent, startTag);

    if (startTag && endTag && startContent && endContent) {
        *endContent = '\0'; // Temporarily end the content string
        char tag[50];
        strncpy(tag, startTag + 1, endTag - startTag - 1);
        tag[endTag - startTag - 1] = '\0'; // Null terminate the tag

        addElement(doc, tag, startContent);
    }
}

void printDocument(XmlDocument *doc) {
    for (int i = 0; i < doc->count; i++) {
        printf("<%s>%s</%s>\n", doc->elements[i].tag, doc->elements[i].content, doc->elements[i].tag);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    XmlDocument doc;
    initializeDocument(&doc);

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLine(&doc, line);
    }

    fclose(file);

    printDocument(&doc);
    freeDocument(&doc);

    return 0;
}