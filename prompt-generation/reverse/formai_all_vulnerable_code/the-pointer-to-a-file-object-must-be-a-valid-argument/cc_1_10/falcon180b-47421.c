//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGES 100
#define MAX_CLASSES 10

typedef struct {
    char name[50];
    int num_images;
} Class;

typedef struct {
    char filename[100];
    int label;
} Image;

Class classes[MAX_CLASSES];
Image images[MAX_IMAGES];

void read_classes(char filename[100]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(filename, "r");
    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %d", classes[i].name, &classes[i].num_images);
        i++;
    }
    fclose(fp);
}

void read_images(char filename[100]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(filename, "r");
    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %d", images[i].filename, &images[i].label);
        i++;
    }
    fclose(fp);
}

void classify_images() {
    int i, j, k;
    int num_correct = 0;

    for (i = 0; i < MAX_IMAGES; i++) {
        for (j = 0; j < MAX_CLASSES; j++) {
            k = 0;
            while (k < classes[j].num_images && strcmp(classes[j].name, images[i].filename)!= 0) {
                k++;
            }
            if (k == classes[j].num_images) {
                continue;
            }
            if (images[i].label == j) {
                num_correct++;
            }
        }
    }

    printf("Accuracy: %.2f%%\n", (float)num_correct / (MAX_IMAGES * MAX_CLASSES) * 100.0);
}

int main() {
    char classes_filename[100] = "classes.txt";
    char images_filename[100] = "images.txt";

    read_classes(classes_filename);
    read_images(images_filename);
    classify_images();

    return 0;
}