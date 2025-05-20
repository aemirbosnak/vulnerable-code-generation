//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include<stdio.h>
#include<stdlib.h>

typedef struct memnode{
    int start;
    int size;
    struct memnode* next;
}memnode;

memnode* head = NULL;

void create_memory(int start, int size){
    if(head == NULL){
        memnode* new_mem = (memnode*)malloc(sizeof(memnode));
        new_mem->start = start;
        new_mem->size = size;
        new_mem->next = NULL;
        head = new_mem;
        printf("\nMemory created successfully!\n");
        return;
    }
    else{
        memnode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        memnode* new_mem = (memnode*)malloc(sizeof(memnode));
        new_mem->start = temp->start + temp->size;
        new_mem->size = size;
        new_mem->next = NULL;
        temp->next = new_mem;
        printf("\nMemory created successfully!\n");
        return;
    }
}

void allocate_memory(int size){
    if(head == NULL){
        printf("\nNo memory available for allocation!\n");
        return;
    }
    else{
        memnode* temp = head;
        while(temp != NULL){
            if(temp->size < size){
                temp = temp->next;
            }
            else{
                int new_size = temp->size - size;
                if(new_size == 0){
                    printf("\nMemory allocated at address %d successfully!\n", temp->start);
                    if(temp == head){
                        head = temp->next;
                        free(temp);
                        return;
                    }
                    else{
                        memnode* prev = head;
                        while(prev->next != temp){
                            prev = prev->next;
                        }
                        prev->next = temp->next;
                        free(temp);
                        return;
                    }
                }
                else{
                    memnode* new_mem = (memnode*)malloc(sizeof(memnode));
                    new_mem->start = temp->start + size;
                    new_mem->size = new_size;
                    if(temp == head){
                        new_mem->next = temp->next;
                        head = new_mem;
                        temp->size = size;
                        printf("\nMemory allocated at address %d successfully!\n", temp->start);
                        return;
                    }
                    else{
                        new_mem->next = temp->next;
                        memnode* prev = head;
                        while(prev->next != temp){
                            prev = prev->next;
                        }
                        prev->next = new_mem;
                        temp->size = size;
                        printf("\nMemory allocated at address %d successfully!\n", temp->start);
                        return;
                    }
                }
            }
        }
    }
}

void free_memory(int start){
    if(head == NULL){
        printf("\nNo memory to free!\n");
        return;
    }
    else{
        memnode* temp = head;
        while(temp != NULL){
            if(temp->start == start){
                printf("\nMemory at address %d freed successfully!\n", start);
                if(temp == head){
                    head = temp->next;
                    free(temp);
                    return;
                }
                else{
                    memnode* prev = head;
                    while(prev->next != temp){
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    free(temp);
                    return;
                }
            }
            else{
                temp = temp->next;
            }
        }
        printf("\nNo memory found at address %d!\n", start);
        return;
    }
}

int main(){
    int choice, start, size;
    while(1){
        printf("\nEnter your choice:\n1. Create Memory\n2. Allocate Memory\n3. Free Memory\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the starting address of memory: ");
                scanf("%d", &start);
                printf("\nEnter the size of memory: ");
                scanf("%d", &size);
                create_memory(start, size);
                break;
            case 2:
                printf("\nEnter the size of memory to be allocated: ");
                scanf("%d", &size);
                allocate_memory(size);
                break;
            case 3:
                printf("\nEnter the starting address of memory to be freed: ");
                scanf("%d", &start);
                free_memory(start);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}