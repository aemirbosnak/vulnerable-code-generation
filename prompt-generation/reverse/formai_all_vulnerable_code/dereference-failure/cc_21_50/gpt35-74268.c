//FormAI DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename> [config file]\n", argv[0]);
        return 1;
    }
    
    char* filename = argv[1];
    char* config_file = NULL;
    int ignore_case = 0;
    int ignore_whitespace = 0;
    int word_len_min = 0;
    int word_len_max = 0;
    
    if (argc >= 3) {
        config_file = argv[2];
        
        FILE* fp = fopen(config_file, "r");
        if (fp == NULL) {
            printf("Error opening config file.\n");
            return 1;
        }
        
        char* line = NULL;
        size_t len = 0;
        ssize_t read;
        
        while ((read = getline(&line, &len, fp)) != -1) {
            line[strcspn(line, "\n")] = 0;
            
            if (strncmp(line, "ignore_case=", 12) == 0) {
                ignore_case = atoi(line+12);
            }
            else if (strncmp(line, "ignore_whitespace=", 18) == 0) {
                ignore_whitespace = atoi(line+18);
            }
            else if (strncmp(line, "word_len_min=", 13) == 0) {
                word_len_min = atoi(line+13);
            }
            else if (strncmp(line, "word_len_max=", 13) == 0) {
                word_len_max = atoi(line+13);
            }
        }
        
        fclose(fp);
        if (line) free(line);
    }
    
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    
    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0;
        
        char* tok = strtok(line, " ");
        while (tok != NULL) {
            int len = strlen(tok);
            int is_valid = 1;
            
            if (ignore_case) {
                for (int i = 0; i < len; i++) {
                    tok[i] = tolower(tok[i]);
                }
            }
            
            if (ignore_whitespace) {
                for (int i = 0; i < len; i++) {
                    if (isspace(tok[i])) {
                        is_valid = 0;
                        break;
                    }
                }
            }
            
            if (word_len_min > 0 && len < word_len_min) {
                is_valid = 0;
            }
            
            if (word_len_max > 0 && len > word_len_max) {
                is_valid = 0;
            }
            
            if (is_valid) {
                count++;
            }
            
            tok = strtok(NULL, " ");
        }
    }
    
    fclose(fp);
    if (line) free(line);
    
    printf("Word count: %d\n", count);
    
    return 0;
}