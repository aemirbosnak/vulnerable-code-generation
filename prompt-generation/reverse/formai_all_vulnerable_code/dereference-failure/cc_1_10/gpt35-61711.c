//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAXLINE 1024
#define MAXUSERNAME 50
#define MAXPASSWORD 50

void print_mail(char* mail) {
    printf("%s\n", mail);
}

void connect_to_server(char* address, int port, int* sockfd) {
    struct sockaddr_in servaddr;
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed.\n");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if(inet_pton(AF_INET, address, &servaddr.sin_addr) <= 0) {
        printf("Invalid address.\n");
        exit(1);
    }
    if (connect(*sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed.\n");
        exit(1);
    }
}

void send_command(char* command, int sockfd) {
    send(sockfd, command, strlen(command), 0);
    printf("Command: %s sent.\n", command);
}

char* receive_response(int sockfd) {
    char buffer[MAXLINE];
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, MAXLINE, 0);
    printf("Received: %s\n", buffer);
    return strdup(buffer);
}

int login(char* username, char* password, int sockfd) {
    char login_command[MAXLINE],* response;
    memset(login_command, 0, sizeof(login_command));
    sprintf(login_command, "login %s %s\n", username, password);
    send_command(login_command, sockfd);
    response = receive_response(sockfd);
    if(strstr(response, "OK") != NULL) {
        printf("Logged in successfully.\n");
        return 1;
    } else {
        printf("Login failed.\n");
        return 0;
    }
}

void fetch_mail(int sockfd) {
    char* response;
    send_command("select inbox\n", sockfd);
    response = receive_response(sockfd);
    if(strstr(response, "OK") != NULL) {
        printf("Found mailbox.\n");
        send_command("fetch 1:10 (body[])\n", sockfd);
        response = receive_response(sockfd);
        while(strstr(response, "END") == NULL) {
            print_mail(response);
            response = receive_response(sockfd);
        }
        printf("Finished fetching mail.\n");
    } else {
        printf("Mailbox not found.\n");
    }
}

int main() {
    int sockfd, port = 143;
    char address[] = "localhost", username[MAXUSERNAME], password[MAXPASSWORD];
    printf("Enter username: ");
    fgets(username, MAXUSERNAME, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Enter password: ");
    fgets(password, MAXPASSWORD, stdin);
    password[strcspn(password, "\n")] = 0;
    connect_to_server(address, port, &sockfd);
    if(login(username, password, sockfd)) {
        fetch_mail(sockfd);
    }
    close(sockfd);
    return 0;
}