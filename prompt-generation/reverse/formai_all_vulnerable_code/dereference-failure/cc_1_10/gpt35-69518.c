//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>

void convertToAscii(char *filename) {
    FILE *img = fopen(filename, "rb");
    if (img == NULL) {
        printf("Error opening file");
        return;
    }
    fseek(img, 0, SEEK_END);
    int size = ftell(img);
    fseek(img, 0, SEEK_SET);
    char *buffer = (char *) malloc(size);
    fread(buffer, 1, size, img);
    fclose(img);

    printf("\nConverted to ASCII:\n\n");
    for (int i = 0; i < size; i += 3) {
        int r = buffer[i];
        int g = buffer[i + 1];
        int b = buffer[i + 2];
        int brightness = (r + g + b) / 3;
        if (brightness < 25) {
            printf("@");
        } else if (brightness < 50) {
            printf("#");
        } else if (brightness < 75) {
            printf("+");
        } else if (brightness < 100) {
            printf("*");
        } else if (brightness < 125) {
            printf("=");
        } else if (brightness < 150) {
            printf(".");
        } else if (brightness < 175) {
            printf("-");
        } else if (brightness < 200) {
            printf(":");
        } else {
            printf(" ");
        }
        if ((i / 3) % 32 == 0 && i != 0) {
            printf("\n");
        }
    }

    free(buffer);
}

int main() {
    char *imgFilename = "image.jpg";
    convertToAscii(imgFilename);
    return 0;
}