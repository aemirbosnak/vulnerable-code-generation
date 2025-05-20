//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int connect_to_server(char* server_address, int port) {
    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(server_address);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to server\n");
        exit(1);
    }

    return sockfd;
}

int receive_data(int sockfd, char* response) {
    char buffer[4096] = {0};
    int n = read(sockfd, buffer, 4096);
    strncpy(response, buffer, n);
    return n;
}

void send_command(int sockfd, char* command) {
    char buffer[4096] = {0};
    strncpy(buffer, command, strlen(command));
    write(sockfd, buffer, strlen(buffer));
}

char* get_user_input(char* prompt) {
    printf("%s", prompt);
    char* input = (char*)malloc(sizeof(char)*4096);
    fgets(input, 4096, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

int main() {
    char server_address[64];
    int port;
    char* username;
    char* password;
    char response[4096] = {0};
    int sockfd;

    printf("Welcome! Let's connect to your IMAP server.\n");

    // Get IMAP server details from user
    strcpy(server_address, get_user_input("Server address: "));
    port = atoi(get_user_input("Port: "));
    username = get_user_input("Username: ");
    password = get_user_input("Password: ");

    // Connect to the server
    sockfd = connect_to_server(server_address, port);

    // Receive and print the server greeting
    receive_data(sockfd, response);
    printf("%s", response);

    // Send the LOGIN command with the user's credentials
    char login_command[100];
    snprintf(login_command, 100, "LOGIN %s %s\r\n", username, password);
    send_command(sockfd, login_command);

    // Receive and print the response to the LOGIN command
    receive_data(sockfd, response);
    printf("%s", response);

    // Send the LIST command to get a list of mailboxes
    send_command(sockfd, "LIST \"\" *\r\n");

    // Receive and print the response to the LIST command
    receive_data(sockfd, response);
    printf("%s", response);

    // Send the SELECT command to select a mailbox
    char select_command[100];
    snprintf(select_command, 100, "SELECT %s\r\n", get_user_input("Mailbox name: "));
    send_command(sockfd, select_command);

    // Receive and print the response to the SELECT command
    receive_data(sockfd, response);
    printf("%s", response);

    // Send the LOGOUT command to close the connection
    send_command(sockfd, "LOGOUT\r\n");

    // Receive and print the response to the LOGOUT command
    receive_data(sockfd, response);
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}