//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct PriorityQueue {
    int size;
    Node **nodes;
} PriorityQueue;

Node *createNode(char character, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

PriorityQueue *createPriorityQueue(int size) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = size;
    pq->nodes = (Node **)malloc(sizeof(Node *) * size);
    return pq;
}

void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->nodes[left]->frequency < pq->nodes[smallest]->frequency) {
        smallest = left;
    }

    if (right < pq->size && pq->nodes[right]->frequency < pq->nodes[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != i) {
        swapNodes(&pq->nodes[i], &pq->nodes[smallest]);
        minHeapify(pq, smallest);
    }
}

Node *extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        return NULL;
    }

    Node *root = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}

void insertNode(PriorityQueue *pq, Node *node) {
    int i = pq->size++;
    pq->nodes[i] = node;

    while (i > 0 && pq->nodes[(i - 1) / 2]->frequency > pq->nodes[i]->frequency) {
        swapNodes(&pq->nodes[(i - 1) / 2], &pq->nodes[i]);
        i = (i - 1) / 2;
    }
}

Node *buildHuffmanTree(char *characters, int *frequencies, int size) {
    int i;

    PriorityQueue *pq = createPriorityQueue(size);

    for (i = 0; i < size; i++) {
        if (frequencies[i] > 0) {
            Node *node = createNode(characters[i], frequencies[i]);
            insertNode(pq, node);
        }
    }

    while (pq->size > 1) {
        Node *left = extractMin(pq);
        Node *right = extractMin(pq);

        Node *parent = createNode(' ', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        insertNode(pq, parent);
    }

    return extractMin(pq);
}

void printCodes(Node *root, char *code, int top) {
    if (root->character != ' ') {
        printf("%c: %s\n", root->character, code);
        return;
    }

    code[top] = '0';
    printCodes(root->left, code, top + 1);

    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

void encode(char *characters, int *frequencies, int size, char *message) {
    Node *root = buildHuffmanTree(characters, frequencies, size);

    int i, j;
    char code[size];

    for (i = 0; i < size; i++) {
        code[i] = ' ';
    }

    printCodes(root, code, 0);

    printf("Encoded message: ");
    for (i = 0; message[i] != '\0'; i++) {
        for (j = 0; j < size; j++) {
            if (message[i] == characters[j]) {
                printf("%s", code[j]);
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    char message[] = "this is a test message";

    encode(characters, frequencies, size, message);

    return 0;
}