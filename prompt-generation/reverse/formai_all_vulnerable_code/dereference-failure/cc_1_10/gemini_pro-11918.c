//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define N 512

typedef unsigned char uchar;

int main() {
    FILE *f = fopen("image.bmp", "rb");
    if (!f) {
        printf("Error opening file!\n");
        return -1;
    }

    uchar header[54];
    fread(header, 54, 1, f);

    uchar *data = malloc(N * N * 3);
    fread(data, N * N * 3, 1, f);
    fclose(f);

    uchar watermark[N * N / 8];
    FILE *wf = fopen("watermark.txt", "rb");
    if (!wf) {
        printf("Error opening watermark file!\n");
        free(data);
        return -1;
    }

    fread(watermark, N * N / 8, 1, wf);
    fclose(wf);

    int bit = 0;
    for (int i = 0; i < N * N; i++) {
        if (bit == N * N / 8) {
            bit = 0;
        }

        int pos = i * 3;
        data[pos] &= 0xFE;
        data[pos] |= (watermark[bit] >> 7) & 1;

        bit++;
    }

    f = fopen("watermarked.bmp", "wb");
    if (!f) {
        printf("Error opening output file!\n");
        free(data);
        return -1;
    }

    fwrite(header, 54, 1, f);
    fwrite(data, N * N * 3, 1, f);
    fclose(f);

    free(data);

    printf("Watermarking complete!\n");
    return 0;
}