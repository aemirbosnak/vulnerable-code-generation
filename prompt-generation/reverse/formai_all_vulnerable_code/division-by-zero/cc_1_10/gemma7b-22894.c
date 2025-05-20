//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y, z, w, h, r, g, b;
    char c;
    int n = 0;
    int m = 0;

    system("clear");

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    w = rand() % r;
    h = rand() % c;

    printf("The weather is changing...\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            x = rand() % 2;
            y = rand() % 2;

            switch (x)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("O");
                    break;
            }

            switch (y)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("|");
                    break;
            }

            printf(" ");
        }

        printf("\n");
    }

    printf("The weather has settled.\n");

    return 0;
}