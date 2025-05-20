//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to recover data from file
void dataRecovery(char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file); // get file size in bytes
    fseek(file, 0, SEEK_SET); // go back to beginning
    char* data = malloc(size + 1);
    fread(data, 1, size, file); // read file into buffer
    fclose(file);

    // Data recovery algorithm goes here
    // For example, we could remove all null bytes from the buffer
    char* recoveredData = malloc(size + 1);
    int j = 0;
    for(int i=0; i<size; i++){
        if(data[i] != '\0'){
            recoveredData[j] = data[i];
            j++;
        }
    }
    recoveredData[j] = '\0'; // add null terminator at end of string

    // Write recovered data to new file with .recovered extension
    char* newFilename = malloc(strlen(filename) + strlen(".recovered") + 1);
    sprintf(newFilename, "%s.recovered", filename);
    file = fopen(newFilename, "w");
    if(file == NULL){
        printf("Error creating new file!\n");
        exit(1);
    }
    fwrite(recoveredData, 1, strlen(recoveredData), file);
    fclose(file);

    free(data);
    free(recoveredData);
    free(newFilename);

    printf("Data recovery successful!\n");
}


int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Invalid number of arguments!\n");
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    dataRecovery(filename);

    return 0;
}