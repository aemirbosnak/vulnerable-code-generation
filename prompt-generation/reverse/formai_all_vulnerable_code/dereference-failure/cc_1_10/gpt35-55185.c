//FormAI DATASET v1.0 Category: Image Classification system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 784

typedef struct {
    int label;
    float *pixels;
} image_t;

typedef struct {
    float **weights;
    int num_input;
    int num_output;
} neural_layer_t;

typedef struct {
    neural_layer_t input_layer;
    neural_layer_t hidden_layer;
    neural_layer_t output_layer;
} neural_network_t;

float **create_weights(int num_input, int num_output) {
    float **weights = (float **) malloc(num_output * sizeof(float *));
    for (int i = 0; i < num_output; i++) {
        weights[i] = (float *) malloc(num_input * sizeof(float));
        for (int j = 0; j < num_input; j++) {
            weights[i][j] = (float) rand() / RAND_MAX;
        }
    }
    return weights;
}

void destroy_weights(float **weights, int num_output) {
    for (int i = 0; i < num_output; i++) {
        free(weights[i]);
    }
    free(weights);
}

image_t *read_image(FILE *fp) {
    image_t *image = (image_t *) malloc(sizeof(image_t));
    image->pixels = (float *) malloc(IMAGE_SIZE * sizeof(float));
    fread(&image->label, sizeof(int), 1, fp);
    fread(image->pixels, sizeof(float), IMAGE_SIZE, fp);
    return image;
}

void destroy_image(image_t *image) {
    free(image->pixels);
    free(image);
}

int classify_image(neural_network_t *nn, image_t *image) {
    // Input layer
    float *input = (float *) malloc(nn->input_layer.num_input * sizeof(float));
    for (int i = 0; i < nn->input_layer.num_input; i++) {
        input[i] = image->pixels[i];
    }

    // Hidden layer
    float *hidden = (float *) malloc(nn->hidden_layer.num_output * sizeof(float));
    for (int i = 0; i < nn->hidden_layer.num_output; i++) {
        float sum = 0.0;
        for (int j = 0; j < nn->hidden_layer.num_input; j++) {
            sum += input[j] * nn->hidden_layer.weights[i][j];
        }
        hidden[i] = 1.0 / (1.0 + exp(-sum));
    }

    // Output layer
    float *output = (float *) malloc(nn->output_layer.num_output * sizeof(float));
    for (int i = 0; i < nn->output_layer.num_output; i++) {
        float sum = 0.0;
        for (int j = 0; j < nn->output_layer.num_input; j++) {
            sum += hidden[j] * nn->output_layer.weights[i][j];
        }
        output[i] = 1.0 / (1.0 + exp(-sum));
    }

    int max_index = 0;
    for (int i = 1; i < nn->output_layer.num_output; i++) {
        if (output[i] > output[max_index]) {
            max_index = i;
        }
    }

    free(input);
    free(hidden);
    free(output);

    return max_index;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    neural_network_t nn = {
            {create_weights(IMAGE_SIZE, NUM_CLASSES), IMAGE_SIZE, NUM_CLASSES},
            {create_weights(NUM_CLASSES, NUM_CLASSES), NUM_CLASSES, NUM_CLASSES},
            {create_weights(NUM_CLASSES, NUM_CLASSES), NUM_CLASSES, NUM_CLASSES}
    };

    FILE *fp_in = fopen(argv[1], "rb");
    FILE *fp_out = fopen(argv[2], "w");

    if (fp_in == NULL) {
        printf("Error opening input file '%s'\n", argv[1]);
        return 1;
    }

    if (fp_out == NULL) {
        printf("Error opening output file '%s'\n", argv[2]);
        fclose(fp_in);
        return 1;
    }

    int num_images;
    fread(&num_images, sizeof(int), 1, fp_in);

    for (int i = 0; i < num_images; i++) {
        image_t *image = read_image(fp_in);
        int label = classify_image(&nn, image);
        fprintf(fp_out, "%d\n", label);
        destroy_image(image);
    }

    fclose(fp_out);
    fclose(fp_in);

    destroy_weights(nn.input_layer.weights, nn.input_layer.num_output);
    destroy_weights(nn.hidden_layer.weights, nn.hidden_layer.num_output);
    destroy_weights(nn.output_layer.weights, nn.output_layer.num_output);

    printf("Program complete. Output written to '%s'\n", argv[2]);

    return 0;
}