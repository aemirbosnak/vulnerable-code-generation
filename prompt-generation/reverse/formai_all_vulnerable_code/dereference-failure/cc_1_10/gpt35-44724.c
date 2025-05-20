//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Declare custom error codes */ 
#define MY_ERROR_1 1 
#define MY_ERROR_2 2 
#define MY_ERROR_3 3 

/* Function to demonstrate error handling */
void foo(int val) {
    if (val == 1) {
        perror("Error occurred in foo() function");
        exit(MY_ERROR_1);
    }
    else if (val == 2) {
        printf("Warning: Value given is not recommended\n"); 
        /* Continue processing despite the warning */
    }
    else if (val == 3) {
        printf("The file could not be opened properly.\n"); 
        exit(MY_ERROR_2);
    }
    else {
        printf("Foo() function executed successfully\n");
    }
}

int main() {
    /* Example of handling errors using returned values */

    FILE *fptr;
    fptr = fopen("example.txt", "r");

    if (fptr == NULL) {
        printf("Error: Could not open file %s\n", "example.txt");
        return MY_ERROR_3;
    }

    fclose(fptr);

    /* Example of handling errors using errno */
    int val = 1;
    if (val == 1) {
        printf("Attempting to perform an operation that will cause an error...\n");
        errno = EDOM;
        perror("Error occurred in main() function");
        exit(MY_ERROR_3);
    }

    /* Example of handling warnings */
    val = 2;
    foo(val);

    /* Example of successful execution */
    val = 4;
    foo(val);

    return 0;
}