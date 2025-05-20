//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    FILE *fp_in, *fp_out;
    char ch;
    int sum = 0;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open output file
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: Output file not found.\n");
        exit(1);
    }

    // Calculate checksum
    while ((ch = fgetc(fp_in))!= EOF) {
        sum += ch;
    }

    // Write checksum to output file
    fprintf(fp_out, "%d\n", sum);

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    printf("Checksum calculated and written to output file.\n");

    return 0;
}