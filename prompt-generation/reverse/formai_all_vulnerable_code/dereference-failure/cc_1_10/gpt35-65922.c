//FormAI DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 //Define the maximum length of the text to be compressed
#define CODE_SIZE 16    //Define the number of bits for each code

//Node structure for the Huffman Tree
typedef struct Node {
    char letter;               //Letter of the node (if it is a leaf node)
    unsigned int frequency;    //Frequency of the letter in the text
    struct Node* left_child;   //Pointer to left child
    struct Node* right_child;  //Pointer to right child
} Node;

//Priority Queue structure
typedef struct pqNode {
    Node* elem;
    unsigned int priority;
    struct pqNode* next;
} pqNode;

//Function declarations
void compress(char* text);
void add_node_to_pq(pqNode** front, Node* elem, unsigned int priority);
void delete_pq_node(pqNode** front);
Node* build_huffman_tree(pqNode** front);
void create_codes(Node* root, unsigned char* codes[], unsigned char prefix[], unsigned int depth);
void write_codes_to_file(Node* root, unsigned char* codes[], FILE* outFile);
void free_node_memory(Node* node);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* inFile = fopen(argv[1], "r");
    if (!inFile) {
        printf("Error opening file\n");
        return 1;
    }

    char* text = malloc(MAX_LENGTH * sizeof(char));
    if (!text) {
        printf("Error allocating memory\n");
        fclose(inFile);
        return 1;
    }

    int c, i = 0;
    while ((c = getc(inFile)) != EOF) {
        text[i++] = (char)c;
        if (i >= MAX_LENGTH) {
            printf("Text too long!\n");
            fclose(inFile);
            free(text);
            return 1;
        }
    }
    text[i] = '\0';
    fclose(inFile);

    compress(text);
    free(text);
    return 0;
}

void compress(char* text) {
    //Count frequency of each character
    unsigned int frequency[256] = {0};
    int i = 0;
    while (text[i] != '\0') {
        frequency[text[i]]++;
        i++;
    }

    //Build the Huffman Tree
    pqNode* queue = NULL;
    for (unsigned int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            Node* newNode = malloc(sizeof(Node));
            newNode->letter = i;
            newNode->frequency = frequency[i];
            newNode->left_child = NULL;
            newNode->right_child = NULL;
            add_node_to_pq(&queue, newNode, newNode->frequency);
        }
    }
    Node* root = build_huffman_tree(&queue);

    //Create the codes for each character
    unsigned char* codes[256];
    unsigned char prefix[CODE_SIZE];
    create_codes(root, codes, prefix, 0);

    //Write the codes to file
    FILE* outFile = fopen("compressed.txt", "w");
    write_codes_to_file(root, codes, outFile);
    fclose(outFile);

    //Free memory
    free_node_memory(root);
}

void add_node_to_pq(pqNode** front, Node* elem, unsigned int priority) {
    pqNode* newNode = malloc(sizeof(pqNode));
    newNode->elem = elem;
    newNode->priority = priority;

    if (*front == NULL) { //if priority queue is empty
        newNode->next = NULL;
        *front = newNode;
    } else {
        if ((*front)->priority >= priority) { //insert at beginning
            newNode->next = *front;
            *front = newNode;
        } else {
            //find the node after which the new node should be inserted
            pqNode* current = *front;
            while (current->next != NULL && current->next->priority < priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

void delete_pq_node(pqNode** front) {
    pqNode* first = *front;
    *front = first->next;
    free(first);
}

Node* build_huffman_tree(pqNode** front) {
    while ((*front)->next != NULL) {
        Node* newNode = malloc(sizeof(Node));
        newNode->letter = '\0';
        newNode->frequency = (*front)->elem->frequency + (*front)->next->elem->frequency;
        newNode->left_child = (*front)->elem;
        newNode->right_child = (*front)->next->elem;

        delete_pq_node(front);
        delete_pq_node(front);
        add_node_to_pq(front, newNode, newNode->frequency);
    }
    return (*front)->elem;
}

void create_codes(Node* root, unsigned char* codes[], unsigned char prefix[], unsigned int depth) {
    if (root == NULL) {
        return;
    }

    if (root->left_child == NULL && root->right_child == NULL) { //if it's a leaf node
        prefix[depth] = '\0';
        unsigned char* code = malloc(sizeof(unsigned char) * (depth + 1));
        codes[root->letter] = code;
        strcpy((char*)code, (char*)prefix);
        return;
    }

    //Process left child
    prefix[depth] = '0';
    create_codes(root->left_child, codes, prefix, depth + 1);

    //Process right child
    prefix[depth] = '1';
    create_codes(root->right_child, codes, prefix, depth + 1);
}

void write_codes_to_file(Node* root, unsigned char* codes[], FILE* outFile) {
    fwrite(root, sizeof(Node), 1, outFile);
    if (root->left_child != NULL) {
        write_codes_to_file(root->left_child, codes, outFile);
    }
    if (root->right_child != NULL) {
        write_codes_to_file(root->right_child, codes, outFile);
    }
    if (root->left_child == NULL && root->right_child == NULL) { //if it's a leaf node
        unsigned char codeLength = strlen((char*)codes[root->letter]);
        fwrite(&root->letter, sizeof(char), 1, outFile);
        fwrite(&codeLength, sizeof(unsigned char), 1, outFile);
        fwrite(codes[root->letter], sizeof(char), codeLength, outFile);
    }
}

void free_node_memory(Node* node) {
    if (node->left_child != NULL) {
        free_node_memory(node->left_child);
    }
    if (node->right_child != NULL) {
        free_node_memory(node->right_child);
    }
    free(node);
}