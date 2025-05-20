//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_BUFFER_SIZE 1024

typedef struct XMLNode {
    char *data;
    struct XMLNode *next;
} XMLNode;

XMLNode *parse_xml(char *xml_data) {
    XMLNode *head = NULL;
    XMLNode *curr = NULL;
    int i = 0;

    for (i = 0; xml_data[i] != '\0'; i++) {
        if (xml_data[i] == '<') {
            curr = malloc(sizeof(XMLNode));
            curr->data = malloc(XML_BUFFER_SIZE);
            curr->next = NULL;

            if (head == NULL) {
                head = curr;
            } else {
                curr->next = head;
                head = curr;
            }

            i++;
            while (xml_data[i] != '>' && xml_data[i] != '\0') {
                curr->data[i - 1] = xml_data[i];
                i++;
            }
        }
    }

    return head;
}

int main() {
    char xml_data[] = "<foo><bar>baz</bar></foo>";
    XMLNode *head = parse_xml(xml_data);

    XMLNode *curr = head;
    while (curr) {
        printf("Data: %s\n", curr->data);
        curr = curr->next;
    }

    return 0;
}