//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMPERATURES 100

typedef struct {
    char name[20];
    double temperature;
} Temperature;

void readTemperatures(Temperature *temperatures, int *count) {
    FILE *fp = fopen("temperatures.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open temperatures file.\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: Invalid temperature data.\n");
            exit(1);
        }

        strcpy(temperatures[i].name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid temperature data.\n");
            exit(1);
        }

        temperatures[i].temperature = atof(token);
        i++;
    }

    fclose(fp);
    *count = i;
}

void sortTemperatures(Temperature *temperatures, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (temperatures[j].temperature < temperatures[i].temperature) {
                Temperature temp = temperatures[i];
                temperatures[i] = temperatures[j];
                temperatures[j] = temp;
            }
        }
    }
}

void printTemperatures(Temperature *temperatures, int count) {
    printf("Name           Temperature\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %10.2f\n", temperatures[i].name, temperatures[i].temperature);
    }
}

int main() {
    Temperature temperatures[MAX_TEMPERATURES];
    int count = 0;

    readTemperatures(temperatures, &count);
    if (count == 0) {
        printf("No temperatures found.\n");
        return 1;
    }

    sortTemperatures(temperatures, count);
    printTemperatures(temperatures, count);

    return 0;
}