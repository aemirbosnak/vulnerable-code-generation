//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Structure to store the frequency of characters in text
typedef struct node {
    char c;
    int freq;
    struct node *left, *right;
} node;

//Array to store the codes for each character in text
char **codes;
int num_codes = 0;

//Function to create a new node in the tree
node *newNode(char c, int freq) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->c = c;
    new_node->freq = freq;
    return new_node;
}

//Function to combine two nodes in the tree
node *combineNodes(node *n1, node *n2) {
    node *new_node = newNode('$', n1->freq + n2->freq);
    new_node->left = n1;
    new_node->right = n2;
    return new_node;
}

//Function to traverse the tree and assign huffman codes to each character
void assignCodes(node *root, int *code, int depth) {
    if(!root->left && !root->right) {
        codes[num_codes] = (char *) malloc( (1 + depth) * sizeof(char));
        int i;
        for(i=0; i<depth; i++){
            codes[num_codes][i] = code[i] + '0';
        }
        codes[num_codes][i] = '\0';
        num_codes += 1;
    } else {
        code[depth] = 0;
        assignCodes(root->left, code, depth+1);
        code[depth] = 1;
        assignCodes(root->right, code, depth+1);
    }
}

//Function to find the huffman code for a given character
char *findCode(char c) {
    int i;
    for(i=0; i<num_codes; i++) {
        if(codes[i][0] == c) {
            return codes[i]+1;
        }
    }
    return NULL;
}

//Function to free up the memory allocated for the huffman codes
void freeCodes() {
    int i;
    for(i=0; i<num_codes; i++){
        free(codes[i]);
    }
    free(codes);
}

//Function to encode a string using huffman coding
char *encode(char *text) {
    //Find the frequency of each character in text
    int freq[UCHAR_MAX+1] = {0};  //UCHAR_MAX is defined in limits.h
    int i;
    for(i=0; text[i]; i++) {
        freq[(unsigned char) text[i]]++;
    }

    //Create a node for each character in text
    node *nodes[UCHAR_MAX+1];
    int num_nodes = 0;
    for(i=0; i<=UCHAR_MAX; i++) {
        if(freq[i]) {
            nodes[num_nodes] = newNode(i, freq[i]);
            num_nodes++;
        }
    }

    //Combine nodes to form the Huffman tree
    node *root;
    int j; 
    for(i=0; i<num_nodes-1; i++) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int index1 = -1, index2 = -1;
        for(j=0; j<num_nodes; j++) {
            if(nodes[j]->freq < min1) {
                min2 = min1;
                index2 = index1;
                min1 = nodes[j]->freq;
                index1 = j;
            } else if(nodes[j]->freq < min2) {
                min2 = nodes[j]->freq;
                index2 = j;
            }
        }
        root = combineNodes(nodes[index1], nodes[index2]);
        nodes[index1] = root;
        nodes[index2] = nodes[num_nodes-1];
        num_nodes--;
    }

    //Assign huffman codes to each character in text
    codes = (char **) malloc(num_nodes*sizeof(char *));
    int code[UCHAR_MAX+1];
    assignCodes(root, code, 0);

    //Generate the huffman encoded string
    char *encoded = (char *) malloc(i*num_codes*sizeof(char));
    int k = 0;
    for(j=0; text[j]; j++) {
        char *c = findCode(text[j]);
        while(*c) {
            encoded[k] = *c;
            k++;
            c++;
        }
    }
    encoded[k] = '\0';

    //Free up the memory allocated to the huffman codes
    freeCodes();

    //Return the huffman encoded string
    return encoded;
}

int main() {
    char text[100];
    printf("Enter the text to be encoded: ");
    fgets(text, 100, stdin);

    char *encoded = encode(text);

    printf("The huffman encoded string is: %s\n", encoded);

    free(encoded);

    return 0;
}