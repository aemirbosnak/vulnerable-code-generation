//FormAI DATASET v1.0 Category: Image Classification system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_BUFFER 1024
#define K 5 // K value for KNN algorithm

// Data structure to hold image data
typedef struct {
    double *pixels;
    int label;
} image;

// Function to load image data from file
image *read_data(char *filename, int num_images) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // allocate memory for image data
    image *data = malloc(num_images * sizeof(image));
    if (!data) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // read image data from file
    char line[MAX_BUFFER];
    int pixel_count = 784; // 28 x 28 pixels
    for (int i = 0; i < num_images; i++) {
        fgets(line, MAX_BUFFER, fp);
        data[i].pixels = malloc(pixel_count * sizeof(double));
        if (!data[i].pixels) {
            printf("Error allocating memory\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        for (int j = 0; j < pixel_count; j++) {
            data[i].pixels[j] = atof(token);
            token = strtok(NULL, ",");
        }
        data[i].label = atoi(token);
    }

    fclose(fp);
    return data;
}

// Function to compute Euclidean distance between two images
double distance(image a, image b) {
    double sum = 0.0;
    int pixel_count = 784; // 28 x 28 pixels
    for (int i = 0; i < pixel_count; i++) {
        sum += pow(a.pixels[i] - b.pixels[i], 2);
    }
    return sqrt(sum);
}

// Function to perform KNN classification
int classify(image *data, image test_image, int num_images) {
    struct {
        image img;
        double dist;
    } nearest[K] = {0};

    // find the K nearest images to the test image
    for (int i = 0; i < num_images; i++) {
        double d = distance(data[i], test_image);
        for (int j = 0; j < K; j++) {
            if (nearest[j].dist == 0 || d < nearest[j].dist) {
                memmove(&nearest[j + 1], &nearest[j], (K - j - 1) * sizeof(*nearest));
                nearest[j].img = data[i];
                nearest[j].dist = d;
                break;
            }
        }
    }

    // count the number of images for each label
    int label_count[10] = {0};
    for (int i = 0; i < K; i++) {
        label_count[nearest[i].img.label]++;
    }

    // find the label with the highest count
    int max_count = 0, max_label = 0;
    for (int i = 0; i < 10; i++) {
        if (label_count[i] > max_count) {
            max_count = label_count[i];
            max_label = i;
        }
    }

    return max_label;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <image_data_file> <test_data_file>\n", argv[0]);
        exit(1);
    }

    // load image data from file
    image *data = read_data(argv[1], 60000);
    int num_images = 60000;

    // load test data from file
    image *test_data = read_data(argv[2], 10000);
    int num_test_images = 10000;

    // classify test images using KNN algorithm
    int correct_predictions = 0;
    for (int i = 0; i < num_test_images; i++) {
        int predicted_label = classify(data, test_data[i], num_images);
        if (predicted_label == test_data[i].label) {
            correct_predictions++;
        }
    }

    printf("Accuracy: %.2f%%\n", (double) correct_predictions / num_test_images * 100);

    // free memory
    for (int i = 0; i < num_images; i++) {
        free(data[i].pixels);
    }
    free(data);
    for (int i = 0; i < num_test_images; i++) {
        free(test_data[i].pixels);
    }
    free(test_data);

    return 0;
}