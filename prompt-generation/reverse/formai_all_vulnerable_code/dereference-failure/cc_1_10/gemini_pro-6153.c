//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <portaudio.h>

#define SR 44100
#define BUF_LEN 64
#define NUM_CHANNELS 2

typedef struct {
    PaStream *stream;
    float *buffer;
    int buffer_size;
    int buffer_index;
} AudioData;

void process_buffer(AudioData *data, float *input, int num_frames) {
    for (int i = 0; i < num_frames * NUM_CHANNELS; i += NUM_CHANNELS) {
        float left = input[i];
        float right = input[i + 1];

        // Apply a simple delay effect
        float delayed_left = data->buffer[(data->buffer_index - 1 + data->buffer_size) % data->buffer_size];
        float delayed_right = data->buffer[(data->buffer_index - 1 + data->buffer_size) % data->buffer_size];

        // Mix the delayed signal with the original signal
        left = 0.5 * left + 0.5 * delayed_left;
        right = 0.5 * right + 0.5 * delayed_right;

        // Write the processed signal to the buffer
        data->buffer[data->buffer_index] = left;
        data->buffer[data->buffer_index + 1] = right;

        // Increment the buffer index
        data->buffer_index = (data->buffer_index + NUM_CHANNELS) % data->buffer_size;
    }
}

int main(int argc, char *argv[]) {
    // Initialize PortAudio
    PaError error = Pa_Initialize();
    if (error != paNoError) {
        fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    // Open the default audio input and output devices
    PaStreamParameters input_params, output_params;
    input_params.device = Pa_GetDefaultInputDevice();
    input_params.channelCount = NUM_CHANNELS;
    input_params.sampleFormat = paFloat32;
    input_params.suggestedLatency = Pa_GetDeviceInfo(input_params.device)->defaultLowInputLatency;
    input_params.hostApiSpecificStreamInfo = NULL;

    output_params.device = Pa_GetDefaultOutputDevice();
    output_params.channelCount = NUM_CHANNELS;
    output_params.sampleFormat = paFloat32;
    output_params.suggestedLatency = Pa_GetDeviceInfo(output_params.device)->defaultLowOutputLatency;
    output_params.hostApiSpecificStreamInfo = NULL;

    AudioData data;
    data.buffer_size = SR * NUM_CHANNELS * 2;
    data.buffer = malloc(data.buffer_size * sizeof(float));
    data.buffer_index = 0;
    

    error = Pa_OpenStream(&data.stream, &input_params, &output_params, SR, BUF_LEN, paClipOff, NULL, NULL);
    if (error != paNoError) {
        fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    // Start the stream
    error = Pa_StartStream(data.stream);
    if (error != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    // Keep the program running until the user presses Enter
    printf("Press Enter to quit.\n");
    while (getchar() != '\n') {
        // Read a buffer of audio data from the input device
        float input[BUF_LEN * NUM_CHANNELS];
        error = Pa_ReadStream(data.stream, input, BUF_LEN);
        if (error != paNoError) {
            fprintf(stderr, "Error reading stream: %s\n", Pa_GetErrorText(error));
            break;
        }

        // Process the buffer of audio data
        process_buffer(&data, input, BUF_LEN);

        // Write the processed buffer of audio data to the output device
        error = Pa_WriteStream(data.stream, data.buffer, BUF_LEN);
        if (error != paNoError) {
            fprintf(stderr, "Error writing stream: %s\n", Pa_GetErrorText(error));
            break;
        }
    }

    // Stop the stream
    error = Pa_StopStream(data.stream);
    if (error != paNoError) {
        fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    // Close the stream
    error = Pa_CloseStream(data.stream);
    if (error != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(error));
        return EXIT_FAILURE;
    }

    // Terminate PortAudio
    Pa_Terminate();

    // Free the audio buffer
    free(data.buffer);

    return EXIT_SUCCESS;
}