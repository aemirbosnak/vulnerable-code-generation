//FormAI DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to read in the image and return as a 2D array */
int **read_image(int rows, int cols, FILE *image_file) {
    int **image = (int **)malloc(rows * sizeof(int *));
    for (int i=0; i<rows; i++) {
        image[i] = (int *)malloc(cols * sizeof(int));
        for (int j=0; j<cols; j++) {
            fscanf(image_file, "%d", &image[i][j]);
        }
    }
    return image;
}

/* Function to calculate the mean of an array */
float get_mean(int *array, int size) {
    float sum = 0.0;
    for (int i=0; i<size; i++) {
        sum += array[i];
    }
    return sum / size;
}

/* Function to calculate the standard deviation of an array */
float get_std_dev(int *array, int size, float mean) {
    float sum = 0.0;
    for (int i=0; i<size; i++) {
        sum += pow((array[i] - mean), 2);
    }
    return sqrt(sum / size);
}

/* Function to classify the image */
int classify_image(int rows, int cols, int **image) {
    float means[2] = {0.0, 0.0};
    float std_devs[2] = {0.0, 0.0};

    /* Calculate the means and standard deviations of each row */
    for (int i=0; i<rows; i++) {
        float current_mean = get_mean(image[i], cols);
        float current_std_dev = get_std_dev(image[i], cols, current_mean);
        if (i < (rows / 2)) {
            means[0] += current_mean;
            std_devs[0] += current_std_dev;
        } else {
            means[1] += current_mean;
            std_devs[1] += current_std_dev;
        }
    }

    /* Calculate the final means and standard deviations */
    means[0] /= (rows / 2);
    means[1] /= (rows / 2);
    std_devs[0] /= (rows / 2);
    std_devs[1] /= (rows / 2);

    /* If the first half of the image has a higher mean and lower standard deviation,
       classify it as class 1, otherwise classify it as class 2 */
    if (means[0] > means[1] && std_devs[0] < std_devs[1]) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    FILE *image_file = fopen("image.txt", "r");
    int rows = 10;
    int cols = 10;

    int **image = read_image(rows, cols, image_file);

    int classification = classify_image(rows, cols, image);

    printf("Classification: %d", classification);

    fclose(image_file);

    return 0;
}