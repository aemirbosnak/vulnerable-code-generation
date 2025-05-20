//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEMP_UNITS 3

typedef struct {
    char name[20];
    float factor;
    float offset;
} TempUnit;

TempUnit tempUnits[MAX_TEMP_UNITS] = {
    {"Celsius", 1.0, 0.0},
    {"Fahrenheit", 1.8, 32.0},
    {"Kelvin", 1.0, -273.15}
};

int main() {
    char input[MAX_LINE_LENGTH];
    char tempUnitName[20];
    int numTemps;
    float temps[MAX_LINE_LENGTH];
    int i;

    printf("Enter the number of temperatures to convert:\n");
    scanf("%d", &numTemps);

    printf("Enter the temperatures (one per line):\n");
    for (i = 0; i < numTemps; i++) {
        fgets(input, MAX_LINE_LENGTH, stdin);
        strtok(input, " ");
        strcpy(tempUnitName, strtok(NULL, " "));
        temps[i] = atof(strtok(NULL, " "));
    }

    printf("Enter the temperature unit to convert to:\n");
    scanf("%s", tempUnitName);

    for (i = 0; i < MAX_TEMP_UNITS; i++) {
        if (strcmp(tempUnits[i].name, tempUnitName) == 0) {
            break;
        }
    }

    if (i == MAX_TEMP_UNITS) {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    for (i = 0; i < numTemps; i++) {
        temps[i] = (temps[i] * tempUnits[i].factor) + tempUnits[i].offset;
        printf("%.2f %s = %.2f %s\n", temps[i], tempUnitName, temps[i], tempUnits[i].name);
    }

    return 0;
}