//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

/*Function to check and handle errors*/
void handle_error(int err_num, char* msg){
    if(err_num == 0) {
        printf("No error detected\n");
        return;
    }
    printf("Error detected!\n");
    fprintf(stderr, "Error code: %d\n", err_num);

    /*Check errno and print error message*/
    switch(err_num) {
        case EACCES:
            fprintf(stderr, "%s\n", "Permission denied");
            break;
        case ENOENT:
            fprintf(stderr, "%s\n", "File not found");
            break;
        case EINVAL:
            fprintf(stderr, "%s\n", "Invalid argument");
            break;
        default:
            fprintf(stderr, "%s\n", "Unknown error occurred");
            break;
    }

    /*Print custom error message*/
    if(msg != NULL) {
        fprintf(stderr, "%s\n", msg);
    }
}

int main() {
    FILE *fp;
    char filename[] = "nonexistent.txt";

    /*Try to open file*/
    fp = fopen(filename, "r");
    
    /*If fopen returns NULL, check for error*/
    if(fp == NULL) {
        handle_error(errno, "Could not open file for reading");
        return(EXIT_FAILURE);
    }

    /*Try to close file*/
    if(fclose(fp) != 0) {
        handle_error(errno, "Could not close file");
        return(EXIT_FAILURE);
    }

    printf("Program executed successfully\n");

    return(EXIT_SUCCESS);
}