#ifndef JNICKG_SONG
#define JNICKG_SONG

#include <cstdlib>
#include <ostream>
#include <cstring>
#include "List.h"

/* SONG
Song.h
Nick Giampietro | jnickg
giampiet@pdx.edu
Created 10 Nov 2013

This class contains information for a song, including:
	Artist that made the song
	Title of song
	Playlists it is in
	Length (seconds)
	Album
*/
class Song
{
public:
	// Default constructor
	Song(void);
	// Adds starter values; no playlists
	Song(char* t, char* ar, char* al, int l);
	// Default destructor
	~Song(void);

	// Adds song to a new playlist
	int addToPlaylist(char* pl);

	// Sets all the data to this, from params
	int setSongFrom(char* t, char* ar, char* al, int l);
	// Sets all the data to this, from params
	int setSongFrom(char* t, char* ar, char* al, int l, jnickg::adt::List<char*> ply);
	// Copies all data to this, from that
	int copySongFrom(const Song& that);
	// Copies all data from this, to that
	int copySongTo(Song & that) const;

	// Spits out a string representation of the instance
	int toStr(char * & ts) const;
	// Copies to art the artist of the instance
	int getArtist(char * & art) const;
	// Copies to alb the album of the instance
	int getAlbum(char * & alb) const;
	// Copies to ply the playlist of the instance
	int getPlaylist(jnickg::adt::List<char*> & ply) const;

	// Prints all data
	std::ostream& print(std::ostream & out) const;
	// Calls copySong
	Song& operator=(const Song & right);

	// Simple boolean comparators--all implemented in terms of operator<
	bool operator<(const Song & right) const;
	bool operator>(const Song & right) const;
	bool operator==(const Song & right) const;
private:
	char* title; // The title of the song
	char* artist; // The artist who made the song
	char* album; // The album the song is in
	//jnickg::adt::List<char*> playlists; // The playlists in which the song appears
	int length; // The length (in seconds) of the song

	// Invokes the Song's print function
	friend std::ostream& operator<<(std::ostream& out, const Song* const song);
};

std::ostream& operator<<(std::ostream& out, const Song* const song);

#endif
