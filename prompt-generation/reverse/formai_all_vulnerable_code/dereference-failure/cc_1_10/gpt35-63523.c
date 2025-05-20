//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *tag_name;
    char *attributes[MAX_SIZE][2];
    char *content;
} xml_node;

int parse_xml(char *xml_text, xml_node *nodes, int max_nodes) {
    int node_count = 0;

    char *cursor = xml_text;

    while (*cursor) {
        if (*cursor == '<') {
            xml_node node;
            node.tag_name = malloc(MAX_SIZE);

            char *tag_name_cursor = node.tag_name;
            cursor++;

            while (*cursor != '>' && !isspace(*cursor)) {
                *tag_name_cursor = *cursor;
                tag_name_cursor++;
                cursor++;
            }

            *tag_name_cursor = '\0';

            char *close_tag = malloc(MAX_SIZE);
            sprintf(close_tag, "</%s>", node.tag_name);

            char *end_close_tag = strstr(cursor, close_tag);

            if (end_close_tag == NULL) {
                printf("Error parsing XML: could not find closing tag for %s\n", node.tag_name);
                free(node.tag_name);
                free(close_tag);
                break;
            }

            node.content = malloc(MAX_SIZE * sizeof(char));
            int content_index = 0;

            while (cursor < end_close_tag) {
                content_index = cursor - xml_text;
                node.content[content_index] = *cursor;
                cursor++;
            }

            node.content[content_index] = '\0';

            char *attributes_cursor;

            while (*cursor != '>') {
                if (!isspace(*cursor)) {
                    char *attribute_name = malloc(MAX_SIZE);
                    char *attribute_value = malloc(MAX_SIZE);

                    attributes_cursor = attribute_name;

                    while (*cursor != '=') {
                        *attributes_cursor = *cursor;
                        attributes_cursor++;
                        cursor++;
                    }

                    *attributes_cursor = '\0';
                    cursor++;

                    if (*cursor != '\'') {
                        printf("Error parsing XML: expected single quotes around attribute value for attribute %s\n", attribute_name);
                        free(attribute_name);
                        free(attribute_value);
                        continue;
                    }

                    cursor++;

                    attributes_cursor = attribute_value;

                    while (*cursor != '\'') {
                        *attributes_cursor = *cursor;
                        attributes_cursor++;
                        cursor++;
                    }

                    *attributes_cursor = '\0';
                    cursor++;

                    node.attributes[node_count][0] = attribute_name;
                    node.attributes[node_count][1] = attribute_value;

                    node_count++;
                }
                cursor++;
            }

            nodes[node_count] = node;

            if (node_count == max_nodes) {
                printf("Error parsing XML: exceeded maximum number of nodes");
                break;
            }
        } else {
            cursor++;
        }
    }

    return node_count;
}

int main() {
    char xml[] = "<book category='fiction'>\n"
                 "  <title lang='en'>The Hitchhiker's Guide to the Galaxy</title>\n"
                 "  <author>Douglas Adams</author>\n"
                 "  <year>1979</year>\n"
                 "</book>";

    xml_node nodes[MAX_SIZE];
    int node_count = parse_xml(xml, nodes, MAX_SIZE);

    printf("Parsed %d nodes\n", node_count);

    for (int i = 0; i < node_count; i++) {
        printf("Node %d\n", i + 1);
        printf("Tag name: %s\n", nodes[i].tag_name);
        printf("Content: %s\n", nodes[i].content);

        printf("Attributes:\n");

        for (int j = 0; j < MAX_SIZE; j++) {
            if (nodes[i].attributes[j][0] == NULL) {
                break;
            }

            printf("%s: %s\n", nodes[i].attributes[j][0], nodes[i].attributes[j][1]);
        }

        printf("\n");
    }

    return 0;
}