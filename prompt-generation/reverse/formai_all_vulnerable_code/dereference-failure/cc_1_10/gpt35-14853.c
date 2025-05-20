//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void handle_error(char *error_message) {
    fprintf(stderr, "Error: %s, Errno: %d, %s\n",
            error_message, errno, strerror(errno));
    exit(1);
}

void send_command(int sock, char *command) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int command_length = strlen(command);
    if (command_length != write(sock, command, command_length)) {
        handle_error("Failed to send command");
    }
    read(sock, buffer, BUFFER_SIZE);
    printf("Command response: %s", buffer);
}

void receive_mail(int sock) {
    send_command(sock, "LIST\r\n");
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    int message_count;
    sscanf(buffer, "+OK %d", &message_count);
    printf("Messages: %d\n", message_count);
    for (int i = 1; i <= message_count; i++) {
        printf("Message %d:\n", i);
        char command[BUFFER_SIZE];
        sprintf(command, "RETR %d\r\n", i);
        send_command(sock, command);
        while(1) {
            memset(buffer, 0, BUFFER_SIZE);
            read(sock, buffer, BUFFER_SIZE);
            if (strncmp(buffer, ".\r\n", 3) == 0) {
                break;
            }
            printf("%s", buffer);
        }
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        handle_error("Failed to create socket");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        handle_error("Invalid address/Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        handle_error("Failed to connect to server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    if (strncmp(buffer, "+OK", 3) != 0) {
        handle_error("Invalid server greeting");
    }

    char username[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    char password[BUFFER_SIZE];
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    sprintf(buffer, "USER %s\r\n", username);
    send_command(sock, buffer);
    sprintf(buffer, "PASS %s\r\n", password);
    send_command(sock, buffer);

    receive_mail(sock);

    close(sock);
    return 0;
}