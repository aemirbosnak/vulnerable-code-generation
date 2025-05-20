//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {

    // Step 1: Connect to the mail server
    int client_socket;
    struct sockaddr_in server_address;
    struct hostent *server;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error: could not create socket.\n");
        return 1;
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: no such host\n");
        return 1;
    }

    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char *)&server_address.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_address.sin_port = htons(POP3_PORT);

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server.\n");
        return 1;
    }

    // Step 2: Receive the server greeting
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive server greeting.\n");
        return 1;
    }

    printf("%s", buffer);

    // Step 3: Send the user identification
    char user_command[MAX_BUFFER_SIZE];
    char user_name[MAX_BUFFER_SIZE];

    printf("Enter your username: ");
    memset(user_name, 0, MAX_BUFFER_SIZE);
    fgets(user_name, MAX_BUFFER_SIZE, stdin);

    sprintf(user_command, "USER %s", user_name);
    send(client_socket, user_command, strlen(user_command), 0);

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive user identification response.\n");
        return 1;
    }

    printf("%s", buffer);

    // Step 4: Send the password identification
    char password_command[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];

    printf("Enter your password: ");
    memset(password, 0, MAX_BUFFER_SIZE);
    fgets(password, MAX_BUFFER_SIZE, stdin);

    sprintf(password_command, "PASS %s", password);
    send(client_socket, password_command, strlen(password_command), 0);

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive password identification response.\n");
        return 1;
    }

    printf("%s", buffer);

    // Step 5: List messages available
    char list_command[] = "LIST\n";
    send(client_socket, list_command, strlen(list_command), 0);

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        printf("Error: could not receive list response.\n");
        return 1;
    }

    printf("%s", buffer);

    // Step 6: Select a message to download
    char select_command[MAX_BUFFER_SIZE];
    char msg_number[MAX_BUFFER_SIZE];
    char *msg_body = NULL;
    int msg_size = 0;

    printf("Enter the message number you want to download: ");
    memset(msg_number, 0, MAX_BUFFER_SIZE);
    fgets(msg_number, MAX_BUFFER_SIZE, stdin);

    sprintf(select_command, "RETR %s", msg_number);
    send(client_socket, select_command, strlen(select_command), 0);

    // Step 7: Receive the selected message
    while (recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) > 0) {
        if (msg_body == NULL) {
            msg_body = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
        } else {
            msg_body = (char *)realloc(msg_body, (msg_size + strlen(buffer)) * sizeof(char));
        }

        strcpy(msg_body + msg_size, buffer);
        msg_size += strlen(buffer);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    printf("%s", msg_body);

    // Step 8: Exit gracefully
    free(msg_body);
    close(client_socket);

    return 0;
}