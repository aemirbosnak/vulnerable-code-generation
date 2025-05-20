//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int retrieveEmails(char* username, char* password, char* server, int port) {
    // create TCP socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr(server);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection to server failed.\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Login to server
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock_fd, buffer, strlen(buffer), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);

    memset(buffer, 0, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock_fd, buffer, strlen(buffer), 0);
    recv(sock_fd, buffer, BUFFER_SIZE, 0);

    memset(buffer, 0, BUFFER_SIZE);

    // List number of emails in inbox
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer); // print server response

    char* token = strtok(buffer, " "); // get number of emails in inbox
    token = strtok(NULL, " ");

    int total_emails = atoi(token);

    // Retrieve each email
    for (int i = 1; i <= total_emails; i++) {
        snprintf(buffer, BUFFER_SIZE, "RETR %d\r\n", i);
        send(sock_fd, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);

        // create file to store email
        char filename[BUFFER_SIZE];
        snprintf(filename, BUFFER_SIZE, "email_%d.txt", i);
        FILE* email_file = fopen(filename, "w");

        // read email data from server and write to file
        int bytes_received = 0;
        while ((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            fwrite(buffer, 1, bytes_received, email_file);

            if (strstr(buffer, "\r\n.\r\n")) { // check if end of email data
                break;
            }

            memset(buffer, 0, BUFFER_SIZE);
        }

        fclose(email_file); // close email file
    }

    // quit session
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    send(sock_fd, buffer, strlen(buffer), 0);

    recv(sock_fd, buffer, BUFFER_SIZE, 0); // print server response
    printf("%s", buffer);

    // close socket
    close(sock_fd);

    return 0;
}

int main() {
    char* username = "exampleuser";
    char* password = "examplepassword";
    char* server = "pop.example.com";
    int port = 110;

    retrieveEmails(username, password, server, port);

    return 0;
}