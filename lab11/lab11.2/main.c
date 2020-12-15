#include"Header.h"

int main()
{
	int number;
	int quantitiSong;
	printf("print quantiti of your song: ");
	scanf_s("%d", &quantitiSong);

	printf("1 - Add music to the end of the file\n");
	printf("2 - Bring out musics\n");
	printf("3 - Sort musics\n");
	printf("4 - Delete music\n");
	printf("5 - Exit\n");

	printf("select number: ");
	scanf_s("%d", &number);

	FILE* file;

	switch (number)
	{
	case 1:
		file = fopen("musics.txt", "a");
		fseek(file, 0, SEEK_END);
		AddMusic(file);
		fclose(file);
		break;

	case 2:
		file = fopen("musics.txt", "r");
		struct Music* musics = (struct Music*)malloc(quantitiSong * sizeof(struct Music));
		displaysMusic(musics, file, quantitiSong);
		rewind(file);
		fclose(file);
		free(musics);
		break;

	case 3:
		file = fopen("musics.txt", "r+");
		struct Music* song = (struct Music*)malloc(quantitiSong * sizeof(struct Music));
		displaysMusic(song, file, quantitiSong);
		sortingName(song, quantitiSong);
		rewind(file);
		resultSorting(song, file, quantitiSong);
		free(song);
		fclose(file);
		break;

	case 4:
		file = fopen("musics.txt", "r+");
		struct Music* songs = (struct Music*)malloc(quantitiSong * sizeof(struct Music));
		displaysMusic(songs, file, quantitiSong);
		char deleteArtist[LENGTH];
		getchar();
		printf("Print name of artist which song you want to delete: ");
		fgets(deleteArtist, LENGTH, stdin);
		deleteSong(songs, deleteArtist, &quantitiSong);
		rewind(file);
		resultDeleted(songs, file, quantitiSong);
		free(songs);
		fclose(file);
		break;

	case 5:
		printf("finish");
		break;
	}
	
	return 0;
}
