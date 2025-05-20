//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
// FTP Client Implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_BUFF_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void send_data(int sockfd, char* buff, int len)
{
    int n = write(sockfd, buff, len);

    if (n < 0) 
        error("ERROR writing to socket");
}

int receive_data(int sockfd, char* buff)
{
    bzero(buff, MAX_BUFF_SIZE);
    int n = read(sockfd, buff, MAX_BUFF_SIZE);

    if (n < 0) 
         error("ERROR reading from socket");

    return n;
}

void login(int sockfd)
{
    char buff[MAX_BUFF_SIZE];

    receive_data(sockfd, buff);
    printf("%s", buff);
    bzero(buff, MAX_BUFF_SIZE);

    char* username = "USERNAME";
    char* password = "PASSWORD";

    sprintf(buff, "%s%c%s%c", username, '\0', password, '\0');   
    send_data(sockfd, buff, strlen(buff));
    receive_data(sockfd, buff);

    if (strncmp(buff, "230", 3) != 0)
        error("ERROR logging in");
}

void download_file(int sockfd, char* filename)
{
    char buff[MAX_BUFF_SIZE];

    sprintf(buff, "RETR %s\r\n", filename);
    send_data(sockfd, buff, strlen(buff));

    receive_data(sockfd, buff);
    if (strncmp(buff, "550", 3) == 0)
        error("ERROR file does not exist");

    printf("\nDownloading file...\n");

    FILE* fp = fopen(filename, "w");
    while ((receive_data(sockfd, buff)) > 0)
    {
        fwrite(buff, 1, MAX_BUFF_SIZE, fp);
    }

    if (fp != NULL)
        fclose(fp);

    receive_data(sockfd, buff);
    printf("%s\n", buff);
}

void upload_file(int sockfd, char* filename)
{
    char buff[MAX_BUFF_SIZE];

    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        error("ERROR opening file");

    sprintf(buff, "STOR %s\r\n", filename);
    send_data(sockfd, buff, strlen(buff));

    receive_data(sockfd, buff);   
    printf("\nUploading file...\n");

    while (!feof(fp))
    {
        bzero(buff, MAX_BUFF_SIZE);
        int nread = fread(buff, 1, MAX_BUFF_SIZE, fp);
        send_data(sockfd, buff, nread);
    }

    if (fp != NULL)
    {
        fclose(fp);
    }

    receive_data(sockfd, buff);
    printf("%s\n", buff);
}

int main(int argc, char* argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    char buffer[MAX_BUFF_SIZE];

    if (argc < 3) 
    {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    login(sockfd);

    printf("\nConnected to FTP server successfully.\n");
    printf("Enter command (get | put | bye): ");

    scanf("%s", buffer);

    if(strncmp(buffer, "bye", 3) != 0)
    {
        char filename[MAX_BUFF_SIZE];

        printf("Enter filename: ");
        scanf("%s", filename);

        if(strncmp(buffer, "get", 3) == 0)
        {
            download_file(sockfd, filename);
        }
        else if(strncmp(buffer, "put", 3) == 0)
        {
            upload_file(sockfd, filename);
        }
        else
        {
            printf("Invalid command. Please enter 'get' or 'put'.\n");
        }
    }
    else
    {
        send_data(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
        receive_data(sockfd, buffer);
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}