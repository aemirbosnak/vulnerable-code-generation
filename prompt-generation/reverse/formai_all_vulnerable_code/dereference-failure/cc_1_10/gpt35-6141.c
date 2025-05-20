//FormAI DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/rand.h>

#define MAX_BUFFER_SIZE 4096
#define RSA_KEY_SIZE 2048

// function to handle errors
void handle_error(const char *msg)
{
    perror(msg);
    exit(1);
}

// function to start server
void start_server(int port_num)
{
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // create socket for server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        handle_error("Error opening socket");

    // set server address and port number
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port_num);

    // bind socket to server address and port number
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        handle_error("Error on binding");

    // listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // accept client connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        handle_error("Error on accept");

    // read message from client
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int n = read(newsockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0)
        handle_error("Error reading from socket");
    
    // generate RSA key pair
    RSA *rsa;
    FILE *fp;
    fp = fopen("private.pem", "w");
    fclose(fp);
    fp = fopen("public.pem", "w");
    fclose(fp);
    rsa = RSA_generate_key(RSA_KEY_SIZE, RSA_F4, NULL, NULL);

    // write public key to file
    fp = fopen("public.pem", "wb");
    PEM_write_RSAPublicKey(fp, rsa);
    fclose(fp);

    // write private key to file
    fp = fopen("private.pem", "wb");
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);

    // encrypt message with RSA public key
    unsigned char encrypted[MAX_BUFFER_SIZE];
    memset(encrypted, 0, MAX_BUFFER_SIZE);
    RSA_public_encrypt(strlen(buffer), (unsigned char *) buffer,
                       (unsigned char *) encrypted, rsa,
                       RSA_PKCS1_OAEP_PADDING);

    // send encrypted message to client
    n = write(newsockfd, (char *)encrypted, RSA_size(rsa));
    if (n < 0)
        handle_error("Error writing to socket");

    // clear memory and close sockets
    RSA_free(rsa);
    close(newsockfd);
    close(sockfd);
}

// function to connect to server
void connect_to_server(char *ip_addr, int port_num)
{
    int sockfd, n;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    RSA *rsa;
    FILE *fp;

    // create socket for client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        handle_error("Error opening socket");

    // set server address and port number
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
    if(inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr)<=0)
        handle_error("Error invalid address");

    // connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        handle_error("Error connecting");

    // generate RSA key pair
    fp = fopen("private.pem", "w");
    fclose(fp);
    fp = fopen("public.pem", "w");
    fclose(fp);
    rsa = RSA_generate_key(RSA_KEY_SIZE, RSA_F4, NULL, NULL);

    // write public key to file
    fp = fopen("public.pem", "wb");
    PEM_write_RSAPublicKey(fp, rsa);
    fclose(fp);

    // write private key to file
    fp = fopen("private.pem", "wb");
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);

    // read message from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0)
        handle_error("Error reading from socket");

    // decrypt message with RSA private key
    unsigned char decrypted[MAX_BUFFER_SIZE];
    memset(decrypted, 0, MAX_BUFFER_SIZE);
    RSA_private_decrypt(n, (unsigned char *) buffer,
                        (unsigned char *) decrypted, rsa,
                        RSA_PKCS1_OAEP_PADDING);

    printf("Received message from server: %s\n", decrypted);

    // clear memory and close socket
    RSA_free(rsa);
    close(sockfd);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr,"Usage: %s [server | client]\n", argv[0]);
        exit(1);
    } else if (strcmp(argv[1], "server") == 0) {
        start_server(8888);
    } else if (strcmp(argv[1], "client") == 0) {
        connect_to_server("127.0.0.1", 8888);
    } else {
        fprintf(stderr,"Usage: %s [server | client]\n", argv[0]);
        exit(1);
    }

    return 0;
}