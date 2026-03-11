#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 4
#define separSize 7
#define arr arr0

int ValidateFindStr(char* str1, size_t strLen, int* outMas, size_t outMasLen);

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

int ValidateFindStr(char* str1, size_t strLen, int* outMas, size_t outMasLen) // 0 - validation success and found words; 1 - validation failure or invalid str.
{
  if(outMasLen < strLen * 2) return 2; // 2 - outMas is too small.
  if(str1 && outMas)
  {
    int validationTab[256] = {0}; // 0 - Invalid symbol; 1 - Valid symbol-separator; 2 - Valid symbol.

    for(int i = 65; i <= 90; i++){validationTab[i] = 2;} // A - Z.
    for(int i = 97; i <= 122; i++){validationTab[i] = 2;} // a - z.
    validationTab[0] = 2;

    validationTab[32] = 1; // ' '
    validationTab[44] = 1; // ','
    validationTab[46] = 1; // '.'

    int wordCounter = 0;
    if(validationTab[str1[0]] == 2)
    {
      outMas[wordCounter] = 0;
      wordCounter += 2;
      //for(int i = 0; validationTab[str1[i]] == 2; i++) outMas[wordCounter]++;
    }

    for(int i = 0; i < outMasLen; i++){outMas[i] = 0;}

    size_t len = 0;
    for(int i = 0; str1[i] != '\0'; i++)
    {
      if(validationTab[str1[i]])
      {
        if(str1[i + 1] != '\0' && validationTab[str1[i]] == 1 && validationTab[str1[i + 1]] == 2)
        {
          outMas[wordCounter] = i + 1;
          wordCounter += 2;
        }
        if(validationTab[str1[i]] == 2)
        {
          outMas[wordCounter - 1]++;
        }
      }
      else return 1;
    }
    outMas[wordCounter] = -1;
    outMas[wordCounter + 1] = -1;
    return 0;
  }
  else
  {
    return 1;
  }
}
