#ifndef JNICKG_MUSICLIB
#define JNICKG_MUSICLIB

#include "Song.h"
#include "List.h"
#include "TreeSet.h"
#include "Playlist.h"

namespace jnickg { namespace adt {
#ifndef JNICKG_ADT_BSTSTRUCT
#define JNICKG_ADT_BSTSTRUCT
template <class T> struct bst_node
{
	T data;
	node<T>* left;
	node<T>* right;
};
#endif // JNICKG_ADT_BSTSTRUCT
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

	// Creates an empty playlist with a title
	int createPlaylist(char * playlist);

	// Adds song to existing playlist or creates a new one and adds song to it
	int addtoPlaylist(Song & song, char* playlist);

	// Searches for artist and copies existing albums to result
	int getByArtist(char* artist, jnickg::adt::List<Song> & result);
	// Searches for album and copies existing songs to result
	int getByAlbum(char* album, jnickg::adt::List<Song> & result);
	// Searches for a playlist and copies existing songs to result
	int getByPlaylist(char * playlist, jnickg::adt::List<Song> & result);
private:
	char* name;

	/* Hash Tables */
	jnickg::adt::TreeSet<Song> songs;
	jnickg::adt::TreeSet<Playlist> playlists;
};

#endif
