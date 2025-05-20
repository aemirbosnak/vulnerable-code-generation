//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (512)

typedef struct {
    float left_phase;
    float right_phase;
    float frequency;
} sine_data;

typedef struct {
    float lowpass_state;
    float highpass_state;
} filter_data;

static int sine_callback(const void *input_buffer, void *output_buffer,
                         unsigned long frames_per_buffer,
                         const PaStreamCallbackTimeInfo* time_info,
                         PaStreamCallbackFlags status_flags,
                         void *user_data ) {
    sine_data *sine = (sine_data*)user_data;
    float *out = (float*)output_buffer;
    unsigned int i;
    
    for (i = 0; i < frames_per_buffer; i++) {
        *out++ = sinf(2 * M_PI * sine->frequency * sine->left_phase);
        *out++ = sinf(2 * M_PI * sine->frequency * sine->right_phase);
        sine->left_phase += 1.0f / SAMPLE_RATE;
        sine->right_phase += 1.1f / SAMPLE_RATE;
    }
    
    return 0;
}

static int filter_callback(const void *input_buffer, void *output_buffer,
                           unsigned long frames_per_buffer,
                           const PaStreamCallbackTimeInfo* time_info,
                           PaStreamCallbackFlags status_flags,
                           void *user_data ) {
    filter_data *filter = (filter_data*)user_data;
    float *in = (float*)input_buffer;
    float *out = (float*)output_buffer;
    unsigned int i;
    
    for (i = 0; i < frames_per_buffer; i++) {
        float input = in[2*i];
        
        /* High-pass filter */
        float highpass_output = input - filter->highpass_state;
        filter->highpass_state += 0.01f * highpass_output;
        
        /* Low-pass filter */
        float lowpass_output = filter->lowpass_state + 0.01f * (input - filter->lowpass_state);
        filter->lowpass_state = lowpass_output;
        
        out[2*i] = highpass_output;
        out[2*i+1] = lowpass_output;
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    PaStreamParameters input_params, output_params;
    PaStream *stream;
    PaError err;
    
    sine_data sine = {0, 0, 440.0f};
    filter_data filter = {0, 0};
    
    /* Initialize PortAudio */
    err = Pa_Initialize();
    if (err != paNoError) goto error;
    
    /* Setup input stream */
    input_params.device = Pa_GetDefaultInputDevice();
    input_params.channelCount = 2;
    input_params.sampleFormat = paFloat32;
    input_params.suggestedLatency = Pa_GetDeviceInfo(input_params.device)->defaultLowInputLatency;
    input_params.hostApiSpecificStreamInfo = NULL;
    
    /* Setup output stream */
    output_params.device = Pa_GetDefaultOutputDevice();
    output_params.channelCount = 2;
    output_params.sampleFormat = paFloat32;
    output_params.suggestedLatency = Pa_GetDeviceInfo(output_params.device)->defaultLowOutputLatency;
    output_params.hostApiSpecificStreamInfo = NULL;
    
    /* Open stream */
    err = Pa_OpenStream(&stream,
                        &input_params,
                        &output_params,
                        SAMPLE_RATE,
                        FRAMES_PER_BUFFER,
                        paClipOff,
                        filter_callback,
                        &filter);
    if (err != paNoError) goto error;
    
    /* Start stream */
    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;
    
    printf("Press any key to exit...\n");
    getchar();
    
    /* Stop stream */
    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;
    
    /* Close stream */
    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;
    
    /* Terminate PortAudio */
    err = Pa_Terminate();
    if (err != paNoError) goto error;
    
    return 0;
    
error:
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
}