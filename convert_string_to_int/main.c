#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint32_t strToInt(char* string)
{
    uint32_t val = 0;
    uint8_t i=0;
    while (string[i] != '\0') //1234
    {
        if((string[i]<48) || (string[i]>57))
        {
            printf("Chuoi khong hop le! Status code: ");
            return -1;
        }
        ++i;
    }
    for(int j=1; j<=i; j++)
    {
        int temp;
        temp = string[j-1] - 48;
        val += temp * pow(10,i-j);
    }
    return val;
}

int main()
{
    char str[] = "1233456789"; // <- intput string here
    uint32_t int_num = strToInt(str);
    printf("%d", int_num);

    return 0;
}
