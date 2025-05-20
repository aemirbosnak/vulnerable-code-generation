//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {

    int client_socket, port, n;
    struct sockaddr_in server;
    char message[MAXSIZE], response[MAXSIZE];
    struct hostent *host;

    // Checking the command line usage
    if(argc < 3) {
        printf("\nUsage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Creating a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        printf("\nCould not create socket!\n");
        exit(1);
    }

    // Checking the hostname
    host = gethostbyname(argv[1]);
    if(host == NULL) {
        printf("\nCould not resolve hostname!\n");
        exit(1);
    }

    // Setting up server parameters
    port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr*) host->h_addr);
    memset(&(server.sin_zero), 0, 8);

    // Connecting to server
    if(connect(client_socket, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("\nCould not connect to server!\n");
        exit(1);
    }

    // Logging in to SMTP server
    sprintf(message,"EHLO %s\r\n", argv[1]);
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    // Sending a test email
    sprintf(message, "MAIL FROM:<from@example.com>\r\n");
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    sprintf(message, "RCPT TO:<to@example.com>\r\n");
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    sprintf(message, "DATA\r\n");
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    sprintf(message, "From:<from@example.com>\r\nTo:<to@example.com>\r\nSubject: Test email\r\n\r\nThis is a test email sent using a SMTP client.\r\n.\r\n");
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    // Logging out of SMTP server
    sprintf(message, "Quit\r\n");
    send(client_socket, message, strlen(message), 0);
    n = recv(client_socket, response, MAXSIZE, 0);
    response[n] = '\0';
    printf("%s\n", response);

    close(client_socket);
    return 0;
}