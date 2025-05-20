//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_ATTR_LEN 50
#define MAX_ATTR_COUNT 10
#define MAX_VALUE_LEN 50
#define MAX_XML_LEN 10000

typedef struct Attribute {
    char key[MAX_ATTR_LEN];
    char value[MAX_VALUE_LEN];
} Attribute;

typedef struct Tag {
    char name[MAX_TAG_LEN];
    Attribute attrs[MAX_ATTR_COUNT];
    int attr_count;
    struct Tag *children;
    struct Tag *next;
    char value[MAX_VALUE_LEN];
} Tag;

void parse_xml(char *xml);
Tag *create_tag(char *begin_slice, char *end_slice);
void add_tag_child(Tag *parent, Tag *child);
void print_tag(Tag *tag);
void destroy_tag(Tag *tag);

int main() {
    char xml[MAX_XML_LEN];
    FILE *xml_file = fopen("example.xml", "r");

    if (!xml_file) {
        printf("Failed to open file.");
        return -1;
    }

    fread(xml, sizeof(char), MAX_XML_LEN, xml_file);
    parse_xml(xml);

    fclose(xml_file);

    return 0;
}

void parse_xml(char *xml) {
    Tag *root = NULL;
    Tag *last_tag = NULL;

    char *curr = xml;
    while (*curr != '\0') {
        if (*curr == '<') {
            char *begin_slice = curr + 1;
            char *end_slice = strchr(curr, '>');

            Tag *new_tag = create_tag(begin_slice, end_slice);
            if (new_tag == NULL) {
                printf("Failed to parse tag.");
                return;
            }

            if (last_tag == NULL) {
                root = new_tag;
            } else {
                add_tag_child(last_tag, new_tag);
            }

            last_tag = new_tag;
            curr = end_slice + 1;
        } else {
            char *begin_slice = curr;
            char *end_slice = strchr(curr, '<');
            if (end_slice == NULL) {
                strcpy(last_tag->value, begin_slice);
                break;
            }

            Tag *text_tag = create_tag(begin_slice, end_slice - 1);
            strcpy(text_tag->value, begin_slice);

            if (last_tag == NULL) {
                printf("Found text outside of tag.\n");
                return;
            }

            add_tag_child(last_tag, text_tag);

            curr = end_slice;
            last_tag->next = NULL;
        }
    }

    print_tag(root);
    destroy_tag(root);
}

Tag *create_tag(char *begin_slice, char *end_slice) {
    if (begin_slice == NULL || end_slice == NULL) {
        return NULL;
    }

    Tag *tag = malloc(sizeof(Tag));
    if (tag == NULL) {
        printf("Failed to allocate memory for tag.");
        return NULL;
    }

    int name_len = end_slice - begin_slice;
    if (name_len > MAX_TAG_LEN - 1) {
        printf("Tag name too long.");
        free(tag);
        return NULL;
    }

    strncpy(tag->name, begin_slice, name_len);
    tag->name[name_len] = '\0';

    char *curr = begin_slice + name_len + 1;
    tag->attr_count = 0;
    while (curr < end_slice) {
        char *key_begin = curr;
        char *key_end = strchr(curr, '=');
        if (key_end == NULL) {
            printf("Malformed attribute.");
            free(tag);
            return NULL;
        }
        char *value_begin = key_end + 2; // skip the equals sign and opening double quote
        char *value_end = strchr(value_begin, '\"');

        int key_len = key_end - key_begin;
        int value_len = value_end - value_begin;
        if (key_len > MAX_ATTR_LEN - 1 || value_len > MAX_VALUE_LEN - 1 || tag->attr_count >= MAX_ATTR_COUNT) {
            printf("Attribute key or value too long, or too many attributes.");
            free(tag);
            return NULL;
        }

        Attribute attr;
        strncpy(attr.key, key_begin, key_len);
        attr.key[key_len] = '\0';
        strncpy(attr.value, value_begin, value_len);
        attr.value[value_len] = '\0';

        tag->attrs[tag->attr_count] = attr;
        tag->attr_count++;

        curr = value_end + 1; // skip the closing double quote
    }

    tag->children = NULL;
    tag->next = NULL;
    tag->value[0] = '\0';

    return tag;
}

void add_tag_child(Tag *parent, Tag *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Tag *curr = parent->children;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = child;
    }
}

void print_tag(Tag *tag) {
    printf("<%s", tag->name);

    for (int i = 0; i < tag->attr_count; i++) {
        printf(" %s=\"%s\"", tag->attrs[i].key, tag->attrs[i].value);
    }

    if (tag->value[0] == '\0') {
        printf(">\n");
    } else {
        printf(">%s\n", tag->value);
    }

    Tag *curr = tag->children;
    while (curr != NULL) {
        print_tag(curr);
        curr = curr->next;
    }

    printf("</%s>\n", tag->name);
}

void destroy_tag(Tag *tag) {
    if (tag == NULL) {
        return;
    }

    Tag *curr = tag->children;
    while (curr != NULL) {
        Tag *next = curr->next;
        destroy_tag(curr);
        curr = next;
    }

    free(tag);
}