//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc , char *argv[])
{
    //Welcome message
    printf("%s", "Welcome to my FTP Client Example Program!\n");

    //Get the IP address of the server and the port number to connect to
    if(argc != 3)
    {
        printf("%s", "Usage: ./FTPClient IP_Address Port_Number\n");
        exit(1);
    }
    char *serverip = argv[1];
    int serverport = atoi(argv[2]);

    //Create a socket
    int client_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (client_sock == -1)
    {
        error("Error creating socket");
    }

    //Connect to remote server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(serverip);
    server_address.sin_port = htons(serverport);

    if(connect(client_sock , (struct sockaddr *)&server_address , sizeof(server_address)) < 0)
    {
        error("Could not connect to server");
    }

    //Welcome message
    printf("%s", "Connected to Server!\n");

    //Response from server
    char server_response[MAXSIZE];
    memset(&server_response, 0, sizeof(server_response));
    if(recv(client_sock, server_response, MAXSIZE, 0) < 0)
    {
        error("Error receiving response");
    }
    printf("Server Response: %s\n",server_response);

    //Send username to server
    char username[MAXSIZE];
    printf("%s", "Enter Username: ");
    scanf("%s", username);
    write(client_sock, username, strlen(username));

    //Receive response from server
    memset(&server_response, 0, sizeof(server_response));
    if(recv(client_sock, server_response, MAXSIZE, 0) < 0)
    {
        error("Error receiving response");
    }
    printf("Server Response: %s\n",server_response);

    //Send password to server
    char password[MAXSIZE];
    printf("%s", "Enter Password: ");
    scanf("%s", password);
    write(client_sock, password, strlen(password));

    //Receive response from server
    memset(&server_response, 0, sizeof(server_response));
    if(recv(client_sock, server_response, MAXSIZE, 0) < 0)
    {
        error("Error receiving response");
    }
    printf("Server Response: %s\n",server_response);

    //Send command to server
    char command[MAXSIZE];
    printf("%s", "Enter FTP Command (e.g. ls, put, get): ");
    scanf("%s", command);
    write(client_sock, command, strlen(command));

    //Response from server
    memset(&server_response, 0, sizeof(server_response));
    if(recv(client_sock, server_response, MAXSIZE, 0) < 0)
    {
        error("Error receiving response");
    }
    printf("Server Response: %s\n",server_response);

    //Send filename to server
    char filename[MAXSIZE];
    printf("%s", "Enter Filename: ");
    scanf("%s", filename);
    write(client_sock, filename, strlen(filename));

    //File transfer
    if(strcmp(command, "get") == 0)
    {
        char buffer[MAXSIZE] = {0};
        FILE *file = fopen(filename, "wb");
        if(file == NULL)
        {
            error("Error creating file");
        }

        while (1) 
        {
            int n = recv(client_sock, buffer, MAXSIZE, 0);
            if (n <= 0)
            {
                break;
            }
            fwrite(buffer, sizeof(char), n, file);
        }

        fclose(file);
        printf("%s", "File received successfully!\n");
    }
    else if(strcmp(command, "put") == 0)
    {
        char buffer[MAXSIZE] = {0};
        FILE *file = fopen(filename, "rb");
        if(file == NULL)
        {
            error("Error opening file");
        }

        while (1) 
        {
            int n = fread(buffer, sizeof(char), MAXSIZE, file);
            if (n <= 0)
            {
                break;
            }
            send(client_sock, buffer, n, 0);
        }

        fclose(file);
        printf("%s", "File sent successfully!\n");
    }

    //Close the socket
    close(client_sock);

    return 0;
}