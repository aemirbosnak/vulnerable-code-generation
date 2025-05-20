//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_DELAY_MS 5000

typedef struct {
    float *buffer;
    int buffer_size;
    int write_index;
    int read_index;
    int delay_ms;
} DelayLine;

void init_delay_line(DelayLine *delay_line, int delay_ms) {
    delay_line->buffer_size = BUFFER_SIZE;
    delay_line->delay_ms = delay_ms;
    delay_line->buffer = (float *) malloc(delay_line->buffer_size * sizeof(float));
    if (delay_line->buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate delay line buffer.\n");
        exit(1);
    }
    delay_line->write_index = 0;
    delay_line->read_index = 0;
}

void free_delay_line(DelayLine *delay_line) {
    free(delay_line->buffer);
}

void process_audio(float *input_buffer, float *output_buffer, int buffer_size, DelayLine *delay_line) {
    int i;
    for (i = 0; i < buffer_size; i++) {
        float delay_time = (float) delay_line->delay_ms / 1000.0f;
        int delay_samples = round(delay_time * SAMPLE_RATE);
        int read_index = (delay_line->write_index - delay_samples) % delay_line->buffer_size;
        float delayed_sample = delay_line->buffer[read_index];
        float dry_sample = input_buffer[i];
        float wet_sample = delayed_sample;
        output_buffer[i] = dry_sample + wet_sample;
        delay_line->buffer[delay_line->write_index] = input_buffer[i];
        delay_line->write_index = (delay_line->write_index + 1) % delay_line->buffer_size;
    }
}

void *audio_thread(void *arg) {
    DelayLine *delay_line = (DelayLine *) arg;
    float *input_buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));
    float *output_buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));
    if (input_buffer == NULL || output_buffer == NULL) {
        fprintf(stderr, "Error: Failed to allocate audio buffers.\n");
        exit(1);
    }
    while (1) {
        int bytes_read = fread(input_buffer, sizeof(float), BUFFER_SIZE, stdin);
        if (bytes_read!= BUFFER_SIZE) {
            fprintf(stderr, "Error: Failed to read audio data.\n");
            exit(1);
        }
        process_audio(input_buffer, output_buffer, BUFFER_SIZE, delay_line);
        fwrite(output_buffer, sizeof(float), BUFFER_SIZE, stdout);
    }
}

int main() {
    int delay_ms;
    printf("Enter delay time in milliseconds: ");
    scanf("%d", &delay_ms);
    if (delay_ms > MAX_DELAY_MS) {
        fprintf(stderr, "Error: Delay time is too long.\n");
        exit(1);
    }
    DelayLine delay_line;
    init_delay_line(&delay_line, delay_ms);
    pthread_t audio_thread_id;
    pthread_create(&audio_thread_id, NULL, audio_thread, &delay_line);
    while (1) {
        int bytes_written = fwrite("\0", sizeof(char), 1, stdout);
        if (bytes_written!= 1) {
            fprintf(stderr, "Error: Failed to write silence.\n");
            exit(1);
        }
        sleep(1);
    }
    return 0;
}