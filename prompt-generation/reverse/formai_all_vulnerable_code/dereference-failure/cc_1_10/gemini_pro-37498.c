//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// Function to establish a connection with the FTP server
int connect_to_server(char *ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }
    
    return sockfd;
}

// Function to send a command to the FTP server
void send_command(int sockfd, char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Command sending failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a response from the FTP server
void receive_response(int sockfd) {
    char buffer[1024];
    
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Response receiving failed");
        exit(EXIT_FAILURE);
    }
    
    printf("%s", buffer);
}

// Function to list the files in the current directory on the FTP server
void list_files(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

// Function to download a file from the FTP server
void download_file(int sockfd, char *filename) {
    char buffer[1024];
    FILE *fp;
    
    send_command(sockfd, "RETR ");
    send_command(sockfd, filename);
    send_command(sockfd, "\r\n");
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }
    
    fclose(fp);
}

// Function to upload a file to the FTP server
void upload_file(int sockfd, char *filename) {
    char buffer[1024];
    FILE *fp;
    
    send_command(sockfd, "STOR ");
    send_command(sockfd, filename);
    send_command(sockfd, "\r\n");
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        send(sockfd, buffer, strlen(buffer), 0);
    }
    
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    int sockfd;
    
    if (argc != 3) {
        printf("Usage: %s <ip address> <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    sockfd = connect_to_server(argv[1]);
    receive_response(sockfd);
    
    if (strcmp(argv[2], "LIST") == 0) {
        list_files(sockfd);
    } else if (strcmp(argv[2], "DOWNLOAD") == 0) {
        download_file(sockfd, argv[3]);
    } else if (strcmp(argv[2], "UPLOAD") == 0) {
        upload_file(sockfd, argv[3]);
    } else {
        printf("Invalid command\n");
    }
    
    close(sockfd);
    return 0;
}