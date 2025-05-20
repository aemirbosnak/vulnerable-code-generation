//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE + 1];
    FILE *file;
    
    // Check for valid arguments
    if (argc < 4) {
        fprintf(stderr,"%s hostname port filename\n", argv[0]);
        exit(1);
    }
    
    portno = atoi(argv[2]);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    // Send file name to server
    n = write(sockfd, argv[3], strlen(argv[3]));
    
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    // Open file in binary mode
    file = fopen(argv[3], "wb");
    
    if (file == NULL) {
        error("ERROR opening file");
    }
    
    // Receive file data from server and write to file
    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, n, file);
    }
    
    if (n < 0) {
        error("ERROR reading from socket");
    }
    
    printf("File transferred successfully.\n");
    
    // Close file and socket
    fclose(file);
    close(sockfd);
    
    return 0;
}