//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct node {
    int freq;
    char ch;
    struct node *left, *right;
} node;

typedef struct heap {
    int size;
    node *nodes[MAX_TREE_SIZE];
} heap;

node *create_node(char ch, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

heap *create_heap() {
    heap *new_heap = (heap *)malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

void swap_nodes(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void push(heap *h, node *n) {
    int i = h->size++;
    while (i > 0 && h->nodes[(i - 1) / 2]->freq > n->freq) {
        h->nodes[i] = h->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->nodes[i] = n;
}

node *pop(heap *h) {
    node *root = h->nodes[0];
    h->nodes[0] = h->nodes[--(h->size)];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size && h->nodes[left]->freq < h->nodes[i]->freq) {
            smallest = left;
        }
        if (right < h->size && h->nodes[right]->freq < h->nodes[smallest]->freq) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }
        swap_nodes(&h->nodes[i], &h->nodes[smallest]);
        i = smallest;
    }
    return root;
}

void print_heap(heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%c: %d\n", h->nodes[i]->ch, h->nodes[i]->freq);
    }
}

node *build_huffman_tree(heap *h) {
    while (h->size > 1) {
        node *left = pop(h);
        node *right = pop(h);
        node *new_node = create_node(' ', left->freq + right->freq);
        new_node->left = left;
        new_node->right = right;
        push(h, new_node);
    }
    return pop(h);
}

void print_codes(node *root, char *code, int code_size) {
    if (root == NULL) {
        return;
    }
    if (root->ch != ' ') {
        printf("%c: %s\n", root->ch, code);
    }
    print_codes(root->left, strcat(code, "0"), code_size + 1);
    print_codes(root->right, strcat(code, "1"), code_size + 1);
}

void encode(char *input, char *output) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    char ch;
    int freq[256] = {0};
    while ((ch = fgetc(in)) != EOF) {
        freq[ch]++;
    }
    fclose(in);
    heap *h = create_heap();
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            push(h, create_node(i, freq[i]));
        }
    }
    node *root = build_huffman_tree(h);
    char code[MAX_TREE_SIZE] = "";
    print_codes(root, code, 0);
    in = fopen(input, "r");
    while ((ch = fgetc(in)) != EOF) {
        int code_index = ch;
        while (code_index >= 0) {
            fprintf(out, "%c", code[code_index]);
            code_index -= 2;
        }
    }
    fclose(in);
    fclose(out);
}

void decode(char *input, char *output) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    char ch;
    node *root = NULL;
    node *current = NULL;
    while ((ch = fgetc(in)) != EOF) {
        if (root == NULL) {
            root = create_node(ch, 1);
            current = root;
        } else if (ch == '0') {
            if (current->left == NULL) {
                current->left = create_node(' ', 0);
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = create_node(' ', 0);
            }
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            fprintf(out, "%c", current->ch);
            current = root;
        }
    }
    fclose(in);
    fclose(out);
}

int main() {
    char input[] = "input.txt";
    char output[] = "output.txt";
    encode(input, output);
    decode(output, "decoded.txt");
    return 0;
}