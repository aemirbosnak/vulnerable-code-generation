//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMG_SIZE 1024
#define MAX_CLASSES 10
#define MAX_IMG_CLASSES 50

typedef struct {
    char* name;
    int count;
    int* classes;
} Image;

typedef struct {
    char* name;
    int count;
} Class;

void loadImage(Image* img, char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    img->name = malloc(strlen(filename) + 1);
    strcpy(img->name, filename);
    img->count = 1;
    img->classes = calloc(MAX_IMG_CLASSES, sizeof(int));
    unsigned char* buffer = malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);
}

void loadClass(Class* cls, char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    cls->name = malloc(strlen(filename) + 1);
    strcpy(cls->name, filename);
    cls->count = 1;
    unsigned char* buffer = malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);
}

void addClass(Image* img, Class* cls) {
    int i;
    for (i = 0; i < img->count; i++) {
        if (img->classes[i] == cls->count) {
            break;
        }
    }
    if (i == img->count) {
        img->classes[i] = cls->count;
        img->count++;
    }
}

int main() {
    Image img1, img2;
    Class cls1, cls2;

    loadImage(&img1, "img1.jpg");
    loadImage(&img2, "img2.jpg");

    loadClass(&cls1, "class1.txt");
    loadClass(&cls2, "class2.txt");

    addClass(&img1, &cls1);
    addClass(&img1, &cls2);

    addClass(&img2, &cls1);

    return 0;
}