//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int len;
} watermark;

watermark *create_watermark(char *data, int len) {
    watermark *wm = malloc(sizeof(watermark));
    wm->data = data;
    wm->len = len;
    return wm;
}

void destroy_watermark(watermark *wm) {
    free(wm->data);
    free(wm);
}

void embed_watermark(char *image, int image_len, watermark *wm) {
    for (int i = 0; i < wm->len; i++) {
        image[i] = image[i] ^ wm->data[i];
    }
}

void extract_watermark(char *image, int image_len, watermark *wm) {
    for (int i = 0; i < wm->len; i++) {
        wm->data[i] = image[i] ^ wm->data[i];
    }
}

int main() {
    char *image = "This is a secret image.";
    int image_len = strlen(image);

    char *watermark_data = "This is a secret watermark.";
    int watermark_len = strlen(watermark_data);

    watermark *wm = create_watermark(watermark_data, watermark_len);

    embed_watermark(image, image_len, wm);

    printf("Watermarked image: %s\n", image);

    watermark *extracted_wm = create_watermark(malloc(watermark_len), watermark_len);

    extract_watermark(image, image_len, extracted_wm);

    if (strcmp(extracted_wm->data, watermark_data) == 0) {
        printf("Watermark successfully extracted.\n");
    } else {
        printf("Watermark extraction failed.\n");
    }

    destroy_watermark(wm);
    destroy_watermark(extracted_wm);

    return 0;
}