//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

/* Node structure for linked list */
typedef struct node_t {
    char word[MAX_WORD_LENGTH];
    int freq;
    struct node_t* next;
} node;

/* Function to create a new node with given word and frequency */
node* create_node(char* word, int freq) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    new_node->freq = freq;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a new node at the beginning of the linked list */
void insert_node(node** head_ref, char* word, int freq) {
    node* new_node = create_node(word, freq);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to traverse the linked list and print the word frequency */
void print_list(node* head) {
    printf("Word Frequency\n");
    printf("--------------\n");
    node* curr = head;
    while (curr != NULL) {
        printf("%s %d\n", curr->word, curr->freq);
        curr = curr->next;
    }
}

/* Function to remove duplicate spaces and punctuation marks from input string */
void clean_string(char* str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        } else if (isspace(str[i])) {
            if (j > 0 && !isspace(str[j-1])) {
                str[j++] = ' ';
            }
        }
    }
    str[j] = '\0';
}

/* Function to tokenize input string and calculate word frequency */
void count_words(char* str, node** head_ref) {
    char* token = strtok(str, " ");
    int freq = 1;
    while (token != NULL) {
        node* curr = *head_ref;
        int found = 0;
        while (curr != NULL) {
            if (strcmp(curr->word, token) == 0) {
                curr->freq += 1;
                found = 1;
                break;
            }
            curr = curr->next;
        }
        if (!found) {
            insert_node(head_ref, token, freq);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input_string[1000];
    printf("Enter a string: ");
    fgets(input_string, 1000, stdin);
    clean_string(input_string);
    node* head = NULL;
    count_words(input_string, &head);
    print_list(head);
    return 0;
}