#include <stdio.h>

int cmpStrAlphabetOrder(char* str1, char* str2);
int ValidateStrSqueez(char* str1);

int main()
{
  char str0[10] = "abcd,";
  char str1[10] = "aacd,";
  char str2[10] = "aa,";
  char str3[10] = "a";
  char o = 234;
  printf("%c \n", o);

  printf("%d \n", cmpStrAlphabetOrder(str3, str2));
}

int cmpStrAlphabetOrder(char* str1, char* str2)
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

int ValidateStrSqueez(char* str1) // 0 - validation success; 1 - validation failure or invalid str.
{
  if(str1)
  {
    int validationTab[256] = {0}; // 0 - Invalid symbol; 1 - Valid symbol-separator; 2 - Valid symbol.

    for(int i = 65; i <= 90; i++){validationTab[i] = 2;} // A - Z.
    for(int i = 97; i <= 122; i++){validationTab[i] = 2;} // a - z.
    validationTab[0] = 2;

    validationTab[32] = 1; // ' '
    validationTab[44] = 1; // ','
    validationTab[46] = 1; // '.'

    for(int i = 0; str1[i] != '\0'; i++)
    {
      if(validationTab[str1[i]])
      {

      }
      else return 1;
    }
  }
  else
  {
    return 1;
  }
}
