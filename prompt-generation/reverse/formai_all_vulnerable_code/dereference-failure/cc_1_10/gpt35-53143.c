//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char virus_signature[] = "ILoveYou";
    char user_input[50];

    printf("Welcome to the best Antivirus Scanner EVER!\n");
    printf("Please enter the file path to scan: ");
    scanf("%s", user_input);

    printf("Scanning file for viruses...\n");

    FILE* file = fopen(user_input, "rb");
    if (file == NULL) {
        printf("ERROR: File not found.\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* file_contents = (char*) malloc(file_size * sizeof(char));
    fread(file_contents, sizeof(char), file_size, file);
    fclose(file);

    int virus_count = 0;

    for (int i = 0; i < file_size - strlen(virus_signature); i++) {
        int found_virus = 1;
        for (int j = 0; j < strlen(virus_signature); j++) {
            if (file_contents[i+j] != virus_signature[j]) {
                found_virus = 0;
                break;
            }
        }
        if (found_virus) {
            virus_count++;
        }
    }

    if (virus_count == 0) {
        printf("No viruses were found. Your computer is safe... for now.\n");
    } else {
        printf("WARNING! VIRUSES DETECTED! Do not run this program again until files are quarantined.\n");
    }

    free(file_contents);

    return 0;
}