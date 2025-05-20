//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 10000        // maximum size of the data to be watermarked
#define WATERMARK "1234567890"     // the watermark string

void embedWatermark(unsigned char *data, int data_size, const char *watermark) {
    int watermark_size = strlen(watermark);     // get the size of the watermark string

    // first embed the size of watermark in the data
    data[0] = (unsigned char) (watermark_size >> 8);
    data[1] = (unsigned char) watermark_size;

    // now embed the watermark
    int i, j;
    for (i = 0, j = 2; i < watermark_size; i++, j++) {
        data[j] = (unsigned char) (data[j] | (watermark[i] & 0x0f));     // embed 4 bits of watermark in lower nibble
        data[j+1] = (unsigned char) (data[j+1] | ((watermark[i] & 0xf0) >> 4));   // embed 4 bits of watermark in upper nibble
    }
}

void extractWatermark(unsigned char *data, int data_size, char *watermark) {
    int watermark_size = (data[0] << 8) + data[1];   // extract the size of the watermark

    // now extract the watermark
    int i, j;
    for (i = 0, j = 2; i < watermark_size; i++, j += 2) {
        watermark[i] = ((data[j+1] & 0x0f) << 4) | (data[j] & 0x0f);     // extract the watermark from lower and upper nibble
    }
    watermark[watermark_size] = '\0';     // set the last character to null character to end the string
}

int main() {
    unsigned char *data = (unsigned char*) malloc(MAX_DATA_SIZE);
    int data_size;

    // read the data to be watermarked from a file
    FILE *fp = fopen("input.txt", "rb");
    if (fp != NULL) {
        data_size = fread(data, 1, MAX_DATA_SIZE, fp);
        fclose(fp);
    }

    // embed the watermark in the data
    embedWatermark(data, data_size, WATERMARK);

    // write the watermarked data to a file
    fp = fopen("output.txt", "wb");
    if (fp != NULL) {
        fwrite(data, 1, data_size, fp);
        fclose(fp);
    }

    // extract the watermark from the watermarked data
    char watermark[11] = "";
    extractWatermark(data, data_size, watermark);
    printf("Extracted watermark: %s\n", watermark);

    free(data);

    return 0;
}