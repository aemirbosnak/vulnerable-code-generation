//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FORTUNE_LENGTH 1024
#define MAX_FORTUNE_FILE_LENGTH 102400

char fortune[MAX_FORTUNE_LENGTH];
char fortune_file[MAX_FORTUNE_FILE_LENGTH];
char* fortune_pointer;
char* fortune_files_pointer[3];

char* get_random_fortune() {
    // Load fortune files into memory if they haven't been loaded yet
    if (!fortune_files_pointer[0]) {
        FILE* f1 = fopen("fortune1.txt", "rb");
        FILE* f2 = fopen("fortune2.txt", "rb");
        FILE* f3 = fopen("fortune3.txt", "rb");
        if (!f1 || !f2 || !f3) {
            printf("Error: could not open fortune files!\n");
            exit(1);
        }
        fread(fortune_file, 1, MAX_FORTUNE_FILE_LENGTH, f1);
        fortune_files_pointer[0] = fortune_file;
        fortune_files_pointer[1] = strchr(fortune_files_pointer[0], '%') + 1;
        fortune_files_pointer[2] = strchr(fortune_files_pointer[1], '%') + 1;
        fread(fortune_files_pointer[1], 1, MAX_FORTUNE_FILE_LENGTH - (int)(fortune_files_pointer[1] - fortune_files_pointer[0]), f2);
        fread(fortune_files_pointer[2], 1, MAX_FORTUNE_FILE_LENGTH - (int)(fortune_files_pointer[2] - fortune_files_pointer[0]), f3);
        fclose(f1);
        fclose(f2);
        fclose(f3);
    }

    // Get a random line from a random fortune file
    int file_number = rand() % 3;
    char* file_pointer = fortune_files_pointer[file_number];
    char* end_pointer = strchr(file_pointer, '%');
    int fortune_length = (int)(end_pointer - file_pointer) - 1;
    memcpy(fortune, file_pointer, fortune_length);
    fortune[fortune_length] = '\0';
    fortune_files_pointer[file_number] = end_pointer + 1;

    return fortune;
}

int main() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press Enter to get your fortune or type \"quit\" to exit.\n");

    char input[1024];
    while (1) {
        fgets(input, 1024, stdin);
        if (!strcmp(input, "quit\n")) break;

        // Clear any existing fortune text
        memset(fortune, 0, MAX_FORTUNE_LENGTH);

        printf("Your fortune is: %s\n", get_random_fortune());
    }

    printf("Goodbye!\n");
    return 0;
}