//FormAI DATASET v1.0 Category: Image Classification system ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Struct for image info
typedef struct {
    int width;
    int height;
    int channels;
    float *data;
} Image;

// Function to load image data from file
Image* loadImage(char *filename) {
    Image *img = malloc(sizeof(Image));
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error opening file\n");
        return NULL;
    }
    fscanf(f, "%d %d %d", &img->width, &img->height, &img->channels);
    int size = img->width * img->height * img->channels;
    img->data = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        fscanf(f, "%f", &img->data[i]);
    }
    fclose(f);
    return img;
}

// Function to predict class of image based on model
int predictClass(Image *img, float *model, int numClasses) {
    float *output = malloc(numClasses * sizeof(float));
    int size = img->width * img->height * img->channels;
    for (int i = 0; i < numClasses; i++) {
        output[i] = 0.0;
        for (int j = 0; j < size; j++) {
            output[i] += model[i * size + j] * img->data[j];
        }
    }
    int maxIndex = 0;
    for (int i = 1; i < numClasses; i++) {
        if (output[i] > output[maxIndex]) {
            maxIndex = i;
        }
    }
    free(output);
    return maxIndex;
}

int main() {
    // Load model from file
    float *model;
    int numClasses, modelSize;
    FILE *f = fopen("model.dat", "rb");
    if (!f) {
        printf("Error opening model file\n");
        return 1;
    }
    fread(&numClasses, sizeof(int), 1, f);
    fread(&modelSize, sizeof(int), 1, f);
    model = malloc(modelSize * sizeof(float));
    fread(model, sizeof(float), modelSize, f);
    fclose(f);

    // Load image from file
    Image *img = loadImage("test_image.txt");
    if (!img) {
        return 1;
    }

    // Predict class of image
    int prediction = predictClass(img, model, numClasses);

    // Print result
    printf("Predicted class: %d\n", prediction);

    free(model);
    free(img->data);
    free(img);
    return 0;
}