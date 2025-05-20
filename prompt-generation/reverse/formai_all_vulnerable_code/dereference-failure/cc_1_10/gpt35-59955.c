//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
 
#define BUFFER_SIZE 1024
#define POP3_PORT 110
 
void print_error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int create_socket(const char* server_name, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        print_error("Failed to create socket.");
    }
 
    struct hostent* server = gethostbyname(server_name);
    if (server == NULL) {
        print_error("Failed to find server.");
    }
 
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
 
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        print_error("Failed to connect to server.");
    }

    return sock;
}

void receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (recv(sock, buffer, BUFFER_SIZE - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
}

void send_request(int sock, const char* request, const char* expected_response) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (send(sock, request, strlen(request), 0) < 0) {
        print_error("Failed to send request.");
    }
    
    receive_data(sock);

    if (expected_response != NULL) {
        if (recv(sock, buffer, BUFFER_SIZE - 1, 0) < 0) {
            print_error("Failed to receive server response.");
        }
        if (strstr(buffer, expected_response) == NULL) {
            printf("Error: Expected %s but received %s\n", expected_response, buffer);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: pop3client [server name] [user name] [password]\n");
        exit(EXIT_FAILURE);
    }

    const char* server_name = argv[1];
    const char* user_name = argv[2];
    const char* password = argv[3];

    int sock = create_socket(server_name, POP3_PORT);

    send_request(sock, "USER ", NULL);
    send_request(sock, user_name, "+OK");

    send_request(sock, "PASS ", NULL);
    send_request(sock, password, "+OK");

    send_request(sock, "LIST\r\n", "+OK");
    send_request(sock, "QUIT\r\n", "+OK");

    close(sock);
    return 0;
}