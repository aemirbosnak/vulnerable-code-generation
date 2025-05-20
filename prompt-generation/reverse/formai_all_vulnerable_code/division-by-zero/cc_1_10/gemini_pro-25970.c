//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    size_t len;
} Buffer;

static Buffer* read_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    rewind(file);

    unsigned char *data = malloc(len);
    if (data == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    if (fread(data, 1, len, file) != len) {
        perror("fread");
        free(data);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return &(Buffer){.data = data, .len = len};
}

static void write_file(const char *path, const void *data, size_t len) {
    FILE *file = fopen(path, "wb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    if (fwrite(data, 1, len, file) != len) {
        perror("fwrite");
        fclose(file);
        return;
    }

    fclose(file);
}

static unsigned char *encrypt(const unsigned char *data, size_t len, const unsigned char *key, size_t key_len) {
    unsigned char *result = malloc(len);
    if (result == NULL) {
        perror("malloc");
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        result[i] = data[i] ^ key[i % key_len];
    }

    return result;
}

static void print_usage(const char *name) {
    printf("Usage: %s <input_file> <output_file> <key>\n", name);
    printf("Encrypts a file using a key.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_path = argv[1];
    const char *output_path = argv[2];
    const char *key = argv[3];

    Buffer *buffer = read_file(input_path);
    if (buffer == NULL) {
        return EXIT_FAILURE;
    }

    unsigned char *encrypted_data = encrypt(buffer->data, buffer->len, (const unsigned char *)key, strlen(key));
    if (encrypted_data == NULL) {
        free(buffer->data);
        free(buffer);
        return EXIT_FAILURE;
    }

    write_file(output_path, encrypted_data, buffer->len);

    free(buffer->data);
    free(buffer);
    free(encrypted_data);

    return EXIT_SUCCESS;
}