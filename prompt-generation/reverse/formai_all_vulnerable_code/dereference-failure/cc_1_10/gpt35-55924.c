//FormAI DATASET v1.0 Category: Temperature monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50.0
#define MIN_TEMP -20.0
#define MAX_DIFF 5.0

float getTemperature();
void logTemperature(float temp);

int main() {
    srand(time(NULL)); // initialize random seed
    float temp;

    while(1) {
        temp = getTemperature();
        if(temp >= MIN_TEMP && temp <= MAX_TEMP) { // only log valid temperatures
            logTemperature(temp);
        }
    }

    return 0;
}

// simulate temperature readings
float getTemperature() {
    float temp;
    float diff = (float)rand()/(float)(RAND_MAX/MAX_DIFF); // generate random difference
    int sign = rand()%2 == 0 ? 1 : -1; // generate random sign

    temp = 20.0 + diff*sign; // starting temp at 20.0

    return temp;
}

// log temperature to file
void logTemperature(float temp) {
    time_t now;
    time(&now);
    struct tm *timeinfo = localtime(&now);
    char filename[20];
    sprintf(filename, "temp_%d-%d-%d.txt", timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_mday);

    FILE *fptr = fopen(filename, "a");
    if(fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%.2f\t%d:%d:%d\n", temp, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    fclose(fptr);
}