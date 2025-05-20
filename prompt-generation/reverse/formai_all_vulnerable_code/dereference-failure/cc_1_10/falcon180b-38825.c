//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_DELAY_MS 1000

typedef struct {
    float *buffer;
    int position;
    int delay_time_ms;
} DelayLine;

int main() {
    int i;
    float freq, amp, phase, feedback;
    DelayLine delay_line;
    delay_line.buffer = (float *)malloc(BUFFER_SIZE * sizeof(float));
    for (i = 0; i < BUFFER_SIZE; i++) {
        delay_line.buffer[i] = 0.0;
    }
    delay_line.position = 0;
    delay_line.delay_time_ms = 500;

    while (1) {
        printf("Enter frequency (Hz): ");
        scanf("%f", &freq);
        printf("Enter amplitude: ");
        scanf("%f", &amp);
        printf("Enter phase (degrees): ");
        scanf("%f", &phase);
        printf("Enter feedback: ");
        scanf("%f", &feedback);

        for (i = 0; i < BUFFER_SIZE; i++) {
            float sample = 0.0;
            float delayed_sample = delay_line.buffer[(delay_line.position + i) % BUFFER_SIZE];
            sample += amp * sin(2 * M_PI * freq * (i / SAMPLE_RATE) + phase);
            sample += feedback * delayed_sample;
            delay_line.buffer[delay_line.position] = sample;
            delay_line.position = (delay_line.position + 1) % BUFFER_SIZE;
        }

        for (i = 0; i < BUFFER_SIZE; i++) {
            printf("%f ", delay_line.buffer[i]);
        }
        printf("\n");
    }

    return 0;
}