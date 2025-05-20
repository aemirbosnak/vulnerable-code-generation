//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 64
#define MAX_ATTR_NAME 64
#define MAX_ATTR_VALUE 256

typedef struct Attribute {
    char name[MAX_ATTR_NAME];
    char value[MAX_ATTR_VALUE];
    struct Attribute* next;
} Attribute;

typedef struct Tag {
    char name[MAX_TAG_NAME];
    Attribute* attributes;
    struct Tag* next;
} Tag;

Tag* head = NULL;

void addTag(const char* name) {
    Tag* newTag = (Tag*)malloc(sizeof(Tag));
    strcpy(newTag->name, name);
    newTag->attributes = NULL;
    newTag->next = head;
    head = newTag;
}

void addAttribute(Tag* tag, const char* attrName, const char* attrValue) {
    Attribute* newAttr = (Attribute*)malloc(sizeof(Attribute));
    strcpy(newAttr->name, attrName);
    strcpy(newAttr->value, attrValue);
    newAttr->next = tag->attributes;
    tag->attributes = newAttr;
}

void parseXML(const char* xml) {
    const char* p = xml;
    char tagName[MAX_TAG_NAME];
    char attrName[MAX_ATTR_NAME];
    char attrValue[MAX_ATTR_VALUE];

    while (*p) {
        if (*p == '<') {
            ++p; // Go to the tag name

            // Read tag name
            int idx = 0;
            while (*p != ' ' && *p != '>' && *p != '\0') {
                tagName[idx++] = *p++;
            }
            tagName[idx] = '\0';

            addTag(tagName);
            Tag* currentTag = head;

            // Read attributes
            while (*p != '>' && *p != '\0') {
                if (*p == ' ') {
                    ++p; // Skip spaces
                    // Read attribute name
                    idx = 0;
                    while (*p != '=' && *p != '\0') {
                        attrName[idx++] = *p++;
                    }
                    attrName[idx] = '\0';
                    ++p; // Skip '='
                    ++p; // Skip '"'

                    // Read attribute value
                    idx = 0;
                    while (*p != '"' && *p != '\0') {
                        attrValue[idx++] = *p++;
                    }
                    attrValue[idx] = '\0';
                    ++p; // Skip '"'

                    // Attach attribute to current tag
                    addAttribute(currentTag, attrName, attrValue);
                }
                ++p;
            }
            ++p; // Skip '>'
        }
        ++p;
    }
}

void printTags() {
    Tag* current = head;
    while (current) {
        printf("Tag: %s\n", current->name);
        Attribute* attr = current->attributes;
        while (attr) {
            printf("  Attribute: %s = %s\n", attr->name, attr->value);
            attr = attr->next;
        }
        current = current->next;
    }
}

void freeTags() {
    while (head) {
        Tag* tempTag = head;
        head = head->next;

        Attribute* attr = tempTag->attributes;
        while (attr) {
            Attribute* tempAttr = attr;
            attr = attr->next;
            free(tempAttr);
        }
        free(tempTag);
    }
}

int main() {
    const char* xml_input = "<cat name=\"Whiskers\" color=\"orange\"><food type=\"fish\"/><warning level=\"high\">Too cute!</warning></cat>";

    printf("XML Input:\n%s\n\n", xml_input);
    parseXML(xml_input);
    printf("Parsed Tags and Attributes:\n");
    printTags();

    freeTags();
    return 0;
}