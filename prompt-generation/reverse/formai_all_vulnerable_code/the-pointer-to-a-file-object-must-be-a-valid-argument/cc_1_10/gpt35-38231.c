//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_SAMPLES 100
#define MAX_FILENAME_LEN 100

// Define a structure to hold information about the samples in each class
typedef struct sample {
    int id;
    int features[10];
} sample_t;

// Define a structure to hold information about each class
typedef struct class {
    char name[20];
    int num_samples;
    sample_t samples[MAX_SAMPLES];
} class_t;

// Function to read a feature vector from a file
void read_feature_vector(FILE *fp, int *features) {
    char line[100];
    fgets(line, 100, fp);
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
        features[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

// Function to read the training data from a file
void read_training_data(char *filename, class_t *classes, int *num_classes) {
    FILE *fp = fopen(filename, "r");

    // Read the number of classes
    char line[100];
    fgets(line, 100, fp);
    *num_classes = atoi(line);

    // Read each class
    for (int i = 0; i < *num_classes; i++) {
        fgets(classes[i].name, 20, fp);

        // Read the number of samples in the class
        fgets(line, 100, fp);
        classes[i].num_samples = atoi(line);

        // Read each sample in the class
        for (int j = 0; j < classes[i].num_samples; j++) {
            classes[i].samples[j].id = (i * 1000) + j;
            read_feature_vector(fp, classes[i].samples[j].features);
        }
    }

    fclose(fp);
}

// Function to classify a single feature vector
char *classify_sample(sample_t *sample, class_t *classes, int num_classes) {
    int max_class = -1;
    double max_score = -9999999.0;
    double scores[MAX_CLASSES];

    // Compute the score for each class
    for (int i = 0; i < num_classes; i++) {
        double score = 0.0;
        for (int j = 0; j < classes[i].num_samples; j++) {
            sample_t *train_sample = &classes[i].samples[j];
            for (int k = 0; k < 10; k++) {
                score += (sample->features[k] - train_sample->features[k]) *
                         (sample->features[k] - train_sample->features[k]);
            }
        }
        scores[i] = score;
        if (score > max_score) {
            max_score = score;
            max_class = i;
        }
    }

    // Check if the sample is ambiguous
    for (int i = 0; i < num_classes; i++) {
        if (i != max_class && scores[i] == max_score) {
            return "ambiguous";
        }
    }

    return classes[max_class].name;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <training_file> <test_file>\n", argv[0]);
        return 1;
    }

    // Read the training data
    class_t classes[MAX_CLASSES];
    int num_classes;
    read_training_data(argv[1], classes, &num_classes);

    // Classify each test sample
    FILE *fp = fopen(argv[2], "r");
    while (!feof(fp)) {
        // Read the next feature vector
        int features[10];
        read_feature_vector(fp, features);

        // Create a sample_t struct for the feature vector
        sample_t sample;
        sample.id = -1;
        memcpy(sample.features, features, sizeof(features));

        // Classify the sample
        char *class_name = classify_sample(&sample, classes, num_classes);
        printf("%s\n", class_name);
    }

    fclose(fp);
    return 0;
}