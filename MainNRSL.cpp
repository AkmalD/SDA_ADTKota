

/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/* Kamus Lokal */
		List List[5]; 								//Untuk list Nama
		int i, cariNama=0,cariPosisi=0,menu=0;
		address P, Prec,First;
		tElmtList kota[5]={Nil}; 					//Diisi "Nil" karena menunjukkan bahwa data belum di insialisasi
		infotype nama,nama2,isi;
		
	/* Program */

	CreateList(&List[0]);
	CreateList(&List[1]);
	CreateList(&List[2]);
	CreateList(&List[4]);
	CreateList(&List[5]);
	
	while(menu==0){ 								//Untuk menampilkan daftar kota yang ada
	printf("Daftar Kota :\n");
	for(int i=0;i<5;i++){
		if(kota[i].info != Nil){
			PrintInfoKota(i+1,kota[i].info);
			printf("\n");
		}
	}
	Menu();
	scanf("%d",&menu);
	
	//Tampil Nama
	if(menu==1){
	printf("Pilih kota untuk lihat data nama :\n");
	scanf("%d", &cariNama);
	switch(cariNama){
		case 1: printf("Data nama di Kota %s: ", kota[0].info);
				PrintInfo(List[0]);
				break;
		case 2: printf("Data nama di Kota %s: ", kota[1].info);
				PrintInfo(List[1]);
				break;
		case 3: printf("Data nama di Kota %s: ", kota[2].info);
				PrintInfo(List[2]);
				break;
		case 4: printf("Data nama di Kota %s: ", kota[3].info);
				PrintInfo(List[3]);
				break;
		case 5: printf("Data nama di Kota %s: ", kota[4].info);
				PrintInfo(List[4]);
				break;
			}
		printf("\nKembali ke Menu? ya(0) tidak(1) : ");
		scanf("%d", &menu);
		system("cls");
	}
		
	//Enrty Nama
	if(menu==2){
		printf("Daftar Kota :\n");
		for(int i=0;i<5;i++){
			if(kota[i].info != Nil){
				PrintInfoKota(i+1,kota[i].info);
				PrintInfo(List[i]);
			}
		}
		printf("\nMasukkan nama : ");
		alokString(&nama);
		scanf(" %[^\n]", nama);
		printf("\nPilih kota : ");
		scanf("%d", &cariPosisi);
		switch(cariPosisi){
			case 1: printf("\nInsert awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	First=InsVFirst(&List[0],nama);
								kota[0].next=First;break;
						case 2:InsVLast (&List[0], nama);}break;
			case 2: printf("\nInsert awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	First=InsVFirst(&List[1],nama);
								kota[1].next=First;break;
						case 2:InsVLast (&List[1], nama);}break;
			case 3: printf("\nInsert awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	First=InsVFirst(&List[2],nama);
								kota[2].next=First;break;
						case 2:InsVLast (&List[2], nama);}break;
			case 4: printf("\nInsert awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	First=InsVFirst(&List[3],nama);
								kota[3].next=First;break;
						case 2:InsVLast (&List[3], nama);}break;
			case 5: printf("\nInsert awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	First=InsVFirst(&List[4],nama);
								kota[4].next=First;break;
						case 2:InsVLast (&List[4], nama);}break;
			}
		printf("\nKembali ke Menu? ya(0) tidak(1) : ");
		scanf("%d", &menu);
		system("cls");		
	}
	
	//Delete Nama
	if(menu==3){
		printf("Daftar Kota :\n");
		for(int i=0;i<5;i++){
			if(kota[i].info != Nil){
				PrintInfoKota(i+1,kota[i].info);
				PrintInfo(List[i]);
			}
		}
		printf("\nPilih kota : ");
		scanf("%d", &cariPosisi);
		switch(cariPosisi){
			case 1: printf("\nHapus awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	DelVFirst (&List[0], &isi);break;
						case 2:DelVLast (&List[0], &isi);}break;
			case 2:printf("\nHapus awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	DelVFirst (&List[1], &isi);break;
						case 2:DelVLast (&List[1], &isi);}break;
			case 3:printf("\nHapus awal(1) atau akhir(2) :");
					scanf("%d", &cariPosisi);
					switch(cariPosisi){
						case 1:	DelVFirst (&List[2], &isi);break;
						case 2:DelVLast (&List[2], &isi);}break;
			}
		printf("\nKembali ke Menu? ya(0) tidak(1) : ");
		scanf("%d", &menu);
		system("cls");		
	}
	
	//Tambah Kota
	if(menu==4){
	for(int i=0;i<5;i++){
		if(kota[i].info != Nil){
			PrintInfoKota(i+1,kota[i].info);
			printf("\n");
		}
	}
	printf("Masukkan nama kota :");
	alokString(&nama);
	scanf(" %[^\n]", nama);
	for(int i=0;i<5;i++){
		if(kota[i].info == Nil){
			kota[i].info=nama;
			kota[i].next=List[i].First;
			break;
		}
	}
	printf("\nKembali ke Menu? ya(0) tidak(1) : ");
		scanf("%d", &menu);
		system("cls");	
	}
	
	//Hapus Kota
	if(menu==5){
		for(int i=0;i<4;i++){
		if(kota[i].info != Nil){
			PrintInfoKota(i+1,kota[i].info);
			printf("\n");
		}
		if (first->next != Nil)
    {
        last = isiLast(dapen[index]);
        while (first->next!=Nil){
            address P = first;
            while(P->next != last){
                P = P->next;
            }
            sambungList(&last,P);
            free(P->next);
            P->next = Nil;
        }

    }
	}
	printf("Pilih nomor kota yang akan dihapus :");
	scanf("%d", &cariPosisi);
	switch(cariPosisi){
		case 1: kota[0].info=Nil;
				DelAll(&List[0]);break;
				kota[0]=kota[1];
				kota[0].next=List[1].First;
				List[0]=List[1];
		case 2: kota[1].info=Nil;
				DelAll(&List[1]);break;
		case 3: kota[2].info=Nil;
				DelAll(&List[2]);break;
		case 4: kota[3].info=Nil;
				DelAll(&List[3]);break;
		case 5: kota[4].info=Nil;
				DelAll(&List[4]);break;
		}
	
	printf("\nKembali ke Menu? ya(0) tidak(1) : ");
		scanf("%d", &menu);
		system("cls");	
	}
	

}

	
	P = First(List[0]);
	DeAlokasi (P);
	P = First(List[1]);
	DeAlokasi (P);
	P = First(List[2]);
	DeAlokasi (P);
	P = First(List[3]);
	DeAlokasi (P);
	P = First(List[4]);
	DeAlokasi (P);
	return 0;
}

