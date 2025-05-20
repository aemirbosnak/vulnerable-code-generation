//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define BITS_PER_BYTE 8 /**< Number of bits in a byte. */
#define MAX_TREE_HT 512 /**< Maximum height of Huffman tree. */

/**
 * @brief Huffman tree node.
 *
 * Represents a node of the Huffman tree with a character, its frequency,
 * pointers to left and right children, and a character buffer to store the
 * encoding computed during tree traversal.
 */
typedef struct node_t {
    char character; /**< Character associated with node. */
    uint32_t frequency; /**< Frequency of the character. */
    struct node_t *left; /**< Pointer to left child. */
    struct node_t *right; /**< Pointer to right child. */
    char encoding[MAX_TREE_HT]; /**< Huffman encoding. */
} node_t;

/**
 * @brief Priority queue node.
 *
 * Represents a node of the priority queue with a character, its frequency,
 * and a pointer to the Huffman tree node it represents.
 */
typedef struct pq_node_t {
    char character; /**< Character associated with node. */
    uint32_t frequency; /**< Frequency of the character. */
    node_t *huffman_node; /**< Pointer to Huffman tree node. */
    struct pq_node_t *next; /**< Pointer to next node in the priority queue. */
} pq_node_t;

/**
 * @brief Priority queue.
 *
 * Represents a priority queue for building the Huffman tree. The queue
 * is implemented as a singly linked list with the head always pointing to
 * the element with the lowest frequency.
 */
typedef struct priority_queue_t {
    pq_node_t *head; /**< Pointer to first element in the queue. */
    uint32_t size; /**< Number of elements in the queue. */
} priority_queue_t;

/**
 * @brief Compute Huffman encoding for each character in the tree.
 *
 * Traverses the Huffman tree recursively and computes the encoding for
 * each character by concatenating 0 for each left child and 1 for each
 * right child.
 *
 * @param[in]   node    A pointer to the current node being traversed.
 * @param[in]   code    The current code being computed.
 * @param[in]   level   The current depth of the tree.
 *
 * @return  void
 */
void compute_encoding(node_t *node, char *code, int level)
{
    if (node == NULL) {
        return;
    }

    /* Prepend current level to the encoding buffer and increment level. */
    node->encoding[level] = *code;
    level++;
    code++;

    /* Terminate encoding buffer with null character. */
    node->encoding[level] = '\0';

    if (node->left == NULL && node->right == NULL) {
        /* We have reached a leaf node, so the encoding is complete. */
        return;
    }

    /* Traverse left child with encoding 0. */
    compute_encoding(node->left, code, level);

    /* Traverse right child with encoding 1. */
    compute_encoding(node->right, code, level);
}

/**
 * @brief Create a new priority queue node.
 *
 * Creates a new priority queue node with the specified character,
 * frequency, and Huffman tree node pointer.
 *
 * @param[in]   character   The character associated with the node.
 * @param[in]   frequency   The frequency of the character.
 * @param[in]   huffman_node    A pointer to the Huffman tree node.
 *
 * @return  A pointer to the new priority queue node.
 */
pq_node_t *pq_node_new(char character, uint32_t frequency, node_t *huffman_node)
{
    pq_node_t *node = (pq_node_t *)malloc(sizeof(pq_node_t));
    node->character = character;
    node->frequency = frequency;
    node->huffman_node = huffman_node;
    node->next = NULL;
    return node;
}

/**
 * @brief Create a new Huffman tree node.
 *
 * Creates a new Huffman tree node with the specified character and
 * frequency.
 *
 * @param[in]   character   The character associated with the node.
 * @param[in]   frequency   The frequency of the character.
 *
 * @return  A pointer to the new Huffman tree node.
 */
node_t *node_new(char character, uint32_t frequency)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    memset(node->encoding, 0, sizeof(node->encoding));
    return node;
}

/**
 * @brief Create a new priority queue.
 *
 * Creates a new priority queue.
 *
 * @return  A pointer to the new priority queue.
 */
priority_queue_t *pq_new()
{
    priority_queue_t *pq = (priority_queue_t *)malloc(sizeof(priority_queue_t));
    pq->head = NULL;
    pq->size = 0;
    return pq;
}

/**
 * @brief Push a new element onto the priority queue.
 *
 * Creates a new priority queue node with the specified character,
 * frequency, and Huffman tree node, and inserts the node into the
 * priority queue at the correct position based on frequency.
 *
 * @param[in]   pq  A pointer to the priority queue.
 * @param[in]   character   The character associated with the node.
 * @param[in]   frequency   The frequency of the character.
 * @param[in]   huffman_node    A pointer to the Huffman tree node.
 *
 * @return  void
 */
void pq_push(priority_queue_t *pq, char character, uint32_t frequency, node_t *huffman_node)
{
    pq_node_t *node = pq_node_new(character, frequency, huffman_node);

    /* If queue is empty or new node has lower frequency than head node, insert at head. */
    if (pq->head == NULL || frequency <= pq->head->frequency) {
        node->next = pq->head;
        pq->head = node;
    } else {
        /* Find the node after which the new node should be inserted. */
        pq_node_t *prev = pq->head;
        while (prev->next != NULL && prev->next->frequency < frequency) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }

    pq->size++;
}

/**
 * @brief Pop the minimum element from the priority queue.
 *
 * Removes the element with the lowest frequency from the priority queue
 * and returns a pointer to the Huffman tree node it represents.
 *
 * @param[in]   pq  A pointer to the priority queue.
 *
 * @return  A pointer to the Huffman tree node.
 */
node_t *pq_pop(priority_queue_t *pq)
{
    assert(pq->head != NULL);

    /* Remove the head node and return a pointer to its Huffman tree node. */
    pq_node_t *node = pq->head;
    pq->head = node->next;
    pq->size--;
    node_t *huffman_node = node->huffman_node;
    free(node);
    return huffman_node;
}

/**
 * @brief Build the Huffman tree from a frequency table.
 *
 * Builds the Huffman tree from a frequency table by creating a priority queue
 * of Huffman tree nodes initialized with each character and its frequency.
 * The queue is then iteratively popped until there is only one node remaining,
 * which represents the root of the Huffman tree.
 *
 * @param[in]   frequency_table A pointer to the frequency table.
 * @param[in]   table_size  The number of entries in the frequency table.
 *
 * @return  A pointer to the root node of the Huffman tree.
 */
node_t *build_tree(uint32_t *frequency_table, int table_size)
{
    /* Create a priority queue for each character in the frequency table. */
    priority_queue_t *pq = pq_new();
    for (int i = 0; i < table_size; i++) {
        uint32_t frequency = frequency_table[i];
        if (frequency != 0) {
            char character = (char)i;
            pq_push(pq, character, frequency, node_new(character, frequency));
        }
    }

    /* Pop pairs of nodes from the priority queue until only one remains. */
    while (pq->size > 1) {
        node_t *left_child = pq_pop(pq);
        node_t *right_child = pq_pop(pq);
        pq_push(pq, '\0', left_child->frequency + right_child->frequency,
                node_new('\0', left_child->frequency + right_child->frequency));
        pq->head->huffman_node->left = left_child;
        pq->head->huffman_node->right = right_child;
    }

    /* Pop the remaining node from the priority queue and return it. */
    node_t *root = pq_pop(pq);
    free(pq);
    return root;
}

/**
 * @brief Compress a message using Huffman coding.
 *
 * Compresses a message using Huffman coding by building a frequency table,
 * building the Huffman tree, computing the encoding for each character in
 * the tree, and finally encoding the message using the computed encoding.
 *
 * @param[in]   message The message to compress.
 * @param[in]   message_length  The length of the message in bytes.
 * @param[out]  compressed_message  A pointer to the compressed message.
 * @param[out]  compressed_size The size of the compressed message in bytes.
 *
 * @return  void
 */
void compress_message(const char *message, int message_length, uint8_t **compressed_message, int *compressed_size)
{
    uint32_t frequency_table[256] = {0};

    /* Compute the frequency of each character in the message. */
    for (int i = 0; i < message_length; i++) {
        frequency_table[(uint8_t)message[i]]++;
    }

    /* Build the Huffman tree from the frequency table. */
    node_t *root = build_tree(frequency_table, 256);

    /* Compute the encoding for each character in the Huffman tree. */
    char code[MAX_TREE_HT] = {0};
    compute_encoding(root, code, 0);

    /* Encode the message using the computed encoding. */
    int bits_written = 0;
    int compressed_buffer_size = (message_length * MAX_TREE_HT) / BITS_PER_BYTE + 1;
    uint8_t *compressed_buffer = (uint8_t *)malloc(compressed_buffer_size);
    memset(compressed_buffer, 0, compressed_buffer_size);

    for (int i = 0; i < message_length; i++) {
        const char *encoding = root->encoding[(uint8_t)message[i]];
        int encoding_length = strlen(encoding);
        for (int j = 0; j < encoding_length; j++) {
            compressed_buffer[bits_written / BITS_PER_BYTE] |=
                (encoding[j] - '0') << (BITS_PER_BYTE - 1 - bits_written % BITS_PER_BYTE);
            bits_written++;
        }
    }

    /* Compute the size of the compressed message and return it. */
    *compressed_size = (bits_written + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    *compressed_message = compressed_buffer;

    free(root);
}

/**
 * @brief Decompress a message using Huffman coding.
 *
 * Decompresses a message using Huffman coding by building the Huffman tree
 * from the frequency table, and decoding the message using the tree.
 *
 * @param[in]   compressed_message  The compressed message to decompress.
 * @param[in]   compressed_size The size of the compressed message in bytes.
 * @param[in]   frequency_table A pointer to the frequency table.
 * @param[in]   table_size  The number of entries in the frequency table.
 * @param[out]  message A pointer to the decompressed message.
 *
 * @return  The length of the decompressed message in bytes.
 */
int decompress_message(uint8_t *compressed_message, int compressed_size, uint32_t *frequency_table, int table_size, char **message)
{
    /* Build the Huffman tree from the frequency table. */
    node_t *root = build_tree(frequency_table, table_size);

    /* Decode the message using the Huffman tree. */
    int bits_read = 0;
    int message_size = 0;
    char *message_buffer = (char *)malloc(MAX_TREE_HT);
    node_t *node = root;

    while (bits_read < compressed_size * BITS_PER_BYTE) {
        if (node->left == NULL && node->right == NULL) {
            /* We have reached a leaf node, so the message character is complete. */
            message_buffer[message_size++] = node->character;
            node = root;
        } else {
            /* Read the next bit and traverse the tree accordingly. */
            uint8_t bit = (compressed_message[bits_read / BITS_PER_BYTE] >> (BITS_PER_BYTE - 1 - bits_read % BITS_PER_BYTE)) & 1;
            bits_read++;
            node = bit ? node->right : node->left;
        }
    }

    /* Free memory and return length of decompressed message. */
    free(root);
    *message = message_buffer;
    return message_size;
}

int main()
{
    char *message = "Hello, world!";
    int message_length = strlen(message);
    uint8_t *compressed_message;
    int compressed_size;

    compress_message(message, message_length, &compressed_message, &compressed_size);
    printf("Compressed message size: %d bytes\n", compressed_size);

    uint32_t frequency_table[256] = {0};
    for (int i = 0; i < message_length; i++) {
        frequency_table[(uint8_t)message[i]]++;
    }

    char *decompressed_message;
    int decompressed_size = decompress_message(compressed_message, compressed_size, frequency_table, 256, &decompressed_message);

    printf("Original message: %s\n", message);
    printf("Decompressed message: %s\n", decompressed_message);
    printf("Decompressed message size: %d bytes\n", decompressed_size);

    free(compressed_message);
    free(decompressed_message);

    return 0;
}