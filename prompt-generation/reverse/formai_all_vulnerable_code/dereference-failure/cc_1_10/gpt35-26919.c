//FormAI DATASET v1.0 Category: Image compression ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// CONSTANTS
#define MAX_THREADS 10
#define BLOCK_SIZE 8

// STRUCTURES
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

typedef struct {
    Image *input;
    Image *output;
    int start_row;
    int n_rows;
} BlockData;

// FUNCTION DECLARATIONS
Image* read_image(char *filename);
int write_image(char *filename, Image *image);
void* compress_block(void *arg);

// GLOBAL VARIABLES
int num_threads = 1;

int main(int argc, char **argv) {
    // check command-line arguments
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file> [num_threads]\n", argv[0]);
        return 0;
    }
    if (argc >= 4) {
        num_threads = atoi(argv[3]);
        if (num_threads < 1) {
            printf("Invalid number of threads\n");
            return 0;
        }
        if (num_threads > MAX_THREADS) {
            printf("Maximum number of threads is %d\n", MAX_THREADS);
            num_threads = MAX_THREADS;
        }
    }
    // read input image
    Image *input = read_image(argv[1]);
    if (!input) {
        printf("Error reading input image\n");
        return 0;
    }
    // create output image
    Image *output = malloc(sizeof(Image));
    output->width = input->width;
    output->height = input->height;
    output->data = malloc(output->width * output->height);
    // create block data structures
    BlockData block[num_threads];
    int rows_per_thread = output->height / num_threads;
    int rows_remainder = output->height % num_threads;
    int cur_row = 0;
    for (int i = 0; i < num_threads; i++) {
        block[i].input = input;
        block[i].output = output;
        block[i].start_row = cur_row;
        block[i].n_rows = rows_per_thread + (i < rows_remainder ? 1 : 0);
        cur_row += block[i].n_rows;
    }
    // launch threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, compress_block, &block[i]);
    }
    // wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    // write output image
    if (!write_image(argv[2], output)) {
        printf("Error writing output image\n");
    }
    // free images
    free(input->data);
    free(input);
    free(output->data);
    free(output);
    return 0;
}

Image* read_image(char *filename) {
    // open file
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening input file\n");
        return NULL;
    }
    // read image header
    char magic[3];
    if (fread(magic, 1, 2, fp) != 2 || strcmp(magic, "P5")) {
        printf("Invalid input file format\n");
        fclose(fp);
        return NULL;
    }
    char c;
    do {
        c = getc(fp);
    } while (c != '\n');
    do {
        c = getc(fp);
    } while (c == '#');
    ungetc(c, fp);
    int width, height, maxval;
    if (fscanf(fp, "%d %d %d", &width, &height, &maxval) != 3 || maxval != 255) {
        printf("Invalid input file format\n");
        fclose(fp);
        return NULL;
    }
    // allocate image data
    unsigned char *data = malloc(width * height);
    if (!data) {
        printf("Error allocating memory\n");
        fclose(fp);
        return NULL;
    }
    // read image data
    if (fread(data, 1, width * height, fp) != width * height) {
        printf("Error reading input file\n");
        free(data);
        fclose(fp);
        return NULL;
    }
    // close file and return image
    fclose(fp);
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;
    return image;
}

int write_image(char *filename, Image *image) {
    // open file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error opening output file\n");
        return 0;
    }
    // write image header
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
    // write image data
    if (fwrite(image->data, 1, image->width * image->height, fp) != image->width * image->height) {
        printf("Error writing output file\n");
        fclose(fp);
        return 0;
    }
    // close file and return success
    fclose(fp);
    return 1;
}

void* compress_block(void *arg) {
    // cast argument to BlockData pointer
    BlockData *data = (BlockData*) arg;
    // process block
    for (int j = data->start_row; j < data->start_row + data->n_rows; j += BLOCK_SIZE) {
        for (int i = 0; i < data->input->width; i += BLOCK_SIZE) {
            // calculate sum of pixel values in block
            int sum = 0;
            for (int y = j; y < j + BLOCK_SIZE && y < data->input->height; y++) {
                for (int x = i; x < i + BLOCK_SIZE && x < data->input->width; x++) {
                    sum += data->input->data[y * data->input->width + x];
                }
            }
            // calculate average pixel value for block
            int avg = sum / (BLOCK_SIZE * BLOCK_SIZE);
            // set output pixels to average value
            for (int y = j; y < j + BLOCK_SIZE && y < data->output->height; y++) {
                for (int x = i; x < i + BLOCK_SIZE && x < data->output->width; x++) {
                    data->output->data[y * data->output->width + x] = avg;
                }
            }
        }
    }
    // return success
    return NULL;
}