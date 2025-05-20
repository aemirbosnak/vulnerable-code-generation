//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to calculate the multidimensional Discrete Fourier Transform (DFT)
void DFT(int **inputSignal, int **outputSignal, int numOfRows, int numOfCols) {
    for (int k = 0; k < numOfRows; k++) {
        for (int n = 0; n < numOfCols; n++) {
            double sum_real = 0.0, sum_imag = 0.0;
            for (int i = 0; i < numOfRows; i++) {
                for (int j = 0; j < numOfCols; j++) {
                    double angle = 2 * PI * ((double) (k * i) / numOfRows + (double) (n * j) / numOfCols);
                    sum_real += inputSignal[i][j] * cos(angle);
                    sum_imag -= inputSignal[i][j] * sin(angle);
                }
            }
            outputSignal[k][n] = (int) round(sqrt(pow(sum_real, 2) + pow(sum_imag, 2)));
        }
    }
}

int main() {
    int numOfRows = 3, numOfCols = 4;
    int inputSignal[numOfRows][numOfCols];

    // Create a sample input signal
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            inputSignal[i][j] = i + j;
        }
    }

    int **outputSignal;
    outputSignal = (int **) calloc(numOfRows, sizeof(int **));
    for (int i = 0; i < numOfRows; i++) {
        outputSignal[i] = (int *) calloc(numOfCols, sizeof(int *));
    }

    // Calculate the 2D DFT of the input signal
    DFT(inputSignal, outputSignal, numOfRows, numOfCols);

    // Print the output signal (the result of the DFT)
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < numOfCols; j++) {
            printf("%d ", outputSignal[i][j]);
        }
        printf("\n");
    }

    return 0;
}