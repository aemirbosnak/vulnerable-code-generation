//Falcon-180B DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Memory management functions */
void *my_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr)
{
    free(ptr);
}

/* Example program */
int main()
{
    int *array1, *array2;
    int i;

    /* Allocate memory for array1 */
    array1 = my_malloc(10 * sizeof(int));

    /* Initialize array1 */
    for (i = 0; i < 10; i++) {
        array1[i] = i;
    }

    /* Allocate memory for array2 */
    array2 = my_malloc(5 * sizeof(int));

    /* Initialize array2 */
    for (i = 0; i < 5; i++) {
        array2[i] = i;
    }

    /* Print the contents of array1 */
    printf("Array1: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    /* Print the contents of array2 */
    printf("Array2: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    /* Free the memory allocated for array1 */
    my_free(array1);

    /* Free the memory allocated for array2 */
    my_free(array2);

    return 0;
}