//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image along vertical axis
void flipImageVertical(int **image, int height, int width){
    for(int i=0;i<height;i++){
        for(int j=0;j<width/2;j++){
            int temp=image[i][j];
            image[i][j]=image[i][width-j-1];
            image[i][width-j-1]=temp;
        }
    }
}

// Function to adjust the brightness and constrast of image
void adjustBrightnessContrast(int **image, int height, int width, int brightness, int contrast){
    // Adjust brightness
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j]+=brightness;
            if(image[i][j]>255) image[i][j]=255;
            if(image[i][j]<0) image[i][j]=0;
        }
    }
    // Adjust contrast
    float factor=(259*(contrast+255))/(255*(259-contrast));
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            float val=image[i][j]-128;
            val=val*factor;
            val=val+128;
            if(val>255) val=255;
            if(val<0) val=0;
            image[i][j]=(int)val;
        }
    }
}

int main() {
    int height=5;
    int width=5;
    int **image= (int **)malloc(height*sizeof(int*)); 
    for (int i=0;i<height;i++) 
         image[i] = (int *)malloc(width*sizeof(int)); 
    
    // Initializing image with random values
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            image[i][j]=rand()%256;
        }
    }
    
    printf("Original Image:\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    
    // Flipping Image Vertical
    flipImageVertical(image,height,width);
    
    printf("Flipped Image (Vertical):\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    
    // Adjusting Brightness and Contrast
    adjustBrightnessContrast(image,height,width,50,50);
    
    printf("Modified Image (Brightness+Contrast):\n");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ",image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}