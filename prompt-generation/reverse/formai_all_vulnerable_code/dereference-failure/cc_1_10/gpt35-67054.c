//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h> 
#include<errno.h>
#include<stddef.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_LENGTH 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd = 0, bytesreceived = 0, file_size = 0, file_fd = 0;
    int recv_size = 0, remaining_data = 0;
    char recv_buffer[BUFFER_SIZE], buffer[MAX_LENGTH];
    struct sockaddr_in server_address;
    char *file_name = NULL;

    if(argc < 4)
    {
        error("Usage: ./ftp_client hostname port filename\n");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));  
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd,(struct sockaddr *)&server_address,sizeof(server_address)) < 0)
    {
        error("ERROR connecting");
    }

    // Sending the file name to the server
    if(send(sockfd, argv[3], strlen(argv[3]), 0) < 0)
    {
        error("ERROR writing to socket");
    }

    // Receiving whether the file exists on the server or not
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        error("ERROR reading from socket");
    }

    if(strcmp(buffer, "no") == 0)
    {
        printf("File %s does not exist on the server.\n", argv[3]);
        exit(1);
    }

    else
    {
        printf("File exists on the server. Downloading file...\n");
        // Receiving the size of the file
        if(recv(sockfd, &file_size, sizeof(int), 0) < 0)
        {
            error("ERROR reading from socket");
        }

        // Creating a file with the same name as that on the server
        if ((file_fd = open(argv[3], O_CREAT | O_EXCL | O_WRONLY, 0666)) == -1)
        {
            error("ERROR creating file on client");
        }

        remaining_data = file_size;

        // Receiving the data in chunks and writing it to the file
        while(((bytesreceived = recv(sockfd, recv_buffer, BUFFER_SIZE, 0)) > 0) && (remaining_data > 0))
        {
            printf("%d bytes received\n",bytesreceived);
            fflush(stdout);
            write(file_fd, recv_buffer, bytesreceived);
            remaining_data -= bytesreceived;
            memset(recv_buffer,0,BUFFER_SIZE);
        }

        // Closing the file and socket
        close(file_fd);
        close(sockfd);

        printf("File %s downloaded successfully!\n", argv[3]);
    }

    return 0;
}