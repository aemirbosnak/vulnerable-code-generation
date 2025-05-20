//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t u64;

struct binary_converter {
    u64 value;
    int size;
};

struct binary_converter *binary_converter_new(u64 value, int size) {
    struct binary_converter *bc = malloc(sizeof(struct binary_converter));
    if (bc == NULL) {
        return NULL;
    }
    bc->value = value;
    bc->size = size;
    return bc;
}

void binary_converter_free(struct binary_converter *bc) {
    free(bc);
}

char *binary_converter_to_string(struct binary_converter *bc) {
    char *str = malloc(bc->size + 1);
    if (str == NULL) {
        return NULL;
    }
    int i;
    for (i = bc->size - 1; i >= 0; i--) {
        str[i] = (bc->value & 1) + '0';
        bc->value >>= 1;
    }
    str[bc->size] = '\0';
    return str;
}

u64 binary_converter_from_string(const char *str) {
    u64 value = 0;
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        value <<= 1;
        value |= str[i] - '0';
    }
    return value;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <value> <size>\n", argv[0]);
        return EXIT_FAILURE;
    }
    u64 value = strtoull(argv[1], NULL, 10);
    int size = atoi(argv[2]);
    struct binary_converter *bc = binary_converter_new(value, size);
    if (bc == NULL) {
        fprintf(stderr, "Error: could not allocate memory for binary converter.\n");
        return EXIT_FAILURE;
    }
    char *str = binary_converter_to_string(bc);
    if (str == NULL) {
        fprintf(stderr, "Error: could not convert binary converter to string.\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", str);
    free(str);
    binary_converter_free(bc);
    return EXIT_SUCCESS;
}