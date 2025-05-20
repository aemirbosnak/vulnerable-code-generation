//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_WIDTH 28
#define INPUT_HEIGHT 28

typedef struct {
    unsigned char data[INPUT_WIDTH * INPUT_HEIGHT];
    int label;
} Image;

typedef struct {
    double weights[INPUT_WIDTH * INPUT_HEIGHT][10];
    double biases[10];
} Model;

Image* load_image(char* filename) {
    Image* image = malloc(sizeof(Image));
    FILE* file = fopen(filename, "rb");
    fread(image->data, 1, INPUT_WIDTH * INPUT_HEIGHT, file);
    image->label = fgetc(file);
    fclose(file);
    return image;
}

Model* load_model(char* filename) {
    Model* model = malloc(sizeof(Model));
    FILE* file = fopen(filename, "rb");
    fread(model->weights, sizeof(double), INPUT_WIDTH * INPUT_HEIGHT * 10, file);
    fread(model->biases, sizeof(double), 10, file);
    fclose(file);
    return model;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double* forward_propagate(Image* image, Model* model) {
    double* outputs = malloc(sizeof(double) * 10);
    for (int i = 0; i < 10; i++) {
        double sum = 0;
        for (int j = 0; j < INPUT_WIDTH * INPUT_HEIGHT; j++) {
            sum += image->data[j] * model->weights[j][i];
        }
        outputs[i] = sigmoid(sum + model->biases[i]);
    }
    return outputs;
}

int predict(Image* image, Model* model) {
    double* outputs = forward_propagate(image, model);
    int max_index = 0;
    double max_value = outputs[0];
    for (int i = 1; i < 10; i++) {
        if (outputs[i] > max_value) {
            max_index = i;
            max_value = outputs[i];
        }
    }
    free(outputs);
    return max_index;
}

int main() {
    Image* image = load_image("image.bin");
    Model* model = load_model("model.bin");
    int prediction = predict(image, model);
    printf("Prediction: %d\n", prediction);
    free(image);
    free(model);
    return 0;
}