//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdbool.h>

//Constants
#define MAX_REQUEST_LEN 1024
#define MAX_RESPONSE_LEN 1024
#define HTTP_PORT 80
#define HTTP_OK 200

//Function declarations
void output_error(char* error_message);
void http_request(char* hostname, char* path, char* method);
void extract_response_data(char* response, int response_length);

int main(int argc, char** argv) {
    if(argc != 4) {
        output_error("Usage: http_client <hostname> <path> <method>");
        return -1;
    }

    //Extract command line args
    char* hostname = argv[1];
    char* path = argv[2];
    char* method = argv[3];

    //Make HTTP request
    http_request(hostname, path, method);

    return 0;
}

void output_error(char* error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
}

void http_request(char* hostname, char* path, char* method) {
    struct hostent *he;
    struct sockaddr_in server_address;
    char request_buffer[MAX_REQUEST_LEN];
    char response_buffer[MAX_RESPONSE_LEN];
    int request_length;
    int response_length;
    int client_socket;

    //Resolve hostname
    if((he = gethostbyname(hostname)) == NULL) {
        output_error("Could not resolve hostname");
        return;
    }

    //Set up server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr*)he->h_addr);
    server_address.sin_port = htons(HTTP_PORT);

    //Create socket and connect to server
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        output_error("Could not create socket");
        return;
    }
    if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        output_error("Could not connect to server");
        return;
    }

    //Send HTTP request
    sprintf(request_buffer, "%s %s HTTP/1.0\r\nHost: %s\r\n\r\n", method, path, hostname);
    request_length = strlen(request_buffer);
    if(send(client_socket, request_buffer, request_length, 0) == -1) {
        output_error("Error sending request");
        return;
    }

    //Receive HTTP response
    response_length = recv(client_socket, response_buffer, MAX_RESPONSE_LEN - 1, 0);
    if(response_length == -1) {
        output_error("Error receiving response");
        return;
    }

    //Close socket
    close(client_socket);

    //Extract response data
    extract_response_data(response_buffer, response_length);
}

void extract_response_data(char* response, int response_length) {
    int i = 0;
    int status_code = 0;
    bool response_ok = false;

    //Extract status code
    while(i < response_length - 3) {
        if(response[i] == ' ' && response[i + 1] >= '0' && response[i + 1] <= '9' && response[i + 2] >= '0' && response[i + 2] <= '9' && response[i + 3] >= '0' && response[i + 3] <= '9') {
            status_code = (response[i + 1] - '0') * 100 + (response[i + 2] - '0') * 10 + (response[i + 3] - '0');
            break;
        }
        i++;
    }

    //Check if response was OK
    if(status_code == HTTP_OK) {
        response_ok = true;
    }

    //Extract and output response body
    if(response_ok) {
        char* response_body_start = strstr(response, "\r\n\r\n") + 4;
        printf("%s", response_body_start);
    } else {
        output_error("HTTP request failed");
    }
}