//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

void ftp_login(int sockfd) {
    char buffer[BUFFER_SIZE];
    
    // Sending USER command
    printf("Enter username: ");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");  // Remove newline character
    write(sockfd, buffer, strlen(buffer));
    write(sockfd, "\r\n", 2); // FTP commands end with CRLF
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    
    // Sending PASS command
    printf("Enter password: ");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n");  // Remove newline character
    write(sockfd, buffer, strlen(buffer));
    write(sockfd, "\r\n", 2);
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

void ftp_get(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
    write(sockfd, buffer, strlen(buffer));
    
    read(sockfd, buffer, sizeof(buffer)); // Read response
    printf("%s", buffer);
    
    if (strstr(buffer, "150") != NULL) { // Start of data transmission
        FILE *fp = fopen(filename, "wb");
        if (fp == NULL) {
            error("Could not open file");
        }
        
        while (1) {
            ssize_t bytesRead = read(sockfd, buffer, sizeof(buffer));
            if (bytesRead <= 0) {
                break; // End of file or error
            }
            fwrite(buffer, 1, bytesRead, fp);
        }
        fclose(fp);
        
        read(sockfd, buffer, sizeof(buffer)); // Read completion message
        printf("%s", buffer);
    }
}

void ftp_put(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "STOR %s\r\n", filename);
    write(sockfd, buffer, strlen(buffer));

    read(sockfd, buffer, sizeof(buffer)); // Read response
    printf("%s", buffer);
    
    if (strstr(buffer, "150") != NULL) { // Ready to accept data
        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
            error("Could not open file");
        }
        
        while (!feof(fp)) {
            ssize_t bytesRead = fread(buffer, 1, sizeof(buffer), fp);
            write(sockfd, buffer, bytesRead);
        }
        fclose(fp);
        
        read(sockfd, buffer, sizeof(buffer)); // Read completion message
        printf("%s", buffer);
    }
}

int ftp_connect(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *he;

    if ((he = gethostbyname(hostname)) == NULL) { // get the host info
        herror("gethostbyname");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, he->h_addr, he->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }
    
    return sockfd;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    int sockfd = ftp_connect(hostname, port);
    
    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, sizeof(buffer)); // Read server greeting
    printf("%s", buffer);

    ftp_login(sockfd);
    
    while (1) {
        printf("\nEnter command (GET <filename>/PUT <filename>/EXIT): ");
        fgets(buffer, sizeof(buffer), stdin);
        strtok(buffer, "\n"); // Remove newline

        if (strncmp(buffer, "GET", 3) == 0) {
            ftp_get(sockfd, buffer + 4);
        } else if (strncmp(buffer, "PUT", 3) == 0) {
            ftp_put(sockfd, buffer + 4);
        } else if (strncmp(buffer, "EXIT", 4) == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    close(sockfd);
    return 0;
}