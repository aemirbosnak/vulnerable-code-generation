//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Converts a string from ASCII to hex
char *as_to_hex(const char *str) {
    int len = strlen(str);
    char *hex = malloc(2 * len + 1);
    for (int i = 0; i < len; i++) {
        sprintf(hex + 2 * i, "%02x", str[i]);
    }
    hex[2 * len] = '\0';
    return hex;
}

// Extracts metadata from a JPEG file
void extract_jpeg_metadata(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Read entire file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(size);
    fread(data, 1, size, file);
    fclose(file);

    // Set pointer at the APP0 marker
    const char *marker = strstr(data, "\xff\xe0");
    if (!marker) {
        printf("No APP0 marker found\n");
        return;
    }

    // Extract segment length in hex
    char *segment_length_str = malloc(10);
    strncpy(segment_length_str, marker + 2, 2);
    char *segment_length_hex = as_to_hex(segment_length_str);

    // Parse Exif metadata
    const char *exif_header = strstr(data, segment_length_hex);
    if (!exif_header) {
        printf("No Exif header found\n");
        return;
    }

    // Extract Exif data in hex
    char *exif_data_str = malloc(1024);
    strncpy(exif_data_str, exif_header + 4, 1024);
    char *exif_data_hex = as_to_hex(exif_data_str);

    // Decode Exif data
    char *make = strstr(exif_data_hex, "0x010f");
    char *model = strstr(exif_data_hex, "0x0110");
    char *aperture = strstr(exif_data_hex, "0x829d");
    char *shutter_speed = strstr(exif_data_hex, "0x9202");
    char *iso = strstr(exif_data_hex, "0x8827");

    // Convert decoded data to ASCII
    char *make_ascii = strtok(make, "0x");
    char *model_ascii = strtok(model, "0x");
    char *aperture_ascii = strtok(aperture, "0x");
    char *shutter_speed_ascii = strtok(shutter_speed, "0x");
    char *iso_ascii = strtok(iso, "0x");

    // Print extracted metadata
    printf("Make: %s\n", make_ascii);
    printf("Model: %s\n", model_ascii);
    printf("Aperture: %s\n", aperture_ascii);
    printf("Shutter speed: %s\n", shutter_speed_ascii);
    printf("ISO: %s\n", iso_ascii);

    // Free allocated memory
    free(data);
    free(segment_length_str);
    free(segment_length_hex);
    free(exif_data_str);
    free(exif_data_hex);
}

int main() {
    extract_jpeg_metadata("image.jpg");
    return 0;
}