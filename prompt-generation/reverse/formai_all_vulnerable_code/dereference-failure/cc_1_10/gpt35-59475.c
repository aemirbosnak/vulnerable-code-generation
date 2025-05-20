//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char* tagname;
    int taglen;
    char* content;
    int contentlen;
} tag;

static tag* tags;
static int numtags = 0;
static int tagindex = -1;
static char* buffer = NULL;
static int bufsize = 0;
static int buflen = 0;

void startelement(char* el, int len) {
    tagindex++;
    tags[tagindex].tagname = malloc(len+1);
    strncpy(tags[tagindex].tagname, el, len);
    tags[tagindex].tagname[len] = '\0';
    tags[tagindex].taglen = len;
    tags[tagindex].content = NULL;
    tags[tagindex].contentlen = 0;
}

void endelement(char* el, int len) {
    if (tagindex != -1 && strncmp(tags[tagindex].tagname, el, len) == 0 && tags[tagindex].taglen == len) {
        // We've found the closing tag for the current element
        printf("Tag %s content: %s\n", tags[tagindex].tagname, tags[tagindex].content);
        free(tags[tagindex].tagname);
        free(tags[tagindex].content);
        tagindex--;
    }
}

void characters(char* ch, int len) {
    // Append the content for the current tag
    if (tagindex != -1) {
        if (tags[tagindex].content == NULL) {
            tags[tagindex].content = malloc(len+1);
        } else {
            tags[tagindex].content = realloc(tags[tagindex].content, tags[tagindex].contentlen + len + 1);
        }
        strncpy(tags[tagindex].content + tags[tagindex].contentlen, ch, len);
        tags[tagindex].contentlen += len;
        tags[tagindex].content[tags[tagindex].contentlen] = '\0';
    }
}

void parsexml(char* xml, int len) {
    tags = malloc(len * sizeof(tag));
    int i, j, k;
    for (i = 0; i < len; ++i) {
        if (xml[i] == '<') {
            if (xml[i+1] == '/') {
                // This is an end tag
                for (k = i+2; k < len; ++k) {
                    if (xml[k] == '>') {
                        // We've found the end of the tag name
                        endelement(xml+i+2, k-i-2);
                        i = k;
                        break;
                    }
                }
            } else {
                // This is a start tag
                for (j = i+1; j < len; ++j) {
                    if (xml[j] == '>') {
                        // We've found the end of the tag name
                        startelement(xml+i+1, j-i-1);
                        i = j;
                        break;
                    }
                }
            }
        } else {
            // This is text content between elements
            for (k = i; k < len; ++k) {
                if (xml[k] == '<') {
                    // We've found the start of a new element
                    characters(xml+i, k-i);
                    i = k-1;
                    break;
                }
            }
        }
    }
}

int main() {
    FILE* fp = fopen("example.xml", "r");
    if (!fp) {
        perror("example.xml");
        return 1;
    }
    fseek(fp, 0L, SEEK_END);
    bufsize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    buffer = malloc(bufsize);
    buflen = fread(buffer, sizeof(char), bufsize, fp);

    parsexml(buffer, buflen);

    fclose(fp);
    free(buffer);
    free(tags);

    return 0;
}