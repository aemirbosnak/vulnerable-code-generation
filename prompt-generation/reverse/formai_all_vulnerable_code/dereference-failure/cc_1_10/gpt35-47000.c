//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

bool connect_to_server(char *server_address, int port_number);

void send_command(char *command);

char *receive_data();

int sockfd;

int main() {
    char *server_address = "imap.gmail.com";
    int port_number = 993;

    // connect to the server
    if (!connect_to_server(server_address, port_number)) {
        printf("Failed to connect to server.\n");
        exit(1);
    }

    // authenticate user
    send_command("1 LOGIN username password");
    char *response = receive_data();
    if (strstr(response, "OK") != NULL) {
        printf("Successfully logged in.\n");
    } else {
        printf("Failed to log in.\n");
        exit(1);
    }

    // get mailbox list
    send_command("2 LIST \"\" *");
    response = receive_data();
    printf("Mailboxes:\n");
    printf("%s", response);

    // logout and close connection
    send_command("3 LOGOUT");
    close(sockfd);

    return 0;
}

bool connect_to_server(char *server_address, int port_number) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return false;
    }

    server = gethostbyname(server_address);
    if (server == NULL) {
        return false;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        return false;
    }

    return true;
}

void send_command(char *command) {
    char buffer[MAX_BUFF_SIZE];
    sprintf(buffer, "%s\r\n", command);
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Failed to send command.\n");
        exit(1);
    }
}

char *receive_data() {
    char buffer[MAX_BUFF_SIZE];
    bzero(buffer, MAX_BUFF_SIZE);
    int n = read(sockfd, buffer, MAX_BUFF_SIZE - 1);
    if (n < 0) {
        printf("Failed to receive data.\n");
        exit(1);
    }
    return strdup(buffer);
}