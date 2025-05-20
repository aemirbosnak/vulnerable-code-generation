//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Function to read temperature from a file
int readTemperature()
{
    FILE *fp;
    char buff[255];
    int temp;

    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) {
        printf("[ERROR] Couldn't find the file!\n");
        exit(1);
    }

    fgets(buff, 255, fp);
    temp = atoi(buff) / 1000;
    fclose(fp);

    return temp;
}

int main(int argc, char **argv)
{
    int temp, threshold;
    bool tooHot = false;

    printf("C Temperature Monitor\n");
    printf("----------------------\n");

    if (argc < 2) {
        printf("[ERROR] Please provide a temperature threshold!\n");
        exit(1);
    }
    else {
        threshold = atoi(argv[1]);
        printf("[INFO] Temperature threshold set to: %d C\n", threshold);
    }

    while (true) {
        temp = readTemperature();
        printf("[INFO] Current temperature is: %d C\n", temp);

        if (temp >= threshold) {
            if (!tooHot) {
                printf("[WARNING] Temperature is too high!\n");
                tooHot = true;
            }
        }
        else {
            if (tooHot) {
                printf("[INFO] Temperature is back to normal.\n");
                tooHot = false;
            }
        }

        sleep(1);
    }

    return 0;
}