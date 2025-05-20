//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//Function to flip an image
void flip_image(int **image, int rows, int cols, int i, int j){
    //Base case
    if(i>=rows || j>=cols){
        return;
    }
    //Recursive call to flip the image
    flip_image(image, rows, cols, i+1, j);
    flip_image(image, rows, cols, i, j+1);

    //Swapping the pixel values
    int temp = image[i][j];
    image[i][j] = image[rows-i-1][cols-j-1];
    image[rows-i-1][cols-j-1] = temp;
}

//Function to change the brightness and contrast of an image
void brightness_contrast(int **image, int rows, int cols, int i, int j, int brightness, int contrast){
    //Base case
    if(i>=rows || j>=cols){
        return;
    }
    //Recursive call to adjust the brightness and contrast of each pixel
    brightness_contrast(image, rows, cols, i+1, j, brightness, contrast);
    brightness_contrast(image, rows, cols, i, j+1, brightness, contrast);

    //Changing the brightness and contrast of the pixel
    int pixel_value = image[i][j];
    pixel_value = (pixel_value * contrast + brightness);
    pixel_value = (pixel_value > 255)? 255 : pixel_value;
    pixel_value = (pixel_value < 0)? 0 : pixel_value;
    image[i][j] = pixel_value;
}

int main(){
    int rows, cols;
    printf("Enter the number of rows and columns in the image: ");
    scanf("%d %d", &rows, &cols);
    printf("\nEnter the pixel values of the image:\n");

    //Dynamically allocating memory for the image
    int **image = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++){
        image[i] = (int *)malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            scanf("%d", &image[i][j]);
        }
    }

    //Flipping the image
    flip_image(image, rows, cols, 0, 0);

    //Adjusting the brightness and contrast of the image
    brightness_contrast(image, rows, cols, 0, 0, 50, 1.2);

    //Displaying the final image
    printf("\nThe processed image is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    //Freeing the dynamically allocated memory
    for(int i=0; i<rows; i++){
        free(image[i]);
    }
    free(image);

    return 0;
}