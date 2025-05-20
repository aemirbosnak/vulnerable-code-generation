//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to apply grayscale filter
void grayscale(unsigned char *image, int width, int height)
{
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int off = (y * width + x) * 3;
            unsigned char r = image[off];
            unsigned char g = image[off + 1];
            unsigned char b = image[off + 2];
            unsigned char gray = (unsigned char)(0.2989 * r + 0.5870 * g + 0.1140 * b);

            image[off] = gray;
            image[off + 1] = gray;
            image[off + 2] = gray;
        }
    }
}

//Function to apply blur filter
void blur(unsigned char *image, int width, int height)
{
    int x, y;
    int kSize = 3;

    unsigned char *tmpImage = (unsigned char *) calloc(width * height * 3, sizeof(unsigned char));

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            float rAcc = 0, gAcc = 0, bAcc = 0;
            int n = 0;

            for (int ky = -kSize; ky <= kSize; ky++) {
                for (int kx = -kSize; kx <= kSize; kx++) {
                    int nx = x + kx;
                    int ny = y + ky;

                    if (nx >= 0 && ny >= 0 && nx < width && ny < height) {
                        int off = (ny * width + nx) * 3;
                        rAcc += image[off];
                        gAcc += image[off + 1];
                        bAcc += image[off + 2];
                        n++;
                    }
                }
            }

            int off = (y * width + x) * 3;

            tmpImage[off++] = rAcc / n;
            tmpImage[off++] = gAcc / n;
            tmpImage[off++] = bAcc / n;
        }
    }

    memcpy(image, tmpImage, width * height * 3);
    free(tmpImage);
}

//Function to apply threshold filter
void threshold(unsigned char *image, int width, int height, unsigned char thresholdValue)
{
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int off = (y * width + x) * 3;
            unsigned char r = image[off];
            unsigned char g = image[off + 1];
            unsigned char b = image[off + 2];

            unsigned char gray = (unsigned char) (0.2989 * r + 0.5870 * g + 0.1140 * b);

            if (gray >= thresholdValue) {
                image[off] = 255;
                image[off + 1] = 255;
                image[off + 2] = 255;
            } else {
                image[off] = 0;
                image[off + 1] = 0;
                image[off + 2] = 0;
            }
        }
    }
}

int main(int argc, char **argv)
{
    //Input image file name
    char *imageFileName = "inputImage.bmp";

    //Output image file name
    char *outputFileName = "outputImage.bmp";

    //Read image file
    unsigned char *image;
    int width, height;
    int imageSize;

    FILE *fp = fopen(imageFileName, "rb");

    if (fp) {
        fseek(fp, 18, SEEK_SET);
        fread(&width, sizeof(int), 1, fp);
        fread(&height, sizeof(int), 1, fp);
        imageSize = width * height * 3;

        image = (unsigned char *) malloc(imageSize);

        fseek(fp, 54, SEEK_SET);
        fread(image, sizeof(unsigned char), imageSize, fp);

        fclose(fp);

        printf("Image width: %d\n", width);
        printf("Image height: %d\n", height);

        //Apply grayscale filter
        grayscale(image, width, height);
        printf("Grayscale filter applied\n");

        //Apply blur filter
        blur(image, width, height);
        printf("Blur filter applied\n");

        //Apply threshold filter
        threshold(image, width, height, 128);
        printf("Threshold filter applied\n");

        //Write image file
        fp = fopen(outputFileName, "wb");

        fseek(fp, 18, SEEK_SET);
        fwrite(&width, sizeof(int), 1, fp);
        fwrite(&height, sizeof(int), 1, fp);

        fseek(fp, 54, SEEK_SET);
        fwrite(image, sizeof(unsigned char), imageSize, fp);

        fclose(fp);

        printf("Output image saved as %s\n", outputFileName);

        free(image);
    } else {
        printf("Error opening image file %s", imageFileName);
    }

    return 0;
}