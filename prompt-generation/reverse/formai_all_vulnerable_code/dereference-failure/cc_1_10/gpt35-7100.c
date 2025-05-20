//FormAI DATASET v1.0 Category: Image Classification system ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Declare function prototypes
float** matrix_multiply(float** A, int A_row, int A_col, float** B, int B_row, int B_col);
float** convolution(float** image, int image_row, int image_col, float** filter, int filter_size);
int max_index(float* array, int size);

int main() {
    // Initialize image and filter
    float image[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float filter[2][2] = {{1, 0}, {0, 1}};

    // Convert image and filter to 2D array of pointers
    float **image_ptr = malloc(3 * sizeof(float*));
    for (int i = 0; i < 3; i++) {
        image_ptr[i] = malloc(3 * sizeof(float));
        for (int j = 0; j < 3; j++) {
            image_ptr[i][j] = image[i][j];
        }
    }
    float **filter_ptr = malloc(2 * sizeof(float*));
    for (int i = 0; i < 2; i++) {
        filter_ptr[i] = malloc(2 * sizeof(float));
        for (int j = 0; j < 2; j++) {
            filter_ptr[i][j] = filter[i][j];
        }
    }

    // Perform convolution and print result
    float **convolved_image = convolution(image_ptr, 3, 3, filter_ptr, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", convolved_image[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < 3; i++) {
        free(image_ptr[i]);
    }
    free(image_ptr);
    for (int i = 0; i < 2; i++) {
        free(filter_ptr[i]);
    }
    free(filter_ptr);
    for (int i = 0; i < 2; i++) {
        free(convolved_image[i]);
    }
    free(convolved_image);

    return 0;
}

// Matrix multiplication function
float** matrix_multiply(float** A, int A_row, int A_col, float** B, int B_row, int B_col) {
    if (A_col != B_row) {
        printf("Error: Matrices cannot be multiplied");
        return NULL;
    }

    float **C = malloc(A_row * sizeof(float*));

    for (int i = 0; i < A_row; i++) {
        C[i] = malloc(B_col * sizeof(float));
        for (int j = 0; j < B_col; j++) {
            C[i][j] = 0;
            for (int k = 0; k < A_col; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Convolution function
float** convolution(float** image, int image_row, int image_col, float** filter, int filter_size) {
    int output_row = image_row - filter_size + 1;
    int output_col = image_col - filter_size + 1;
    float **output = malloc(output_row * sizeof(float*));

    for (int i = 0; i < output_row; i++) {
        output[i] = malloc(output_col * sizeof(float));
        for (int j = 0; j < output_col; j++) {
            float **image_slice = malloc(filter_size * sizeof(float*));
            for (int k = 0; k < filter_size; k++) {
                image_slice[k] = malloc(filter_size * sizeof(float));
                for (int l = 0; l < filter_size; l++) {
                    image_slice[k][l] = image[i+k][j+l];
                }
            }
            float **convolved_slice = matrix_multiply(image_slice, filter_size, filter_size, filter, filter_size, filter_size);
            output[i][j] = convolved_slice[0][0];
            for (int k = 0; k < filter_size; k++) {
                free(image_slice[k]);
                free(convolved_slice[k]);
            }
            free(image_slice);
            free(convolved_slice);
        }
    }

    return output;
}

// Function to find the index of the maximum element in an array
int max_index(float* array, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > array[max]) {
            max = i;
        }
    }
    return max;
}