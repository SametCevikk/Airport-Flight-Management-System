
//SAMET ÇEVÝK 180202064


#include <stdio.h>
#include <stdlib.h>
int sayac3=0,w,e,tutac=0 ,tutac2=0,tutacinindexi, sayac=0;
int inecek_olanlar_oncelik[24];
int inecek_olanlar_id[24];
int inecek_olanlar_talep_saat[24];
int inecek_olanlar_inis_saat[24];
int inecek_olanlar_gecikme[24];
int kalkis_gecikme_sayac[24];

int kalkis_pis_kullanim_oncelik[24];
int kalkis_pis_kullanim_id[24];
int kalkis_pis_kullanim_talep_saat[24];
int kalkis_pis_kullanim_inis_saat[24];
int kalkis_pis_kullanim_kalkis_saat[24];
int kalkis_pis_kullanim_gecikme[24];
int talep_saat,kalkis_saaat,gecikme ;

void guncelle()
{
	int i ;
	for(i=0;i<24;i++)
	{
		kalkis_pis_kullanim_oncelik[i]=inecek_olanlar_oncelik[i];
		kalkis_pis_kullanim_id[i]=inecek_olanlar_id[i];
		kalkis_pis_kullanim_talep_saat[i]=inecek_olanlar_talep_saat[i];
		kalkis_pis_kullanim_inis_saat[i]=inecek_olanlar_inis_saat[i];
		if(inecek_olanlar_id[i]!=0){
			kalkis_pis_kullanim_kalkis_saat[i]=inecek_olanlar_inis_saat[i]+1;
		}

		kalkis_pis_kullanim_gecikme[i]=inecek_olanlar_gecikme[i];






	}
	printf("oncelk   id   talep    inis   kalkis  gecikme \t \t SAAT\n");
	for (i=0;i<24;i++)
	{
		printf("  %d \t  %d \t %d \t  %d \t  %d \t %d \t\t%d\n",kalkis_pis_kullanim_oncelik[i],kalkis_pis_kullanim_id[i],kalkis_pis_kullanim_talep_saat[i],kalkis_pis_kullanim_inis_saat[i],kalkis_pis_kullanim_kalkis_saat[i],kalkis_pis_kullanim_gecikme[i],i+1);
	}

}

void yazdir()
{
	int a ;
	FILE *file ;
	file=fopen("output.txt","w");
	for (a=0;a<24;a++){
		fprintf(file,"%d %d %d %d %d %d\n",kalkis_pis_kullanim_oncelik[a],kalkis_pis_kullanim_id[a],kalkis_pis_kullanim_talep_saat[a],kalkis_pis_kullanim_inis_saat[a],kalkis_pis_kullanim_kalkis_saat[a],kalkis_pis_kullanim_gecikme[a]);
	}
	fclose(file);
}


void ertele(int oncelik,int ucakid,int inisaat)
{
	int i;


	for(i=0;i<24;i++)
	{
		if(inecek_olanlar_inis_saat[i]==inisaat+1)
		{



		if( oncelik>=inecek_olanlar_oncelik[i])
		{
			printf("%d id li ucak sizden daha oncelikli oldugu icin yine erteleniyorsunuz \n",inecek_olanlar_id[i]);

		}else{

		printf("%d id li ucaktan daha oncelikli oldugunuz icin inis izni verildi \n",inecek_olanlar_id[i]);
			ertele(inecek_olanlar_oncelik[i],inecek_olanlar_id[i],inisaat+1);
		 	inecek_olanlar_id[inisaat]=ucakid ;
			inecek_olanlar_oncelik[inisaat]=oncelik ;
			inecek_olanlar_inis_saat[inisaat]=inisaat+1;
			inecek_olanlar_talep_saat[inisaat]=inisaat;
			inecek_olanlar_gecikme[inisaat]=1 ;

			goto dur;
				break;
	}
	}
}
	if(inecek_olanlar_id[inisaat]==0 )
	{		 printf("bir sonraki saat bos oldugu icin inis izni verildi \n");
			inecek_olanlar_id[inisaat]=ucakid ;
			inecek_olanlar_oncelik[inisaat]=oncelik ;
			inecek_olanlar_inis_saat[inisaat]=inisaat+1;
			inecek_olanlar_talep_saat[inisaat]=inisaat;
			inecek_olanlar_gecikme[inisaat]=1 ;
				goto dur;

	}


		for(i=0;i<24;i++)
	{
		if(inecek_olanlar_inis_saat[i]==inisaat+2)
		{




		if( oncelik>=inecek_olanlar_oncelik[i] )
		{
			printf("%d id li ucak sizden daha oncelikli oldugu icin yine erteleniyorsunuz \n",inecek_olanlar_id[i]);

		}
		else{

		printf("%d id li ucaktan daha oncelikli oldugunuz icin inis izni verildi \n",inecek_olanlar_id[i]);
		   if(inecek_olanlar_gecikme[i]==3){
		   	printf("%d id li ucak 3. kez ertelendiniz  \n",inecek_olanlar_id[i]);
		   printf("sabiha goksen havalimanina yonlendiriliyorsunuz \n");
		   	inecek_olanlar_id[inisaat+1]=ucakid ;
			inecek_olanlar_oncelik[inisaat+1]=oncelik ;
			inecek_olanlar_inis_saat[inisaat+1]=inisaat+2;
			inecek_olanlar_talep_saat[inisaat+1]=inisaat;
			inecek_olanlar_gecikme[inisaat+1]=2;
		goto dur;
		   }
			ertele(inecek_olanlar_oncelik[i],inecek_olanlar_id[i],inisaat+2);
		 	inecek_olanlar_id[inisaat+1]=ucakid ;
			inecek_olanlar_oncelik[inisaat+1]=oncelik ;
			inecek_olanlar_inis_saat[inisaat+1]=inisaat+2;
			inecek_olanlar_talep_saat[inisaat+1]=inisaat;
			inecek_olanlar_gecikme[inisaat+1]=2;
		    break;
		 	goto dur;
	}
	}
}
	if(inecek_olanlar_id[inisaat+1]==0)
	{
	   printf("bir sonraki saat bos oldugu icin inis izni verildi \n");
		  	inecek_olanlar_id[inisaat+1]=ucakid ;
			inecek_olanlar_oncelik[inisaat+1]=oncelik ;
			inecek_olanlar_inis_saat[inisaat+1]=inisaat+2;
			inecek_olanlar_talep_saat[inisaat+1]=inisaat;
			inecek_olanlar_gecikme[inisaat+1]=2 ;
				goto dur;

	}



		for(i=0;i<24;i++)
	{
		if(inecek_olanlar_inis_saat[i]==inisaat+3)
		{




		if( oncelik>=inecek_olanlar_oncelik[i] )
		{
			printf("%d id li ucak sizden daha oncelikli 3. kez ertelendiniz  \n",inecek_olanlar_id[i]);
		   printf("sabiha goksen havalimanina yonlendiriliyorsunuz");
		goto dur;
		}else{

		printf("%d id li ucaktan daha oncelikli oldugunuz icin inis izni verildi \n",inecek_olanlar_id[i]);
			ertele(inecek_olanlar_oncelik[i],inecek_olanlar_id[i],inisaat+3);
		  	inecek_olanlar_id[inisaat+2]=ucakid ;
			inecek_olanlar_oncelik[inisaat+2]=oncelik ;
			inecek_olanlar_inis_saat[inisaat+2]=inisaat+3;
			inecek_olanlar_talep_saat[inisaat+2]=inisaat;
			inecek_olanlar_gecikme[inisaat+2]=3 ;
			break;
			goto dur;
	}
	}
}

	if(inecek_olanlar_id[inisaat+2]==0 )
	{		 printf("bir sonraki saat bos oldugu icin inis izni verildi \n");
			inecek_olanlar_id[inisaat+2]=ucakid ;
			inecek_olanlar_oncelik[inisaat+2]=oncelik ;
			inecek_olanlar_inis_saat[inisaat+2]=inisaat+3;
			inecek_olanlar_talep_saat[inisaat+2]=inisaat;
			inecek_olanlar_gecikme[inisaat+2]=3 ;

	}

			dur: printf("\n");
		}



void add(int oncelik,int ucakid,int inissaat){


		for(w=0;w<24;w++)
		{
			if(inecek_olanlar_inis_saat[w]==inissaat)
			{
				tutac=1 ;

				break ;
			}
		}

		if(tutac==1)
		{
			printf("inis saatiniz icin farkli bir ucak izin almistir. lutfen bekleyin oncelik durumunuz kontrol ediliyor\n");

			if(inecek_olanlar_oncelik[w]>oncelik)
			{
				printf("%d id'li ucagin oncelik sirasi dusuk oldugu icin inis saati erteleniyor.\n",inecek_olanlar_id[w]);
				printf("%d id'li ucak %d saatine izin almistir.\n",ucakid,inissaat);

					ertele(inecek_olanlar_oncelik[w],inecek_olanlar_id[w],inissaat);
			inecek_olanlar_id[inissaat-1]=ucakid ;
			inecek_olanlar_oncelik[inissaat-1]=oncelik ;
			inecek_olanlar_inis_saat[inissaat-1]=inissaat;
			inecek_olanlar_talep_saat[inissaat-1]=inissaat;
			inecek_olanlar_gecikme[inissaat-1]=0 ;

			}
			else
			{
				printf("istediginiz inis saatinde onceligi sizden yuksek bir ucak bulunmaktadir. Onceliginize gore inis saatiniz hesaplaniyor.\n");
				ertele(oncelik,ucakid,inissaat);
			}


		}
		else
		{
			printf("%d id'li ucak %d saatine inis icin izin almistir.\n",ucakid,inissaat);
			inecek_olanlar_id[inissaat-1]=ucakid ;
			inecek_olanlar_oncelik[inissaat-1]=oncelik ;
			inecek_olanlar_inis_saat[inissaat-1]=inissaat;
			inecek_olanlar_talep_saat[inissaat-1]=inissaat;
			inecek_olanlar_gecikme[inissaat-1]=0 ;

		}
		tutac=0;


}



int main(int argc, char *argv[]) {
	FILE *dosya ;
	dosya=fopen("input.txt","r");

	for (sayac3=0;sayac3<24;sayac3++)
	{
	inecek_olanlar_id[sayac3]=0;
	inecek_olanlar_oncelik[sayac3]=0;
	inecek_olanlar_talep_saat[sayac3]=0;
	inecek_olanlar_inis_saat[sayac3]=0;
	inecek_olanlar_gecikme[sayac3]=0;
	kalkis_gecikme_sayac[sayac3]=0;

	}
	char deneme1[100];
	char deneme2[100];
	char deneme3[100];
	int i=0 ;
	while (!feof(dosya))
	{
		if(i!=0)
		{
			fscanf(dosya,"%s %s %s\n",&deneme1,&deneme2,&deneme3);
    		if (ferror(dosya))
			{
         	printf("Kaynak dosyadan okuma hatasý!\n");
         	break ;
     		}
  		}
		  i++ ;
	}
  fclose (dosya);
  int linesayisi=i-2 ;
  FILE *dosya2 ;
  dosya2=fopen("input.txt","r");
  int oncelik_sirasi[i-2] ;
  int ucak_id[i-2] ;
  int inis_saati[i-2];
  int j=0;
  char a[3],b[3],c[3] ;
  while (!feof(dosya2))
	{

		if(j!=0)
		{
			fscanf(dosya2,"%s %s %s \n",&a,&b,&c);
			int a1,b1,c1 ;
			a1=atoi(a);
			b1=atoi(b);
			c1=atoi(c);
			inis_saati[j-1]=c1;
			ucak_id[j-1]=b1;
			oncelik_sirasi[j-1]=a1;
    		if (ferror(dosya2))
			{
         	printf("Kaynak dosyadan okuma hatasý!\n");
         	break ;
     		}
  		}
		  j++ ;
	}
  fclose(dosya2);
  int oncelik_sirasi_sonuc[linesayisi];
  int ucak_id_sonuc[linesayisi];
  int inis_saati_sonuc[linesayisi];
  for(i=0;i<28;i++)
  {
	oncelik_sirasi_sonuc[i]=oncelik_sirasi[i+1];
	ucak_id_sonuc[i]=ucak_id[i+1];
	inis_saati_sonuc[i]=inis_saati[i+1];
  }

  char aaa ;
  for(i=0;i<24;i++){
  	kalkis_pis_kullanim_oncelik[i]=0;
	kalkis_pis_kullanim_id[i]=0;
	kalkis_pis_kullanim_talep_saat[i]=0;
	kalkis_pis_kullanim_inis_saat[i]=0;
	kalkis_pis_kullanim_kalkis_saat[i]=0;
	kalkis_pis_kullanim_gecikme[i]=0;
  }
  for(i=0;i<linesayisi;i++)
  {
  	printf("%d id numarasi sahip ucak %d saatine inis talep etmektedir.\n",ucak_id_sonuc[i],inis_saati_sonuc[i]);
  	add(oncelik_sirasi_sonuc[i],ucak_id_sonuc[i],inis_saati_sonuc[i]);
  	guncelle();
  	yazdir();
  	scanf("%c",&aaa);
  }


	return 0;
}
