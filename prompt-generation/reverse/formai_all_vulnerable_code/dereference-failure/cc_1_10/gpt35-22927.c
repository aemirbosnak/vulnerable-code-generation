//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char word[50];
    int frequency;
    struct node *next;
};

struct node *head = NULL;

int add_word(char *word) {
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            temp->frequency++;
            return 0;
        }
        temp = temp->next;
    }
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    strncpy(new_node->word, word, sizeof(new_node->word));
    new_node->frequency = 1;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    return 0;
}

void display_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%s : %d\n", temp->word, temp->frequency);
        temp = temp->next;
    }
}

void remove_list() {
    struct node *temp1 = head;
    struct node *temp2 = NULL;
    while (temp1 != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }
}

int main(int argc, char *argv[]) {
    int i = 1;
    char *filename = NULL;
    while (i < argc) {
        if (strcmp(argv[i], "--file") == 0 && i+1 < argc) {
            filename = argv[i+1];
        }
        i++;
    }
    if (filename == NULL) {
        printf("Please provide a filename using the --file option.\n");
        return -1;
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return -1;
    }
    char word[50];
    memset(word, 0, sizeof(word));
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[count] = tolower(c);
            count++;
        } else if (count > 0) {
            word[count] = '\0';
            add_word(word);
            memset(word, 0, sizeof(word));
            count = 0;
        }
    }
    if (count > 0) {
        word[count] = '\0';
        add_word(word);
        count = 0;
    }
    fclose(fp);
    display_list();
    remove_list();
    return 0;
}