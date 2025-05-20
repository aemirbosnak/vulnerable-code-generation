//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 993

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *username = "sherlock"; // example username
    char *password = "elementary"; // example password
    char buffer[1024] = {0};
    char email_ids[1024] = {0};

    // connect to server
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // convert IP address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // login with username and password
    char *login_message = "a001 LOGIN ";
    strcat(login_message, username);
    strcat(login_message, " ");
    strcat(login_message, password);
    strcat(login_message, "\r\n");

    send(sock, login_message, strlen(login_message), 0);
    valread = read(sock, buffer, 1024);

    // check if login successful
    if (strstr(buffer, "OK") == NULL) {
        printf("Login Failed\n");
        return -1;
    }

    // get list of emails
    char *list_message = "a002 LIST \"\" *\r\n";
    send(sock, list_message, strlen(list_message), 0);
    valread = read(sock, buffer, 1024);
    strncpy(email_ids, buffer, 1024);
    memset(buffer, 0, 1024);

    // print email IDs
    printf("List of Email IDs:\n");
    char *token = strtok(email_ids, "\r\n");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "\r\n");
    }

    // logout
    char *logout_message = "a003 LOGOUT\r\n";
    send(sock, logout_message, strlen(logout_message), 0);
    return 0;
}