#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define LENGTH 25
#define QUANTITI_OF_SONGS 2

struct Music
{
	char Name[LENGTH];
	char Artist[LENGTH];
	int Duration;
	int Rank;
};

struct Music rereading(FILE* file);
void outputResult(struct Music* musics);
void AddMusic(FILE* file);
void sortingName(struct Music* arr, int q);

void deleteSong(struct Music* arr, char* str, int* quantitiSong);
void displaysMusic(struct Music* musics, FILE* file, int quantitiSong);
void resultSorting(struct Music* song, FILE* file, int quantitiSong);
void resultDeleted(struct Music* song, FILE* file, int quantitiSong);

#endif 

