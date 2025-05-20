//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w;
    int h;
    char *data;
} Bitmap;

Bitmap *bitmap_new(int w, int h) {
    Bitmap *bitmap = malloc(sizeof(Bitmap));
    bitmap->w = w;
    bitmap->h = h;
    bitmap->data = malloc(w * h);
    return bitmap;
}

void bitmap_free(Bitmap *bitmap) {
    free(bitmap->data);
    free(bitmap);
}

void bitmap_set_pixel(Bitmap *bitmap, int x, int y, char c) {
    if (x < 0 || x >= bitmap->w || y < 0 || y >= bitmap->h) {
        return;
    }
    bitmap->data[y * bitmap->w + x] = c;
}

char *bitmap_to_ascii(Bitmap *bitmap) {
    char *ascii = malloc(bitmap->w * bitmap->h + 1);
    int k = 0;
    for (int y = 0; y < bitmap->h; y++) {
        for (int x = 0; x < bitmap->w; x++) {
            ascii[k++] = bitmap->data[y * bitmap->w + x];
        }
        ascii[k++] = '\n';
    }
    ascii[k] = '\0';
    return ascii;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buf = malloc(size + 1);
    if (fread(buf, 1, size, fp) != size) {
        perror("fread");
        return 1;
    }
    fclose(fp);
    buf[size] = '\0';

    Bitmap *bitmap = bitmap_new(80, 25);
    int x = 0;
    int y = 0;
    for (int i = 0; i < size; i++) {
        char c = buf[i];
        if (c == '\n') {
            x = 0;
            y++;
        } else {
            bitmap_set_pixel(bitmap, x++, y, c);
        }
    }

    char *ascii = bitmap_to_ascii(bitmap);
    printf("%s", ascii);
    free(ascii);
    bitmap_free(bitmap);
    free(buf);

    return 0;
}