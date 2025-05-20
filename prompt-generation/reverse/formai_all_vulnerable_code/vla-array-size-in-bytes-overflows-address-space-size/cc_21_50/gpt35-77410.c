//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height, maxval, brightness, contrast, choice;
    char filename[100];
    FILE *fp;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error: Cannot open file %s", filename);
        exit(1);
    }

    fscanf(fp, "P3\n%d %d\n%d\n", &width, &height, &maxval);

    int image[height][width][3];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                fscanf(fp, "%d", &image[i][j][k]);
            }
        }
    }

    printf("\nImage opened successfully!");
    printf("\n\n\t1. Flip Image Horizontally.");
    printf("\n\t2. Flip Image Vertically.");
    printf("\n\t3. Increase Brightness.");
    printf("\n\t4. Reduce Brightness.");
    printf("\n\t5. Increase Contrast.");
    printf("\n\t6. Reduce Contrast.");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Flip horizontally
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width/2; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        int temp = image[i][j][k];
                        image[i][j][k] = image[i][width-j-1][k];
                        image[i][width-j-1][k] = temp;
                    }
                }
            }
            printf("Image flipped horizontally!");
            break;

        case 2: // Flip vertically
            for(int i = 0; i < height/2; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        int temp = image[i][j][k];
                        image[i][j][k] = image[height-i-1][j][k];
                        image[height-i-1][j][k] = temp;
                    }
                }
            }
            printf("Image flipped vertically!");
            break;

        case 3: // Increase brightness
            printf("Enter increase in brightness (0-255): ");
            scanf("%d", &brightness);
            if(brightness > 255 || brightness < 0)
            {
                printf("Error: brightness must be in the range of 0-255.");
                exit(1);
            }
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        if(image[i][j][k] + brightness > 255)
                        {
                            image[i][j][k] = 255;
                        }
                        else
                        {
                            image[i][j][k] += brightness;
                        }
                    }
                }
            }
            printf("Brightness increased by %d!", brightness);
            break;

        case 4: // Reduce brightness
            printf("Enter reduction in brightness (0-255): ");
            scanf("%d", &brightness);
            if(brightness > 255 || brightness < 0)
            {
                printf("Error: brightness must be in the range of 0-255.");
                exit(1);
            }
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        if(image[i][j][k] - brightness < 0)
                        {
                            image[i][j][k] = 0;
                        }
                        else
                        {
                            image[i][j][k] -= brightness;
                        }
                    }
                }
            }
            printf("Brightness reduced by %d!", brightness);
            break;

        case 5: // Increase contrast
            printf("Enter increase in contrast (0-100): ");
            scanf("%d", &contrast);
            if(contrast > 100 || contrast < 0)
            {
                printf("Error: contrast must be in the range of 0-100.");
                exit(1);
            }
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
                        image[i][j][k] = (int) (factor * (image[i][j][k] - 128) + 128);
                        if(image[i][j][k] > 255)
                        {
                            image[i][j][k] = 255;
                        }
                        else if(image[i][j][k] < 0)
                        {
                            image[i][j][k] = 0;
                        }
                    }
                }
            }
            printf("Contrast increased by %d%%!", contrast);
            break;

        case 6: // Reduce contrast
            printf("Enter reduction in contrast (0-100): ");
            scanf("%d", &contrast);
            if(contrast > 100 || contrast < 0)
            {
                printf("Error: contrast must be in the range of 0-100.");
                exit(1);
            }
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        float factor = (259 * (255 - contrast)) / (255 * (259 - contrast));
                        image[i][j][k] = (int) (factor * (image[i][j][k] - 128) + 128);
                        if(image[i][j][k] > 255)
                        {
                            image[i][j][k] = 255;
                        }
                        else if(image[i][j][k] < 0)
                        {
                            image[i][j][k] = 0;
                        }
                    }
                }
            }
            printf("Contrast reduced by %d%%!", contrast);
            break;

        default:
            printf("Error: Invalid choice.");
            exit(1);
    }

    char new_filename[100];
    printf("\nEnter the name of the new file to save the image: ");
    scanf("%s", new_filename);

    fp = fopen(new_filename, "w");

    fprintf(fp, "P3\n%d %d\n%d\n", width, height, maxval);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            fprintf(fp, "%d %d %d ", image[i][j][0], image[i][j][1], image[i][j][2]);
        }
        fprintf(fp, "\n");
    }

    printf("\nImage saved successfully as %s!", new_filename);

    fclose(fp);

    return 0;
}