//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define SECRET_KEY 12345
#define MAX_WATERMARK_SIZE 1024

void embed_watermark(char* input_file, char* output_file, char* watermark) {
    FILE* fp_in = fopen(input_file, "rb");
    FILE* fp_out = fopen(output_file, "wb");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Read the input file
    fseek(fp_in, 0L, SEEK_END);
    long file_size = ftell(fp_in);
    rewind(fp_in);

    char* data = malloc(file_size);
    fread(data, sizeof(char), file_size, fp_in);

    // Embed the watermark in the data
    char* ptr = data;
    for (int i = 0; i < MAX_WATERMARK_SIZE; i++) {
        if (*watermark == '\0') {
            break;
        }

        if (*ptr + SECRET_KEY >= 255) {
            *ptr = (char)(*watermark - SECRET_KEY);
        } else {
            *ptr += SECRET_KEY;
        }
        
        watermark++;
        ptr++;
    }

    // Write the modified data to the output file
    fwrite(data, sizeof(char), file_size, fp_out);

    free(data);
    fclose(fp_in);
    fclose(fp_out);

    printf("Watermark successfully embedded!\n");
}

char* extract_watermark(char* input_file) {
    FILE* fp_in = fopen(input_file, "rb");

    if (fp_in == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the input file
    fseek(fp_in, 0L, SEEK_END);
    long file_size = ftell(fp_in);
    rewind(fp_in);

    char* data = malloc(file_size);
    fread(data, sizeof(char), file_size, fp_in);

    // Extract the watermark from the data
    char* watermark = malloc(MAX_WATERMARK_SIZE);
    char* ptr = data;

    for (int i = 0; i < MAX_WATERMARK_SIZE; i++) {
        if (*ptr - SECRET_KEY <= 0) {
            *(watermark + i) = (char)(*ptr + SECRET_KEY);
        } else {
            *(watermark + i) = (char)(*ptr - SECRET_KEY);
        }

        ptr++;

        if (*(watermark + i) == '\0') {
            break;
        }
    }

    free(data);
    fclose(fp_in);

    return watermark;
}

int main() {
    char* input_file = "input.txt";
    char* output_file = "output.txt";
    char* watermark = "This is a digital watermark.";

    embed_watermark(input_file, output_file, watermark);

    char* extracted_watermark = extract_watermark(output_file);
    printf("Extracted watermark: %s\n", extracted_watermark);
    free(extracted_watermark);

    return 0;
}