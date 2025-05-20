//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct {
    char name[256];
    char type[256];
    char desc[256];
    int size;
    struct node *next;
} node_t;

node_t *head = NULL;

void insert_node(char *name, char *type, char *desc, int size) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    strcpy(new_node->type, type);
    strcpy(new_node->desc, desc);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
        head = new_node;
    }
}

void extract_metadata() {
    FILE *fp = fopen("/etc/passwd", "r");
    char line[256];
    char *name, *type, *desc;
    int size;

    while (fgets(line, 256, fp) != NULL) {
        name = strtok(line, ":");
        type = strtok(NULL, ":");
        desc = strtok(NULL, ":");
        size = atoi(strtok(NULL, ":"));

        insert_node(name, type, desc, size);
    }

    fclose(fp);
}

int main() {
    extract_metadata();

    node_t *current = head;
    while (current) {
        printf("%s: %s, %s, %d\n", current->name, current->type, current->desc, current->size);
        current = current->next;
    }

    return 0;
}