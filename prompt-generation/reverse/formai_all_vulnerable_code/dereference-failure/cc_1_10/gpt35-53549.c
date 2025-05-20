//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Romeo and Juliet
/* A Romance of Optimization
 * 
 * Written by: A Chatbot
 * 
 * Act I: Scene I
 * 
 * In fair C-System where we lay our scene,
 * From ancient code breaks new utility,
 * Where optimizing up program's memory
 * Is now the task of our dear hero's duty.
 * 
 * Enter ROMEO, a programmer, writing a main function.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Begin optimization
    printf("Oh, optimization! Where art thou?");
    
    /* Act II: Scene II
     * 
     * Enter JULIET, a system boot optimizer
     * 
     * JULIET:
     * Good sir ROMEO, why dost thou mope around?
     * Perchance I may assist with the optimization sound.
     */
    
    // Declare variables
    int count = 0;
    int *ptr;
    
    // Allocate memory for array
    ptr = (int*) malloc(sizeof(int)*1000);
    
    // Store random values in array
    for(count = 0;count < 1000; count++)
    {
        ptr[count] = rand()%1000;
    }
    
    // Sort the array
    for(count = 0; count < 1000; count++)
    {
        for(int i = count+1; i < 1000; i++)
        {
            if(ptr[count] > ptr[i])
            {
                int temp = ptr[count];
                ptr[count] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    
    // Deallocate memory for array
    free(ptr);
    
    // End optimization
    printf("\nOptimization complete, my dear Juliet!");
    
    return 0;
    
    /* End of Act II */
}

/* End of program */