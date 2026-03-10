#include <stdio.h>
#include <stdbool.h>

int cmpStrAlphabetOrder(char* str1, char* str2, size_t l1, size_t l2);
int ValidateFindStr(char* str1, size_t strLen, int* outMas, size_t outMasLen);

int main()
{
  char str0[128] = "abcd,abcd,gggggg,udgngf,d,    fg  d fasdf, df ,df ,d ,d. f.d ,df...,abcd,a,ab,aaab,aa,aa,a,abcd,abcda";
  int indxLnWrd[256] = {0};

  ValidateFindStr(str0, 128, indxLnWrd, 256);

  for(int i = 0; indxLnWrd[i] != -1; i += 2)
  {
    for(int j = i + 2; indxLnWrd[j] != -1; j += 2)
    {
      if(ValidateFindStr(str0 + indxLnWrd[i], str0 + indxLnWrd[j], indxLnWrd[i + 1], indxLnWrd[j + 1])){}
    }
  }
}

int cmpStrAlphabetOrder(char* str1, char* str2, size_t l1, size_t l2)
{
  if(str1 && str2)
  {
    for(int i = 0; ; i++)
    {
      if(str1[i] == ',' || str1[i] == '.' || str1[i] == '\0') return 1;
      if(str2[i] == ',' || str2[i] == '.' || str1[i] == '\0') return 0;

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
  if(str1 && outMas && outMasLen >= strLen * 2)
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
    for(int i = 0; str1[i + 1] != '\0'; i++)
    {
      if(validationTab[str1[i]])
      {
        if(validationTab[str1[i]] == 1 && validationTab[str1[i + 1]] == 2)
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
  }
  else
  {
    return 1;
  }
}
