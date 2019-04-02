#include <fstream>
#include <iostream>
#include <string>
#include "Song.h"
#include <vector>

using namespace std;

namespace MusicDB
{
	//a list of songs managed by MusicDB
	vector<Song> song_list;


	//add song to the database
	void addsong(Song song)
	{
		song_list.push_back(song);
	}

	//return the total number of songs in the database
	int gettotalsongs()
	{
		return song_list.size();
	}

	//returns a song from the database by index
	Song getsong(int index)
	{
		return song_list[index];
	}

	//load sing database from file
	void loadsongsfromfile(string filename)
	{
		//clear the database to make sure that theres nothing in it before we get music
		song_list.clear();

		ifstream ghost(filename, ifstream::binary);
		if (ghost.is_open())
		{
			int total_songs = 0;
			ghost.read((char*)&total_songs, sizeof(int));

			for (int idx = 0; idx < total_songs; idx++);
			{
				Song pepper;
				ghost.read((char*)&pepper, sizeof(Song));
				song_list.push_back(pepper);
			}
			ghost.close();

		}
	}

	//save the song database to the file
	void savesongtofile(string filename)
	{
		ofstream file (filename, ofstream::binary);
		if (file.is_open())
		{
			int total_songs = gettotalsongs();
			file.write((char*)&total_songs, sizeof(int));

			for (int idx = 0; idx < total_songs; idx++)
			{
				Song aligator = getsong(idx);
				file.write((char*)&aligator, sizeof(Song));
			}

			file.close();
		}

	}


}





