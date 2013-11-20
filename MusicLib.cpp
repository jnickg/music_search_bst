#include "MusicLib.h"

MusicLib::MusicLib(void)
{
	// Starting size is 37 for posterity and great success.
	artS = 37;
	albS = 37;

	int i;

	// Make default-size table for artists
	artistTable = new jnickg::adt::node<jnickg::adt::List<Song > >*[37];
	for(i=0; i<artS; i++) artistTable[i] = NULL;

	// Default-size table for albums
	albumTable = new jnickg::adt::node<Album>*[37];
	for(i=0; i<albS; i++) albumTable[i] = NULL;
}

// Delete everything
MusicLib::~MusicLib(void)
{
	int i;
	for(i=0; i<artS; i++)
	{
		jnickg::adt::node < jnickg::adt::List < Song > > * it = artistTable[i];
		jnickg::adt::node < jnickg::adt::List < Song > > * tmp;
		while(it)
		{
			tmp = it;
			it = it->next;
			delete tmp;
		}
		tmp = NULL;
		it = NULL;
		artistTable[i] = NULL;
	}
	for(i=0; i<albS; i++)
	{
		jnickg::adt::node < Album > * it = albumTable[i];
		jnickg::adt::node < Album > * tmp;
		while(it)
		{
			tmp = it;
			it = it->next;
			delete tmp;
		}
		tmp = NULL;
		it = NULL;
		albumTable[i] = NULL;
	}
}

// Copies the song's data to a new song and inserts it into the
// music library
int MusicLib::cpyToLib(Song & nSong)
{
	int worked = 0;
	// Get artist and album from nSong
	char* art = NULL;
	char* alb = NULL;
	nSong.getArtist(art);
	nSong.getAlbum(alb);

	// Get the artist from nSong & hash it to add to artistTable
	worked += addByArtist(art, nSong);

	// Get the album from nSong & hash it to add to albumTable
	worked += addByAlbum(alb, nSong);

	return worked;
}

// Adds nSong to artistTable; chains if needed
// If there is a collision, iterate through the LLL of List<Song>s
// and check if a list of name "artist" exists; if so, add the song
// when the right one is found or it is realized that a new List of
// name "artist" is needed.
// Returns 0 if there was no collision; 1 if a collision was resolved;
// -1 if there was an error.
int MusicLib::addByArtist(char* artist, Song & nSong)
{
	int h = hash(artist);
	
	// Case 1: Nothing there yet
	if(NULL == artistTable[h%artS])
	{
		artistTable[h%artS] = new jnickg::adt::node<jnickg::adt::List<Song > >;
		artistTable[h%artS]->data.setName(artist);
		artistTable[h%artS]->data.add_to_end(nSong);
		artistTable[h%artS]->next = NULL;
		return 0;
	} // End case 1 if
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		// First check if an artist of this name exists by running getByArtist()
		jnickg::adt::List<Song> tmpL;
		
		int exists = getByArtist(artist, tmpL);
		tmpL.setName(artist);

		if(exists) 
		{
			tmpL.add_to_end(nSong);
			bool got=false;
			// Re-insert tmpL into correct place in hash table
			jnickg::adt::node< jnickg::adt::List < Song > >* tmp = artistTable[h%artS];
			while(tmp)
			{
				got = tmp->data.isname(artist);
				if(got)
				{
					tmp->data = tmpL;
					return 1;
				}
				else 
				{
					tmp = tmp->next;
				}
			}
			return -1;
		}

		else
		{
			// If it doesn't, add to head of chain by holding onto the head and adding one before it
			jnickg::adt::node<jnickg::adt::List<Song > >* tmp = artistTable[h%artS];
			artistTable[h%artS] = new jnickg::adt::node<jnickg::adt::List<Song > >;
			artistTable[h%artS]->data.setName(artist);
			artistTable[h%artS]->data.add_to_end(nSong);
			artistTable[h%artS]->next = tmp;
		}
		return 1;
	} // End case 2 else
}

// Adds nSong to albumTable; chains if needed
// If there is a collision, iterate through the LLL of Albums
// and check if a list of name "album" exists using retrieve;
// if so, add the song to retrieved album; if not, make a new album
// of name "album"
int MusicLib::addByAlbum(char* album, Song & nSong)
{
	int h = hash(album);

	// Case 1: Nothing there yet
	if(NULL == albumTable[h%albS])
	{
		albumTable[h%albS] = new jnickg::adt::node<Album>;
		albumTable[h%albS]->data.setTitle(album);
		albumTable[h%albS]->data.addSong(nSong);
		albumTable[h%albS]->next = NULL;
		return 0;
	}
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		// First check if an album of this name exists by running getByAlbum()
		Album tmpA;
		int exists = getByAlbum(album, tmpA);

		if(exists) 
		{
			tmpA.addSong(nSong);
			int got=0;  // used to see if the correct album to override w/ tmpA was found
			Album trash; // This is not needed except to shut the compiler up; should make new function in Album to just check name
			// Re-insert tmpA into correct place in hash table
			jnickg::adt::node<Album>* tmp = albumTable[h%albS];
			while(tmp)
			{
				got = tmp->data.retrieve(album, trash);
				if(got)
				{
					tmp->data = tmpA;
					return 1;
				}
				else tmp = tmp->next;
			}
			return -1; // Something went wrong.
		}
		else // ALbum did not yet exist; add to head of chain by holding onto the head and adding one before it
		{
			
			jnickg::adt::node<Album>* tmp = albumTable[h%albS];
			albumTable[h%albS] = new jnickg::adt::node<Album>;
			albumTable[h%albS]->data.setTitle(album);
			albumTable[h%albS]->data.addSong(nSong);
			albumTable[h%albS]->next = tmp;
			return 1;
		}
	}
}

// Searches for artist and copies existing albums to result
int MusicLib::getByArtist(char* artist, jnickg::adt::List<Song> & result)
{
	int h = hash(artist);

	// Case 1: Nothing there yet
	if(NULL == artistTable[h%artS])
	{
		return 0;
	}
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		int got=0;
		jnickg::adt::node< jnickg::adt::List < Song > >* tmp = artistTable[h%artS];
		while(tmp)
		{
			got = tmp->data.isname(artist);
			if(got)
			{
				result = tmp->data;
				return 1;
			}
			else tmp = tmp->next;
		}
		return 0;
	}
}

// Searches for album and copies existing songs to result
int MusicLib::getByAlbum(char* album, Album & result)
{
	int h = hash(album);

	// Case 1: Nothing there yet
	if(NULL == albumTable[h%albS])
	{
		return 0;
	}
	// Case 2: Solve collision with chaining even though linear probing would be better
	else
	{
		int got=0;
		jnickg::adt::node<Album>* tmp = albumTable[h%albS];
		while(tmp)
		{
			got = tmp->data.retrieve(album, result);
			if(got) return 1;
			else tmp = tmp->next;
		}
		return 0;
	}
}

// Hashes the string using a simple hash function
int MusicLib::hash(char* str)
{
	//int h = 0;
	//while(*str)
	//{
	//	h = h * 13 + *str++;
	//}
	//return h;
	return 1337;
}

