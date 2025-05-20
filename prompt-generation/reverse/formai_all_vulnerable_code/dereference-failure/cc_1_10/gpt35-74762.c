//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_SERVER "pop3.example.com" // Replace with actual POP3 server
#define POP3_PORT 110 // Standard POP3 port

struct pop3_response {
    int code;
    char *message;
};

struct pop3_response *pop3_send_command(int sock, const char *command) {
    char buffer[1024];
    struct pop3_response *response = malloc(sizeof(struct pop3_response));
    ssize_t bytes_sent = send(sock, command, strlen(command), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    response->code = atoi(buffer);
    response->message = strdup(buffer + 4);
    return response;
}

int main(int argc, char **argv) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct hostent *server = gethostbyname(POP3_SERVER);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", POP3_SERVER);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    struct pop3_response *response = pop3_send_command(sock, "USER username@example.com\r\n");
    printf("Response code: %d\nMessage: %s\n", response->code, response->message);
    free(response->message);
    free(response);
    response = pop3_send_command(sock, "PASS password123\r\n");
    printf("Response code: %d\nMessage: %s\n", response->code, response->message);
    free(response->message);
    free(response);
    response = pop3_send_command(sock, "STAT\r\n");
    printf("Response code: %d\nMessage: %s\n", response->code, response->message);
    free(response->message);
    free(response);
    close(sock);
    return 0;
}