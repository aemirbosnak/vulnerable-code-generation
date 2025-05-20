//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: modular
#include<stdio.h>
#include<string.h>
#define MAX_PATH 260

// Function to check if file extension is .c
int is_c_file(char *filename){
    int len = strlen(filename);
    if(len<2) return 0; // Empty file name
    if(filename[len-1]!='c') return 0; // Last char not c
    if(filename[len-2]=='.') return 1; // Second last char is .
    return 0;
}

// Function to check if file exists
int file_exists(char *filename){
    FILE *fp = fopen(filename, "r");
    if(fp){
        fclose(fp);
        return 1;
    }
    return 0;
}

// Function to scan a file for virus code
int scan_file(char *filename){
    char command[MAX_PATH+15];
    sprintf(command, "gcc -std=c11 -Wall -Wextra -Werror %s", filename);
    system(command);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if(argc<2){
        printf("Usage: antivirus <filename>\n");
        return 0;
    }
    
    if(!is_c_file(argv[1])){
        printf("Not a c file\n");
        return 0;
    }
    
    if(!file_exists(argv[1])){
        printf("File not found\n");
        return 0;
    }
    
    printf("Scanning %s...\n", argv[1]);
    if(scan_file(argv[1])){
        printf("Virus found!\n");
    } else {
        printf("File is clean\n");
    }
    return 0;
}