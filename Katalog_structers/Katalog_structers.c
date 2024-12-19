#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX_KITAP 100


typedef struct {
    char isim[100];
    char yazar[100];
    int ISBN;
    int mevcut;
} Kitap;


Kitap kutuphane[MAX_KITAP];
int kitap_sayisi = 0;


void kitap_ekle() {
    if (kitap_sayisi >= MAX_KITAP) {
        printf("Kutuphane dolu\n");
        return;
    }

    printf("Kitap adi: ");
    scanf(" %[^\n]", kutuphane[kitap_sayisi].isim);

    printf("Yazar: ");
    scanf(" %[^\n]", kutuphane[kitap_sayisi].yazar);

    printf("ISBN numarasi: ");
    scanf("%d", &kutuphane[kitap_sayisi].ISBN);

    kutuphane[kitap_sayisi].mevcut = 0;
    kitap_sayisi++;
    printf("Kitap eklendi\n");
}


void kitap_listele() {
    if (kitap_sayisi == 0) {
        printf("Kutuphanede kitap yok.\n");
        return;
    }

    printf("\nKutuphanedeki Kitaplar:\n");
    for (int i = 0; i < kitap_sayisi; i++) {
        printf("Kitap #%d\n", i + 1);
        printf("  Adı: %s\n", kutuphane[i].isim);
        printf("  Yazarı: %s\n", kutuphane[i].yazar);
        printf("  ISBN: %d\n", kutuphane[i].ISBN);
        printf("  Durum: %s\n\n", kutuphane[i].mevcut ? "Alinmis" : "Mevcut");
    }
}


void kitap_al() {
    int isbn;
    printf("Odunc almak istediginiz kitabin ISBN numarasini girin: ");
    scanf("%d", &isbn);

    for (int i = 0; i < kitap_sayisi; i++) {
        if (kutuphane[i].ISBN == isbn) {
            if (kutuphane[i].mevcut) {
                printf("Bu kitap zaten alinmis\n");
            }
            else {
                kutuphane[i].mevcut = 1;
                printf("Kitap odunc alindi\n");
            }
            return;
        }
    }
    printf("Girilen ISBN numarasina sahip kitap bulunamadi\n");
}


void kitap_ver() {
    int isbn;
    printf("Iade etmek istediginiz kitabin ISBN numarasini girin: ");
    scanf("%d", &isbn);

    for (int i = 0; i < kitap_sayisi; i++) {
        if (kutuphane[i].ISBN == isbn) {
            if (!kutuphane[i].mevcut) {
                printf("Bu kitap zaten kütüphanede.\n");
            }
            else {
                kutuphane[i].mevcut = 0;
                printf("Kitap iade edildi\n");
            }
            return;
        }
    }
    printf("Girilen ISBN numarasina sahip kitap bulunamadi\n");
}


void menu() {
    int secim;
    do {
        printf("1. Kitap Ekle\n");
        printf("2. Kitaplari Listele\n");
        printf("3. Kitap Odunc Al\n");
        printf("4. Kitap Iade Et\n");
        printf("5. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            kitap_ekle();
            break;
        case 2:
            kitap_listele();
            break;
        case 3:
            kitap_al();
            break;
        case 4:
            kitap_ver();
            break;
        case 5:
            printf("Cikis yapiliyor\n");
            break;
        default:
            printf("Gecersiz Secim\n");
        }
    } while (secim != 5);
}


int main() {
    menu();
    return 0;
}