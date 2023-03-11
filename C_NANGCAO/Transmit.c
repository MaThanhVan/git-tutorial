#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union 
{
    struct{
        char uid[5];
        char data[9];
    }frame;                     //member 1
    char data_frame[12];      
}frame_nfc;                       //member 2

frame_nfc nfc;
char* Transmit(char* ID, char* DATA)
{
    
    strcpy(nfc.frame.uid, ID);         // Truyền data vào uid
    strcpy(nfc.frame.data, DATA);       // Truyền data vào data 
    
    return strcat(nfc.frame.uid, nfc.frame.data); 
}

int main(int ardc, char const *argv[])
{
    printf("%s",  Transmit((char*)"1001", (char*)"10100110" ));
    return 0;
}