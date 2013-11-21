#ifndef JNICKG_MUSICLIB
#define JNICKG_MUSICLIB

#include "Song.h"
#include "Album.h"
#include "List.h"
#include "TreeSet.h"

namespace jnickg { namespace adt {
#ifndef BSTSTRUCT
#define BSTSTRUCT
template <class T> struct bst_node
{
	T data;
	node<T>* left;
	node<T>* right;
};
#endif // BSTSTRUCT
}} // end namespace

/* MUSIC LIBRARY
MusicLib.h
Nick Giampietro | jnickg
giampiet@pdx.edu
Created 10 Nov 2013

This class contains a music library and allows
for retrieval by either album name or artist name.

It can automatically add new songs as well.
*/
class MusicLib
{
public:
	// Default constructor
	MusicLib(void);
	// Default destructor
	~MusicLib(void);

	// Copies the song's data to a new song and inserts it into the
	// music library
	int cpyToLib(Song & nSong);



	// Searches for artist and copies existing albums to result
	int getByArtist(char* artist, jnickg::adt::List<Song> & result);

	// Searches for album and copies existing songs to result
	int getByAlbum(char* album, Album & result);
private:
	int artS; // size of the artist table
	int albS; // size of the album table
	/* Hash Tables */
	jnickg::adt::TreeSet<Song> songs;
	
	// Hashes the string input in a standard way.
	int hash(char* str);

	// Adds nSong to artistTable; chains if needed
	int addByArtist(char* artist, Song & nSong);

	// Adds nSong to albumTable; chains if needed
	int addByAlbum(char* album, Song & nSong);
};

#endif
