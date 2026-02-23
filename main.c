#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 4
#define separSize 7
#define arr arr0

int main()
{
    // For wLen == 4
    char arr0[size] = "abcd abcd abcd, ughabcd - hababcd: abcd-abcd-h acbd abcd"; //6
    char arr1[size] = "abcd, ..abcd.. (abcd), ughabcd:- - hababcd: ()abcd-abcd-h acbd abcd"; //6
    char arr2[size] = "abcdabcd-abcd"; //1
    char arr3[size] = "abcd abcd abcd abcd"; //4
    char arr4[size] = "abcd acbd acdb abdc adcb acbd adbc acdb"; //1
    char arr5[size] = "abcd123 abcd abcd, ughabcd - hababcd: abcd-abcd-h acbd 123abcd"; //4
    // For wLen == 1
    char arr6[size] = "a a   a a a  a a  a a aa  a a a"; //12

    char buff[wLen] = "abcd";
    char separators[separSize] = {' ', ',', ':', '-', '(', ')', '.'};
    //int begEnd[size] = {0};
    int count = 0;

    int arrlen = strlen(arr);
    int j = 0;
    for(int i = 0; i < arrlen || arr[i] == '\0'; i++)
    {
        int k = 0;
        for(; k < separSize && arr[i] != separators[k] && arr[i] != '\0'; k++)
        {
        }
        if(k == separSize)
        {
            j++;
        }
        else
        {
          if(j == wLen)
          {
            int cntr = i - wLen;
            int m = 0;
            for(; m < wLen && arr[cntr] == buff[m]; m++, cntr++)
            {
            }
            if(m == wLen)
            {
              count++;
            }
          }
          j = 0;
        }
    }

    printf("count of words is: %d \n", count);

    return 0;
}
