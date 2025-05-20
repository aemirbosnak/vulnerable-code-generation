//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_PASSWORD_LENGTH 32
#define RANDOM_SEED (unsigned int)time(NULL)

typedef struct {
    char file_name[MAX_FILE_SIZE];
    char password[MAX_PASSWORD_LENGTH + 1];
    unsigned int seed;
} file_t;

void generate_password(char* password, unsigned int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=}{][:;?><,./-=";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <password>\n", argv[0]);
        return 1;
    }

    file_t input_file = {0};
    strncpy(input_file.file_name, argv[1], MAX_FILE_SIZE - 1);
    input_file.file_name[MAX_FILE_SIZE - 1] = '\0';
    input_file.seed = RANDOM_SEED;

    file_t output_file = {0};
    strncpy(output_file.file_name, argv[2], MAX_FILE_SIZE - 1);
    output_file.file_name[MAX_FILE_SIZE - 1] = '\0';
    output_file.seed = RANDOM_SEED;

    char password[MAX_PASSWORD_LENGTH + 1] = {0};
    strncpy(password, argv[3], MAX_PASSWORD_LENGTH);
    password[MAX_PASSWORD_LENGTH] = '\0';

    FILE* input_fp = fopen(input_file.file_name, "rb");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_fp = fopen(output_file.file_name, "wb");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        fclose(input_fp);
        return 1;
    }

    fseek(input_fp, 0, SEEK_END);
    unsigned int input_file_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    unsigned char input_buffer[input_file_size];
    fread(input_buffer, input_file_size, 1, input_fp);
    fclose(input_fp);

    unsigned char output_buffer[input_file_size];
    for (int i = 0; i < input_file_size; i++) {
        output_buffer[i] = input_buffer[i] ^ password[i % strlen(password)];
    }

    fwrite(output_buffer, input_file_size, 1, output_fp);
    fclose(output_fp);

    printf("File encrypted successfully.\n");
    return 0;
}