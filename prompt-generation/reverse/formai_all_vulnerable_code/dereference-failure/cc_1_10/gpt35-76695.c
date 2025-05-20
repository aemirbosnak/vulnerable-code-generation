//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct index_element{
    int page_no;
    int offset;
};

void add_element(struct index_element *index_array, int *index_size, int page_no, int offset){
    index_array[*index_size].page_no = page_no;
    index_array[*index_size].offset = offset;
    (*index_size)++;
}

int search_element(struct index_element *index_array, int index_size, int page_no, int offset){
    for(int i=0; i<index_size; i++){
        if(index_array[i].page_no == page_no && index_array[i].offset == offset)
            return i;
    }
    return -1;
}

void remove_element(struct index_element *index_array, int *index_size, int index){
    for(int i=index; i<*index_size-1; i++)
        index_array[i] = index_array[i+1];
    (*index_size)--;
}

int main(){
    int choice, page_no, offset, index_size=0;
    struct index_element *index_array = (struct index_element*)malloc(sizeof(struct index_element)*100);
    
    while(1){
        printf("Enter your choice:\n1. Add element\n2. Search element\n3. Remove element\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: //adding element
                printf("Enter the page no: ");
                scanf("%d", &page_no);
                printf("Enter the offset: ");
                scanf("%d", &offset);
                add_element(index_array, &index_size, page_no, offset);
                printf("Element added successfully!\n\n");
                break;
            case 2: //searching element
                printf("Enter the page no: ");
                scanf("%d", &page_no);
                printf("Enter the offset: ");
                scanf("%d", &offset);
                int index = search_element(index_array, index_size, page_no, offset);
                if(index == -1)
                    printf("Element not found!\n\n");
                else
                    printf("Element found at index: %d\n\n", index);
                break;
            case 3: //removing element
                printf("Enter the page no: ");
                scanf("%d", &page_no);
                printf("Enter the offset: ");
                scanf("%d", &offset);
                int index2 = search_element(index_array, index_size, page_no, offset);
                if(index2 == -1)
                    printf("Element not found!\n\n");
                else{
                    remove_element(index_array, &index_size, index2);
                    printf("Element removed successfully!\n\n");
                }
                break;
            case 4: //exit
                free(index_array);
                exit(0);
            default:
                printf("Invalid Choice!\n\n");
        }
    }
    return 0;
}