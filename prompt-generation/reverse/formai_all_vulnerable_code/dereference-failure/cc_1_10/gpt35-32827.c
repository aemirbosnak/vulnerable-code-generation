//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* tag;
    char* content;
} Node;

void parseXML(char* xml, Node** nodes, int* num_nodes) {
    // assuming xml has only one root tag
    char* root_start = strstr(xml, "<");
    char* root_end = strstr(xml, ">");
    char* root_tag = (char*) malloc(sizeof(char) * (root_end - root_start - 1));
    strncpy(root_tag, root_start + 1, root_end - root_start - 1);
    root_tag[root_end - root_start - 1] = '\0';

    (*num_nodes)++;
    (*nodes) = (Node*) realloc(*nodes, sizeof(Node) * (*num_nodes));
    (*nodes)[*num_nodes - 1].tag = root_tag;
    (*nodes)[*num_nodes - 1].content = NULL;

    char* curr_start = root_end + 1;
    char* next_start = strstr(curr_start, "<");
    while (next_start != NULL) {
        char* curr_end = strstr(curr_start, ">");
        char* curr_tag = (char*) malloc(sizeof(char) * (curr_end - curr_start - 1));
        strncpy(curr_tag, curr_start + 1, curr_end - curr_start - 1);
        curr_tag[curr_end - curr_start - 1] = '\0';

        (*num_nodes)++;
        (*nodes) = (Node*) realloc(*nodes, sizeof(Node) * (*num_nodes));
        (*nodes)[*num_nodes - 1].tag = curr_tag;

        char* next_end = strstr(next_start, ">");
        if (*(next_start + 1) == '/') {
            // ending tag
            (*nodes)[*num_nodes - 1].content = NULL;
        } else {
            // starting tag, recursive call
            char* inner_xml_start = next_end + 1;
            char* inner_xml_end = strstr(inner_xml_start, "</");
            int inner_num_nodes = 0;
            Node* inner_nodes = NULL;
            parseXML(inner_xml_start, &inner_nodes, &inner_num_nodes);

            (*nodes)[*num_nodes - 1].content = (char*) malloc(sizeof(char) * strlen(inner_nodes[0].content));
            strcpy((*nodes)[*num_nodes - 1].content, inner_nodes[0].content);

            free(inner_nodes[0].tag);
            free(inner_nodes[0].content);
            free(inner_nodes);
        }

        curr_start = next_end + 1;
        next_start = strstr(curr_start, "<");
    }
}

int main() {

    char* xml = "<castle><tower><name>East Tower</name></tower><tower><name>West Tower</name></tower><moat>water</moat></castle>";

    Node* nodes = NULL;
    int num_nodes = 0;
    parseXML(xml, &nodes, &num_nodes);

    printf("XML parsed successfully!\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i+1);
        printf("Tag: %s\n", nodes[i].tag);
        if (nodes[i].content != NULL) {
            printf("Content: %s\n", nodes[i].content);
        }
        printf("\n");
        free(nodes[i].tag);
        if (nodes[i].content != NULL) {
            free(nodes[i].content);
        }
    }
    free(nodes);
    return 0;
}