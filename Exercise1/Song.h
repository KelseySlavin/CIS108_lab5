#pragma once

enum Genre		//have to make the "genre" function before you can call it at the bottom
{
	blues = 0,
	country,
	electronic,
	folk,
	hip_hop,
	jazz,
	latin,
	pop,
	rock
};

const int MAX_CHARS_PER_TITLE = 64;
const int MAX_CHARS_PER_ARTIST = 64;
const int MAX_CHARS_ALBUM = 64;


struct Song
{
	char title[MAX_CHARS_PER_TITLE];
	char artist[MAX_CHARS_PER_ARTIST];
	char album[MAX_CHARS_ALBUM];
	unsigned int track;
	unsigned int year;
	Genre genre;
};

