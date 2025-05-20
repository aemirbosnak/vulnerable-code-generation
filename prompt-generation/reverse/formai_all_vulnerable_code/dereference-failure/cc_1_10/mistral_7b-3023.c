//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#define KEY_SIZE 1
#define BUFFER_SIZE 256
#define FILENAME_LENGTH 50

/*
 * caesar_cipher - encrypt or decrypt a message using Caesar cipher
 *
 * @mode: 'e' for encryption, 'd' for decryption
 * @key: the encryption key
 * @message: the message to be encrypted or decrypted
 * @output: the encrypted or decrypted message
 */
void caesar_cipher(char mode, int key, char *message, char *output) {
    int i, len = 0;

    len = strlen(message);

    for (i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (mode == 'e') {
                output[i] = ((message[i] + key - 'a') % 26) + 'a';
            } else {
                output[i] = ((message[i] - key + 26) % 26) + 'a';
            }
        } else {
            output[i] = message[i];
        }
    }

    output[len] = '\0';
}

/*
 * process_file - process a file using the given mode and key
 *
 * @mode: 'e' for encryption, 'd' for decryption
 * @key: the encryption key
 * @filename: the name of the file to be processed
 */
void process_file(char mode, int key, char *filename) {
    int fd, len;
    char message[BUFFER_SIZE], output[BUFFER_SIZE];

    fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    read(fd, message, BUFFER_SIZE - 1);
    message[BUFFER_SIZE - 1] = '\0';

    caesar_cipher(mode, key, message, output);

    write(STDOUT_FILENO, output, strlen(output));

    close(fd);
}

/*
 * main - entry point of the program
 */
int main(int argc, char **argv) {
    int key;

    if (argc != 4) {
        printf("Usage: %s <mode> <key> <filename>\n", argv[0]);
        exit(1);
    }

    key = atoi(argv[1]);

    if (key < -26 || key > 25) {
        printf("Invalid key. Key must be between -26 and 25.\n");
        exit(1);
    }

    process_file(argv[2][0], key, argv[3]);

    return 0;
}