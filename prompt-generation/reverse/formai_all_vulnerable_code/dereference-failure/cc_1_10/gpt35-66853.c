//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
char buffer[1024];
int bufferSize = 0;

//Function to parse the XML file
void parseXML(char* xml) {
    char* tag, *start, *end, *text; //variables for holding different parts of a xml tag
    start = xml; //Initially, pointing to start of the XML
    
    while (*start != '\0') { //End the loop when we reach the end of the XML string
        if (*start == '<') { 
            end = strchr(start, '>'); //Find the end of the tag
            
            if (*(end - 1) == '/') { //Check if the tag is self-closing, i.e, ends with '/'
                tag = (char*)malloc(sizeof(char) * (end - start));
                strncpy(tag, start + 1, end - start - 2); //Copy the tag name to the "tag" variable
                
                printf("<%s />\n", tag); //Print the self-closing tag
                
                free(tag); //Free the "tag" variable to avoid memory leaks
                
                start = end + 1; //Update the start pointer to after the self-closing tag
            }
            else { //If the tag is not self-closing
                tag = (char*)malloc(sizeof(char) * (end - start));
                strncpy(tag, start + 1, end - start - 1); //Copy the tag name to the "tag" variable
                
                text = (char*)malloc(sizeof(char) * (start - xml - bufferSize)); //Allocate memory for the "text" variable
                strncpy(text, xml + bufferSize, start - xml - bufferSize); //Copy the text between the previous tag and the current tag to the "text" variable
                
                printf("%s", text); //Print the text
                
                free(text); //Free the "text" variable to avoid memory leaks
                
                printf("<%s>\n", tag); //Print the opening tag
                
                bufferSize = 0; //Reset the buffer size to zero
                
                start = end + 1; //Update the start pointer to after the opening tag
            }
        }
        else if (*start == '/') { //If the current character is '/'
            end = strchr(start, '>'); //Find the end of the closing tag
            
            tag = (char*)malloc(sizeof(char) * (end - start));
            strncpy(tag, start + 2, end - start - 2); //Copy the tag name to the "tag" variable
            
            text = (char*)malloc(sizeof(char) * (start - xml - bufferSize)); //Allocate memory for the "text" variable
            strncpy(text, xml + bufferSize, start - xml - bufferSize); //Copy the text between the previous tag and the closing tag to the "text" variable
            
            printf("%s", text); //Print the text
            
            free(text); //Free the "text" variable to avoid memory leaks
            
            printf("</%s>\n", tag); //Print the closing tag
            
            bufferSize = 0; //Reset the buffer size to zero
            
            start = end + 1; //Update the start pointer to after the closing tag
        }
        else { //If the current character is not a tag or '/'
            bufferSize++; //Increase the buffer size
            start++; //Move the start pointer to the next character
        }
    }
}

int main() {
    char xml[] = "<bookstore>\n\
  <book>\n\
    <title>The Great Gatsby</title>\n\
    <author>F. Scott Fitzgerald</author>\n\
    <price>15.00</price>\n\
  </book>\n\
\
  <book>\n\
    <title>To Kill a Mockingbird</title>\n\
    <author>Harper Lee</author>\n\
    <price>12.50</price>\n\
  </book>\n\
\
  <book>\n\
    <title>1984</title>\n\
    <author>George Orwell</author>\n\
    <price>10.00</price>\n\
  </book>\n\
</bookstore>\n"; //XML string to be parsed
    
    parseXML(xml); //Call the parseXML function to parse the XML string
    
    return 0; //Exit the program
}