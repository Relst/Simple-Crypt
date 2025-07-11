#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool checkDigits(char* str){
    for (int i = 0; i < strlen(str); i++){
        if (isdigit((unsigned char)str[i])){
            return true;
        }
    }
    return false;
}

void fileCreation(char filename[], char newFileName[], int passwordLen, char password[]){
    FILE *file;
    file = fopen(filename, "r");
    FILE * newFilePtr;
    newFilePtr = fopen(newFileName, "w");
    int blockSize = passwordLen;
    char blocks[blockSize];
    int numBytes = passwordLen;
    int counter = 1;
    do {
        numBytes = fread(blocks, 1, blockSize, file);
        for (int i = 0; i<numBytes; i++){
            blocks[i] = blocks[i]^password[i];
        }
        fwrite(blocks, 1,  numBytes, newFilePtr);
    }while(numBytes == blockSize);

    fclose(file), fclose(newFilePtr);
}



int main(int argc, char *argv[]) {
    char fileName[16];
    char newFileName[20] = "new-";
    int passwordLen = strlen(argv[2]);
    bool validLen, validDigit;

    if (argc == 3){
        strcpy(fileName, argv[1]);
        strcat(newFileName, fileName);
        validLen = (passwordLen >= 8);
        validDigit = checkDigits(argv[2]);
        if (!validLen){
            printf("The password needs to have at least 8 characters.\n");
        }
        if (!validDigit){
         printf("The password needs to contain at least one digit.\n");
        }


        fileCreation(fileName,newFileName, passwordLen, argv[2]);
        
    }

    return 0;
}

