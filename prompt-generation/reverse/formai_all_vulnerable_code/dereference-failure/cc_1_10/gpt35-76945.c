//FormAI DATASET v1.0 Category: Image Classification system ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define NUM_CLASSES 10
#define IMG_SIZE 784

typedef struct {
    int label;
    double* pixels;
} Image;

typedef struct {
    double** matrix;
    int rows;
    int cols;
} Matrix;

typedef struct {
    Matrix* weights;
    Matrix* biases;
} Layer;

// Function to create and return a new Matrix with given number of rows and columns
Matrix* createMatrix(int rows, int cols) {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (double**) malloc(rows * sizeof(double*));
    for(int i = 0; i < rows; i++) {
        matrix->matrix[i] = (double*) malloc(cols * sizeof(double));
        for(int j = 0; j < cols; j++) {
            matrix->matrix[i][j] = 0;
        }
    }
    return matrix;
}

// Function to create and return a new Layer with given number of inputs and outputs
Layer* createLayer(int num_inputs, int num_outputs) {
    Layer* layer = (Layer*) malloc(sizeof(Layer));
    layer->weights = createMatrix(num_outputs, num_inputs);
    layer->biases = createMatrix(num_outputs, 1);
    return layer;
}

// Function to free memory allocated to matrices
void freeMatrix(Matrix* matrix) {
    for(int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// Function to free memory allocated to layers
void freeLayer(Layer* layer) {
    freeMatrix(layer->weights);
    freeMatrix(layer->biases);
    free(layer);
}

// Function to perform matrix multiplication of two matrices and return result
Matrix* matmul(Matrix* A, Matrix* B) {
    if(A->cols != B->rows) {
        printf("Error: Cannot multiply matrices with incompatible sizes.\n");
        return NULL;
    }
    Matrix* C = createMatrix(A->rows, B->cols);
    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < B->cols; j++) {
            for(int k = 0; k < A->cols; k++) {
                C->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
    }
    return C;
}

// Function to perform element-wise multiplication of two matrices and return result
Matrix* elemmul(Matrix* A, Matrix* B) {
    if(A->rows != B->rows || A->cols != B->cols) {
        printf("Error: Cannot perform element-wise multiplication on matrices with incompatible sizes.\n");
        return NULL;
    }
    Matrix* C = createMatrix(A->rows, A->cols);
    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < A->cols; j++) {
            C->matrix[i][j] = A->matrix[i][j] * B->matrix[i][j];
        }
    }
    return C;
}

// Function to perform element-wise addition of two matrices and return result
Matrix* elemadd(Matrix* A, Matrix* B) {
    if(A->rows != B->rows || A->cols != B->cols) {
        printf("Error: Cannot perform element-wise addition on matrices with incompatible sizes.\n");
        return NULL;
    }
    Matrix* C = createMatrix(A->rows, A->cols);
    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < A->cols; j++) {
            C->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }
    return C;
}

// Function to perform element-wise ReLU activation on a matrix and return result
Matrix* relu(Matrix* A) {
    Matrix* B = createMatrix(A->rows, A->cols);
    for(int i = 0; i < A->rows; i++) {
        for(int j = 0; j < A->cols; j++) {
            B->matrix[i][j] = (A->matrix[i][j] > 0) ? A->matrix[i][j] : 0;
        }
    }
    return B;
}

// Function to perform element-wise Softmax activation on a matrix and return result
Matrix* softmax(Matrix* A) {
    Matrix* B = createMatrix(A->rows, A->cols);
    double max_val;
    for(int i = 0; i < A->rows; i++) {
        max_val = A->matrix[i][0];
        for(int j = 1; j < A->cols; j++) {
            if(A->matrix[i][j] > max_val) {
                max_val = A->matrix[i][j];
            }
        }
        double sum_exp = 0;
        for(int j = 0; j < A->cols; j++) {
            sum_exp += exp(A->matrix[i][j] - max_val);
        }
        for(int j = 0; j < A->cols; j++) {
            B->matrix[i][j] = exp(A->matrix[i][j] - max_val) / sum_exp;
        }
    }
    return B;
}

// Function to load MNIST dataset images and labels from files and return an array of Image structs
Image* loadImages(const char* images_file, const char* labels_file, int num_images) {
    Image* images = (Image*) malloc(num_images * sizeof(Image));
    FILE* file_images = fopen(images_file, "r");
    FILE* file_labels = fopen(labels_file, "r");
    if(file_images == NULL || file_labels == NULL) {
        printf("Error: Could not open dataset files.\n");
        return NULL;
    }
    // Skip the header information in the images file
    int num_ignore;
    fread(&num_ignore, 4, 1, file_images);
    fread(&num_ignore, 4, 1, file_images);
    fread(&num_ignore, 4, 1, file_images);
    fread(&num_ignore, 4, 1, file_images);
    // Skip the header information in the labels file
    fread(&num_ignore, 4, 1, file_labels);
    fread(&num_ignore, 4, 1, file_labels);
    for(int i = 0; i < num_images; i++) {
        images[i].pixels = (double*) malloc(IMG_SIZE * sizeof(double));
        fread(images[i].pixels, 1, IMG_SIZE, file_images);
        unsigned char label;
        fread(&label, 1, 1, file_labels);
        images[i].label = (int) label;
    }
    fclose(file_images);
    fclose(file_labels);
    return images;
}

// Function to perform forward pass on given input through given layer and return output
Matrix* forwardLayer(Matrix* input, Layer* layer) {
    Matrix* A = matmul(layer->weights, input);
    Matrix* Z = elemadd(A, layer->biases);
    Matrix* output = relu(Z);
    freeMatrix(A);
    freeMatrix(Z);
    return output;
}

// Function to perform forward pass on given input through given network and return output
Matrix* forwardNetwork(Matrix* input, Layer** network, int num_layers) {
    Matrix* output = input;
    for(int i = 0; i < num_layers; i++) {
        output = forwardLayer(output, network[i]);
        if(output == NULL) {
            return NULL;
        }
    }
    return softmax(output);
}

// Function to predict class label of input using given network
int predict(Matrix* input, Layer** network, int num_layers) {
    Matrix* output = forwardNetwork(input, network, num_layers);
    int class_label = -1;
    double max_prob = -1;
    for(int i = 0; i < NUM_CLASSES; i++) {
        if(output->matrix[0][i] > max_prob) {
            max_prob = output->matrix[0][i];
            class_label = i;
        }
    }
    freeMatrix(output);
    return class_label;
}

int main() {
    // Load test images and labels
    Image* test_images = loadImages("test_images.bin", "test_labels.bin", 10000);
    if(test_images == NULL) {
        return -1;
    }

    // Initialize network architecture
    const int num_layers = 3;
    const int num_hidden = 128;
    Layer** network = (Layer**) malloc(num_layers * sizeof(Layer*));
    network[0] = createLayer(IMG_SIZE, num_hidden);
    network[1] = createLayer(num_hidden, num_hidden);
    network[2] = createLayer(num_hidden, NUM_CLASSES);

    // Load trained weights into network
    FILE* file_weights = fopen("weights.txt", "r");
    if(file_weights == NULL) {
        printf("Error: Could not open weights file.\n");
        return -1;
    }
    for(int i = 0; i < num_layers; i++) {
        for(int j = 0; j < network[i]->weights->rows; j++) {
            for(int k = 0; k < network[i]->weights->cols; k++) {
                fscanf(file_weights, "%lf", &network[i]->weights->matrix[j][k]);
            }
        }
        for(int j = 0; j < network[i]->biases->rows; j++) {
            fscanf(file_weights, "%lf", &network[i]->biases->matrix[j][0]);
        }
    }
    fclose(file_weights);

    // Test the network on the loaded images
    int num_correct = 0;
    for(int i = 0; i < 10000; i++) {
        Matrix* input = createMatrix(1, IMG_SIZE);
        for(int j = 0; j < IMG_SIZE; j++) {
            input->matrix[0][j] = test_images[i].pixels[j];
        }
        int predicted_label = predict(input, network, num_layers);
        if(predicted_label == test_images[i].label) {
            num_correct++;
        }
        freeMatrix(input);
    }
    printf("Accuracy: %.2f%%\n", (double) num_correct / 10000 * 100);

    // Clean up memory
    for(int i = 0; i < num_layers; i++) {
        freeLayer(network[i]);
    }
    free(network);
    for(int i = 0; i < 10000; i++) {
        free(test_images[i].pixels);
    }
    free(test_images);

    return 0;
}