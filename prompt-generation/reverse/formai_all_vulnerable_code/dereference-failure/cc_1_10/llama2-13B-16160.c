//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 100
#define MAX_STRING_LENGTH 100

typedef struct heap {
    int data;
    struct heap *left;
    struct heap *right;
} heap;

typedef struct string {
    char *data;
    int length;
} string;

heap *create_heap(void) {
    heap *h = (heap *)malloc(sizeof(heap));
    h->data = 0;
    h->left = h->right = NULL;
    return h;
}

void insert_heap(heap *h, int data) {
    heap *new_h = (heap *)malloc(sizeof(heap));
    new_h->data = data;
    new_h->left = h->left;
    new_h->right = h->right;
    if (h->left == NULL) {
        h->left = new_h;
    } else if (h->right == NULL) {
        h->right = new_h;
    } else {
        int left_max = h->left->data;
        int right_max = h->right->data;
        if (data > left_max) {
            h->left = new_h;
        } else if (data > right_max) {
            h->right = new_h;
        }
    }
}

void delete_heap(heap *h) {
    if (h == NULL) {
        return;
    }
    if (h->left == NULL) {
        free(h);
        h = h->right;
    } else if (h->right == NULL) {
        free(h);
        h = h->left;
    } else {
        int max_data = h->left->data;
        heap *max_heap = h->left;
        while (max_heap->right != NULL) {
            max_heap = max_heap->right;
        }
        free(max_heap);
        h = h->right;
    }
    delete_heap(h);
}

string *create_string(const char *data) {
    string *s = (string *)malloc(sizeof(string));
    s->data = (char *)malloc(strlen(data) + 1);
    strcpy(s->data, data);
    s->length = strlen(data) + 1;
    return s;
}

void print_string(string *s) {
    printf("%s\n", s->data);
}

int main(void) {
    heap *h = create_heap();
    string *s1 = create_string("apple");
    string *s2 = create_string("banana");
    string *s3 = create_string("cherry");
    insert_heap(h, 10);
    insert_heap(h, 5);
    insert_heap(h, 15);
    insert_heap(h, 20);
    print_string(s1);
    print_string(s2);
    print_string(s3);
    delete_heap(h);
    return 0;
}