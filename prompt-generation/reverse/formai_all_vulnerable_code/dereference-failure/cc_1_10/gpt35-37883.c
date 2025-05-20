//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct huffman_t{
    int freq;
    char data;
    struct huffman_t *right, *left;
}huffman;

void swap(huffman **a, huffman **b){
    huffman *t = *a;
    *a = *b;
    *b = t;
}

void min_heap(huffman **list, int n, int i){
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && list[left]->freq < list[smallest]->freq){
        smallest = left;
    }
    if (right < n && list[right]->freq < list[smallest]->freq){
        smallest = right;
    }
    if (smallest != i){
        swap(&list[i], &list[smallest]);
        min_heap(list, n, smallest);
    }
}

void build_heap(huffman **list, int n){
    int i;
    for (i = n/2 - 1; i >=0; i--){
        min_heap(list, n, i);
    }
}

huffman *huffman_tree(char *data, int *freq, int n){
    int i;
    huffman *top, *left, *right, **list;

    list = (huffman **)malloc(n * sizeof(huffman *));
    for (i = 0; i < n; i++){
        list[i] = (huffman *)malloc(sizeof(huffman));
        list[i]->left = list[i]->right = NULL;
        list[i]->data = data[i];
        list[i]->freq = freq[i];
    }
    build_heap(list, n);

    while(n > 1){
        left = list[0];
        swap(&list[0], &list[n-1]);
        n--;
        min_heap(list, n, 0);
        right = list[0];

        top = (huffman *)malloc(sizeof(huffman));
        top->data = '^';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        list[n] = top;
        min_heap(list, n+1, 0);
    }
    return list[0];
}

void print_codes(huffman *root, char *code, int top){
    if (root->left){
        code[top] = '0';
        print_codes(root->left, code, top+1);
    }
    if (root->right){
        code[top] = '1';
        print_codes(root->right, code, top+1);
    }
    if (!root->left && !root->right){
        printf("%c : ", root->data);
        for (int i = 0; i < top; i++){
            printf("%c", code[i]);
        }
        printf("\n");
    }
}

void romantic_print(){
    printf("Every time I think of you, my heart races like a clock.\n");
    printf("My love for you is like code, it is always changing but never lost.\n");
    printf("You are the beautiful program that runs perfectly in my mind.\n");
    printf("Without you, my life would be an infinite loop of meaningless variables.\n");
    printf("Every conversation we have is like a function, it flows so perfectly together.\n");
    printf("I can't imagine my life without you, you are the semicolon to my statement.\n");
    printf("You are the perfect bug fixer, you always know how to fix my broken heart.\n");
    printf("My love for you is like recursion, it may be complex but it always leads me back to you.\n");
    printf("You are the perfect user-defined data type, you fit so perfectly in my life.\n");
    printf("I could debug my code for hours, but loving you has always been error-free.\n");
}

int main(){

    romantic_print();

    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {5, 10, 15, 20, 25};

    huffman *root = huffman_tree(data, freq, 5);

    char code[100];
    printf("\nHuffman Codes: \n\n");
    print_codes(root, code, 0);

    return 0;
}