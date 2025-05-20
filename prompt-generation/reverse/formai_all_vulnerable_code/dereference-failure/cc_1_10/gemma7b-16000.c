//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASS_NUM 5

typedef struct ImageData
{
    char **pixels;
    int width;
    int height;
    int label;
} ImageData;

ImageData **loadData(char *path)
{
    // Read image file and allocate memory for ImageData structure
    ImageData **data = malloc(sizeof(ImageData *) * MAX_CLASS_NUM);
    for (int i = 0; i < MAX_CLASS_NUM; i++)
    {
        data[i] = malloc(sizeof(ImageData));
    }

    // Get image width, height, and label
    FILE *fp = fopen(path, "r");
    fscanf(fp, "%d %d", &data[0]->width, &data[0]->height);
    data[0]->label = fgetc(fp);
    fclose(fp);

    // Allocate memory for pixels and copy pixels from file
    data[0]->pixels = malloc(data[0]->width * data[0]->height * sizeof(char));
    fp = fopen(path, "r");
    fread(data[0]->pixels, data[0]->width * data[0]->height * sizeof(char), 1, fp);
    fclose(fp);

    return data;
}

int main()
{
    // Load images
    ImageData **data = loadData("image.jpg");

    // Print label of each image
    for (int i = 0; i < MAX_CLASS_NUM; i++)
    {
        printf("Image %d label: %c\n", i, data[i]->label);
    }

    return 0;
}