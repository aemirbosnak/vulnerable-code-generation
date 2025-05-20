//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

void compress_image(int **img, int rows, int cols){
    int count, curr_pixel;
    for (int i = 0; i < rows; i++){
        count = 1;
        curr_pixel = img[i][0];
        for (int j = 1; j < cols; j++){
            if(curr_pixel == img[i][j]){
                count++;
            }
            else{
                printf("%d %d ", curr_pixel, count);
                curr_pixel = img[i][j];
                count = 1;
            }
        }
        printf("%d %d ", curr_pixel, count); //Print last pixel and its count
        printf("\n");
    }
}

int main(){
    int rows, cols;
    printf("Enter number of rows in image: ");
    scanf("%d", &rows);
    printf("Enter number of columns in image: ");
    scanf("%d", &cols);

    int **img = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        img[i] = (int *)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++){
            printf("Enter pixel value at row %d and column %d: ", i+1, j+1);
            scanf("%d", &img[i][j]);
        }
    }

    printf("\nCompressed image data:\n");
    compress_image(img, rows, cols);

    //Free allocated memory
    for(int i = 0; i < rows; i++){
        free(img[i]);
    }
    free(img);

    return 0;
}