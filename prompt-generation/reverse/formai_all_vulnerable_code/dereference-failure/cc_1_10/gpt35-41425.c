//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char message[MAX_SIZE];
    int watermark[MAX_SIZE];
    int length;
} Watermark;

void add_watermark(Watermark *wm) {
    int seed = 0;
    for (int i = 0; i < wm->length; i++) {
        seed += wm->message[i];
        wm->watermark[i] = seed;
    }
}

void remove_watermark(Watermark *wm) {
    int seed = 0;
    for (int i = 0; i < wm->length; i++) {
        seed += wm->message[i];
        wm->message[i] = (wm->watermark[i] - seed < 0) ? 0 : (wm->watermark[i] - seed);
    }
}

void print_watermark(Watermark *wm) {
    printf("Message: %s\n", wm->message);
    printf("Watermark: ");
    for (int i = 0; i < wm->length; i++) {
        printf("%d ", wm->watermark[i]);
    }
    printf("\n");
}

int main() {
    Watermark *wm = (Watermark*) malloc(sizeof(Watermark));
    printf("Enter the message:\n");
    fgets(wm->message, MAX_SIZE, stdin);
    wm->length = strlen(wm->message) - 1;
    printf("Original watermark:\n");
    add_watermark(wm);
    print_watermark(wm);

    remove_watermark(wm);
    printf("Watermark removed:\n");
    printf("Message: %s\n", wm->message);

    printf("Reapplying watermark:\n");
    add_watermark(wm);
    print_watermark(wm);

    free(wm);
    return 0;
}