//FormAI DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000      // maximum file size to recover
#define MAX_FILE_NAME_LENGTH 100   // maximum file name length
#define MAX_FILE_EXTENSION_LENGTH 20   // maximum file extension length

void recover_data(){
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_extension[MAX_FILE_EXTENSION_LENGTH];
    char *data;
    int file_size = 0;
    FILE *infile, *outfile;

    printf("Enter the filename to recover: ");
    scanf("%s", file_name);
    printf("Enter the file extension to recover: ");
    scanf("%s", file_extension);

    // open the input file in binary mode
    infile = fopen(file_name, "rb");
    if (infile == NULL){
        printf("Error: Unable to open file %s for reading!\n", file_name);
        return;
    }

    // check if extension matches
    char *current_extension = strrchr(file_name, '.');
    if (current_extension && strcmp(current_extension+1, file_extension) != 0){
        printf("Error: File extension does not match!\n");
        return;
    }

    // allocate memory for the file data
    data = (char *) malloc(sizeof(char) * MAX_FILE_SIZE);
    if (data == NULL){
        printf("Error: Memory allocation failed!\n");
        return;
    }

    // read input file into data buffer
    file_size = fread(data, sizeof(char), MAX_FILE_SIZE, infile);
    if (file_size <= 0){
        printf("Error: File is empty!\n");
        return;
    }

    // close the input file
    fclose(infile);

    // open the output file in binary mode
    outfile = fopen(file_name, "wb");
    if (outfile == NULL){
        printf("Error: Unable to open file %s for writing!\n", file_name);
        return;
    }

    // write recovered data into output file
    fwrite(data, sizeof(char), file_size, outfile);

    // close the output file
    fclose(outfile);

    // free memory for the data buffer
    free(data);

    printf("Data successfully recovered from %s with extension %s!\n", file_name, file_extension);
}

int main(){
    recover_data();

    return 0;
}