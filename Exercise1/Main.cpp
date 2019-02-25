#include "Song.h"
#include "MusicDB.h"
#include <iostream>
using namespace std;
int main()
{
	music song = {
		"bye bye bye",
		"NSync",
		"Foo",
		6,
		1994,
	};
	string response = music_database_CRUD::read_song();


	return 0;
}