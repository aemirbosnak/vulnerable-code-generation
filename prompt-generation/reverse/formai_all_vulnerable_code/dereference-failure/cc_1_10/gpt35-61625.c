//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INPUT 1024
#define MAX_RESP 4096

/* Function to get user input */
char* get_input(char* prompt) {
    char* input = (char*) malloc(sizeof(char) * MAX_INPUT);
    printf("%s", prompt);
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character
    return input;
}

int main() {
    char* server = get_input("Enter server address: ");
    char* user = get_input("Enter username: ");
    char* password = get_input("Enter password: ");

    /* Create socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    /* Get server IP address */
    struct hostent* host = gethostbyname(server);
    if (!host) {
        printf("Error getting host name.\n");
        exit(EXIT_FAILURE);
    }

    /* Configure server address and port */
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)host->h_addr_list[0]));
    server_addr.sin_port = htons(110);  // Pop3 port number

    /* Connect to server */
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    /* Receive welcome message */
    char response[MAX_RESP];
    recv(sock, response, MAX_RESP, 0);
    printf("%s", response);

    /* Send login credentials */
    char command[MAX_INPUT];
    sprintf(command, "USER %s\r\n", user);
    send(sock, command, strlen(command), 0);
    recv(sock, response, MAX_RESP, 0);
    printf("%s", response);
    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    recv(sock, response, MAX_RESP, 0);
    printf("%s", response);

    /* Get number of emails */
    sprintf(command, "STAT\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, response, MAX_RESP, 0);
    printf("%s", response);

    /* Close connection */
    sprintf(command, "QUIT\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, response, MAX_RESP, 0);
    printf("%s", response);
    close(sock);
    printf("Connection closed.\n");

    /* Free memory */
    free(server);
    free(user);
    free(password);

    return 0;
}