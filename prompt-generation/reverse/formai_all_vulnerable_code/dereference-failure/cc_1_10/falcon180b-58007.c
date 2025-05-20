//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VIRUS_LENGTH 64
#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_virus(char* file_content, int file_size) {
    char virus_buffer[VIRUS_LENGTH];
    int virus_index = 0;
    
    for(int i=0; i<file_size; i++) {
        if(isalpha(file_content[i])) {
            virus_buffer[virus_index++] = tolower(file_content[i]);
            if(virus_index == VIRUS_LENGTH) {
                virus_index = 0;
            }
        }
    }
    
    if(strstr(virus_buffer, VIRUS_SIGNATURE)) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE* file = fopen(argv[1], "rb");
    if(file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char* file_content = malloc(file_size+1);
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';
    
    int is_infected = is_virus(file_content, file_size);
    
    if(is_infected) {
        printf("The file '%s' is infected with a virus.\n", argv[1]);
    } else {
        printf("The file '%s' is clean.\n", argv[1]);
    }
    
    free(file_content);
    fclose(file);
    
    return 0;
}