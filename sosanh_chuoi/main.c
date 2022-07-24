#include <stdio.h>
#include <stdint.h>

uint8_t StringEqual(char* string1, char* string2)
{
    int i =0;
    while ((i+1)&&((string1[i] != '\0') || (string2[i] != '\0')))
    {
        if(string1[i] != string2[i])
        {
            return 0;
        }
        ++i;
    }
    return 1;
}

int main()
{
    char str1[] = "1234!"; // <- input new string here
    char str2[] = "1234"; // <- input new string here
    int isEqual = StringEqual(str1, str2);
    printf("Status code: %d\n", isEqual); // 1 is equal, 0 is not equal
    return 0;
}
