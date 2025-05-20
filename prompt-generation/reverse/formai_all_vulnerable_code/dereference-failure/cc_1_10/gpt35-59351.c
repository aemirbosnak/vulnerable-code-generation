//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct data_block{
    int id;
    char data[50];
};

struct data_block* read_data(int id){
    FILE *fp;
    struct data_block *block = malloc(sizeof(struct data_block));
    fp = fopen("data.bin", "rb");
    if(fp==NULL) {
        printf("Cannot open file\n");
        return NULL;
    }

    while(fread(block, sizeof(struct data_block), 1, fp)) {
        if(block->id == id) {
            fclose(fp);
            return block;
        }
    }

    fclose(fp);
    free(block);
    return NULL;
}

int write_data(struct data_block *block){
    FILE *fp;
    fp = fopen("data.bin", "ab");
    if(fp==NULL) {
        printf("Cannot open file\n");
        return 0;
    }
    fwrite(block, sizeof(struct data_block), 1, fp);
    fclose(fp);
    return 1;
}

int main(){
    printf("Welcome to the Retro Data Recovery Tool\n");

    while(1){
        printf("\nEnter data ID to recover: ");
        int id;
        scanf("%d", &id);
        struct data_block *block = read_data(id);
        if(block!=NULL){
            printf("Data Block Found!\n");
            printf("ID:   %d\n", block->id);
            printf("Data: %s\n\n", block->data);
            free(block);
        }
        else{
            printf("Data Block Not Found!\n");
        }
        printf("Do you want to add new data? (Y/N): ");
        char ans;
        scanf("\n%c", &ans);
        if(ans=='Y' || ans=='y'){
            struct data_block *new_block = malloc(sizeof(struct data_block));
            printf("\nEnter data ID to add: ");
            scanf("%d", &(new_block->id));
            printf("Enter data to add: ");
            scanf("%s", new_block->data);
            if(write_data(new_block)){
                printf("Data Block Added.\n");
            }
            else{
                printf("Error while adding Data Block.\n");
            }
            free(new_block);
        }
        printf("Do you want to continue? (Y/N): ");
        scanf("\n%c", &ans);
        if(ans=='N' || ans=='n'){
            printf("\nGoodbye!\n");
            break;
        }
    }
    return 0;
}