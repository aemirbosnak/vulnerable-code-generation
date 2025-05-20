//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512 // block size for FAT32 file system
#define FILE_NAME_SIZE 11 // file name size for FAT32 file system

// function to retrieve the first cluster number of the file from the FAT table
unsigned int getFirstCluster(FILE *fp, unsigned char *dirEntry) {
    unsigned int clusterNum = 0;
    unsigned char *entryPtr = dirEntry + 26; // pointer to the byte where the cluster number starts

    clusterNum |= (*entryPtr++); // first byte
    clusterNum |= (*entryPtr++ << 8); // second byte
    clusterNum |= (*entryPtr++ << 16); // third byte
    clusterNum |= (*entryPtr++ << 24); // fourth byte

    return clusterNum;
}

// function to read a block of data from the file
void readBlock(FILE *fp, unsigned char *buffer, unsigned int blockNum, unsigned int bytesPerSector, unsigned int sectorsPerCluster, unsigned int reservedSectors, unsigned int fatSize, unsigned int rootDirSectors) {
    unsigned int firstDataSector = reservedSectors + (fatSize * 2) + rootDirSectors;
    unsigned int firstSectorOfCluster = ((blockNum - 2) * sectorsPerCluster) + firstDataSector;
    unsigned int offsetInBytes = firstSectorOfCluster * bytesPerSector;

    fseek(fp, offsetInBytes, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, fp);
}

// function to retrieve the next cluster number of the file from the FAT table
unsigned int getNextCluster(FILE *fp, unsigned int clusterNum, unsigned int bytesPerSector, unsigned int sectorsPerCluster, unsigned int reservedSectors, unsigned int fatSize) {
    unsigned int fatOffset = reservedSectors * bytesPerSector;
    unsigned int thisFatSector = (clusterNum * 4) / bytesPerSector;
    unsigned int thisFatOffset = (clusterNum * 4) % bytesPerSector;
    unsigned int fatEntryOffset = fatOffset + (thisFatSector * bytesPerSector) + thisFatOffset;
    unsigned int fatValue = 0;

    fseek(fp, fatEntryOffset, SEEK_SET);
    fread(&fatValue, sizeof(unsigned int), 1, fp);

    return fatValue & 0x0FFFFFFF;
}

// function to recover the file data, given the path of the file and the name of the output file
void recoverFile(char *filePath, char *outputFileName) {
    FILE *fp = fopen(filePath, "rb");

    if(fp == NULL) {
        printf("Unable to open file: %s\n", filePath);
        return;
    }

    unsigned char buffer[BLOCK_SIZE];
    unsigned int bytesPerSector, sectorsPerCluster, reservedSectors, fatSize, rootDirSectors, firstClusterNum, nextClusterNum;
    unsigned char *dirEntryBuffer = malloc(sizeof(unsigned char) * 32);
    memset(dirEntryBuffer, 0, 32);

    // read the header information from the file
    fseek(fp, 11, SEEK_SET);
    fread(&bytesPerSector, 2, 1, fp);
    fseek(fp, 13, SEEK_SET);
    fread(&sectorsPerCluster, 1, 1, fp);
    fseek(fp, 14, SEEK_SET);
    fread(&reservedSectors, 2, 1, fp);
    fseek(fp, 16, SEEK_SET);
    fread(&fatSize, 2, 1, fp);
    fseek(fp, 19, SEEK_SET);
    fread(&rootDirSectors, 2, 1, fp);

    // find the first cluster number of the file
    fseek(fp, reservedSectors * bytesPerSector, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, fp);

    unsigned int rootDirOffset = 0;
    unsigned int clusterNum = 0;
    unsigned int bytesRead = 0;

    while(1) {
        if(rootDirOffset > (rootDirSectors * bytesPerSector)) {
            printf("File not found.\n");
            return;
        }

        memcpy(dirEntryBuffer, buffer + rootDirOffset, 32);

        if(dirEntryBuffer[0] == 0x00) { // end of directory entries
            printf("File not found.\n");
            return;
        }

        if(dirEntryBuffer[0] != 0xE5) { // not deleted file
            char fileName[FILE_NAME_SIZE + 1];
            memset(fileName, 0, FILE_NAME_SIZE + 1);

            for(int i = 0; i < FILE_NAME_SIZE; i++) {
                if(dirEntryBuffer[i] == 0x20) { // space character
                    continue;
                } else if(dirEntryBuffer[i] == 0x00) { // end of file name
                    break;
                } else {
                    fileName[i] = dirEntryBuffer[i];
                }
            }

            if(strcmp(fileName, outputFileName) == 0) { // file name matches
                printf("Found file: %s\n", outputFileName);

                firstClusterNum = getFirstCluster(fp, dirEntryBuffer);
                printf("First cluster number of the file: %u\n", firstClusterNum);

                FILE *outputFile = fopen(outputFileName, "wb");
                if(outputFile == NULL) {
                    printf("Unable to create output file.\n");
                    return;
                }

                unsigned int clusterSizeInBytes = bytesPerSector * sectorsPerCluster;
                unsigned int bytesLeft = dirEntryBuffer[28] + (dirEntryBuffer[29] << 8) + (dirEntryBuffer[30] << 16) + (dirEntryBuffer[31] << 24);

                while(1) {
                    readBlock(fp, buffer, clusterNum, bytesPerSector, sectorsPerCluster, reservedSectors, fatSize, rootDirSectors);
                    fwrite(buffer, BLOCK_SIZE, 1, outputFile);
                    bytesRead += BLOCK_SIZE;
                    bytesLeft -= BLOCK_SIZE;

                    if(bytesLeft <= 0) {
                        break;
                    }

                    if(bytesRead % clusterSizeInBytes == 0) { // read the next cluster number from FAT table
                        nextClusterNum = getNextCluster(fp, clusterNum, bytesPerSector, sectorsPerCluster, reservedSectors, fatSize);

                        if(nextClusterNum >= 0x0FFFFFF8) { // end of file
                            break;
                        } else {
                            clusterNum = nextClusterNum;
                        }
                    }
                }

                printf("File recovered successfully.\n");
                fclose(outputFile);
                return;
            }
        }

        rootDirOffset += 32;
    }

    free(dirEntryBuffer);
    fclose(fp);
}

int main() {
    char filePath[] = "disk.img";
    char outputFileName[] = "file.txt";

    recoverFile(filePath, outputFileName);

    return 0;
}