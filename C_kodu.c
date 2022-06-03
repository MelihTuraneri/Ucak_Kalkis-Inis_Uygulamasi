#include <stdio.h>
#include <stdlib.h>
struct Ucak
{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
};
struct Ucak2
{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
    int inis_saati;
    int gecikme_suresi;
};
int kayit_sayisini_bulma();
void yazdir();
void cizdir();
void index_dosyasi_olustur(int V)
{
    FILE *fp0;
    FILE *fp1;
    FILE *fp2;
    int kayit_sayaci = 0;
    int sayac = 0;
    int sayac1 = 0;
    int kayit_sayisi = V;
    if((fp1=fopen("Input.txt", "r+"))==NULL)
    {
        printf("Text Dosya acilamadi...\n");
        exit(0);
    }
    if((fp2=fopen("Output.txt", "w+"))==NULL)
    {
        printf("Text2 Dosya acilamadi...\n");
        exit(0);
    }
    if((fp0=fopen("Veri.bin", "r+b"))==NULL)
    {
        printf("Binary Dosya acilamadi...\n");
        exit(0);
    }
    struct Ucak2 ucak_kayit_dizi[kayit_sayisi + 1];
    struct Ucak ucak_kayit_dizi_asil[kayit_sayisi];
    while (1)
    {
        size_t sayi = fread(&ucak_kayit_dizi_asil[sayac], sizeof(struct Ucak), 1, fp0);
        if (sayi < 1)
            break;
        sayac ++;
    }
    int cekme_sayac = 0;
    while(cekme_sayac < kayit_sayisi)   //Kuyruga tek tek kayit cekme!!
    {
        ucak_kayit_dizi[cekme_sayac].oncelik_id = ucak_kayit_dizi_asil[cekme_sayac].oncelik_id;
        ucak_kayit_dizi[cekme_sayac].ucak_id = ucak_kayit_dizi_asil[cekme_sayac].ucak_id;
        ucak_kayit_dizi[cekme_sayac].inis_saati = ucak_kayit_dizi_asil[cekme_sayac].talep_edilen_inis_saati;
        ucak_kayit_dizi[cekme_sayac].gecikme_suresi = 0;
        for(int a = 0; a < cekme_sayac ; a++)
        {
            int b = 0;
            for(int j = 1; j <= cekme_sayac ; j++)
            {
                if(ucak_kayit_dizi[b].inis_saati > ucak_kayit_dizi[j].inis_saati)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[b].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[b].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[b].inis_saati;
                    ucak_kayit_dizi[b].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[b].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[b].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                }
                b++;
            }
        }
        for(int i = 0; i < cekme_sayac; i++)
        {
            int k = 0;
            for(int j = 1; j <= cekme_sayac; j++)
            {
                if(ucak_kayit_dizi[k].oncelik_id > ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[k].inis_saati == ucak_kayit_dizi[j].inis_saati)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[k].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[k].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[k].inis_saati;
                    ucak_kayit_dizi[k].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[k].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[k].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                }
                k++;
            }
        }
        for(int i = 0; i < cekme_sayac; i++)
        {
            int p = 0;
            for(int j = 1; j <= cekme_sayac; j++)
            {
                if(ucak_kayit_dizi[p].ucak_id > ucak_kayit_dizi[j].ucak_id && ucak_kayit_dizi[p].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[p].oncelik_id == ucak_kayit_dizi[j].oncelik_id)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[p].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[p].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[p].inis_saati;
                    ucak_kayit_dizi[p].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[p].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[p].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                }
                p++;
            }
        }
        cekme_sayac++;
    }
    sayac1 = 0;
    while (sayac1 < kayit_sayisi)
    {
        ucak_kayit_dizi[sayac1].talep_edilen_inis_saati = ucak_kayit_dizi[sayac1].inis_saati;
        sayac1 ++;
    }
    int siralayici = 0;
    int ust_sayac = 1;
    int alt_sayac;
    int if_sayac = 0;
    int if_sayac2 = 0;
    int kacan_sayac = 0;
    int f;
    while(ust_sayac < 25)
    {
        alt_sayac = 0;
        if_sayac = 0;
        if_sayac2 = 0;
        while((alt_sayac + kacan_sayac) < kayit_sayisi + 1)
        {
            if(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati == ust_sayac && (if_sayac == 0))
            {
                if_sayac = 1;
                printf("\n─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
                printf("|%d\t| %d\t| %d\t| %d\t| %d\t|", ucak_kayit_dizi[alt_sayac + kacan_sayac].oncelik_id,ucak_kayit_dizi[alt_sayac + kacan_sayac].ucak_id,ucak_kayit_dizi[alt_sayac + kacan_sayac].talep_edilen_inis_saati,ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati,(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati - ucak_kayit_dizi[alt_sayac + kacan_sayac].talep_edilen_inis_saati));
                printf("İniş İzin Talebiniz Onaylanmıştır 🛬");
                printf("\n─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");
            }
            else if(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati == ust_sayac && (if_sayac == 1))
            {
                ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati++;
                ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi = ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati - ucak_kayit_dizi[alt_sayac + kacan_sayac].talep_edilen_inis_saati;
                printf("\n|%d\t| %d\t| %d\t| %d\t| %d\t|", ucak_kayit_dizi[alt_sayac + kacan_sayac].oncelik_id,ucak_kayit_dizi[alt_sayac + kacan_sayac].ucak_id,ucak_kayit_dizi[alt_sayac + kacan_sayac].talep_edilen_inis_saati,ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati,(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati - ucak_kayit_dizi[alt_sayac + kacan_sayac].talep_edilen_inis_saati));
                printf("İniş İzin Talebiniz Öncelikli Ucak İnişi Sebebiyle Ertelenmiştir ");
                if(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati > 24)
                {
                    printf("\n\t\t\t\t\t|İnişiniz Ertesi Güne Kaldığı İçin Sabiha Gökçen Havaalanına Yönlendiriliyorsunuz\n");
                    printf("─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");
                }
                if(ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi == 3 && if_sayac2 == 1)
                {
                    printf("  İnis Saatiniz Kotasından Fazla Ertelendiği İçin Sabiha Gökçen Havaalanına Yönlendiriliyorsunuz");
                    printf("\n─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");
                }
                if(ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi == 3 && if_sayac2 == 0) if_sayac2 = 1;
            }
            else if(ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati != ust_sayac && (if_sayac == 0))
            {
                alt_sayac = 0;
                ust_sayac++;
                continue;
            }
            alt_sayac++;
        }
        if_sayac = 0;
        if_sayac2 = 0;
        alt_sayac = 0;
        for(int i = 0; i < kayit_sayisi ; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi ; j++)
            {
                if(ucak_kayit_dizi[f].inis_saati > ucak_kayit_dizi[j].inis_saati)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].oncelik_id > ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].ucak_id > ucak_kayit_dizi[j].ucak_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[f].oncelik_id == ucak_kayit_dizi[j].oncelik_id)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[j].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].oncelik_id == ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[j].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].ucak_id == ucak_kayit_dizi[j].ucak_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[f].oncelik_id == ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[j].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].inis_saati > ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[j].gecikme_suresi == 3 && ucak_kayit_dizi[f].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].oncelik_id > ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[j].gecikme_suresi == 3 && ucak_kayit_dizi[f].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        for(int i = 0; i < kayit_sayisi; i++)
        {
            f = 0;
            for(int j = 1; j < kayit_sayisi; j++)
            {
                if(ucak_kayit_dizi[f].ucak_id > ucak_kayit_dizi[j].ucak_id && ucak_kayit_dizi[f].inis_saati == ucak_kayit_dizi[j].inis_saati && ucak_kayit_dizi[f].oncelik_id == ucak_kayit_dizi[j].oncelik_id && ucak_kayit_dizi[j].gecikme_suresi == 3 && ucak_kayit_dizi[f].gecikme_suresi == 3)
                {
                    ucak_kayit_dizi[kayit_sayisi].oncelik_id = ucak_kayit_dizi[j].oncelik_id;
                    ucak_kayit_dizi[kayit_sayisi].ucak_id = ucak_kayit_dizi[j].ucak_id;
                    ucak_kayit_dizi[kayit_sayisi].inis_saati = ucak_kayit_dizi[j].inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati = ucak_kayit_dizi[j].talep_edilen_inis_saati;
                    ucak_kayit_dizi[kayit_sayisi].gecikme_suresi = ucak_kayit_dizi[j].gecikme_suresi;
                    ucak_kayit_dizi[j].oncelik_id = ucak_kayit_dizi[f].oncelik_id;
                    ucak_kayit_dizi[j].ucak_id = ucak_kayit_dizi[f].ucak_id;
                    ucak_kayit_dizi[j].inis_saati = ucak_kayit_dizi[f].inis_saati;
                    ucak_kayit_dizi[j].talep_edilen_inis_saati = ucak_kayit_dizi[f].talep_edilen_inis_saati;
                    ucak_kayit_dizi[j].gecikme_suresi = ucak_kayit_dizi[f].gecikme_suresi;
                    ucak_kayit_dizi[f].oncelik_id = ucak_kayit_dizi[kayit_sayisi].oncelik_id;
                    ucak_kayit_dizi[f].ucak_id = ucak_kayit_dizi[kayit_sayisi].ucak_id;
                    ucak_kayit_dizi[f].inis_saati = ucak_kayit_dizi[kayit_sayisi].inis_saati;
                    ucak_kayit_dizi[f].talep_edilen_inis_saati = ucak_kayit_dizi[kayit_sayisi].talep_edilen_inis_saati;
                    ucak_kayit_dizi[f].gecikme_suresi = ucak_kayit_dizi[kayit_sayisi].gecikme_suresi;
                }
                f++;
            }
        }
        kacan_sayac++;
        while((alt_sayac + kacan_sayac) < kayit_sayisi + 1)
        {
            if(ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi == 3 && (if_sayac == 0))
            {
                if_sayac = 1;
            }
            else if(ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi == 3 && (if_sayac == 1))
            {
                ucak_kayit_dizi[alt_sayac + kacan_sayac].gecikme_suresi++;
                ucak_kayit_dizi[alt_sayac + kacan_sayac].inis_saati = 100;
            }
            alt_sayac++;
        }
        ust_sayac++;
    }
    printf("\n\n");
    sayac1 = 0;
    fprintf(fp2,"%s\t%s\t%s\t%s\t%s\t%s\n","oncelik_id","ucak_id","talep_edilen_inis_saati","inis_saati","gecikme_suresi","kalkis_saati");
    while (sayac1 < kayit_sayisi)
    {
        if(ucak_kayit_dizi[sayac1].inis_saati == 24)
        {
            fprintf(fp2,"|%d\t\t| %d\t\t| %d\t\t\t\t| %d\t\t| %d\t\t| %d (Ertesi Gun)\n", ucak_kayit_dizi[sayac1].oncelik_id,ucak_kayit_dizi[sayac1].ucak_id,ucak_kayit_dizi[sayac1].talep_edilen_inis_saati,ucak_kayit_dizi[sayac1].inis_saati,ucak_kayit_dizi[sayac1].gecikme_suresi,1);
        }
        else
            fprintf(fp2,"|%d\t\t| %d\t\t| %d\t\t\t\t| %d\t\t| %d\t\t| %d\n", ucak_kayit_dizi[sayac1].oncelik_id,ucak_kayit_dizi[sayac1].ucak_id,ucak_kayit_dizi[sayac1].talep_edilen_inis_saati,ucak_kayit_dizi[sayac1].inis_saati,ucak_kayit_dizi[sayac1].gecikme_suresi,(ucak_kayit_dizi[sayac1].inis_saati + 1));
        if(ucak_kayit_dizi[sayac1].inis_saati == 24) break;
        sayac1 ++;
    }
    sayac1 = 0;
    printf("oncelik_id\tucak_id\t\ttalep_edilen_inis_saati\t\tinis_saati\tgecikme_suresi\tkalkis_saati\n");
    while (sayac1 < kayit_sayisi)
    {
        if(ucak_kayit_dizi[sayac1].inis_saati == 24)
        {
            printf("|%d\t\t| %d\t\t| %d\t\t\t\t| %d\t\t| %d\t\t| %d (Ertesi Gun)\n", ucak_kayit_dizi[sayac1].oncelik_id,ucak_kayit_dizi[sayac1].ucak_id,ucak_kayit_dizi[sayac1].talep_edilen_inis_saati,ucak_kayit_dizi[sayac1].inis_saati,ucak_kayit_dizi[sayac1].gecikme_suresi,1);
        }
        else
            printf("|%d\t\t| %d\t\t| %d\t\t\t\t| %d\t\t| %d\t\t| %d\n", ucak_kayit_dizi[sayac1].oncelik_id,ucak_kayit_dizi[sayac1].ucak_id,ucak_kayit_dizi[sayac1].talep_edilen_inis_saati,ucak_kayit_dizi[sayac1].inis_saati,ucak_kayit_dizi[sayac1].gecikme_suresi,(ucak_kayit_dizi[sayac1].inis_saati + 1));
        if(ucak_kayit_dizi[sayac1].inis_saati == 24) break;
        sayac1 ++;
    }
    fclose(fp0);
    fclose(fp1);
    fclose(fp2);
}
int main()
{
    yazdir();
    int kayit_sayisi = kayit_sayisini_bulma();
    index_dosyasi_olustur(kayit_sayisi);
    return 0;
}
void yazdir()
{
    FILE *fp;
    FILE *fp1;
    if((fp1=fopen("Input.txt", "r"))==NULL)
    {
        printf("Text Dosya acilamadi...\n");
        exit(0);
    }
    if((fp=fopen("Veri.bin", "wb"))==NULL)
    {
        printf("Binary Dosya acilamadi...\n");
        exit(0);
    }
    int i = 0;
    while (1)
    {
        i++;
        struct Ucak ucak;
        fscanf(fp1,"%d %d %d\n",&ucak.oncelik_id,&ucak.ucak_id,&ucak.talep_edilen_inis_saati);
        fwrite(&ucak, sizeof(struct Ucak), 1, fp);
        if(i == 28) break;
    }
    fclose(fp);
    fclose(fp1);
    int n = kayit_sayisini_bulma();
}
void cizdir()
{
    FILE *fp0;
    if ((fp0 = fopen("Veri.bin", "rb")) == NULL)
    {
        printf("dosya acilamadi!\n");
        exit(1);
    }
    while (1)
    {
        struct Ucak ucak;
        size_t sayi = fread(&ucak, sizeof(struct Ucak), 1, fp0);
        if (sayi < 1)
            break;
        printf("%d\t %d\t %d\n", ucak.oncelik_id, ucak.ucak_id, ucak.talep_edilen_inis_saati);
    }
    fclose(fp0);
}
int kayit_sayisini_bulma()
{
    FILE *fp0;
    int n = 0;
    if((fp0=fopen("Veri.bin", "r+b"))==NULL)
    {
        printf("Binary Dosyasi Acilamadi...\n");
        exit(0);
    }
    while (fgetc(fp0) != EOF)
    {
        n++;
    }
    return (n/12);
}

