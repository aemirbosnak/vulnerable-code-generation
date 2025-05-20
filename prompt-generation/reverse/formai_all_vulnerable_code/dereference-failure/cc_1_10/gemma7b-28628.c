//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct watermark_t {
    char *data;
    int size;
    struct watermark_t *next;
} watermark_t;

void watermark_insert(watermark_t **head, char *data, int size) {
    watermark_t *new_node = malloc(sizeof(watermark_t));
    new_node->data = strdup(data);
    new_node->size = size;
    new_node->next = NULL;

    if (*head) {
        (*head)->next = new_node;
    } else {
        *head = new_node;
    }
}

int watermark_search( watermark_t *head, char *data ) {
    while (head) {
        if (strcmp(head->data, data) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
     watermark_t *head = NULL;

    // Insert watermark data
    watermark_insert(&head, "Secret message", 20);
    watermark_insert(&head, "Hidden data", 15);

    // Search for watermark data
    if (watermark_search(head, "Secret message") == 1) {
        printf("Watermark found!\n");
    } else {
        printf("Watermark not found.\n");
    }

    return 0;
}