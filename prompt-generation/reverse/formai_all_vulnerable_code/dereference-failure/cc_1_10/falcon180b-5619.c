//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10

typedef struct {
    char name[50];
    int count;
} class_t;

class_t classes[MAX_CLASSES];
int num_classes;

void add_class(char* name) {
    int i;
    for(i = 0; i < num_classes; i++) {
        if(strcmp(classes[i].name, name) == 0) {
            classes[i].count++;
            return;
        }
    }
    if(num_classes >= MAX_CLASSES) {
        printf("Error: maximum number of classes reached\n");
        exit(1);
    }
    strcpy(classes[num_classes].name, name);
    classes[num_classes].count = 1;
    num_classes++;
}

void print_classes() {
    int i;
    for(i = 0; i < num_classes; i++) {
        printf("%s: %d\n", classes[i].name, classes[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    unsigned char header[3];
    fread(header, 1, 3, fp);
    if(header[0]!= 0xFF || header[1]!= 0xD8 || header[2]!= 0xFF) {
        printf("Error: not a valid JPEG file\n");
        exit(1);
    }

    int width, height;
    fseek(fp, 0xA0, SEEK_SET);
    fread(&width, 2, 1, fp);
    fread(&height, 2, 1, fp);

    unsigned char* data = malloc(3 * width * height);
    fseek(fp, 0xDA, SEEK_SET);
    fread(data, 1, 3 * width * height, fp);
    fclose(fp);

    int num_pixels = width * height;
    int red_count = 0, green_count = 0, blue_count = 0;
    int max_count = 0;
    int dominant_color = -1;

    for(int i = 0; i < num_pixels; i++) {
        int r = data[i*3+0];
        int g = data[i*3+1];
        int b = data[i*3+2];
        if(r > 128) {
            red_count++;
        }
        if(g > 128) {
            green_count++;
        }
        if(b > 128) {
            blue_count++;
        }
        if(red_count > max_count) {
            max_count = red_count;
            dominant_color = 0;
        } else if(green_count > max_count) {
            max_count = green_count;
            dominant_color = 1;
        } else if(blue_count > max_count) {
            max_count = blue_count;
            dominant_color = 2;
        }
    }

    add_class("red");
    add_class("green");
    add_class("blue");
    print_classes();

    if(dominant_color == 0) {
        printf("The image is mostly red.\n");
    } else if(dominant_color == 1) {
        printf("The image is mostly green.\n");
    } else {
        printf("The image is mostly blue.\n");
    }

    free(data);
    return 0;
}