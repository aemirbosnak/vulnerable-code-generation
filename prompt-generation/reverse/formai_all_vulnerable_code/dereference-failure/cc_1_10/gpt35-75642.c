//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

double sine(double freq, double time) {
    return sin(2 * PI * freq * time);
}

double square(double freq, double time) {
    return sine(freq, time) >= 0 ? 1.0 : -1.0;
}

double sawtooth(double freq, double time) {
    return 2.0 * fmod(time * freq, 1.0) - 1.0;
}

double triangle(double freq, double time) {
    return 2.0 * fabs(sawtooth(freq, time)) - 1.0;
}

double white_noise() {
    return (double)(rand() * 2.0 / RAND_MAX - 1.0);
}

double clip(double x, double a, double b) {
    return x < a ? a : (x > b ? b : x);
}

double smoothstep(double x) {
    return x * x * (3 - 2 * x);
}

double gain(double x, double gain_db) {
    return x * pow(10.0, gain_db / 20.0);
}

int main(int argc, char const *argv[]) {
    double (*synth_fn)(double, double);
    if (argc < 3) {
        printf("Usage: %s <sine|square|sawtooth|triangle|noise> <freq> [<amp>] [<gain>]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "sine") == 0) synth_fn = sine;
    else if (strcmp(argv[1], "square") == 0) synth_fn = square;
    else if (strcmp(argv[1], "sawtooth") == 0) synth_fn = sawtooth;
    else if (strcmp(argv[1], "triangle") == 0) synth_fn = triangle;
    else if (strcmp(argv[1], "noise") == 0) synth_fn = white_noise;
    else {
        printf("Invalid synth function '%s'\n", argv[1]);
        return 1;
    }
    double freq = atof(argv[2]), amp = 1.0, gain_db = 0.0;
    if (argc > 3) amp = atof(argv[3]);
    if (argc > 4) gain_db = atof(argv[4]);
    double time = 0.0;
    while (1) {
        double sample = synth_fn(freq, time) * amp;
        sample = clip(sample, -1.0, 1.0);
        sample = gain(sample, gain_db);
        sample = smoothstep(sample);
        putchar((char)(128 + (int)(127.0 * sample)));
        time += 1.0 / SAMPLE_RATE;
    }
    return 0;
}