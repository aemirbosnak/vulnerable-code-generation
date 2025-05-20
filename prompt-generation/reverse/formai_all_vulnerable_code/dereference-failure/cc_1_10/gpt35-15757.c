//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node {
    int data;
    unsigned freq;
    struct node *left, *right;
} node_t;

typedef struct minHeap {
    unsigned size;
    unsigned capacity;
    node_t **arr;
} minHeap_t;

typedef struct huffmanTree {
    node_t *root;
} huffmanTree_t;

typedef struct code_book {
    char code[MAX_TREE_HT];
    int size;
} code_book_t;

node_t *new_node(int data, unsigned freq) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

minHeap_t *create_min_heap(unsigned capacity) {
    minHeap_t *min_heap = (minHeap_t *)malloc(sizeof(minHeap_t));

    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->arr = (node_t **)malloc(min_heap->capacity * sizeof(node_t **));

    return min_heap;
}

void swap_node(node_t **a, node_t **b) {
    node_t *t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(minHeap_t *min_heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < min_heap->size && min_heap->arr[left]->freq < min_heap->arr[smallest]->freq) {
        smallest = left;
    }

    if (right < min_heap->size && min_heap->arr[right]->freq < min_heap->arr[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swap_node(&min_heap->arr[smallest], &min_heap->arr[idx]);
        min_heapify(min_heap, smallest);
    }
}

node_t *extract_min_node(minHeap_t *min_heap) {
    node_t *temp = min_heap->arr[0];
    min_heap->arr[0] = min_heap->arr[min_heap->size - 1];

    --min_heap->size;
    min_heapify(min_heap, 0);

    return temp;
}

void insert_min_heap(minHeap_t *min_heap, node_t *node) {
    ++min_heap->size;
    int idx = min_heap->size - 1;

    while (idx && node->freq < min_heap->arr[(idx - 1) / 2]->freq) {
        min_heap->arr[idx] = min_heap->arr[(idx - 1) / 2];
        idx = (idx - 1) / 2;
    }

    min_heap->arr[idx] = node;
}

minHeap_t *build_min_heap(char *data, int *freq, int size) {
    minHeap_t *min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        min_heap->arr[i] = new_node(data[i], freq[i]);
    }

    min_heap->size = size;

    for (int i = (min_heap->size - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }

    return min_heap;
}

huffmanTree_t *build_huffman_tree(char *data, int *freq, int size) {
    huffmanTree_t *huffman_tree = (huffmanTree_t *)malloc(sizeof(huffmanTree_t));
    minHeap_t *min_heap = build_min_heap(data, freq, size);

    while (min_heap->size != 1) {
        node_t *left = extract_min_node(min_heap);
        node_t *right = extract_min_node(min_heap);

        node_t *temp = new_node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;

        insert_min_heap(min_heap, temp);
    }

    huffman_tree->root = extract_min_node(min_heap);

    return huffman_tree;
}

void print_codes(node_t *root, int arr[], int top, code_book_t *book) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1, book);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1, book);
    }

    if (!root->left && !root->right) {
        book->size = top;
        for (int i = 0; i < top; ++i) {
            sprintf(book->code, "%s%d", book->code, arr[i]);
        }
    }
}

code_book_t *build_code_book(huffmanTree_t *huffman_tree) {
    int arr[MAX_TREE_HT];
    code_book_t *book = (code_book_t *)malloc(sizeof(code_book_t));
    book->size = 0;
    print_codes(huffman_tree->root, arr, 0, book);

    return book;
}

void print_code_book(code_book_t *book) {
    printf("Code book:\n");
    for (int i = 0; i < 256; ++i) {
        if (book[i].size > 0) {
            printf("%c:\t%s\n", i, book[i].code);
        }
    }
}

void write_to_file(char *data, code_book_t *book, char *filename) {
    FILE *fp = fopen(filename, "wb");
    int len = strlen(data);

    fwrite(&len, sizeof(int), 1, fp);

    for (int i = 0; i < len; ++i) {
        fwrite(&book[data[i]].size, sizeof(int), 1, fp);
        fwrite(book[data[i]].code, sizeof(char), book[data[i]].size, fp);
    }

    fclose(fp);
}

char *read_from_file(code_book_t *book, char *filename) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    char *data = (char *)malloc(file_size + 1);
    memset(data, 0, file_size + 1);

    fread(&file_size, sizeof(int), 1, fp);

    for (int i = 0; i < file_size; ++i) {
        int size;
        fread(&size, sizeof(int), 1, fp);
        fread(book[i].code, sizeof(char), size, fp);
        book[i].size = size;
    }

    for (int i = 0; i < file_size; ++i) {
        printf("%s", book[i].code);
    }

    return data;
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    huffmanTree_t *huffman_tree = build_huffman_tree(data, freq, size);
    code_book_t *book = build_code_book(huffman_tree);
    print_code_book(book);
    write_to_file("abcdefabcdef", book, "compressed.bin");
    char *decompressed_data = read_from_file(book, "compressed.bin");

    printf("\noriginal text: abcdefabcdef\n");
    printf("decompressed text: %s\n", decompressed_data);

    return 0;
}