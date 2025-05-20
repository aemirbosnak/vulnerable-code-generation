//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_VIRUS_SIZE 1024 * 10

struct Virus {
    char *name;
    char *signature;
    int size;
};

struct Virus *viruses;
int num_viruses;

void init_viruses() {
    viruses = malloc(sizeof(struct Virus) * 10);
    num_viruses = 0;
}

void add_virus(char *name, char *signature, int size) {
    viruses[num_viruses].name = name;
    viruses[num_viruses].signature = signature;
    viruses[num_viruses].size = size;
    num_viruses++;
}

int scan_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *file_buffer = malloc(file_size);
    if (file_buffer == NULL) {
        return -1;
    }

    fread(file_buffer, 1, file_size, file);
    fclose(file);

    for (int i = 0; i < num_viruses; i++) {
        if (strstr(file_buffer, viruses[i].signature) != NULL) {
            printf("Virus found: %s\n", viruses[i].name);
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    init_viruses();

    add_virus("Virus A", "0x00 0x01 0x02 0x03", 4);
    add_virus("Virus B", "0x04 0x05 0x06 0x07", 4);
    add_virus("Virus C", "0x08 0x09 0x0A 0x0B", 4);

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int result = scan_file(argv[1]);
    if (result == -1) {
        printf("Error: Could not open file.\n");
        return 1;
    } else if (result == 1) {
        printf("File is infected.\n");
        return 1;
    } else {
        printf("File is clean.\n");
        return 0;
    }
}