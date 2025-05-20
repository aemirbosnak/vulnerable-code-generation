//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct node {
    char *data;
    struct node *next;
};

struct node *compress(char *str) {
    struct node *head = NULL, *current = NULL, *previous = NULL;
    int i, j, count = 0;

    // Step 1: Create a linked list of all unique characters in the input string
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            if (current == NULL) {
                current = (struct node *) malloc(sizeof(struct node));
                current->data = str[i];
                current->next = head;
                head = current;
            } else {
                previous->next = current;
                previous = current;
                current = (struct node *) malloc(sizeof(struct node));
                current->data = str[i];
                current->next = head;
                head = current;
            }
            count++;
        }
    }

    // Step 2: Compress the linked list by removing duplicate characters
    for (i = 1; i < count; i++) {
        for (j = 0; j < i; j++) {
            if (head->data == head->next->data) {
                head->next->data = '\0';
            }
        }
        head = head->next;
    }

    // Step 3: Convert the compressed linked list back to a string
    char *compressed_str = NULL;
    current = head;
    i = 0;
    while (current != NULL) {
        compressed_str[i] = current->data;
        i++;
        current = current->next;
    }
    compressed_str[i] = '\0';

    return compressed_str;
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    char *compressed_str = compress(str);
    printf("%s\n", compressed_str);
    free(compressed_str);
    return 0;
}