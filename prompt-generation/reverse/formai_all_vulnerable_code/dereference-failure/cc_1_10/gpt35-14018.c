//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Define error codes
#define ERR_FILE_NOT_FOUND 1
#define ERR_INVALID_INPUT 2
#define ERR_MEMORY_ALLOCATION_FAILED 3

//Function to read file and return error code if file not found
int read_file(char* filename, char** content) {
    FILE* fp; 
    fp = fopen(filename, "r"); //Opening file in read mode
    if (!fp) {
        return ERR_FILE_NOT_FOUND;
    }

    fseek(fp, 0, SEEK_END); //Move file pointer to end of file
    long file_size = ftell(fp); //Get the size of the file
    fseek(fp, 0, SEEK_SET); //Move file pointer to start of file
    *content = (char*) malloc((file_size+1) * sizeof(char)); //Allocate memory for file content
    if (!*content) {
        return ERR_MEMORY_ALLOCATION_FAILED;
    }

    fread(*content, file_size, 1, fp); //Reading file content
    fclose(fp); //Closing file
    return 0; //Successful execution
}

//Function to convert string to integer and return error code if input is invalid
int string_to_int(char* str, int* num) {
    int result = 0, sign = 1;
    if (*str == '-') { //Handling negative numbers
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str < '0' || *str > '9') { //Checking for non-numeric characters
            return ERR_INVALID_INPUT;
        }
        result = (result * 10) + (*str - '0');
        str++;
    }

    *num = sign * result;
    return 0; //Successful execution
}

int main() {
    char* filename = "input.txt";
    char* content;
    int num;
    bool success = true;

    int read_result = read_file(filename, &content);
    switch (read_result) {
        case ERR_FILE_NOT_FOUND:
            printf("Error %d: File not found\n", ERR_FILE_NOT_FOUND);
            success = false;
            break;
        case ERR_MEMORY_ALLOCATION_FAILED:
            printf("Error %d: Memory allocation failed\n", ERR_MEMORY_ALLOCATION_FAILED);
            success = false;
            break;
        default:
            printf("File read successfully\n");
            break;
    }

    if (success) {
        int int_result = string_to_int(content, &num);
        switch (int_result) {
            case ERR_INVALID_INPUT:
                printf("Error %d: Invalid input\n", ERR_INVALID_INPUT);
                success = false;
                break;
            default:
                printf("Input converted successfully\n");
                break;
        }
    }

    if (success) {
        printf("The converted number is: %d\n", num);
    }

    free(content); //Freeing memory
    return 0; //Successful execution
}