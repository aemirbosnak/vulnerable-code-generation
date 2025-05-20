//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
    struct node* next;
} Node;

Node* create_node(char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_word(Node** root, char* word) {
    Node* new_node = create_node(word);
    Node* curr_node = *root;
    while (curr_node!= NULL && strcmp(curr_node->word, word) < 0) {
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        new_node->next = *root;
        *root = new_node;
    } else {
        new_node->next = curr_node->next;
        curr_node->next = new_node;
    }
}

void print_index(Node* root) {
    Node* curr_node = root;
    while (curr_node!= NULL) {
        printf("%s %d\n", curr_node->word, curr_node->count);
        curr_node = curr_node->next;
    }
}

void delete_word(Node** root, char* word) {
    Node* curr_node = *root;
    while (curr_node!= NULL && strcmp(curr_node->word, word) < 0) {
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        return;
    }
    if (curr_node->next == NULL) {
        *root = NULL;
        free(curr_node);
        return;
    }
    Node* temp_node = curr_node->next;
    curr_node->next = temp_node->next;
    free(temp_node);
}

int main() {
    Node* root = NULL;
    int choice, flag = 1;
    while (flag) {
        printf("1. Insert Word\n2. Print Index\n3. Delete Word\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char word[MAX_WORD_LEN];
                printf("Enter Word: ");
                scanf("%s", word);
                insert_word(&root, word);
                break;
            }
            case 2: {
                print_index(root);
                break;
            }
            case 3: {
                char word[MAX_WORD_LEN];
                printf("Enter Word: ");
                scanf("%s", word);
                delete_word(&root, word);
                break;
            }
            case 4: {
                flag = 0;
                break;
            }
            default: {
                printf("Invalid Choice\n");
            }
        }
    }
    return 0;
}