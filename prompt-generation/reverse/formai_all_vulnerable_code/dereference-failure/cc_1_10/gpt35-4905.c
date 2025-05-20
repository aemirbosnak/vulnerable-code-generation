//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define IMG_SIZE 28
#define IMG_PIXELS IMG_SIZE * IMG_SIZE

typedef struct {
    float pixels[IMG_PIXELS];
    int label;
} Image;

typedef struct {
    Image *images;
    int num_images;
} Dataset;

typedef struct {
    float *weights;
    float bias;
} LinearLayer;

typedef struct {
    float *activations;
    LinearLayer *linear_layer;
} DenseLayer;

Dataset load_dataset(char *image_file, char *label_file) {
    FILE *fp1, *fp2;
    Dataset dataset;
    fp1 = fopen(image_file, "rb");
    fp2 = fopen(label_file, "rb");
    int n_images, n_labels;
    fread(&n_images, sizeof(int), 1, fp1);
    fread(&n_labels, sizeof(int), 1, fp2);
    fgetc(fp2);
    dataset.images = malloc(n_images * sizeof(Image));
    dataset.num_images = n_images;
    for (int i = 0; i < n_images; i++) {
        fread(dataset.images[i].pixels, sizeof(float), IMG_PIXELS, fp1);
        dataset.images[i].label = fgetc(fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return dataset;
}

float *softmax(float *inputs, int size) {
    float *outputs = malloc(size * sizeof(float));
    float sum = 0;
    for (int i = 0; i < size; i++) {
        outputs[i] = exp(inputs[i]);
        sum += outputs[i];
    }
    for (int i = 0; i < size; i++) {
        outputs[i] /= sum;
    }
    return outputs;
}

void init_dense_layer(DenseLayer *layer, int input_size, int output_size) {
    layer->activations = malloc(output_size * sizeof(float));
    layer->linear_layer = malloc(sizeof(LinearLayer));
    layer->linear_layer->weights = malloc(input_size * output_size * sizeof(float));
    layer->linear_layer->bias = 0;
    for (int i = 0; i < input_size * output_size; i++) {
        layer->linear_layer->weights[i] = (float) rand() / RAND_MAX;
    }
}

void forward_dense_layer(DenseLayer *layer, float *inputs, int input_size, int output_size) {
    for (int i = 0; i < output_size; i++) {
        float sum = 0;
        for (int j = 0; j < input_size; j++) {
            sum += inputs[j] * layer->linear_layer->weights[j * output_size + i];
        }
        layer->activations[i] = sum + layer->linear_layer->bias;
    }
    layer->activations = softmax(layer->activations, output_size);
}

int predict(DenseLayer **layers, int num_layers, float *inputs, int input_size, int output_size) {
    DenseLayer *prev_layer = NULL;
    for (int i = 0; i < num_layers; i++) {
        if (prev_layer == NULL) {
            forward_dense_layer(layers[i], inputs, input_size, output_size);
        } else {
            forward_dense_layer(layers[i], prev_layer->activations, prev_layer->linear_layer->bias, output_size);
        }
        prev_layer = layers[i];
    }
    float max_activation = 0;
    int max_index = 0;
    for (int i = 0; i < output_size; i++) {
        if (prev_layer->activations[i] > max_activation) {
            max_activation = prev_layer->activations[i];
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    Dataset train_set = load_dataset("train-images.idx3-ubyte", "train-labels.idx1-ubyte");
    DenseLayer *layers[3];
    init_dense_layer(layers[0], IMG_PIXELS, 256);
    init_dense_layer(layers[1], 256, 128);
    init_dense_layer(layers[2], 128, 10);
    for (int i = 0; i < train_set.num_images; i++) {
        int label = train_set.images[i].label;
        float *pixels = train_set.images[i].pixels;
        int prediction = predict(layers, 3, pixels, IMG_PIXELS, 10);
        // Backpropagation code would go here
    }
    return 0;
}