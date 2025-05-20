//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *image = NULL;
    image = malloc(1024);
    memset(image, 0, 1024);

    char *filter = NULL;
    filter = malloc(1024);
    memset(filter, 0, 1024);

    printf("Enter filter command: ");
    fgets(filter, 1024, stdin);

    // Paranoia-fuelled filter implementation
    if (strcmp(filter, "blur") == 0)
    {
        // Blur image with random noise
        for (int i = 0; i < 1024; i++)
        {
            image[i] = (image[i] + rand() % 10) / 10;
        }
    }
    else if (strcmp(filter, "sharpen") == 0)
    {
        // Sharpen image with edge detection
        for (int i = 0; i < 1024; i++)
        {
            image[i] = (image[i] - rand() % 5) * 2 + image[i];
        }
    }
    else if (strcmp(filter, "noise") == 0)
    {
        // Add random noise to image
        for (int i = 0; i < 1024; i++)
        {
            image[i] += rand() % 10;
        }
    }

    printf("Image after filter: \n");
    printf("%s", image);

    free(image);
    free(filter);

    return 0;
}