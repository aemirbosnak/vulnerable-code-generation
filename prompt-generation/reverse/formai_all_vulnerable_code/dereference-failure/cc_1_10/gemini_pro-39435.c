//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CHAR 256

typedef struct node {
    char c;
    unsigned frequency;
    struct node *left, *right;
} node;

typedef struct thread_data {
    char *str;
    int str_len;
    node *root;
} thread_data;

node *create_node(char c, unsigned frequency) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->c = c;
    new_node->frequency = frequency;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node *create_tree(char *str, int str_len) {
    unsigned frequency[MAX_CHAR] = {0};
    for (int i = 0; i < str_len; i++) {
        frequency[str[i]]++;
    }

    node *queue[str_len];
    int front = 0, rear = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i]) {
            queue[rear++] = create_node(i, frequency[i]);
        }
    }

    while (rear > 1) {
        node *left = queue[front++];
        node *right = queue[front++];
        node *parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        queue[rear++] = parent;
    }

    return queue[front];
}

void encode(node *root, char *str, int str_len, char *encoded_str) {
    for (int i = 0; i < str_len; i++) {
        node *temp = root;
        while (temp->left || temp->right) {
            if (str[i] == temp->c) {
                break;
            } else if (str[i] < temp->c) {
                temp = temp->left;
                encoded_str[i] = '0';
            } else {
                temp = temp->right;
                encoded_str[i] = '1';
            }
        }
    }
}

void decode(node *root, char *encoded_str, int encoded_str_len, char *decoded_str) {
    node *temp = root;
    for (int i = 0; i < encoded_str_len; i++) {
        if (encoded_str[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }

        if (!temp->left && !temp->right) {
            decoded_str[i] = temp->c;
            temp = root;
        }
    }
}

void *thread_function(void *arg) {
    thread_data *data = (thread_data *)arg;
    char *encoded_str = (char *)malloc(data->str_len * sizeof(char));
    encode(data->root, data->str, data->str_len, encoded_str);
    pthread_exit((void *)encoded_str);
}

int main() {
    char str[] = "Hello World";
    int str_len = strlen(str);

    node *root = create_tree(str, str_len);

    pthread_t thread;
    thread_data data = {str, str_len, root};
    pthread_create(&thread, NULL, thread_function, &data);
    void *encoded_str;
    pthread_join(thread, &encoded_str);

    char decoded_str[str_len];
    decode(root, encoded_str, str_len, decoded_str);
    printf("Original string: %s\n", str);
    printf("Encoded string: %s\n", encoded_str);
    printf("Decoded string: %s\n", decoded_str);

    return 0;
}