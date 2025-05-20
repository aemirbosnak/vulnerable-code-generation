//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int sock_desc;
    struct sockaddr_in server;
    struct hostent *host;
    char message[1024], buffer[1024];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    /* Create socket */
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_desc == -1) {
        printf("Could not create socket");
        exit(1);
    }

    /* Set server details */
    host = gethostbyname(argv[1]);
    server.sin_addr = *((struct in_addr *) host->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    /* Connect to server */
    if (connect(sock_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Could not connect to server");
        exit(1);
    }

    /* Receive welcome message */
    if (recv(sock_desc, buffer, 1024, 0) < 0) {
        printf("Error receiving welcome message from server");
        exit(1);
    }

    printf("Server message: %s\n", buffer);

    /* Send login credentials */
    sprintf(message, "a001 LOGIN johnsmith secretpassword\r\n");
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Error sending login credentials to server");
        exit(1);
    }

    /* Receive response */
    if (recv(sock_desc, buffer, 1024, 0) < 0) {
        printf("Error receiving response from server");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    /* Send command to list folders */
    sprintf(message, "a002 LIST \"\" *\r\n");
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Error sending command to list folders to server");
        exit(1);
    }

    /* Receive response */
    if (recv(sock_desc, buffer, 1024, 0) < 0) {
        printf("Error receiving response from server");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    /* Logout and close connection */
    sprintf(message, "a003 LOGOUT\r\n");
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Error sending logout command to server");
        exit(1);
    }

    close(sock_desc);

    return 0;
}