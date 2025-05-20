//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CHARS 256
#define DEBUG false

typedef struct Node {
    unsigned char value;    // character value
    int freq;               // frequency
    bool is_leaf;           // represents leaf node
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(unsigned char value, int freq, bool is_leaf) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->freq = freq;
    node->is_leaf = is_leaf;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swap_node(Node **n1, Node **n2) {
    Node *temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void insertion_sort(Node **arr, int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        Node *key = arr[i];
        for (j = i - 1; j >= 0 && arr[j]->freq > key->freq; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}

void min_heapify(Node **arr, int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && arr[left]->freq < arr[smallest]->freq) 
        smallest = left;

    if (right < size && arr[right]->freq < arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap_node(&arr[i], &arr[smallest]);
        min_heapify(arr, size, smallest);
    }
}

Node *build_huffman_tree(Node **arr, int size) {
    while (size > 1) {
        insertion_sort(arr, size);
        Node *min1 = arr[0];
        swap_node(&arr[0], &arr[size-1]);
        size--;
        min_heapify(arr, size, 0);
        Node *min2 = arr[0];
        swap_node(&arr[0], &arr[size-1]);
        size--;
        Node *parent = create_node('\0', min1->freq + min2->freq, false);
        parent->left = min1;
        parent->right = min2;
        arr[size] = parent;
        size++;
        min_heapify(arr, size, size-1);
    }
    return arr[0];
}

void huffman_traversal(Node *root, int *arr, int index, int **codes, char **symbols) {
    if (root->left) {
        arr[index] = 0;
        huffman_traversal(root->left, arr, index+1, codes, symbols);
    }
    if (root->right) {
        arr[index] = 1;
        huffman_traversal(root->right, arr, index+1, codes, symbols);
    }
    if (root->is_leaf) {
        int len = index;
        int *code = (int*)malloc(len*sizeof(int));
        strncpy(*symbols, (char*)&root->value, sizeof(char));
        for (int i = 0; i < len; i++)
            code[i] = arr[i];
        codes[root->value] = code;
        (*symbols)++;
    }
}

int **generate_huffman_codes(Node *root, char **symbols) {
    int *arr = (int*)malloc(NUM_CHARS*sizeof(int));
    int **codes = (int**)malloc(NUM_CHARS*sizeof(int*));
    memset(codes, 0, NUM_CHARS*sizeof(int*));
    huffman_traversal(root, arr, 0, codes, symbols);
    return codes;
}

void free_codes(int **codes) {
    for (int i = 0; i < NUM_CHARS; i++)
        free(codes[i]);
    free(codes);
}

void print_bits(int *bits, int len) {
    for (int i = 0; i < len; i++)
        printf("%d", bits[i]);
}

void print_codes(int **codes) {
    for (int i = 0; i < NUM_CHARS; i++) {
        if (codes[i]) {
            printf("%c: ", (char)i);
            print_bits(codes[i], strlen((char*)codes[i]));
            printf("\n");
        }
    }
}

void encode_huffman(char *str, int **codes, int *bits, int *len) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        int *code = codes[(int)str[i]];
        int code_len = strlen((char*)code);
        if (code) {
            for (int j = 0; j < code_len; j++)
                bits[(*len)++] = code[j];
        }
    }
}

int main() {
    // paranoid security measures
    int pass_len = 0;
    char *password = (char*)malloc(sizeof(char)*pass_len);
    while (pass_len != 16) {
        printf("Enter a 16 character password: ");
        scanf("%s", password);
        pass_len = strlen(password);
        if (pass_len != 16)
            printf("Invalid length. Must be 16 characters.\n");
    }
    password[16] = '\0';
    memset(password, '\0', pass_len);

    // sample string to encode
    char *str = "example input string here!";

    // initialize frequency array with zeroes
    int freq[NUM_CHARS];
    memset(freq, 0, NUM_CHARS*sizeof(int));

    // calculate frequency of each character in string
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++)
        freq[(int)str[i]]++;

    // create leaf nodes for each character
    Node* arr[NUM_CHARS];
    int size = 0;
    for (int i = 0; i < NUM_CHARS; i++) {
        if (freq[i] > 0) {
            Node *node = create_node((unsigned char)i, freq[i], true);
            arr[size++] = node;
        }
    }

    // build Huffman tree
    Node *root = build_huffman_tree(arr, size);

    // generate Huffman codes for each character
    char *symbols = (char*)malloc(NUM_CHARS*sizeof(char));
    memset(symbols, '\0', NUM_CHARS*sizeof(char));
    int **codes = generate_huffman_codes(root, &symbols);

    // print Huffman codes for each character
    if (DEBUG) print_codes(codes);

    // encode string using Huffman codes
    int bits[str_len*8];
    int len = 0;
    memset(bits, '\0', str_len*8*sizeof(int));
    encode_huffman(str, codes, bits, &len);

    // print encoded bits
    if (DEBUG) {
        printf("Encoded bits:\n");
        print_bits(bits, len);
        printf("\n");
    }

    // paranoid security measures
    free_codes(codes);
    free(symbols);
    memset(str, '\0', str_len);
    memset(bits, '\0', len);
    str_len = 0;
    len = 0;

    return 0;
}