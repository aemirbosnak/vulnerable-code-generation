//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE  1024

/* function prototypes */
int open_socket(char *ip, int port);
void receive_file(int socket, char *filename);
void send_file(int socket, char *filename);

int main(int argc, char **argv)
{
    int port;
    char *server_ip, *file;
    int option;
    int sock;

    if (argc != 4) {
        printf("Usage: ./ftpclient IP Port Option\n");
        printf("Option: 1 for receiving file, 2 for sending file\n");
        exit(-1);
    }

    /* get server ip, port, and file from command line arguments */
    server_ip = argv[1];
    port = atoi(argv[2]);
    option = atoi(argv[3]);

    /* open socket */
    sock = open_socket(server_ip, port);

    /* receive file */
    if (option == 1) {
        printf("Enter filename: ");
        scanf("%s", file);
        receive_file(sock, file);
    }
    /* send file */
    else if (option == 2) {
        printf("Enter filename: ");
        scanf("%s", file);
        send_file(sock, file);
    }
    /* invalid option */
    else {
        printf("Invalid option\n");
        exit(-1);
    }

    close(sock);
    return 0;
}

/* create socket and connect to server */
int open_socket(char *ip, int port)
{
    int sock;
    struct sockaddr_in server_addr;

    /* create socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(-1);
    }

    /* set up server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    /* connect to server */
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(-1);
    }

    return sock;
}

/* receive file from server */
void receive_file(int socket, char *filename)
{
    FILE *file;
    char buffer[BUFF_SIZE];
    int received, total = 0;

    /* send filename to server */
    send(socket, filename, strlen(filename)+1, 0);

    /* create file on client side */
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error creating file\n");
        exit(-1);
    }

    /* receive file from server */
    while (1) {
        received = recv(socket, buffer, BUFF_SIZE, 0);
        total += received;
        if (received <= 0) {
            break;
        }
        fwrite(buffer, 1, received, file);
    }

    fclose(file);

    if (total > 0) {
        printf("File received from server\n");
    }
    else {
        printf("File not found on server\n");
    }
}

/* send file to server */
void send_file(int socket, char *filename)
{
    FILE *file;
    char buffer[BUFF_SIZE];
    int sent, total = 0;

    /* check if file exists */
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(-1);
    }

    /* send filename to server */
    send(socket, filename, strlen(filename)+1, 0);

    /* send file to server */
    while (1) {
        sent = fread(buffer, 1, BUFF_SIZE, file);
        total += sent;
        if (sent <= 0) {
            break;
        }
        send(socket, buffer, sent, 0);
    }

    fclose(file);

    if (total > 0) {
        printf("File sent to server\n");
    }
    else {
        printf("Error sending file\n");
    }
}