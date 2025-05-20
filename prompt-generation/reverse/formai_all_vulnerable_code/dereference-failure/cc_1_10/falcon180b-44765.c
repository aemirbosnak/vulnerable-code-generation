//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} Buffer;

Buffer createBuffer(int size) {
    Buffer buffer = {
       .data = malloc(size * sizeof(float)),
       .size = size
    };
    if (buffer.data == NULL) {
        printf("Error: Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

void destroyBuffer(Buffer *buffer) {
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
}

void fillBufferWithNoise(Buffer *buffer) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = rand() / RAND_MAX;
    }
}

void applyGain(Buffer *buffer, float gain) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] *= gain;
    }
}

void applyReverb(Buffer *buffer, float roomSize, float damping) {
    const float A0 = 0.5;
    const float A1 = 0.5 + 0.5 * damping;
    const float A2 = 0.5 - 0.5 * damping;
    const float T60 = 60.0 / (2.0 * roomSize);
    const float tau = T60 / SAMPLE_RATE;
    const float alpha = 1.0 - A1 * exp(-1.0 / tau) - A2 * exp(-2.0 / tau);
    float *data = buffer->data;
    float *end = data + buffer->size;
    while (data < end) {
        float x = *data++;
        float y = *data++;
        float z = *data++;
        float r = (1.0 - alpha) * x + alpha * (y + z);
        float l = (1.0 - alpha) * y + alpha * (z + x);
        *data++ = r;
        *data++ = l;
    }
}

void applyDelay(Buffer *buffer, int delaySamples) {
    int bufferSize = buffer->size;
    int delay = delaySamples % bufferSize;
    float *data = buffer->data;
    float *end = data + bufferSize;
    while (data < end) {
        float *dest = data + delay;
        float *src = data;
        while (src < end) {
            *dest++ = *src++;
        }
        data += bufferSize;
    }
}

int main() {
    Buffer inputBuffer = createBuffer(BUFFER_SIZE);
    Buffer outputBuffer = createBuffer(BUFFER_SIZE);
    fillBufferWithNoise(&inputBuffer);

    float gain = 0.5;
    float roomSize = 0.8;
    float damping = 0.7;

    applyGain(&inputBuffer, gain);
    applyReverb(&inputBuffer, roomSize, damping);
    applyDelay(&inputBuffer, 1000);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        outputBuffer.data[i] = inputBuffer.data[i];
    }

    destroyBuffer(&inputBuffer);
    destroyBuffer(&outputBuffer);

    return 0;
}