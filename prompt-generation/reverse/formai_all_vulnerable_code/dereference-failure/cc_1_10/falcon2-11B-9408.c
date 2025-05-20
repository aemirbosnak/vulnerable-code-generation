//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_response(int client_socket, const char *message, int status_code) {
    char response[1024];
    int response_size;

    snprintf(response, sizeof(response), "HTTP/1.1 %d %s\r\n", status_code, message);
    snprintf(response + strlen(response), sizeof(response) - strlen(response), "\r\n");

    response_size = strlen(response);
    send(client_socket, response, response_size, 0);
}

void handle_client(int client_socket, const char *request_header, const char *request_body) {
    char response_header[1024];
    char response_body[1024];
    int response_size;
    int status_code;

    // Parse request header
    char *header_value;
    char *header_name;
    char *header_name_value_pair;
    char *header_name_value_pairs[1024];

    strcpy(response_header, request_header);
    strcat(response_header, "\r\n");

    // Parse request body
    int i;
    for (i = 0; i < strlen(request_body); i++) {
        if (request_body[i] == '\r') {
            break;
        }
    }
    strcpy(response_body, request_body + i + 1);

    // Set status code based on request method
    if (strcmp(request_header, "GET") == 0) {
        status_code = 200;
        header_name_value_pairs[0] = "Content-Type";
        header_name_value_pairs[1] = "text/html";
        header_name_value_pairs[2] = "text/plain";
    } else if (strcmp(request_header, "POST") == 0) {
        status_code = 201;
        header_name_value_pairs[0] = "Location";
        header_name_value_pairs[1] = "https://example.com";
        header_name_value_pairs[2] = "text/html";
        header_name_value_pairs[3] = "text/plain";
    } else {
        status_code = 404;
        header_name_value_pairs[0] = "Content-Type";
        header_name_value_pairs[1] = "text/html";
        header_name_value_pairs[2] = "text/plain";
    }

    // Set response header
    header_name_value_pair = header_name_value_pairs[0];
    header_value = header_name_value_pair + strlen(header_name_value_pair) + 2;
    header_name = header_name_value_pair;
    while (header_name[strlen(header_name) - 1] == ':') {
        header_name[strlen(header_name) - 1] = '\0';
        header_value[strlen(header_value) - 1] = '\0';
        header_value += strlen(header_value) + 2;
        header_name_value_pair++;
    }
    strcat(response_header, header_name);
    strcat(response_header, ": ");
    strcat(response_header, header_value);
    strcat(response_header, "\r\n");

    // Set response body
    strcat(response_body, header_name_value_pairs[1]);
    strcat(response_body, "\r\n");

    response_size = strlen(response_header) + strlen(response_body) + 2;
    send(client_socket, response_header, response_size, 0);
    send(client_socket, response_body, strlen(response_body), 0);
}

int main(int argc, char **argv) {
    int client_socket;
    struct sockaddr_in client_address;
    struct hostent *client_host;
    int client_port;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    client_port = atoi(argv[1]);

    client_host = gethostbyname("localhost");
    if (client_host == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    client_address.sin_family = AF_INET;
    bcopy((char *)client_host->h_addr, (char *)&client_address.sin_addr.s_addr, client_host->h_length);
    client_address.sin_port = htons(client_port);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        fprintf(stderr, "Error: socket failed\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) == -1) {
        fprintf(stderr, "Error: connect failed\n");
        exit(1);
    }

    while (1) {
        char request_header[1024];
        char request_body[1024];
        int request_header_size;
        int request_body_size;

        request_header_size = recv(client_socket, request_header, sizeof(request_header), 0);
        if (request_header_size == -1) {
            fprintf(stderr, "Error: recv failed\n");
            exit(1);
        }

        request_body_size = recv(client_socket, request_body, sizeof(request_body), 0);
        if (request_body_size == -1) {
            fprintf(stderr, "Error: recv failed\n");
            exit(1);
        }

        handle_client(client_socket, request_header, request_body);

        close(client_socket);
    }

    return 0;
}