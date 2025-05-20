//FormAI DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/aes.h>
#include <sys/wait.h>

#define CHUNK_SIZE 1024 // chunk size for file processing
#define ENCRYPT 1 // mode for encryption
#define DECRYPT 0 // mode for decryption

/**
 * Encrypt or decrypt a given file using AES-256 CBC algorithm
 * 
 * @param file_path: path of the input file
 * @param key_bytes: pointer to the key bytes
 * @param iv_bytes: pointer to the initialization vector bytes
 * @param mode: ENCRYPT or DECRYPT
 * @param process_id: ID of the current process (for printing info)
*/
void process_file(char* file_path, unsigned char* key_bytes, unsigned char* iv_bytes, int mode, int process_id) {
    FILE* in_file = fopen(file_path, "r");
    if (in_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    char* ext = (mode == ENCRYPT) ? ".enc" : ".dec";
    char* out_file_path = malloc(strlen(file_path) + strlen(ext) + 1);
    strcpy(out_file_path, file_path);
    strcat(out_file_path, ext);

    FILE* out_file = fopen(out_file_path, "w");
    if (out_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    AES_KEY key;
    AES_set_encrypt_key(key_bytes, 256, &key);
    unsigned char ivec[AES_BLOCK_SIZE];
    memcpy(ivec, iv_bytes, AES_BLOCK_SIZE);

    unsigned char in_chunk[CHUNK_SIZE];
    unsigned char out_chunk[CHUNK_SIZE + AES_BLOCK_SIZE];
    int num_bytes_read;
    int actual_out_size;

    while ((num_bytes_read = fread(in_chunk, sizeof(char), CHUNK_SIZE, in_file)) > 0) {
        if (mode == ENCRYPT) {
            AES_cbc_encrypt(in_chunk, out_chunk, num_bytes_read, &key, ivec, AES_ENCRYPT);            
            actual_out_size = num_bytes_read + AES_BLOCK_SIZE;
        } else { // DECRYPT
            AES_cbc_encrypt(in_chunk, out_chunk, num_bytes_read, &key, ivec, AES_DECRYPT);
            // Remove padding
            actual_out_size = num_bytes_read - out_chunk[num_bytes_read - 1];
        }
        fwrite(out_chunk, sizeof(char), actual_out_size, out_file);
    }

    fclose(in_file);
    fclose(out_file);
    printf("[Process %d] Finished processing file %s\n", process_id, file_path);
}

/**
 * Distribute input files evenly among a fixed number of processes
 * and process each file concurrently to encrypt or decrypt them.
 * 
 * @param input_files: pointer to array of input file paths
 * @param num_input_files: number of input files
 * @param key_bytes: pointer to the key bytes
 * @param iv_bytes: pointer to the initialization vector bytes
 * @param num_processes: number of processes to use
 * @param mode: ENCRYPT or DECRYPT
*/
void distribute_files(char** input_files, int num_input_files, unsigned char* key_bytes, unsigned char* iv_bytes, int num_processes, int mode) {
    int num_files_per_process = num_input_files / num_processes;
    int remaining_files = num_input_files % num_processes;

    int start_index = 0;
    int end_index = -1;
    int process_id;
    pid_t pid;

    for (process_id = 0; process_id < num_processes; process_id++) {
        end_index = start_index + num_files_per_process - 1;
        if (remaining_files > 0) {
            remaining_files--;
            end_index++;
        }

        pid = fork();
        if (pid == -1) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // child process
            printf("[Process %d] Starting encryption/decryption...\n", process_id);
            for (int i = start_index; i <= end_index; i++) {
                process_file(input_files[i], key_bytes, iv_bytes, mode, process_id);
            }
            printf("[Process %d] Done!\n", process_id);
            exit(EXIT_SUCCESS);
        } else { // parent process
            start_index = end_index + 1;
        }
    }

    // Wait for child processes to finish
    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }
}

int main(int argc, char** argv) {
    if (argc < 5) {
        fprintf(stderr,
                "Usage: %s <key> <iv> <mode> <file1> <file2> ... <fileN>\n"
                "\t- key: 32 bytes in hexadecimal form\n"
                "\t- iv: 16 bytes in hexadecimal form\n"
                "\t- mode: 'enc' for encryption, 'dec' for decryption\n"
                "\t- file1 ... fileN: paths of input files to process\n", 
                argv[0]);
        return EXIT_FAILURE;
    }

    // Get key and IV bytes
    unsigned char key_bytes[AES_BLOCK_SIZE];
    memset(key_bytes, 0, AES_BLOCK_SIZE);
    sscanf(argv[1], "%32hhx", key_bytes);

    unsigned char iv_bytes[AES_BLOCK_SIZE];
    memset(iv_bytes, 0, AES_BLOCK_SIZE);
    sscanf(argv[2], "%16hhx", iv_bytes);

    // Get file paths and mode
    int num_files = argc - 4;
    char** file_paths = malloc(num_files * sizeof(char*));
    for (int i = 4; i < argc; i++) {
        file_paths[i - 4] = argv[i];
    }

    int mode = -1;
    if (strcmp(argv[3], "enc") == 0) {
        mode = ENCRYPT;
    } else if (strcmp(argv[3], "dec") == 0) {
        mode = DECRYPT;
    } else {
        fprintf(stderr, "Invalid mode\n");
        return EXIT_FAILURE;
    }

    distribute_files(file_paths, num_files, key_bytes, iv_bytes, 4, mode);

    return EXIT_SUCCESS;
}