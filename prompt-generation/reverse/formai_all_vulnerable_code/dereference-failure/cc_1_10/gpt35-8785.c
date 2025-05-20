//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for Huffman Tree
struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

// Function to create a new node
struct node* new_node(char ch, int freq) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to compare two nodes based on their frequency
int cmpf(const void* a, const void* b) {
    struct node **n1, **n2;
    n1 = (struct node **)a;
    n2 = (struct node **)b;
    return (*n1)->freq - (*n2)->freq;
}

// Function to build Huffman Tree
struct node* build_huffman_tree(char *str) {
    int n = strlen(str);
    struct node **nodes, *temp;
    nodes = (struct node **)malloc(n*sizeof(struct node *));
    for(int i=0;i<n;i++) {
        nodes[i] = new_node(str[i],1);
    }
    qsort(nodes,n,sizeof(struct node *),cmpf);
    int i=0;
    while(i<n-1) {
        temp = new_node('\0',nodes[i]->freq+nodes[i+1]->freq);
        temp->left = nodes[i];
        temp->right = nodes[i+1];
        nodes[i+1] = temp;
        i++;
        qsort(nodes+i,n-i,sizeof(struct node *),cmpf);
    }
    return nodes[n-1];
}

// Function to print Huffman Codes
void print_huffman_codes(struct node* root, char *code) {
    if(root->left == NULL && root->right == NULL && root->ch != '\0') {
        printf("%c: %s\n",root->ch,code);
        return;
    }
    print_huffman_codes(root->left, strcat(code,"0"));
    code[strlen(code)-1] = '\0';
    print_huffman_codes(root->right, strcat(code,"1"));
}

int main() {
    char str[100];
    printf("Enter the string to be encoded: ");
    scanf("%[^\n]%*c",str);
    struct node* root = build_huffman_tree(str);
    char code[100];
    code[0] = '\0';
    printf("\nHUFFMAN CODES:\n");
    print_huffman_codes(root, code);
    return 0;
}