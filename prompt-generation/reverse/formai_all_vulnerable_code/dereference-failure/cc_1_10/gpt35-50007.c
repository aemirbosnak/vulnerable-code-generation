//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define CODE_SIZE 8

typedef struct node {
    char symbol;
    int frequency;
    struct node* left;
    struct node* right;
} Node;

void sort_nodes(Node** nodes, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(nodes[j]->frequency > nodes[j+1]->frequency) {
                Node* temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }
}

Node* create_node(char symbol, int frequency) {
    Node* node = malloc(sizeof(Node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert_node(Node** nodes, int* n, Node* node) {
    nodes[*n] = node;
    (*n)++;
}

Node* get_huffman_tree(Node** nodes, int n) {
    while(n > 1) {
        sort_nodes(nodes, n);
        
        Node* left = nodes[0];
        Node* right = nodes[1];
        
        Node* parent = create_node(' ', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        
        nodes[0] = parent;
        for(int i=1; i<n-1; i++) {
            nodes[i] = nodes[i+1];
        }
        n--;
    }
    
    return nodes[0];
}

void print_codes(Node* root, int code[], int len, char codes[][CODE_SIZE], int* idx) {
    if(root == NULL) {
        return;
    }
    
    if(root->left == NULL && root->right == NULL) {
        code[len] = '\0';
        strcpy(codes[*idx], code);
        (*idx)++;
    }
    else {
        code[len] = '0';
        print_codes(root->left, code, len+1, codes, idx);
        
        code[len] = '1';
        print_codes(root->right, code, len+1, codes, idx);
    }
}

void encode_data(char data[], char codes[][CODE_SIZE], char* output) {
    int i = 0;
    while(data[i] != '\0') {
        char code[CODE_SIZE] = "";
        for(int j=0; j<strlen(codes[data[i]]); j++) {
            code[j] = codes[data[i]][j];
        }
        strcat(output, code);
        i++;
    }
}

void decode_data(Node* root, char* data, char* output) {
    Node* curr = root;
    int i = 0;
    while(data[i] != '\0') {
        if(data[i] == '0') {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
        if(curr->left == NULL && curr->right == NULL) {
            sprintf(output, "%s%c", output, curr->symbol);
            curr = root;
        }
        i++;
    }
}

int main() {
    char input[MAX_LEN] = "hello world";
    Node* nodes[MAX_LEN];
    int n = 0;
    
    // Calculate frequency of each character
    int freq[128] = {0};
    int i = 0;
    while(input[i] != '\0') {
        freq[(int)input[i]]++;
        i++;
    }
    
    // Create leaf nodes for each character and insert them into nodes array
    for(i=0; i<128; i++) {
        if(freq[i] > 0) {
            Node* node = create_node((char)i, freq[i]);
            insert_node(nodes, &n, node);
        }
    }
    
    Node* root = get_huffman_tree(nodes, n);
    
    // Get codes for each character
    char codes[128][CODE_SIZE];
    int code[CODE_SIZE];
    int idx = 0;
    print_codes(root, code, 0, codes, &idx);
    
    // Encode input data using Huffman coding
    char* encoded = malloc(10*MAX_LEN*sizeof(char));
    encode_data(input, codes, encoded);
    
    // Decode encoded data using Huffman coding
    char* decoded = malloc(MAX_LEN*sizeof(char));
    decode_data(root, encoded, decoded);
    
    printf("Input Data: %s\n", input);
    printf("Encoded Data: %s\n", encoded);
    printf("Decoded Data: %s\n", decoded);
    
    free(encoded);
    free(decoded);
    return 0;
}