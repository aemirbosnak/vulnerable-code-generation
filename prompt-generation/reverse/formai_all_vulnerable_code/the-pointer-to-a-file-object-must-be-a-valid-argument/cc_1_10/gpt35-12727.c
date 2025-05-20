//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_FILES 100 
#define MAX_FILENAME 100 
#define MAX_VIRUS_PATTERN 100 

char virus_patterns[MAX_VIRUS_PATTERN][MAX_FILENAME]; 
int num_viruses = 0; 

void scan_file(char* filename) 
{ 
    FILE* file = fopen(filename, "r"); 
    int virus_found = 0; 
    char line[256]; 

    while (fgets(line, sizeof(line), file)) { 
        for (int i = 0; i < num_viruses; i++) { 
            if (strstr(line, virus_patterns[i])) { 
                virus_found = 1; 
                printf("Virus detected in file: %s\n", filename); 
                break; 
            } 
        } 

        if (virus_found) { 
            break; 
        } 
    } 

    if (!virus_found) { 
        printf("No virus detected in file: %s\n", filename); 
    } 

    fclose(file); 
} 

int main(int argc, char* argv[]) 
{ 
    char file_list[MAX_FILES][MAX_FILENAME]; 
    int num_files = 0; 

    // load virus definitions from file 
    FILE* virus_file = fopen("virus_definitions.txt", "r"); 
    char virus_pattern[MAX_FILENAME]; 

    while (fgets(virus_pattern, sizeof(virus_pattern), virus_file)) { 
        virus_pattern[strcspn(virus_pattern, "\n")] = 0; 
        strcpy(virus_patterns[num_viruses], virus_pattern); 
        num_viruses++; 
    } 

    fclose(virus_file); 

    // get list of files to scan 
    FILE* file_list_file = fopen("file_list.txt", "r"); 
    char filename[MAX_FILENAME]; 

    while (fgets(filename, sizeof(filename), file_list_file)) { 
        filename[strcspn(filename, "\n")] = 0; 
        strcpy(file_list[num_files], filename); 
        num_files++; 
    } 

    fclose(file_list_file); 

    // scan the files 
    for (int i = 0; i < num_files; i++) { 
        scan_file(file_list[i]); 
    } 

    return 0; 
}