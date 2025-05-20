//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WATERMARK_LEN 256

typedef struct watermark_t {
    char *data;
    int size;
} watermark_t;

void watermark_init(watermark_t *wm, int size) {
    wm->data = malloc(size);
    wm->size = size;
}

int watermark_add(watermark_t *wm, char *watermarked_data) {
    int i = 0;
    for (i = 0; i < wm->size && watermarked_data[i] != '\0'; i++) {
        wm->data[i] = (watermarked_data[i] & 0x1F) ^ 0x1F;
    }
    return 0;
}

int watermark_detect(watermark_t *wm, char *data) {
    int i = 0;
    for (i = 0; i < wm->size && data[i] != '\0'; i++) {
        if (wm->data[i] != (data[i] & 0x1F) ^ 0x1F) {
            return -1;
        }
    }
    return 0;
}

int main() {
     watermark_t wm;
    watermark_init(&wm, MAX_WATERMARK_LEN);

    char *watermarked_data = "This is a watermarked message.";
    watermark_add(&wm, watermarked_data);

    char *data = "This is a message.";
    if (watermark_detect(&wm, data) == 0) {
        printf("Watermarked message detected.\n");
    } else {
        printf("No watermark detected.\n");
    }

    return 0;
}