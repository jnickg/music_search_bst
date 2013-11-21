#ifndef JNICKG_PLAYLIST
#define JNICKG_PLAYLIST

#include <cstdlib>
#include <cstring>
#include "Song.h"
#include "TreeSet.h"

/* PLAYLIST
Playlist.h
Nick Giampietro | jnickg
giampiet@pdx.edu
Created 10 Nov 2013

This class contains information for a music Playlist:
	The name of the Playlist
	A list of the songs in the playlist
*/

class Playlist
{
public:
	// Default constructor
	Playlist(void);
	// Gives the Playlist a title
	Playlist(char* t);
	// Default destructor
	~Playlist(void);

	int setTitle(char* t);

	int retrieve(char* name, Playlist & found);

	// Copies this's title to ttl
	int getTitle(char * & ttl) const;

	// Copies this's songs to ttl
	int getSongs(jnickg::adt::List<Song> & rtn) const;

	// Adds a song to the Playlist
	int addSong(const Song & song);
	// Spits out a string representation of the Playlist
	int toStr(char * & ts) const;
	// Iterates through songs and prints each
	std::ostream& print(std::ostream & out) const;

	Playlist& operator=(const Playlist & right);
	bool operator==(const Playlist & right) const;
private:
	char* title;
	jnickg::adt::TreeSet<Song> songs; // The songs in the Playlist

	// Invokes the Playlist's print function
	friend std::ostream& operator<<(std::ostream& out, const Playlist* const playlist);

};

std::ostream& operator<<(std::ostream& out, const Playlist* const playlist);

#endif
