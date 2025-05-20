//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold the data of each record
struct customer{
    int id;
    char name[30];
    char city[20];
};

//structure to hold the data of each index record
struct index{
    int id;
    int offset;
};

//function to compare two index records
int compare(const void* a, const void* b){
    return (((struct index*)a)->id - ((struct index*)b)->id);
}

int main(){
    FILE *fp, *fpindex;
    struct customer cust;
    struct index ind;
    int i, n, count=0, pos=0;

    //create a file and store customer data in it
    fp = fopen("customer.txt", "w");

    printf("Enter the number of customers: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter customer id, name and city: ");
        scanf("%d %s %s", &cust.id, cust.name, cust.city);
        fwrite(&cust, sizeof(cust), 1, fp);
    }

    fclose(fp);

    //create an index file and store customer ids and their positions in the data file
    fp = fopen("customer.txt", "r");
    fpindex = fopen("customer_index.txt", "w");

    while(fread(&cust, sizeof(cust), 1, fp)){
        ind.id = cust.id;
        ind.offset = pos;
        fwrite(&ind, sizeof(ind), 1, fpindex);
        pos = ftell(fp);
    }

    fclose(fp);
    fclose(fpindex);

    //open index file and read the records into an array and sort them
    fpindex = fopen("customer_index.txt", "r");
    fseek(fpindex, 0, SEEK_END);
    count = ftell(fpindex)/sizeof(ind);
    fseek(fpindex, 0, SEEK_SET);

    struct index indexlist[count];

    fread(&indexlist, sizeof(ind), count, fpindex);

    qsort(indexlist, count, sizeof(struct index), compare);

    fclose(fpindex);

    //search for a record using binary search
    int id, first=0, last=count-1, middle;

    printf("Enter customer id to search: ");
    scanf("%d", &id);

    while(first <= last){
        middle = (first + last)/2;
        if(indexlist[middle].id < id)
            first = middle + 1;
        else if(indexlist[middle].id == id){
            fp = fopen("customer.txt", "r");
            fseek(fp, indexlist[middle].offset, SEEK_SET);
            fread(&cust, sizeof(cust), 1, fp);
            printf("Record found: id=%d, name=%s, city=%s", cust.id, cust.name, cust.city);
            fclose(fp);
            break;
        }
        else
            last = middle - 1;
    }

    if(first > last)
        printf("Record not found!");

    return 0;
}