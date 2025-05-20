//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to classify image
void classify_image(char *image_path, char *classification)
{
    FILE *fp = fopen(image_path, "rb");
    if (fp == NULL)
    {
        printf("Error opening image file.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *image_data = (char *)malloc(image_size);
    fread(image_data, 1, image_size, fp);
    fclose(fp);

    int classification_index = classify(image_data, image_size, classification);
    if (classification_index == -1)
    {
        printf("Image not classified.\n");
    }
    else
    {
        printf("Image classified as %s.\n", classification[classification_index]);
    }

    free(image_data);
}

int classify(char *image_data, int image_size, char *classifications[])
{
    int num_classes = sizeof(classifications) / sizeof(char *);
    for (int i = 0; i < num_classes; i++)
    {
        if (strcmp(image_data, classifications[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char *image_path = "image.jpg";
    char *classifications[] = {"flower", "tree", "sky", "water"};

    classify_image(image_path, classifications);

    return 0;
}