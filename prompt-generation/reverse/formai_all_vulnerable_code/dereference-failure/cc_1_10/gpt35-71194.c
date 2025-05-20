//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

char *toBin(int num) {
    char *bin = (char *) malloc(sizeof(char) * 8);
    int i = 7;
    while(num > 0) {
        bin[i--] = (num % 2) + '0';
        num /= 2;
    }
    while(i >= 0) {
        bin[i--] = '0';
    }
    return bin;
}

int toDecimal(char *bin) {
    int d = 0, i;
    for(i = 0; i < 8; i++) {
        d = 2 * d + (bin[i] - '0');
    }
    return d;
}

void hideData(RGB *pixels, int n, char *data, int len) {
    int i, j, k, l = 0;
    char *ch, *bin;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            ch = (char *) &pixels[i * n + j];
            for(k = 0; k < 3; k++) {
                if(l < len) {
                    bin = toBin(data[l++]);
                    bin[strlen(bin)] = '\0';
                } else {
                    bin = toBin(0);
                }
                bin[strlen(bin)] = '\0';
                ch[k] = (ch[k] & 0xFE) | (bin[0] - '0');
                ch[k + 1] = (ch[k + 1] & 0xFE) | (bin[1] - '0');
                ch[k + 2] = (ch[k + 2] & 0xFE) | (bin[2] - '0');
                k += 2;
            }
        }
    }
    printf("Data hidden successfully!\n");
}

char *retrieveData(RGB *pixels, int n, int len) {
    int i, j, k, l = 0, d;
    char *data = (char *) malloc(sizeof(char) * (len + 1));
    char *bin = (char *) malloc(sizeof(char) * 8);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            char *ch = (char *) &pixels[i * n + j];
            for(k = 0; k < 3; k++) {
                bin[k] = ((ch[k] & 1) + '0');
            }
            bin[k] = '\0';
            d = toDecimal(bin);
            if(l < len) {
                data[l++] = (char) d;
            }
        }
    }
    data[l] = '\0';
    return data;
}

int main() {
    // read image
    FILE * in = fopen("input.bmp", "rb");
    FILE * out = fopen("output.bmp", "wb+");
    int i, j, k, n, width, height, **image;
    char *data = "This is an example of steganography!";
    n = 512;
    RGB *pixels = (RGB *) malloc(sizeof(RGB) * n * n);

    // get image width and height
    fseek(in, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, in);
    fread(&height, sizeof(int), 1, in);
    printf("Image dimensions: %d x %d\n", width, height);

    // skip color table and read pixels
    fseek(in, 54, SEEK_SET);
    fread(pixels, sizeof(RGB), n * n, in);

    // hide data in image
    hideData(pixels, n, data, strlen(data));

    // write pixels to new file
    fseek(out, 0, SEEK_SET);
    fwrite(pixels, sizeof(RGB), n * n, out);

    // retrieve data from image
    char *retrievedData = retrieveData(pixels, n, strlen(data));
    printf("Retrieved data: %s\n", retrievedData);

    fclose(in);
    fclose(out);
    return 0;
}