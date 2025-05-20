//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int width, height, size, max_val, val;
    char filename[100];
    FILE *fp;
    unsigned char *data;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    data = (unsigned char *) malloc(size);
    if (data == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    fread(data, size, 1, fp);
    fclose(fp);

    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    if (width > MAX_SIZE || height > MAX_SIZE) {
        printf("Error: image dimensions are too large.\n");
        exit(1);
    }

    max_val = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    printf("Enter new maximum value (0-255): ");
    scanf("%d", &val);

    for (int i = 0; i < size; i++) {
        data[i] = (unsigned char) (255 * (data[i] - max_val) / (max_val - 0) + val);
    }

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fwrite(data, size, 1, fp);
    fclose(fp);

    printf("Image saved.\n");

    return 0;
}