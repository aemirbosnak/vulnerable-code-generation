//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], filename[100];
    FILE *file;
    off_t size;
    
    if (argc != 4) {
        printf("Usage : %s <server_ip> <server_port> <filename>\n", argv[0]);
        return 0;
    }
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Unable to connect to the server.\n");
        return 0;
    }
    
    strcpy(filename, argv[3]);
    
    n = send(sock, filename, 100, 0);
    
    if (n == -1) {
        printf("Unable to send filename to the server.\n");
        return 0;
    }
    
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    
    if (n == -1) {
        printf("Unable to receive file size from the server.\n");
        return 0;
    }
    
    size = atol(buffer);
    
    if (size == 0) {
        printf("File not found on the server.\n");
        return 0;
    }
    
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Unable to create file on the client.\n");
        return 0;
    }
    
    while (size > 0) {
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        
        if (n == -1) {
            printf("Unable to receive file data from the server.\n");
            return 0;
        }
        
        fwrite(buffer, 1, n, file);
        size -= n;
    }
    
    printf("File received successfully.\n");
    
    fclose(file);
    close(sock);
    
    return 0;
}