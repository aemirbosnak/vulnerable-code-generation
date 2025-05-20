//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>

#define SEARCH_STR "The quick brown fox jumps over the lazy dog"
#define MAX_LEN 50

struct node {
    char word[MAX_LEN];
    struct node *next;
};

struct node* search(struct node* head, char* str) {
    struct node* current = head;
    struct node* previous = NULL;
    int i = 0;

    while (current != NULL) {
        if (strcmp(current->word, str) == 0) {
            if (previous == NULL) {
                return current;
            } else {
                previous->next = current->next;
                current->next = NULL;
                return current;
            }
        }
        previous = current;
        current = current->next;
        i++;
    }
    return NULL;
}

int main() {
    struct node* head = NULL;
    char search_str[MAX_LEN];

    // Create a list of words
    for (int i = 0; i < 10; i++) {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->word[0] = i % 2 ? 'a' : 'b';
        new_node->word[1] = i % 2 ? 'c' : 'd';
        new_node->next = head;
        head = new_node;
    }

    // Search for a word
    search_str[0] = 'q';
    search_str[1] = 'u';
    search_str[2] = 'i';
    search_str[3] = 'c';
    search_str[4] = 'k';
    search_str[5] = 'b';
    search_str[6] = 't';
    search_str[7] = 'f';
    search_str[8] = 'o';
    search_str[9] = 'x';

    struct node* result = search(head, search_str);

    // Print the result
    if (result != NULL) {
        printf("Found %s\n", result->word);
    } else {
        printf("Not found\n");
    }

    return 0;
}