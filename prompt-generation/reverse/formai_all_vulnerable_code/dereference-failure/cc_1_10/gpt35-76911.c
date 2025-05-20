//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int *array, int n){
    srand(time(NULL));
    int i, j, temp;
    for(i=n-1;i>0;i--){
        j=rand()%(i+1);
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
}

void display(int *array, int n){
    int i;
    printf("\n\t");
    for(i=0;i<n;i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int match(int *array, int n){
    int i;
    
    for(i=0;i<n-1;i++){
        if(array[i]!=array[i+1])
            return 0;
    }
    return 1;
}

int play(int *array, int n, int count, int first, int second){
    display(array, n);
    printf("\n\n Number of moves: %d\n", count);
    
    if(match(array,n)==1){
        printf("\n\n Yeahhhh!! You matched all the numbers in %d moves", count);
        return 0;
    }
    
    printf("\n\n Enter first number to flip: ");
    scanf("%d", &first);
    if(first<0 || first>n-1){
        printf("\nInvalid input!\n");
        return play(array,n,count,first,second);
    }
    
    printf("\nEnter second number to flip: ");
    scanf("%d", &second);
    if(second<0 || second>n-1){
        printf("\nInvalid input!\n");
        return play(array,n,count,first,second);
    }
    
    int temp=array[first];
    array[first]=array[second];
    array[second]=temp;
    
    return play(array,n,count+1,first,second);
}

int main(){
    printf("\n\n\t---C MEMORY GAME---\n");
    printf("\nRules: Flip the numbers to match them all!\n");
    
    int num=4;
    int count=0;
    int first, second;
    int *array=(int*)malloc(num*sizeof(int));
    
    int i, j=0;
    for(i=1;i<=num/2;i++){
        array[j]=i;
        array[j+1]=i;
        j+=2;
    }
    
    shuffle(array, num);
    
    play(array, num, count, first, second);
    
    return 0;
}