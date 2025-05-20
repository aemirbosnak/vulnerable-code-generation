//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc==1)
    {
        printf("Please provide an image file in the command line argument.");
        exit(0);
    }

    char* imageFile = argv[1];

    char prompt[100] = "Enter the number of the filter you want to apply:\n"
                       "1. Grayscale Filter\n"
                       "2. Invert Colors Filter\n"
                       "3. Sepia Filter\n"
                       "4. Blur Filter\n"
                       "5. Sharpen Filter\n"
                       "6. Brightness Filter\n"
                       "7. Contrast Filter\n"
                       "8. Exit\n";
    printf("%s", prompt);

    int filterChoice;
    scanf("%d", &filterChoice);

    FILE* image = fopen(imageFile, "r");
    if(image==NULL)
    {
        printf("Error opening image file.");
        exit(0);
    }

    char magicNumber[3];
    fscanf(image, "%s", magicNumber);

    if(strcmp(magicNumber, "P3")!=0)
    {
        printf("Invalid image file format. This program only supports P3 PPM files.");
        exit(0);
    }

    int width, height, colorRange;
    fscanf(image, "%d %d\n%d", &width, &height, &colorRange);

    int numPixels = width * height;
    int* pixelColors = (int*)malloc(numPixels * sizeof(int));

    for(int i=0; i<numPixels; i++)
    {
        int red, green, blue;
        fscanf(image, "%d %d %d", &red, &green, &blue);
        pixelColors[i] = (red<<16) | (green<<8) | blue;
    }

    fclose(image);

    int r, g, b, gray, redSepia, greenSepia, blueSepia;
    int* newPixelColors = (int*)malloc(numPixels * sizeof(int));

    switch(filterChoice)
    {
        case 1: // Grayscale Filter
            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);
                gray = (r + g + b) / 3;
                newPixelColors[i] = (gray<<16) | (gray<<8) | gray;
            }
            break;

        case 2: // Invert Colors Filter
            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);
                newPixelColors[i] = ((255 - r)<<16) | ((255 - g)<<8) | (255 - b);
            }
            break;

        case 3: // Sepia Filter
            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);
                redSepia = (int)(0.393 * r + 0.769 * g + 0.189 * b);
                greenSepia = (int)(0.349 * r + 0.686 * g + 0.168 * b);
                blueSepia = (int)(0.272 * r + 0.534 * g + 0.131 * b);
                newPixelColors[i] = (redSepia<<16) | (greenSepia<<8) | blueSepia;
            }
            break;

        case 4: // Blur Filter
            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);

                int redSum=0, greenSum=0, blueSum=0, numPixelsUsed=0;

                for(int j=-1; j<=1; j++)
                {
                    for(int k=-1; k<=1; k++)
                    {
                        int pixelIndex = i + j*width + k;
                        if(pixelIndex >=0 && pixelIndex<numPixels)
                        {
                            redSum += (pixelColors[pixelIndex] >> 16) & 0xFF;
                            greenSum += (pixelColors[pixelIndex] >> 8) & 0xFF;
                            blueSum += pixelColors[pixelIndex] & 0xFF;
                            numPixelsUsed++;
                        }
                    }
                }

                newPixelColors[i] = ((redSum/numPixelsUsed)<<16) | ((greenSum/numPixelsUsed)<<8) | (blueSum/numPixelsUsed);
            }
            break;

        case 5: // Sharpen Filter
            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);

                int redSum=0, greenSum=0, blueSum=0, numPixelsUsed=0;

                for(int j=-1; j<=1; j++)
                {
                    for(int k=-1; k<=1; k++)
                    {
                        int pixelIndex = i + j*width + k;
                        if(pixelIndex >=0 && pixelIndex<numPixels)
                        {
                            redSum += (pixelColors[pixelIndex] >> 16) & 0xFF;
                            greenSum += (pixelColors[pixelIndex] >> 8) & 0xFF;
                            blueSum += pixelColors[pixelIndex] & 0xFF;
                            numPixelsUsed++;
                        }
                    }
                }

                int redSharpened = (3*r - (redSum/numPixelsUsed));
                int greenSharpened = (3*g - (greenSum/numPixelsUsed));
                int blueSharpened = (3*b - (blueSum/numPixelsUsed));

                if(redSharpened>255) redSharpened = 255;
                if(greenSharpened>255) greenSharpened = 255;
                if(blueSharpened>255) blueSharpened = 255;

                if(redSharpened<0) redSharpened = 0;
                if(greenSharpened<0) greenSharpened = 0;
                if(blueSharpened<0) blueSharpened = 0;

                newPixelColors[i] = (redSharpened<<16) | (greenSharpened<<8) | blueSharpened;
            }
            break;

        case 6: // Brightness Filter
            printf("Enter the brightness level (-255 to 255): ");
            int brightnessLevel;
            scanf("%d", &brightnessLevel);

            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);

                int redBrightened = r + brightnessLevel;
                int greenBrightened = g + brightnessLevel;
                int blueBrightened = b + brightnessLevel;

                if(redBrightened>255) redBrightened = 255;
                if(greenBrightened>255) greenBrightened = 255;
                if(blueBrightened>255) blueBrightened = 255;

                if(redBrightened<0) redBrightened = 0;
                if(greenBrightened<0) greenBrightened = 0;
                if(blueBrightened<0) blueBrightened = 0;

                newPixelColors[i] = (redBrightened<<16) | (greenBrightened<<8) | blueBrightened;
            }
            break;

        case 7: // Contrast Filter
            printf("Enter the contrast level (-255 to 255): ");
            int contrastLevel;
            scanf("%d", &contrastLevel);

            double contrastFactor = (259.0 * (contrastLevel + 255.0)) / (255.0 * (259.0 - contrastLevel));

            for(int i=0; i<numPixels; i++)
            {
                r = (pixelColors[i] >> 16) & 0xFF;
                g = (pixelColors[i] >> 8) & 0xFF;
                b = (pixelColors[i] & 0xFF);

                int redContrasted = (int)(contrastFactor * (r - 128) + 128);
                int greenContrasted = (int)(contrastFactor * (g - 128) + 128);
                int blueContrasted = (int)(contrastFactor * (b - 128) + 128);

                if(redContrasted>255) redContrasted = 255;
                if(greenContrasted>255) greenContrasted = 255;
                if(blueContrasted>255) blueContrasted = 255;

                if(redContrasted<0) redContrasted = 0;
                if(greenContrasted<0) greenContrasted = 0;
                if(blueContrasted<0) blueContrasted = 0;

                newPixelColors[i] = (redContrasted<<16) | (greenContrasted<<8) | blueContrasted;
            }
            break;

        case 8: // Exit
            printf("Exiting the program.");
            exit(0);

        default:
            printf("Invalid filter choice.");
            exit(0);
    }

    FILE* newImage = fopen("newimage.ppm", "w");
    fprintf(newImage, "P3\n");
    fprintf(newImage, "%d %d\n", width, height);
    fprintf(newImage, "%d\n", colorRange);

    for(int i=0; i<numPixels; i++)
    {
        fprintf(newImage, "%d %d %d ", (newPixelColors[i] >> 16) & 0xFF, (newPixelColors[i] >> 8) & 0xFF, newPixelColors[i] & 0xFF);
    }

    fclose(newImage);
    free(pixelColors);
    free(newPixelColors);

    printf("The image has been edited successfully. The new image has been saved as 'newimage.ppm'");
    return 0;
}