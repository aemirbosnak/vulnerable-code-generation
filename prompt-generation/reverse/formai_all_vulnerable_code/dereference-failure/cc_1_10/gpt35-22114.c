//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 10

// Define the structure for a node in the bucket list
typedef struct node_tag {
    char *word;
    struct node_tag *next;
} node_t;

// Define the structure for a bucket
typedef struct {
    int count;
    node_t *head;
} bucket_t;

// Function to insert a word into a bucket list
void insert_word(bucket_t *buckets, char *word, int length) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->word = (char*) malloc((length+1) * sizeof(char));
    strcpy(new_node->word, word);
    new_node->next = buckets[length].head;
    buckets[length].head = new_node;
    buckets[length].count++;
}

// Function to print out the sorted list of words
void print_words(bucket_t *buckets) {
    printf("\nHere are the sorted happy words:\n");
    for(int i = 0; i < NUM_BUCKETS; i++) {
        node_t *current_node = buckets[i].head;
        while(current_node != NULL) {
            printf("%s\n", current_node->word);
            current_node = current_node->next;
        }
    }
}

int main() {
    char *word_list[] = {"happy", "joyful", "blissful", "ecstatic", "content", "pleased", "jubilant", "delighted", "thrilled", "overjoyed", "elated", "merry", "cheerful", "glad", "exhilarated", "radiant", "smiling", "gleeful", "grinning", "peaceful", "carefree", "fun-loving", "untroubled", "jovial", "festive", "upbeat", "optimistic", "enthusiastic", "energetic", "spirited", "lively", "bubbly", "vibrant", "buoyant", "hopeful", "heart-warming", "exultant", "euphoric", "pleasurable", "exquisite", "blithesome", "enjoyable", "amusing", "jocular", "comic", "facetious", "humorous", "whimsical", "playful", "boisterous", "rollicking", "mirthful"};
    int num_words = sizeof(word_list) / sizeof(char*);
    bucket_t buckets[NUM_BUCKETS] = {0};

    // Insert each word into the correct bucket
    for(int i = 0; i < num_words; i++) {
        int length = strlen(word_list[i]);
        insert_word(buckets, word_list[i], length);
    }

    // Print out the sorted list of words
    print_words(buckets);

    // Free memory allocated for the bucket lists
    for(int i = 0; i < NUM_BUCKETS; i++) {
        node_t *current_node = buckets[i].head;
        while(current_node != NULL) {
            node_t *next_node = current_node->next;
            free(current_node->word);
            free(current_node);
            current_node = next_node;
        }
    }

    return 0;
}