//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define image size
#define ROWS 10
#define COLS 10

// define image matrix
int image[ROWS][COLS] = {
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255}
};

// function to display the image matrix
void displayImage() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// function to invert the colors of the image
void* invertColors(void* arg) {
    int row = *(int*) arg;
    for (int j = 0; j < COLS; j++) {
        image[row][j] = 255 - image[row][j];
    }
    return NULL;
}

int main() {
    printf("Original Image:\n");
    displayImage();

    // create threads to invert colors of image asynchronously
    pthread_t tid[ROWS];
    for (int i = 0; i < ROWS; i++) {
        int* row = malloc(sizeof(int));
        *row = i;
        pthread_create(&tid[i], NULL, invertColors, row);
    }

    // wait for all threads to complete
    for (int i = 0; i < ROWS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("\nInverted Image:\n");
    displayImage();

    return 0;
}