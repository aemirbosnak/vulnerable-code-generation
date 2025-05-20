//FormAI DATASET v1.0 Category: Audio processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <math.h>
#include <portaudio.h>

float cutoff_frequency = 500.0;
float sample_rate = 44100.0;
float gain = 1.0;

float sine_phase = 0.0;

unsigned long frame_index = 0;

pthread_mutex_t mutex;

typedef struct
{
    PaStream *stream;
    float *buffer;
} pa_data;

void process_audio(float *input, float *output, unsigned long frames_per_buffer)
{
    pthread_mutex_lock(&mutex);

    for(int i=0; i<frames_per_buffer; i++)
    {
        float sample = input[i];

        float cutoff_normalized = cutoff_frequency/sample_rate;
        float wet_gain = sin(M_PI_2 * cutoff_normalized);

        float filter_output = wet_gain * sample + (1 - wet_gain) * sine_phase;

        sine_phase = fmod(sine_phase + 2 * M_PI * cutoff_normalized, 2 * M_PI);
        output[i] = gain * filter_output;
    }

    pthread_mutex_unlock(&mutex);
}

static void *thread_func(void *arg)
{
    printf("Thread started\n");

    pa_data *data = (pa_data *) arg;

    if(Pa_OpenStream(&data->stream, NULL, NULL, sample_rate, paFramesPerBufferUnspecified, paNoFlag, process_audio, data) != paNoError)
    {
        printf("Failed to open stream\n");
        return NULL;
    }

    if(Pa_StartStream(data->stream) != paNoError)
    {
        printf("Failed to start stream\n");
        return NULL;
    }

    while(true);

    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);

    if(Pa_Initialize() != paNoError)
    {
        printf("Failed to initialize PortAudio\n");
        return -1;
    }

    pa_data *data = malloc(sizeof(pa_data));
    data->buffer = malloc(sizeof(float) * paFramesPerBufferUnspecified);

    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, data);

    while(getchar() != 'q')
    {
        printf("Enter a gain value between 0 and 1: ");
        scanf("%f", &gain);

        if(gain < 0) gain = 0;
        if(gain > 1) gain = 1;
    }

    pthread_cancel(thread);
    pthread_join(thread, NULL);

    Pa_Terminate();
    free(data->buffer);
    free(data);

    return 0;
}