//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

void receiveFile(int sockfd, char* filePath){
    char buffer[BUFFER_SIZE];
    FILE* file = fopen(filePath, "wb");
    if(file == NULL){
        printf("Failed to receive file\n");
        return;
    }
    while(1){
        int readBytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(readBytes <= 0){
            break;
        }
        fwrite(buffer, 1, readBytes, file);
    }
    fclose(file);
    printf("File received successfully\n");
}

void sendFile(int sockfd, char* filePath){
    char buffer[BUFFER_SIZE];
    FILE* file = fopen(filePath, "rb");
    if(file == NULL){
        printf("Failed to open file\n");
        return;
    }
    while(1){
        int readBytes = fread(buffer, 1, BUFFER_SIZE, file);
        if(readBytes <= 0){
            break;
        }
        send(sockfd, buffer, readBytes, 0);
    }
    fclose(file);
    printf("File sent successfully\n");
}

int main(int argc, char* argv[]){
    // Check arguments
    if(argc < 3){
        printf("Usage: ./ftpclient [server_ip] [server_port]\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Failed to create socket\n");
        return 1;
    }

    // Connect to server
    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    if(inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0){
        printf("Invalid server IP address\n");
        return 1;
    }
    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        printf("Failed to connect to server\n");
        return 1;
    }
    printf("Connected to server\n");

    while(1){
        printf("Enter command (get, put, quit): ");
        char command[BUFFER_SIZE];
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';

        if(strcmp(command, "get") == 0){
            char path[BUFFER_SIZE];
            printf("Enter file path: ");
            fgets(path, BUFFER_SIZE, stdin);
            path[strcspn(path, "\n")] = '\0';
            send(sockfd, "get", strlen("get"), 0);
            send(sockfd, path, strlen(path), 0);
            receiveFile(sockfd, path);
        }else if(strcmp(command, "put") == 0){
            char path[BUFFER_SIZE];
            printf("Enter file path: ");
            fgets(path, BUFFER_SIZE, stdin);
            path[strcspn(path, "\n")] = '\0';
            send(sockfd, "put", strlen("put"), 0);
            send(sockfd, path, strlen(path), 0);
            sendFile(sockfd, path);
        }else if(strcmp(command, "quit") == 0){
            send(sockfd, "quit", strlen("quit"), 0);
            break;
        }else{
            printf("Invalid command\n");
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}