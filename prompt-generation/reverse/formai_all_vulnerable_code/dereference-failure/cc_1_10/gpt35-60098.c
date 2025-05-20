//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    int freq;
    struct node *left, *right;
};

struct heap {
    int count;
    int capacity;
    struct node **arr;
};

struct code {
    char data;
    char *bitstring;
};

struct hashtable {
    int size;
    struct code **table;
};

struct node* createNode(char data, int freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

struct heap* createHeap(int capacity) {
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->count = 0;
    h->capacity = capacity;
    h->arr = (struct node**)malloc(h->capacity * sizeof(struct node*));
    return h;
}

struct hashtable* createHashtable(int size) {
    struct hashtable* ht = (struct hashtable*)malloc(sizeof(struct hashtable));
    ht->size = size;
    ht->table = (struct code**)malloc(ht->size * sizeof(struct code*));
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void minHeapify(struct heap* h, int i) {
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < h->count && h->arr[left]->freq < h->arr[smallest]->freq) {
        smallest = left;
    }
    if (right < h->count && h->arr[right]->freq < h->arr[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        struct node* temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        minHeapify(h, smallest);
    }
}

int isHeapEmpty(struct heap* h) {
    return h->count == 0;
}

void insertHeap(struct heap* h, struct node* n) {
    h->count++;
    int i = h->count - 1;
    while (i > 0 && n->freq < h->arr[(i - 1) / 2]->freq) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = n;
}

struct node* removeMinHeap(struct heap* h) {
    struct node* temp = h->arr[0];
    h->arr[0] = h->arr[h->count - 1];
    h->count--;
    minHeapify(h, 0);
    return temp;
}

void buildMinHeap(struct heap* h) {
    int n = h->count;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(h, i);
    }
}

int isLeafNode(struct node* n) {
    return !(n->left) && !(n->right);
}

void generateCodes(struct node* root, char *bitstring, int index, struct hashtable* ht) {
    if (!root) return;
    if (isLeafNode(root)) {
        char c = root->data;
        ht->table[c]->data = c;
        ht->table[c]->bitstring = (char*)malloc((index+1) * sizeof(char));
        strcpy(ht->table[c]->bitstring, bitstring);
    }
    char lbitstring[100];
    strcpy(lbitstring, bitstring);
    char rbitstring[100];
    strcpy(rbitstring, bitstring);
    lbitstring[index] = '0';
    rbitstring[index] = '1';
    generateCodes(root->left, lbitstring, index+1, ht);
    generateCodes(root->right, rbitstring, index+1, ht);
}

void compressFile(char* filename, struct hashtable* ht) {
    FILE* fp = fopen(filename, "r");
    FILE* fpc = fopen("compressed.bin", "wb");
    char c;
    int index = 0;
    unsigned char byte = 0;
    while((c = fgetc(fp)) != EOF) {
        char* bitstring = ht->table[c]->bitstring;
        for (int i = 0; i < strlen(bitstring); i++) {
            if (bitstring[i] == '1') {
                byte |= (1 << (7 - index));
            }
            index++;
            if (index == 8) {
                fwrite(&byte, sizeof(unsigned char), 1, fpc);
                byte = 0;
                index = 0;
            }
        }
    }
    if (index > 0) {
        fwrite(&byte, sizeof(unsigned char), 1, fpc);
    }
    fclose(fp);
    fclose(fpc);
}

int main() {
    // Open file for reading
    FILE* fp = fopen("sample.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    // Count frequencies
    int freq[128] = {0};
    char c;
    while((c = fgetc(fp)) != EOF) {
        freq[c]++;
    }

    // Build heap
    struct heap* h = createHeap(128);
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            struct node* n = createNode((char)i, freq[i]);
            insertHeap(h, n);
        }
    }
    buildMinHeap(h);

    // Build Huffman Tree
    while (h->count > 1) {
        struct node* l = removeMinHeap(h);
        struct node* r = removeMinHeap(h);
        struct node* n = createNode('@', l->freq + r->freq);
        n->left = l;
        n->right = r;
        insertHeap(h, n);
    }
    struct hashtable* ht = createHashtable(128);
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            ht->table[i] = (struct code*)malloc(sizeof(struct code));
            ht->table[i]->data = (char)i;
            ht->table[i]->bitstring = "";
        }
    }
    struct node* root = removeMinHeap(h);
    generateCodes(root, "", 0, ht);

    // Compress file
    compressFile("sample.txt", ht);

    // Print codes
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            printf("%c: %s\n", ht->table[i]->data, ht->table[i]->bitstring);
        }
    }
    
    printf("File compressed successfully!\n");

    return 0;
}