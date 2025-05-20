//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64
#define MAX_ATTR_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct Attribute {
    char name[MAX_ATTR_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Attribute* next;
} Attribute;

typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    Attribute* attributes;
    struct Tag* next;
} Tag;

Tag* createTag(const char* name) {
    Tag* newTag = (Tag*)malloc(sizeof(Tag));
    snprintf(newTag->name, MAX_TAG_LENGTH, "%s", name);
    newTag->attributes = NULL;
    newTag->next = NULL;
    return newTag;
}

Attribute* createAttribute(const char* name, const char* value) {
    Attribute* newAttr = (Attribute*)malloc(sizeof(Attribute));
    snprintf(newAttr->name, MAX_ATTR_LENGTH, "%s", name);
    snprintf(newAttr->value, MAX_VALUE_LENGTH, "%s", value);
    newAttr->next = NULL;
    return newAttr;
}

void addAttribute(Tag* tag, const char* name, const char* value) {
    Attribute* newAttr = createAttribute(name, value);
    newAttr->next = tag->attributes;
    tag->attributes = newAttr;
}

void printTag(const Tag* tag) {
    printf("Tag: <%s>\n", tag->name);
    Attribute* attr = tag->attributes;
    while (attr) {
        printf("  Attribute: %s = %s\n", attr->name, attr->value);
        attr = attr->next;
    }
}

void freeAttributes(Attribute* attr) {
    while (attr) {
        Attribute* temp = attr;
        attr = attr->next;
        free(temp);
    }
}

void freeTags(Tag* tag) {
    while (tag) {
        Tag* temp = tag;
        tag = tag->next;
        freeAttributes(temp->attributes);
        free(temp);
    }
}

Tag* parseXML(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    Tag* head = NULL;
    Tag* tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tagName[MAX_TAG_LENGTH];
        if (sscanf(line, "<%63[^ >]", tagName) == 1) {
            Tag* newTag = createTag(tagName);
            if (!head) {
                head = tail = newTag;
            } else {
                tail->next = newTag;
                tail = newTag;
            }
        }
        
        char attrName[MAX_ATTR_LENGTH], attrValue[MAX_VALUE_LENGTH];
        while (sscanf(line, "%63[^=]=\"%255[^\"]\"", attrName, attrValue) == 2) {
            addAttribute(tail, attrName, attrValue);
            line[strcspn(line, "\n")] = 0; // Remove newline for next sscanf
        }
    }

    fclose(file);
    return head;
}

void printXML(const Tag* head) {
    Tag* current = head;
    while (current) {
        printTag(current);
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    Tag* tags = parseXML(argv[1]);
    if (!tags) {
        return 1; // Error parsing XML
    }

    printf("Parsed XML Tags and Attributes:\n");
    printXML(tags);

    freeTags(tags);
    return 0;
}