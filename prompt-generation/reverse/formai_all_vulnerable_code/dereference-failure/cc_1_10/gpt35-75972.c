//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct banking_record{
    char name[50];
    int account_no;
    int balance;
    struct banking_record *next;
};

typedef struct banking_record Record;

void insert_record(Record **head, char name[], int account_no, int balance){
    Record *new_record = (Record *) malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->account_no = account_no;
    new_record->balance = balance;
    new_record->next = NULL;

    if(*head == NULL){
        *head = new_record;
    }
    else{
        Record *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_record;
    }
}

void display_records(Record *head){
    printf("Name    \tAccount No.\tBalance\n");
    while(head != NULL){
        printf("%s\t%d\t%d\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

Record * search_record(Record *head, int account_no){
    while(head != NULL){
        if(head->account_no == account_no){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void update_balance(Record *head, int account_no, int amount){
    Record *record = search_record(head, account_no);
    if(record != NULL){
        record->balance += amount;
    }
}

void delete_record(Record **head, int account_no){
    Record *current = *head, *previous = NULL;
    while(current != NULL){
        if(current->account_no == account_no){
            break;
        }
        previous = current;
        current = current->next;
    }
    if(current != NULL){
        if(previous == NULL){
            *head = current->next;
        }
        else{
            previous->next = current->next;
        }
        free(current);
        printf("Record deleted successfully!\n");
    }
}

int main(){
    Record *head = NULL;

    insert_record(&head, "John Doe", 101, 500);
    insert_record(&head, "Jane Smith", 102, 700);
    insert_record(&head, "Tom Williams", 103, 1000);

    display_records(head);
    printf("\n");

    update_balance(head, 101, 200);
    update_balance(head, 102, -100);

    display_records(head);
    printf("\n");

    delete_record(&head, 103);

    display_records(head);

    return 0;
}