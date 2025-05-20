//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH 4096
#define MAX_BUFFER_SIZE 1024

void ftpConnect(int sockfd, char* ip_address) {
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(FTP_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ip_address);
    int connect_status = connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if(connect_status == -1) {
        perror("Error connecting to host");
        exit(1);
    }
}

void processCommand(const char* command, const char* expectedResponse, int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);
    if(strstr(buffer, expectedResponse) == NULL) {
        printf("Error processing command: %s\n", command);
        exit(1);
    }
}

void ftpLogin(int sockfd) {
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    char* loginCommand = (char*) malloc(MAX_COMMAND_LENGTH);
    sprintf(loginCommand, "USER %s\r\n", username);
    processCommand(loginCommand, "331", sockfd);
    sprintf(loginCommand, "PASS %s\r\n", password);
    processCommand(loginCommand, "230", sockfd);
    free(loginCommand);
}

void ftpRetrieve(int sockfd) {
    char filename[MAX_COMMAND_LENGTH];
    printf("Enter the file name: ");
    scanf("%s", filename);
    char* retrieveCommand = (char*) malloc(MAX_COMMAND_LENGTH);
    sprintf(retrieveCommand, "RETR %s\r\n", filename);
    processCommand(retrieveCommand, "150", sockfd);
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    while(1) {
        int bytesReceived = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if(bytesReceived <= 0) {
            break;
        }
        fwrite(buffer, bytesReceived, 1, fp);
        memset(buffer, 0, sizeof(buffer));
    }
    fclose(fp);
    free(retrieveCommand);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    ftpConnect(sockfd, argv[1]);
    processCommand("220", "220", sockfd);
    ftpLogin(sockfd);
    ftpRetrieve(sockfd);
    processCommand("226", "226", sockfd);
    printf("File downloaded successfully\n");
    close(sockfd);
    return 0;
}