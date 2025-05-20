//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 0xCAFEBEDELL

struct node {
    int data;
    struct node *next;
};

struct compression_struct {
    struct node *head;
    int count;
};

void compression_init(struct compression_struct *compress) {
    compress->head = NULL;
    compress->count = 0;
}

void compression_add(struct compression_struct *compress, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = compress->head;
    compress->head = new_node;
    compress->count++;
}

int compression_get(struct compression_struct *compress) {
    int data = compress->head->data;
    struct node *temp = compress->head;
    compress->head = compress->head->next;
    free(temp);
    return data;
}

int compression_get_count(struct compression_struct *compress) {
    return compress->count;
}

void compression_deinit(struct compression_struct *compress) {
    struct node *temp = compress->head;
    compress->head = NULL;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    compress->count = 0;
}

int main() {
    struct compression_struct compress;
    compression_init(&compress);

    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        compression_add(&compress, data[i]);
    }

    for (int i = 0; i < 10; i++) {
        int retrieved = compression_get(&compress);
        printf("%d ", retrieved);
    }

    printf("\nCompression count: %d\n", compression_get_count(&compress));

    compression_deinit(&compress);

    return 0;
}