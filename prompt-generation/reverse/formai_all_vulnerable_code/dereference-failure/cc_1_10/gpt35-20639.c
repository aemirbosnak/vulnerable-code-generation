//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
/*
* This program demonstrates a unique method of image compression using
* a combination of run-length encoding and Huffman coding. The program
* takes an input image file (in BMP format with 24 bits per pixel) and
* compresses it to a specified output file at a variable compression
* level. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Define some constants */
#define HEADER_SIZE 54
#define MAX_COLOR 255
#define MAX_RUN_LENGTH 255
#define MAX_TREE_DEPTH 20

/* Define structs for image and Huffman tree */
typedef struct pixel {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

typedef struct pixel_node {
    pixel value;
    int count;
    struct pixel_node *left;
    struct pixel_node *right;
} pixel_node;

/* Define global variables for input and output files */
FILE *in_file;
FILE *out_file;

/* Define function prototypes */
pixel **read_image(char *filename, int *width, int *height);
void write_image(char *filename, pixel **image, int width, int height);
int *run_length_encode(pixel **image, int width, int height);
pixel_node *build_huffman_tree(int *counts);
void decode_tree(unsigned char *encoded, pixel_node **root, int *index, int max_depth);
void decode_image(unsigned char *encoded, pixel **image, int width, int height, pixel_node *root, int *index);

int main(int argc, char **argv) {
    /* Check command line arguments */
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <compression level>\n", argv[0]);
        exit(1);
    }

    /* Open input file */
    if ((in_file = fopen(argv[1], "rb")) == NULL) {
        printf("Couldn't open input file %s\n", argv[1]);
        exit(1);
    }

    /* Determine image dimensions */
    fseek(in_file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, in_file);
    fread(&height, sizeof(int), 1, in_file);

    /* Read image data */
    fseek(in_file, HEADER_SIZE, SEEK_SET);
    pixel **image = read_image(argv[1], &width, &height);

    /* Close input file */
    fclose(in_file);

    /* Compress image */
    int *counts = run_length_encode(image, width, height);
    pixel_node *root = build_huffman_tree(counts);

    unsigned char *encoded = malloc(width * height * 2 * sizeof(unsigned char));
    int index = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            /* Convert pixel value to 16-bit run length code */
            int run_length = image[row][col].red;
            run_length <<= 8;
            run_length |= image[row][col].blue;

            /* Encode run length using Huffman coding */
            pixel_node *node = root;
            int bit = 0;
            for (int depth = 0; depth < MAX_TREE_DEPTH && node->left != NULL && node->right != NULL; depth++) {
                bit = (run_length >> (MAX_TREE_DEPTH - depth - 1)) & 1;
                if (bit == 0) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            encoded[index++] = node->value.red;
            encoded[index++] = node->value.blue;
        }
    }

    /* Open output file */
    if ((out_file = fopen(argv[2], "wb")) == NULL) {
        printf("Couldn't open output file %s\n", argv[2]);
        exit(1);
    }

    /* Write image dimensions to output file */
    fwrite(&width, sizeof(int), 1, out_file);
    fwrite(&height, sizeof(int), 1, out_file);

    /* Write Huffman tree to output file */
    unsigned char *tree_output = malloc(width * height * 2 * sizeof(unsigned char));
    index = 0;
    int max_depth = ceil(log2(MAX_RUN_LENGTH));
    decode_tree(tree_output, &root, &index, max_depth);
    fwrite(&max_depth, sizeof(int), 1, out_file);
    fwrite(tree_output, sizeof(unsigned char), index, out_file);
    free(tree_output);

    /* Write encoded image data to output file */
    fwrite(encoded, sizeof(unsigned char), index, out_file);
    free(encoded);

    /* Close output file */
    fclose(out_file);

    /* Free memory */
    for (int row = 0; row < height; row++) {
        free(image[row]);
    }
    free(image);
    free(counts);
}

/* Reads in image data from a specified BMP file */
pixel **read_image(char *filename, int *width, int *height) {
    /* Open file */
    FILE *file;
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("Couldn't open file %s\n", filename);
        exit(1);
    }

    /* Determine image dimensions */
    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);

    /* Allocate memory for image data */
    pixel **image = malloc(*height * sizeof(pixel *));
    for (int i = 0; i < *height; i++) {
        image[i] = malloc(*width * sizeof(pixel));
    }

    /* Read image data */
    int padding = ((*width * 3) % 4) ? 4 - ((*width * 3) % 4) : 0;
    for (int row = 0; row < *height; row++) {
        for (int col = 0; col < *width; col++) {
            fread(&image[row][col].blue, sizeof(unsigned char), 1, file);
            fread(&image[row][col].green, sizeof(unsigned char), 1, file);
            fread(&image[row][col].red, sizeof(unsigned char), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }

    /* Close file */
    fclose(file);

    /* Return image data */
    return image;
}

/* Writes out image data to a specified BMP file */
void write_image(char *filename, pixel **image, int width, int height) {
    /* Open file */
    FILE *file;
    if ((file = fopen(filename, "wb")) == NULL) {
        printf("Couldn't open file %s\n", filename);
        exit(1);
    }

    /* Write header */
    unsigned char header[HEADER_SIZE] = {
        'B', 'M',                // signature
        0, 0, 0, 0,              // size (filled in later)
        0, 0,                   // reserved
        0, 0,                   // reserved
        HEADER_SIZE, 0, 0, 0,    // start of data
        40, 0, 0, 0,             // size of info header
        0, 0, 0, 0,              // width (filled in later)
        0, 0, 0, 0,              // height (filled in later)
        1, 0,                   // color planes
        24, 0,                  // bits per pixel
        0, 0, 0, 0,              // compression
        0, 0, 0, 0,              // image size (filled in later)
        0, 0, 0, 0,              // horizontal resolution
        0, 0, 0, 0,              // vertical resolution
        0, 0, 0, 0,              // colors in palette
        0, 0, 0, 0               // important colors
    };
    int data_size = ((3 * width) % 4) ? ((3 * width) / 4 + 1) * 4 * height : 3 * width * height;
    int file_size = data_size + HEADER_SIZE;
    header[2] = (unsigned char) (file_size);
    header[3] = (unsigned char) (file_size >> 8);
    header[4] = (unsigned char) (file_size >> 16);
    header[5] = (unsigned char) (file_size >> 24);
    header[18] = (unsigned char) (width);
    header[19] = (unsigned char) (width >> 8);
    header[20] = (unsigned char) (width >> 16);
    header[21] = (unsigned char) (width >> 24);
    header[22] = (unsigned char) (height);
    header[23] = (unsigned char) (height >> 8);
    header[24] = (unsigned char) (height >> 16);
    header[25] = (unsigned char) (height >> 24);
    header[34] = (unsigned char) (data_size);
    header[35] = (unsigned char) (data_size >> 8);
    header[36] = (unsigned char) (data_size >> 16);
    header[37] = (unsigned char) (data_size >> 24);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, file);

    /* Write image data */
    int padding = ((3 * width) % 4) ? 4 - ((3 * width) % 4) : 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            fwrite(&image[row][col].blue, sizeof(unsigned char), 1, file);
            fwrite(&image[row][col].green, sizeof(unsigned char), 1, file);
            fwrite(&image[row][col].red, sizeof(unsigned char), 1, file);
        }
        for (int i = 0; i < padding; i++) {
            fwrite("\0", sizeof(unsigned char), 1, file);
        }
    }

    /* Close file */
    fclose(file);
}

/* Performs run-length encoding on an image and returns counts of run lengths */
int *run_length_encode(pixel **image, int width, int height) {
    /* Allocate memory for counts */
    int *counts = calloc(MAX_RUN_LENGTH + 1, sizeof(int));

    /* Encode each row of the image */
    for (int row = 0; row < height; row++) {
        int length = 1;
        unsigned char blue = image[row][0].blue;
        unsigned char red = image[row][0].red;

        for (int col = 1; col < width; col++) {
            if (image[row][col].blue == blue && image[row][col].red == red && length < MAX_RUN_LENGTH) {
                length++;
            } else {
                counts[length]++;
                length = 1;
                blue = image[row][col].blue;
                red = image[row][col].red;
            }
        }

        /* Handle last run in row */
        counts[length]++;
    }

    return counts;
}

/* Builds a Huffman tree given an input array of run-length counts */
pixel_node *build_huffman_tree(int *counts) {
    /* Initialize nodes */
    pixel_node *nodes[MAX_RUN_LENGTH + 1];
    for (int i = 0; i <= MAX_RUN_LENGTH; i++) {
        nodes[i] = malloc(sizeof(pixel_node));
        nodes[i]->value.red = i >> 8;
        nodes[i]->value.blue = i & 0xFF;
        nodes[i]->count = counts[i];
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    /* Use bubble sort to sort nodes by count */
    for (int i = MAX_RUN_LENGTH; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nodes[j]->count < nodes[j+1]->count) {
                pixel_node *temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }

    /* Build the tree */
    int num_nodes = MAX_RUN_LENGTH + 1;
    while (num_nodes > 1) {
        pixel_node *new_node = malloc(sizeof(pixel_node));
        new_node->count = nodes[num_nodes-2]->count + nodes[num_nodes-1]->count;
        new_node->left = nodes[num_nodes-2];
        new_node->right = nodes[num_nodes-1];

        /* Insert new node into sorted array */
        int i = num_nodes - 2;
        while (i > 0 && new_node->count > nodes[i-1]->count) {
            nodes[i] = nodes[i-1];
            i--;
        }
        nodes[i] = new_node;
        num_nodes--;
    }

    /* Return root of tree */
    return nodes[0];
}

/* Decodes a Huffman tree from an input array of encoded tree data */
void decode_tree(unsigned char *encoded, pixel_node **root, int *index, int max_depth) {
    /* Check if current node is a leaf node */
    if (*index >= max_depth + 2) {
        return;
    }

    /* Read current node's value */
    unsigned char red = encoded[(*index)++];
    unsigned char blue = encoded[(*index)++];

    /* Check if current node is a leaf node */
    if (red == 0xFF && blue == 0xFF) {
        return;
    }

    /* Create new node */
    pixel_node *node = malloc(sizeof(pixel_node));
    node->value.red = red;
    node->value.blue = blue;
    node->left = NULL;
    node->right = NULL;

    /* Set parent's left or right child */
    if (*root == NULL) {
        *root = node;
    } else {
        if (node->value.red & (1 << (MAX_TREE_DEPTH - *index))) {
            (*root)->right = node;
            decode_tree(encoded, &(*root)->right, index, max_depth);
        } else {
            (*root)->left = node;
            decode_tree(encoded, &(*root)->left, index, max_depth);
        }
    }
}

/* Decodes an encoded image using a specified Huffman tree */
void decode_image(unsigned char *encoded, pixel **image, int width, int height, pixel_node *root, int *index) {
    /* Decode each row of the image */
    for (int row = 0; row < height; row++) {
        int col = 0;
        while (col < width) {
            /* Traverse Huffman tree to decode run length */
            pixel_node *node = root;
            while (node->left != NULL && node->right != NULL) {
                if (encoded[*index] & (1 << (7 - (*index % 8)))) {
                    node = node->right;
                } else {
                    node = node->left;
                }
                (*index)++;
            }

            /* Convert run length back to pixel value */
            int run_length = node->value.red;
            run_length <<= 8;
            run_length |= node->value.blue;
            for (int i = 0; i < run_length && col < width; i++) {
                image[row][col].blue = encoded[*index];
                (*index)++;
                image[row][col].green = 0;
                image[row][col].red = encoded[*index];
                (*index)++;
                col++;
            }
        }
    }
}