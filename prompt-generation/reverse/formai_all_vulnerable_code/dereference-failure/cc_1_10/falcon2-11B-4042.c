//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int freq;
    char ch;
    struct node* left;
    struct node* right;
};

struct node* create_node(char ch, int freq) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_node(struct node* node) {
    if (node!= NULL) {
        free_node(node->left);
        free_node(node->right);
        free(node);
    }
}

void build_huffman_tree(struct node** root, int** freq, int n) {
    int i, j, max_freq = 0;
    for (i = 0; i < n; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            j = i;
        }
    }
    *root = create_node('\0', max_freq);
    free(freq[j]);
    freq[j] = NULL;
    for (i = 0; i < n; i++) {
        if (freq[i] == max_freq) {
            free(freq[i]);
            freq[i] = NULL;
            build_huffman_tree(&(*root)->left, freq, n-1);
            build_huffman_tree(&(*root)->right, freq, n-1);
            break;
        }
    }
}

void print_huffman_tree(struct node* node) {
    if (node!= NULL) {
        print_huffman_tree(node->left);
        printf("%d %c\n", node->freq, node->ch);
        print_huffman_tree(node->right);
    }
}

int** get_freq(char* str, int n) {
    int i, j, **freq;
    freq = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        freq[i] = (int*) malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            freq[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (str[i] == str[j]) {
                freq[i][j] = freq[i][j] + 1;
            }
        }
    }
    return freq;
}

char* huffman_encode(char* str, int* freq, int n) {
    struct node* root = NULL;
    int i, j;
    int** freq_copy = get_freq(str, n);
    build_huffman_tree(&root, freq_copy, n);
    char* encoded = (char*) malloc(n * sizeof(char));
    for (i = 0; i < n; i++) {
        if (root->ch == str[i]) {
            encoded[i] = '0';
        } else {
            encoded[i] = '1';
        }
    }
    free(root);
    free(freq_copy);
    return encoded;
}

int main() {
    char str[] = "ABACACAA";
    int freq[26];
    int n = sizeof(str)/sizeof(str[0]);
    int** freq_copy = get_freq(str, n);
    struct node* root = NULL;
    build_huffman_tree(&root, freq_copy, n);
    printf("Huffman Tree:\n");
    print_huffman_tree(root);
    char* encoded = huffman_encode(str, freq, n);
    printf("Encoded String: %s\n", encoded);
    free(encoded);
    free(root);
    free(freq_copy);
    return 0;
}