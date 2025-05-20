//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment{
    char name[20];
    int hour;
    int minute;
    struct appointment *next;
}*head=NULL;

void insert(char name[20], int h, int m){
    struct appointment *temp=(struct appointment*)malloc(sizeof(struct appointment));
    strcpy(temp->name, name);
    temp->hour=h;
    temp->minute=m;
    temp->next=NULL;
    if(head==NULL) head=temp;
    else{
        struct appointment *curr=head, *prev=NULL;
        while(curr!=NULL){
            if(curr->hour>temp->hour){
                if(prev!=NULL) prev->next=temp;
                else head=temp;
                temp->next=curr;
                return;
            }
            else if(curr->hour==temp->hour){
                if(curr->minute>temp->minute){
                    if(prev!=NULL) prev->next=temp;
                    else head=temp;
                    temp->next=curr;
                    return;
                }
            }
            prev=curr;
            curr=curr->next;
        }
        prev->next=temp;
    }
}

void display(){
    if(head==NULL) printf("No appointments scheduled for today.\n");
    else{
        struct appointment *curr=head;
        printf("Scheduled Appointments:\n");
        while(curr!=NULL){
            printf("%s: %d:%d\n", curr->name, curr->hour, curr->minute);
            curr=curr->next;
        }
    }
}

void delete(char name[20]){
    if(head==NULL) printf("No appointments scheduled for today.\n");
    else{
        struct appointment *curr=head, *prev=NULL;
        while(curr!=NULL){
            if(strcmp(curr->name, name)==0){
                if(prev!=NULL) prev->next=curr->next;
                else head=curr->next;
                free(curr);
                return;
            }
            prev=curr;
            curr=curr->next;
        }
        printf("%s has no appointment scheduled today.\n", name);
    }
}

int main(){
    printf("Welcome to the Appointment Scheduler!\n\n");
    printf("To schedule an appointment, enter appointment name, hour, minute in format (Name HH MM): \n");
    printf("To delete an appointment, enter (delete Name): \n");
    printf("To display all appointments, enter (display): \n");
    printf("To exit, enter (exit): \n");
    printf("\n");

    char input[30];
    char name[20];
    int h, m;

    while(1){
        fgets(input, sizeof(input), stdin);
        if(strncmp(input, "delete", 6)==0){
            sscanf(input+7, "%s", name);
            delete(name);
        }
        else if(strncmp(input, "display", 7)==0){
            display();
        }
        else if(strncmp(input, "exit", 4)==0){
            printf("Thank you for using Appointment Scheduler!\n");
            return 0;
        }
        else{
            sscanf(input, "%s %d %d", name, &h, &m);
            if(h<0 || h>23 || m<0 || m>59){
                printf("Invalid time format. Please enter in format (HH MM).\n");
                continue;
            }
            insert(name, h, m);
        }    
    }

    return 0;
}