#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 4
#define separSize 7

int main()
{
    char arr[size] = "abcd abcd abcd, ughabcd - hababcd: abcd-abcd-h abcd";

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
