#include "MusicDB.h"
#include <iostream>
#include <string>

using namespace std;
void menu();				//output the user help menu
Song getsongfromuser();		//calling the song struct from song.h
void listsong();			//list songs in the database
string convertgenretostring(Genre genre); //converts a genre enum to a string
Genre convertstringtogenre(string genre); //converts a string to a genre enum

const string DATABASE_FILE = "music.db";

int main()
{
	//output the menu
	menu();

	//load the songs from the database
	MusicDB::loadsongsfromfile(DATABASE_FILE);
 
	bool should_exit = false;
	while (!should_exit)
	{
		//display the promt
		cout << ">";

		//get command from the user
		string command;
		getline(cin, command);

		if (command == "add")
		{
			Song new_song = getsongfromuser();
			MusicDB::addsong(new_song);
		}
		else if (command == "list")
		{
			//list the songs in the database
			listsong();			
		}
		else if (command == "save")
		{
			MusicDB::savesongtofile(DATABASE_FILE);
		}
		else if (command == "help")
		{
			//display the menu
			menu();
		}
		else if (command == "exit")
		{
			//exit the loop
			should_exit = true;
		}
		else
		{
			cout << "You cannot do that, please try another." << endl;
		}

	}
	return 0;
}

//output the help menu to the user
void menu()
{
	cout << "add: Add a song to the database" << endl;
	cout << "list: List the songs in the database" << endl;
	cout << "save: Saves the songs into the database" << endl;
	cout << "help: Display the help menu" << endl;
	cout << "exit: Exit the program" << endl;
}

//get a new song from user
Song getsongfromuser()
{
	Song song;

	string title;
	cout << "Enter song title: ";
	getline(cin, title);

	string artist;
	cout << "Enter artist: ";
	getline(cin, artist);

	string album;
	cout << "Enter album name: ";
	getline(cin, album);

	unsigned int track;
	cout << "Enter track number: ";
	cin >> track;

	unsigned int year;
	cout << "Enter year: ";
	cin >> year; 

	string genre;
	cout << "Enter genre: ";
	cin.ignore();
	getline(cin, genre);

	strncpy_s(song.title, title.c_str (), MAX_CHARS_PER_TITLE);
	strncpy_s(song.artist, artist.c_str(), MAX_CHARS_PER_ARTIST);
	strncpy_s(song.album, album.c_str(), MAX_CHARS_ALBUM);
	song.track = track;
	song.year = year;
	song.genre = convertstringtogenre(genre);

	return song;

}

void listsong()			//list songs in th database
{
	for (int idx = 0; idx < MusicDB::gettotalsongs(); idx++)
	{
		Song jalapeno = MusicDB::getsong(idx);

		cout << "Title:" << jalapeno.title << endl;
		cout << "Song #:" << idx + 1 << endl;
		cout << "Artist:" << jalapeno.artist << endl;
		cout << "Album:" << jalapeno.album << endl;
		cout << "Track:" << jalapeno.track << endl;
		cout << "Year:" << jalapeno.year << endl;
		cout << "Genre:" << convertgenretostring (jalapeno.genre)<< endl;


	}
}

string convertgenretostring(Genre genre)
{
	string genre_string = "unknown";

	switch (genre)
	{
		case blues:  genre_string = "blues"; break;
		case country: genre_string = "country"; break;
		case electronic: genre_string = "electronic"; break;
		case folk: genre_string = "country"; break;
		case hip_hop: genre_string = "hip hop"; break;
		case jazz: genre_string = "jazz"; break;
		case latin: genre_string = "latin"; break;
		case pop: genre_string = "pop"; break;
		case rock: genre_string = "rock"; break;
	}

	return genre_string;

}

Genre convertstringtogenre(string genre)
{
	Genre genre_enum;

	if (genre == "blues")	genre_enum = blues;
	else if (genre == "country") genre_enum = country;
	else if (genre == "electronic") genre_enum = electronic;
	else if (genre == "folk") genre_enum = folk;
	else if (genre == "hip_hop") genre_enum = hip_hop;
	else if (genre == "jazz") genre_enum = jazz;
	else if (genre == "latin") genre_enum = latin;
	else if (genre == "pop") genre_enum = pop;
	else if (genre == "rock") genre_enum = rock;

	return genre_enum;
}
