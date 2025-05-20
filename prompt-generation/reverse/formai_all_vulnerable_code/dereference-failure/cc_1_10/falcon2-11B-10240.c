//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 10000

typedef struct node {
    char *name;
    char *value;
    struct node *next;
} node;

node *root = NULL;

void add_node(char *name, char *value) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = root;
    root = new_node;
}

int main() {
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];
    int i, j;

    if ((fp = fopen("example.xml", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '<') {
                for (j = i + 1; j < strlen(buffer); j++) {
                    if (buffer[j] == '>') {
                        break;
                    }
                }
                char *name = strndup(buffer + i + 1, j - (i + 1));
                add_node(name, "");
            }
        }
    }

    fclose(fp);

    node *current = root;
    while (current!= NULL) {
        printf("%s : %s\n", current->name, current->value);
        current = current->next;
    }

    return 0;
}