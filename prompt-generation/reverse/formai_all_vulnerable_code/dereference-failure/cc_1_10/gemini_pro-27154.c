//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QR_VERSION_MIN 1
#define QR_VERSION_MAX 40

#define QR_MODE_NUMERIC 0x00
#define QR_MODE_ALPHANUMERIC 0x01
#define QR_MODE_BYTE 0x02
#define QR_MODE_KANJI 0x03

#define QR_ERROR_CORRECTION_LEVEL_L 0x00
#define QR_ERROR_CORRECTION_LEVEL_M 0x01
#define QR_ERROR_CORRECTION_LEVEL_Q 0x02
#define QR_ERROR_CORRECTION_LEVEL_H 0x03

typedef struct {
    int version;
    int error_correction_level;
    int mode;
    int data_length;
    char *data;
} qr_code_info_t;

typedef struct {
    int width;
    int height;
    char **data;
} qr_code_t;

void qr_code_info_init(qr_code_info_t *info) {
    info->version = QR_VERSION_MIN;
    info->error_correction_level = QR_ERROR_CORRECTION_LEVEL_L;
    info->mode = QR_MODE_NUMERIC;
    info->data_length = 0;
    info->data = NULL;
}

void qr_code_info_free(qr_code_info_t *info) {
    free(info->data);
}

int qr_code_info_set_version(qr_code_info_t *info, int version) {
    if (version < QR_VERSION_MIN || version > QR_VERSION_MAX) {
        return -1;
    }

    info->version = version;
    return 0;
}

int qr_code_info_set_error_correction_level(qr_code_info_t *info, int error_correction_level) {
    if (error_correction_level < QR_ERROR_CORRECTION_LEVEL_L || error_correction_level > QR_ERROR_CORRECTION_LEVEL_H) {
        return -1;
    }

    info->error_correction_level = error_correction_level;
    return 0;
}

int qr_code_info_set_mode(qr_code_info_t *info, int mode) {
    if (mode < QR_MODE_NUMERIC || mode > QR_MODE_KANJI) {
        return -1;
    }

    info->mode = mode;
    return 0;
}

int qr_code_info_set_data(qr_code_info_t *info, char *data, int data_length) {
    if (data_length < 0) {
        return -1;
    }

    info->data_length = data_length;
    info->data = malloc(data_length + 1);
    if (info->data == NULL) {
        return -1;
    }

    strcpy(info->data, data);
    return 0;
}

qr_code_t *qr_code_create(qr_code_info_t *info) {
    qr_code_t *qr_code = malloc(sizeof(qr_code_t));
    if (qr_code == NULL) {
        return NULL;
    }

    qr_code->width = 0;
    qr_code->height = 0;
    qr_code->data = NULL;

    return qr_code;
}

void qr_code_free(qr_code_t *qr_code) {
    for (int i = 0; i < qr_code->height; i++) {
        free(qr_code->data[i]);
    }

    free(qr_code->data);
    free(qr_code);
}

int qr_code_generate(qr_code_t *qr_code, qr_code_info_t *info) {
    // Calculate the qr code size
    qr_code->width = 4 * info->version + 17;
    qr_code->height = 4 * info->version + 17;

    // Allocate memory for the qr code data
    qr_code->data = malloc(qr_code->height * sizeof(char *));
    if (qr_code->data == NULL) {
        return -1;
    }

    for (int i = 0; i < qr_code->height; i++) {
        qr_code->data[i] = malloc(qr_code->width + 1);
        if (qr_code->data[i] == NULL) {
            return -1;
        }

        for (int j = 0; j < qr_code->width; j++) {
            qr_code->data[i][j] = ' ';
        }

        qr_code->data[i][qr_code->width] = '\0';
    }

    // Generate the qr code data
    int data_index = 0;
    int x = 0;
    int y = 0;
    int direction = 1; // 1 = right, -1 = left

    while (data_index < info->data_length) {
        if (x < 0 || x >= qr_code->width || y < 0 || y >= qr_code->height || qr_code->data[y][x] != ' ') {
            direction *= -1;
            if (x < 0) {
                x = 0;
            } else if (x >= qr_code->width) {
                x = qr_code->width - 1;
            } else if (y < 0) {
                y = 0;
            } else if (y >= qr_code->height) {
                y = qr_code->height - 1;
            }
        }

        qr_code->data[y][x] = info->data[data_index++];

        x += direction;
        y -= direction;
    }

    return 0;
}

void qr_code_print(qr_code_t *qr_code) {
    for (int i = 0; i < qr_code->height; i++) {
        printf("%s\n", qr_code->data[i]);
    }
}

int main() {
    qr_code_info_t info;
    qr_code_t *qr_code;

    qr_code_info_init(&info);
    qr_code_info_set_version(&info, 1);
    qr_code_info_set_error_correction_level(&info, QR_ERROR_CORRECTION_LEVEL_L);
    qr_code_info_set_mode(&info, QR_MODE_NUMERIC);
    qr_code_info_set_data(&info, "1234567890", 10);

    qr_code = qr_code_create(&info);
    qr_code_generate(qr_code, &info);
    qr_code_print(qr_code);
    qr_code_free(qr_code);

    qr_code_info_free(&info);

    return 0;
}