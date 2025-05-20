//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected to server...\n");

    printf("FTP Client Commands:\n");
    printf("get <filename>\nput <filename>\nquit\n");

    while (1) {
        bzero(buffer, BUF_SIZE);

        printf("FTP> ");

        fgets(buffer, BUF_SIZE, stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            error("ERROR writing to socket");
        }

        if (strncmp(buffer, "quit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strncmp(buffer, "get", 3) == 0) {
            char file_name[BUF_SIZE];
            sscanf(buffer, "get %s", file_name);

            FILE *file = fopen(file_name, "wb");

            if (file == NULL) {
                printf("File %s cannot be opened.\n", file_name);
                continue;
            }

            bzero(buffer, BUF_SIZE);

            int file_size;

            recv(sockfd, &file_size, sizeof(file_size), 0);

            int remain_data = file_size;

            while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0 && remain_data > 0) {
                fwrite(buffer, sizeof(char), n, file);
                remain_data -= n;
            }

            fclose(file);

            printf("%s received successfully!\n", file_name);
        }

        if (strncmp(buffer, "put", 3) == 0) {
            char file_name[BUF_SIZE];
            sscanf(buffer, "put %s", file_name);

            FILE *file = fopen(file_name, "rb");

            if (file == NULL) {
                printf("File %s cannot be opened.\n", file_name);
                continue;
            }

            bzero(buffer, BUF_SIZE);

            int file_size = 0;

            fseek(file, 0L, SEEK_END);
            file_size = ftell(file);
            fseek(file, 0L, SEEK_SET);

            printf("Sending %s (%d bytes) to server...\n", file_name, file_size);

            send(sockfd, &file_size, sizeof(file_size), 0);
            
            int remain_data = file_size;

            while (remain_data > 0) {
                int read_data = fread(buffer, sizeof(char), BUF_SIZE, file);
                remain_data -= read_data;
                int write_data = write(sockfd, buffer, read_data);

                if (write_data < read_data) {
                    printf("ERROR writing to socket\n");
                    break;
                }
            }

            fclose(file);

            printf("%s sent successfully!\n", file_name);
        }

        bzero(buffer, BUF_SIZE);

        n = read(sockfd, buffer, BUF_SIZE);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}