//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

typedef struct heap {
    int size;
    node **nodes;
} heap;

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void insert(heap *h, node *n) {
    h->nodes[h->size++] = n;
    int i = h->size - 1;
    while (i > 0 && h->nodes[i]->frequency < h->nodes[(i - 1) / 2]->frequency) {
        swap(&h->nodes[i], &h->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node *extract_min(heap *h) {
    node *min = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (h->nodes[left]->frequency < h->nodes[i]->frequency) {
            smallest = left;
        }
        if (right < h->size && h->nodes[right]->frequency < h->nodes[smallest]->frequency) {
            smallest = right;
        }
        if (smallest != i) {
            swap(&h->nodes[i], &h->nodes[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return min;
}

void print_codes(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
        return;
    }
    if (root->left != NULL) {
        char new_code[strlen(code) + 1];
        strcpy(new_code, code);
        strcat(new_code, "0");
        print_codes(root->left, new_code);
    }
    if (root->right != NULL) {
        char new_code[strlen(code) + 1];
        strcpy(new_code, code);
        strcat(new_code, "1");
        print_codes(root->right, new_code);
    }
}

void build_tree(heap *h) {
    while (h->size > 1) {
        node *left = extract_min(h);
        node *right = extract_min(h);
        node *parent = malloc(sizeof(node));
        parent->character = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        insert(h, parent);
    }
}

void build_heap(heap *h, char *text) {
    int frequencies[MAX_SIZE] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        frequencies[text[i]]++;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequencies[i] > 0) {
            node *n = malloc(sizeof(node));
            n->character = i;
            n->frequency = frequencies[i];
            n->left = NULL;
            n->right = NULL;
            insert(h, n);
        }
    }
}

void encode(char *text, char *encoded_text) {
    heap h = {0, malloc(MAX_SIZE * sizeof(node *))};
    build_heap(&h, text);
    build_tree(&h);
    char code[MAX_SIZE] = {0};
    print_codes(h.nodes[0], code);
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        char *code = "";
        for (int k = 0; code[k] != '\0'; k++) {
            if (text[i] == code[k]) {
                encoded_text[j++] = code[k];
            }
        }
        i++;
    }
    encoded_text[j] = '\0';
}

int main() {
    char text[] = "This is a sample text for Huffman coding";
    char encoded_text[strlen(text) * 8 + 1];
    encode(text, encoded_text);
    printf("Encoded text: %s\n", encoded_text);
    return 0;
}