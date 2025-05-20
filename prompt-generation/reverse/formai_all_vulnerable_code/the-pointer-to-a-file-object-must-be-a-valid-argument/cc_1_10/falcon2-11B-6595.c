//Falcon2-11B DATASET v1.0 Category: File handling ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<dirent.h>
#include<unistd.h>

// Function to count number of words in the file
int countWords(char* fileName)
{
	int wordCount = 0;
	int fileHandle;
	char line[1000];

	// Open file
	fileHandle = open(fileName, O_RDONLY);
	if(fileHandle == -1)
	{
		printf("Error: Unable to open file.\n");
		return 0;
	}

	// Read lines
	while(!feof(fileHandle))
	{
		// Read a line
		fgets(line, sizeof(line), fileHandle);

		// Split the line into words
		char* word = strtok(line, " \t\n");
		while(word!= NULL)
		{
			wordCount++;
			word = strtok(NULL, " \t\n");
		}
	}

	// Close file
	close(fileHandle);

	// Return word count
	return wordCount;
}

int main()
{
	char* fileName = "example.txt";
	int wordCount = countWords(fileName);
	printf("Number of words in the file: %d\n", wordCount);

	return 0;
}