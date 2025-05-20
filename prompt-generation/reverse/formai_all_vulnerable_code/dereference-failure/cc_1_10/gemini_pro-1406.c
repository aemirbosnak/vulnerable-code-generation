//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KELVIN 0
#define FAHRENHEIT 1
#define CELSIUS 2
#define SCALE_COUNT 3
#define INFINITE_LOOP 0

const double CONVERT_TEMPERATURES[][SCALE_COUNT] = {
    {1, 1.8, 273.15},
    {0.555555555555556, 1, 255.9277777777778},
    {-0.003666666666666666, -0.0018333333333333333, 1}
};

int main(int nArguments, char *pszArguments[]) {
    int nMode = -1;
    if (nArguments == 3) {
        double dInputTemperature = atof(pszArguments[1]);
        if (strcmp(pszArguments[2], "K") == 0) {
            nMode = KELVIN;
        } else if (strcmp(pszArguments[2], "F") == 0) {
            nMode = FAHRENHEIT;
        } else if (strcmp(pszArguments[2], "C") == 0) {
            nMode = CELSIUS;
        }
    }
    if (nMode == -1) {
        fprintf(stderr, "\nUsage %s temperature unit\n",
            pszArguments[0]);
        fprintf(stderr, "Supported unit are:\n");
        fprintf(stderr, "    K -> Kelvin\n");
        fprintf(stderr, "    F -> Fahrenheit\n");
        fprintf(stderr, "    C -> Celsius\n\n");
        return EXIT_FAILURE;
    }
    int i = 0;
    while (INFINITE_LOOP) {
        fprintf(stdout, "\n%d. Enter the temperature (or 'q' to quit) >>> ",
            i + 1);
        char cBuffer[2];
        scanf("%s", cBuffer);
        if (strcmp(cBuffer, "q") == 0) {
            break;
        }
        double dInputTemperature = atof(cBuffer);
        int j = 0;
        while (j < SCALE_COUNT) {
            j = (nMode == j) ? j + 1 : j;
        }
        fprintf(stdout, "\n%.2f K = %.2f F = %.2f C\n",
            CONVERT_TEMPERATURES[nMode][j] * dInputTemperature,
            CONVERT_TEMPERATURES[nMode][j - 1] * dInputTemperature,
            CONVERT_TEMPERATURES[nMode][j - 2] * dInputTemperature);
        i++;
    }
    return EXIT_SUCCESS;
}