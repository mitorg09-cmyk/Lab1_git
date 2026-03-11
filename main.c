#include <stdio.h>
#include <stdbool.h>

int cmpStrAlphabetOrder(char* str1, char* str2, size_t l1, size_t l2);
int ValidateFindStr(char* str1, size_t strLen, int* outMas, size_t outMasLen);

int main()
{
  char str0[128] = "abcd,abcd,gggggg,udgngf,d,    fg  d fasdf, df ,df ,d ,d. f.d ,df...,abcd,a,ab,aaab,aa,aa,a,abcd,abcda";
  int indxLnWrd[256] = {0};

  int code = 0;
  code = ValidateFindStr(str0, 128, indxLnWrd, 256);

  if(!code)
  {
    // for(int i = 0; i < 256; i++)
    // {
    //   printf("%d \n", indxLnWrd[i]);
    // }

    for(int i = 0; indxLnWrd[i] != -1; i += 2)
    {
      char* tempFirst = str0 + indxLnWrd[i];
      size_t lenTempFirst = indxLnWrd[i + 1];
      for(int j = i + 2; indxLnWrd[j] != -1; j += 2)
      {
        int code1 = cmpStrAlphabetOrder(str0 + indxLnWrd[j], tempFirst, indxLnWrd[j + 1], lenTempFirst);
        if(code1 == 1)
        {
          tempFirst = str0 + indxLnWrd[j];
          lenTempFirst = indxLnWrd[j + 1];
          indxLnWrd[j] = indxLnWrd[i];
          indxLnWrd[j + 1] = indxLnWrd[i + 1];
          indxLnWrd[i] = tempFirst - str0;
          indxLnWrd[i + 1] = lenTempFirst;
        }
        else if(code == 2)
        {
          printf("Invalid pointer or str");
        }
      }
      for(int k = 0; k < (int)lenTempFirst; k++) printf("%c", tempFirst[k]);
      printf("\n");
    }
  }
  else if(code == 1) printf("Invalid str \n");
  else if(code == 2) printf("Out mass if too small \n");
}

int cmpStrAlphabetOrder(char* str1, char* str2, size_t l1, size_t l2)
{
  if(str1 && str2)
  {
    for(int i = 0; ; i++)
    {
      if(i == (int)l1 || str1[i] == '\0') return 1;
      if(i == (int)l2 || str2[i] == '\0') return 0;

      if(str1[i] < str2[i])
      {
        return 1;
      }

      if(str1[i] > str2[i])
      {
        return 0;
      }
    }
  }
  else return 2;
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
