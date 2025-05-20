//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct task{
    char task_name[20];
    int time;
    struct task *next;
};

struct task *head=NULL;

void insert(){ //inserts a task to scheduler
    struct task *temp=(struct task*)malloc(sizeof(struct task));
    printf("Enter task name: ");
    scanf("%s", temp->task_name);
    printf("Enter task time (in seconds): ");
    scanf("%d", &temp->time);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct task *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void delete(){ //deletes the first task in scheduler
    if(head==NULL){
        printf("Scheduler is empty.\n");
    }
    else{
        printf("Task '%s' with time %d seconds is deleted from Scheduler.\n", head->task_name, head->time);
        head=head->next;
    }
}

void display(){ //displays the tasks in scheduler
    if(head==NULL){
        printf("Scheduler is empty.\n");
    }
    else{
        struct task *ptr=head;
        printf("***** SCHEDULER *****\n");
        while(ptr!=NULL){
            printf("Task Name: %s\tTime: %d seconds\n", ptr->task_name, ptr->time);
            ptr=ptr->next;
        }
    }
}

void run(){ //executes the tasks in scheduler
    if(head==NULL){
        printf("Scheduler is empty.\n");
    }
    else{
        printf("----- RUNNING SCHEDULER -----\n");
        struct task *ptr=head;
        while(ptr!=NULL){
            printf("Running Task '%s' for %d seconds...\n", ptr->task_name, ptr->time);
            sleep(ptr->time); //pause the execution for time seconds
            ptr=ptr->next;
        }
        printf("----- SCHEDULER EXECUTION COMPLETE -----\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n***** TASK SCHEDULER *****\n");
        printf("1. Insert Task\n2. Delete Task\n3. Display Scheduler\n4. Run Scheduler\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                run();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}