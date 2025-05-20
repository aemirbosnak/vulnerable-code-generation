//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the Huffman tree
typedef struct node{
    char character;     // The character represented by the node
    int frequency;      // The frequency of the character in the input string
    struct node *left;  // Pointer to the left child node
    struct node *right; // Pointer to the right child node
} Node;

// Define a structure to store the Huffman code for each character
typedef struct code{
    char character;     // The character for which the Huffman code is defined
    char *bits;         // The bits that define the Huffman code
} Code;

// Function to create a new node with the given character and frequency
Node *new_node(char character, int frequency){
    Node *node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to swap two nodes in an array
void swap(Node **nodes, int i, int j){
    Node *temp = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = temp;
}

// Function to build the Huffman tree for the given input string
Node *build_tree(char *input){
    int frequencies[256] = {0}; // Initialize array to store the frequency of each character
    int i;

    // Count the frequency of each character in the input string
    for(i=0; input[i]!='\0'; i++){
        frequencies[(int)input[i]]++;
    }

    Node *nodes[256] = {NULL}; // Initialize array to store the tree nodes
    int num_nodes = 0;

    // Create a node for each character with non-zero frequency
    for(i=0; i<256; i++){
        if(frequencies[i] > 0){
            nodes[num_nodes++] = new_node((char)i, frequencies[i]);
        }
    }

    // Build the Huffman tree by merging the two nodes with lowest frequency
    while(num_nodes > 1){
        // Find the two nodes with lowest frequency
        int min1 = 0;
        int min2 = 1;
        if(nodes[min2]->frequency < nodes[min1]->frequency){
            swap(nodes, min1, min2);
        }
        for(i=2; i<num_nodes; i++){
            if(nodes[i]->frequency < nodes[min1]->frequency){
                min2 = min1;
                min1 = i;
            }else if(nodes[i]->frequency < nodes[min2]->frequency){
                min2 = i;
            }
        }

        // Merge the two nodes into a new parent node
        Node *parent = new_node('\0', nodes[min1]->frequency + nodes[min2]->frequency);
        parent->left = nodes[min1];
        parent->right = nodes[min2];

        // Add the parent node to the array
        nodes[min1] = parent;
        nodes[min2] = nodes[--num_nodes];
    }

    // Return the root node of the Huffman tree
    return nodes[0];
}

// Function to generate the Huffman code for each character in the tree
void generate_code(Code *codes, Node *node, char *bits, int index){
    if(node->left){     // Traverse left subtree and append "0" to bits
        bits[index] = '0';
        generate_code(codes, node->left, bits, index+1);
    }
    if(node->right){    // Traverse right subtree and append "1" to bits
        bits[index] = '1';
        generate_code(codes, node->right, bits, index+1);
    }
    if(!node->left && !node->right){    // Leaf node reached, add character and code to Code struct
        codes[node->character].character = node->character;
        codes[node->character].bits = (char*)malloc((strlen(bits)+1)*sizeof(char));
        strcpy(codes[node->character].bits, bits);
    }
}

// Function to encode the input string using the Huffman code
char *encode(char *input, Code *codes){
    int i, j;
    char *output = (char*)malloc(strlen(input)*sizeof(char));
    char temp[256] = {0};

    // Convert each character in the input string to its Huffman code
    for(i=0; input[i]!='\0'; i++){
        strcat(temp, codes[input[i]].bits);  // Append Huffman code to temp string
        if(strlen(temp) >= 8){              // If temp string has 8 bits, convert to char and add to output string
            char c = 0;
            for(j=0; j<8; j++){
                if(temp[j] == '1'){
                    c |= 1 << (7-j);       // Set the bit at position 7-j to 1
                }
            }
            output[i/8] = c;
            strcpy(temp, &temp[8]);         // Remove the first 8 bits from temp string
        }
    }

    // If temp string has less than 8 bits remaining, pad with "0"s and convert to char
    if(strlen(temp) > 0){
        while(strlen(temp) < 8){
            strcat(temp, "0");
        }
        char c = 0;
        for(j=0; j<8; j++){
            if(temp[j] == '1'){
                c |= 1 << (7-j);           // Set the bit at position 7-j to 1
            }
        }
        output[i/8] = c;
    }

    return output;
}

int main(){
    char input[] = "hello world";
    Node *root = build_tree(input);

    Code codes[256] = {{'\0', NULL}};
    char bits[256] = {0};
    generate_code(codes, root, bits, 0);

    int i;
    for(i=0; i<256; i++){
        if(codes[i].bits != NULL){
            printf("%c : %s\n", codes[i].character, codes[i].bits);
        }
    }

    char *output = encode(input, codes);
    printf("Encoded string: ");
    for(i=0; i<strlen(input); i++){
        printf("%x ", (unsigned char)output[i]);
    }
    printf("\n");

    return 0;
}