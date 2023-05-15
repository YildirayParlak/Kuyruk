
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5

int queue[BOYUT], bas = -1, arka = -1;  // Kuyru�u tan�mlada�k burada

void enQueue(int veri)  // Kuyru�a eleman ekleyen fonksiyon kulland�k
{
    if (arka == BOYUT)  // Kuyru�un dolu olup olmad���n� kontrol ediyoruz burada
        printf("\nKuyruk Dolu");
    else
    {
        if (bas == -1)
           bas  = 0;
        arka = arka + 1;
        queue[arka] = veri;  
    }
}

void deQueue()  // Kuyruktan eleman silen fonksiyonu kullan�yoz
{
    if (bas == -1 || bas > arka)  // Kuyru�un bo� olup olmad���n� kontrol eder
    {
        printf("\nKuyruk Bos");
        bas = -1;
        arka = -1;
    }
    else
    {
        bas = bas + 1;  // �lk eleman� kuyruktan ��kar
        printf("Eleman silindi!");
    }
}

void display()  // Elemanlar� g�r�nt�leyen fonksiyon
{
    int i;
    for (i = bas; i <= arka; i++)
        printf("\n%d\n", queue[i]);  // Kuyruktaki elemanlar� s�rayla yazd�r�yoruz
}

int main(int argc, char *argv[]) 
{
    int secim;
    int ekle;
    int i = 1;

    while (i == 1)  // burada kullan�c�dan men�den i�lme yapmas�n� istiyoruz
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
                enQueue(ekle);  // Kuyru�a veri eklemme k�sm�
                break;	

            case 2:
                deQueue();  // Kuyruktan eleman ��karma k�sm�
                break;

            case 3:
                display();  // Kuyruktaki elemanlar� g�r�nt�leme k�sm�
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

