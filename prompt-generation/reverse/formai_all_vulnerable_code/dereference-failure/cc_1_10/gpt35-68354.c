//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
};

struct node *new_node(char ch, int freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

int is_leaf(struct node *node)
{
    return (node->left == NULL && node->right == NULL);
}

void print_codes(struct node *root, int code[], int top)
{
    if (root->left) {
        code[top] = 0;
        print_codes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        print_codes(root->right, code, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void destroy_tree(struct node *node)
{
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

void compress(char *str)
{
    if (str == NULL) {
        return;
    }

    int freq[MAX_CHARS] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    struct node *heap[MAX_CHARS];
    int heap_size = 0;
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            heap[heap_size++] = new_node((char)i, freq[i]);
        }
    }

    while (heap_size > 1) {
        struct node *left = heap[--heap_size];
        struct node *right = heap[--heap_size];
        struct node *parent = new_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        heap[heap_size++] = parent;
    }

    struct node *root = heap[0];
    int code[MAX_CHARS];
    int top = 0;

    printf("Huffman Codes:\n");
    print_codes(root, code, top);

    destroy_tree(root);
}

int main()
{
    char str[] = "Hello, World!";
    printf("Original String: %s\n", str);
    compress(str);
    return 0;
}