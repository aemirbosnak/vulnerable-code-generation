//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SIZE 1024

typedef struct {
    char* name;
    char* value;
} header_t;

typedef struct {
    int cnt;
    header_t* headers;
    char* body;
} response_t;

void error_quit(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

response_t* parse_response(char* resp_str) {
    response_t* response = malloc(sizeof(response_t));
    // get headers
    char* line = strtok(resp_str, "\r\n");
    while (line && strcmp(line, "")) {
        if (strstr(line, " ") == NULL) {
            error_quit("unable to parse response headers");
        }
        header_t* header = malloc(sizeof(header_t));
        header->name = strtok(line, ":");
        header->value = strtok(NULL, ":");
        response->headers = realloc(response->headers, sizeof(header_t) * (response->cnt + 1));
        response->headers[response->cnt++] = *header;
        line = strtok(NULL, "\r\n");
    }
    // get body
    if (line) {
        response->body = malloc(strlen(line) + 1);
        strcpy(response->body, line);
    }
    return response;
}

void show_header(header_t header) {
    printf("%s: %s\n", header.name, header.value);
}

void free_response(response_t* response) {
    for (int i = 0; i < response->cnt; i++) {
        free(response->headers[i].name);
        free(response->headers[i].value);
    }
    free(response->headers);
    free(response->body);
    free(response);
}

void receive_response(int socket_fd, char* resp_str) {
    int r;
    char buffer[SIZE];
    resp_str[0] = '\0';
    while ((r = recv(socket_fd, buffer, SIZE, 0)) > 0) {
        buffer[r] = '\0';
        strcat(resp_str, buffer);
    }
    if (r < 0) {
        error_quit("recv error");
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("usage: %s <server ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // connect to server
    char* server_ip = argv[1];
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        error_quit("socket error");
    }
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(110);
    if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        error_quit("connect error");
    }
    // receive welcome message
    char resp_str[SIZE];
    receive_response(socket_fd, resp_str);
    printf("%s", resp_str);
    // send username
    char user_str[SIZE];
    sprintf(user_str, "USER %s\r\n", argv[2]);
    if (send(socket_fd, user_str, strlen(user_str), 0) < 0) {
        error_quit("send error");
    }
    // receive response to username
    receive_response(socket_fd, resp_str);
    response_t* response = parse_response(resp_str);
    show_header(response->headers[0]);
    free_response(response);
    // send password
    char pass_str[SIZE];
    sprintf(pass_str, "PASS %s\r\n", argv[3]);
    if (send(socket_fd, pass_str, strlen(pass_str), 0) < 0) {
        error_quit("send error");
    }
    // receive response to password
    receive_response(socket_fd, resp_str);
    response = parse_response(resp_str);
    show_header(response->headers[0]);
    free_response(response);
    // send quit command
    if (send(socket_fd, "QUIT\r\n", 6, 0) < 0) {
        error_quit("send error");
    }
    // receive goodbye message
    receive_response(socket_fd, resp_str);
    printf("%s", resp_str);
    close(socket_fd);
    return 0;
}