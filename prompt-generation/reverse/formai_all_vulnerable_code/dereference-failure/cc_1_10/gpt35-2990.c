//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_CONNECTIONS 1000

typedef struct {
    int id;
    char ip[16];
} User;

typedef struct {
    int id;
    int src_id;
    int dest_id;
    int timestamp;
} Connection;

int main() {
    User users[MAX_USERS];
    Connection connections[MAX_CONNECTIONS];
    int num_users = 0;
    int num_connections = 0;
    
    // read in user data
    FILE* users_file = fopen("users.txt", "r");
    char line[30];
    while (fgets(line, 30, users_file)) {
        char* token = strtok(line, ",");
        users[num_users].id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(users[num_users].ip, token);
        num_users++;
    }
    fclose(users_file);
    
    // read in connection data
    FILE* connections_file = fopen("connections.txt", "r");
    while (fgets(line, 30, connections_file)) {
        char* token = strtok(line, ",");
        connections[num_connections].id = atoi(token);
        token = strtok(NULL, ",");
        connections[num_connections].src_id = atoi(token);
        token = strtok(NULL, ",");
        connections[num_connections].dest_id = atoi(token);
        token = strtok(NULL, ",");
        connections[num_connections].timestamp = atoi(token);
        num_connections++;
    }
    fclose(connections_file);
    
    // analyze connections
    for (int i = 0; i < num_connections; i++) {
        Connection conn = connections[i];
        int src_id = conn.src_id;
        int dest_id = conn.dest_id;
        int src_ip[4];
        int dest_ip[4];
        
        // convert source IP to int array
        char* token = strtok(users[src_id].ip, ".");
        src_ip[0] = atoi(token);
        token = strtok(NULL, ".");
        src_ip[1] = atoi(token);
        token = strtok(NULL, ".");
        src_ip[2] = atoi(token);
        token = strtok(NULL, ".");
        src_ip[3] = atoi(token);
        
        // convert destination IP to int array
        token = strtok(users[dest_id].ip, ".");
        dest_ip[0] = atoi(token);
        token = strtok(NULL, ".");
        dest_ip[1] = atoi(token);
        token = strtok(NULL, ".");
        dest_ip[2] = atoi(token);
        token = strtok(NULL, ".");
        dest_ip[3] = atoi(token);
        
        // check for suspicious behavior
        if ((src_ip[0] == 192 && src_ip[1] == 168) || (src_ip[0] == 10) ||
            (dest_ip[0] == 192 && dest_ip[1] == 168) || (dest_ip[0] == 10)) {
            printf("Connection %d is suspicious!\n", conn.id);
        }
    }
    
    return 0;
}