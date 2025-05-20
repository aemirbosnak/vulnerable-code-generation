//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

// Function to connect to POP3 server
void connect_to_pop3_server(char *server_address, char *port_number, char *username, char *password) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port_number));
    serv_addr.sin_addr.s_addr = inet_addr(server_address);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server.\n");

    // Send username and password to server
    char command[1024];
    sprintf(command, "USER %s %s\r\n", username, password);
    write(sockfd, command, strlen(command));

    printf("Sent username and password.\n");

    // Receive and print server response
    char response[1024];
    if (read(sockfd, response, sizeof(response)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", response);

    // Send OK command to continue
    sprintf(command, "OK\r\n");
    write(sockfd, command, strlen(command));

    printf("Sent OK command.\n");

    // Receive and print server response
    if (read(sockfd, response, sizeof(response)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", response);

    close(sockfd);
    return;
}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        printf("Usage: %s server_address port_number username password\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    connect_to_pop3_server(argv[1], argv[2], argv[3], argv[4]);

    return 0;
}