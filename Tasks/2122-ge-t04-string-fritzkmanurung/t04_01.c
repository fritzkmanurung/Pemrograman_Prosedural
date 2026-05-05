// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{
    char kata[105];
    scanf("%100[^\n]", kata);
    int n;
    scanf("%d", &n);
    
    n %= 255;
    if(n < 0) n += 255;
    
    int leng = strlen(kata);
    if(leng > 0 && kata[leng-1] == '\r') {
        kata[leng-1] = '\0';
        leng--;
    }
    
    for (int i = 0; i < leng; i++) {
        int val = (kata[i] + n) % 255;
        printf("%03d", val);
    }
    printf("\n");

    return 0;
}
