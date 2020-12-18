#include"Header.h"

void createBin()
{
	FILE* file;
	file = fopen("musics.bin", "wb");
	FILE* fileTmp;
	fileTmp = fopen("musics.txt", "r");
	while (!feof(fileTmp))
	{
		int a, b, len1, len2;
		char ch;
		char str[20], str2[20];
		fgets(str, 19, fileTmp);
		//fscanf(fileTmp, "%[^\n]s", str);
		fgets(str2, 19, fileTmp);
		len1 = strlen(str) - 1;
		len2 = strlen(str2) - 1;
		//fscanf(fileTmp, "%[^\n]s", str2);
		str2[len2] = '\0';
		str[len1] = '\0';

		fscanf(fileTmp, "%d", &a);
		fscanf(fileTmp, "%d", &b);
		fscanf(fileTmp, "%c", &ch);

		fwrite(&len1, sizeof(int), 1, file);
		fwrite(str, sizeof(char), len1, file);
		fwrite(&len2, sizeof(int), 1, file);
		fwrite(str2, sizeof(char), len2, file);
		fwrite(&a, sizeof(int), 1, file);
		fwrite(&b, sizeof(int), 1, file);
	}
	fclose(file);
	fclose(fileTmp);
}


struct Music rereading(FILE* file)
{
	struct Music songs;
	int len1, len2;
	fread(&len1, sizeof(int), 1, file);
	fread(songs.Name, sizeof(char), len1, file);
	songs.Name[len1] = '\0';
	fread(&len2, sizeof(int), 1, file);
	fread(songs.Artist, sizeof(char), len2, file);
	songs.Artist[len2] = '\0';
	fread(&songs.Duration, sizeof(int), 1, file);
	fread(&songs.Rank, sizeof(int), 1, file);

	return songs;
}

void outputResult(struct Music* musics)
{
	printf("Name: %s\n", (*musics).Name);
	printf("Artist: %s\n", (*musics).Artist);
	printf("Duration: %d\n", (*musics).Duration);
	printf("Rank: %d\n", (*musics).Rank);
	//printf("\n");
}

void AddMusic(FILE* file)
{
	char musics[LENGTH];
	int k, len;
	printf_s("Print Name: ");
	getchar();
	fgets(musics, LENGTH, stdin);
	len = strlen(musics) - 1;
	musics[len] = '\0';
	fwrite(&len, sizeof(int), 1, file);
	fwrite(musics, sizeof(char), len, file);
	printf_s("Print Artist: ");
	fgets(musics, LENGTH, stdin);
	len = strlen(musics) - 1;
	musics[len] = '\0';
	fwrite(&len, sizeof(int), 1, file);
	fwrite(musics, sizeof(char), len, file);
	printf_s("Print Duration: ");
	scanf_s("%d", &k);
	fwrite(&k, sizeof(int), 1, file);
	printf_s("Print Rank: ");
	getchar();
	scanf_s("%d", &k);
	fwrite(&k, sizeof(int), 1, file);
}

void sortingName(struct Music* array, int n)
{
	for (int j = 1; j <= n - 1; j++)
		for (int i = n - 1; i >= j; i--)
		{
			if (strcmp(array[i].Name, array[i - 1].Name) < 0)
			{
				struct Music tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
			}
		}
}




void deleteSong(struct Music* array, char* str, int* quantitiSong)

{
	int i;
	int dif = 0;
	for (i = 0; i < *quantitiSong; i++)
	{
		if (strcmp(array[i].Artist, str) == 0)
		{

			dif++;

		}

		else if (dif > 0)
			array[i - dif] = array[i];
	}

	*quantitiSong -= dif;
}




void displaysMusic(struct Music* musics, FILE* file, int quantitiSong)
{
	for (int i = 0; i < quantitiSong; i++)
	{
		musics[i] = rereading(file);
		outputResult(&musics[i]);
	}
}

void resultSorting(struct Music* song, FILE* file, int quantitiSong)
{
	printf("--------------------------");
	printf("\nresult after soting:\n");
	printf("--------------------------\n");
	for (int i = 0; i < quantitiSong; i++)
	{
		outputResult(&song[i]);
		fprintf(file, "%s%s%d\n%d\n", song[i].Name, song[i].Artist, song[i].Duration, song[i].Rank);
	}

}

void resultDeleted(struct Music* song, FILE* file, int quantitiSong)
{
	for (int i = 0; i < quantitiSong; i++)
		fprintf(file, "%s%s%d\n%d\n", song[i].Name, song[i].Artist, song[i].Duration, song[i].Rank);
}