//FormAI DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1048576

typedef struct node_ {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    struct node_ *next;
} node;

node *head = NULL;

void add_node(char *filename, int size);
void delete_node(node *prev, node *cur);
void display_files();
int file_exists(char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int size = 0;
    char buffer[MAX_FILE_SIZE];

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file: %s\n", filename);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    if (size > MAX_FILE_SIZE) {
        printf("Error: File too large: %s\n", filename);
        exit(1);
    }
    fread(buffer, size, 1, fp);
    fclose(fp);

    if (file_exists(filename)) {
        printf("File %s already exists. Do you want to overwrite? (y/n): ", filename);
        char response;
        scanf("%c", &response);
        if (response == 'n') {
            printf("File not backed up.\n");
            exit(0);
        } else if (response != 'y') {
            printf("Invalid input. File not backed up.\n");
            exit(1);
        }
        node *cur = head;
        while (cur != NULL) {
            if (strcmp(cur->filename, filename) == 0) {
                delete_node(NULL, cur);
                break;
            }
            cur = cur->next;
        }
    }

    add_node(filename, size);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not create file: %s\n", filename);
        exit(1);
    }
    fwrite(buffer, size, 1, fp);
    printf("File backed up successfully.\n");
    fclose(fp);
    display_files();
    return 0;
}

void add_node(char *filename, int size) {
    node *new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->filename, filename);
    new_node->size = size;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

void delete_node(node *prev, node *cur) {
    if (prev == NULL) {
        head = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
}

void display_files() {
    if (head == NULL) {
        printf("No files backed up.\n");
        return;
    }
    printf("Files backed up:\n");
    node *cur = head;
    while (cur != NULL) {
        printf("%s (%d bytes)\n", cur->filename, cur->size);
        cur = cur->next;
    }
}

int file_exists(char *filename) {
    node *cur = head;
    while (cur != NULL) {
        if (strcmp(cur->filename, filename) == 0) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}