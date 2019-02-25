#pragma once

struct music
{
	char title[64];
	char artist[32];
	char album[64];
	int track;
	int year;
};
enum genre
{
	blues=1,
	country,
	electronic,
	folk,
	hip_hop,
	jazz,
	latin,
	pop,
	rock
};
