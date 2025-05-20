//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CMD_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024

void print_surrealist(char *message) {
    printf("The moon speaks in riddles: %s\n", message);
}

int connect_to_server(char *hostname, int port) {
    struct hostent *host_info;
    struct sockaddr_in server_address;
    int sock_fd;

    host_info = gethostbyname(hostname);
    if (!host_info) {
        print_surrealist("The stars have gone into hiding, I cannot find the server.");
        return -1;
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        print_surrealist("I am trapped in a void with no socket to connect with.");
        return -1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *) host_info->h_addr);

    if (connect(sock_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        print_surrealist("The gatekeeper is blocking my way to the server.");
        return -1;
    }

    return sock_fd;
}

int send_command(int sock_fd, char *cmd) {
    int bytes_sent, total_sent = 0;

    while (total_sent < strlen(cmd)) {
        bytes_sent = send(sock_fd, cmd + total_sent, strlen(cmd) - total_sent, 0);
        if (bytes_sent < 0) {
            print_surrealist("The winds of fate have turned against me, I cannot send my command to the server.");
            return -1;
        }
        total_sent += bytes_sent;
    }

    return total_sent;
}

int receive_response(int sock_fd, char *response) {
    int bytes_recv, total_recv = 0;
    char buf[MAX_RESPONSE_LENGTH];

    do {
        bytes_recv = recv(sock_fd, buf, MAX_RESPONSE_LENGTH - 1, 0);
        if (bytes_recv < 0) {
            print_surrealist("The curse of the Sphinx, I cannot receive the server's response.");
            return -1;
        }
        buf[bytes_recv] = '\0';
        strcat(response, buf);
        total_recv += bytes_recv;
    } while (bytes_recv == MAX_RESPONSE_LENGTH - 1);

    return total_recv;
}

int main(int argc, char *argv[]) {
    int sock_fd, port;
    char *hostname, cmd[MAX_CMD_LENGTH], response[MAX_RESPONSE_LENGTH] = "";
    if (argc != 3) {
        print_surrealist("I am lost in the labyrinth of argument parsing, please provide the hostname and port as command line arguments.");
        return -1;
    }
    hostname = argv[1];
    port = atoi(argv[2]);

    sock_fd = connect_to_server(hostname, port);
    if (sock_fd < 0) {
        return -1;
    }

    strcat(cmd, "HELO ");
    strcat(cmd, hostname);
    strcat(cmd, "\r\n");

    if (send_command(sock_fd, cmd) < 0) {
        return -1;
    }

    if (receive_response(sock_fd, response) < 0) {
        return -1;
    }
    print_surrealist(response);

    close(sock_fd);

    print_surrealist("The dream is over, I must wake up now.");
    return 0;
}