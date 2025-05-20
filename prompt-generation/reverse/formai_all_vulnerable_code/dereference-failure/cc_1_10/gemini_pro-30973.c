//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_ATTR_LENGTH 100
#define MAX_ATTR_VALUE_LENGTH 100

typedef struct {
    char name[MAX_TAG_LENGTH];
    char *attrs[10];
    char *values[10];
    int num_attrs;
} Tag;

typedef struct {
    Tag *tags;
    int num_tags;
} XMLDocument;

XMLDocument *parse_xml(char *xml) {
    XMLDocument *doc = malloc(sizeof(XMLDocument));
    doc->tags = NULL;
    doc->num_tags = 0;

    char *start = xml;
    char *end = xml;

    while (*end != '\0') {
        if (*end == '<') {
            start = end;
            end++;

            while (*end != '>') {
                end++;
            }

            char *tag_name = start + 1;
            char *tag_end = end;
            *tag_end = '\0';

            Tag tag;
            strcpy(tag.name, tag_name);
            tag.num_attrs = 0;

            start = end + 1;
            end = start;

            while (*end != '\0') {
                if (*end == ' ') {
                    end++;
                } else if (*end == '/') {
                    break;
                } else {
                    char *attr_name = end;
                    end++;

                    while (*end != '=' && *end != ' ') {
                        end++;
                    }

                    *end = '\0';

                    char *attr_value = end + 1;
                    end++;

                    while (*end != ' ' && *end != '>') {
                        end++;
                    }

                    *end = '\0';

                    tag.attrs[tag.num_attrs] = malloc(strlen(attr_name) + 1);
                    strcpy(tag.attrs[tag.num_attrs], attr_name);
                    tag.values[tag.num_attrs] = malloc(strlen(attr_value) + 1);
                    strcpy(tag.values[tag.num_attrs], attr_value);
                    tag.num_attrs++;
                }
            }

            doc->tags = realloc(doc->tags, (doc->num_tags + 1) * sizeof(Tag));
            doc->tags[doc->num_tags] = tag;
            doc->num_tags++;
        } else {
            end++;
        }
    }

    return doc;
}

void free_xml_document(XMLDocument *doc) {
    for (int i = 0; i < doc->num_tags; i++) {
        free(doc->tags[i].name);
        for (int j = 0; j < doc->tags[i].num_attrs; j++) {
            free(doc->tags[i].attrs[j]);
            free(doc->tags[i].values[j]);
        }
    }

    free(doc->tags);
    free(doc);
}

void print_xml_document(XMLDocument *doc) {
    for (int i = 0; i < doc->num_tags; i++) {
        Tag tag = doc->tags[i];

        printf("<%s", tag.name);

        for (int j = 0; j < tag.num_attrs; j++) {
            printf(" %s=\"%s\"", tag.attrs[j], tag.values[j]);
        }

        printf(">");
    }

    printf("\n");
}

int main() {
    char *xml = "<root><child1 attr1=\"value1\" attr2=\"value2\"/><child2/></root>";

    XMLDocument *doc = parse_xml(xml);
    print_xml_document(doc);
    free_xml_document(doc);

    return 0;
}