//FormAI DATASET v1.0 Category: Client Server Application ; Style: genious
/* Client-Server Application for Finding the Sum of Numbers */

# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>

# define PORT 8080
# define BUF_SIZE 1024

void server(int);
void client(char*, int);

int main(int argc, char *argv[]) {
    char *mode = argv[1];
    int num;

    if (strcmp(mode, "server") == 0) {
        printf("Starting Server...\n");
        server(PORT);
    }
    else if (strcmp(mode, "client") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Usage: %s client [server IP]\n", argv[0]);
            exit(1);
        }
        printf("Enter the number of elements in the array: ");
        scanf("%d", &num);
        client(argv[2], num);
    }
    else {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        exit(1);
    }
    return 0;
}

void server(int portno) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    int n;
    int sum = 0;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket option");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server Listening on port %d...\n", portno);
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        valread = read(new_socket, buffer, BUF_SIZE);
        if (valread == 0 || strcmp(buffer, "exit") == 0) {
            break;
        }
        sscanf(buffer, "%d", &n);
        sum += n;
    }

    printf("The sum is %d\n", sum);
    close(new_socket);
    close(server_fd);
}

void client(char *ip, int n) {
    struct sockaddr_in serv_addr;
    int sock = 0, valread;
    struct sockaddr_in address;
    char buffer[BUF_SIZE] = {0};
    int arr[n];
    int i, sum = 0;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(1);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(1);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        exit(1);
    }
    for (i=0; i<n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        sprintf(buffer, "%d", arr[i]);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUF_SIZE);
    }
    send(sock, "exit", 4, 0);
    valread = read(sock, buffer, BUF_SIZE);
    sscanf(buffer, "%d", &sum);
    printf("The sum received from server is %d\n", sum);
    close(sock);
}