#include <fstream>
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

namespace music_database_CRUD
{
	std::string filename = "Mymusic.txt";
	std::string Create_song_entry(music song)
	{
		try
		{
			
			std::ofstream file(filename, ios::app);
			file << song.title <<","<<song.artist<<","<<song.album<<","<<song.track<<","<<song.year<<"\n";
			file.close();
			return "success";
		}
		catch(exception ex)
		{
			return "Something went wrong. Please try again.";
		}

	}
	/*std::string create; 
	std::string line;
	std::ifstream file("myfile.txt");*/

	string read_song ()
	{
		//try
		//{
			string line; 
			std::ifstream file(filename); 
			while (std::getline(file, line)){
			{
				cout << line << '\n';
			}
			return "foo";

		//}
		//catch (exception ex)
		/*{
			return music {"","","",0,0};
		*/}
	}



}




