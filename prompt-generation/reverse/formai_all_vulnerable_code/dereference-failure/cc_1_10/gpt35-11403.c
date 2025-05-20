//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a custom error structure
typedef struct {
    int err_code;
    char *err_msg;
} Error;

//Function to raise an error
void raise_error(int code, char *msg) {
    Error *e = malloc(sizeof(Error));
    e->err_code = code;
    e->err_msg = malloc(strlen(msg) + 1);
    strcpy(e->err_msg, msg);
    printf("Error #%d: %s\n", e->err_code, e->err_msg);
    free(e->err_msg);
    free(e);
}

int main() {
    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    //Ensure input is within range
    if(num < 1 || num > 10) {
        raise_error(1, "Number out of range");
        return 1;
    }

    //Allocate memory for array
    int *arr = malloc(num * sizeof(int));

    //Check for memory allocation failure
    if(!arr) {
        raise_error(2, "Memory allocation failed");
        return 1;
    }

    //Initialize array with random values
    for(int i = 0; i < num; i++) {
        arr[i] = rand();
    }

    //Print array contents
    printf("Array contents: [ ");
    for(int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    //Free allocated memory
    free(arr);

    //Handle unexpected errors
    if(1 + 1 != 2) {
        raise_error(3, "Unexpected error occurred");
        return 1;
    }

    printf("Program executed successfully.\n");
    return 0;
}