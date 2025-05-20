//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: futuristic
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _HuffmanNode {
  struct _HuffmanNode *left;
  struct _HuffmanNode *right;
  uint8_t value;
  uint32_t frequency;
} HuffmanNode;

typedef struct _PriorityQueue {
  HuffmanNode **nodes;
  uint32_t size;
  uint32_t capacity;
} PriorityQueue;

HuffmanNode *create_node(uint8_t value, uint32_t frequency) {
  HuffmanNode *node = malloc(sizeof(HuffmanNode));
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  node->frequency = frequency;
  return node;
}

PriorityQueue *create_priority_queue(uint32_t capacity) {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->nodes = malloc(sizeof(HuffmanNode *) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

void enqueue(PriorityQueue *queue, HuffmanNode *node) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    queue->nodes = realloc(queue->nodes, sizeof(HuffmanNode *) * queue->capacity);
  }
  queue->nodes[queue->size++] = node;
}

HuffmanNode *dequeue(PriorityQueue *queue) {
  if (queue->size == 0) {
    return NULL;
  }
  uint32_t min_index = 0;
  for (uint32_t i = 1; i < queue->size; i++) {
    if (queue->nodes[i]->frequency < queue->nodes[min_index]->frequency) {
      min_index = i;
    }
  }
  HuffmanNode *node = queue->nodes[min_index];
  queue->nodes[min_index] = queue->nodes[queue->size - 1];
  queue->size--;
  return node;
}

HuffmanNode *build_huffman_tree(uint8_t *data, uint32_t length) {
  // Create a frequency table
  uint32_t frequencies[256] = {0};
  for (uint32_t i = 0; i < length; i++) {
    frequencies[data[i]]++;
  }

  // Create a priority queue
  PriorityQueue *queue = create_priority_queue(length);
  for (uint32_t i = 0; i < 256; i++) {
    if (frequencies[i] > 0) {
      enqueue(queue, create_node(i, frequencies[i]));
    }
  }

  // Build the Huffman tree
  while (queue->size > 1) {
    HuffmanNode *left_node = dequeue(queue);
    HuffmanNode *right_node = dequeue(queue);
    HuffmanNode *parent_node = create_node(0, left_node->frequency + right_node->frequency);
    parent_node->left = left_node;
    parent_node->right = right_node;
    enqueue(queue, parent_node);
  }

  // Return the root of the Huffman tree
  return dequeue(queue);
}

void print_huffman_codes(HuffmanNode *root, uint8_t *code, uint32_t code_length) {
  if (root->left == NULL && root->right == NULL) {
    printf("%c: ", root->value);
    for (uint32_t i = 0; i < code_length; i++) {
      printf("%d", code[i]);
    }
    printf("\n");
    return;
  }
  code[code_length] = 0;
  print_huffman_codes(root->left, code, code_length + 1);
  code[code_length] = 1;
  print_huffman_codes(root->right, code, code_length + 1);
}

void encode_data(HuffmanNode *root, uint8_t *data, uint32_t length, uint8_t *encoded_data) {
  uint32_t encoded_length = 0;
  uint8_t code[256] = {0};
  print_huffman_codes(root, code, 0);
  for (uint32_t i = 0; i < length; i++) {
    uint8_t *code_ptr = &code[data[i]];
    while (*code_ptr != 0) {
      encoded_data[encoded_length++] = *code_ptr++;
    }
  }
  encoded_data[encoded_length] = 0;
}

void decode_data(HuffmanNode *root, uint8_t *encoded_data, uint32_t length, uint8_t *decoded_data) {
  uint32_t decoded_length = 0;
  HuffmanNode *current_node = root;
  for (uint32_t i = 0; i < length; i++) {
    if (encoded_data[i] == 0) {
      decoded_data[decoded_length++] = current_node->value;
      current_node = root;
    } else {
      current_node = current_node->right;
    }
  }
  decoded_data[decoded_length] = 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Read the input file
  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", argv[1]);
    return 1;
  }
  fseek(input_file, 0, SEEK_END);
  uint32_t input_file_size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);
  uint8_t *input_data = malloc(input_file_size);
  fread(input_data, 1, input_file_size, input_file);
  fclose(input_file);

  // Build the Huffman tree
  HuffmanNode *root = build_huffman_tree(input_data, input_file_size);

  // Encode the data
  uint8_t *encoded_data = malloc(input_file_size * 2);
  encode_data(root, input_data, input_file_size, encoded_data);

  // Write the encoded data to the output file
  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    printf("Error opening output file: %s\n", argv[2]);
    return 1;
  }
  fwrite(encoded_data, 1, strlen((char *)encoded_data), output_file);
  fclose(output_file);

  // Decode the data
  uint8_t *decoded_data = malloc(input_file_size);
  decode_data(root, encoded_data, strlen((char *)encoded_data), decoded_data);

  // Check if the decoded data is the same as the original data
  if (memcmp(input_data, decoded_data, input_file_size) == 0) {
    printf("Data successfully compressed and decompressed!\n");
  } else {
    printf("Error: Decoded data is not the same as the original data!\n");
  }

  // Free the allocated memory
  free(input_data);
  free(encoded_data);
  free(decoded_data);
  free(root);

  return 0;
}