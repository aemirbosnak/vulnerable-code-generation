//FormAI DATASET v1.0 Category: Image Classification system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_image_data(int num_images, int image_size, char** file_names, double** data) {
    for (int i = 0; i < num_images; i++) {
        FILE* f = fopen(file_names[i], "r");
        if (!f) {
            printf("Error: cannot open file %s\n", file_names[i]);
            exit(1);
        }
        char line[1000];
        int row = 0;
        while (fgets(line, 1000, f)) {
            if (row < image_size) {
                char *token = strtok(line, ",");
                int col = 0;
                while (token != NULL) {
                    data[i][row*image_size + col] = atof(token);
                    token = strtok(NULL, ",");
                    col++;
                }
                row++;
            } else {
                break;
            }
        }
        fclose(f);
    }
}

double dot_product(double* a, double* b, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void softmax(double* a, int size) {
    double denominator = 0;
    double max = a[0];
    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int i = 0; i < size; i++) {
        denominator += exp(a[i] - max);
    }
    for (int i = 0; i < size; i++) {
        a[i] = exp(a[i] - max) / denominator;
    }
}

void predict(int num_images, int image_size, double** test_data, int num_classes, double** weights, int* predictions) {
    for (int i = 0; i < num_images; i++) {
        double scores[num_classes];
        for (int j = 0; j < num_classes; j++) {
            double* weight = weights[j];
            scores[j] = dot_product(weight, test_data[i], image_size);
        }
        softmax(scores, num_classes);
        int max_index = 0;
        double max_score = scores[0];
        for (int j = 1; j < num_classes; j++) {
            if (scores[j] > max_score) {
                max_index = j;
                max_score = scores[j];
            }
        }
        predictions[i] = max_index;
    }
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s num_classes num_train_images num_test_images image_size\n", argv[0]);
        return 1;
    }
    int num_classes = atoi(argv[1]);
    int num_train_images = atoi(argv[2]);
    int num_test_images = atoi(argv[3]);
    int image_size = atoi(argv[4]);
    double** train_data = malloc(num_train_images*sizeof(double*));
    for (int i = 0; i < num_train_images; i++) {
        train_data[i] = malloc(image_size*image_size*sizeof(double));
    }
    double** test_data = malloc(num_test_images*sizeof(double*));
    for (int i = 0; i < num_test_images; i++) {
        test_data[i] = malloc(image_size*image_size*sizeof(double));
    }
    char** train_file_names = malloc(num_train_images*sizeof(char*));
    char** test_file_names = malloc(num_test_images*sizeof(char*));
    for (int i = 0; i < num_train_images; i++) {
        train_file_names[i] = malloc(100*sizeof(char));
        sprintf(train_file_names[i], "train_%d.txt", i);
    }
    for (int i = 0; i < num_test_images; i++) {
        test_file_names[i] = malloc(100*sizeof(char));
        sprintf(test_file_names[i], "test_%d.txt", i);
    }
    int* train_labels = malloc(num_train_images*sizeof(int));
    int* test_labels = malloc(num_test_images*sizeof(int));
    double** weights = malloc(num_classes*sizeof(double*));
    for (int i = 0; i < num_classes; i++) {
        weights[i] = malloc(image_size*image_size*sizeof(double));
    }
    int* train_predictions = malloc(num_train_images*sizeof(int));
    int* test_predictions = malloc(num_test_images*sizeof(int));
    load_image_data(num_train_images, image_size, train_file_names, train_data);
    load_image_data(num_test_images, image_size, test_file_names, test_data);
    for (int i = 0; i < num_train_images; i++) {
        train_labels[i] = i % num_classes;
    }
    for (int i = 0; i < num_classes; i++) {
        for (int j = 0; j < image_size*image_size; j++) {
            weights[i][j] = ((double)rand())/RAND_MAX;
        }
    }
    for (int epoch = 0; epoch < 10; epoch++) {
        for (int i = 0; i < num_train_images; i++) {
            double scores[num_classes];
            for (int j = 0; j < num_classes; j++) {
                double* weight = weights[j];
                scores[j] = dot_product(weight, train_data[i], image_size);
            }
            softmax(scores, num_classes);
            int predicted_label = train_labels[i];
            int actual_label = predicted_label;
            double max_score = scores[predicted_label];
            for (int j = 0; j < num_classes; j++) {
                if (scores[j] > max_score) {
                    predicted_label = j;
                    max_score = scores[j];
                }
                if (train_labels[i] == j) {
                    actual_label = j;
                }
            }
            train_predictions[i] = predicted_label;
            int correct = (predicted_label == actual_label);
            for (int j = 0; j < num_classes; j++) {
                double* weight = weights[j];
                double* data = train_data[i];
                double gradient = 0;
                if (j == actual_label) {
                    gradient = (correct ? 1.0 : 0.0) - 1.0*scores[j];
                } else {
                    gradient = 1.0*scores[j];
                }
                for (int k = 0; k < image_size*image_size; k++) {
                    weight[k] += 0.001*gradient*data[k];
                }
            }
        }
    }
    predict(num_test_images, image_size, test_data, num_classes, weights, test_predictions);
    double test_accuracy = 0;
    for (int i = 0; i < num_test_images; i++) {
        if (test_predictions[i] == i % num_classes) {
            test_accuracy += 1.0;
        }
    }
    test_accuracy /= num_test_images;
    printf("Test accuracy: %.3f\n", test_accuracy);
    return 0;
}