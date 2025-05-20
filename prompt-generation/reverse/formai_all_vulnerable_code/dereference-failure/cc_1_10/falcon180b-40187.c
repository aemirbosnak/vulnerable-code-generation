//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LEN 100

struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node* next;
};

struct node* create_node(char* word) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void add_word(struct node** head, char* word) {
    struct node* curr_node = *head;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->word, word) == 0) {
            curr_node->count++;
            return;
        }
        curr_node = curr_node->next;
    }
    curr_node = create_node(word);
    curr_node->next = *head;
    *head = curr_node;
}

void display_word_counts(struct node* head, FILE* output) {
    while (head!= NULL) {
        fprintf(output, "%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

int main(int argc, char** argv) {
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    struct node* word_counts = NULL;

    char word[MAX_WORD_LEN];
    while (fscanf(input_file, "%s", word)!= EOF) {
        add_word(&word_counts, word);
    }

    fclose(input_file);

    FILE* output_file = fopen("word_counts.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file: word_counts.txt\n");
        return 1;
    }

    display_word_counts(word_counts, output_file);

    fclose(output_file);
    return 0;
}