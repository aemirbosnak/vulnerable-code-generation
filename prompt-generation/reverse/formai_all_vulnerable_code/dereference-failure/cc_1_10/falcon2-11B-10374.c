//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    // Read the input file
    FILE *in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return 1;
    }

    // Create a unique watermark
    char watermark[] = "This is a watermark";
    char *watermark_buf = malloc(strlen(watermark) + 1);
    strcpy(watermark_buf, watermark);

    // Write the watermark to the output file
    FILE *out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    while (fgets(line, sizeof(line), in_file)!= NULL) {
        // Add the watermark to each line
        char *new_line = realloc(line, len + strlen(watermark_buf));
        if (new_line == NULL) {
            fprintf(stderr, "Error reallocating memory: %s\n", line);
            return 1;
        }
        strcat(new_line, watermark_buf);
        free(line);
        line = new_line;

        // Write the line to the output file
        fwrite(line, sizeof(char), len, out_file);
        len = strlen(line);
    }

    // Clean up
    free(watermark_buf);
    fclose(in_file);
    fclose(out_file);

    return 0;
}