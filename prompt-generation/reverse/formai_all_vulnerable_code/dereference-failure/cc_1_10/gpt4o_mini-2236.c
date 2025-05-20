//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>
#include <fftw3.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 512
#define FFT_SIZE (FRAMES_PER_BUFFER / 2)

typedef struct {
    float *inputBuffer;
    float *outputBuffer;
    float *fftInput;
    fftw_complex *fftOutput;
    fftw_plan fftPlan;
} AudioData;

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) {
    AudioData *data = (AudioData *) userData;
    (void) timeInfo;   
    (void) statusFlags; 

    // Cast the input buffer to a float pointer
    const float *in = (const float *) inputBuffer;

    // Copy the input audio samples to the input buffer
    for (unsigned long i = 0; i < framesPerBuffer; i++) {
        data->inputBuffer[i] = in[i];
    }

    // Perform FFT
    fftw_execute(data->fftPlan);

    // Display the frequency spectrum
    for (int i = 0; i < FFT_SIZE; i++) {
        float magnitude = sqrt(data->fftOutput[i][0] * data->fftOutput[i][0] +
                               data->fftOutput[i][1] * data->fftOutput[i][1]);
        printf("Frequency bin %d: Magnitude = %f\n", i, magnitude);
    }

    return paContinue;
}

int main(void) {
    PaError err;
    AudioData audioData;

    // Allocate memory
    audioData.inputBuffer = (float *) malloc(FRAMES_PER_BUFFER * sizeof(float));
    audioData.fftInput = (float *) fftw_malloc(FRAMES_PER_BUFFER * sizeof(float));
    audioData.fftOutput = (fftw_complex *) fftw_malloc(FFT_SIZE * sizeof(fftw_complex));

    // Initialize FFTW plan
    audioData.fftPlan = fftw_plan_dft_r2c_1d(FRAMES_PER_BUFFER, audioData.inputBuffer, audioData.fftOutput, FFTW_ESTIMATE);

    // Initialize PortAudio
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Open stream for input and output
    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream,
                               FRAMES_PER_BUFFER,
                               FRAMES_PER_BUFFER,
                               paFloat32,
                               SAMPLE_RATE,
                               FRAMES_PER_BUFFER,
                               audioCallback,
                               &audioData);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Start the audio stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    printf("Press Enter to stop recording...\n");
    getchar(); // Wait for user input

    // Stop and close the stream
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Cleanup
    fftw_destroy_plan(audioData.fftPlan);
    fftw_free(audioData.fftOutput);
    fftw_free(audioData.fftInput);
    free(audioData.inputBuffer);
    
    Pa_Terminate();
    printf("Finished.\n");

    return 0;
}