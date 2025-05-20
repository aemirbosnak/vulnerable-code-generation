//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Image Classification System Example Program!\n");
    printf("Please enter the number of images you want to classify: ");

    int numImages;
    scanf("%d", &numImages);

    int* imageLabels = (int*) malloc(numImages * sizeof(int));
    float* imageScores = (float*) malloc(numImages * sizeof(float));

    printf("\nGreat! Now let's begin classifying.\n");

    for (int i = 0; i < numImages; i++) {
        printf("\n\n------------------------------\n");
        printf("Please input Data for Image %d\n", i+1);
        printf("Image Width: ");
        int width;
        scanf("%d", &width);
        printf("Image Height: ");
        int height;
        scanf("%d", &height);

        // Image classification algorithm goes here
        printf("\nImage %d has been classified.\n", i+1);

        // Assigning random scores and labels just for demonstration purposes
        float score = (float) rand() / RAND_MAX;
        imageScores[i] = score;
        int label = (int) (score * 10);
        imageLabels[i] = label;
    }

    printf("\n\nAll images have been classified!\n");

    // Sorting the images in descending order of scores
    for (int i = 0; i < numImages-1; i++) {
        for (int j = 0; j < numImages-i-1; j++) {
            if (imageScores[j] < imageScores[j+1]) {
                float tempScore = imageScores[j];
                imageScores[j] = imageScores[j+1];
                imageScores[j+1] = tempScore;

                int tempLabel = imageLabels[j];
                imageLabels[j] = imageLabels[j+1];
                imageLabels[j+1] = tempLabel;
            }
        }
    }

    // Displaying the results
    printf("\n\nResults:\n");
    printf("-----------------------------\n");
    printf("|    Image    |    Label    |\n");
    printf("-----------------------------\n");
    for (int i = 0; i < numImages; i++) {
        printf("|      %d      |      %d      |\n", i+1, imageLabels[i]);
        printf("-----------------------------\n");
    }

    free(imageLabels);
    free(imageScores);

    return 0;
}