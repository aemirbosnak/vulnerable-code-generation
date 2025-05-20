//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// This memory management program is going to be a party! Let's get started!

int main() {

    // Let's start by declaring pointers for our partygoers
    char *partyGuest1 = NULL;
    int *partyGuest2 = NULL;
    float *partyGuest3 = NULL;

    // Next, we'll assign some memory space for them to party in!
    partyGuest1 = (char*) malloc(25 * sizeof(char));
    partyGuest2 = (int*) malloc(10 * sizeof(int));
    partyGuest3 = (float*) malloc(5 * sizeof(float));

    // Now that we've got our memory space ready, let's set the party atmosphere!
    printf("Welcome to the best party in town!\n\n");

    // Each of our partygoers needs a name tag so we can keep track of everyone.
    // Let's assign some values to their memory space so they know who they are!
    strcpy(partyGuest1, "Jenny");
    partyGuest2[0] = 47;
    partyGuest3[3] = 3.14159;

    // Let's check in on the partygoers and make sure they're having a good time.
    printf("%s is having a great time at the party!\n", partyGuest1);
    printf("%d is really enjoying the music!\n", partyGuest2[0]);
    printf("%f just had a delicious snack!\n\n", partyGuest3[3]);

    // Uh-oh, it looks like we need some more room for our guests to dance!
    // Let's use realloc to expand the memory space for one of our partygoers.
    partyGuest2 = (int*) realloc(partyGuest2, 20 * sizeof(int));

    // Now that we've got more space, let's invite some new guests to the party!
    partyGuest2[10] = 100;
    partyGuest2[14] = 57;

    // Let's check in on our original partygoers and see how they're doing.
    printf("%s is still having a blast! They haven't stopped dancing!\n", partyGuest1);
    printf("%d is a little tired but is still having fun!\n", partyGuest2[0]);
    printf("%f just met some new friends and is having a great time!\n\n", partyGuest3[3]);

    // As the party starts to wind down, let's clean up after ourselves.
    // Using free, we'll delete the memory space we used for our partygoers.
    free(partyGuest1);
    free(partyGuest2);
    free(partyGuest3);

    // And finally, let's say goodbye to everyone who came to the party!
    printf("Thanks for coming! We had a great time and hope to see you all again soon!\n");

    return 0;
}