//FormAI DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void copyFile(char* src, char* dest){
    FILE* f_src = fopen(src, "r");
    FILE* f_dest = fopen(dest, "w");
    if(f_src == NULL || f_dest == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int c;
    while((c = fgetc(f_src)) != EOF){
        fputc(c, f_dest);
    }

    fclose(f_src);
    fclose(f_dest);
}

void backupFile(char* src, char* backup_dir){
    char* basename = strrchr(src, '/');
    if(strlen(backup_dir) + strlen(basename) > 1024){
        fprintf(stderr, "Error: the backup path is too long\n");
        exit(EXIT_FAILURE);
    }

    char* dest = malloc(strlen(backup_dir) + strlen(basename) + 2); // 2 for // and \0
    if(dest == NULL){
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    sprintf(dest, "%s/%s", backup_dir, basename);

    copyFile(src, dest);

    free(dest);
}

int main(int argc, char** argv){
    if(argc < 3){
        fprintf(stderr, "Usage: %s <source file> <backup directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(access(argv[1], F_OK) == -1){
        fprintf(stderr, "Error: the source file does not exist\n");
        exit(EXIT_FAILURE);
    }

    if(access(argv[2], F_OK) == -1){
        if(mkdir(argv[2], 0777) == -1){
            perror("Error creating backup directory");
            exit(EXIT_FAILURE);
        }else{
            printf("Created backup directory: %s\n", argv[2]);
        }
    }

    backupFile(argv[1], argv[2]);

    printf("Backup successful!\n");

    return 0;
}