//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split the list into buckets based on the first letter of each word
void splitList(char *words[], int listSize) {
    int i;
    int numBuckets = 26;
    int *buckets = (int *)malloc(numBuckets * sizeof(int));
    for (i = 0; i < listSize; i++) {
        int index = 0;
        while (index < numBuckets && toupper(words[i][0]) > 'A' + index)
            index++;
        buckets[index]++;
    }
    for (i = 0; i < numBuckets; i++)
        printf("%c: %d\n", 'A' + i, buckets[i]);
}

// Function to merge the buckets back into a sorted list
void mergeBuckets(char *words[], int listSize) {
    int i, j, k;
    char *temp = (char *)malloc((listSize * 2) * sizeof(char));
    int numBuckets = 26;
    for (i = 0; i < numBuckets; i++) {
        int index = 0;
        for (j = 0; j < listSize; j++) {
            int bucketIndex = 0;
            while (bucketIndex < numBuckets && toupper(words[j][0]) > 'A' + bucketIndex)
                bucketIndex++;
            temp[index++] = words[j][bucketIndex];
        }
        for (j = 0; j < index; j++)
            words[j] = temp + j;
    }
    free(temp);
}

int main() {
    char words[10][20] = {
        "apple",
        "banana",
        "cherry",
        "date",
        "elderberry",
        "fig",
        "grape",
        "honeydew",
        "kiwi",
        "lemon",
    };
    int listSize = 10;
    splitList(words, listSize);
    mergeBuckets(words, listSize);
    for (int i = 0; i < listSize; i++)
        printf("%s\n", words[i]);
    return 0;
}