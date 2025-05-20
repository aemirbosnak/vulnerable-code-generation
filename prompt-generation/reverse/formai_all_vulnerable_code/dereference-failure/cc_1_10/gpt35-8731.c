//FormAI DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define PI 3.141592653589793238

typedef struct {
    int32_t i[2];
} i32_pair;

char *load_file(char *filename, size_t *size) {
    char *buffer;
    struct stat st;
    int fd;

    if((fd = open(filename, O_RDONLY)) == -1) {
        fprintf(stderr, "[%s] Error opening file: %s\n", strerror(errno), filename);
        exit(1);
    }

    if(fstat(fd, &st) == -1) {
        fprintf(stderr, "[%s] Error calling stat()\n", strerror(errno));
        exit(1);
    }

    buffer = (char *) mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if(buffer == MAP_FAILED) {
        fprintf(stderr, "[%s] Error mmapping the file\n", strerror(errno));
        exit(1);
    }

    *size = st.st_size;

    return buffer;
}

void process_file(char *filename) {
    size_t size;
    char *input = load_file(filename, &size);

    int32_t *samples = (int32_t *) malloc(size);
    int nsamples = size / sizeof(int32_t);

    memcpy(samples, input, size);

    for(int i = 0; i < nsamples; i++) {
        double s = (double) samples[i] / (double) INT32_MAX;
        double t = ((double) i) / 44100.0;
        
        s *= sin(2.0 * PI * 440.0 * t);

        samples[i] = (int32_t) (s * INT32_MAX);
    }

    FILE *output_file = fopen("output.raw", "wb");

    fwrite(samples, sizeof(int32_t), nsamples, output_file);

    fclose(output_file);
    free(input);
    free(samples);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s input_file.raw\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);

    return 0;
}