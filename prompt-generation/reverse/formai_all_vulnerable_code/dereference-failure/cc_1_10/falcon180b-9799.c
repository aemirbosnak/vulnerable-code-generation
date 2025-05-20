//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *filename;
    FILE *file;
    int file_size;
    char *buffer;
    int word_count = 0;
    int letter_count = 0;
    int line_count = 0;
    int character_count = 0;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Memory error!\n");
        exit(1);
    }
    
    fread(buffer, file_size, 1, file);
    fclose(file);
    
    for (int i = 0; i < file_size; i++) {
        if (buffer[i] == '\n') {
            line_count++;
        } else if (isalpha(buffer[i])) {
            letter_count++;
        } else if (isspace(buffer[i])) {
            character_count++;
        }
    }
    
    printf("File name: %s\n", filename);
    printf("File size: %d bytes\n", file_size);
    printf("Word count: %d\n", word_count);
    printf("Letter count: %d\n", letter_count);
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", character_count);
    
    free(buffer);
    
    return 0;
}