//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define MAP_FAILED  (-1)
#define PAGE_SIZE    (4096)

struct mem_node {
    void* addr;
    size_t size;
    struct mem_node* next;
};

struct mem_tree {
    struct mem_node* root;
};

void* mem_alloc(size_t size) {
    void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    return addr;
}

void mem_free(void* addr) {
    munmap(addr, PAGE_SIZE);
}

struct mem_tree* mem_tree_create() {
    struct mem_tree* tree = malloc(sizeof(*tree));
    tree->root = NULL;
    return tree;
}

void mem_tree_destroy(struct mem_tree* tree) {
    struct mem_node* node = tree->root;
    while (node != NULL) {
        struct mem_node* next = node->next;
        mem_free(node->addr);
        free(node);
        node = next;
    }
    free(tree);
}

void mem_tree_traverse(struct mem_tree* tree, void(*fn)(void*)) {
    struct mem_node* node = tree->root;
    while (node != NULL) {
        fn(node->addr);
        node = node->next;
    }
}

int main() {
    struct mem_tree* tree = mem_tree_create();

    // Create some memory blocks
    void* block1 = mem_alloc(1024);
    void* block2 = mem_alloc(2048);
    void* block3 = mem_alloc(3072);

    // Add the memory blocks to the tree
    struct mem_node* node1 = malloc(sizeof(*node1));
    node1->addr = block1;
    node1->size = 1024;
    node1->next = tree->root;
    tree->root = node1;

    struct mem_node* node2 = malloc(sizeof(*node2));
    node2->addr = block2;
    node2->size = 2048;
    node2->next = NULL;
    tree->root = node2;

    struct mem_node* node3 = malloc(sizeof(*node3));
    node3->addr = block3;
    node3->size = 3072;
    node3->next = NULL;
    tree->root = node3;

    // Traverse the tree and print the memory usage
    mem_tree_traverse(tree, (void(*)())printf);

    // Free the memory blocks and the tree
    mem_free(block1);
    mem_free(block2);
    mem_free(block3);
    mem_tree_destroy(tree);

    return 0;
}