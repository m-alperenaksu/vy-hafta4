#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node {
    int data;
    struct node *next;
};

struct node *basaEkle(struct node *head, int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

void sonaEkle(struct node *head, int data) {
    if (head == NULL) {
        printf("Boş bir listenin sonuna eleman ekleyemezsiniz.\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct node *temp2 = (struct node*) malloc(sizeof(struct node));
    temp2->data = data;
    temp2->next = NULL;
    temp->next = temp2;
}

void ortayaEkle(struct node *head, int data, int index) {
    if (head == NULL) {
        printf("Boş bir listede ortaya ekleme yapamazsınız.\n");
        return;
    }
    struct node *temp = head;
    while (temp->data != index) {
        temp = temp->next;
    }
    struct node *temp2 = (struct node*) malloc(sizeof(struct node));
    temp2->data = data;
    temp2->next = temp->next;
    temp->next = temp2;
}

void listeyiYazdir(struct node *head) {
    if (head == NULL) {
        printf("Boş bir listeyi yazdıramazsınız.\n");
        return;
    }
    struct node *temp = head;
    printf("Listenin elemanları: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void elemanDuzenle(struct node *head, int data, int index) {
    if (head == NULL) {
        printf("Boş bir listeyi düzenleyemezsiniz.\n");
        return;
    }
    struct node *temp = head;
    while (temp->data != index) {
        temp = temp->next;
    }
    temp->data = data;
}

struct node *elemanSil(struct node *head, int data) {
    if (head == NULL) {
        printf("Boş bir listeden eleman silemezsiniz.\n");
        return head;
    }
    struct node *temp = head;
    if (head->data == data) {
        head = head->next;
        free(temp);
    } else {
        while (temp->next->data != data) {
            if (temp->next->next == NULL) {
                printf("Silmek istediğiniz eleman bulunamadı.\n");
                return head;
            }
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return head;
}

struct node *listeyiBosalt(struct node *head) {
    if (head == NULL) {
        printf("Liste zaten boş.\n");
        return head;
    }
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int elemanSayisi(struct node *head) {
    int sayi = 0;
    struct node *temp = head;
    while (temp != NULL) {
        sayi++;
        temp = temp->next;
    }
    return sayi;
}

void listeBilgisiYazdir(struct node *head) {
    struct node *temp = head;
    int sayac = 1;
    while (temp != NULL) {
        printf("Listenin %d. elemanın adresi = %p\n", sayac, temp);
        printf("Listenin %d. elemanının depoladığı veri = %d\n", sayac, temp->data);
        printf("Listenin %d. elemanına bağlı olan düğümün adresi = %p\n", sayac, temp->next);
        sayac++;
        temp = temp->next;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");
    int secim, data, index;
    struct node *head = NULL;

    while (1) {
        printf("-----Aşağıdaki işlemlerden birini seçiniz...---\n");
        printf("1-Listenin Başına Eleman Ekleme\n");
        printf("2-Listenin Sonuna Eleman Ekleme\n");
        printf("3-Listenin Ortasına Eleman Ekleme\n");
        printf("4-Elemanları Listele\n");
        printf("5-Verilen Adresteki elemanı Düzenle\n");
        printf("6-Listenden İstenilen Elemanı Sil\n");
        printf("7-Listeyi Sil\n");
        printf("8-Listenin Eleman Sayısı\n");
        printf("9-Listenin Tüm elemanlarının Bilgilerini Yazdır\n");
        printf("10-Programdan Çık\n");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...");
                scanf("%d", &data);
                head = basaEkle(head, data);
                break;
            case 2:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...");
                scanf("%d", &data);
                sonaEkle(head, data);
                break;
            case 3:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...");
                scanf("%d", &data);
                printf("Lütfen Ekleme Yapılacak Pozisyon Bilgisini Giriniz.....");
                scanf("%d", &index);
                ortayaEkle(head, data, index);
                break;
            case 4:
                listeyiYazdir(head);
                break;
            case 5:
                printf("Lütfen Değiştirmek İstediğiniz Yeni Değeri Giriniz...");
                scanf("%d", &data);
                printf("Lütfen Değeri Değiştirilmek İsteyen Pozisyon Bilgisini Giriniz.....");
                scanf("%d", &index);
                elemanDuzenle(head, data, index);
                break;
            case 6:
                printf("Lütfen Silmek İstediğiniz Elemanın Değerini Giriniz...");
                scanf("%d", &data);
                head = elemanSil(head, data);
                break;
            case 7:
                head = listeyiBosalt(head);
                break;
            case 8:
                printf("Listenin Eleman Sayısı = %d\n", elemanSayisi(head));
                break;
            case 9:
                listeBilgisiYazdir(head);
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Yanlış seçim\n");
        }
    }

    return 0;
}
