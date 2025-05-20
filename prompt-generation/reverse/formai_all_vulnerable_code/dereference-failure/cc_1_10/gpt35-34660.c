//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define max_string_length 100

typedef struct node 
{
    char character;
    int frequency;
    struct node *left, *right;
} node;

typedef struct heap 
{
    int size;
    node **array;
} heap;

node* create_node(char character, int frequency) 
{
    node* temp = (node*) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}

heap* create_heap(int capacity) 
{
    heap* h = (heap*) malloc(sizeof(heap));
    h->size = 0;
    h->array = (node**) malloc(capacity * sizeof(node*));
    return h;
}

void swap_node(node** a, node** b) 
{
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(heap* h, int index) 
{
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < h->size && h->array[left_child]->frequency < h->array[smallest]->frequency) 
    {
        smallest = left_child;
    }
    if (right_child < h->size && h->array[right_child]->frequency < h->array[smallest]->frequency) 
    {
        smallest = right_child;
    }
    if (smallest != index) 
    {
        swap_node(&h->array[index], &h->array[smallest]);
        min_heapify(h, smallest);
    }
}

int is_leaf(node* root) 
{
    return !(root->left) && !(root->right);
}

heap* build_heap(char characters[max_string_length], int frequency[max_string_length], int characters_count) 
{
    heap* h = create_heap(characters_count);
    for (int i = 0; i < characters_count; i++) 
    {
        h->array[i] = create_node(characters[i], frequency[i]);
    }
    h->size = characters_count;
    for (int i = (h->size - 2) / 2; i >= 0; i--) 
    {
        min_heapify(h, i);
    }
    return h;
}

node* extract_minimum(heap* h) 
{
    node* temp = h->array[0];
    h->array[0] = h->array[h->size - 1];
    --h->size;
    min_heapify(h, 0);
    return temp;
}

void insert_heap(heap* h, node* n) 
{
    ++h->size;
    int index = h->size - 1;
    while (index && n->frequency < h->array[(index - 1) / 2]->frequency) 
    {
        h->array[index] = h->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    h->array[index] = n;
}

node* huffman_encoding(char characters[max_string_length], int frequency[max_string_length], int characters_count) 
{
    node *left, *right, *top;
    heap* h = build_heap(characters, frequency, characters_count);
    while (h->size != 1) 
    {
        left = extract_minimum(h);
        right = extract_minimum(h);
        top = create_node('#', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert_heap(h, top);
    }
    return extract_minimum(h);
}

void print_codes(node* root, int arr[], int top) 
{
    if (root->left) 
    {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) 
    {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (is_leaf(root)) 
    {
        printf("%c", root->character);
        for (int i = 0; i < top; i++) 
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffman_encoding_driver(char characters[max_string_length], int frequency[max_string_length], int characters_count) 
{
    node* root = huffman_encoding(characters, frequency, characters_count);
    int arr[max_string_length], top = 0;
    print_codes(root, arr, top);
}

int main() 
{
    printf("Welcome to Huffman's Encoding Comedy Club!\n");
    printf("Please enter a string to encode: \n");

    char input_string[max_string_length];
    fgets(input_string, max_string_length, stdin);
    input_string[strcspn(input_string, "\n")] = 0; // remove newline character from input

    printf("You entered: %s\n", input_string);

    int frequency[max_string_length] = { 0 };
    char characters[max_string_length] = { 0 };

    for (int i = 0; i < strlen(input_string); ++i) 
    {
        int char_exists = FALSE;
        for (int j = 0; j < strlen(characters); ++j) 
        {
            if (input_string[i] == characters[j]) 
            {
                ++frequency[j];
                char_exists = TRUE;
                break;
            }
        }
        if (!char_exists) 
        {
            characters[strlen(characters)] = input_string[i];
            frequency[strlen(frequency)] = 1;
        }
    }

    int characters_count = strlen(characters);

    if (characters_count == 1) 
    {
        printf("Try entering something with more variety, please...\n");
        return 0;
    }

    printf("These are the Huffman codes for each character:\n");

    huffman_encoding_driver(characters, frequency, characters_count);

    printf("That's all, folks! Thanks for coming to Huffman's Encoding Comedy Club!\n");

    return 0;
}