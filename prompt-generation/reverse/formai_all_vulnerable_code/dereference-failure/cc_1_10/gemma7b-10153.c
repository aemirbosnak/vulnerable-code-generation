//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_BUFFER_SIZE 1024

typedef struct XML_Node {
    struct XML_Node* next;
    char* data;
    int type;
} XML_Node;

XML_Node* xml_parser(char* xml_data) {
    XML_Node* head = NULL;
    char* buffer = NULL;
    int i = 0;
    int state = 0;

    buffer = malloc(XML_BUFFER_SIZE);

    while (xml_data[i] != '\0') {
        switch (state) {
            case 0:
                if (xml_data[i] == '<') {
                    state = 1;
                    buffer = realloc(buffer, XML_BUFFER_SIZE * 2);
                    buffer[0] = xml_data[i];
                    buffer[1] = xml_data[i + 1];
                    buffer[2] = '\0';
                    XML_Node* node = malloc(sizeof(XML_Node));
                    node->data = buffer;
                    node->type = 1;
                    node->next = head;
                    head = node;
                } else {
                    state = 0;
                }
                break;
            case 1:
                if (xml_data[i] == '>') {
                    state = 0;
                    buffer = realloc(buffer, XML_BUFFER_SIZE);
                    buffer[0] = xml_data[i];
                    buffer[1] = '\0';
                    XML_Node* node = malloc(sizeof(XML_Node));
                    node->data = buffer;
                    node->type = 2;
                    node->next = head;
                    head = node;
                } else {
                    buffer = realloc(buffer, XML_BUFFER_SIZE * 2);
                    buffer[0] = xml_data[i];
                    buffer[1] = xml_data[i + 1];
                    buffer[2] = '\0';
                }
                break;
            default:
                state = 0;
                break;
        }
        i++;
    }

    free(buffer);

    return head;
}

int main() {
    char* xml_data = "<foo><b>Hello, world!</b></foo>";
    XML_Node* head = xml_parser(xml_data);

    for (XML_Node* node = head; node; node = node->next) {
        printf("%s", node->data);
    }

    return 0;
}