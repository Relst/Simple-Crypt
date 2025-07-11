#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    char fileName[16];
    char newFileName[20] = "new-";
    int passwordLen = strlen(argv[2]);
   
   if (argc == 3){
       strcpy(fileName, argv[1]);
       strcat(newFileName, fileName);
       printf("newFileName = %s\npassword length = %d\n", newFileName, passwordLen);

   }
   
   
}