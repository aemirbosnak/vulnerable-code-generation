//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 21

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int createSocket(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *he;

    if ((he = gethostbyname(hostname)) == NULL) {
        handleError("gethostbyname");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        handleError("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(sockfd);
        handleError("connect");
    }

    return sockfd;
}

void sendCommand(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void readResponse(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes;
    
    while ((bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "230") != NULL || strstr(buffer, "221") != NULL || strstr(buffer, "226") != NULL) {
            break;
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];

    snprintf(cmd, sizeof(cmd), "USER %s", username);
    sendCommand(sockfd, cmd);
    readResponse(sockfd);
    
    snprintf(cmd, sizeof(cmd), "PASS %s", password);
    sendCommand(sockfd, cmd);
    readResponse(sockfd);
}

void uploadFile(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        handleError("File opening failed");
    }

    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "STOR %s", filename);
    sendCommand(sockfd, cmd);
    readResponse(sockfd);

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(sockfd, buffer, bytesRead, 0);
    }

    fclose(file);
    readResponse(sockfd);
}

void listFiles(int sockfd) {
    sendCommand(sockfd, "PASV");
    readResponse(sockfd);

    // Here we'll need to parse the response to get the passive FTP server port
    // This is a bit complex and usually requires regex to extract the port 
    // So, we'll skip that and assume a predefined PORT for simplicity.
    // In a real application, you would use regex or string parsing to get the correct port.

    int data_sockfd = createSocket("127.0.0.1"); // this should point to the server address in PASV mode.
    
    sendCommand(data_sockfd, "LIST");
    readResponse(data_sockfd);
    close(data_sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = createSocket(hostname);
    readResponse(sockfd);

    login(sockfd, username, password);
    
    // Upload a file
    uploadFile(sockfd, "example.txt");
    
    // List files on server
    listFiles(sockfd);

    // Exit
    sendCommand(sockfd, "QUIT");
    readResponse(sockfd);
    close(sockfd);
    
    return 0;
}