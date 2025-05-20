//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int main() {
    FILE *fp;
    char filename[100] = "qrcode.png";
    char buffer[100];
    int width, height, i, j, n, x, y, count = 0;
    Point *points = NULL;
    unsigned char *data;
    size_t size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    data = (unsigned char*) malloc(size);
    fread(data, size, 1, fp);
    fclose(fp);

    width = (int) (sqrt((double) size / 3.0));
    height = width;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (data[(i * width + j) * 3] == 0 && data[(i * width + j) * 3 + 1] == 0 && data[(i * width + j) * 3 + 2] == 0) {
                points = (Point*) realloc(points, sizeof(Point) * ++count);
                points[count - 1].x = j;
                points[count - 1].y = i;
            }
        }
    }

    printf("Found %d points:\n", count);
    for (n = 0; n < count; n++) {
        printf("(%d, %d)\n", points[n].x, points[n].y);
    }

    free(data);
    free(points);

    return 0;
}