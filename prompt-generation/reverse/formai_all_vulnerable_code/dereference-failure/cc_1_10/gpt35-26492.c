//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    unsigned char character;
    unsigned int frequency;
    struct node *left, *right;
} Node;

typedef struct {
    Node **array;
    int size;
} MinHeap;

typedef struct {
    unsigned char *array;
    int size;
} CodeTable;

Node *create_node(unsigned char character, unsigned int frequency, Node *left, Node *right) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

MinHeap *create_min_heap(int capacity) {
    MinHeap *min_heap = (MinHeap*) malloc(sizeof(MinHeap));
    min_heap->array = (Node**) malloc(sizeof(Node*) * capacity);
    min_heap->size = 0;
    return min_heap;
}

CodeTable *create_code_table(int capacity) {
    CodeTable *code_table = (CodeTable*) malloc(sizeof(CodeTable));
    code_table->array = (unsigned char*) malloc(sizeof(unsigned char) * capacity);
    code_table->size = 0;
    return code_table;
}

void swap_nodes(Node **node1, Node **node2) {
    Node *temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

void heapify(MinHeap *min_heap, int index) {
    int smallest_index = index;
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    if (left_child_index < min_heap->size && min_heap->array[left_child_index]->frequency < min_heap->array[smallest_index]->frequency)
        smallest_index = left_child_index;
    if (right_child_index < min_heap->size && min_heap->array[right_child_index]->frequency < min_heap->array[smallest_index]->frequency)
        smallest_index = right_child_index;
    if (smallest_index != index) {
        swap_nodes(&min_heap->array[smallest_index], &min_heap->array[index]);
        heapify(min_heap, smallest_index);
    }
}

void insert_node(MinHeap *min_heap, Node *node) {
    ++min_heap->size;
    int i = min_heap->size - 1;
    while (i && node->frequency < min_heap->array[(i - 1) / 2]->frequency) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    min_heap->array[i] = node;
}

Node *extract_min_node(MinHeap *min_heap) {
    Node *min_node = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    heapify(min_heap, 0);
    return min_node;
}

int is_leaf_node(Node *node) {
    return !(node->left) && !(node->right);
}

void build_min_heap(MinHeap *min_heap) {
    int n = min_heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        heapify(min_heap, i);
}

Node *build_huffman_tree(unsigned char *characters, unsigned int *frequencies, int size) {
    MinHeap *min_heap = create_min_heap(size);
    for (int i = 0; i < size; ++i)
        insert_node(min_heap, create_node(characters[i], frequencies[i], NULL, NULL));
    build_min_heap(min_heap);
    while (min_heap->size > 1) {
        Node *left_child = extract_min_node(min_heap);
        Node *right_child = extract_min_node(min_heap);
        Node *parent_node = create_node('\0', left_child->frequency + right_child->frequency, left_child, right_child);
        insert_node(min_heap, parent_node);
    }
    return extract_min_node(min_heap);
}

void generate_codes(Node *root, CodeTable *code_table, unsigned char *code_array, int code_index) {
    if (root) {
        if (is_leaf_node(root)) {
            for (int i = 0; i < code_index; ++i)
                code_table->array[root->character * 100 + i] = code_array[i];
            code_table->size += code_index;
            return;
        }
        code_array[code_index] = '0';
        generate_codes(root->left, code_table, code_array, code_index + 1);
        code_array[code_index] = '1';
        generate_codes(root->right, code_table, code_array, code_index + 1);
    }
}

void huffman_encoding(unsigned char *input_string, int input_size, CodeTable *code_table) {
    unsigned char *characters = (unsigned char*) malloc(sizeof(unsigned char) * input_size);
    unsigned int *frequencies = (unsigned int*) malloc(sizeof(unsigned int) * input_size);
    int size = 0;
    for (int i = 0; i < input_size; ++i) {
        int j;
        for (j = 0; j < size; ++j)
            if (characters[j] == input_string[i]) {
                ++frequencies[j];
                break;
            }
        if (j == size) {
            characters[size] = input_string[i];
            frequencies[size++] = 1;
        }
    }
    Node *root = build_huffman_tree(characters, frequencies, size);
    unsigned char code_array[100];
    generate_codes(root, code_table, code_array, 0);
    free(characters);
    free(frequencies);
}

void huffman_decoding(unsigned char *encoded_string, int encoded_size, Node *root) {
    Node *temp = root;
    for (int i = 0; i < encoded_size; ++i) {
        if (encoded_string[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;
        if (is_leaf_node(temp)) {
            printf("%c", temp->character);
            temp = root;
        }
    }
}

int main() {
    unsigned char input_string[] = "Write a unique C Huffman Coding Implementation example program";
    int input_size = sizeof(input_string) / sizeof(input_string[0]) - 1; // subtracting 1 to ignore '\0' character
    CodeTable *code_table = create_code_table(input_size);
    huffman_encoding(input_string, input_size, code_table);
    printf("Code Table\n");
    for (int i = 0; i < input_size; ++i) {
        printf("%c - ", i);
        for (int j = 0; j < code_table->size; ++j)
            if (code_table->array[i * 100 + j] != '\0')
                printf("%c", code_table->array[i * 100 + j]);
        printf("\n");
    }
    printf("Original String: %s\n", input_string);
    printf("Encoded String: ");
    for (int i = 0; i < input_size; ++i)
        for (int j = 0; j < code_table->size; ++j)
            if (input_string[i] == j) {
                for (int k = 0; k < code_table->size; ++k)
                    if (code_table->array[j * 100 + k] != '\0')
                        printf("%c", code_table->array[j * 100 + k]);
                break;
            }
    printf("\n");
    Node *root = build_huffman_tree(code_table->array, NULL, input_size * 100); // building tree from code table
    printf("Decoded String: ");
    huffman_decoding("10001010100011111000010011100011111101000011101000011100100000001011011011111000111000000110101111010111110111100111110000011000101110001101000111011",
                     135, root);
    printf("\n");
    free(code_table->array);
    free(code_table);
    return 0;
}