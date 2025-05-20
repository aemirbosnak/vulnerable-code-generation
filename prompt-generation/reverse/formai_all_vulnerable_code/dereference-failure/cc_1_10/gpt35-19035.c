//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

typedef struct HuffmanNode {
    char symbol;
    int freq;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

typedef struct PriorityQueueNode {
    HuffmanNode* node;
    int priority;
} PriorityQueueNode;

typedef struct PriorityQueue {
    PriorityQueueNode* nodes[MAX_LENGTH];
    int size;
} PriorityQueue;

typedef struct CodeTable {
    char symbol;
    char* code;
} CodeTable;

char* encode(char* message, CodeTable* table) {
    int message_length = strlen(message);
    char* encoded = malloc(sizeof(char) * 2 * message_length);
    encoded[0] = '\0';

    for (int i = 0; i < message_length; i++) {
        for (int j = 0; table[j].code != NULL; j++) {
            if (message[i] == table[j].symbol) {
                strcat(encoded, table[j].code);
                break;
            }
        }
    }

    return encoded;
}

char* decode(char* message, HuffmanNode* tree) {
    HuffmanNode* current_node = tree;
    int message_length = strlen(message);
    char* decoded = malloc(sizeof(char) * message_length / 2);
    decoded[0] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (message[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }

        if (current_node->left == NULL && current_node->right == NULL) {
            strncat(decoded, &(current_node->symbol), 1);
            current_node = tree;
        }
    }

    return decoded;
}

void compute_frequencies(char* message, int* frequencies) {
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        frequencies[(int) message[i]]++;
    }
}

HuffmanNode* create_node(char symbol, int freq) {
    HuffmanNode* node = malloc(sizeof(HuffmanNode));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

PriorityQueueNode* create_priority_queue_node(HuffmanNode* node, int priority) {
    PriorityQueueNode* queue_node = malloc(sizeof(PriorityQueueNode));
    queue_node->node = node;
    queue_node->priority = priority;

    return queue_node;
}

PriorityQueue* create_priority_queue() {
    PriorityQueue* queue = malloc(sizeof(PriorityQueue));
    queue->size = 0;

    return queue;
}

void enqueue(PriorityQueue* queue, PriorityQueueNode* node) {
    if (queue->size == MAX_LENGTH) {
        return;
    }

    queue->nodes[queue->size] = node;
    queue->size++;

    int current = queue->size - 1;

    while (current > 0) {
        int parent = (current - 1) / 2;

        if (queue->nodes[parent]->priority <= queue->nodes[current]->priority) {
            break;
        }

        PriorityQueueNode* temp = queue->nodes[parent];
        queue->nodes[parent] = queue->nodes[current];
        queue->nodes[current] = temp;
        current = parent;
    }
}

PriorityQueueNode* dequeue(PriorityQueue* queue) {
    if (queue->size == 0) {
        return NULL;
    }

    PriorityQueueNode* result = queue->nodes[0];
    queue->size--;

    if (queue->size > 0) {
        queue->nodes[0] = queue->nodes[queue->size];
        int current = 0;

        while (current < queue->size) {
            int left_child = current * 2 + 1;
            int right_child = current * 2 + 2;
            int smallest_child = current;

            if (left_child < queue->size && queue->nodes[left_child]->priority < queue->nodes[smallest_child]->priority) {
                smallest_child = left_child;
            }

            if (right_child < queue->size && queue->nodes[right_child]->priority < queue->nodes[smallest_child]->priority) {
                smallest_child = right_child;
            }

            if (smallest_child == current) {
                break;
            }

            PriorityQueueNode* temp = queue->nodes[smallest_child];
            queue->nodes[smallest_child] = queue->nodes[current];
            queue->nodes[current] = temp;
            current = smallest_child;
        }
    }

    return result;
}

HuffmanNode* build_tree(int* frequencies) {
    PriorityQueue* queue = create_priority_queue();

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (frequencies[i] > 0) {
            HuffmanNode* node = create_node(i, frequencies[i]);
            PriorityQueueNode* queue_node = create_priority_queue_node(node, frequencies[i]);
            enqueue(queue, queue_node);
        }
    }

    while (queue->size > 1) {
        PriorityQueueNode* first = dequeue(queue);
        PriorityQueueNode* second = dequeue(queue);
        HuffmanNode* new_node = create_node(-1, first->node->freq + second->node->freq);
        new_node->left = first->node;
        new_node->right = second->node;
        PriorityQueueNode* new_queue_node = create_priority_queue_node(new_node, new_node->freq);
        enqueue(queue, new_queue_node);
        free(first);
        free(second);
    }

    HuffmanNode* root = dequeue(queue)->node;
    free(queue);

    return root;
}

void build_code_table(HuffmanNode* tree, char* path, int depth, CodeTable* table) {
    if (tree == NULL) {
        return;
    }

    if (tree->left == NULL && tree->right == NULL) {
        int index = (int) tree->symbol;
        table[index].symbol = tree->symbol;
        table[index].code = malloc(sizeof(char) * (depth + 1));
        strcpy(table[index].code, path);
        return;
    }

    char left_path[MAX_LENGTH];
    strcpy(left_path, path);
    strcat(left_path, "0");
    build_code_table(tree->left, left_path, depth + 1, table);

    char right_path[MAX_LENGTH];
    strcpy(right_path, path);
    strcat(right_path, "1");
    build_code_table(tree->right, right_path, depth + 1, table);
}

CodeTable* build_code_table_wrapper(HuffmanNode* tree) {
    CodeTable* table = malloc(sizeof(CodeTable) * MAX_LENGTH);
    memset(table, 0, sizeof(CodeTable) * MAX_LENGTH);
    char path[MAX_LENGTH] = "";

    build_code_table(tree, path, 0, table);

    return table;
}

void destroy_huffman_tree(HuffmanNode* tree) {
    if (tree != NULL) {
        destroy_huffman_tree(tree->left);
        destroy_huffman_tree(tree->right);
        free(tree);
    }
}

void destroy_code_table(CodeTable* table) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (table[i].code != NULL) {
            free(table[i].code);
        }
    }

    free(table);
}

void print_code_table(CodeTable* table) {
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (table[i].code != NULL) {
            printf("Symbol: %c Code: %s\n", table[i].symbol, table[i].code);
        }
    }
}

int main() {
    char message[] = "abracadabra";
    int frequencies[MAX_LENGTH] = {0};

    compute_frequencies(message, frequencies);

    HuffmanNode* tree = build_tree(frequencies);
    CodeTable* table = build_code_table_wrapper(tree);

    printf("Code table:\n");
    print_code_table(table);

    char* encoded_message = encode(message, table);
    printf("Encoded message: %s\n", encoded_message);

    char* decoded_message = decode(encoded_message, tree);
    printf("Decoded message: %s\n", decoded_message);

    free(encoded_message);
    free(decoded_message);
    destroy_code_table(table);
    destroy_huffman_tree(tree);

    return 0;
}