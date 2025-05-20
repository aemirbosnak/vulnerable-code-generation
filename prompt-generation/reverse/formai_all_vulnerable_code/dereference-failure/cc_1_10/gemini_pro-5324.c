//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char character;
    unsigned int frequency;
    struct node *left;
    struct node *right;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

void enqueue(queue_t *queue, node_t *node) {
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->right = node;
        queue->rear = node;
    }
}

node_t *dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    node_t *node = queue->front;
    queue->front = queue->front->right;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return node;
}

node_t *build_huffman_tree(unsigned char *message, unsigned int length) {
    unsigned int frequencies[256] = {0};
    for (unsigned int i = 0; i < length; i++) {
        frequencies[message[i]]++;
    }

    queue_t queue;
    queue.front = NULL;
    queue.rear = NULL;
    for (unsigned char i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            node_t *node = malloc(sizeof(node_t));
            node->character = i;
            node->frequency = frequencies[i];
            node->left = NULL;
            node->right = NULL;
            enqueue(&queue, node);
        }
    }

    while (queue.front != NULL && queue.front->right != NULL) {
        node_t *node1 = dequeue(&queue);
        node_t *node2 = dequeue(&queue);
        node_t *parent = malloc(sizeof(node_t));
        parent->character = 0;
        parent->frequency = node1->frequency + node2->frequency;
        parent->left = node1;
        parent->right = node2;
        enqueue(&queue, parent);
    }

    return queue.front;
}

void print_huffman_code(node_t *node, char *code, unsigned int length) {
    if (node->left == NULL && node->right == NULL) {
        printf("%c: %s\n", node->character, code);
    } else {
        char left_code[length + 1];
        char right_code[length + 1];
        strcpy(left_code, code);
        strcpy(right_code, code);
        strcat(left_code, "0");
        strcat(right_code, "1");
        print_huffman_code(node->left, left_code, length + 1);
        print_huffman_code(node->right, right_code, length + 1);
    }
}

char *encode_message(node_t *tree, unsigned char *message, unsigned int length) {
    char *encoded_message = malloc(length * 8 + 1);
    unsigned int index = 0;
    for (unsigned int i = 0; i < length; i++) {
        node_t *node = tree;
        while (node->left != NULL && node->right != NULL) {
            if (message[i] == node->left->character) {
                strcat(encoded_message, "0");
                node = node->left;
            } else {
                strcat(encoded_message, "1");
                node = node->right;
            }
        }
    }
    encoded_message[length * 8] = '\0';
    return encoded_message;
}

unsigned char *decode_message(node_t *tree, char *encoded_message, unsigned int length) {
    unsigned char *decoded_message = malloc(length + 1);
    unsigned int index = 0;
    node_t *node = tree;
    for (unsigned int i = 0; i < length; i++) {
        if (encoded_message[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->left == NULL && node->right == NULL) {
            decoded_message[index++] = node->character;
            node = tree;
        }
    }
    decoded_message[index] = '\0';
    return decoded_message;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    unsigned char *message = argv[1];
    unsigned int length = strlen(message);

    node_t *tree = build_huffman_tree(message, length);

    char *code = malloc(length * 8 + 1);
    print_huffman_code(tree, code, 0);

    char *encoded_message = encode_message(tree, message, length);
    printf("Encoded message: %s\n", encoded_message);

    unsigned char *decoded_message = decode_message(tree, encoded_message, strlen(encoded_message));
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}