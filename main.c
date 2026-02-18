#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 4
#define separSize 7

int main()
{
    char arr[size] = "abcd Abcd abcd, ughabcd - hababcd: abcd-abcd-h";
    char buff[wLen] = "abcd";
    char separators[separSize] = {' ', ',', ':', '-', '(', ')', '.'};
    int begEnd[size] = {0};

    int arrlen = strlen(arr);
    int j = 0;
    for(int i = 0; i < arrlen && arr[i] != '\0'; i++)
    {
        int k = 0;
        for(; k < separSize && arr[i] != separators[k]; k++)
        {
        }
        if(k == separSize)
        {
            j++;
        }
        else
        {
            j = 0;
        }
        if(j == wLen)
        {

        }
    }

    return 0;
}
