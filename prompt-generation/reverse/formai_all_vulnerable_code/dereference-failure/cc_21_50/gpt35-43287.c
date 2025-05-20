//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the Curious Image Editor!\n");
    
    int choice = 0;
    int img_width = 0;
    int img_height = 0;
    int i, j;
    
    printf("Enter the width of the image: ");
    scanf("%d", &img_width);
    printf("Enter the height of the image: ");
    scanf("%d", &img_height);
    
    int **image = (int **)malloc(img_width * sizeof(int *));
    for(i=0;i<img_width;i++){
        image[i] = (int *)malloc(img_height * sizeof(int));
    }
    
    //initialize the image with random pixel values
    for(i=0;i<img_height;i++){
        for(j=0;j<img_width;j++){
            image[j][i] = rand()%255;
        }
    }
    
    //display the image
    printf("\nInitial Image:\n");
    for(i=0;i<img_height;i++){
        for(j=0;j<img_width;j++){
            printf("%d ", image[j][i]);
        }
        printf("\n");
    }
    
    while(1){
        printf("\n1. Gray Scale\n");
        printf("2. Invert Colors\n");
        printf("3. Mirror Image\n");
        printf("4. Rotate 90 degrees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: //convert image to gray scale
            {
                for(i=0;i<img_height;i++){
                    for(j=0;j<img_width;j++){
                        int gray_value = 0.299*image[j][i] + 0.587*image[j][i] + 0.114*image[j][i];
                        image[j][i] = gray_value;
                    }
                }
                printf("\nImage converted to gray scale.\n");
                break;
            }
            case 2: //invert colors of image
            {
                for(i=0;i<img_height;i++){
                    for(j=0;j<img_width;j++){
                        image[j][i] = 255 - image[j][i];
                    }
                }
                printf("\nColors of image inverted.\n");
                break;
            }
            case 3: //mirror image
            {
                for(i=0;i<img_height;i++){
                    for(j=0;j<img_width/2;j++){
                        int temp = image[j][i];
                        image[j][i] = image[img_width-j-1][i];
                        image[img_width-j-1][i] = temp;
                    }
                }
                printf("\nImage mirrored.\n");
                break;
            }
            case 4: //rotate image 90 degrees
            {
                int **rotated_image = (int **)malloc(img_height * sizeof(int *));
                for(i=0;i<img_height;i++){
                    rotated_image[i] = (int *)malloc(img_width * sizeof(int));
                }
                
                for(i=0;i<img_width;i++){
                    for(j=0;j<img_height;j++){
                        rotated_image[j][img_width-i-1] = image[i][j];
                    }
                }
                
                printf("\nImage rotated 90 degrees.\n");
                
                //free the existing memory for image and re-allocate it to the new rotated image
                for(i=0;i<img_width;i++){
                    free(image[i]);
                }
                free(image);
                image = rotated_image;
                int temp = img_width;
                img_width = img_height;
                img_height = temp;
                
                break;
            }
            case 5: //exit the program
            {
                printf("\nThank you for using Curious Image Editor!\n");
                
                //free the memory allocated for image
                for(i=0;i<img_width;i++){
                    free(image[i]);
                }
                free(image);
                return 0;
            }
            default:
            {
                printf("\nInvalid choice. Please enter again.\n");
                break;
            }
        }
        
        //display the updated image
        printf("\nUpdated Image:\n");
        for(i=0;i<img_height;i++){
            for(j=0;j<img_width;j++){
                printf("%d ", image[j][i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}