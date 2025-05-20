//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define pi 3.14159265358979323846
#define SIZE 1024

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

void generateRandomRectangle(Rectangle *rect) {
    srand(time(NULL));
    rect->topLeft.row = rand() % SIZE;
    rect->topLeft.col = rand() % SIZE;
    rect->bottomRight.row = rect->topLeft.row + rand() % SIZE;
    rect->bottomRight.col = rect->topLeft.col + rand() % SIZE;
}

void generateRandomPoints(Point *points, int numPoints, Rectangle rect) {
    for (int i = 0; i < numPoints; i++) {
        points[i].row = rand() % rect.bottomRight.row;
        points[i].col = rand() % rect.bottomRight.col;
    }
}

int isInsideRectangle(Point point, Rectangle rect) {
    if (point.row >= rect.topLeft.row && point.row <= rect.bottomRight.row &&
        point.col >= rect.topLeft.col && point.col <= rect.bottomRight.col) {
        return 1;
    }
    return 0;
}

int isInsideCircle(Point point, Point center, int radius) {
    int distance = sqrt(pow(point.row - center.row, 2) + pow(point.col - center.col, 2));
    if (distance <= radius) {
        return 1;
    }
    return 0;
}

void encryptFile(char *filename, Rectangle rect, int numPoints, Point *points) {
    FILE *file;
    char buffer[1024];
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), file)) {
        int i = 0;
        while (buffer[i]!= '\n') {
            if (isalpha(buffer[i])) {
                if (isInsideRectangle(points[i % numPoints], rect)) {
                    buffer[i] = toupper(buffer[i]);
                } else {
                    buffer[i] = tolower(buffer[i]);
                }
            }
            i++;
        }
        fprintf(stdout, "%s", buffer);
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    Rectangle rect;
    Point points[100];
    generateRandomRectangle(&rect);
    generateRandomPoints(points, 100, rect);
    encryptFile("input.txt", rect, 100, points);
    return 0;
}