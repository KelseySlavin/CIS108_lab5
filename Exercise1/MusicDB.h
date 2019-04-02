#pragma once

#include "Song.h"
#include <iostream>
#include <string>

using namespace std;


namespace MusicDB
{
	//add a song to the database
	void addsong(Song song);

	//returns the total number of songs in the database
	int gettotalsongs();

	//returns a song from the database by index
	Song getsong(int index);

	//load sing daabase from file
	void loadsongsfromfile(string filename);

	//save the song database to the file
	void savesongtofile (string filename);



}