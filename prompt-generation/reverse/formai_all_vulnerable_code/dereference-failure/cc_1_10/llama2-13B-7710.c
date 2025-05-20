//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 1024
#define MAX_ARRAY_SIZE 64

typedef struct heap_node {
    int key;
    void* data;
    struct heap_node* parent;
    struct heap_node* left;
    struct heap_node* right;
} heap_node_t;

typedef struct array {
    int capacity;
    int size;
    void** elements;
} array_t;

void* malloc_with_tracking(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        fprintf(stderr, "Failed to allocate memory: %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return mem;
}

void free_with_tracking(void* mem) {
    if (mem == NULL) {
        fprintf(stderr, "Attempt to free null memory\n");
        exit(EXIT_FAILURE);
    }
    free(mem);
}

heap_node_t* create_heap(int size) {
    heap_node_t* heap = calloc(size, sizeof(heap_node_t));
    for (int i = 0; i < size; i++) {
        heap[i].key = i * 2;
        heap[i].data = malloc_with_tracking(sizeof(int));
        *((int*)heap[i].data) = i * 2;
        heap[i].parent = NULL;
        heap[i].left = NULL;
        heap[i].right = NULL;
    }
    return heap;
}

void heap_insert(heap_node_t** heap, int key, void* data) {
    heap_node_t* new_node = malloc_with_tracking(sizeof(heap_node_t));
    new_node->key = key;
    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = *heap;
    *heap = new_node;
}

void heap_delete(heap_node_t** heap, int key) {
    if (*heap == NULL) {
        return;
    }
    if ((*heap)->key == key) {
        if ((*heap)->left == NULL && (*heap)->right == NULL) {
            free_with_tracking((*heap)->data);
            free((*heap));
            *heap = NULL;
        } else {
            heap_node_t* temp = (*heap)->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = (*heap)->right;
            (*heap)->right = NULL;
            free_with_tracking((*heap)->data);
            free((*heap));
            *heap = temp;
        }
    } else {
        if ((*heap)->left != NULL) {
            heap_delete(&(*heap)->left, key);
        }
    }
}

array_t* create_array(int size) {
    array_t* array = calloc(size, sizeof(array_t));
    for (int i = 0; i < size; i++) {
        array[i].capacity = 16;
        array[i].size = 0;
        array[i].elements = calloc(array[i].capacity, sizeof(void*));
    }
    return array;
}

void array_insert(array_t* array, void* data) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->elements = realloc(array->elements, array->capacity * sizeof(void*));
    }
    array->elements[array->size] = data;
    array->size++;
}

void array_delete(array_t* array, void* data) {
    for (int i = 0; i < array->size; i++) {
        if (array->elements[i] == data) {
            for (int j = i; j < array->size - 1; j++) {
                array->elements[j] = array->elements[j + 1];
            }
            array->size--;
            break;
        }
    }
}

int main() {
    heap_node_t* heap = create_heap(10);
    array_t* array = create_array(10);

    for (int i = 0; i < 10; i++) {
        heap_insert(&heap, i * 2, malloc_with_tracking(sizeof(int)));
        array_insert(array, (void*)i);
    }

    for (int i = 0; i < 10; i++) {
        heap_delete(&heap, i * 2);
        array_delete(array, (void*)i);
    }

    return 0;
}