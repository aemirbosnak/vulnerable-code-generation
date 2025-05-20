//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ABYSS_FILENAME "abyss.txt"

typedef struct Whisper {
    char name[20];
    char message[100];
} Whisper;

void write_whisper(Whisper whisper) {
    int file = open(ABYSS_FILENAME, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file == -1) {
        perror("Error opening file:");
        exit(EXIT_FAILURE);
    }

    ssize_t name_len = strlen(whisper.name);
    write(file, whisper.name, name_len + 1);

    ssize_t message_len = strlen(whisper.message);
    write(file, whisper.message, message_len + 1);

    lseek(file, -(name_len + message_len + 1), SEEK_CUR);
    write(file, "\n", 1);

    close(file);
}

void read_whispers() {
    int file = open(ABYSS_FILENAME, O_RDONLY);
    if (file == -1) {
        perror("Error opening file:");
        exit(EXIT_FAILURE);
    }

    char buffer[200];
    ssize_t bytes_read;
    while ((bytes_read = read(file, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';

        char name[20];
        sscanf(buffer, "%s%s", name, NULL);
        printf("%s: %s\n", name, buffer + strlen(name) + 1);
    }

    close(file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <name> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Whisper whisper;
    strcpy(whisper.name, argv[1]);
    strcpy(whisper.message, argv[2]);

    write_whisper(whisper);

    printf("Your whisper has been added to the Abyss...\n");

    sleep(5); // Give the file a moment to be written

    read_whispers();

    return EXIT_SUCCESS;
}