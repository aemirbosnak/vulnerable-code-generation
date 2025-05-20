//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF_SIZE (1 << 20)

typedef struct {
    char * buff;
    int buff_size;
    int written;
} Buffer;

void buffer_init(Buffer * buff, int size) {
    buff->buff = malloc(size);
    buff->buff_size = size;
    buff->written = 0;
}

void buffer_free(Buffer * buff) {
    free(buff->buff);
    buff->buff = NULL;
    buff->buff_size = 0;
    buff->written = 0;
}

int buffer_write(Buffer * buff, const void * data, int size) {
    if(buff->written + size > buff->buff_size) {
        return -1;
    }

    memcpy(buff->buff + buff->written, data, size);
    buff->written += size;

    return size;
}

int buffer_read(Buffer * buff, void * data, int size) {
    if(buff->written < size) {
        return -1;
    }

    memcpy(data, buff->buff, size);
    buff->written -= size;

    return size;
}

typedef struct {
    Buffer input;
    Buffer output;
} Compressor;

void compressor_init(Compressor * compressor) {
    buffer_init(&compressor->input, MAX_BUFF_SIZE);
    buffer_init(&compressor->output, MAX_BUFF_SIZE);
}

void compressor_free(Compressor * compressor) {
    buffer_free(&compressor->input);
    buffer_free(&compressor->output);
}

int compressor_compress(Compressor * compressor) {
    int i, j, k;

    i = 0;
    while(i < compressor->input.written) {
        j = i + 1;
        while(j < compressor->input.written && compressor->input.buff[i] == compressor->input.buff[j]) {
            j++;
        }

        k = j - i;
        if(k > 1) {
            if(buffer_write(&compressor->output, &i, sizeof(i)) < 0) {
                return -1;
            }

            if(buffer_write(&compressor->output, &k, sizeof(k)) < 0) {
                return -1;
            }
        }
        else {
            if(buffer_write(&compressor->output, &compressor->input.buff[i], sizeof(char)) < 0) {
                return -1;
            }
        }

        i = j;
    }

    return 0;
}

int compressor_decompress(Compressor * compressor) {
    int i, j, k;

    i = 0;
    while(i < compressor->output.written) {
        if(buffer_read(&compressor->output, &j, sizeof(j)) < 0) {
            return -1;
        }

        if(buffer_read(&compressor->output, &k, sizeof(k)) < 0) {
            return -1;
        }

        if(k > 1) {
            for(j = 0; j < k; j++) {
                if(buffer_write(&compressor->input, &compressor->input.buff[j], sizeof(char)) < 0) {
                    return -1;
                }
            }
        }
        else {
            if(buffer_read(&compressor->output, &compressor->input.buff[j], sizeof(char)) < 0) {
                return -1;
            }
        }

        i += sizeof(j) + sizeof(k);
    }

    return 0;
}

int main(int argc, char ** argv) {
    Compressor compressor;
    char * input_file, * output_file;

    if(argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input_file = argv[1];
    output_file = argv[2];

    compressor_init(&compressor);

    // Read input file
    FILE * fp = fopen(input_file, "rb");
    if(fp == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int input_file_size = ftell(fp);
    rewind(fp);

    if(input_file_size > MAX_BUFF_SIZE) {
        printf("Input file too large: %d bytes (max: %d bytes)\n", input_file_size, MAX_BUFF_SIZE);
        return 1;
    }

    if(fread(compressor.input.buff, 1, input_file_size, fp) != input_file_size) {
        printf("Error reading input file: %s\n", input_file);
        return 1;
    }

    fclose(fp);

    // Compress input
    if(compressor_compress(&compressor) < 0) {
        printf("Error compressing input\n");
        return 1;
    }

    // Write output file
    fp = fopen(output_file, "wb");
    if(fp == NULL) {
        printf("Error opening output file: %s\n", output_file);
        return 1;
    }

    if(fwrite(compressor.output.buff, 1, compressor.output.written, fp) != compressor.output.written) {
        printf("Error writing output file: %s\n", output_file);
        return 1;
    }

    fclose(fp);

    return 0;
}