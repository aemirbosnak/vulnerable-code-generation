//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define SERVER_PORT 21
#define BUF_SIZE 1024

int create_socket(char *ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation error.\n");
        exit(EXIT_FAILURE);
    }
    
    // Setup server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip_address, &server_addr.sin_addr)<=0){
        printf("Invalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Connection Error.\n");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void read_response(int sockfd, char *buffer){
    int response;
    response = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[response] = '\0';
    printf("%s", buffer);
}

void send_data(int sockfd, char *data){
    int data_length = strlen(data);
    if (send(sockfd, data, data_length, 0) != data_length){
        perror("Send failed.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Please provide remote ftp server address.\n");
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];

    printf("Connecting to %s\n", ip_address);

    // Create socket and connect to server
    int sockfd = create_socket(ip_address);
    char buffer[BUF_SIZE];

    // Read server response
    read_response(sockfd, buffer);

    // Send username
    printf("Enter username: ");
    fgets(buffer, BUF_SIZE, stdin);
    char username[BUF_SIZE];
    strcpy(username, buffer);
    send_data(sockfd, username);

    // Read server response
    read_response(sockfd, buffer);

    // Send password
    printf("Enter password: ");
    fgets(buffer, BUF_SIZE, stdin);
    char password[BUF_SIZE];
    strcpy(password, buffer);
    send_data(sockfd, password);

    // Read server response
    read_response(sockfd, buffer);

    // Send passive mode command
    char *pasv = "PASV\r\n";
    send_data(sockfd, pasv);

    // Read server response for the passive mode command
    read_response(sockfd, buffer);

    // Parse the server response to get the port to use for data transfer
    // The expected response for PASV command is of the form 227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).
    int h1, h2, h3, h4, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &h1, &h2, &h3, &h4, &p1, &p2);
    int data_port = p1*256 + p2;

    // Create a new socket for data transfer and connect to server
    int data_socket = create_socket(ip_address);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(data_socket, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0){
        perror("Connection Error.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server on data port %d\n", data_port);

    // Send RETR command to get file from server
    char *retr = "RETR test.txt\r\n";
    send_data(sockfd, retr);

    // Read server response for RETR command
    read_response(sockfd, buffer);

    if (strncmp("550", buffer, 3) == 0){
        printf("File not found on server.\n");
        return EXIT_FAILURE;
    }

    // Open file to write file data
    int file = open("received_file.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
    if(file == -1){
        perror("Failed to open file for writing.\n");
        return EXIT_FAILURE;
    }

    ssize_t n;
    char buff[BUF_SIZE];
    while ((n = read(data_socket, buff, BUF_SIZE)) > 0){
        write(file, buff, n);
    }

    if (n == -1){
        perror("Failed to read data from server.\n");
        return EXIT_FAILURE;
    }

    printf("File received successfully and saved as received_file.txt\n");

    // Close connections and file
    close(sockfd);
    close(data_socket);
    close(file);

    return EXIT_SUCCESS;
}