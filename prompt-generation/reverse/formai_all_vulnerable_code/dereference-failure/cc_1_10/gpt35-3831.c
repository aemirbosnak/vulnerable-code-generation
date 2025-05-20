//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to our C Data recovery tool program!\n");
    printf("We have a surprise for you today - a unique method to recover data from corrupted files.\n");

    char fileName[50];
    printf("\nPlease enter the name of the file you want to recover: ");
    scanf("%s", fileName);

    FILE *filePtr;
    filePtr = fopen(fileName, "rb");

    if (filePtr == NULL)
    {
        printf("\nSorry, we couldn't find the file. Please check the name and try again.\n");
        return 0;
    }

    fseek(filePtr, 0, SEEK_END);

    long int fileSize = ftell(filePtr);

    if (fileSize <= 0)
    {
        printf("\nSorry, the file is empty or corrupted. We cannot recover anything from it.\n");
        return 0;
    }

    char *fileData = (char *) malloc(fileSize * sizeof(char));

    fseek(filePtr, 0, SEEK_SET);
    fread(fileData, sizeof(char), fileSize, filePtr);

    char recoveredData[fileSize];
    int index = 0;

    for (int i = 0; i < fileSize; i++)
    {
        if (fileData[i] != '\0')
        {
            recoveredData[index] = fileData[i];
            index++;
        }
    }

    printf("\nThe data has been recovered successfully! Here is your file content:\n");

    for (int i = 0; i < index; i++)
    {
        printf("%c", recoveredData[i]);
    }

    fclose(filePtr);
    free(fileData);

    printf("\n\nThank you for using our unique C Data recovery tool program. Stay tuned for more surprises!\n");

    return 0;
}