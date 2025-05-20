//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Audio processing function to increase volume */

int16_t *increase_volume(int16_t *samples, int num_samples, float volume_factor) {
    int16_t *new_samples = malloc(num_samples * sizeof(int16_t));
    if (!new_samples) {
        printf("Memory allocation error\n");
        exit(1);
    }
    for (int i = 0; i < num_samples; i++) {
        new_samples[i] = samples[i] * volume_factor;
    }
    return new_samples;
}

/* Audio processing function to reverse samples */

int16_t *reverse_samples(int16_t *samples, int num_samples) {
    int16_t *new_samples = malloc(num_samples * sizeof(int16_t));
    if (!new_samples) {
        printf("Memory allocation error\n");
        exit(1);
    }
    for (int i = num_samples - 1, j = 0; i >= 0; i--, j++) {
        new_samples[j] = samples[i];
    }
    return new_samples;
}

int main() {
    int16_t samples[] = {100, 200, 300, 400, 500};
    int num_samples = sizeof(samples) / sizeof(samples[0]);
    float volume_factor = 1.5;

    printf("Original samples: ");
    for (int i = 0; i < num_samples; i++) {
        printf("%d ", samples[i]);
    }
    printf("\n");

    int16_t *new_samples = increase_volume(samples, num_samples, volume_factor);

    printf("Increased volume samples: ");
    for (int i = 0; i < num_samples; i++) {
        printf("%d ", new_samples[i]);
    }
    printf("\n");

    int16_t *reversed_samples = reverse_samples(samples, num_samples);

    printf("Reversed samples: ");
    for (int i = 0; i < num_samples; i++) {
        printf("%d ", reversed_samples[i]);
    }
    printf("\n");

    free(new_samples);
    free(reversed_samples);

    return 0;
}