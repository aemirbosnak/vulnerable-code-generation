//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_START "*****WATERMARK_START*****"
#define WATERMARK_END "*****WATERMARK_END*****"

void addWatermarkToFile(char* fileName, char* watermark) {
    char tempName[100] = "temp.txt";
    char buffer[1000];
    FILE *originalFile, *tempFile;
    int found = 0;
    
    originalFile = fopen(fileName, "r");
    if (originalFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    tempFile = fopen(tempName, "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    while (fgets(buffer, 1000, originalFile) != NULL) {
        if (strstr(buffer, WATERMARK_START) != NULL) {
            found = 1;
            break;
        }
        fputs(buffer, tempFile);
    }

    if (!found) {
        fputs(WATERMARK_START, tempFile);
        fputs(watermark, tempFile);
        fputs("\n", tempFile);
        fputs(WATERMARK_END, tempFile);
        fputs("\n", tempFile);
    }

    rewind(originalFile);
    
    while (fgets(buffer, 1000, originalFile) != NULL) {
        fputs(buffer, tempFile);
    }

    fclose(originalFile);
    fclose(tempFile);

    remove(fileName);
    rename(tempName, fileName);
}

int watermarkExistsInFile(char* fileName) {
    char buffer[1000];
    FILE *file;
    int found = 0;
    
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while (fgets(buffer, 1000, file) != NULL) {
        if (strstr(buffer, WATERMARK_START) != NULL && strstr(buffer, WATERMARK_END) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(file);

    return found;
}

char* extractWatermarkFromFile(char* fileName) {
    char buffer[1000];
    FILE *file;
    char* watermark;
    int bufferLength = 0, watermarkLength = 0, startFound = 0, endFound = 0, i, j;

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    while (fgets(buffer, 1000, file) != NULL) {
        if (strstr(buffer, WATERMARK_START) != NULL) {
            startFound = 1;
            continue;
        }
        if (startFound) {
            bufferLength = strlen(buffer);
            for (i = 0; i < bufferLength; i++) {
                if (buffer[i] == '\n') {
                    endFound = 1;
                    break;
                }
                watermarkLength++;
            }
        }
        if (endFound) {
            break;
        }
    }

    if (watermarkLength == 0) {
        printf("Error: Watermark not found in file.\n");
        return NULL;
    }

    watermark = (char*)malloc((watermarkLength + 1) * sizeof(char));
    if (watermark == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    rewind(file);
    startFound = 0;

    while (fgets(buffer, 1000, file) != NULL) {
        if (strstr(buffer, WATERMARK_START) != NULL) {
            startFound = 1;
            continue;
        }
        if (startFound) {
            bufferLength = strlen(buffer);
            for (i = 0, j = 0; i < bufferLength; i++) {
                if (buffer[i] == '\n') {
                    break;
                }
                watermark[j] = buffer[i];
                j++;
            }
        }
        if (endFound) {
            break;
        }
    }

    watermark[watermarkLength] = '\0';

    fclose(file);

    return watermark;
}

int main() {
    char fileName[100], watermark[100], *extractedWatermark;
    int choice;

    printf("Enter file name: ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    if (!watermarkExistsInFile(fileName)) {
        printf("No watermark found in file.\n");
        printf("Do you want to add a watermark? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        getchar();
        if (choice) {
            printf("Enter watermark: ");
            fgets(watermark, 100, stdin);
            watermark[strcspn(watermark, "\n")] = 0;
            addWatermarkToFile(fileName, watermark);
            printf("Watermark added successfully.\n");
        } else {
            printf("Exiting program.\n");
        }
    } else {
        printf("Watermark found in file.\n");
        printf("Do you want to extract the watermark? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        getchar();
        if (choice) {
            extractedWatermark = extractWatermarkFromFile(fileName);
            if (extractedWatermark != NULL) {
                printf("Extracted watermark: %s\n", extractedWatermark);
                free(extractedWatermark);
            }
        } else {
            printf("Exiting program.\n");
        }
    }

    return 0;
}