//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to perform digital watermarking
void digitalWatermark(char *inputFile, char *watermark) {
    FILE *fp; // File pointer for opening input file
    FILE *wp; // File pointer for creating output file

    char c; // Variable for storing each character of input file
    int i = 0; // Counter variable for iterating over watermark string
    int j = 0; // Counter variable for iterating over input file

    fp = fopen(inputFile, "r"); // Open input file in read mode
    wp = fopen("output.txt", "w"); // Create output file in write mode

    if(fp == NULL) {
        printf("Error opening input file\n");
        return;
    }

    if(wp == NULL) {
        printf("Error creating output file\n");
        return;
    }

    while((c = fgetc(fp)) != EOF) { // Loop through each character of input file
        if(c == '\n') { // Check for end of line character
            fputc(c, wp); // Write character to output file
            j++; // Increment counter variable
            continue;
        }

        if(i < strlen(watermark)) { // Check if digits of watermark are left
            int asciiVal = (int) watermark[i]; // Get ASCII value of current digit

            if(asciiVal >= 48 && asciiVal <= 57) { // Check if ASCII value is between 0 and 9
                int digit = asciiVal - 48; // Convert digit to integer

                while(digit > 0) { // Loop for writing digit number of '#' characters
                    fputc('#', wp); // Write '#' character to output file
                    j++; // Increment counter variable
                    digit--;
                }
            } else { // If ASCII value is not between 0 and 9
                fputc(asciiVal, wp); // Write character to output file
                j++; // Increment counter variable
            }

            i++; // Increment counter variable
        }

        fputc(c, wp); // Write character to output file
        j++; // Increment counter variable
    }

    fclose(fp); // Close input file
    fclose(wp); // Close output file

    printf("Watermarking done successfully!\n");
}

int main() {
    char inputFile[] = "input.txt"; // Name of input file
    char watermark[] = "12345"; // Watermark string

    digitalWatermark(inputFile, watermark); // Call function to perform digital watermarking

    return 0;
}