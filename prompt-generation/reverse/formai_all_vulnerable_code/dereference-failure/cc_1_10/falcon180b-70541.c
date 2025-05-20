//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip;
    char *date;
    char *method;
    char *url;
    int status_code;
} Request;

void process_line(char *line, Request *request);
void print_request(Request *request);

int main() {
    FILE *log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    Request current_request = {0};
    Request previous_request = {0};
    int num_requests = 0;

    while (fgets(current_request.ip, MAX_LINE_SIZE, log_file)!= NULL) {
        process_line(current_request.ip, &current_request);
        if (num_requests > 0) {
            print_request(&previous_request);
        }
        previous_request = current_request;
        num_requests++;
    }

    if (num_requests > 0) {
        print_request(&previous_request);
    }

    fclose(log_file);
    return 0;
}

void process_line(char *line, Request *request) {
    char *token = strtok(line, " ");
    strcpy(request->ip, token);

    token = strtok(NULL, " ");
    strcpy(request->date, token);

    token = strtok(NULL, " ");
    strcpy(request->method, token);

    token = strtok(NULL, " ");
    strcpy(request->url, token);

    token = strtok(NULL, " ");
    request->status_code = atoi(token);
}

void print_request(Request *request) {
    printf("IP: %s\n", request->ip);
    printf("Date: %s\n", request->date);
    printf("Method: %s\n", request->method);
    printf("URL: %s\n", request->url);
    printf("Status Code: %d\n\n", request->status_code);
}