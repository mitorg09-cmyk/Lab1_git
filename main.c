#include <stdio.h>
#include <string.h>
#define size 256
#define max 2147483647
#define min -2147483648
#define arr arr0

int main()
{
    char arr0[size] = "0"; // 0
    char arr1[size] = "1"; // 1
    char arr2[size] = "-1"; // -1
    char arr3[size] = "-0"; // 0
    char arr4[size] = "+1"; // 1
    char arr5[size] = "2147483647"; // max
    char arr6[size] = "-2147483648"; // min
    char arr7[size] = "2147483648"; // max + 1 >> Overflow
    char arr8[size] = "-2147483649"; // min - 1 >> Overflow
    char arr9[size] = "11qqq"; // Invalid symbol
    char arr10[size] = "-aaa"; // Invalid symbol
    char arr11[size] = "-99999999999999999999999"; // Overflow
    char arr12[size] = "+99999999999999999999999"; // Overflow

    int result = 0;
    int isNegat = 0;

    int strSz = strlen(arr);

    int i = 0;
    if(arr[i] == '-')
    {
      isNegat = 1;
      i = 1;
    }
    else if(arr[i] == '+') i = 1;

    for(; i < strSz && arr[i] != '\0'; i++)
    {
      arr[i] -= '0';

      if(arr[i] < 0 || arr[i] > 9)
      {
        printf("Invalid symbol \n");
        return 0;
      }

      if(isNegat)
      {
        if(result < min / 10)
        {
          printf("Overflow \n");
          return 0;
        }

        result *= 10;

        if(result < min + arr[i])
        {
          printf("Overflow \n");
          return 0;
        }

        result -= arr[i];
      }
      else
      {
        if(result > max / 10)
        {
          printf("Overflow \n");
          return 0;
        }

        result *= 10;

        if(result > max - arr[i])
        {
          printf("Overflow \n");
          return 0;
        }

        result += arr[i];
      }

    }

    printf("Result is: %d \n", result);

    return 0;
}
