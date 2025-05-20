//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define MAX_PATH 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

char *get_response(int sockfd) {
    static char buffer[BUFFER_SIZE];
    int n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("Error reading from socket");
    }
    buffer[n] = '\0';
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    char password[100];
    struct sockaddr_in server_addr;
    int sockfd;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Retrieve the server's IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Read server response
    printf("%s", get_response(sockfd));

    // Send username
    char login_cmd[MAX_PATH];
    snprintf(login_cmd, sizeof(login_cmd), "USER %s", username);
    send_command(sockfd, login_cmd);
    printf("%s", get_response(sockfd));

    // Send password
    printf("Enter Password: ");
    scanf("%s", password);
    char pass_cmd[MAX_PATH];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s", password);
    send_command(sockfd, pass_cmd);
    printf("%s", get_response(sockfd));

    // Send LIST command to fetch available files
    send_command(sockfd, "PASV");
    printf("%s", get_response(sockfd));

    // Simulating file listing and downloading (replace with real implementation)
    printf("Listing files...\n");
    printf("1. file1.txt\n");
    printf("2. file2.txt\n");
    
    printf("Enter file to download: ");
    int file_choice;
    scanf("%d", &file_choice);
    
    if (file_choice == 1) {
        printf("Downloading file1.txt...\n");
    } else if (file_choice == 2) {
        printf("Downloading file2.txt...\n");
    } else {
        printf("Invalid choice!\n");
    }

    // Clean up and exit
    send_command(sockfd, "QUIT");
    printf("%s", get_response(sockfd));

    close(sockfd);
    return 0;
}