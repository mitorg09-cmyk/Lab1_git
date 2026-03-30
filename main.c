#include <stdio.h>
#include <string.h>
#define size 256
#define max 2147483647
#define min -2147483648
#define arr arr0

int strToDecimal(char* str1, int* outNum);

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

    int number = 0;
    int code = strToDecimal(arr, &number);

    if(!code)
    {
      printf("Number is %d \n", number);
    }
    else if (code == 1)
    {
      printf("Invalid string \n");
    }
    else if (code == 2)
    {
      printf("Overflow \n");
    }
    else
    {
      printf("Invalid pointer \n");
    }
}

int strToDecimal(char* str1, int* outNum)
{
  if(str1 && outNum)
  {
    *outNum = 0;
    int isNegat = 0;

    int strSz = strlen(str1);

    int i = 0;
    if(str1[i] == '-')
    {
      isNegat = 1;
      i = 1;
    }
    else if(str1[i] == '+') i = 1;

    for(; i < strSz && str1[i] != '\0'; i++)
    {
      str1[i] -= '0';

      if(str1[i] < 0 || str1[i] > 9)
      {
        return 1; // 1 - Invalid str
      }

      if(isNegat)
      {
        if(*outNum < min / 10)
        {
          return 2; // Overflow
        }

        *outNum *= 10;

        if(*outNum < min + str1[i])
        {
          return 2; // Overflow
        }

        *outNum -= str1[i];
      }
      else
      {
        if(*outNum > max / 10)
        {
          return 2; // Overflow
        }

        *outNum *= 10;

        if(*outNum > max - str1[i])
        {
          return 2; // Overflow
        }

        *outNum += str1[i];
      }

    }
    return 0;
  }
  return -1; // -1 Invalid ptrs
}
