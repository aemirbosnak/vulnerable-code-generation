//FormAI DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#pragma pack(push, 1)
typedef struct {
    char riff_id[4];
    uint32_t size;
    char wave_id[4];
    char fmt_id[4];
    uint32_t fmt_size;
    uint16_t format;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data_id[4];
    uint32_t data_size;
} wave_header;
#pragma pack(pop)

int main() {
    float alpha = 0.5;
    float y_prev = 0;
    float x_prev = 0;

    FILE* file = fopen("audio.wav", "rb");
    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    wave_header header;
    fread(&header, sizeof(header), 1, file);
    if (header.format != 1) {
        printf("Unsupported format\n");
        fclose(file);
        return 1;
    }

    int16_t* data = malloc(header.data_size);
    fread(data, header.data_size, 1, file);
    fclose(file);

    for (uint32_t i = 0; i < header.data_size/2; i++) {
        float x = data[i] / 32768.0f;
        float y = alpha * (y_prev + x - x_prev);
        y_prev = y;
        x_prev = x;
        data[i] = (int16_t)(y * 32768.0f);
    }

    file = fopen("audio_filtered.wav", "wb");
    if (!file) {
        printf("Failed to create file\n");
        return 1;
    }

    fwrite(&header, sizeof(header), 1, file);
    fwrite(data, header.data_size, 1, file);
    fclose(file);

    free(data);
    printf("Filtered audio saved\n");

    return 0;
}