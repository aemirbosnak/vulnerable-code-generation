//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct diary{
    char subject[50];
    char date[15];
    char time[10];
    char note[250];
    struct diary *next;
} *head=NULL,*ptr=NULL,*temp;

void addEntry(){
    temp = (struct diary*) malloc(sizeof(struct diary));
    printf("\nEnter Subject: ");
    scanf("%s",temp->subject);
    printf("\nEnter Date (DD/MM/YYYY): ");
    scanf("%s",temp->date);
    printf("\nEnter Time (HH:MM): ");
    scanf("%s",temp->time);
    printf("\nEnter Note: ");
    scanf("%s",temp->note);
    temp->next=NULL;
    if(head==NULL)
        head=ptr=temp;
    else{
        ptr->next=temp;
        ptr=ptr->next;
    }
    printf("\nEntry Added Successfully!\n");
    return;
}

void displayEntries(struct diary *ptr){
    if(ptr==NULL){
        printf("No entries found in the Digital Diary.");
        return;
    }
    printf("\nSubject: %s\nDate: %s\nTime: %s\nNote: %s\n",ptr->subject,ptr->date,ptr->time,ptr->note);
    if(ptr->next!=NULL)
        displayEntries(ptr->next);
    return;
}

void deleteEntry(){
    if(head==NULL){
        printf("\nList is already empty.\n");
        return;
    }
    char delSubject[50];
    printf("\nEnter Subject of entry to be deleted: ");
    scanf("%s",delSubject);
    if(head->next==NULL && strcmp(head->subject,delSubject)==0){
        free(head);
        head=NULL;
        printf("\nEntry Deleted Successfully!\n");
        return;
    }
    if(strcmp(head->subject,delSubject)==0){
        temp=head;
        head=head->next;
        free(temp);
        printf("\nEntry Deleted Successfully!\n");
        return;
    }
    ptr=head;
    while(ptr->next!=NULL && strcmp(ptr->next->subject,delSubject)!=0)
        ptr=ptr->next;
    if(ptr->next==NULL){
        printf("\nEntry with subject %s not found!\n",delSubject);
        return;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    printf("\nEntry Deleted Successfully!\n");
    return;
}

int main(){
    int choice;
    printf("\n\nWelcome to the Digital Diary!\n\n");
    while(1){
        printf("\n\t---------------------\n");
        printf("\n\t1. Add Entry\n\t2. Display Entries\n\t3. Delete Entry\n\t4. Exit\n");
        printf("\n\t---------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addEntry();
                    break;
            case 2: displayEntries(head);
                    break;
            case 3: deleteEntry();
                    break;
            case 4: printf("\n\nGoodbye!\n\n");
                    exit(0);
            default: printf("\n\nWrong choice! Please try again.\n\n");
                     break;
        }
    }
    return 0;
}