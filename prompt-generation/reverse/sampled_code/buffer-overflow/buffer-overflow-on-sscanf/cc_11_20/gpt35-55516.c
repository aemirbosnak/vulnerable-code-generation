//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char file_name[BUFFER_SIZE];
    FILE *fp;
    int file_size, read_size = 0;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if(connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("Enter file name to download: ");
        scanf("%s", file_name);

        if(send(sock, file_name, strlen(file_name), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        if(recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if(strcmp(buffer, "File not found") == 0) {
            printf("%s\n", buffer);
            continue;
        }

        sscanf(buffer, "%d", &file_size);
        printf("File size: %d bytes\n", file_size);

        if((fp = fopen(file_name, "wb")) == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        while(read_size < file_size && (read_size += fread(buffer, 1, BUFFER_SIZE, fp))) {
            fwrite(buffer, 1, read_size, fp);
            memset(buffer, 0, BUFFER_SIZE);
        }

        printf("File downloaded successfully!\n");

        fclose(fp);
        read_size = 0;
    }

    close(sock);
    exit(EXIT_SUCCESS);
}