//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_file(int sockfd, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        if (send(sockfd, buffer, bytes_read, 0) != bytes_read) {
            printf("Error while sending file %s\n", filename);
            break;
        }
        bzero(buffer, BUFFER_SIZE);
    }

    fclose(fp);
}

void receive_file(int sockfd, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Could not create file %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
        bzero(buffer, BUFFER_SIZE);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <server_ip> <server_port> <username> <password>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    int bytes_received;

    // Send username
    bzero(username, BUFFER_SIZE);
    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    send(sockfd, username, strlen(username), 0);

    // Send password
    bzero(password, BUFFER_SIZE);
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    send(sockfd, password, strlen(password), 0);

    // Authentication result
    bzero(buffer, BUFFER_SIZE);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strcmp(buffer, "success\n") == 0) {
        printf("Authentication successful\n");
    } else {
        printf("Authentication failed\n");
        return 1;
    }

    // User menu
    while (1) {
        printf("\n1. Send file\n");
        printf("2. Receive file\n");
        printf("3. Exit\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: // Send file
                printf("Enter file name: ");
                bzero(buffer, BUFFER_SIZE);
                fgets(buffer, BUFFER_SIZE, stdin);
                strtok(buffer, "\n");

                // Send file name
                send(sockfd, buffer, strlen(buffer), 0);

                // Send file
                send_file(sockfd, buffer);
                printf("File sent successfully!\n");
                break;

            case 2: // Receive file
                printf("Enter file name: ");
                bzero(buffer, BUFFER_SIZE);
                fgets(buffer, BUFFER_SIZE, stdin);
                strtok(buffer, "\n");

                // Send file name
                send(sockfd, buffer, strlen(buffer), 0);

                // Receive file
                receive_file(sockfd, buffer);
                printf("File received successfully!\n");
                break;

            case 3: // Exit
                close(sockfd);
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}