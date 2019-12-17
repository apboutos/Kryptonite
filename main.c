#include <stdio.h>
#include <stdlib.h>

void kryptonite();
void menu();


int main(int args, char *argv[])
{

    FILE *fp = NULL;
    long fSize;
    int i,choice;
    char *buffer;
    char c;

    kryptonite();
    fp = fopen(argv[1],"rb+");
    if (fp == NULL)
    {
            printf("Error: Could not open uncrypted file\n");
            system("PAUSE");
            return -1;
    }

    printf("File loaded: %s\n\n",argv[1]);

    printf("1. Encrypt/Decrypt\n");
    printf("2. Help\n");
    printf("3. Quit\n");
    printf("\nEnter a choice: ");
    scanf("%d",&choice);

    while (choice < 1 || choice > 3)
    {
        printf("\nInvalid choice, must be 1, 2, or 3\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
    }

    if (choice == 3)
    {
        return 0;
    }
    if (choice == 2)
    {
        printf("Kryptonite is an encryption software.It's purpose is encrypting small files, most commonly containing\n");
        printf("a list of keys or passwords or other information that you wish to keep confidential. When encrypting a\n");
        printf("file you must choose a password which will be your encryption key. You will have to use the same key if\n");
        printf("you want to decrypt your file in the future\n");
        printf("\nWARNING: Kryptonite will not store any encryption keys. This is a feature to make the program more secure\n");
        printf("against reverse engineering attacks. This means that you must be able to remember your encryption key in order\n");
        printf("to be able to decrypt any of your files. For better security it is not recommended to use the same key more than once.");
        printf("\nIn order to encrypt or decrypt a file, drag and drop in inside the Kryptonite.exe, or if you start Kryptonite from\n");
        printf("the command line pass it as the first argument. You can pass the encryption key as the second argument from the\n");
        printf("command line. If you do not do so, you will be prompted to the menu.\n");
        printf("\n Press any key to continue ");
        scanf("%d");
    }



    fseek(fp,0,SEEK_END);
    fSize = ftell(fp);
    fseek(fp,0,SEEK_SET);

    buffer = (char *)malloc(fSize);

    for (i = 0; i<fSize ; i++)
    {
        c = fgetc(fp);
        buffer[i] = c;
        buffer[i] = buffer[i]^'h';
    }

    fseek(fp,0,SEEK_SET);
    for (i = 0; i<fSize ; i++)
    {
        fputc(buffer[i],fp);
    }


    fclose(fp);
    free(buffer);
    return 0;
}

void kryptonite(){

    printf("      __          __  _____   ____   _        _____  _____\n");
    printf("|  / |  \\  \\   / |  \\   |    /    \\ | \\   | |   |   |     \n");
    printf("| /  |  /   \\ /  |__/   |    |    | |  \\  | |   |   |__   \n");
    printf("| \\  | \\     |   |      |    |    | |   \\ | |   |   |     \n");
    printf("|  \\ |  \\    |   |      |    \\____/ |    \\| |   |   |_____\n\n\n\n");
}

void menu(){



    printf("File ");




}
