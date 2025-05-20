//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    int file_size;
    char content[1];
} File;

int is_virus(const char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", file_name);
        return -1;
    }
    
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    
    char* content = (char*) malloc(file_size + 1);
    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    
    fclose(file);
    
    if (strstr(content, "I love you")) {
        printf("Virus detected: %s\n", file_name);
        return 1;
    }
    
    free(content);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    
    const char* file_name = argv[1];
    int virus_detected = is_virus(file_name);
    
    if (virus_detected == 1) {
        printf("Virus detected: %s\n", file_name);
    } else {
        printf("No virus detected: %s\n", file_name);
    }
    
    return 0;
}