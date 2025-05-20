//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Read response from the server
    while (1) {
        int bytes_received = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (bytes_received < 0) {
            error("ERROR reading from socket");
        }
        printf("%s", buffer);
        if (bytes_received < BUFFER_SIZE - 1) {
            break; // End of response
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    sprintf(command, "PASS %s", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[] = "PASV";
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Note: This example does not handle the actual data connection.
    // You would typically need to parse the response to get the data socket info.
    
    // For now, we'll just print out a placeholder.
    printf("Mode switched to Passive and files listed (mock)\n");
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %s", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void ftp_client(const char *hostname, const char *username, const char *password) {
    int sockfd = connect_to_server(hostname);
    if (sockfd < 0) {
        return;
    }

    receive_response(sockfd);
    login(sockfd, username, password);
    list_files(sockfd);
    
    char filename[100];
    printf("Enter the name of the file to download: ");
    scanf("%99s", filename);
    download_file(sockfd, filename);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    ftp_client(hostname, username, password);

    return 0;
}