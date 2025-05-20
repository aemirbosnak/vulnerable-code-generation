//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int client_fd, port_no, num1, num2, sum, n;
    struct sockaddr_in server_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    port_no = atoi(argv[1]);

    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_no);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Can't connect to server\n");
        exit(1);
    }

    printf("Enter two numbers: ");
    fgets(buffer, sizeof(buffer), stdin);

    sscanf(buffer, "%d %d", &num1, &num2);

    sum = num1 + num2;

    if (write(client_fd, &sum, sizeof(sum))!= sizeof(sum)) {
        perror("Error: Can't write to server");
        exit(1);
    }

    n = read(client_fd, buffer, sizeof(buffer));

    if (n!= sizeof(buffer)) {
        perror("Error: Can't read from server");
        exit(1);
    }

    printf("Server says: %s\n", buffer);

    close(client_fd);
    return 0;
}