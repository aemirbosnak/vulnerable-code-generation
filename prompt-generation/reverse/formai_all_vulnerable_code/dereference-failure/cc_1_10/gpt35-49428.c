//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    bool connected = false;

    struct hostent *server;
    struct sockaddr_in server_address = { 0 };
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);

    // Get server IP address
    server = gethostbyname("imap.gmail.com");
    if (server == NULL) {
        printf("Could not resolve hostname.\n");
        return EXIT_FAILURE;
    }
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1) {
        printf("Could not create socket.\n");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        printf("Could not connect to server.\n");
        return EXIT_FAILURE;
    }
    connected = true;

    // Authenticate with server
    char username[] = "example@gmail.com";
    char password[] = "examplepassword";
    char auth_buf[BUFFER_SIZE] = { 0 }, response[BUFFER_SIZE] = { 0 };
    sprintf(auth_buf, ". LOGIN %s %s\n", username, password);
    send(sockfd, auth_buf, strlen(auth_buf), 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
    // Check response from server for successful authentication

    // Select mailbox
    char mailbox[] = "INBOX";
    char select_buf[BUFFER_SIZE] = { 0 };
    sprintf(select_buf, ". SELECT %s\n", mailbox);
    send(sockfd, select_buf, strlen(select_buf), 0);
    recv(sockfd, response, BUFFER_SIZE, 0);

    // Read messages in mailbox
    char fetch_buf[BUFFER_SIZE] = { 0 };
    sprintf(fetch_buf, ". FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\n");
    send(sockfd, fetch_buf, strlen(fetch_buf), 0);
    while (1) {
        char buffer[BUFFER_SIZE] = { 0 };
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (strstr(buffer, "BAD") != NULL) {
            printf("Error reading messages.\n");
            return EXIT_FAILURE;
        }
        if (strstr(buffer, "UID ") != NULL) {
            // Handle message header - extract subject, from, and date fields
        }
        if (strstr(buffer, ") OK") != NULL) {
            break;
        }
    }

    // Disconnect from server
    if (connected) {
        send(sockfd, ". LOGOUT\n", 9, 0);
        recv(sockfd, response, BUFFER_SIZE, 0);
        close(sockfd);
    }

    printf("All done!\n");
    return EXIT_SUCCESS;
}