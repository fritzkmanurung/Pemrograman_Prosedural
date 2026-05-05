// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
int jumlah ; 
  float hargasatubuku,hargasemuabuku,diskon,totalharga;
  char * dash;
scanf("%d", &jumlah);
scanf("%f", &hargasatubuku);
  hargasemuabuku=jumlah*hargasatubuku;

  if (hargasemuabuku > 500000) {
    diskon = hargasemuabuku * 15 / 100;
    totalharga = hargasemuabuku - diskon;
    printf("%.2f\n%.2f\n", diskon, totalharga);
  } else if (hargasemuabuku >= 100000) {
    diskon = hargasemuabuku * 10 / 100;
    totalharga = hargasemuabuku - diskon;
    printf("%.2f\n%.2f\n", diskon, totalharga);
  } else if (hargasemuabuku > 50000) {
    diskon = hargasemuabuku * 5 / 100;
    totalharga = hargasemuabuku - diskon;
    printf("%.2f\n%.2f\n", diskon, totalharga);
  } else {
    printf("---\n%.2f\n", hargasemuabuku);
  }
  
  return 0;

}
