#include "MusicLib.h"

MusicLib::MusicLib(void)
{
	name = NULL;
}

// Delete everything
MusicLib::~MusicLib(void)
{
	if(name) delete name;
}

// Copies the song's data to a new song and inserts it into the
// music library
int MusicLib::cpyToLib(Song & nSong)
{
	return songs.add(nSong);
}

int MusicLib::createPlaylist(char* playlist)
{
	Playlist nPlay(playlist);
	return playlists.add(nPlay);
}

int MusicLib::addtoPlaylist(Song & song, char* playlist)
{
	int rtn = 0;
	Playlist pl(playlist);
	if(playlists.contains(pl)) // pulls playlist if existent
		rtn = 1; // playlist did not need to be added
	pl.addSong(song); // add song
	playlists.put(pl); // [re-]insert playlist w/ new song
	return rtn;
}


// Searches for artist and copies existing albums to result
int MusicLib::getByArtist(char* artist, jnickg::adt::List<Song> & result)
{

}

// Searches for album and copies existing songs to result
int MusicLib::getByAlbum(char* album, jnickg::adt::List<Song> & result)
{

}

// Searches for playlist and copies existing songs to result
int MusicLib::getByPlaylist(char* playlist, jnickg::adt::List<Song> & result)
{

}

