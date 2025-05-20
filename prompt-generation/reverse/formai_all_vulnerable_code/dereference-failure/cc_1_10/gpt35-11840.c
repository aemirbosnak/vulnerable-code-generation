//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_FILE_EXT_LEN 5
#define MAX_VIRUS_SIG_LEN 10
#define MAX_SCAN_MSG_LEN 100

typedef struct _file_info {
    char name[MAX_FILENAME_LEN];
    char extension[MAX_FILE_EXT_LEN];
} file_info;

typedef struct _virus_signature {
    char signature[MAX_VIRUS_SIG_LEN];
} virus_signature;

file_info get_file_info(char* filename) {
    file_info info;
    char* ext = strchr(filename, '.'); // find the extension
    if (ext != NULL) {
        strcpy(info.extension, ext+1);
        *ext = '\0'; // remove extension from name
    } else {
        info.extension[0] = '\0';
    }
    strcpy(info.name, filename);
    return info;
}

int scan_file(char* filename, virus_signature* signatures, int num_signatures) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("%s NOT FOUND\n", filename);
        return 0; // file not found
    }

    char buffer[MAX_VIRUS_SIG_LEN];
    while (fread(buffer, 1, MAX_VIRUS_SIG_LEN, file) == MAX_VIRUS_SIG_LEN) {
        for (int i = 0; i < num_signatures; i++) {
            if (strcmp(buffer, signatures[i].signature) == 0) {
                printf("%s INFECTED WITH %s\n", filename, buffer);
                fclose(file);
                return 1; // file infected
            }
        }
        fseek(file, -MAX_VIRUS_SIG_LEN+1, SEEK_CUR); // rewind file pointer by signature length-1
    }

    fclose(file);
    printf("%s CLEAN\n", filename);
    return 0; // file clean
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("USAGE: ./antivirus <file1> <file2> ... <fileN> <signature1> <signature2> ... <signatureM>\n");
        return -1;
    }

    int num_files = argc - (argc/2) - 1; // count files
    int num_signatures = argc - num_files - 1; // count signatures
    file_info* files = malloc(num_files * sizeof(file_info));
    virus_signature* signatures = malloc(num_signatures * sizeof(virus_signature));

    // get file names and extensions
    for (int i = 1; i <= num_files; i++) {
        files[i-1] = get_file_info(argv[i]);
    }

    // get virus signatures
    for (int i = num_files+1; i < argc; i++) {
        strcpy(signatures[i-num_files-1].signature, argv[i]);
    }

    // scan files
    for (int i = 0; i < num_files; i++) {
        scan_file(files[i].name, signatures, num_signatures);
    }

    free(files);
    free(signatures);

    return 0;
}