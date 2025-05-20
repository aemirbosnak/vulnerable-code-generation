//FormAI DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1000

unsigned char byteBuffer[MAX_BUF_SIZE]; //buffer to hold each byte read from file
unsigned int byteFrequency[256] = {0}; //to store frequency of each byte in input file

/*Node structure of Huffman tree*/
typedef struct Node {
    unsigned char character;
    unsigned int frequency;
    struct Node* left;
    struct Node* right;
} Node;

/*Functions to insert a new node and to sort the array of nodes according to frequencies*/
void insert_node(Node** nodes_array, Node* newNode, unsigned int* size) {
    if((*size) == 0) { //if array is empty
        nodes_array[0] = newNode;
        (*size)++;
        return;
    }
    nodes_array[(*size)] = newNode;
    int index = (*size);
    (*size)++;
    while(index > 0 && nodes_array[index]->frequency < nodes_array[index-1]->frequency) { //insert node at correct position based on frequency
        Node* temp = nodes_array[index];
        nodes_array[index] = nodes_array[index-1];
        nodes_array[index-1] = temp;
        index--;
    }
}

/*Function to generate Huffman tree*/
Node* generate_huffman_tree() {
    Node* nodes_array[256] = {NULL}; //array to hold all the nodes
    unsigned int size = 0;
    for(int i=0; i<256; i++) {
        if(byteFrequency[i] > 0) { //if byte is present in input file, create a new node and add it to array
            Node* node = (Node*) malloc(sizeof(Node));
            node->character = (unsigned char) i;
            node->frequency = byteFrequency[i];
            node->left = NULL;
            node->right = NULL;
            insert_node(nodes_array, node, &size); //insert node at correct position in array
        }
    }
    while(size > 1) { //continue till only 1 node remains
        Node* node = (Node*) malloc(sizeof(Node));
        node->character = '\0';
        node->frequency = nodes_array[0]->frequency + nodes_array[1]->frequency; //sum of frequencies of 2 smallest nodes
        node->left = nodes_array[0]; //attach the 2 smallest nodes as left and right children
        node->right = nodes_array[1];
        Node* temp = nodes_array[0];
        nodes_array[0] = node; //push node to front of array
        for(int i=1; i<(size-1); i++) { //shift all the nodes one position to the left
            nodes_array[i] = nodes_array[i+1];
        }
        nodes_array[size-1] = temp; //store the second smallest node at the last position
        size--;
    }
    return nodes_array[0];
}

/*Function to perform Huffman encoding recursively*/
void huffman_encoding_helper(Node* node, unsigned char* binary, int level, unsigned char* encoded_string) {
    if(node == NULL) { //base case
        return;
    }
    if(node->left == NULL && node->right == NULL) { //if node is a leaf node
        encoded_string[node->character] = '\0';
        strcat(encoded_string, (const char*)binary); //concatenate binary code of node to encoded string
        return;
    }
    binary[level] = '0'; //encode left children as 0
    huffman_encoding_helper(node->left, binary, level+1, encoded_string);
    binary[level] = '1'; //encode right children as 1
    huffman_encoding_helper(node->right, binary, level+1, encoded_string);
}

/*Function to perform Huffman encoding*/
void huffman_encoding(Node* huffman_tree) {
    unsigned char binary[256] = {0}; //to store binary code of each character
    unsigned char encoded_string[256] = {0}; //to store encoded string
    huffman_encoding_helper(huffman_tree, binary, 0, encoded_string); //perform Huffman encoding recursively
    for(int i=0; i<256; i++) {
        if(byteFrequency[i] > 0) {
            printf("%c: %s\n", (unsigned char)i, encoded_string[i]); //print the binary code of each character
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "rb"); //open input file in binary mode
    if(inputFile == NULL) {
        printf("Error: Input file not found!\n");
        return -1;
    }
    int bytesRead = 0;
    while((bytesRead = fread(byteBuffer, 1, MAX_BUF_SIZE, inputFile)) > 0) { //read file in chunks of max buffer size
        for(int i=0; i<bytesRead; i++) {
            byteFrequency[byteBuffer[i]]++; //calculate frequency of each byte
        }
    }
    fclose(inputFile);
    Node* huffman_tree = generate_huffman_tree(); //generate Huffman tree
    huffman_encoding(huffman_tree); //perform Huffman encoding
    return 0;
}