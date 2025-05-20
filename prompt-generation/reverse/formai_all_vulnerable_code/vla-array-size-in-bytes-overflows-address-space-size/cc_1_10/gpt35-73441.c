//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Data structure for storing the index
struct Index{
    char key[20];
    int address;
};

int main()
{
    int n; //number of records
    printf("Enter the number of records: ");
    scanf("%d", &n);
    getchar();

    char filename[50];
    printf("Enter the name of the file: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = 0; //remove newline character

    //open the file in read mode
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Couldn't open file!\n");
        exit(1);
    }

    //initialize index table
    struct Index indexTable[n];

    //read each record from the file and store it in the index table
    for(int i=0; i<n; i++){
        char record[100];
        fgets(record, 100, file);
        char *token = strtok(record, ",");
        strcpy(indexTable[i].key, token);
        indexTable[i].address = ftell(file); //store the file pointer address
    }

    //close the file
    fclose(file);

    //display the index table
    printf("Index Table:\n");
    for(int i=0; i<n; i++){
        printf("%s: %d\n", indexTable[i].key, indexTable[i].address);
    }

    //search for a record
    char searchKey[20];
    printf("Enter the key to search: ");
    fgets(searchKey, 20, stdin);
    searchKey[strcspn(searchKey, "\n")] = 0; //remove newline character

    //perform binary search
    int l=0, r=n-1, mid, flag=0;
    while(l<=r){
        mid = (l+r)/2;
        if(strcmp(searchKey, indexTable[mid].key) == 0){
            flag=1;
            break;
        }
        else if(strcmp(searchKey, indexTable[mid].key) < 0)
            r = mid-1;
        else
            l = mid+1;
    }

    //display the result
    if(flag==1)
        printf("Record Found at address %d\n", indexTable[mid].address);
    else
        printf("Record Not Found\n");

    return 0;
}