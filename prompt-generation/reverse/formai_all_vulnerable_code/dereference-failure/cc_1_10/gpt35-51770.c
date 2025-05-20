//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_CMD_LENGTH 128
#define MAX_RESP_LENGTH 1024
#define FILE_CHUNK_SIZE 1024

/* This function establishes a connection to the given FTP host name and port number */
int connect_ftp(char *hostname, int port){
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        printf("Error: Could not open socket.\n");
        return -1;
    }
    server = gethostbyname(hostname);
    if (server == NULL){
        printf("Error: Could not find server.\n");
        return -1;
    }
    memset((void *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((void *)server->h_addr, (void *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
        printf("Error: Could not connect to server.\n");
        return -1;
    }
    return sockfd;
}

/* This function logs into the FTP server with the given username and password */
int login_ftp(int sockfd, char *username, char *password){
    char buf[MAX_RESP_LENGTH];
    int res;
    read(sockfd, buf, MAX_RESP_LENGTH);
    printf("Server: %s", buf);
    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, MAX_RESP_LENGTH);
    printf("Server: %s", buf);
    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, MAX_RESP_LENGTH);
    if (buf[0] == '2' && buf[1] == '3' && buf[2] == '0'){
        printf("Server: Login successful!\n");
        res = 1;
    }
    else{
        printf("Server: Login failed.\n");
        res = 0;
    }
    printf("Server: %s", buf);
    return res;
}

/* This function retrieves the file over FTP */
void get_file(int sockfd, char *filename){
    char buf[MAX_CMD_LENGTH];
    int filefd;
    int numread;
    long totread = 0;
    char filebuf[FILE_CHUNK_SIZE];
    sprintf(buf, "TYPE I\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, MAX_CMD_LENGTH);
    sprintf(buf, "RETR %s\r\n", filename);
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, MAX_RESP_LENGTH);
    if (buf[0] == '5'){
        printf("Server: %s", buf);
        return;
    }
    filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((numread = read(sockfd, filebuf, FILE_CHUNK_SIZE)) > 0){
        write(filefd, filebuf, numread);
        totread += numread;
    }
    close(filefd);
    printf("Server: File received (%ld bytes).\n", totread);
    read(sockfd, buf, MAX_RESP_LENGTH);
    printf("Server: %s", buf);
}

/* This function disconnects from the FTP server */
void quit_ftp(int sockfd){
    char buf[MAX_CMD_LENGTH];
    sprintf(buf, "QUIT\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, MAX_RESP_LENGTH);
    printf("Server: %s", buf);
    close(sockfd);
}

/* This is the main function */
int main(){
    int sockfd;
    char hostname[] = "ftp.example.com";
    int port = 21;
    char username[] = "myusername";
    char password[] = "mypassword";
    char filename[] = "example.txt";
    sockfd = connect_ftp(hostname, port);
    if (sockfd < 0){
        return -1;
    }
    if (!login_ftp(sockfd, username, password)){
        return -1;
    }
    get_file(sockfd, filename);
    quit_ftp(sockfd);
    return 0;
}