//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_handling(char *msg){
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sd;
    struct sockaddr_in srv_addr;
    char buf[BUF_SIZE];
    int str_len, read_len;
    FILE *fp;

    if (argc!=4) {
        printf("Usage: %s <IP> <port> <filename>", argv[0]);
        exit(1);
    }

    // create a socket
    sd=socket(PF_INET, SOCK_STREAM, 0);
    if (sd==-1)
        error_handling("socket() error");

    // set server address
    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family=AF_INET;
    srv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    srv_addr.sin_port=htons(atoi(argv[2]));

    // connect to server
    if (connect(sd, (struct sockaddr*)&srv_addr, sizeof(srv_addr))==-1)
        error_handling("connect() error");

    // send filename to server
    write(sd, argv[3], strlen(argv[3]));

    // receive file size from server
    read(sd, &str_len, sizeof(int));

    // check if file exists
    if (str_len == -1) {
        printf("File does not exist on server\n");
        exit(1);
    }

    // open or create file for writing
    fp = fopen(argv[3], "wb");
    if (fp == NULL)
        error_handling("File opening error");

    // receive file contents from server and write to file
    while (read_len = read(sd, buf, BUF_SIZE)) {
        fwrite(buf, 1, read_len, fp);
    }

    // close file and socket
    fclose(fp);
    close(sd);

    printf("File transfer completed!\n");

    return 0;
}