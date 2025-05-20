//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Some commonly used FTP commands.
#define CMD_GET "get"
#define CMD_PUT "put"
#define CMD_LS  "ls"
#define CMD_CD  "cd"
#define CMD_QUIT  "quit"

//FTP response codes.
#define RSP_OK          200
#define RSP_FILENAME    201
#define RSP_ERROR       400
#define RSP_QUIT        221

int main(int argc,char *argv[])
{
    struct sockaddr_in server_addr;
    int client_socket;

    //Create a socket for the client
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit( EXIT_FAILURE );
    }

    //Handle user arguments
    char *server_ip_addr;
    char *server_port;
    char *username;
    char *password;
    char *command;
    char *filename;

    if (argc < 6) {
        printf("Usage: ftp_client <server_ip_addr> <server_port> <username> <password> <command> <filename>\n");
        exit( EXIT_FAILURE );
    } else {
        server_ip_addr = argv[1];
        server_port = argv[2];
        username = argv[3];
        password = argv[4];
        command = argv[5];
        filename = argc == 7 ? argv[6] : "";
    }

    //Connect to the server
    memset(&server_addr, 0 ,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip_addr);
    server_addr.sin_port = htons(atoi(server_port));

    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        perror("connect() failed");
        exit( EXIT_FAILURE );
    }

    //Send login credentials
    char buffer[256];
    sprintf(buffer,"%s:%s",username,password);
    send(client_socket, buffer, strlen(buffer), 0);

    //Receive login response from server
    memset(buffer, 0, sizeof(buffer));
    int response_code = recv(client_socket, buffer, sizeof(buffer), 0);

    if(response_code == RSP_ERROR) {
        printf("\nLogin failed\n");
        exit(EXIT_FAILURE);
    } else if(response_code == RSP_OK) {
        printf("\nLogin successful\n");
    }

    //Process user's command
    if(strcmp(command,CMD_GET) == 0) {
        //GET command
        printf("\nGET command\n");

        //Send command to server
        sprintf(buffer,"%s:%s",CMD_GET,filename);
        send(client_socket, buffer, strlen(buffer), 0);

        //Receive server file's content length
        memset(buffer, 0, sizeof(buffer));
        int file_length;
        recv(client_socket, &file_length, sizeof(file_length), 0);

        if(file_length == -1) {
            printf("Cannot find file on server\n");
            exit(EXIT_FAILURE);
        }

        //Receive file content from server
        FILE *file = fopen(filename, "wb");

        if (!file) {
            printf("Cannot create file on client\n");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, sizeof(buffer));
        int received_length;
        while((received_length = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
            fwrite(buffer, sizeof(char), received_length, file);
            file_length -= received_length;
            if (file_length == 0) {
                break;
            }
            memset(buffer, 0, sizeof(buffer));
        }

        fclose(file);

        printf("File %s received successfully from server\n",filename);
    } else if(strcmp(command,CMD_PUT) == 0) {
        //PUT command
        printf("\nPUT command\n");

        //Send command to server and file content length
        sprintf(buffer,"%s:%s",CMD_PUT,filename);
        send(client_socket, buffer, strlen(buffer), 0);

        FILE *file = fopen(filename, "rb");

        if(!file) {
            printf("Cannot open file on client\n");
            exit(EXIT_FAILURE);
        }

        //Determine file length
        int file_length;
        fseek(file, 0, SEEK_END);
        file_length = ftell(file);
        fseek(file, 0, SEEK_SET);

        //Send file length to server
        send(client_socket, &file_length, sizeof(file_length), 0);

        //Send file content to server
        memset(buffer, 0, sizeof(buffer));
        int sent_length;
        while((sent_length = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) {
            send(client_socket, buffer, sent_length, 0);
            memset(buffer, 0, sizeof(buffer));
        }

        fclose(file);

        printf("File %s sent successfully to server\n",filename);
    } else if(strcmp(command,CMD_LS) == 0) {
        //LS command
        printf("\nLS command\n");

        //Send command to server
        sprintf(buffer,"%s",CMD_LS);
        send(client_socket, buffer, strlen(buffer), 0);

        //Receive and print server response
        memset(buffer, 0, sizeof(buffer));
        while(recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    } else if(strcmp(command,CMD_CD) == 0) {
        //CD command
        printf("\nCD command\n");

        //Send command to server
        sprintf(buffer,"%s:%s",CMD_CD,filename);
        send(client_socket, buffer, strlen(buffer), 0);

        //Receive and print server response
        memset(buffer, 0, sizeof(buffer));
        while(recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    } else if(strcmp(command,CMD_QUIT) == 0) {
        //QUIT command
        printf("\nQUIT command\n");

        //Send command to server
        sprintf(buffer,"%s",CMD_QUIT);
        send(client_socket, buffer, strlen(buffer), 0);

        //Receive server response
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        if(strcmp(buffer,"Goodbye") == 0) {
            printf("Disconnected from server\n");
        }
    }

    //Close client socket
    close(client_socket);

    exit(EXIT_SUCCESS);
}