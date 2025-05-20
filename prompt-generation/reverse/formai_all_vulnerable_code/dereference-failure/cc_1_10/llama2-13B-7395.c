//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BANK_ACCOUNT_SIZE 1024
#define BANK_MAX_WITHDRAWAL 1000

typedef struct bank_account {
    int balance;
    char name[20];
} bank_account_t;

typedef struct shared_memory {
    char name[20];
    bank_account_t accounts[10];
} shared_memory_t;

// Parent process
int main() {
    shared_memory_t* shared_mem = NULL;
    key_t key = IPC_PRIVATE;
    int shmid = -1;

    // Create shared memory
    shared_mem = (shared_memory_t*)shmat(IPC_PRIVATE, NULL, 0);
    if (shared_mem == (shared_memory_t*) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Fill shared memory with bank accounts
    for (int i = 0; i < 10; i++) {
        bank_account_t* account = &shared_mem->accounts[i];
        strcpy(account->name, "Customer");
        account->balance = 1000;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char* account_name = "John Doe";
        int withdrawal_amount = 500;

        // Retrieve bank account from shared memory
        bank_account_t* account = find_account(shared_mem, account_name);
        if (account == NULL) {
            printf("Account not found\n");
            exit(EXIT_FAILURE);
        }

        // Withdraw funds
        if (withdraw_funds(account, withdrawal_amount)) {
            printf("Withdrawal successful\n");
        } else {
            printf("Withdrawal failed\n");
        }

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}

// Child process
int find_account(shared_memory_t* shared_mem, char* account_name) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(shared_mem->accounts[i].name, account_name) == 0) {
            return &shared_mem->accounts[i];
        }
    }

    return NULL;
}

int withdraw_funds(bank_account_t* account, int withdrawal_amount) {
    if (withdrawal_amount > account->balance) {
        printf("Insufficient funds\n");
        return 0;
    }

    account->balance -= withdrawal_amount;
    printf("Withdrawal successful\n");

    return 1;
}