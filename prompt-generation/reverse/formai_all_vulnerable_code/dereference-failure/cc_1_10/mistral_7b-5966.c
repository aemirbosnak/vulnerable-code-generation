//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 100
#define LINE_SIZE 256
#define FILENAME "input.txt"
typedef struct {
    char line[LINE_SIZE];
    struct Node *next;
} Node;
Node *head = NULL;
int read_file(FILE *fp) {
    char line[LINE_SIZE];
    Node *new_node;
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    while (fgets(line, LINE_SIZE, fp) != NULL) {
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(fp);
            return -1;
        }
        strcpy(new_node->line, line);
        new_node->next = head;
        head = new_node;
    }
    fclose(fp);
    return 0;
}
int main() {
    FILE *fp;
    int error;
    error = read_file(fp = fopen(FILENAME, "r"));
    if (error != 0) {
        return 1;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%s", current->line);
        current = current->next;
    }
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    fclose(fp);
    return 0;
}