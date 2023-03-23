#include <stdio.h>
/*
int i = 10;
char c = 'a';
double d = 3.21;
///Con tro void//////////////////////
int tong(int a, int b){
    return a+b;
}

void test(char typName, void *pvoid){
    switch (typName)
    {
    case 'i':
        printf("Kieu int: %d\n", *(int *)pvoid);    /////ep con tro void thanh kieu du lieu int
        break;

    case 'c':
        printf("Kieu char: %c\n", *(char *)pvoid);
        break;

    case 'd':
        printf("Kieu double: %f\n", *(double *)pvoid);
        break;

    case 'f':
        printf("Kieu du lieu function: \n");
        printf("tong a va b = %d\n", ((int (*)(int, int))pvoid)(5, 7));   
         //cach ep kieu con tro function thanh con tro ham
        break;
    default:
        printf("kieu du lieu khong xac dinh");
        break;
    }
}


int main(int argc, char const *argv[])
{
   test('i', &i);
   test('c', &c);
   test('d', &d);
   test('f', &tong);    ///////////////CON TRO HAM////CON TRO HAM///////////////////////
}*/

///////////////////////CON TRO MANG////////CON TRO MANG/////////
void tong(int a, int b){
    printf("tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n", a, b, a-b);
}

int main(int argc, char const *argv[])
{
    int intArr[]= {1, 4, 8, 6};
    char charArr[]="Hello world";
    double doublearr[] = {1.25, 5.23, 6.54, 4.2};
    void (*functionArr[])(int, int) = {&tong, &hieu};///khai bao con tro ham

    void *arr[4] = {intArr, charArr, doublearr, functionArr};/////tao mang la con tro void arr[] va gan gia tri vao//
    printf("kieu int: %d \n", ((int *)arr[0])[2]);////arr[0] = intArr[dia chi 0] // [3] vi chi 3 cua intArr
    printf("kieu char: %c\n", ((char *)arr[1])[2]);
    printf("kieu double; %f\n", ((double *)arr[2])[2]);

    void *ptr = &tong;
    //ep kieu ptr ve tong ///6,7 truyen tham so vao
    ((void (*)(int, int))ptr)(6,8);      //con tro ham co gia tri tra ve void dau vao la int "void (*)(int, int)""

    int *pointertest = intArr;
    int **pointertopointervoid = &pointertest;  ///////pointer to pointer no luu dia chi cua con tro
    printf("test pointer: %d\n", pointertest[2]);
    return 0;
}
    
