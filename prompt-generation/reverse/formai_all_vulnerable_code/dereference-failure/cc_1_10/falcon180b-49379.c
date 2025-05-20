//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TEMP_SAMPLES 1000
#define TEMP_SAMPLE_INTERVAL 1 // seconds

int main() {
    int i, j, num_samples = 0;
    double temp_samples[MAX_TEMP_SAMPLES];
    double avg_temp = 0;
    char temp_file[20] = "temp_data.txt";
    FILE *temp_data_file;

    // create temp_data.txt file if it doesn't exist
    temp_data_file = fopen(temp_file, "a+");
    if (temp_data_file == NULL) {
        printf("Creating temp_data.txt file...\n");
        temp_data_file = fopen(temp_file, "w+");
        fprintf(temp_data_file, "Time,Temperature\n");
        fclose(temp_data_file);
    }

    // read temp_data.txt file and get number of samples
    temp_data_file = fopen(temp_file, "r+");
    if (temp_data_file == NULL) {
        printf("Error opening temp_data.txt file!\n");
        exit(1);
    }
    rewind(temp_data_file);
    while (fscanf(temp_data_file, "%s", temp_file)!= EOF) {
        num_samples++;
    }
    fclose(temp_data_file);

    // start temperature monitoring
    srand(time(NULL));
    printf("Temperature monitoring started...\n");
    for (i = 0; i < num_samples; i++) {
        temp_samples[i] = rand() % 100; // generate random temperature data
        printf("Sample %d: %.2f\n", i+1, temp_samples[i]);
        fprintf(temp_data_file, "%d,%.2f\n", i+1, temp_samples[i]);
        fflush(temp_data_file);
        sleep(TEMP_SAMPLE_INTERVAL);
    }

    // calculate average temperature
    for (i = 0; i < num_samples; i++) {
        avg_temp += temp_samples[i];
    }
    printf("Average temperature: %.2f\n", avg_temp/num_samples);

    return 0;
}