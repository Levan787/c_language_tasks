#include <stdio.h>
#include <stdlib.h>
int strlen(char* a);
char* strcpy(char* destination, const char* source);
char* strcat(char* destination, const char* source);

int main()
{
    char firstName[30], lastName[30], redID[10];
    printf("Enter name: ");
    gets(firstName);
    printf("Enter last name: ");
    gets(lastName);
    printf("Enter RedID: ");
    gets(redID);
    printf("\nLength of name = %d, length of last name = %d, length of RedId = %d\n", strlen(firstName), strlen(lastName), strlen(redID));

    char copiedString[30];
    strcpy(copiedString, firstName);
    printf("\nString 1 = ");
    puts(copiedString);
    printf("String 2 = ");
    puts(firstName);

    printf("\n");
    
    char finalString[80]="Hello ";
    strcat(finalString,firstName);
    strcat(finalString, " ");
    strcat(finalString,lastName);
    strcat(finalString, " ");
    strcat(finalString,redID);
    strcat(finalString, " ");
    puts(finalString);

    return 0;
}

int strlen(char* a){
    char* ptr=a;
    while(*ptr!='\0')
        ptr++;
    return (ptr-a);
}

char* strcpy(char* destination, const char* source){
    int i=0;
    while (source[i]!='\0'){
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0';
    return destination;
}

char* strcat(char* destination, const char* source){
    int i, j;
    int destLen=strlen(destination);
    for(i=0; source[i]!='\0'; i++)
        destination[destLen+i]=source[i];
    destination[destLen+i]='\0';
    return destination;
}

