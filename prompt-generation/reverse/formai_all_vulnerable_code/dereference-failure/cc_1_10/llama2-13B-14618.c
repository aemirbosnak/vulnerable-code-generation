//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STR_LEN 20
#define MAX_INT 2147483647

// Probability distribution functions
double binomial_pdf(int n, int k, double p) {
    return (double)(k == 0) + (double)(k == n) * (1 - p) * (1 - p) +
           (double)(k == n - 1) * p * (1 - p);
}

double normal_pdf(double x, double mean, double stddev) {
    return (1 / (stddev * sqrt(2 * M_PI))) * exp(-((x - mean) * (x - mean)) / (2 * stddev * stddev));
}

// Function to convert binary to decimal
int binary_to_decimal(char *str) {
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '1') {
            num *= 2;
            num += 1;
        }
    }
    return num;
}

// Function to convert decimal to binary
char *decimal_to_binary(int num) {
    char *str = malloc(sizeof(char) * (num + 1));
    int i = 0;
    while (num != 0) {
        str[i] = (num % 2) == 0 ? '0' : '1';
        num /= 2;
        i++;
    }
    str[i] = '\0';
    return str;
}

int main() {
    srand(time(NULL));

    // Generate a random number between 0 and 1
    double x = drand48();

    // Calculate the probability of the number being in each bin
    double prob[10] = {0};
    for (int i = 0; i < 10; i++) {
        prob[i] = binomial_pdf(10, i, 0.5);
    }

    // Generate a random number of bins
    int n_bins = (int)floor(x * 10 + 0.5);

    // Print the probability of each bin
    for (int i = 0; i < 10; i++) {
        printf("%.2f%% (%d-%d): %f\n", prob[i] * 100, i, i + 1, x >= i ? 1 : 0);
    }

    // Generate a random decimal number
    int num = binary_to_decimal(decimal_to_binary(rand() % 100));

    // Print the binary representation of the number
    printf("Decimal: %d\nBinary: ", num);
    for (int i = 0; i < 10; i++) {
        printf("%c", (num >> i) & 1 ? '1' : '0');
    }

    return 0;
}