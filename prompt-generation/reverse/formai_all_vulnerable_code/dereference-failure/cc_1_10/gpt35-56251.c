//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 21

int create_socket(char* host);

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printf("Usage: ftp <host> <username> <password> <command>\n");
        exit(1);
    }

    char* host = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    char* command = argv[4];

    int socket_fd = create_socket(host);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_read] = '\0';

    printf("%s", buffer);

    sprintf(buffer, "USER %s\r\n", username);
    write(socket_fd, buffer, strlen(buffer));

    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_read] = '\0';

    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    write(socket_fd, buffer, strlen(buffer));

    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_read] = '\0';

    printf("%s", buffer);

    if (strcmp(command, "LIST") == 0)
    {
        sprintf(buffer, "PASV\r\n");
        write(socket_fd, buffer, strlen(buffer));

        bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        buffer[bytes_read] = '\0';

        printf("%s", buffer);

        char* start = strchr(buffer, '(');
        char* end = strchr(buffer, ')');

        if (start != NULL && end != NULL)
        {
            int arr[6];
            sscanf(start, "(%d,%d,%d,%d,%d,%d)", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);

            char ip_address[16];
            sprintf(ip_address, "%d.%d.%d.%d", arr[0], arr[1], arr[2], arr[3]);

            int data_socket_fd = create_socket(ip_address);

            int port_number = arr[4] * 256 + arr[5];
            struct sockaddr_in server_address;
            server_address.sin_family = AF_INET;
            server_address.sin_port = htons(port_number);
            server_address.sin_addr.s_addr = inet_addr(ip_address);

            connect(data_socket_fd, (struct sockaddr*) &server_address, sizeof(server_address));

            sprintf(buffer, "LIST\r\n");
            write(socket_fd, buffer, strlen(buffer));

            bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
            buffer[bytes_read] = '\0';

            printf("%s", buffer);

            while ((bytes_read = recv(data_socket_fd, buffer, BUFFER_SIZE, 0)) > 0)
            {
                buffer[bytes_read] = '\0';
                printf("%s", buffer);
            }

            close(data_socket_fd);

            bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
            buffer[bytes_read] = '\0';

            printf("%s", buffer);
        }
    }
    else if (strcmp(command, "GET") == 0)
    {
        char* filename = argv[5];

        sprintf(buffer, "PASV\r\n");
        write(socket_fd, buffer, strlen(buffer));

        bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        buffer[bytes_read] = '\0';

        printf("%s", buffer);

        char* start = strchr(buffer, '(');
        char* end = strchr(buffer, ')');

        if (start != NULL && end != NULL)
        {
            int arr[6];
            sscanf(start, "(%d,%d,%d,%d,%d,%d)", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);

            char ip_address[16];
            sprintf(ip_address, "%d.%d.%d.%d", arr[0], arr[1], arr[2], arr[3]);

            int data_socket_fd = create_socket(ip_address);

            int port_number = arr[4] * 256 + arr[5];
            struct sockaddr_in server_address;
            server_address.sin_family = AF_INET;
            server_address.sin_port = htons(port_number);
            server_address.sin_addr.s_addr = inet_addr(ip_address);

            connect(data_socket_fd, (struct sockaddr*) &server_address, sizeof(server_address));

            sprintf(buffer, "RETR %s\r\n", filename);
            write(socket_fd, buffer, strlen(buffer));

            bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
            buffer[bytes_read] = '\0';

            printf("%s", buffer);

            int file_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

            while ((bytes_read = recv(data_socket_fd, buffer, BUFFER_SIZE, 0)) > 0)
            {
                write(file_fd, buffer, bytes_read);
            }

            close(file_fd);
            close(data_socket_fd);

            bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
            buffer[bytes_read] = '\0';

            printf("%s", buffer);
        }
    }

    sprintf(buffer, "QUIT\r\n");
    write(socket_fd, buffer, strlen(buffer));

    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_read] = '\0';

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}

int create_socket(char* host)
{
    struct hostent* host_entry;
    host_entry = gethostbyname(host);

    if (host_entry == NULL)
    {
        printf("Error: invalid host\n");
        exit(1);
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr = *((struct in_addr*) host_entry->h_addr);

    connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address));

    char buffer[BUFFER_SIZE];
    int bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_read < 0)
    {
        printf("Error: failed to read from socket\n");
        exit(1);
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    return socket_fd;
}