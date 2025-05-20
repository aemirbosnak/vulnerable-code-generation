//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char ch;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct priority_queue {
    node **nodes;
    int len;
} priority_queue;

node *create_node(unsigned char ch, int freq) {
    node *n = (node*)malloc(sizeof(node));
    n->ch = ch;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

priority_queue *create_priority_queue() {
    priority_queue *pq = (priority_queue*)malloc(sizeof(priority_queue));
    pq->nodes = (node**)malloc(256 * sizeof(node*));
    pq->len = 0;
    return pq;
}

void enqueue(priority_queue *pq, node *n) {
    pq->nodes[pq->len++] = n;
    int i = pq->len - 1;
    while (i > 0 && pq->nodes[i]->freq < pq->nodes[(i-1)/2]->freq) {
        node *tmp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[(i-1)/2];
        pq->nodes[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

node *dequeue(priority_queue *pq) {
    node *n = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->len];
    int i = 0;
    while (2*i+1 < pq->len) {
        int j = 2*i+1;
        if (j+1 < pq->len && pq->nodes[j+1]->freq < pq->nodes[j]->freq)
            j++;
        if (pq->nodes[i]->freq <= pq->nodes[j]->freq)
            break;
        node *tmp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[j];
        pq->nodes[j] = tmp;
        i = j;
    }
    return n;
}

node *build_huffman_tree(int *freq) {
    priority_queue *pq = create_priority_queue();
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node *n = create_node(i, freq[i]);
            enqueue(pq, n);
        }
    }
    while (pq->len > 1) {
        node *n1 = dequeue(pq);
        node *n2 = dequeue(pq);
        int freq_sum = n1->freq + n2->freq;
        node *new_node = create_node('\0', freq_sum);
        new_node->left = n1;
        new_node->right = n2;
        enqueue(pq, new_node);
    }
    node *root = dequeue(pq);
    free(pq->nodes);
    free(pq);
    return root;
}

void encode(node *root, char *code, char **codes) {
    if (root->left) {
        code[strlen(code)] = '0';
        encode(root->left, code, codes);
        code[strlen(code)-1] = '\0';
    }
    if (root->right) {
        code[strlen(code)] = '1';
        encode(root->right, code, codes);
        code[strlen(code)-1] = '\0';
    }
    if (!root->left && !root->right) {
        codes[root->ch] = (char*)malloc((strlen(code)+1) * sizeof(char));
        strcpy(codes[root->ch], code);
    }
}

void free_tree(node *root) {
    if (root->left)
        free_tree(root->left);
    if (root->right)
        free_tree(root->right);
    free(root);
}

void huffman_encode(int *freq, unsigned char *data, int length, char **codes, int *encoded_length, unsigned char *encoded_data) {
    node *root = build_huffman_tree(freq);
    char code[256];
    memset(code, '\0', 256);
    encode(root, code, codes);
    int curr = 0;
    char buffer = 0;
    int bits_left = 8;
    for (int i = 0; i < length; i++) {
        char *encoded_char = codes[data[i]];
        int len = strlen(encoded_char);
        for (int j = 0; j < len; j++) {
            if (encoded_char[j] == '1')
                buffer |= 1 << (bits_left-1);
            bits_left--;
            if (bits_left == 0) {
                encoded_data[curr++] = buffer;
                bits_left = 8;
                buffer = 0;
            }
        }
    }
    if (bits_left != 8)
        encoded_data[curr++] = buffer;
    *encoded_length = curr;
    free_tree(root);
}

void huffman_decode(node *root, unsigned char *encoded_data, int encoded_length, unsigned char *decoded_data, int *decoded_length) {
    node *current = root;
    int curr = 0;
    for (int i = 0; i < encoded_length; i++) {
        unsigned char byte = encoded_data[i];
        for (int j = 0; j < 8; j++) {
            if (byte & (1 << (7-j)))
                current = current->right;
            else
                current = current->left;
            if (!current->left && !current->right) {
                decoded_data[curr++] = current->ch;
                current = root;
            }
        }
    }
    *decoded_length = curr;
}

int main() {
    int freq[256] = {0};
    char *message = "Hello world!";
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++)
        freq[(unsigned char)message[i]]++;
    char *codes[256];
    int encoded_length;
    unsigned char encoded_data[1000];
    huffman_encode(freq, message, message_length, codes, &encoded_length, encoded_data);
    printf("Encoded message:\n");
    for (int i = 0; i < encoded_length; i++)
        printf("%d ", encoded_data[i]);
    printf("\n");
    unsigned char decoded_data[1000];
    int decoded_length;
    huffman_decode(build_huffman_tree(freq), encoded_data, encoded_length, decoded_data, &decoded_length);
    printf("Decoded message:\n");
    for (int i = 0; i < decoded_length; i++)
        printf("%c", decoded_data[i]);
    printf("\n");
    for (int i = 0; i < 256; i++)
        if (codes[i])
            free(codes[i]);
    return 0;
}