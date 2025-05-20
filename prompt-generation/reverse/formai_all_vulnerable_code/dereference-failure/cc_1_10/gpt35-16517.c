//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

void recover_data(char* filename){
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL){
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char* data = (char*)malloc(MAX_FILE_SIZE * sizeof(char));

    if (data == NULL){
        printf("Error: Unable to allocate memory\n");
        return;
    }

    int read_size = fread(data, sizeof(char), MAX_FILE_SIZE, fp);
    if (read_size == 0){
        printf("Error: Unable to read data from file %s\n", filename);
        free(data);
        return;
    }

    fclose(fp);

    char* recovered_data = (char*)malloc(MAX_FILE_SIZE * sizeof(char));
    int recovered_size = 0;

    for (int i = 0; i < read_size; i++){
        if (data[i] != 0){
            recovered_data[recovered_size] = data[i];
            recovered_size++;
        }
    }

    free(data);

    char new_filename[MAX_FILENAME_LENGTH];
    strcpy(new_filename, "recovered_");
    strcat(new_filename, filename);

    FILE* new_fp = fopen(new_filename, "wb");
    if (new_fp == NULL){
        printf("Error: Unable to create new file %s\n", new_filename);
        free(recovered_data);
        return;
    }

    fwrite(recovered_data, sizeof(char), recovered_size, new_fp);
    fclose(new_fp);

    free(recovered_data);
    printf("Successfully recovered data from file %s\n", filename);
}

int main(){
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to recover data from: ");
    scanf("%s", filename);
    recover_data(filename);
    return 0;
}