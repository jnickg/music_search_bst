#include "Song.h"

// Default constructor
Song::Song(void)
{
	title = NULL;
	artist = NULL;
	album = NULL;
	length = 0;
}

// Adds starter values; no playlists
Song::Song(char* t, char* ar, char* al, int l)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	artist = new char[strlen(ar) + 1];
	strcpy(artist, ar);

	album = new char[strlen(al) + 1];
	strcpy(album, al);

	length = l;
}

// Default destructor
Song::~Song(void)
{
	if(title) delete title;
	title = NULL;
	if(artist) delete artist;
	artist = NULL;
	if(album) delete album;
	album = NULL;
}

// Sets all the data to this, from params
int Song::setSongFrom(char* t, char* ar, char* al, int l)
{
	if(title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);

	if(artist) delete artist;
	artist = new char[strlen(ar) + 1];
	strcpy(artist, ar);

	if(album) delete album;
	album = new char[strlen(al) + 1];
	strcpy(album, al);

	length = l;

	return 1;
}

// Copies all data to this, from that.
int Song::copySongFrom(const Song& that)
{
	*this = that;
	return 1;
}

// Copies all data from this, to that.
// Does not copy playlist data.
int Song::copySongTo(Song & that) const
{
	int worked;
	worked = that.setSongFrom(title, artist, album, length/*, playlists*/);
	return 1;
}

// Spits copies to ts a string representation of the instance.
int Song::toStr(char * & ts) const
{
	if(title && artist)
	{
		if(ts) delete ts;
		ts = new char[strlen(title) + strlen(artist) + 1];
		strcat(ts, title);
		strcat(ts, artist);
		strcat(ts, "\n");
		return 1;
	}
	else return 0;
}

// Copies to art the artist of the instance
int Song::getArtist(char * & art) const
{
	if(artist)
	{
		if(art) delete art;
		art = new char[strlen(artist) + 1];
		strcpy(art, artist);
		return 1;
	}
	else return 0;
}

// Copies to alb the album of the instance
int Song::getAlbum(char * & alb) const
{
	if(album)
	{
		if(alb) delete alb;
		alb = new char[strlen(album) + 1];
		strcpy(alb, album);
		return 1;
	}
	else return 0;
}

int Song::retrieve(char* srch, Song & rtn) const
{
	// Searches through all of Song's data for a match
	if(retTitle(srch, rtn) | retArtist(srch, rtn) | retAlbum(srch, rtn))
		return 1;
	else return 0;
}

int Song::retTitle(char* tit, Song & rtn) const
{
	if(strcmp(tit, title)==0)
	{
		rtn.setSongFrom(title, artist, album, length);
		return 1;
	}
	else return 0;
}

int Song::retArtist(char* art, Song & rtn) const
{
	if(strcmp(art, artist)==0)
	{
		rtn.setSongFrom(title, artist, album, length);
		return 1;
	}
	else return 0;
}

int Song::retAlbum(char* alb, Song & rtn) const
{
	if(strcmp(alb, album)==0)
	{
		rtn.setSongFrom(title, artist, album, length);
		return 1;
	}
	else return 0;
}

	
// Prints all data
std::ostream& Song::print(std::ostream & out) const
{
	out << "SONG:" << std::endl;
	out << "title:\t" << title << std::endl;
	out << "artist:\t" << artist << std::endl;
	out << "album:\t" << album << std::endl;
	out << "length:\t" << length << " sec" << std::endl;
	out << "\n" << std::endl;
}

// Calls copySong
Song& Song::operator=(const Song & right)
{
	right.copySongTo(*this);
	return *this;
}

bool Song::operator<(const Song & right) const
{
	int art, tit, alb; // Compares artist, title, and then album
	art = strcmp(artist, right.artist);
	if(art == 0)
	{
		tit = strcmp(title, right.title);
		if(tit == 0)
		{
			alb = strcmp(album, right.album);
			if(alb == 0) return false;
			else if(alb < 0) return true;
			else return false;
		}
		else if(tit < 0) return true;
		else return false;
	}
	else if(art < 0)
		return true;
	else return false;
}

bool Song::operator>(const Song & right) const
{
	return (right<(*this));
}

bool Song::operator==(const Song & right) const
{
	if((*this) < right) return false;
	else if(right < (*this)) return false;
	else return true;
}

std::ostream& operator<<(std::ostream& out, const Song* const song)
{
	song->print(out);
	return out;
}
