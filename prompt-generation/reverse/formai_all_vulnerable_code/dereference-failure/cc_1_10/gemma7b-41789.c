//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char img[] = "C Image to ASCII Art Converter";
    int i, j, k, l, n, m;
    printf("%s\n", img);

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    char **arr = (char **)malloc(n * sizeof(char *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the image data (separated by spaces): ");
    scanf("%[^\n]%*c", arr);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            switch (arr[i][j])
            {
                case '0':
                    printf(". ");
                    break;
                case '1':
                    printf("O ");
                    break;
                case '2':
                    printf("* ");
                    break;
                case '3':
                    printf("# ");
                    break;
                default:
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }

    free(arr);
    return 0;
}