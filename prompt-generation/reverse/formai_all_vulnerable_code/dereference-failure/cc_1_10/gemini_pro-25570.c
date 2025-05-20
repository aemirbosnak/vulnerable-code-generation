//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DATA_SIZE 255
#define MAX_ERROR_CORRECTION_LEVEL 3
#define MIN_MODULE_SIZE 1

typedef struct {
    int version;
    int error_correction_level;
    int module_size;
    int num_modules;
    int data_size;
    unsigned char *data;
} qr_code;

qr_code* qr_code_new(int version, int error_correction_level, int module_size, unsigned char *data, int data_size) {
    qr_code *code = malloc(sizeof(qr_code));

    code->version = version;
    code->error_correction_level = error_correction_level;
    code->module_size = module_size;
    code->num_modules = (version + 7) * 4 + 1;
    code->data_size = data_size;
    code->data = malloc(data_size);

    memcpy(code->data, data, data_size);

    return code;
}

void qr_code_free(qr_code *code) {
    free(code->data);
    free(code);
}

int qr_code_get_version(qr_code *code) {
    return code->version;
}

int qr_code_get_error_correction_level(qr_code *code) {
    return code->error_correction_level;
}

int qr_code_get_module_size(qr_code *code) {
    return code->module_size;
}

int qr_code_get_num_modules(qr_code *code) {
    return code->num_modules;
}

int qr_code_get_data_size(qr_code *code) {
    return code->data_size;
}

unsigned char* qr_code_get_data(qr_code *code) {
    return code->data;
}

void qr_code_set_version(qr_code *code, int version) {
    code->version = version;
}

void qr_code_set_error_correction_level(qr_code *code, int error_correction_level) {
    code->error_correction_level = error_correction_level;
}

void qr_code_set_module_size(qr_code *code, int module_size) {
    code->module_size = module_size;
}

void qr_code_set_num_modules(qr_code *code, int num_modules) {
    code->num_modules = num_modules;
}

void qr_code_set_data_size(qr_code *code, int data_size) {
    code->data_size = data_size;
}

void qr_code_set_data(qr_code *code, unsigned char *data) {
    memcpy(code->data, data, code->data_size);
}

void qr_code_print(qr_code *code) {
    for (int i = 0; i < code->num_modules; i++) {
        for (int j = 0; j < code->num_modules; j++) {
            printf("%c", code->data[i * code->num_modules + j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

qr_code* qr_code_generate(unsigned char *data, int data_size, int version, int error_correction_level, int module_size) {
    qr_code *code = qr_code_new(version, error_correction_level, module_size, data, data_size);

    // Generate the QR code
    // ...

    return code;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    unsigned char *data = argv[1];
    int data_size = strlen(data);

    qr_code *code = qr_code_generate(data, data_size, 1, 0, 1);

    qr_code_print(code);

    qr_code_free(code);

    return 0;
}