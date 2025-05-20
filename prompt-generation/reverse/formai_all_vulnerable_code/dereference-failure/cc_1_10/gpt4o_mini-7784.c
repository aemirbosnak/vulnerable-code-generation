//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void parse_response(char *response) {
    int code;
    sscanf(response, "%d", &code);
    printf("Server Response: %s", response);
    if (code >= 200 && code < 300) {
        printf("Response Code: %d - Command successful.\n", code);
    } else {
        printf("Response Code: %d - Command failed.\n", code);
    }
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void get_file(int sockfd, const char *file_name) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    
    // Prepare the RETR command
    snprintf(command, sizeof(command), "RETR %s", file_name);
    send_command(sockfd, command);
    
    // Read response
    char response[BUFFER_SIZE];
    read(sockfd, response, sizeof(response));
    parse_response(response);
    
    // Assuming data socket already established
    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        error("Error opening file to write.");
    }
    
    // Receive the file data
    int bytes_received;
    while ((bytes_received = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }
    fclose(fp);
    printf("File %s received successfully.\n", file_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    
    // Get the server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error getting host by name.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server.");
    }

    // Read welcome message from server
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    read(sockfd, buffer, sizeof(buffer));
    parse_response(buffer);

    // Login to the server
    send_command(sockfd, "USER anonymous");
    read(sockfd, buffer, sizeof(buffer));
    parse_response(buffer);

    send_command(sockfd, "PASS anonymous");
    read(sockfd, buffer, sizeof(buffer));
    parse_response(buffer);

    // Get the file
    get_file(sockfd, argv[2]);

    send_command(sockfd, "QUIT");
    read(sockfd, buffer, sizeof(buffer));
    parse_response(buffer);

    close(sockfd);
    return 0;
}