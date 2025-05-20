//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_WATERMARK_LENGTH 1000
#define MAX_FILENAME_LENGTH 256

int main(int argc, char *argv[]) {
    // Check for valid command-line arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <watermark>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error: unable to open %s for reading.\n", argv[1]);
        return 1;
    }

    // Read the input file into a byte buffer
    fseek(in_file, 0, SEEK_END);
    size_t file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);
    unsigned char *file_data = (unsigned char *) malloc(file_size);
    fread(file_data, 1, file_size, in_file);
    fclose(in_file);

    // Extract the input file's header
    unsigned char header[54];
    for (int i = 0; i < 54; i++) {
        header[i] = file_data[i];
    }

    // Extract the input file's image data
    size_t data_size = file_size - 54;
    unsigned char *data = (unsigned char *) malloc(data_size);
    for (int i = 0; i < data_size; i++) {
        data[i] = file_data[i + 54];
    }

    // Determine the length of the watermark
    int watermark_length = strlen(argv[2]);
    if (watermark_length > MAX_WATERMARK_LENGTH) {
        printf("Error: watermark is too long.\n");
        return 1;
    }

    // Append the watermark to the image data
    for (int i = 0; i < watermark_length; i++) {
        data[i] |= (argv[2][i] & 1);
    }

    // Write the resulting data to file
    char out_filename[MAX_FILENAME_LENGTH];
    sprintf(out_filename, "%s.watermarked", argv[1]);
    FILE *out_file = fopen(out_filename, "wb");
    fwrite(header, 1, 54, out_file);
    fwrite(data, 1, data_size, out_file);
    fclose(out_file);

    printf("Watermark successfully applied to %s.\n", argv[1]);

    return 0;
}