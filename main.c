#include <stdio.h>
#include <string.h>

int rakamlartoplami(int sayi)
{
	int birler, onlar, toplam;
	if (sayi < 10)
	{
		birler = sayi % 10;

		toplam = birler;


	}
	else if (sayi < 100)
	{
		birler = sayi % 10;
		onlar = ((sayi % 100) - birler) / 10;

		toplam = birler + onlar;
	}
	return toplam;
}

int fonksiyon(char numara[])
{
	int sonuc = 1;
	for (int i = 0; i < 19; ++i)
	{
		if (i == 4 || i == 9 || i == 14) continue;
		if (isdigit(numara[i] - '0'))
		{
			sonuc = 0;
			break;
		}
	}
	if (sonuc == 0) return 0;

	int idizi[19], icarpim[19], toplam;
	idizi[0] = numara[0] - '0';
	idizi[2] = numara[2] - '0';
	idizi[5] = numara[5] - '0';
	idizi[7] = numara[7] - '0';
	idizi[10] = numara[10] - '0';
	idizi[12] = numara[12] - '0';
	idizi[15] = numara[15] - '0';
	idizi[17] = numara[17] - '0';
	icarpim[0] = idizi[0] * 2;
	icarpim[2] = idizi[2] * 2;
	icarpim[5] = idizi[5] * 2;
	icarpim[7] = idizi[7] * 2;
	icarpim[10] = idizi[10] * 2;
	icarpim[12] = idizi[12] * 2;
	icarpim[15] = idizi[15] * 2;
	icarpim[17] = idizi[17] * 2;
	toplam = rakamlartoplami(icarpim[0]) + (numara[1] - '0') + rakamlartoplami(icarpim[2]) + (numara[3] - '0') + rakamlartoplami(icarpim[5]) + (numara[6] - '0') + rakamlartoplami(icarpim[7]) + (numara[8] - '0')
	+ rakamlartoplami(icarpim[10]) + (numara[11] - '0') + rakamlartoplami(icarpim[12]) + (numara[13] - '0') + rakamlartoplami(icarpim[15]) + (numara[16] - '0') + rakamlartoplami(icarpim[17]) + (numara[18] - '0');
	if (toplam % 10 == 0) return 1; else return 0;
}

int main(void)
{
	FILE* the_file = fopen("numaralar.txt", "r");
	if (the_file == NULL) {
		perror("numaralar.txt dosyasi bulunamadi!");
		return system("pause");
	}
	char line[100];
	while(fgets(line, sizeof(line), the_file))
	{
		if (strlen(line) > 18 && strlen(line) <= 20)
		{
			printf("%s - %s", (fonksiyon(line)) ? "gecerli" : "gecersiz", line);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}