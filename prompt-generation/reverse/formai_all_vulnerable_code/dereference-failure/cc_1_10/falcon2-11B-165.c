//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to establish connection with FTP server
int connect_to_server(char* hostname, int port) {
    struct hostent* server_info = gethostbyname(hostname);
    struct sockaddr_in server_address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = *(long*)(server_info->h_addr);
    int result = connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (result < 0) {
        printf("Error connecting to server\n");
        return -1;
    }
    return sockfd;
}

// Function to send a command to the FTP server
int send_command(int sockfd, char* command) {
    send(sockfd, command, strlen(command), 0);
    return 0;
}

// Function to receive response from the FTP server
int receive_response(int sockfd) {
    char buffer[1024];
    int bytes_read = recv(sockfd, buffer, 1024, 0);
    buffer[bytes_read] = '\0';
    return bytes_read;
}

// Function to handle the response from the FTP server
void handle_response(char* response, int bytes_read) {
    printf("Response from server: %s\n", response);
}

int main() {
    char hostname[256];
    int port = 21;
    int sockfd = connect_to_server(hostname, port);
    if (sockfd < 0) {
        printf("Connection failed\n");
        return -1;
    }

    char command[256];
    printf("Enter FTP command: ");
    fgets(command, sizeof(command), stdin);

    // Trim newline character from the command
    int i = strlen(command) - 1;
    while (i >= 0 && command[i] == '\n') {
        command[i] = '\0';
        i--;
    }

    int bytes_sent = send_command(sockfd, command);
    if (bytes_sent < 0) {
        printf("Error sending command\n");
        return -1;
    }

    char response[256];
    int bytes_read = receive_response(sockfd);
    if (bytes_read < 0) {
        printf("Error receiving response\n");
        return -1;
    }

    handle_response(response, bytes_read);

    close(sockfd);
    return 0;
}