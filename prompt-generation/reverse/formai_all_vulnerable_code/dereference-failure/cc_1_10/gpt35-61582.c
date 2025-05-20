//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TREE_HT 100

//the character struct stores each character in the input string and its frequency in the string
struct character{
    char c;
    int freq;
};

//the node struct used for the huffman tree
struct node{
    char c;
    int freq;
    struct node* left;
    struct node* right;
};

//the min heap struct used for building the huffman tree
struct min_heap{
    int size;
    int capacity;
    struct node** array;
};

//utility function to create a new character struct
struct character* new_character(char c, int freq){
    struct character* ch = (struct character*)malloc(sizeof(struct character));
    ch->c = c;
    ch->freq = freq;
    return ch;
}

//utility function to create a new node struct
struct node* new_node(char c, int freq){
    struct node* nd = (struct node*)malloc(sizeof(struct node));
    nd->c = c;
    nd->freq = freq;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

//utility function to create a new min heap struct
struct min_heap* create_min_heap(int capacity){
    struct min_heap* heap = (struct min_heap*)malloc(sizeof(struct min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct node**)malloc(heap->capacity * sizeof(struct node*));
    return heap;
}

//utility function to swap two node structs
void swap_node(struct node** a, struct node** b){
    struct node* tmp = *a;
    *a = *b;
    *b = tmp;
}

//heapify function used for inserting into min heap
void heapify(struct min_heap* heap, int idx){
    int smallest = idx;
    int left = (idx * 2) + 1;
    int right = (idx * 2) + 2;

    if(left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq){
        smallest = left;
    }

    if(right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq){
        smallest = right;
    }

    if(smallest != idx){
        swap_node(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}

//check if the heap is of size 1 (used for extracting the last remaining element of the heap)
int is_size_one(struct min_heap* heap){
    return heap->size == 1;
}

//extract the node with the smallest frequency from the min heap
struct node* extract_min(struct min_heap* heap){
    struct node* min = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return min;
}

//insert a node into the min heap
void insert_node(struct min_heap* heap, struct node* node){
    heap->size++;
    int i = heap->size - 1;
    while(i > 0 && node->freq < heap->array[(i-1)/2]->freq){
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }

    heap->array[i] = node;
}

//build the huffman tree
struct node* build_huffman_tree(char* input_string, int* freq_array){
    struct node *left, *right, *top;
    struct min_heap* heap = create_min_heap(MAX_TREE_HT);
    for(int i = 0; i < UCHAR_MAX; i++){
        if(freq_array[i] > 0){
            insert_node(heap, new_node((char)i, freq_array[i]));
        }
    }

    while(!is_size_one(heap)){
        left = extract_min(heap);
        right = extract_min(heap);

        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insert_node(heap, top);
    }

    return extract_min(heap);
}

//utility function to print the huffman codes for each character in the input string
void print_codes(struct node* root, int arr[], int depth){
    if(root->left){
        arr[depth] = 0;
        print_codes(root->left, arr, depth+1);
    }

    if(root->right){
        arr[depth] = 1;
        print_codes(root->right, arr, depth+1);
    }

    if(!(root->left) && !(root->right)){
        printf("%c: ", root->c);
        for(int i = 0; i < depth; i++){
            printf("%d", arr[i]);
        }

        printf("\n");
    }
}

//create the frequency array for the input string
void create_freq_array(char* input_string, int* freq_array){
    for(int i = 0; input_string[i]; i++){
        freq_array[(int)input_string[i]]++;
    }
}

//the main function for the program
int main(){
    char input_string[MAX_TREE_HT];
    printf("Enter string to encode: ");
    fgets(input_string, MAX_TREE_HT, stdin);
    int freq_array[UCHAR_MAX] = {0};
    create_freq_array(input_string, freq_array);
    struct node* root = build_huffman_tree(input_string, freq_array);
    int arr[MAX_TREE_HT], depth = 0;
    printf("Huffman codes:\n");
    print_codes(root, arr, depth);
    return 0;
}