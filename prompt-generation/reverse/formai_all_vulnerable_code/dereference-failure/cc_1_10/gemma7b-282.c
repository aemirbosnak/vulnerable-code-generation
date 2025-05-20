//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080

typedef struct BankRecord
{
    char name[50];
    int account_no;
    double balance;
    struct BankRecord* next;
} BankRecord;

BankRecord* insert_record(BankRecord* head, char* name, int account_no, double balance)
{
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if (head == NULL)
    {
        head = new_record;
    }
    else
    {
        head->next = new_record;
    }

    return head;
}

void print_records(BankRecord* head)
{
    while (head)
    {
        printf("%s, %d, %f\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

int main()
{
    BankRecord* head = NULL;

    // Start a server
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    listen(sockfd, 10);

    // Accept connections
    while (1)
    {
        int connfd = accept(sockfd, NULL, NULL);

        // Receive data
        char* name;
        int account_no;
        double balance;
        recv(connfd, &name, sizeof(name), 0);
        recv(connfd, &account_no, sizeof(account_no), 0);
        recv(connfd, &balance, sizeof(balance), 0);

        // Insert record
        head = insert_record(head, name, account_no, balance);

        // Send confirmation
        send(connfd, "Record inserted.", 18, 0);

        close(connfd);
    }

    // Print records
    print_records(head);

    return 0;
}