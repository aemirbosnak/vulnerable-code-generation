//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_CLASSES 5

struct Image {
    int width;
    int height;
    char* data;
    int label;
};

struct Classifier {
    int num_of_features;
    double* weights;
};

typedef struct Image Image;
typedef struct Classifier Classifier;

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

int img_to_feature_vector(Image* img, double* feature_vector) {
    if(img->width != 28 || img->height != 28) {
        return 0;
    }
    for(int i=0; i<img->width * img->height; i++) {
        feature_vector[i] = (unsigned char)img->data[i] / 255.0;
    }
    return 1;
}

int classify_image(Image* img, Classifier* classifier) {
    double feature_vector[img->width * img->height];

    if(!img_to_feature_vector(img, feature_vector)) {
        return -1;
    }

    double score[NUM_OF_CLASSES] = {0};

    for(int i=0; i<NUM_OF_CLASSES; i++) {
        for(int j=0; j<classifier->num_of_features; j++) {
            score[i] += classifier->weights[i*classifier->num_of_features + j] * feature_vector[j];
        }
        score[i] = sigmoid(score[i]);
    }

    double max_score = score[0];
    int max_index = 0;

    for(int i=1; i<NUM_OF_CLASSES; i++) {
        if(score[i] > max_score) {
            max_score = score[i];
            max_index = i;
        }
    }
    return max_index;
}

int train_classifier(Classifier* classifier, int num_of_training_images, Image** training_images, int* training_labels) {
    double step_size = 0.01;

    for(int i=0; i<NUM_OF_CLASSES; i++) {
        for(int j=0; j<classifier->num_of_features; j++) {
            classifier->weights[i*classifier->num_of_features + j] = 0.1;
        }
    }

    for(int epoch=0; epoch<10; epoch++) {
        for(int i=0; i<num_of_training_images; i++) {
            double feature_vector[training_images[i]->width * training_images[i]->height];
            img_to_feature_vector(training_images[i], feature_vector);

            double scores[NUM_OF_CLASSES] = {0};

            for(int j=0; j<NUM_OF_CLASSES; j++) {
                for(int k=0; k<classifier->num_of_features; k++) {
                    scores[j] += classifier->weights[j*classifier->num_of_features + k] * feature_vector[k];
                }
                scores[j] = sigmoid(scores[j]);
            }

            for(int j=0; j<NUM_OF_CLASSES; j++) {
                int label_for_class_j = (training_labels[i] == j) ? 1 : 0;
                double error_for_class_j = label_for_class_j - scores[j];

                for(int k=0; k<classifier->num_of_features; k++) {
                    classifier->weights[j*classifier->num_of_features + k] += step_size * error_for_class_j * feature_vector[k];
                }
            }
        }
    }
    return 1;
}

int main() {
    int width = 28, height = 28;
    char* data[] = {
        "...................................",
        "...................OOO.............",
        "....................O..............",
        "...............OOO..O..............",
        "..............O...O.O..............",
        "..............O..O..O..............",
        "..............O.O...O..............",
        ".............O..O...OOO............",
        "...................................",
        "...................................",
        "...................................",
        "...................................",
        "...................................",
        "...................................",
        "...................................",
        "..................................."
    };
    Image* test_image = malloc(sizeof(Image));
    test_image->width = width;
    test_image->height = height;
    test_image->data = malloc(width * height * sizeof(char));
    test_image->label = -1;
    for(int i=0; i<width*height; i++) {
        test_image->data[i] = data[i];
    }

    Classifier* classifier = malloc(sizeof(Classifier));
    classifier->num_of_features = width * height;
    classifier->weights = malloc(NUM_OF_CLASSES * classifier->num_of_features * sizeof(double));

    int num_of_training_images = 5;
    Image** training_images = malloc(num_of_training_images * sizeof(Image*));
    for(int i=0; i<num_of_training_images; i++) {
        training_images[i] = malloc(sizeof(Image));
        training_images[i]->width = width;
        training_images[i]->height = height;
        training_images[i]->data = malloc(width * height * sizeof(char));
        training_images[i]->label = i % NUM_OF_CLASSES;
        for(int j=0; j<width*height; j++) {
            training_images[i]->data[j] = rand() % 255;
        }
    }

    int* training_labels = malloc(num_of_training_images * sizeof(int));
    for(int i=0; i<num_of_training_images; i++) {
        training_labels[i] = training_images[i]->label;
    }
    
    train_classifier(classifier, num_of_training_images, training_images, training_labels);
    int prediction = classify_image(test_image, classifier);

    if(prediction == -1) {
        printf("Invalid test image\n");
    } else {
        printf("Test image classified as class %d\n", prediction);
    }

    return 0;
}