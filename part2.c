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
        printf("newFileName = %s\npassword length = %d\n", newFileName, passwordLen);
        if (!validLen){
            printf("The password needs to have at least 8 characters.\n");
        }
        if (!validDigit){
         printf("The password needs to contain at least one digit.\n");
        }
    }

    return 0;
}
