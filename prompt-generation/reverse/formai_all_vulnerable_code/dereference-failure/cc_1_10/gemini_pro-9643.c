//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 100

struct mailing_list {
    char name[MAX_LINE_LEN];
    char email[MAX_LINE_LEN];
};

struct mailing_list_node {
    struct mailing_list data;
    struct mailing_list_node *next;
};

struct mailing_list_node *head = NULL;
int num_lines = 0;

void add_mailing_list_entry(char *name, char *email) {
    struct mailing_list_node *new_node = malloc(sizeof(struct mailing_list_node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: could not allocate memory for new mailing list entry\n");
        exit(1);
    }
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.email, email);
    new_node->next = head;
    head = new_node;
    num_lines++;
}

void print_mailing_list() {
    struct mailing_list_node *current_node = head;
    while (current_node != NULL) {
        printf("%s, %s\n", current_node->data.name, current_node->data.email);
        current_node = current_node->next;
    }
}

void free_mailing_list() {
    struct mailing_list_node *current_node = head;
    while (current_node != NULL) {
        struct mailing_list_node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        if (name != NULL && email != NULL) {
            add_mailing_list_entry(name, email);
        }
    }
    print_mailing_list();
    free_mailing_list();
    return 0;
}