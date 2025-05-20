//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 100
#define WIDTH 100
#define NUM_CLASSES 3
#define NUM_TRAINING_SAMPLES 100
#define NUM_TEST_SAMPLES 10

typedef struct {
    int x;
    int y;
    int label;
} Sample;

typedef struct {
    int num_samples;
    Sample *samples;
} Dataset;

void generate_random_dataset(Dataset *dataset) {
    srand(time(NULL));
    dataset->num_samples = NUM_TRAINING_SAMPLES;
    dataset->samples = malloc(dataset->num_samples * sizeof(Sample));

    for (int i = 0; i < dataset->num_samples; i++) {
        dataset->samples[i].x = rand() % WIDTH;
        dataset->samples[i].y = rand() % HEIGHT;
        dataset->samples[i].label = rand() % NUM_CLASSES;
    }
}

void print_sample(Sample sample) {
    printf("(%d, %d, %d)\n", sample.x, sample.y, sample.label);
}

void print_dataset(Dataset dataset) {
    for (int i = 0; i < dataset.num_samples; i++) {
        print_sample(dataset.samples[i]);
    }
}

int main() {
    Dataset training_dataset;
    generate_random_dataset(&training_dataset);
    print_dataset(training_dataset);

    return 0;
}