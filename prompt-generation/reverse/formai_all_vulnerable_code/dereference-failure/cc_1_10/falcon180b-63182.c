//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 8192

#define HTTP_OK "HTTP/1.1 200 OK\r\n"
#define HTTP_NOT_FOUND "HTTP/1.1 404 Not Found\r\n"
#define HTTP_BAD_REQUEST "HTTP/1.1 400 Bad Request\r\n"

#define HTML_HEADER \
    "<!DOCTYPE html>\n" \
    "<html>\n" \
    "<head>\n" \
    "<title>Simple Web Server</title>\n" \
    "</head>\n" \
    "<body>\n"
#define HTML_FOOTER \
    "</body>\n" \
    "</html>\n"

void handle_request(char* request, char* response) {
    char* path = strtok(request, " ");
    if (path == NULL) {
        strcpy(response, HTTP_BAD_REQUEST);
        return;
    }

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        strcpy(response, HTTP_NOT_FOUND);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = malloc(file_size + 1);
    fread(content, file_size, 1, file);
    fclose(file);
    content[file_size] = '\0';

    sprintf(response, "Content-Type: text/html\r\n"
                        "Content-Length: %ld\r\n\r\n"
                        "%s%s%s",
                        file_size,
                        HTML_HEADER,
                        content,
                        HTML_FOOTER);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    printf("Starting Simple Web Server on port %d...\n", port);

    char* response = malloc(MAX_RESPONSE_SIZE);

    while (1) {
        char* request = malloc(MAX_REQUEST_SIZE);
        int bytes_received = recv(0, request, MAX_REQUEST_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        handle_request(request, response);

        send(0, response, strlen(response), 0);
    }

    free(response);
    return 0;
}