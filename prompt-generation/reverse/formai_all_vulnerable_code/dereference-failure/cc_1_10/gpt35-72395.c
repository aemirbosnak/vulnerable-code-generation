//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include<stdio.h>

// Function to hide the message inside the image
void hideMessage(char* imgFilename, char* msgFilename)
{
	FILE *fp1, *fp2;
	fp1 = fopen(imgFilename, "rb"); // Opening image file in read mode
	if(fp1 == NULL){
		printf("Error: Unable to open file %s\n", imgFilename);
		return;
	}
	fp2 = fopen(msgFilename, "r"); // Opening message file in read mode
	if(fp2 == NULL){
		printf("Error: Unable to open file %s\n", msgFilename);
		return;
	}

	fseek(fp2, 0, SEEK_END); // Getting the size of the message file
	int msgSize = ftell(fp2);
	rewind(fp2);

	// Allocating memory for the message and image buffer
	char* msg = (char*) malloc(msgSize*sizeof(char));
	char* img = (char*) malloc(msgSize*sizeof(char));
	fread(msg, msgSize, 1, fp2); // Reading the message from file into buffer

	// Reading the image from file into buffer
	fread(img, msgSize, 1, fp1);
	fclose(fp1);

	int i, j=0;
	for(i=0; i<msgSize; i++){
		img[i] = (img[i] & 0xFE) | ((msg[j] >> 7) & 0x01);
		img[i+1] = (img[i+1] & 0xFE) | ((msg[j] >> 6) & 0x01);
		img[i+2] = (img[i+2] & 0xFE) | ((msg[j] >> 5) & 0x01);
		img[i+3] = (img[i+3] & 0xFE) | ((msg[j] >> 4) & 0x01);
		img[i+4] = (img[i+4] & 0xFE) | ((msg[j] >> 3) & 0x01);
		img[i+5] = (img[i+5] & 0xFE) | ((msg[j] >> 2) & 0x01);
		img[i+6] = (img[i+6] & 0xFE) | ((msg[j] >> 1) & 0x01);
		img[i+7] = (img[i+7] & 0xFE) | (msg[j] & 0x01);
		j++;
	}
	fclose(fp2);

	// Writing the stegnographed image to new file
	char* stegFilename = "img_steg.bmp";
	fp1 = fopen(stegFilename, "wb");
	
	fwrite(img, msgSize, 1, fp1);
	fclose(fp1);
	free(img);
	free(msg);
	printf("Steganography successful. Image saved as '%s'\n", stegFilename);
}

// Function to extract the hidden message from the stegnographed image
void extractMessage(char* stegFilename)
{
	FILE *fp1;
	fp1 = fopen(stegFilename, "rb"); // Opening stegnographed image in read mode
	if(fp1 == NULL){
		printf("Error: Unable to open file %s\n", stegFilename);
		return;
	}
	
	fseek(fp1, 0, SEEK_END); // Getting the size of the stegnographed image
	int imgSize = ftell(fp1);
	rewind(fp1);

	// Allocating memory for the image buffer and message buffer
	char* img = (char*) malloc(imgSize*sizeof(char));
	char* msg = (char*) malloc((imgSize/8)*sizeof(char));

	// Reading the stegnographed image into buffer
	fread(img, imgSize, 1, fp1);
	fclose(fp1);

	int i, j=0;
	for(i=0; i<imgSize; i+=8){
		msg[j] = ((img[i] & 0x01) << 7) |
			 ((img[i+1] & 0x01) << 6) |
			 ((img[i+2] & 0x01) << 5) |
			 ((img[i+3] & 0x01) << 4) |
			 ((img[i+4] & 0x01) << 3) |
			 ((img[i+5] & 0x01) << 2) |
			 ((img[i+6] & 0x01) << 1) |
			 (img[i+7] & 0x01);
		j++;
	}

	// Writing the extracted message to new file
	char* extFilename = "msg_extracted.txt";
	FILE *fp2 = fopen(extFilename, "w");
	
	fwrite(msg, imgSize/8, 1, fp2);
	fclose(fp2);
	free(img);
	free(msg);
	printf("Extraction successful. Message saved as '%s'\n", extFilename);
}

// Driver function
int main()
{
	char* imgFilename = "img_orig.bmp"; // Original image file
	char* msgFilename = "msg.txt"; // Message file

	hideMessage(imgFilename, msgFilename); // Calling hideMessage function to hide the message inside the image

	char* stegFilename = "img_steg.bmp"; // Stegnographed image file
	extractMessage(stegFilename); // Calling extractMessage function to extract the message from the stegnographed image

	return 0;
}