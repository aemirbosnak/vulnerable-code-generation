//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Memory Management Funhouse!\n\n");
    printf("In this program, we will be allocating and deallocating memory like there's no tomorrow!\n\n");

    int *ptr = NULL;

    printf("First, let's allocate some memory....\n");
    
    ptr = (int *) malloc(10 * sizeof(int));

    if(ptr == NULL) {
        printf("Oops, couldn't allocate memory! Better luck next time!\n");
        exit(1);
    }

    printf("Looks like we allocated some memory successfully!\n\n");
    printf("Now let's write some data into that memory...\n");

    for(int i = 0; i < 10; i++) {
        ptr[i] = i * 2;
    }

    printf("Great, now let's print out what we wrote...\n");

    for(int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\n\n");

    printf("Now let's deallocate that memory...!\n");

    free(ptr);

    printf("And just like that, it's gone! See you later, memory! Thanks for the good times!\n\n");

    printf("But wait... let's try to access that memory one more time!\n");
    printf("Just for kicks, you know?");

    for(int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\n\n");

    printf("Well, that didn't work... looks like we tried to access some memory we don't have anymore!\n");
    printf("I hope you had fun in the Memory Management Funhouse! Until next time...\n");

    return 0;
}