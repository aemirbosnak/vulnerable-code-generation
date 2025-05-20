//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double max(double a, double b){
    return (a > b) ? a : b;
}

double min(double a, double b){
    return (a < b) ? a : b;
}

void normalize(double* arr, int len){
    double max_amp = 0.0;

    for(int i = 0; i < len; i++){
        max_amp = max(max_amp, fabs(arr[i]));
    }

    for(int i = 0; i < len; i++){
        arr[i] = arr[i] / max_amp;
    }
}

void low_pass_filter(double* arr, int len, double fc, double sample_rate){
    double alpha = 1.0 / (1.0 + (2.0 * M_PI * fc / sample_rate));
    double prev_output = 0.0;
    double output = 0.0;

    for(int i = 0; i < len; i++){
        output = alpha * arr[i] + (1.0 - alpha) * prev_output;
        prev_output = output;
        arr[i] = output;
    }
}

void high_pass_filter(double* arr, int len, double fc, double sample_rate){
    double alpha = (2.0 * M_PI * fc / sample_rate) / (1.0 + (2.0 * M_PI * fc / sample_rate));
    double prev_output = 0.0;
    double prev_input = 0.0;
    double output = 0.0;

    for(int i = 0; i < len; i++){
        output = alpha * prev_output + alpha * (arr[i] - prev_input);
        prev_output = output;
        prev_input = arr[i];
        arr[i] = output;
    }
}

int main(){
    // read the signal from a file
    FILE* file = fopen("audio_sample.raw", "rb");
    if(!file) {
        printf("Unable to open file\n");
        return 1;
    }

    // get file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // read file data
    char* file_data = (char*) malloc(file_size);
    if(fread(file_data, 1, file_size, file) != file_size){
        printf("Unable to read file\n");
        fclose(file);
        free(file_data);
        return 1;
    }
    fclose(file);

    // convert from char* to double*
    int num_samples = file_size / sizeof(double);
    double* signal = (double*) malloc(num_samples * sizeof(double));
    for(int i = 0; i < num_samples; i++){
        signal[i] = ((double*) file_data)[i];
    }

    // normalize the signal
    normalize(signal, num_samples);

    // apply low pass filter
    double fc = 2000.0; // cutoff frequency in Hz
    double sample_rate = 44100.0; // sample rate in Hz
    low_pass_filter(signal, num_samples, fc, sample_rate);

    // apply high pass filter
    fc = 100.0; // cutoff frequency in Hz
    high_pass_filter(signal, num_samples, fc, sample_rate);

    // save the filtered signal to a file
    file = fopen("audio_sample_filtered.raw", "wb");
    if(!file) {
        printf("Unable to open file\n");
        free(signal);
        free(file_data);
        return 1;
    }
    fwrite(signal, sizeof(double), num_samples, file);
    fclose(file);

    free(signal);
    free(file_data);

    return 0;
}