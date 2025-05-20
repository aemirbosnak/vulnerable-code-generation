//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    unsigned char symbol;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct list {
    node *n;
    struct list *next;
} list;

// Function to create a new list element with given node
list* createList(node* n) {
    list *newList = (list *) malloc(sizeof(list));
    newList -> n = n;
    newList -> next = NULL;
    return newList;
}

// Function to append a new list element at the end of the list
void append(list** l, node* n) {
    if(*l == NULL) {
        *l = createList(n);
    } else {
        list *temp = *l;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = createList(n);
    }
}

// Function to remove the element at the front of the list
node* pop(list** l) {
    if(*l == NULL) {
        return NULL;
    } else {
        node *n = (*l) -> n;
        (*l) = (*l) -> next;
        return n;
    }
}

// Function to sort the list in ascending order based on frequency
void sortList(list** l) {
    if(*l == NULL) {
        return;
    }
    list *tail = NULL, *cur;
    node *temp;
    int swapped = 1;
    
    while(swapped) {
        swapped = 0;
        cur = *l;
        while(cur -> next != tail) {
            if(cur -> n -> freq > cur -> next -> n -> freq) {
                temp = cur -> n;
                cur -> n = cur -> next -> n;
                cur -> next -> n = temp;
                swapped = 1;
            }
            cur = cur -> next;
        }
        tail = cur;
    }
}

// Recursive function to build the Huffman tree
node* buildHuffmanTree(list** l) {
    while(*l != NULL && (*l) -> next != NULL) {
        node *n1 = pop(l);
        node *n2 = pop(l);
        node *parent = (node *) malloc(sizeof(node));
        parent -> symbol = '*';
        parent -> freq = n1 -> freq + n2 -> freq;
        parent -> left = n1;
        parent -> right = n2;
        append(l, parent);
        sortList(l);
    }
    return *l == NULL ? NULL : (*l) -> n;
}

// Recursive function to print the Huffman codes for each symbol
void printCodes(node* root, int arr[], int top) {
    if(root -> left) {
        arr[top] = 0;
        printCodes(root -> left, arr, top + 1);
    }
    if(root -> right) {
        arr[top] = 1;
        printCodes(root -> right, arr, top + 1);
    }
    if(root -> left == NULL && root -> right == NULL) {
        printf("%c: ", root -> symbol);
        for(int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to read the input file and count the frequency of each symbol
list* readInput() {
    FILE *fp = fopen("input.txt", "rb");
    if(fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    list *l = NULL;
    unsigned char buffer[1024];
    int numRead;
    int freq[256] = {0};
    while((numRead = fread(buffer, sizeof(unsigned char), 1024, fp)) > 0) {
        for(int i = 0; i < numRead; i++) {
            freq[buffer[i]]++;
        }
    }
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            node *n = (node *) malloc(sizeof(node));
            n -> symbol = i;
            n -> freq = freq[i];
            n -> left = NULL;
            n -> right = NULL;
            append(&l, n);
        }
    }
    fclose(fp);
    return l;
}

int main() {
    list *l = readInput();
    if(l == NULL) {
        printf("Error reading input file\n");
        exit(1);
    }
    sortList(&l);
    node *root = buildHuffmanTree(&l);
    int arr[256];
    int top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
    return 0;
}