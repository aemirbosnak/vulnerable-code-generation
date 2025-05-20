//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int width, height, size;
    char *filename;

    // surrealist prompt
    printf("Enter the width of your surrealist landscape (1-100): ");
    scanf("%d", &width);

    printf("Enter the height of your surrealist landscape (1-100): ");
    scanf("%d", &height);

    printf("Enter the size of your surrealist landscape (1-10): ");
    scanf("%d", &size);

    // generate surrealist landscape
    int **landscape = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        landscape[i] = (int *)malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            landscape[i][j] = rand() % size + 1;
        }
    }

    // surrealist prompt
    printf("Enter the filename for your surrealist landscape (without extension): ");
    scanf("%s", filename);

    // write QR code to file
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, size);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%d ", landscape[i][j]);
        }
    }
    fclose(fp);

    // surrealist prompt
    printf("Your surrealist landscape has been saved as %s.pbm\n", filename);

    return 0;
}