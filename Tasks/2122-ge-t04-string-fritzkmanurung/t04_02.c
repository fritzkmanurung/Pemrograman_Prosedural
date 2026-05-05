// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{
    char kata[105];
    fgets(kata, 100, stdin);
    kata[strcspn(kata, "\r\n")] = '\0';
    
    int sifting;
    scanf("%d", &sifting);

    sifting %= 255;
    if(sifting < 0) sifting += 255;
    
    int panjangkata = strlen(kata);
    
    for(int i = 0; i < panjangkata; i++) {
        int val = (kata[i] + sifting) % 255;
        printf("%03d", val);
    }
    printf("\n");
    
    for(int i = 0; i < panjangkata; i++) {
        int val = (kata[i] + sifting) % 255;
        printf("%c", val);
    }
    printf("\n");

    return 0;
}
