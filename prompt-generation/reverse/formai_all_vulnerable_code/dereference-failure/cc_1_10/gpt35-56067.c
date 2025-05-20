//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>

// function to download a file from server
void download(char *filename, int sockfd) {
    FILE *fptr;
    if((fptr = fopen(filename, "wb"))==NULL) {
        printf("Error opening file!\n");
    }
    else {
        char buffer[255];
        int file_size;
        bzero(buffer, 255);
        if(recv(sockfd, buffer, sizeof(buffer), 0)>=0) {
            file_size = atoi(buffer);
        }
        int bytes_read = 0;
        int remain_data = 0;
        while(bytes_read < file_size) {
            bzero(buffer, 255);
            remain_data = file_size - bytes_read;
            int read_size = remain_data > 255 ? 255 : remain_data;
            int n = recv(sockfd, buffer, read_size, 0);
            if(n < 0) {
                printf("Error receiving data!\n");
                break;
            }
            fwrite(buffer, sizeof(char), n, fptr);
            bytes_read += n;
            printf("%d bytes received\n", n);
        }
        printf("Download Done!\n");
        fclose(fptr);
    }
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[255];

    if(argc < 4) {
        printf("Usage:\n%s <hostname> <port> <file>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
        printf("Error in address!\n");
        exit(1);
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    // command to download a file
    if(strcmp(argv[3], "download") == 0) {
        bzero(buffer, 255);
        strcpy(buffer, argv[4]);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if(n < 0) {
            printf("Error sending data!\n");
            exit(1);
        }
        download(argv[4], sockfd);
    }

    // command to exit
    else if(strcmp(argv[3], "exit") == 0) {
        bzero(buffer, 255);
        strcpy(buffer, "exit");
        n = send(sockfd, buffer, strlen(buffer), 0);
        if(n < 0) {
            printf("Error sending data!\n");
            exit(1);
        }
    }

    // invalid command
    else {
        printf("Invalid command!\n");
    }
    close(sockfd);
    return 0;
}