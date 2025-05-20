//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_CODES 256
#define MAX_TREE_HEIGHT 10

// Huffman tree node
typedef struct node {
    char data;  // character
    int frequency;  // frequency
    struct node *left, *right;
} node;

// Codes struct to store Huffman codes
typedef struct codes {
    char code[32];
    char data;
} codes;

// function prototypes
node* new_node(char, int);
void generate_codes(node*, char*, codes*, int);
void encode(char*, codes*, char*);
void decode(char*, node*, char*);

int main() {
    char input[MAX_INPUT_SIZE];
    char compressed_message[MAX_INPUT_SIZE];
    char decompressed_message[MAX_INPUT_SIZE];
    char input_copy[MAX_INPUT_SIZE];
    int input_length, compressed_length, decompressed_length, choice;

    printf("Enter the text to be compressed: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_length = strlen(input);

    strcpy(input_copy, input);

    // frequency array
    int freq[MAX_CODES] = {0};
    for (int i = 0; i < input_length; i++) {
        freq[(int)input[i]]++;
    }

    // priority queue of nodes
    int num_nodes = 0;
    node *queue[MAX_CODES] = {NULL};
    for (int i = 0; i < MAX_CODES; i++) {
        if (freq[i] != 0) {
            queue[num_nodes++] = new_node((char)i, freq[i]);
        }
    }

    // Huffman tree generation
    while (num_nodes > 1) {
        // extract two minimum frequency nodes
        node *node1 = queue[num_nodes-1];
        node *node2 = queue[num_nodes-2];
        num_nodes -= 2;

        // create a new node with sum of frequencies of two nodes
        node *new = new_node('*', node1->frequency + node2->frequency);
        new->left = node1;
        new->right = node2;

        // add new node back to queue
        int i;
        for (i = 0; i < num_nodes; i++) {
            if (queue[i]->frequency < new->frequency) {
                break;
            }
        }
        for (int j = num_nodes; j > i; j--) {
            queue[j] = queue[j-1];
        }
        queue[i] = new;
        num_nodes++;
    }

    // Generate Huffman Codes
    codes code_list[MAX_CODES];
    generate_codes(queue[0], "", code_list, 0);

    // Print the codes
    printf("Huffman Codes: \n");
    for (int i = 0; i < MAX_CODES; i++) {
        if (strlen(code_list[i].code) > 0) {
            printf("%c: %s\n", code_list[i].data, code_list[i].code);
        }
    }

    printf("\nEnter 1 to compress, 2 to decompress: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Encoding
        encode(input, code_list, compressed_message);
        compressed_length = strlen(compressed_message);

        printf("\nCompressed Message: %s\n", compressed_message);
        printf("Compressed Message Length: %d bits\n", compressed_length);

    } else if (choice == 2) {
        // Decoding
        decode(input_copy, queue[0], decompressed_message);
        decompressed_length = strlen(decompressed_message);

        printf("\nDecompressed Message: %s\n", decompressed_message);
        printf("Decompressed Message Length: %d bits\n", decompressed_length);

    } else {
        printf("\nInvalid Choice\n");
    }

    return 0;
}

// Helper function to create a new node
node* new_node(char data, int frequency) {
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->frequency = frequency;
    new->left = new->right = NULL;
    return new;
}

// Helper function to generate codes recursively
void generate_codes(node* root, char* code, codes* code_list, int index) {
    if (root->left) {
        char* left_code = (char*) malloc(strlen(code)+2);
        strcpy(left_code, code);
        strcat(left_code, "0");
        generate_codes(root->left, left_code, code_list, index+1);
    }
    if (root->right) {
        char* right_code = (char*) malloc(strlen(code)+2);
        strcpy(right_code, code);
        strcat(right_code, "1");
        generate_codes(root->right, right_code, code_list, index+1);
    }
    if (!root->left && !root->right) {
        code_list[index].data = root->data;
        strcpy(code_list[index].code, code);
    }
}

// Helper function to encode the message
void encode(char* input, codes* code_list, char* compressed_message) {
    int input_length = strlen(input);
    int index = 0;
    for (int i = 0; i < input_length; i++) {
        for (int j = 0; j < MAX_CODES; j++) {
            if (code_list[j].data == input[i]) {
                strcat(compressed_message, code_list[j].code);
                index += strlen(code_list[j].code);
                break;
            }
        }
    }
    compressed_message[index] = '\0';
}

// Helper function to decode the message
void decode(char* input, node* root, char* decompressed_message) {
    int compressed_len = strlen(input);
    node* curr_node = root;
    int index = 0;
    for (int i = 0; i < compressed_len; i++) {
        if (input[i] == '0') {
            curr_node = curr_node->left;
        } else {
            curr_node = curr_node->right;
        }
        if (curr_node->left == NULL && curr_node->right == NULL) {
            decompressed_message[index++] = curr_node->data;
            curr_node = root;
        }
    }
    decompressed_message[index] = '\0';
}