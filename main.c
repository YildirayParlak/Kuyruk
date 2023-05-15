
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5

int queue[BOYUT], bas = -1, arka = -1;  // Kuyruðu tanýmladaýk burada

void enQueue(int veri)  // Kuyruða eleman ekleyen fonksiyon kullandýk
{
    if (arka == BOYUT)  // Kuyruðun dolu olup olmadýðýný kontrol ediyoruz burada
        printf("\nKuyruk Dolu");
    else
    {
        if (bas == -1)
           bas  = 0;
        arka = arka + 1;
        queue[arka] = veri;  
    }
}

void deQueue()  // Kuyruktan eleman silen fonksiyonu kullanýyoz
{
    if (bas == -1 || bas > arka)  // Kuyruðun boþ olup olmadýðýný kontrol eder
    {
        printf("\nKuyruk Bos");
        bas = -1;
        arka = -1;
    }
    else
    {
        bas = bas + 1;  // Ýlk elemaný kuyruktan çýkar
        printf("Eleman silindi!");
    }
}

void display()  // Elemanlarý görüntüleyen fonksiyon
{
    int i;
    for (i = bas; i <= arka; i++)
        printf("\n%d\n", queue[i]);  // Kuyruktaki elemanlarý sýrayla yazdýrýyoruz
}

int main(int argc, char *argv[]) 
{
    int secim;
    int ekle;
    int i = 1;

    while (i == 1)  // burada kullanýcýdan menüden iþlme yapmasýný istiyoruz
    {
        printf("\nLutfen asagidaki islemlerden birini seciniz\n\n");
        printf("1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis");
        printf("\nSeciminiz:");
        scanf("%d", &secim);

        switch (secim)
        {
            case 1:			
                printf("\nEklemek istediginiz sayiyi giriniz:");
                scanf("%d", &ekle);
                enQueue(ekle);  // Kuyruða veri eklemme kýsmý
                break;	

            case 2:
                deQueue();  // Kuyruktan eleman çýkarma kýsmý
                break;

            case 3:
                display();  // Kuyruktaki elemanlarý görüntüleme kýsmý
                break;

            case 4:
                i = 0;
                break;

            default:
                printf("\n sanirim olmayan bir madde sectiniz");	
                break;	
        }
    }
    return 0;
}

