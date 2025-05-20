//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

char* virus_signature = "iAK9^#d%wxP5fN@Hx";

int main(int argc, char** argv) {
    char line[MAX_SIZE];
    int line_num = 0;
    int virus_count = 0;
    
    if (argc < 2) {
        printf("Error: Please provide the name of the file to scan!\n");
        exit(1);
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Couldn't open the file %s\n", argv[1]);
        exit(1);
    }
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line_num++;
        
        // Remove leading and trailing whitespace
        char* current_char = line;
        while (isspace(*current_char)) {
            current_char++;
        }
        char* end_char = current_char + strlen(current_char) - 1;
        while (end_char > current_char && isspace(*end_char)) {
            end_char--;
        }
        *(end_char+1) = '\0';    
        
        // Check if line contains virus signature
        if (strstr(line, virus_signature) != NULL) {
            virus_count++;
            printf("Virus found on line %d!\n", line_num);
        }
    }
    
    fclose(file);
    
    if (virus_count > 0) {
        printf("Warning: %d instances of virus signature found!\n", virus_count);
    } else {
        printf("No viruses found! Congratulations!\n");
    }
    
    return 0;
}