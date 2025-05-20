//Falcon-180B DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define ERR_MSG_LEN 256

typedef struct {
    char file_name[MAX_LINE_LEN];
    char err_msg[ERR_MSG_LEN];
} file_error_t;

void log_error(file_error_t *err) {
    fprintf(stderr, "Error: %s\n", err->err_msg);
}

int read_file(const char *file_name, char **buffer) {
    FILE *fp;
    long file_size;
    char *data;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        file_error_t err = {.file_name = file_name,.err_msg = "Failed to open file"};
        log_error(&err);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    data = malloc(file_size + 1);
    if (data == NULL) {
        file_error_t err = {.file_name = file_name,.err_msg = "Failed to allocate memory"};
        log_error(&err);
        fclose(fp);
        return -1;
    }

    size_t bytes_read = fread(data, sizeof(char), file_size, fp);
    if (bytes_read!= file_size) {
        file_error_t err = {.file_name = file_name,.err_msg = "Failed to read file"};
        log_error(&err);
        free(data);
        fclose(fp);
        return -1;
    }

    data[file_size] = '\0';
    *buffer = data;
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        file_error_t err = {.file_name = "",.err_msg = "Invalid number of arguments"};
        log_error(&err);
        return -1;
    }

    char *buffer;
    int ret = read_file(argv[1], &buffer);
    if (ret!= 0) {
        return ret;
    }

    printf("File content:\n%s", buffer);
    free(buffer);
    return 0;
}