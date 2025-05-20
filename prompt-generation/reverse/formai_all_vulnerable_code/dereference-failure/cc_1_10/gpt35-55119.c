//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "MyWatermark"

void embed_watermark(FILE*, FILE*);
int detect_watermark(FILE*);

int main(int argc, char* argv[]) {
        if (argc != 4) {
                printf("Usage: %s <input file> <output file> <-e or -d>\n", argv[0]);
                return EXIT_FAILURE;
        }
        
        FILE* input = fopen(argv[1], "rb");
        if (input == NULL) {
                printf("Error: can't open input file %s\n", argv[1]);
                return EXIT_FAILURE;
        }
        
        FILE* output = fopen(argv[2], "wb");
        if (output == NULL) {
                printf("Error: can't open output file %s\n", argv[2]);
                fclose(input);
                return EXIT_FAILURE;
        }
        
        if (!strcmp(argv[3], "-e")) {
                embed_watermark(input, output);
        }
        else if (!strcmp(argv[3], "-d")) {
                int found = detect_watermark(input);
                printf("Watermark %s found: %s\n", WATERMARK, found ? "yes" : "no");
        }
        else {
                printf("Error: invalid option %s\n", argv[3]);
                fclose(input);
                fclose(output);
                return EXIT_FAILURE;
        }
        
        fclose(input);
        fclose(output);
        return EXIT_SUCCESS;
}

void embed_watermark(FILE* input, FILE* output) {
        char buffer[1024];
        int watermark_len = strlen(WATERMARK);
        
        while (!feof(input)) {
                int read = fread(buffer, 1, 1024, input);
                for (int i = 0; i < read; i++) {
                        if (i + watermark_len + 1 < read) {
                                if (strncmp(buffer + i, WATERMARK, watermark_len)) {
                                        // we have found watermark
                                        int r = rand() % 2; // set the LSB to 0 or 1
                                        if (r) {
                                                buffer[i + watermark_len] |= 1;
                                        }
                                        else {
                                                buffer[i + watermark_len] &= ~1;
                                        }
                                }
                        }
                }
                fwrite(buffer, 1, read, output);
        }
}

int detect_watermark(FILE* input) {
        char buffer[1024];
        int watermark_len = strlen(WATERMARK);
        int found = 0;
        
        while (!feof(input)) {
                int read = fread(buffer, 1, 1024, input);
                for (int i = 0; i < read; i++) {
                        if (i + watermark_len + 1 < read) {
                                if (strncmp(buffer + i, WATERMARK, watermark_len)) {
                                        // we have found watermark
                                        if (buffer[i + watermark_len] & 1) {
                                                found = 1;
                                                break;
                                        }
                                }
                        }
                }
                if (found) {
                        break;
                }
        }
        
        return found;
}