//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000
#define MAX_TREE_NODES 255

typedef struct node{
    int freq;
    char letter;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree{
    Node *root;
} Tree;

Node* new_node(int freq, char letter){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->freq = freq;
    temp->letter = letter;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void swap_nodes(Node** a, Node** b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(Node** nodes, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(nodes[j]->freq > nodes[j + 1]->freq){
                swap_nodes(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}

Node* build_huffman_tree(char* str, int* freq_count){
    int i;
    int n = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(freq_count[str[i]] == 0){
            n++;
        }
        freq_count[str[i]]++;
    }
    
    Node** nodes = (Node**)malloc(sizeof(Node*) * n);
    int c = 0;
    for(i = 0; i < 256; i++){
        if(freq_count[i] != 0){
            nodes[c] = new_node(freq_count[i], i);
            c++;
        }
    }
    
    while(n > 1){
        bubble_sort(nodes, n);
        Node* temp = new_node(nodes[0]->freq + nodes[1]->freq, '$');
        temp->left = nodes[0];
        temp->right = nodes[1];
        
        nodes[0] = temp;
        nodes[1] = nodes[n - 1];
        n--;
    }
    return nodes[0];
}

void print_codes(Node* node, char* code, int size){
    if(node == NULL){
        return;
    }
    
    if(node->letter != '$'){
        printf("'%c': %s\n", node->letter, code);
    }
    
    char* left_code = (char*)malloc(sizeof(char) * size + 1);
    char* right_code = (char*)malloc(sizeof(char) * size + 1);
    strcpy(left_code, code);
    strcpy(right_code, code);
    
    left_code[size] = '0';
    left_code[size + 1] = '\0';
    
    right_code[size] = '1';
    right_code[size + 1] = '\0';
    
    print_codes(node->left, left_code, size + 1);
    print_codes(node->right, right_code, size + 1);
}

void encode_string(Node* node, char* str, char* enc_str){
    int i, j;
    int n = strlen(str);
    for(i = 0, j = 0; i < n; i++){
        if(node->left == NULL && node->right == NULL){
            enc_str[j] = node->letter;
            j++;
            node = build_huffman_tree(str + i, (int*)calloc(256, sizeof(int)));
        }
        if(str[i] == node->left->letter){
            enc_str[j] = '0';
            node = node->left;
            j++;
        }
        else{
            enc_str[j] = '1';
            node = node->right;
            j++;
        }
    }
    enc_str[j] = node->letter;
}

int main(){
    char* str = (char*)malloc(sizeof(char) * MAX_STRING_LEN);
    printf("Enter the string to be encoded: ");
    fgets(str, MAX_STRING_LEN, stdin);
    str[strlen(str) - 1] = '\0';
    
    int* freq_count = (int*)calloc(256, sizeof(int));
    Node* root = build_huffman_tree(str, freq_count);
    
    printf("Huffman Codes:\n");
    char* code = (char*)malloc(sizeof(char));
    code[0] = '\0';
    print_codes(root, code, 0);
    
    char* enc_str = (char*)malloc(sizeof(char) * (strlen(str) + 1) * 8);
    memset(enc_str, '\0', sizeof(char) * (strlen(str) + 1) * 8);
    encode_string(root, str, enc_str);
    
    printf("Encoded string: %s\n", enc_str);
    
    free(str);
    free(freq_count);
    free(code);
    free(enc_str);
    return 0;
}