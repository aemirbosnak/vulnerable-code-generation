//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

// Function to convert decimal to binary
void decToBin(int n, int *bin_arr)
{
    int i = 0;

    // Decimal to binary conversion
    while (n > 0) {
        bin_arr[i] = n % 2;
        n /= 2;
        i++;
    }

    // Adding extra zeros to make it 8 bit binary
    while (i < 8) {
        bin_arr[i] = 0;
        i++;
    }
}

int main()
{
    char input[MAX_SIZE], output[MAX_SIZE];
    int i = 0, j = 0, k = 0, dec_val = 0;
    int bin_arr[8] = {0};
    FILE *fptr1, *fptr2;

    // Opening input file for reading
    fptr1 = fopen("input.txt", "r");

    // Checking file exists
    if (fptr1 == NULL) {
        printf("Unable to open file\n");
        return 0;
    }

    // Reading input data from the file
    fgets(input, MAX_SIZE, fptr1);

    // Closing input file
    fclose(fptr1);

    // Converting input data to binary
    while (input[i]) {
        // Converting each character to decimal
        dec_val = dec_val * 10 + (input[i] - 48);

        i++;

        // Every 8 digits, convert to binary and write to output file
        if (i == 8) {
            decToBin(dec_val, bin_arr);

            // Open output file for writing, if first time
            if (j == 0) {
                fptr2 = fopen("output.txt", "w");
            }

            // Write binary to output file
            for (k = 7; k >= 0; k--) {
                fprintf(fptr2, "%d", bin_arr[k]);
            }

            // Resetting variables
            j++;
            i = 0;
            dec_val = 0;
        }
    }

    // Padding with additional zeros to make it multiple of 8 digits
    while (i < 8) {
        dec_val = dec_val * 10;
        i++;
    }

    // Converting last set of decimal to binary and writing to output file
    if (i == 8) {
        decToBin(dec_val, bin_arr);

        for (k = 7; k >= 0; k--) {
            fprintf(fptr2, "%d", bin_arr[k]);
        }
    }

    // Closing output file
    fclose(fptr2);

    printf("Image compression done successfully!\n");

    return 0;
}