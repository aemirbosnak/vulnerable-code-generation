//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's magnifying glass
#define MAGNIFY 100

// Watson's notebook
typedef struct {
    char* name;
    int* features;
    int num_features;
} Image;

// The Yard's database
Image* database[100];
int num_images = 0;

// Sherlock's deduction method
Image* classify(Image* image) {
    int best_match_score = 0;
    Image* best_match = NULL;

    for (int i = 0; i < num_images; i++) {
        int score = 0;

        for (int j = 0; j < image->num_features; j++) {
            score += abs(image->features[j] - database[i]->features[j]);
        }

        if (score < best_match_score || best_match == NULL) {
            best_match_score = score;
            best_match = database[i];
        }
    }

    return best_match;
}

// Watson's note-taking method
void add_image(Image* image) {
    database[num_images++] = image;
}

// A crime scene photograph
Image* crime_scene_photo() {
    Image* image = malloc(sizeof(Image));
    image->name = "Crime Scene";
    image->num_features = 10;
    image->features = malloc(sizeof(int) * image->num_features);

    for (int i = 0; i < image->num_features; i++) {
        image->features[i] = rand() % 100;
    }

    return image;
}

int main() {
    // The Yard's initial database
    Image* suspect1 = malloc(sizeof(Image));
    suspect1->name = "Suspect 1";
    suspect1->num_features = 10;
    suspect1->features = malloc(sizeof(int) * suspect1->num_features);

    for (int i = 0; i < suspect1->num_features; i++) {
        suspect1->features[i] = rand() % 100;
    }

    add_image(suspect1);

    Image* suspect2 = malloc(sizeof(Image));
    suspect2->name = "Suspect 2";
    suspect2->num_features = 10;
    suspect2->features = malloc(sizeof(int) * suspect2->num_features);

    for (int i = 0; i < suspect2->num_features; i++) {
        suspect2->features[i] = rand() % 100;
    }

    add_image(suspect2);

    // The crime scene photograph
    Image* crime_scene = crime_scene_photo();

    // Sherlock's deduction
    Image* suspect = classify(crime_scene);

    // Watson's conclusion
    printf("The suspect is: %s\n", suspect->name);

    return 0;
}