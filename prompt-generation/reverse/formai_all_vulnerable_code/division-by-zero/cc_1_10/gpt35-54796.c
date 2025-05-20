//FormAI DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50 //Maximum number of records

typedef struct {
    int license_no;
    char name[20];
    char address[50];
    char phone[15];
} RECORD; //record structure of a person's data

int block_size; //block size for indexing

void createIndex(RECORD [], int [], int);
void display(RECORD []);
int binarySearch(RECORD [], int [], int, int, int);
void insertRecord(RECORD [], int [], int);
void searchRecord(RECORD [], int [], int);
void deleteRecord(RECORD [], int [], int);

int main() {
    RECORD records[MAX]; //array of records
    int index[MAX]; //array of indexes
    int choice, n=0;

    //getting the block size for 2-level indexing
    printf("Enter block size for indexing: ");
    scanf("%d", &block_size);

    while(1) {
        printf("\n\nMENU\n\n");
        printf("1. Create Index\n");
        printf("2. Display all Records\n");
        printf("3. Insert a Record\n");
        printf("4. Search for a Record\n");
        printf("5. Delete a Record\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createIndex(records, index, n); break;
            case 2: display(records); break;
            case 3: insertRecord(records, index, n); n++; break;
            case 4: searchRecord(records, index, n); break;
            case 5: deleteRecord(records, index, n); n--; break;
            case 6: exit(0);
            default: printf("\nInvalid Choice. Try Again.");
        }
    }
    return 0;
}

//function to create indexes for each block
void createIndex(RECORD records[], int index[], int n) {
    int i;
    for(i=0; i<n; i++) {
        if(i%block_size==0) index[i/block_size]=records[i].license_no;
    }
    printf("\nIndexes created successfully.");
}

//function to display all records
void display(RECORD records[]) {
    int i;
    printf("\nLicense No.\tName\t\tAddress\t\tPhone\n");
    for(i=0; i<MAX; i++) {
        if(records[i].license_no!=0) {
            printf("%d\t\t%s\t\t%s\t\t%s\n", records[i].license_no, records[i].name, records[i].address, records[i].phone);
        }
    }
}

//function to perform binary search
int binarySearch(RECORD records[], int index[], int l, int r, int key) {
    int mid;
    while(l<=r) {
        mid=(l+r)/2;
        if(key==index[mid]) {
            return mid;
        }
        else if(key<index[mid]) {
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return -1;
}

//function to insert a record
void insertRecord(RECORD records[], int index[], int n) {
    RECORD temp;
    int i, pos;
    printf("\nEnter License No.: ");
    scanf("%d", &temp.license_no);

    pos=binarySearch(records, index, 0, n/block_size, temp.license_no);

    if(pos==-1) {
        printf("\nEnter Name: ");
        scanf("%s", temp.name);
        printf("Enter Address: ");
        scanf("%s", temp.address);
        printf("Enter Phone: ");
        scanf("%s", temp.phone);

        records[n]=temp;
        for(i=(n/block_size)*block_size; i<=n; i++) {
            if(i%block_size==0) index[i/block_size]=records[i].license_no;
        }
        printf("\nRecord Inserted Successfully.");
    }
    else {
        printf("\nRecord Already Exists.");
    }
}

//function to search for a record
void searchRecord(RECORD records[], int index[], int n) {
    int key, pos;
    printf("\nEnter License No. to Search: ");
    scanf("%d", &key);

    pos=binarySearch(records, index, 0, n/block_size, key);

    if(pos==-1) {
        printf("\nRecord Not Found.");
    }
    else {
        printf("\nLicense No.\tName\t\tAddress\t\tPhone\n");
        printf("%d\t\t%s\t\t%s\t\t%s\n", records[block_size*pos].license_no, records[block_size*pos].name, records[block_size*pos].
        address, records[block_size*pos].phone);
    }
}

//function to delete a record
void deleteRecord(RECORD records[], int index[], int n) {
    int key, pos, i;
    printf("\nEnter License No. to Delete: ");
    scanf("%d", &key);

    pos=binarySearch(records, index, 0, n/block_size, key);

    if(pos==-1) {
        printf("\nRecord Not Found.");
    }
    else {
        for(i=pos*block_size; i<(pos+1)*block_size; i++) {
            if(records[i].license_no==key) {
                memset(records[i].name, 0, sizeof(records[i].name));
                memset(records[i].address, 0, sizeof(records[i].address));
                memset(records[i].phone, 0, sizeof(records[i].phone));
                records[i].license_no=0;
            }
        }
        printf("\nRecord Deleted Successfully.");
    }       
}