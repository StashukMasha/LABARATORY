#include"Header.h"

struct Music rereading(FILE* file)
{
	struct Music songs;
	fgets(songs.Name, LENGTH, file);
	fgets(songs.Artist, LENGTH, file);
	fscanf_s(file, "%d", &songs.Duration);
	fscanf_s(file, "%d", &songs.Rank);
	fgetc(file);
	return songs;
}

void outputResult(struct Music* musics)
{
	printf("Name: %s", (*musics).Name);
	printf("Artist: %s", (*musics).Artist);
	printf("Duration: %d\n", (*musics).Duration);
	printf("Rank: %d\n", (*musics).Rank);
	//printf("\n");
}

void AddMusic(FILE* file)
{
	char musics[LENGTH];
	int k;
	printf_s("Print Name: ");
	getchar();
	fgets(musics, LENGTH, stdin);
	fprintf(file, "%s", musics);
	printf_s("Print Artist: ");
	getchar();
	fgets(musics, LENGTH, stdin);
	fprintf(file, "%s", musics);
	printf_s("Print Duration: ");
	scanf_s("%d", &k);
	fprintf(file, "%d", k);
	printf_s("Print Rank: ");
	getchar();
	scanf_s("%d", &k);
	fprintf(file, "\n%d", k);
}

void sortingName(struct Music* array, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (strcmp(array[i].Name, array[i - 1].Name) > 0)
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

		if (dif > 0)
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