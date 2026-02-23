#include <stdio.h>
#include <string.h>
#define size 256
#define max 2147483647
#define min -2147483648

int main()
{
    char arr[size] = "001";
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
