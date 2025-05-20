//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int n;
    int **img;
} img_data;

void *flip_horizontal(void *arg) {
    img_data *data = (img_data *) arg;
    int n = data->n;
    int **img = data->img;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            int temp = img[i][j];
            img[i][j] = img[i][n-j-1];
            img[i][n-j-1] = temp;
        }
    }
    
    pthread_exit(NULL);
}

void *adjust_contrast(void *arg) {
    img_data *data = (img_data *) arg;
    int n = data->n;
    int **img = data->img;
    int factor = 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j] = img[i][j] * factor;
            if (img[i][j] > 255) {
                img[i][j] = 255;
            }
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    int n = 5;
    int **img = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        img[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            img[i][j] = i + j;
        }
    }
    
    img_data *data = (img_data *) malloc(sizeof(img_data));
    data->n = n;
    data->img = img;
    
    pthread_t tids[2];
    pthread_create(&tids[0], NULL, flip_horizontal, data);
    pthread_create(&tids[1], NULL, adjust_contrast, data);
    
    for (int i = 0; i < 2; i++) {
        pthread_join(tids[i], NULL);
    }
    
    printf("Original Image:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(img[i]);
    }
    free(img);
    free(data);
    
    return 0;
}