//FormAI DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>

#define ITEM_NAME_LEN 50
#define ITEM_ID_LEN 10
#define ITEM_QUANTITY_LEN 5

// Structure definition for inventory item.
struct InventoryItem {
    char item_name[ITEM_NAME_LEN];
    char item_id[ITEM_ID_LEN];
    char item_quantity[ITEM_QUANTITY_LEN];
};

// Print inventory item details.
void printItem(struct InventoryItem item) {
    printf("Item Name: %s\nItem ID: %s\nItem Quantity: %s\n\n", item.item_name, item.item_id, item.item_quantity);
}

// Read inventory items from file.
void readItemsFromFile(struct InventoryItem *items, int num_items) {
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    for(int i=0; i<num_items; i++) {
        fscanf(fp, "%s %s %s", items[i].item_name, items[i].item_id, items[i].item_quantity);
    }
    fclose(fp);
}

// Write updated inventory items to file.
void writeItemsToFile(struct InventoryItem *items, int num_items) {
    FILE *fp;
    fp = fopen("inventory.txt", "w");
    for(int i=0; i<num_items; i++) {
        fprintf(fp, "%s %s %s\n", items[i].item_name, items[i].item_id, items[i].item_quantity);
    }
    fclose(fp);
}

// Search for inventory item by item_id.
struct InventoryItem searchItem(struct InventoryItem *items, int num_items, char *item_id) {
    for(int i=0; i<num_items; i++) {
        if(strcmp(items[i].item_id, item_id) == 0) {
            return items[i];
        }
    }
    struct InventoryItem empty_item = {"", "", ""};
    return empty_item;
}

// Function to handle incoming client requests.
void handleRequests(int sockfd, struct InventoryItem *items, int num_items) {
    char buffer[256];
    bool quit = false;
    while(!quit) {
        // Read client request.
        bzero(buffer, 256);
        int n = read(sockfd, buffer, 255);
        if(n < 0) {
            perror("Error reading from socket");
            break;
        }

        // Process client request.
        if(strncmp(buffer, "search", 6) == 0) {
            char *item_id = strtok(buffer+7, "\n");
            struct InventoryItem item = searchItem(items, num_items, item_id);
            if(strcmp(item.item_id, "") == 0) {
                write(sockfd, "Item not found\n", 15);
            } else {
                char result[256];
                sprintf(result, "%s %s %s\n", item.item_name, item.item_id, item.item_quantity);
                write(sockfd, result, strlen(result));
            }
        } else if(strncmp(buffer, "quit", 4) == 0) {
            quit = true;
            write(sockfd, "Goodbye!\n", 9);
        } else {
            write(sockfd, "Invalid command\n", 16);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n, num_items;

    if(argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    // Read inventory items from file.
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if(fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fscanf(fp, "%d", &num_items);
    struct InventoryItem *items = (struct InventoryItem*)malloc(num_items*sizeof(struct InventoryItem));
    readItemsFromFile(items, num_items);
    fclose(fp);

    // Create TCP socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address.
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address.
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming client connections.
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    while(1) {
        // Accept incoming client connection.
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if(newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        // Handle client requests.
        handleRequests(newsockfd, items, num_items);

        // Close client connection.
        close(newsockfd);
    }

    // Write updated inventory items to file.
    writeItemsToFile(items, num_items);

    // Free dynamically allocated memory.
    free(items);
    return 0;
}