//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the Huffman Tree Node
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

//Define the Huffman tree
struct HuffmanTree {
    struct HuffmanNode* root;
};

//Create a new Huffman Node
struct HuffmanNode* newHuffmanNode(char ch, int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->character = ch;
    node->frequency = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Create a new Huffman Tree
struct HuffmanTree* newHuffmanTree() {
    struct HuffmanTree* tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    tree->root = NULL;
    return tree;
}

//Compare the two Huffman Nodes based on frequence
int compare(const void* a, const void* b) {
    struct HuffmanNode* nodeA = *(struct HuffmanNode**)a;
    struct HuffmanNode* nodeB = *(struct HuffmanNode**)b;
    return nodeA->frequency - nodeB->frequency;
}

//Build the Huffman Tree and return root node
struct HuffmanNode* buildHuffmanTree(char* text) {
    int freq[256] = {0};
    int length = strlen(text);
    
    //Calculate frequency of each character
    for(int i = 0; i < length; i++) {
        freq[text[i]]++;
    }

    //Create Huffman Nodes
    struct HuffmanNode* nodes[256];
    int nodeCount = 0;
    for(int i = 0; i < 256; i++) {
        if(freq[i] != 0) {
            nodes[nodeCount] = newHuffmanNode((char)i, freq[i]);
            nodeCount++;
        }
    }

    //Build Huffman Tree
    while(nodeCount > 1) {
        qsort(nodes, nodeCount, sizeof(struct HuffmanNode*), compare);

        struct HuffmanNode* leftNode = nodes[0];
        struct HuffmanNode* rightNode = nodes[1];
        struct HuffmanNode* combinedNode = newHuffmanNode('$', leftNode->frequency + rightNode->frequency);
        combinedNode->left = leftNode;
        combinedNode->right = rightNode;

        nodes[0] = combinedNode;
        for(int i = 1; i < nodeCount - 1; i++) {
            nodes[i] = nodes[i+1];
        }
        nodes[nodeCount-1] = NULL;

        nodeCount--;
    }

    //Return root node
    return nodes[0];
}

//Create the Huffman Code table
void createHuffmanCodes(struct HuffmanNode* root, char* codeTable[], char* code, int index) {
    if(root->left != NULL) {
        code[index] = '0';
        createHuffmanCodes(root->left, codeTable, code, index+1);
    }
    
    if(root->right != NULL) {
        code[index] = '1';
        createHuffmanCodes(root->right, codeTable, code, index+1);
    }

    if(root->left == NULL && root->right == NULL) {
        code[index] = '\0';
        char* newCode = (char*)malloc(sizeof(char) * (strlen(code)+1));
        strcpy(newCode, code);
        codeTable[(int)root->character] = newCode;
    }
}

//Encode the text using Huffman Code
char* encodeText(char* text, char* codeTable[]) {
    int length = strlen(text);
    int totalCodeLength = 0;

    //Calculate the length of encoded text
    for(int i = 0; i < length; i++) {
        totalCodeLength += strlen(codeTable[(int)text[i]]);
    }

    //Allocate memory for encoded text and generate Huffman code for each character
    char* encodedText = (char*)malloc(sizeof(char) * (totalCodeLength+1));
    int position = 0;
    for(int i = 0; i < length; i++) {
        char* code = codeTable[(int)text[i]];
        strcat(encodedText, code);
        position += strlen(code);
    }

    //Add null terminator to the end of encoded text
    encodedText[totalCodeLength] = '\0';

    return encodedText;
}

//Decode the Huffman Code into original text
char* decodeText(char* encodedText, struct HuffmanNode* root) {
    struct HuffmanNode* currentNode = root;
    int length = strlen(encodedText);
    char* decodedText = (char*)malloc(sizeof(char) * (length+1));
    int position = 0;

    for(int i = 0; i < length; i++) {
        if(currentNode->left == NULL && currentNode->right == NULL) {
            decodedText[position] = currentNode->character;
            position++;
            currentNode = root;
        }

        if(encodedText[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    decodedText[position] = currentNode->character;
    position++;
    decodedText[position] = '\0';

    return decodedText;
}

//Test the Huffman Coding implementation
int main() {
    char* text = "Huffman Coding Example";
    struct HuffmanNode* root = buildHuffmanTree(text);

    char* codeTable[256] = {NULL};
    char code[256];
    createHuffmanCodes(root, codeTable, code, 0);

    char* encodedText = encodeText(text, codeTable);
    printf("Original Text: %s\n", text);
    printf("Encoded Text: %s\n", encodedText);

    char* decodedText = decodeText(encodedText, root);
    printf("Decoded Text: %s\n", decodedText);

    return 0;
}