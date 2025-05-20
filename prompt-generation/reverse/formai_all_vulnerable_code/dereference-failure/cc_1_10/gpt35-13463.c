//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define RULES_FILE "firewall_rules.txt"
#define BUFSIZE 4096
#define MAX_RULES 100

void display_menu(){
    printf("\n***Welcome to the Firewall Control Center***\n");
    printf("Select an option:\n");
    printf("1. Add a rule\n");
    printf("2. Remove a rule\n");
    printf("3. View all rules\n");
    printf("4. Exit\n");
    printf(">>> ");
}

void add_rule(){
    FILE* fp = fopen(RULES_FILE, "a+");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Get input from user
    char protocol[10], ip[17], port_range[20];
    printf("\nEnter protocol (TCP/UDP): ");
    scanf("%s", protocol);
    printf("Enter IP address (x.x.x.x or x.x.x.x/y): ");
    scanf("%s", ip);
    printf("Enter port range (ex: 22-30): ");
    scanf("%s", port_range);

    // Add rule to file
    fprintf(fp, "%s %s %s\n", protocol, ip, port_range);
    printf("Rule added successfully!\n");

    fclose(fp);
}

void remove_rule(){
    FILE* fp = fopen(RULES_FILE, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Get input from user
    int line_num, count = 0;
    printf("\nEnter line number to delete: ");
    scanf("%d", &line_num);

    // Delete line from file
    FILE* tmp = fopen("temp.txt", "w");
    char line[BUFSIZE];
    while (fgets(line, BUFSIZE, fp) != NULL) {
        count++;
        if (count != line_num) {
            fputs(line, tmp);
        }
    }
    fclose(fp);
    fclose(tmp);

    remove(RULES_FILE);
    rename("temp.txt", RULES_FILE);
    printf("Rule deleted successfully!\n");
}

void view_rules(){
    FILE* fp = fopen(RULES_FILE, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Display all rules in file
    char line[BUFSIZE]; 
    while (fgets(line, BUFSIZE, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

bool check_rule(FILE* fp, char* protocol, char* ip, int port){
    char line[BUFSIZE], curr_ip[17], curr_port[20];
    while (fgets(line, BUFSIZE, fp) != NULL) {
        sscanf(line, "%s %s %s", protocol, curr_ip, curr_port);
        if (strcmp(ip, curr_ip) == 0) {
            char* port_range = strtok(curr_port, "-");
            int start_port = atoi(port_range);
            port_range = strtok(NULL, "-");
            int end_port = atoi(port_range);
            if (port >= start_port && port <= end_port) {
                return true;
            }
        }
    }
    return false;
}

void start_firewall(){
    char buf[BUFSIZE];
    struct sockaddr_in addr;
    socklen_t sin_size = sizeof(addr);
    int recvlen, sock_fd;
    char ip[17];

    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        printf("Error: Failed to create socket. %s.\n", strerror(errno));
        return;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);

    if (bind(sock_fd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        printf("Error: Failed to bind socket. %s.\n", strerror(errno));
        return;
    }

    printf("Firewall started successfully!\n");
    while (true) {
        recvlen = recvfrom(sock_fd, buf, BUFSIZE, 0, (struct sockaddr*) &addr, &sin_size);
        inet_ntop(AF_INET, &addr.sin_addr, ip, sizeof(ip));
        int port = ntohs(addr.sin_port);
        if (check_rule(fopen(RULES_FILE, "r"), buf, ip, port)) {
            printf("Blocked packet: %s %s %d\n", buf, ip, port);
            continue;
        }
        printf("Accepted packet: %s %s %d\n", buf, ip, port);
    }
}

int main(){
    int option = 0;
    do {
        display_menu();
        scanf("%d", &option);

        switch(option){
            case 1:
                add_rule();
                break;
            case 2:
                remove_rule();
                break;
            case 3:
                view_rules();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    } while(option != 4);

    start_firewall();
    return 0;
}