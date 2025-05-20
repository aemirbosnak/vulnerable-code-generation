//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int connectToServer(const char * host, const int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    return sockfd;
}

void ftpUpload(const int sockfd, const char *filename, const char *remote_filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        error("ERROR opening file!");
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    int n;
    sprintf(buffer, "STOR %s\r\n", remote_filename);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket!");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        error("ERROR reading from socket!");
    if (buffer[0] == '4' || buffer[0] == '5')
        error("FTP server returned an error!");
    while ((n = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (write(sockfd, buffer, n) < 0)
            error("ERROR writing to socket!");
    }
    fclose(file);
    printf("File uploaded successfully!\n");
}

void ftpDownload(const int sockfd, const char *filename, const char *remote_filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        error("ERROR opening file!");
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    int n;
    sprintf(buffer, "RETR %s\r\n", remote_filename);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket!");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        error("ERROR reading from socket!");
    if (buffer[0] == '4' || buffer[0] == '5')
        error("FTP server returned an error!");
    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        if (fwrite(buffer, 1, n, file) < n)
            error("ERROR writing to file!");
    }
    fclose(file);
    printf("File downloaded successfully!\n");
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    char buffer[BUFFER_SIZE];

    int sockfd = connectToServer(argv[1], atoi(argv[2]));

    bzero(buffer, BUFFER_SIZE);
    int n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        error("ERROR reading from socket!");
    printf("Connected to FTP server: %s", buffer);

    sprintf(buffer, "USER %s\r\n", "username");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket!");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        error("ERROR reading from socket!");
    printf("FTP server says: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", "password");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket!");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        error("ERROR reading from socket!");
    printf("FTP server says: %s", buffer);

    printf("Choose an option:\n");
    printf("1. Upload file\n");
    printf("2. Download file\n");
    int option;
    scanf("%d", &option);

    if (option == 1) {
        char filename[256], remote_filename[256];
        printf("Enter the name of the local file to upload: ");
        scanf("%s", filename);
        printf("Enter the name the file should be saved as on the server: ");
        scanf("%s", remote_filename);
        ftpUpload(sockfd, filename, remote_filename);
    } else if (option == 2) {
        char filename[256], remote_filename[256];
        printf("Enter the name of the file to download: ");
        scanf("%s", remote_filename);
        printf("Enter the name the file should be saved as locally: ");
        scanf("%s", filename);
        ftpDownload(sockfd, filename, remote_filename);
    } else {
        printf("Invalid option!\n");
    }

    close(sockfd);
    return 0;
}