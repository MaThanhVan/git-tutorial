#include <stdio.h>
#include <stdint.h>
#include <string.h>


void converStringtoDec(char* arr)
{
    int hex[1000];
    for(int i=0; i < strlen(arr); i++)
    {
        hex[i] = (int)arr[i];               // ép kiểu để thành mã thập phân
    }

    int temp[7];                            //biến tạm để phân biệt mỗi kỹ tự ASCII đổi sang nhị phân chỉ có 8bit
    for(int j = 0; j < strlen(arr); j++)
     {
        for(int i = 7; i >= 0; i--)         //  chuyển sang dạng nhị phân 8bit, đổi ngược thứ thự của chúng
        {  
            temp[i] = hex[j] % 2;               
            hex[j] = hex[j] / 2;  
        }
                                           
        printf("%c: = ",arr[j]); 
        for(int b = 0 ; b <= 7; b++)        // In các kí tự 
        {  
            printf("%d", temp[b]);          
            if(b == 7) printf("\n");        // nếu đến bit số 7 sẽ xuống dòng để không dính vào nhau
        } 
    }
}


int main(int argc, char const *argv[])
{

    char arr[] = "Hello world";
    converStringtoDec(arr);

}