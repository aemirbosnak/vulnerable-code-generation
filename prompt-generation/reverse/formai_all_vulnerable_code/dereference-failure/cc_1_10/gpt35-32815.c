//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s [IP] [Port] [File]\n", argv[0]);
        exit(1);
    }
    
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1) {
        perror("socket() error");
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    if (connect(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() error");
        exit(1);
    }
    
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    strcpy(buffer, argv[3]);
    struct stat file_stat;
    if (stat(buffer, &file_stat) == -1) {
        perror("stat() error");
        exit(1);
    }
    
    int filefd = open(buffer, O_RDONLY);
    if (filefd == -1) {
        perror("open() error");
        exit(1);
    }
    
    int total_bytes = 0;
    int read_bytes = 0;
    while ((read_bytes = read(filefd, buffer, MAX_BUFFER)) > 0) {
        if (send(sfd, buffer, read_bytes, 0) == -1) {
            perror("send() error");
            exit(1);
        }
        total_bytes += read_bytes;
        memset(buffer, 0, MAX_BUFFER);
    }
    
    printf("Total bytes sent: %d\n", total_bytes);
    close(filefd);
    close(sfd);
    
    return 0;
}