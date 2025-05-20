//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
    uint8_t c;
    uint32_t freq;
    struct node *left, *right;
} node;

typedef struct heap {
    uint32_t size;
    uint32_t capacity;
    node **nodes;
} heap;

heap *create_heap(uint32_t capacity) {
    heap *h = malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->nodes = malloc(capacity * sizeof(node *));
    return h;
}

void swap(node **n1, node **n2) {
    node *temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(heap *h, int32_t i) {
    int32_t smallest = i;
    int32_t left = 2 * i + 1;
    int32_t right = 2 * i + 2;

    if (left < h->size && h->nodes[left]->freq < h->nodes[smallest]->freq) {
        smallest = left;
    }
    if (right < h->size && h->nodes[right]->freq < h->nodes[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&h->nodes[smallest], &h->nodes[i]);
        heapify(h, smallest);
    }
}

node *extract_min(heap *h) {
    node *temp = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify(h, 0);
    return temp;
}

void insert(heap *h, node *n) {
    h->size++;
    int32_t i = h->size - 1;
    while (i > 0 && n->freq < h->nodes[(i - 1) / 2]->freq) {
        h->nodes[i] = h->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->nodes[i] = n;
}

node *create_node(uint8_t c, uint32_t freq) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void populate_freq_table(FILE *f, uint32_t *freq_table) {
    uint8_t buffer[1024];
    size_t read_size;
    while ((read_size = fread(buffer, sizeof(uint8_t), 1024, f)) > 0) {
        for (size_t i = 0; i < read_size; i++) {
            freq_table[buffer[i]]++;
        }
    }
}

node *build_huffman_tree(uint32_t *freq_table) {
    heap *h = create_heap(256);
    for (uint16_t i = 0; i < 256; i++) {
        if (freq_table[i] > 0) {
            node *n = create_node(i, freq_table[i]);
            insert(h, n);
        }
    }
    while (h->size > 1) {
        node *n1 = extract_min(h);
        node *n2 = extract_min(h);
        node *temp = create_node(0, n1->freq + n2->freq);
        temp->left = n1;
        temp->right = n2;
        insert(h, temp);
    }
    node *root = extract_min(h);
    free(h->nodes);
    free(h);
    return root;
}

void populate_code_table(node *root, char *code_table[], char *buffer, uint8_t buffer_index) {
    if (root->left == NULL && root->right == NULL) {
        buffer[buffer_index] = '\0';
        code_table[root->c] = malloc((buffer_index + 1) * sizeof(char));
        strcpy(code_table[root->c], buffer);
        return;
    }
    buffer[buffer_index] = '0';
    populate_code_table(root->left, code_table, buffer, buffer_index + 1);

    buffer[buffer_index] = '1';
    populate_code_table(root->right, code_table, buffer, buffer_index + 1);
}

void encode(FILE *input_file, FILE *output_file, char *code_table[]) {
    uint8_t buffer[1024];
    uint8_t output_buffer = 0;
    uint8_t bits_written = 0;
    size_t read_size;
    while ((read_size = fread(buffer, sizeof(uint8_t), 1024, input_file)) > 0) {
        for (size_t i = 0; i < read_size; i++) {
            char *code = code_table[buffer[i]];
            while (*code != '\0') {
                output_buffer <<= 1;
                output_buffer |= (*code == '1');
                bits_written++;
                if (bits_written == 8) {
                    fwrite(&output_buffer, sizeof(uint8_t), 1, output_file);
                    output_buffer = 0;
                    bits_written = 0;
                }
                code++;
            }
        }
    }
    if (bits_written > 0) {
        output_buffer <<= (8 - bits_written);
        fwrite(&output_buffer, sizeof(uint8_t), 1, output_file);
    }
}

void decode(FILE *input_file, FILE *output_file, node *root, uint32_t file_size) {
    node *curr_node = root;
    uint32_t bytes_read = 0;
    while (bytes_read < file_size) {
        uint8_t buffer;
        fread(&buffer, sizeof(uint8_t), 1, input_file);
        for (int32_t i = 7; i >= 0; i--) {
            if ((buffer >> i) & 1) {
                curr_node = curr_node->right;
            } else {
                curr_node = curr_node->left;
            }
            if (curr_node->left == NULL && curr_node->right == NULL) {
                fwrite(&curr_node->c, sizeof(uint8_t), 1, output_file);
                curr_node = root;
                bytes_read++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encode | decode> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        perror(argv[3]);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "encode") == 0) {
        uint32_t freq_table[256] = {0};
        populate_freq_table(input_file, freq_table);
        rewind(input_file);
        node *root = build_huffman_tree(freq_table);
        char *code_table[256] = {0};
        char buffer[256];
        populate_code_table(root, code_table, buffer, 0);
        fwrite(freq_table, sizeof(uint32_t), 256, output_file);
        fseek(output_file, 1024 * sizeof(char), SEEK_CUR);
        encode(input_file, output_file, code_table);
        fseek(output_file, sizeof(uint32_t), SEEK_SET);
        uint32_t file_size = ftell(output_file);
        file_size -= (256 * sizeof(uint32_t) + 1024 * sizeof(char));
        fwrite(&file_size, sizeof(uint32_t), 1, output_file);
        fclose(input_file);
        fclose(output_file);
        for (int32_t i = 0; i < 256; i++) {
            if (code_table[i] != NULL) {
                free(code_table[i]);
            }
        }
        free(root);
    } else if (strcmp(argv[1], "decode") == 0) {
        uint32_t freq_table[256];
        fread(freq_table, sizeof(uint32_t), 256, input_file);
        node *root = build_huffman_tree(freq_table);
        char buffer[256];
        populate_code_table(root, NULL, buffer, 0);
        uint32_t file_size;
        fseek(input_file, -sizeof(uint32_t), SEEK_END);
        fread(&file_size, sizeof(uint32_t), 1, input_file);
        rewind(input_file);
        fseek(input_file, 256 * sizeof(uint32_t), SEEK_CUR);
        decode(input_file, output_file, root, file_size);
        fclose(input_file);
        fclose(output_file);
        free(root);
    } else {
        fprintf(stderr, "Usage: %s <encode | decode> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}