#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

int main() {
    char kelime[MAX_LENGTH] ="ROKET";
    char tahmin[MAX_LENGTH];
    int kelime_uzunlugu;
    char cikti[MAX_LENGTH];


    kelime_uzunlugu = strlen(kelime);
    printf("Oyun basladi! Hedef kelimeyi bulmaya calisin.\n");

    // İlk çıktıyı oluştur
    for (int i = 0; i < kelime_uzunlugu; i++) {
        cikti[i] = '_';
    }
    cikti[kelime_uzunlugu] = '\0';

    while (1) {
        printf("\nTahmininizi girin: ");
        scanf("%s", tahmin);

        if (strcmp(tahmin, kelime) == 0) {
            printf("Tebrikler! Dogru kelimeyi buldunuz: %s\n", kelime);
            break;
        } else {
            printf("Cikti: ");
            for (int i = 0; i < kelime_uzunlugu; i++) {
                if (tahmin[i] == kelime[i]) {
                    printf("%c", tahmin[i]);
                    cikti[i] = tahmin[i]; // Doğru tahmin edilen harfi güncelle
                } else if (strchr(kelime, tahmin[i]) != NULL && strchr(tahmin, kelime[i]) == NULL) {
                    printf("_");
                } else {
                    printf("%c", cikti[i]); // İlk tahminde doğru tahmin edilen harfi kullan
                }
            }

            printf("\nYeri yanlis harfler: ");
            for (int i = 0; i < kelime_uzunlugu; i++) {
                if (tahmin[i] != kelime[i] && strchr(kelime, tahmin[i]) != NULL) {
                    printf("%c ", tahmin[i]);
                }
            }

            printf("\nOlmayan harfler: ");
            for (int i = 0; i < kelime_uzunlugu; i++) {
                if (strchr(kelime, tahmin[i]) == NULL) {
                    printf("%c ", tahmin[i]);
                }
            }

            printf("\n");
        }
    }
    return 0;
}