//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 4096

double mean(double* buffer, int size);
double variance(double* buffer, int size, double mean);
void normalize(double* buffer, int size, double mean, double variance);

int main()
{
    FILE *in_file, *out_file;
    double buffer[BUFFER_SIZE];
    int size;
    double avg, var;

    // open input file
    in_file = fopen("input.dat", "rb");
    if (in_file == NULL)
    {
        perror("Error opening input.dat");
        return EXIT_FAILURE;
    }

    // open output file
    out_file = fopen("output.dat", "wb");
    if (out_file == NULL)
    {
        perror("Error opening output.dat");
        return EXIT_FAILURE;
    }

    // read input file into buffer
    size = fread(buffer, sizeof(double), BUFFER_SIZE, in_file);
    while (size > 0)
    {
        // calculate mean and variance
        avg = mean(buffer, size);
        var = variance(buffer, size, avg);

        // normalize data
        normalize(buffer, size, avg, var);

        // write normalized data to output file
        fwrite(buffer, sizeof(double), size, out_file);

        // read next block of data
        size = fread(buffer, sizeof(double), BUFFER_SIZE, in_file);
    }

    // close files
    fclose(in_file);
    fclose(out_file);

    return EXIT_SUCCESS;
}

double mean(double* buffer, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += buffer[i];
    }

    return sum / size;
}

double variance(double* buffer, int size, double mean)
{
    double diff_sum = 0;

    for (int i = 0; i < size; i++)
    {
        diff_sum += pow(buffer[i] - mean, 2);
    }

    return diff_sum / (size - 1);
}

void normalize(double* buffer, int size, double mean, double variance)
{
    for (int i = 0; i < size; i++)
    {
        buffer[i] = (buffer[i] - mean) / sqrt(variance);
    }
}