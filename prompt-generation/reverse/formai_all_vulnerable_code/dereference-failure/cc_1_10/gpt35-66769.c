//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

// define a structure to store each word and its occurrence count
typedef struct node {
    char word[MAX_WORD_SIZE];
    int count;
    struct node *next;
} Node;

// function to create a new node with the given word and count
Node* create_node(char* word, int count) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->word, word);
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

// function to insert a new node at the end of the linked list
void insert_node(Node** head_ref, Node* new_node) {
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// function to traverse the linked list and print each node
void print_nodes(Node* head) {
    printf("Word\tCount\n");
    printf("------------\n");
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\t%d\n", temp->word, temp->count);
        temp = temp->next;
    }
}

// function to free the memory of the linked list
void free_nodes(Node** head_ref) {
    Node* temp = *head_ref;
    while (temp != NULL) {
        *head_ref = (*head_ref)->next;
        free(temp);
        temp = *head_ref;
    }
}

int main() {
    // open the input file
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    // create an empty linked list
    Node* head = NULL;

    // read each word from the input file and insert into linked list
    char word[MAX_WORD_SIZE];
    while (fscanf(fp, "%s", word) == 1) {
        // convert word to lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        // find the node with the same word
        int found = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (strcmp(temp->word, word) == 0) {
                temp->count++;
                found = 1;
                break;
            }
            temp = temp->next;
        }

        // if word not found, create a new node and insert into linked list
        if (!found) {
            Node* new_node = create_node(word, 1);
            insert_node(&head, new_node);
        }
    }

    // close the input file
    fclose(fp);

    // print the word count results
    print_nodes(head);

    // free the memory of the linked list
    free_nodes(&head);

    return 0;
}