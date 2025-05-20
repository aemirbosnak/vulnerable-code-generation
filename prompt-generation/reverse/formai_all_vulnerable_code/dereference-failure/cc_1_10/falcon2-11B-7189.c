//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <portaudio.h>
#include <math.h>

// Function prototypes
void error_callback(const PaStreamCallbackTimeInfo* timeinfo,
                    const PaError* err, void* user_data);
void data_callback(const void* input_buffer, void* output_buffer,
                     unsigned long frames_per_buffer,
                     const PaStreamCallbackTimeInfo* timeinfo,
                     void* user_data);

int main(int argc, char** argv) {
    // Create a portaudio stream
    PaStreamParameters input_params;
    input_params.device = Pa_GetDefaultInputDevice();
    input_params.channelCount = 1;
    input_params.sampleFormat = paFloat32;
    input_params.suggestedLatency = Pa_GetDeviceInfo(input_params.device)->defaultLowInputLatency;

    PaStream* input_stream = Pa_OpenStream(
        &input_params, NULL, &input_params, 44100, paFloat32,
        data_callback, NULL, &error_callback);

    // Check for errors
    if (input_stream == NULL) {
        printf("Error opening stream: %s\n", Pa_GetErrorText(input_stream));
        return 1;
    }

    // Play the audio
    printf("Press Enter to stop recording\n");
    getchar();

    // Close the stream
    Pa_CloseStream(input_stream);

    // Cleanup
    Pa_Terminate();

    return 0;
}

// Error callback function
void error_callback(const PaStreamCallbackTimeInfo* timeinfo,
                    const PaError* err, void* user_data) {
    fprintf(stderr, "Error in stream callback: %s\n",
            Pa_GetErrorText(err));
}

// Data callback function
void data_callback(const void* input_buffer, void* output_buffer,
                     unsigned long frames_per_buffer,
                     const PaStreamCallbackTimeInfo* timeinfo,
                     void* user_data) {
    const float* input_data = (const float*)input_buffer;
    float* output_data = (float*)output_buffer;

    // Convert the input data to a sine wave
    const float sample_rate = 44100.0f;
    const float frequency = 440.0f;
    const float amplitude = 0.1f;
    const float offset = 0.0f;

    for (unsigned long i = 0; i < frames_per_buffer; i++) {
        output_data[i] = input_data[i] * amplitude * sin(2 * M_PI * frequency * (i / sample_rate) + offset);
    }
}