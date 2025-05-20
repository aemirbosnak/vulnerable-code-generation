//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _file_node {
    char *filename;
    char *data;
    size_t size;
    struct _file_node *next;
} file_node;

file_node *head = NULL;
file_node *tail = NULL;

void add_file(char *filename, char *data, size_t size) {
    file_node *new_node = malloc(sizeof(file_node));
    new_node->filename = strdup(filename);
    new_node->data = malloc(size);
    memcpy(new_node->data, data, size);
    new_node->size = size;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_files() {
    file_node *current = head;
    while (current != NULL) {
        printf("Filename: %s\n", current->filename);
        printf("Size: %zu\n", current->size);
        printf("Data:\n");
        fwrite(current->data, 1, current->size, stdout);
        printf("\n\n");
        current = current->next;
    }
}

void free_files() {
    file_node *current = head;
    while (current != NULL) {
        file_node *next = current->next;
        free(current->filename);
        free(current->data);
        free(current);
        current = next;
    }
    head = NULL;
    tail = NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            perror("fopen");
            continue;
        }

        fseek(fp, 0, SEEK_END);
        size_t size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char *data = malloc(size);
        fread(data, 1, size, fp);
        fclose(fp);

        add_file(argv[i], data, size);
    }

    print_files();

    free_files();

    return EXIT_SUCCESS;
}