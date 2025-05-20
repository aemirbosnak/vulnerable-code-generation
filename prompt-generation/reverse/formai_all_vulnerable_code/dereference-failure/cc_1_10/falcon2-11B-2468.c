//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Node;

void parse_xml(char *filename) {
    FILE *file;
    Node node;
    char buffer[1024];

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        if (buffer[0] == '<') {
            if (strcmp(buffer, "<doc>") == 0) {
                node.name = strdup("<doc>");
                node.value = strdup("</doc>");
            } else if (strcmp(buffer, "<element>") == 0) {
                node.name = strdup("<element>");
                node.value = strdup("</element>");
            } else if (strcmp(buffer, "<text>") == 0) {
                node.name = strdup("<text>");
                node.value = strdup("</text>");
            } else {
                perror("Invalid XML syntax");
                exit(EXIT_FAILURE);
            }
        } else if (buffer[0] == '>') {
            free(node.name);
            free(node.value);
            node.name = NULL;
            node.value = NULL;
        } else {
            printf("%s%s\n", node.name, node.value);
            free(node.name);
            free(node.value);
            node.name = NULL;
            node.value = NULL;
        }
    }

    fclose(file);
}

int main() {
    parse_xml("sample.xml");

    return 0;
}