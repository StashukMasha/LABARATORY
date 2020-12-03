#include"mystring.h"

int main()
{
    char str[MAX_STRING_SIZE];
    
    printf("print text:\n");
    gets_s(str);

    printf("you print:\n");
    puts(str);

    removeWhiteSpaces(str);
    
    printf("result:\n");
    puts(str);
    
    return 0;
} 

