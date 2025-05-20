//FormAI DATASET v1.0 Category: Log analysis ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    // Checking if the input file is provided or not
    if(argc!=2) {
        printf("Please provide input log file!\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    
    // Checking if the input file exists or not
    if(input == NULL) {
        printf("File doesn't exist!\n");
        exit(1);
    }
    
    char buffer[1024]; //buffer to store line by line logs
    int request_count = 0, error_count = 0, redirect_count = 0, client_errors = 0, server_errors = 0;

    while(fgets(buffer, 1024, input)) {
        char *log_type = strtok(buffer, " ");
        
        // Match log type with request, error, redirect and client/server error
        if(strncmp(log_type, "Request", 7) == 0) {
            request_count++;
        } else if(strncmp(log_type, "Error", 5) == 0) {
            error_count++;
            char *error_code = strtok(NULL, " ");
            if(strcmp(error_code, "404") == 0 || strcmp(error_code, "401") == 0 || strcmp(error_code, "403") == 0) {
                client_errors++;
            } else {
                server_errors++;
            }
        } else if(strncmp(log_type, "Redirect", 9) == 0) {
            redirect_count++;
        }
    }

    // Displaying the analysis of log file
    printf("\n --- Log Analysis of %s ---\n\n", argv[1]);
    printf(" Total Requests: %d\n", request_count);
    printf(" Total Errors: %d\n", error_count);
    printf(" Total Redirects: %d\n", redirect_count);
    printf(" Client Errors: %d\n", client_errors);
    printf(" Server Errors: %d\n\n", server_errors);

    fclose(input);
    return 0;
}