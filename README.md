A simple C program that encrypts or decrypts binary files (e.g., images) using XOR and a password.

How to use:
 - Either Compile part4.c, or use the provided Crypt executable. (I.e. ```gcc -o Crypt part4.c```)
 - Run the executable with a password with atleast 8 characters, and 1 digit.  (I.e ```./Crypt 'filePath' 'password'```)
   - This will create a 'new-FileName' file encrypted by the password. ()
 - To decrupt run the same command using the new file, and if the correct password is entered we will have the original image back.

Notes:
 - File need to be at the same level as executable due to assignment requirements.
