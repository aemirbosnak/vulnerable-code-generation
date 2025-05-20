//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_NAME 100
#define MAX_TEXT_LENGTH 1024

typedef struct Tag {
    char name[MAX_TAG_NAME];
    char text[MAX_TEXT_LENGTH];
    struct Tag *next;
} Tag;

Tag *createTag(const char *name, const char *text) {
    Tag *newTag = (Tag *)malloc(sizeof(Tag));
    if (newTag == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newTag->name, name, MAX_TAG_NAME);
    strncpy(newTag->text, text, MAX_TEXT_LENGTH);
    newTag->next = NULL;
    return newTag;
}

void freeTags(Tag *tag) {
    while (tag) {
        Tag *temp = tag;
        tag = tag->next;
        free(temp);
    }
}

void parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    char buffer[MAX_TEXT_LENGTH];
    char currentTag[MAX_TAG_NAME] = {0};
    char currentText[MAX_TEXT_LENGTH] = {0};
    Tag *head = NULL;
    Tag *tail = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *ptr = buffer;
        while (*ptr) {
            if (*ptr == '<') {
                // Close current text if exists
                if (strlen(currentText) > 0) {
                    Tag *tag = createTag(currentTag, currentText);
                    if (!head) {
                        head = tail = tag;
                    } else {
                        tail->next = tag;
                        tail = tag;
                    }
                    memset(currentText, 0, sizeof(currentText));
                }

                // Read tag name
                ptr++;
                char *end = strchr(ptr, '>');
                if (end) {
                    size_t tagNameLength = end - ptr;
                    strncpy(currentTag, ptr, tagNameLength);
                    currentTag[tagNameLength] = '\0';
                    ptr = end + 1; // Move past the closing '>'
                }
            } else {
                // Read text content
                char *endOfText = strchr(ptr, '<');
                if (endOfText) {
                    size_t textLength = endOfText - ptr;
                    strncat(currentText, ptr, textLength);
                    ptr = endOfText; // Move to the next tag
                } else {
                    strncat(currentText, ptr, strlen(ptr));
                    ptr += strlen(ptr); // Move to the end of the buffer
                }
            }
        }
    }

    fclose(file);

    // Print parsed results
    Tag *current = head;
    while (current) {
        printf("Tag: < %s >, Text: \"%s\"\n", current->name, current->text);
        current = current->next;
    }

    freeTags(head);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.xml>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXML(argv[1]);

    return EXIT_SUCCESS;
}