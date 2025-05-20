//FormAI DATASET v1.0 Category: Audio processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "portaudio.h"

#define SAMPLE_RATE 44100
#define BLOCK_SIZE 1024
#define NUM_CHANNELS 2
#define MAX_DELAY_MS 50
#define DELAY_BUFFER_LEN (SAMPLE_RATE * MAX_DELAY_MS / 1000)

typedef struct {
    float input_buffer[BLOCK_SIZE * NUM_CHANNELS];
    float output_buffer[BLOCK_SIZE * NUM_CHANNELS];
    float delay_buffer[DELAY_BUFFER_LEN * NUM_CHANNELS];
    int delay_pos;
    float delay_gain;
} paUserData;

static int paCallback(const void* input, void* output, unsigned long frameCount,
                      const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
                      void* userData) {
    paUserData* data = (paUserData*)userData;
    float* in = (float*)input;
    float* out = (float*)output;
    int i, j;
    for (i = 0; i < frameCount; i++) {
        // Copy input samples into delay buffer
        for (j = 0; j < NUM_CHANNELS; j++) {
            data->delay_buffer[data->delay_pos * NUM_CHANNELS + j] =
                in[i * NUM_CHANNELS + j] + data->delay_gain * data->output_buffer[i * NUM_CHANNELS + j];
        }
        // Apply delay effect to output samples
        for (j = 0; j < NUM_CHANNELS; j++) {
            float y = data->delay_buffer[(data->delay_pos - DELAY_BUFFER_LEN / 2) * NUM_CHANNELS + j];
            y += data->delay_buffer[(data->delay_pos - (int)(DELAY_BUFFER_LEN / 3)) * NUM_CHANNELS + j] * 0.5f;
            y += data->delay_buffer[(data->delay_pos - (int)(DELAY_BUFFER_LEN / 4)) * NUM_CHANNELS + j] * 0.25f;
            y += data->delay_buffer[(data->delay_pos - (int)(DELAY_BUFFER_LEN / 5)) * NUM_CHANNELS + j] * 0.125f;
            y += data->delay_buffer[(data->delay_pos - (int)(DELAY_BUFFER_LEN / 6)) * NUM_CHANNELS + j] * 0.0625f;
            data->output_buffer[i * NUM_CHANNELS + j] = y;
        }
        // Update delay buffer write position
        data->delay_pos = (data->delay_pos + 1) % DELAY_BUFFER_LEN;
    }
    // Copy processed samples to output buffer
    for (i = 0; i < frameCount; i++) {
        for (j = 0; j < NUM_CHANNELS; j++) {
            out[i * NUM_CHANNELS + j] = data->output_buffer[i * NUM_CHANNELS + j];
        }
    }
    return paContinue;
}

int main() {
    PaStreamParameters inputParams, outputParams;
    PaStream* stream;
    paUserData data;
    int i;
    // Initialize PortAudio
    Pa_Initialize();
    // Configure input/output stream parameters
    inputParams.device = Pa_GetDefaultInputDevice();
    inputParams.channelCount = NUM_CHANNELS;
    inputParams.sampleFormat = paFloat32;
    inputParams.suggestedLatency = Pa_GetDeviceInfo(inputParams.device)->defaultLowInputLatency;
    inputParams.hostApiSpecificStreamInfo = NULL;
    outputParams.device = Pa_GetDefaultOutputDevice();
    outputParams.channelCount = NUM_CHANNELS;
    outputParams.sampleFormat = paFloat32;
    outputParams.suggestedLatency = Pa_GetDeviceInfo(outputParams.device)->defaultLowOutputLatency;
    outputParams.hostApiSpecificStreamInfo = NULL;
    // Initialize delay buffer and gain
    data.delay_pos = 0;
    data.delay_gain = 0.5f;
    for (i = 0; i < DELAY_BUFFER_LEN * NUM_CHANNELS; i++) {
        data.delay_buffer[i] = 0.0f;
    }
    // Open input/output stream with callback function
    Pa_OpenStream(&stream, &inputParams, &outputParams, SAMPLE_RATE, BLOCK_SIZE,
                  paClipOff, paCallback, &data);
    // Start audio stream
    Pa_StartStream(stream);
    printf("Processing audio (press Enter to stop)...\n");
    getchar();
    // Stop and close audio stream
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    // Terminate PortAudio
    Pa_Terminate();
    return 0;
}