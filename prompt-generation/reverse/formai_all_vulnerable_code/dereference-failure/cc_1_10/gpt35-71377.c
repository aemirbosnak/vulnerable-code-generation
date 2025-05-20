//FormAI DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10000

char* beautifyHTML(char* html) {
	char* res = malloc(sizeof(char) * MAX_LEN);
	res[0] = '\0'; // initialize
	int ind = 0, i = 0, len = strlen(html);

	while(i < len) {

		// extract current tag:
		char current[MAX_LEN] = {'\0'};
		if(html[i] == '<') {
			int j = i;
			while(html[j] != '>' && j < len) {
				current[j-i] = html[j];
				j++;
			}
			current[j-i+1] = '>';
			i = j+1;
		}

		// beautify current tag:
		char temp[MAX_LEN] = {'\0'};
		if(strcmp(current, "") != 0) { // if tag is not empty
			// add opening tag:
			strcat(temp, "\n");
			for(int k=0; k<ind; k++) {
				strcat(temp, "\t");
			}
			strcat(temp, current);

			// check if tag is self-closing:
			if(current[strlen(current)-2] == '/') {
				strcat(temp, "\n");
			} else { // tag is not self-closing
				strcat(temp, "\n");
				ind++;

				// read until closing tag:
				char inside[MAX_LEN] = {'\0'};
				while(i < len) {
					if(html[i] == '<') {
						int j = i;
						while(html[j] != '>' && j < len) {
							inside[j-i] = html[j];
							j++;
						}
						inside[j-i+1] = '>';
						i = j+1;
						break;
					} else {
						inside[strlen(inside)] = html[i];
						i++;
					}
				}
				strcat(temp, beautifyHTML(inside));
				for(int k=0; k<ind; k++) {
					strcat(temp, "\t");
				}
				char closing[MAX_LEN] = {'\0'};
				strcat(closing, "</");
				strcat(closing, current+1); // avoid '<' character
				strcat(closing, ">\n");
				strcat(temp, closing);
				ind--;
			}
			strcat(res, temp);
		} else { // current tag is empty
			while(html[i] != '<' && i < len) {
				res[strlen(res)] = html[i];
				i++;
			}
		}
	}
	return res;
}

int main() {
	char html[MAX_LEN] = {"<!DOCTYPE html><html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>Here is some content.</p><ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul></body></html>"};
	printf("%s", beautifyHTML(html));
	return 0;
}