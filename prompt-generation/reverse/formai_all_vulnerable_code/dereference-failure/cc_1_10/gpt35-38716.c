//FormAI DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image {
    int width;
    int height;
    char* filename;
} Image;

typedef struct ClassificationResult {
    char* category;
    float probability;
} ClassificationResult;

int main() {
    printf("Welcome to the wackiest Image Classification system!\n");
    printf("This program will identify whether an image is a cat or dog!\n");

    Image* img = malloc(sizeof(Image));
    img->filename = malloc(sizeof(char) * 50);

    printf("Please enter the filename of the image you would like to classify: ");
    scanf("%s", img->filename);
    printf("Great! We will now analyze \"%s\"\n", img->filename);

    if (strcmp(img->filename, "cute_cat.jpg") == 0) {
        printf("Aww, looks like you have a cute cat picture\n");
    } else if (strcmp(img->filename, "silly_dog.png") == 0) {
        printf("Ha! You have a silly dog picture\n");
    } else {
        printf("Hmm... we're not sure what that is, let us try to classify it!\n");
    }

    ClassificationResult* results = malloc(sizeof(ClassificationResult) * 2);

    if (strcmp(img->filename, "cute_cat.jpg") == 0) {
        results[0].category = "cat";
        results[0].probability = 0.95;
        results[1].category = "dog";
        results[1].probability = 0.05;
    } else if (strcmp(img->filename, "silly_dog.png") == 0) {
        results[0].category = "dog";
        results[0].probability = 0.99;
        results[1].category = "cat";
        results[1].probability = 0.01;
    } else {
        printf("Analyzing image...\n");
        results[0].category = "unknown";
        results[0].probability = 0.5;
        results[1].category = "unknown";
        results[1].probability = 0.5;
    }

    printf("\n");
    printf("Results:\n");
    printf("\"%s\" is most likely a %s with a %f probability\n", img->filename, results[0].category, results[0].probability);
    printf("Or it could be a %s with a %f probability\n", results[1].category, results[1].probability);

    free(img->filename);
    free(img);
    free(results);

    printf("Thanks for using our wacky Image Classification system! Have a pawsome day!\n");

    return 0;
}