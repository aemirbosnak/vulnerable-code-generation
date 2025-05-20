//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//structure for storing the huffman tree
struct node {
    int freq; //frequency of the character
    char character; //character
    struct node *left_child; //left child of the node
    struct node *right_child; //right child of the node
};

typedef struct node node;


//create a new node with the given character and frequency
node* create_node(int freq, char character) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->freq = freq;
    new_node->character = character;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}


//implementation of min heap to hold nodes with minimum frequency
node** create_min_heap(int size) {
    node** min_heap = (node**)malloc(sizeof(node*)*size);
    int i;
    for(i=0;i<size;i++) {
        min_heap[i] = (node*)malloc(sizeof(node));
        min_heap[i]->freq = -1;
        min_heap[i]->character = '\0';
        min_heap[i]->left_child = NULL;
        min_heap[i]->right_child = NULL;
    }
    return min_heap;
}


//percolate up operation in min heap
void perc_up(node** min_heap, int index) {
    if(index<=0) return;
    int parent = (index-1)/2;
    if(min_heap[parent]->freq > min_heap[index]->freq) {
        node* temp = min_heap[parent];
        min_heap[parent] = min_heap[index];
        min_heap[index] = temp;
        perc_up(min_heap, parent);
    }
}


//percolate down operation in min heap
void perc_down(node** min_heap, int index, int size) {
    int left_child = 2*index+1;
    int right_child = 2*index+2;
    if(left_child >= size) return;
    if(right_child >= size) {
        if(min_heap[index]->freq > min_heap[left_child]->freq) {
            node* temp = min_heap[index];
            min_heap[index] = min_heap[left_child];
            min_heap[left_child] = temp;
        }
        return;
    }
    if(min_heap[left_child]->freq < min_heap[right_child]->freq && min_heap[index]->freq > min_heap[left_child]->freq) {
        node* temp = min_heap[index];
        min_heap[index] = min_heap[left_child];
        min_heap[left_child] = temp;
        perc_down(min_heap, left_child, size);
    }
    else if(min_heap[right_child]->freq < min_heap[left_child]->freq && min_heap[index]->freq > min_heap[right_child]->freq) {
        node* temp = min_heap[index];
        min_heap[index] = min_heap[right_child];
        min_heap[right_child] = temp;
        perc_down(min_heap, right_child, size);
    }
}


//insert a new node into the min heap
void insert_node(node** min_heap, node* new_node, int index) {
    int i=index;
    while(min_heap[i]->freq!=-1) {
        i++;
    }
    min_heap[i]->freq = new_node->freq;
    min_heap[i]->character = new_node->character;
    min_heap[i]->left_child = new_node->left_child;
    min_heap[i]->right_child = new_node->right_child;
    perc_up(min_heap, i);
}


//remove and return the node with minimum frequency
node* remove_min(node** min_heap, int index) {
    node* min_node = min_heap[0];
    min_heap[0] = min_heap[index-1];
    min_heap[index-1] = create_node(-1, '\0');
    perc_down(min_heap, 0, index-1);
    return min_node;
}


//build the huffman tree based on the frequency of the characters
node* build_huffman_tree(int* freq_table) {
    node** min_heap = create_min_heap(256);
    int i;
    for(i=0;i<256;i++) {
        if(freq_table[i] > 0) {
            node* new_node = create_node(freq_table[i], (char)i);
            insert_node(min_heap, new_node, 0);
        }
    }
    int size = 256;
    while(size>1) {
        node* min1 = remove_min(min_heap, size);
        size--;
        node* min2 = remove_min(min_heap, size);
        size--;
        node* new_node = create_node(min1->freq+min2->freq, '\0');
        new_node->left_child = min1;
        new_node->right_child = min2;
        insert_node(min_heap, new_node, size);
        size++;
    }
    node* root = remove_min(min_heap, size);
    free(min_heap);
    return root;
}


//traverse the huffman tree to generate codes for each character
void generate_codes(node* root, char* code, char* codes[]) {
    if(root->left_child==NULL && root->right_child==NULL) {
        codes[root->character] = (char*)malloc(strlen(code)+1);
        memcpy(codes[root->character], code, strlen(code)+1);
        return;
    }
    char new_code[strlen(code)+2];
    memcpy(new_code, code, strlen(code)+1);
    new_code[strlen(code)] = '0';
    new_code[strlen(code)+1] = '\0';
    generate_codes(root->left_child, new_code, codes);
    memcpy(new_code, code, strlen(code)+1);
    new_code[strlen(code)] = '1';
    new_code[strlen(code)+1] = '\0';
    generate_codes(root->right_child, new_code, codes);
}


//encode the given message using the codes generated for each character
void encode_message(char* message, int* freq_table, char** codes) {
    int length = strlen(message);
    int i;
    for(i=0;i<length;i++) {
        printf("%s", codes[message[i]]);
    }
    printf("\n");
}


//decode the given message using the huffman tree
void decode_message(char* message, node* root) {
    node* current = root;
    int length = strlen(message);
    int i;
    for(i=0;i<length;i++) {
        if(message[i]=='0') {
            current = current->left_child;
        }
        else {
            current = current->right_child;
        }
        if(current->left_child==NULL && current->right_child==NULL) {
            printf("%c", current->character);
            current = root;
        }
    }
    printf("\n");
}


int main() {
    int freq_table[256] = {0};
    char message[100];
    printf("Enter the message to be encoded: ");
    fgets(message, 100, stdin);
    int length = strlen(message);
    int i;
    for(i=0;i<length;i++) {
        freq_table[message[i]]++;
    }
    node* root = build_huffman_tree(freq_table);
    char* codes[256];
    char code[1] = {'\0'};
    generate_codes(root, code, codes);
    printf("The encoded message is: ");
    encode_message(message, freq_table, codes);
    printf("The decoded message is: ");
    decode_message("11001000101100011001001100111001101111", root);
    return 0;
}