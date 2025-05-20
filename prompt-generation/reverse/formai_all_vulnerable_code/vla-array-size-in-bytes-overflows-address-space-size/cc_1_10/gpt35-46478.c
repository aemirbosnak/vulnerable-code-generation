//FormAI DATASET v1.0 Category: Image Editor ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void gray_scale(int height, int width, int image[][width]);
void lighten(int height, int width, int image[][width], int amount);
void darken(int height, int width, int image[][width], int amount);
void invert(int height, int width, int image[][width]);
void blur(int height, int width, int image[][width], int radius);

int main()
{
    int height, width, choice, amount, radius, i, j;
    
    printf("Enter the height and width of the image: ");
    scanf("%d %d", &height, &width);
    
    int image[height][width];
    
    //Reading the input image
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }
    
    printf("Enter the operation to perform:\n");
    printf("1. Grayscale\n2. Lighten\n3. Darken\n4. Invert\n5. Blur\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: gray_scale(height, width, image);
                break;
                
        case 2: printf("Enter the amount to lighten (0-255): ");
                scanf("%d", &amount);
                lighten(height, width, image, amount);
                break;
                
        case 3: printf("Enter the amount to darken (0-255): ");
                scanf("%d", &amount);
                darken(height, width, image, amount);
                break;
                
        case 4: invert(height, width, image);
                break;
                
        case 5: printf("Enter the blur radius (1-10): ");
                scanf("%d", &radius);
                blur(height, width, image, radius);
                break;
                
        default: printf("Invalid choice!");
    }
    
    //Printing the modified image
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void gray_scale(int height, int width, int image[][width])
{
    int i, j, avg;
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            avg = (image[i][j]>>2) + (image[i][j]>>1) + (image[i][j]>>3);
            image[i][j] = avg;
        }
    }
}

void lighten(int height, int width, int image[][width], int amount)
{
    int i, j;
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            image[i][j] += amount;
            if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

void darken(int height, int width, int image[][width], int amount)
{
    int i, j;
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            image[i][j] -= amount;
            if(image[i][j] < 0) image[i][j] = 0;
        }
    }
}

void invert(int height, int width, int image[][width])
{
    int i, j;
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}

void blur(int height, int width, int image[][width], int radius)
{
    int i, j, k, l, sum, cnt, avg;
    int temp[height][width];
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            sum = 0;
            cnt = 0;
            for(k=i-radius; k<=i+radius; k++)
            {
                for(l=j-radius; l<=j+radius; l++)
                {
                    if(k>=0 && k<height && l>=0 && l<width)
                    {
                        sum += image[k][l];
                        cnt++;
                    }
                }
            }
            temp[i][j] = sum/cnt;
        }
    }
    
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}