//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf(">> Sent: %s\n", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int num_bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (num_bytes < 0) {
        error("Error receiving response");
    }
    buffer[num_bytes] = '\0'; // Null-terminate the string
    printf("<< Received: %s", buffer);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) 
        error("No such host");

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("Error connecting");

    return sockfd;
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[] = "PASV\r\n";
    send_command(sockfd, command);
    receive_response(sockfd);

    // Note: This is a simplified version. Actual implementation will require extracting the port
    //       from the server's response and establishing a new connection for the data transfer.

    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (data_sockfd < 0) 
        error("Error opening data socket");

    // This is merely a placeholder for actual connection setup
    data_addr.sin_family = AF_INET; 
    data_addr.sin_port = htons(20); // Data port, generally 20
    // Normally would use the IP obtained from PASV response.
    
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) 
        error("Error connecting to data port");

    char *command_list = "LIST\r\n";
    send_command(sockfd, command_list);
    receive_response(sockfd); 

    // Simulating file listing - typically you would read from data_sockfd
    char file_list[] = "file1.txt\nfile2.txt\nfile3.txt";
    printf("Files:\n%s", file_list);

    close(data_sockfd);
}

void ftp_quit(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
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
    
    int ftp_sockfd = connect_to_server(hostname);
    receive_response(ftp_sockfd); // Initial server response

    ftp_login(ftp_sockfd, username, password);
    
    list_files(ftp_sockfd);

    ftp_quit(ftp_sockfd);

    return 0;
}