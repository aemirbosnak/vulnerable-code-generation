//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_CONTENT 1024
#define MAX_XML_SIZE 8192

typedef struct Tag {
    char name[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    struct Tag* next;
} Tag;

Tag* create_tag(const char* name, const char* content) {
    Tag* new_tag = (Tag*)malloc(sizeof(Tag));
    strncpy(new_tag->name, name, MAX_TAG_NAME);
    strncpy(new_tag->content, content, MAX_TAG_CONTENT);
    new_tag->next = NULL;
    return new_tag;
}

void append_tag(Tag** head, const char* name, const char* content) {
    Tag* new_tag = create_tag(name, content);
    if (*head == NULL) {
        *head = new_tag;
    } else {
        Tag* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_tag;
    }
}

void free_tags(Tag* head) {
    Tag* current = head;
    while (current != NULL) {
        Tag* temp = current;
        current = current->next;
        free(temp);
    }
}

void parse_xml(const char* xml, Tag** tags) {
    char tag_name[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    int i = 0, j = 0, tag_mode = 0, content_mode = 0;
    
    while (xml[i] != '\0' && i < MAX_XML_SIZE) {
        if (xml[i] == '<') {
            if (xml[i + 1] != '/') {
                i++;
                tag_mode = 1;
                j = 0;
                while (xml[i] != '>' && xml[i] != '\0') {
                    if (j < MAX_TAG_NAME - 1) {
                        tag_name[j++] = xml[i++];
                    }
                }
                tag_name[j] = '\0';
                i++; // Move past '>'
            } else {
                i += 2; // Skip "</"
                while (xml[i] != '>' && xml[i] != '\0') {
                    if (j < MAX_TAG_NAME - 1) {
                        tag_name[j++] = xml[i++];
                    }
                }
                tag_name[j] = '\0';
                i++; // Move past '>'
            }

            if (tag_mode) {
                content_mode = 1;
                j = 0;
                while (xml[i] != '<' && xml[i] != '\0') {
                    if (j < MAX_TAG_CONTENT - 1) {
                        content[j++] = xml[i++];
                    }
                }
                content[j] = '\0';
                
                if (strcmp(tag_name, "open") == 0) {
                    append_tag(tags, tag_name, content);
                }
            }
            tag_mode = 0;
        } else {
            i++;
        }
    }
}

void display_tags(Tag* head) {
    printf("Neon Outlines:\n");
    while (head != NULL) {
        printf("Tag: <%s> Content: %s\n", head->name, head->content);
        head = head->next;
    }
}

int main() {
    char xml_data[MAX_XML_SIZE] =
        "<data>"
        "<open>Hacked the system</open>"
        "<open>Accessing the mainframe</open>"
        "<close>All systems go</close>"
        "</data>";
    
    Tag* tags = NULL;

    printf("Initiating XML Parsing...\n");
    parse_xml(xml_data, &tags);
    printf("Parsing Complete. Extracted Tags:\n");
    display_tags(tags);

    free_tags(tags);
    return 0;
}