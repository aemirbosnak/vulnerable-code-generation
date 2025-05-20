//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char* data;
    int size;
} Image;

void read_image(Image* img, char* filename) {
    FILE* fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    img->size = ftell(fp);
    rewind(fp);
    img->data = malloc(img->size);
    fread(img->data, img->size, 1, fp);
    fclose(fp);
}

void write_image(Image* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    fwrite(img->data, img->size, 1, fp);
    fclose(fp);
}

void hide_data(Image* img, char* data, int datalen) {
    int i = 0;
    int j = 0;
    while (i < img->size && j < datalen) {
        if (img->data[i] == '\0') {
            img->data[i] = data[j];
            i++;
            j++;
        } else {
            i++;
        }
    }
}

void extract_data(Image* img, char* data, int datalen) {
    int i = 0;
    int j = 0;
    while (i < img->size && j < datalen) {
        if (img->data[i]!= '\0') {
            data[j] = img->data[i];
            i++;
            j++;
        } else {
            i++;
        }
    }
}

int main() {
    Image cover, stego;
    char* cover_filename = "cover.jpg";
    char* stego_filename = "stego.jpg";
    char* data_to_hide = "This is a secret message.";
    int datalen = strlen(data_to_hide);

    read_image(&cover, cover_filename);
    hide_data(&cover, data_to_hide, datalen);
    write_image(&cover, stego_filename);

    printf("Data hidden successfully!\n");

    return 0;
}