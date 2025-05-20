//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>

typedef struct {
    char* input;
    char* output;
    char binary[128];
} binary_converter;

void die(char* msg) {
    perror(msg);
    exit(1);
}

void signal_handler(int signal) {
    printf("Interrupted, exiting...\n");
    munmap((void*)&(((binary_converter*)0)->binary), 128);
    exit(0);
}

int main(int argc, char** argv) {
    signal(SIGINT, signal_handler);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(1);
    }

    binary_converter* converter = mmap(NULL, sizeof(binary_converter), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (converter == MAP_FAILED) die("mmap failed");

    converter->input = argv[1];
    converter->output = argv[2];

    memset(converter->binary, 0, 128);

    int i, j;
    for (i = 0; converter->input[i] != '\0'; i++) {
        if (converter->input[i] >= '0' && converter->input[i] <= '9') {
            converter->binary[j++] = converter->input[i] - '0' << (7 & ~(i % 4));
        } else if (converter->input[i] >= 'A' && converter->input[i] <= 'F') {
            converter->binary[j++] = (converter->input[i] - 'A' + 10) << (7 & ~(i % 4));
        } else if (converter->input[i] == ' ') {
            continue;
        } else {
            fprintf(stderr, "Invalid character '%c' in input string\n", converter->input[i]);
            munmap((void*)converter, sizeof(binary_converter));
            exit(1);
        }
    }

    for (i = 0; i < 128; i += 8) {
        for (j = i; j < i + 4 && j < 128; j++) {
            putchar(converter->binary[j / 8] >> (7 & ~(j % 8)) & 0xFF);
        }
        putchar(' ');
    }

    munmap((void*)converter, sizeof(binary_converter));

    return 0;
}