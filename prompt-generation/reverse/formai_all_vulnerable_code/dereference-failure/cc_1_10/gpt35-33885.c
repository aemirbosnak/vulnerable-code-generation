//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *tag;
    char *attr;
    char *content;
} xml_node;

void parse_xml(char *xml, xml_node **nodes);

int main(void) {
    char *xml_string = "<book><title attr=\"true\">The Great Gatsby</title><author>F. Scott Fitzgerald</author></book>";
    xml_node **nodes = malloc(sizeof(xml_node*) * 3); // Maximum number of nodes in this XML string is 3

    parse_xml(xml_string, nodes);

    printf("%s: %s (%s)\n", nodes[0]->tag, nodes[0]->content, nodes[0]->name);
    printf("%s: %s\n", nodes[1]->tag, nodes[1]->content);
    printf("%s: %s\n", nodes[2]->tag, nodes[2]->content);

    free(nodes[0]->name);
    free(nodes[0]->tag);
    free(nodes[0]->attr);
    free(nodes[0]->content);
    free(nodes[0]);
    free(nodes[1]->tag);
    free(nodes[1]->content);
    free(nodes[1]);
    free(nodes[2]->tag);
    free(nodes[2]->content);
    free(nodes[2]);
    free(nodes);

    return 0;
}

void parse_xml(char *xml, xml_node **nodes) {
    char *start_tag;
    char *end_tag;
    char *node_content;
    char *attr_start;
    char *tag_end;

    start_tag = strstr(xml, "<");

    while (start_tag != NULL) {
        end_tag = strstr(start_tag, ">");
        node_content = malloc(sizeof(char) * (end_tag - start_tag + 1));
        strncpy(node_content, start_tag + 1, end_tag - start_tag - 1);
        node_content[end_tag - start_tag - 1] = '\0';

        nodes[0] = malloc(sizeof(xml_node));
        nodes[0]->name = "book";
        nodes[1] = malloc(sizeof(xml_node));
        nodes[1]->name = "title";
        nodes[2] = malloc(sizeof(xml_node));
        nodes[2]->name = "author";

        attr_start = strstr(start_tag, " ");
        tag_end = strstr(start_tag, ">");

        if (attr_start != NULL && attr_start < end_tag && attr_start < tag_end) {
            char *attr_end = strstr(attr_start, "\"");
            nodes[1]->attr = malloc(sizeof(char) * (attr_end - attr_start + 1));
            strncpy(nodes[1]->attr, attr_start + 1, attr_end - attr_start - 1);
            nodes[1]->attr[attr_end - attr_start - 1] = '\0';
        }
        else {
            nodes[1]->attr = "";
        }

        strncpy(nodes[1]->content, node_content, strlen(node_content));
        nodes[1]->tag = "title";

        if (start_tag == xml) {
            strncpy(nodes[0]->content, node_content, strlen(node_content));
            nodes[0]->tag = "book";
        }
        else {
            strncpy(nodes[2]->content, node_content, strlen(node_content));
            nodes[2]->tag = "author";
        }

        start_tag = strstr(end_tag, "<");
    }
}