//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void print_tower(int* arr1, int* arr2, int* arr3, int n) {
    printf("\n\nTower of Hanoi\n\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            if(j==0) {
                if(i<n-arr1[i]) printf("|");
                else printf(" ");
                for(int k=n-1;k>=arr1[i];k--) printf("*");
                printf(" ");
                if(i<n-arr1[i]) printf("|");
                else printf(" ");
                printf("\t");
            } else if(j==1) {
                if(i<n-arr2[i]) printf("|");
                else printf(" ");
                for(int k=n-1;k>=arr2[i];k--) printf("*");
                printf(" ");
                if(i<n-arr2[i]) printf("|");
                else printf(" ");
                printf("\t");
            } else {
                if(i<n-arr3[i]) printf("|");
                else printf(" ");
                for(int k=n-1;k>=arr3[i];k--) printf("*");
                printf(" ");
                if(i<n-arr3[i]) printf("|");
                else printf(" ");
                printf("\t");
            }
        }
        printf("\n");
    }
    printf("|");
    for(int i=0;i<n;i++) printf("-");
    printf("|\t|");
    for(int i=0;i<n;i++) printf("-");
    printf("|\t|");
    for(int i=0;i<n;i++) printf("-");
    printf("|");
    printf("\n");
    printf("|Tower 1|\t|Tower 2|\t|Tower 3|");
    printf("\n\n");
    sleep(1);
}

void move(int* from, int* to) {
    int temp = from[0];
    for(int i=0;i<9;i++) from[i] = from[i+1];
    to[temp+1] = temp;
}

void solve(int* arr1, int* arr2, int* arr3, int n) {
    while(1) {
        if(n%2==0) {
            if ((arr1[0]%2==0 && arr2[0]%2==0 && arr1[0]<arr2[0]) || (arr1[0]%2==1 && arr2[0]%2==1 && arr1[0]<arr2[0])) move(arr1, arr2);
            else if ((arr1[0]%2==0 && arr3[0]%2==0 && arr1[0]<arr3[0]) || (arr1[0]%2==1 && arr3[0]%2==1 && arr1[0]<arr3[0])) move(arr1, arr3);
            else if ((arr2[0]%2==0 && arr3[0]%2==0 && arr2[0]<arr3[0]) || (arr2[0]%2==1 && arr3[0]%2==1 && arr2[0]<arr3[0])) move(arr2, arr3);
            else if ((arr2[0]%2==0 && arr1[0]%2==0 && arr2[0]<arr1[0]) || (arr2[0]%2==1 && arr1[0]%2==1 && arr2[0]<arr1[0])) move(arr2, arr1);
            else if ((arr3[0]%2==0 && arr1[0]%2==0 && arr3[0]<arr1[0]) || (arr3[0]%2==1 && arr1[0]%2==1 && arr3[0]<arr1[0])) move(arr3, arr1);
            else if ((arr3[0]%2==0 && arr2[0]%2==0 && arr3[0]<arr2[0]) || (arr3[0]%2==1 && arr2[0]%2==1 && arr3[0]<arr2[0])) move(arr3, arr2);
        } else {
            if ((arr1[0]%2==0 && arr3[0]%2==0 && arr1[0]<arr3[0]) || (arr1[0]%2==1 && arr3[0]%2==1 && arr1[0]<arr3[0])) move(arr1, arr3);
            else if ((arr1[0]%2==0 && arr2[0]%2==0 && arr1[0]<arr2[0]) || (arr1[0]%2==1 && arr2[0]%2==1 && arr1[0]<arr2[0])) move(arr1, arr2);
            else if ((arr2[0]%2==0 && arr1[0]%2==0 && arr2[0]<arr1[0]) || (arr2[0]%2==1 && arr1[0]%2==1 && arr2[0]<arr1[0])) move(arr2, arr1);
            else if ((arr2[0]%2==0 && arr3[0]%2==0 && arr2[0]<arr3[0]) || (arr2[0]%2==1 && arr3[0]%2==1 && arr2[0]<arr3[0])) move(arr2, arr3);
            else if ((arr3[0]%2==0 && arr1[0]%2==0 && arr3[0]<arr1[0]) || (arr3[0]%2==1 && arr1[0]%2==1 && arr3[0]<arr1[0])) move(arr3, arr1);
            else if ((arr3[0]%2==0 && arr2[0]%2==0 && arr3[0]<arr2[0]) || (arr3[0]%2==1 && arr2[0]%2==1 && arr3[0]<arr2[0])) move(arr3, arr2);
        }
        print_tower(arr1, arr2, arr3, n);
        if(arr3[0]==n-1) break;
    }
}

int main() {
    srand(time(0));
    printf("Enter the size of Tower of Hanoi: ");
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n], arr3[n];
    for(int i=0;i<n;i++) {
        arr1[i] = i;
        arr2[i] = n;
        arr3[i] = n;
    }
    for(int i=0;i<100;i++) {
        int x = rand()%3;
        int y = rand()%3;
        if(x==0 && y==1) move(arr1, arr2);
        else if(x==0 && y==2) move(arr1, arr3);
        else if(x==1 && y==0) move(arr2, arr1);
        else if(x==1 && y==2) move(arr2, arr3);
        else if(x==2 && y==0) move(arr3, arr1);
        else if(x==2 && y==1) move(arr3, arr2);
    }
    print_tower(arr1, arr2, arr3, n);
    solve(arr1, arr2, arr3, n);
    return 0;
}