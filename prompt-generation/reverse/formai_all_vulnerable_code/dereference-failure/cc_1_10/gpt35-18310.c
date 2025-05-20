//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_file(char* file_name) {
    printf("Checking file: %s\n", file_name);
    char* ext = strrchr(file_name, '.');
    if (ext != NULL && strcmp(ext, ".exe") == 0) {
        printf("File is an executable, checking for viruses...\n");
        int virus_count = 0;
        char* virus_db[] = {"trojan", "worm", "rootkit", "backdoor"};
        int num_viruses = sizeof(virus_db)/sizeof(char*);
        FILE* file = fopen(file_name, "rb");
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            fseek(file, 0, SEEK_SET);
            char* file_content = (char*) malloc(file_size);
            fread(file_content, 1, file_size, file);
            for (int i = 0; i < num_viruses; i++) {
                if (strstr(file_content, virus_db[i]) != NULL) {
                    printf("Found virus: %s\n", virus_db[i]);
                    virus_count++;
                }
            }
            free(file_content);
            fclose(file);
        }
        if (virus_count == 0) {
            printf("File is clean!\n");
        } else {
            printf("File is infected with %d virus(es)!\n", virus_count);
        }
    } else {
        printf("File is not an executable, skipping...\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> [file2] [file3] ...\n", argv[0]);
        return 1;
    }
    printf("Welcome to the Shape-Shifting Antivirus Scanner!\n");
    printf("Initializing virus database...\n");
    // Add more viruses to database here
    printf("Database initialized with %d viruses!\n", 4);
    printf("Scanning %d files...\n", argc-1);
    for (int i = 1; i < argc; i++) {
        check_file(argv[i]);
    }
    printf("Scanning complete!\n");
    return 0;
}