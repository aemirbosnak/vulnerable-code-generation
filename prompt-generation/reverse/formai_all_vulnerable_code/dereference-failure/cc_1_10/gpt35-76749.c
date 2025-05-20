//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

char* virii[] = { "WannaCry", "ILOVEYOU", "Code Red", "Sasser", "Melissa", "Nimda" };
char* clean[] = { "not a virus", "safe", "clean", "not infected" };

int scan_file(char *filename){
    FILE *file;
    char ch;
    char buffer[1024];
    int i, j;
    int counter = 0;
    int virus = 0;
    size_t len;
    
    file = fopen(filename, "r");
    if (file) {
        while ((ch = fgetc(file)) != EOF) {
            buffer[counter++] = ch;
            if (counter == BUFSIZE) {
                for (i = 0; i < 6; i++) {
                    len = strlen(virii[i]);
                    for (j = 0; j < BUFSIZE - len; j++) {
                        if (memcmp(&buffer[j], virii[i], len) == 0) {
                            virus++;
                            printf("Virus found: %s\n", virii[i]);
                        }
                    }
                }
                counter = 0;
            }
        }
    }
    if (virus) return 1;
    else return 0;
}

void scan_directory(char *path) {
    DIR *dir;
    struct dirent *directory;
    char fullpath[1024];
    int virus = 0;
    
    dir = opendir(path);
    if (dir) {
        while ((directory = readdir(dir)) != NULL) {
            if (strcmp(directory->d_name, ".") != 0 && strcmp(directory->d_name, "..") != 0) {
                sprintf(fullpath, "%s/%s", path, directory->d_name);
                if (directory->d_type == DT_DIR) {
                    scan_directory(fullpath);
                } else {
                    virus += scan_file(fullpath);
                }
            }
        }
        closedir(dir);
    }
    if (virus) printf("%s is infected!\n", path);
    else printf("%s is clean!\n", path);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    int choice = 1;
    int i;
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) error("ERROR connecting");
    printf("Connected to server\n");
    while (choice != 0) {
        printf("1. Scan directory\n");
        printf("2. Add virus signature\n");
        printf("3. Remove virus signature\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter directory path to scan: ");
                scanf("%s", buffer);
                n = write(sockfd, buffer, strlen(buffer));
                if (n < 0) error("ERROR writing to socket");
                n = read(sockfd, buffer, BUFSIZE);
                if (n < 0) error("ERROR reading from socket");
                printf("%s\n", buffer);
                break;
            case 2:
                printf("Enter virus signature to add: ");
                scanf("%s", buffer);
                virii[5] = buffer;
                printf("%s added as virus signature!\n", virii[5]);
                break;
            case 3:
                printf("Enter virus signature to remove: ");
                scanf("%s", buffer);
                for (i = 0; i < 6; i++) {
                    if (strcmp(virii[i], buffer) == 0) {
                        virii[i] = clean[i];
                        printf("%s removed as virus signature!\n", buffer);
                    }
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    close(sockfd);
    return 0;
}