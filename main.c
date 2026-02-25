#include <stdio.h>
#include <string.h>

void GetAlphabetOrder(char str[256], unsigned short Order[128]);

int main()
{
    char str1[256] = "abcd,aaaa,a,bd,hihiab,ab,aabc.";
    unsigned short Ord[128] = {0};
    GetAlphabetOrder(str1, Ord);
}

void GetAlphabetOrder(char str[256], unsigned short Order[128])
{
    char* ptrToWords[128] = {NULL};
    int lenOfWords[128] = {0};

    int wordCounter = 0;
    ptrToWords[0] = str;
    for(int i = 0; str[i] != '.' ||  str[i] != '\0'; i++)
    {
        if(str[i] != ',')
        {
            lenOfWords[wordCounter]++;
        }
        else
        {
            wordCounter++;
            ptrToWords[wordCounter] = str + i + 1;
        }
    }

    printf("%d", (int)*ptrToWords[0]);

//    for(int i = 0; ptrToWords[i] != NULL; i++)
//    {
//        printf("fffdddd", ptrToWords[i]);
//  }
}

