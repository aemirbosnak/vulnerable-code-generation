//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* receiveMessage(int sock) {
    char message[BUFFER_SIZE];
    memset(message, 0, BUFFER_SIZE);
    if (recv(sock, message, BUFFER_SIZE, 0) < 0) {
        perror("\nError receiving message: ");
        exit(EXIT_FAILURE);
    }
    message[strcspn(message, "\r\n")] = 0; // remove \r\n
    char* response = (char*) malloc(strlen(message) + 1);
    strcpy(response, message);
    return response;
}

void sendMessage(int sock, char* message) {
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("\nError sending message: ");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {

    char* server = "localhost"; // change this to the IP of your IMAP server
    char* username = "example@gmail.com"; // change this to your email username
    char* password = "password123"; // change this to your email password

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("\nError creating socket: ");
        exit(EXIT_FAILURE);
    }

    // set up server address struct
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(143); // IMAP server port
    serverAddress.sin_addr.s_addr = inet_addr(server);

    // connect to server
    if (connect(sock, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("\nError connecting to server: ");
        exit(EXIT_FAILURE);
    }

    // receive server greeting
    char* greeting = receiveMessage(sock);
    printf("%s\n", greeting);
    free(greeting);

    // send login command
    char* loginCommand = (char*) calloc(100, sizeof(char)); // avoid buffer overflow
    sprintf(loginCommand, "LOGIN %s %s\r\n", username, password);
    sendMessage(sock, loginCommand);
    free(loginCommand);

    // receive login response
    char* loginResponse = receiveMessage(sock);
    printf("%s\n", loginResponse);
    free(loginResponse);

    // send select inbox command
    char* selectCommand = "SELECT INBOX\r\n";
    sendMessage(sock, selectCommand);

    // receive select response
    char* selectResponse = receiveMessage(sock);
    printf("%s\n", selectResponse);
    free(selectResponse);

    // send list messages command
    char* listCommand = "FETCH 1:* BODY[HEADER.FIELDS (FROM TO SUBJECT)]\r\n";
    sendMessage(sock, listCommand);

    // receive list response
    char* listResponse;
    while (true) {
        listResponse = receiveMessage(sock);
        printf("%s\n", listResponse);
        if (strstr(listResponse, "OK FETCH completed") != NULL) {
            break;
        }
        free(listResponse);
    }
    free(listResponse);

    // send logout command
    char* logoutCommand = "LOGOUT\r\n";
    sendMessage(sock, logoutCommand);

    // receive logout response
    char* logoutResponse = receiveMessage(sock);
    printf("%s\n", logoutResponse);
    free(logoutResponse);

    // close socket
    close(sock);

    return 0;
}