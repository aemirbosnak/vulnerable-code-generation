//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
/* 
Brave Compression Algorithm
Author: Chatbot007
Date: 01/01/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256
#define MAX_LENGTH 1000

void compress(char* input_string, char* encrypted_string);
int count_characters(char* input_string, int* frequency);
int create_huffman_tree(int* frequency);
void build_code(int index, char* prefix, char** codes);
void encode(char* input_string, char** codes, char* encrypted_string);

int main() {

    char *input_string = "compress me brave bot!";
    char encrypted_string[MAX_LENGTH];

    printf("Input String: %s\n", input_string);

    compress(input_string, encrypted_string);

    printf("Encrypted String: %s\n", encrypted_string);

    return 0;
}

void compress(char* input_string, char* encrypted_string) {

    int frequency[MAX_CHARACTERS] = {0};

    // Count the frequency of characters in input string
    int size = count_characters(input_string, frequency);

    // Create Huffman Tree and generate codes for each letter
    int root = create_huffman_tree(frequency);
    char** codes = malloc(sizeof(char*) * MAX_CHARACTERS);
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        codes[i] = malloc(sizeof(char) * (size + 1));
        codes[i][0] = '\0';
    }
    char prefix[MAX_CHARACTERS];
    build_code(root, prefix, codes);

    // Encode input string using Huffman codes
    encode(input_string, codes, encrypted_string);

    // Free memory
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        free(codes[i]);
    }
    free(codes);
}

int count_characters(char* input_string, int* frequency) {

    int size = strlen(input_string);

    for (int i = 0; i < size; i++) {
        frequency[input_string[i]]++;
    }

    return size;
}

typedef struct node {
    int freq;
    char data;
    struct node* left;
    struct node* right;
} node;

node* heap[MAX_CHARACTERS + 1];
int heap_size = 0;

void push(node* n) {
    heap[++heap_size] = n;

    int i = heap_size;
    while (i > 1) {
        if (heap[i]->freq < heap[i/2]->freq) {
            node* tmp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = tmp;
        }
        i /= 2;
    }
}

node* pop() {
    node* result = heap[1];

    heap[1] = heap[heap_size];
    heap[heap_size--] = NULL;

    int i = 1;
    while (i * 2 <= heap_size) {
        int child = i * 2;
        if (child + 1 <= heap_size && heap[child+1]->freq < heap[child]->freq) {
            child++;
        }
        if (heap[i]->freq > heap[child]->freq) {
            node* tmp = heap[i];
            heap[i] = heap[child];
            heap[child] = tmp;
        } else {
            break;
        }
        i = child;
    }

    return result;
}

int create_huffman_tree(int* frequency) {
    // Create nodes for each character with non-zero frequency
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequency[i] != 0) {
            node* n = malloc(sizeof(node));
            n->freq = frequency[i];
            n->data = i;
            n->left = NULL;
            n->right = NULL;
            push(n);
        }
    }

    // Combine nodes with lowest frequency until only 1 node remains
    while (heap_size > 1) {
        node* left = pop();
        node* right = pop();

        node* combined = malloc(sizeof(node));
        combined->freq = left->freq + right->freq;
        combined->data = '\0';
        combined->left = left;
        combined->right = right;

        push(combined);
    }

    return heap[1]->data;
}

void build_code(int index, char* prefix, char** codes) {
    // Add code for character to code array
    if (index >= MAX_CHARACTERS) {
        int code_index = index - MAX_CHARACTERS;
        strcpy(codes[code_index], prefix);
        return;
    }

    // Traverse left subtree
    int left_child = index * 2;
    prefix[left_child-1] = '0';
    prefix[left_child] = '\0';
    build_code(heap[index]->left->data + MAX_CHARACTERS, prefix, codes);

    // Traverse right subtree
    int right_child = index * 2 + 1;
    prefix[left_child-1] = '1';
    prefix[right_child] = '\0';
    build_code(heap[index]->right->data + MAX_CHARACTERS, prefix, codes);
}

void encode(char* input_string, char** codes, char* encrypted_string) {
    int size = strlen(input_string);
    char* binary = malloc(sizeof(char) * (size + 1) * MAX_LENGTH);
    binary[0] = '\0';

    // Convert input_string to binary string using Huffman codes
    for (int i = 0; i < size; i++) {
        strcat(binary, codes[input_string[i] + MAX_CHARACTERS]);
    }

    // Convert binary string to encrypted_string
    int i = 0, k = 0;
    while (binary[i]) {
        char byte = 0;
        for (int j = 0; j < 8 && binary[i]; j++, i++) {
            byte <<= 1;
            if (binary[i] == '1') {
                byte |= 1;
            }
        }
        encrypted_string[k++] = byte;
    }
    encrypted_string[k] = '\0';

    // Free memory
    free(binary);
}