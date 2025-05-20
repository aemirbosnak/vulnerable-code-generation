//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        if(tolower(str[i])!= tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}

// Function to scan a file for viruses
void scan_file(FILE* fp, char* virus_name) {
    char line[1024];
    while(fgets(line, sizeof(line), fp)!= NULL) {
        if(strstr(line, virus_name)!= NULL) {
            printf("Virus found in file: %s\n", virus_name);
            exit(1);
        }
    }
}

// Main function to run the antivirus scanner
int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <file_to_scan> <virus_name>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    char* virus_name = argv[2];

    // Open the file for reading
    FILE* fp = fopen(file_path, "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", file_path);
        return 1;
    }

    // Scan the file for viruses
    scan_file(fp, virus_name);

    // Close the file
    fclose(fp);

    return 0;
}