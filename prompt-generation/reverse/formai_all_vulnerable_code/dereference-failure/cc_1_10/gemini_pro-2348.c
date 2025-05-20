//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BUFFERSIZE 1024

// Shannon entropy function
double shannon_entropy(char *str) {
    int i, len = strlen(str);
    double entropy = 0.0;
    double p;

    for (i = 0; i < len; i++) {
        p = (double)str[i] / len;
        if (p > 0) {
            entropy -= p * log2(p);
        }
    }

    return entropy;
}

int main() {
    // Initialize variables
    char *buffer = malloc(BUFFERSIZE);
    FILE *fp;
    int i, j, n, m;
    double entropy;

    // Open log file
    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    // Read log file
    while (fgets(buffer, BUFFERSIZE, fp) != NULL) {
        // Calculate entropy of each line
        entropy = shannon_entropy(buffer);

        // Print entropy if it is below a threshold
        if (entropy < 0.5) {
            printf("%s", buffer);
        }
    }

    // Close log file
    fclose(fp);

    return 0;
}