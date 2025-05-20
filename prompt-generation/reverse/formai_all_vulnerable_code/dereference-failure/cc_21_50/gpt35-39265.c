//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to our C Image Editor!\n");

    int width, height, choice;

    printf("Enter the width and height of the image:\n");
    scanf("%d %d", &width, &height);

    // Allocate memory for image matrix
    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        image[i] = (int *)malloc(width * sizeof(int));

    // Initialize image matrix with zeros
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = 0;
        }
    }

    // Display menu
    printf("\nMenu:\n");
    printf("1. Draw a line\n");
    printf("2. Draw a circle\n");
    printf("3. Draw a square\n");
    printf("4. Exit\n");

    // Loop until user chooses "Exit"
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Draw a line
                printf("\nEnter line start and end points (x1 y1 x2 y2):\n");
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                // Draw the line
                for (int i = y1; i <= y2; i++)
                {
                    int j = x1 + (x2 - x1) * (i - y1) / (y2 - y1);
                    image[i][j] = 1;
                }

                // Print image matrix
                printf("\nImage matrix:\n");
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
            
            case 2:
                // Draw a circle
                printf("\nEnter circle center and radius (x y r):\n");
                int x, y, r;
                scanf("%d %d %d", &x, &y, &r);

                // Draw the circle
                for (int i = y - r; i <= y + r; i++)
                {
                    for (int j = x - r; j <= x + r; j++)
                    {
                        if ((i - y) * (i - y) + (j - x) * (j - x) <= r * r)
                            image[i][j] = 1;
                    }
                }

                // Print image matrix
                printf("\nImage matrix:\n");
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                // Draw a square
                printf("\nEnter square top-left corner and side length (x y s):\n");
                int x_tl, y_tl, s;
                scanf("%d %d %d", &x_tl, &y_tl, &s);

                // Draw the square
                for (int i = y_tl; i < y_tl + s; i++)
                {
                    for (int j = x_tl; j < x_tl + s; j++)
                    {
                        image[i][j] = 1;
                    }
                }

                // Print image matrix
                printf("\nImage matrix:\n");
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                // Exit the program
                printf("\nThank you for using our C Image Editor!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}