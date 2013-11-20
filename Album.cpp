#include "Album.h"

// Default constructor
Album::Album(void)
{
	title = NULL;
}

// Gives the album a title
Album::Album(char* t)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);
}

// Default destructor
Album::~Album(void)
{
	delete title;
	title = NULL;
}

int Album::setTitle(char* t)
{
	if(title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);
	return 1;
}

// Used by MusicLib to test if an element in albumTable's
// chain matches the one being requested--if so, copies to
// found and returns 1; if not, returns 0.
int Album::retrieve(char* name, Album & found)
{
	if(0==strcmp(title, name))
	{
		found = *this;
		return 1;
	}
	else return 0;
}

// Copies this's title to ttl
int Album::getTitle(char * & ttl) const
{
	if(title)
	{
		if(ttl) delete ttl;
		ttl = new char[strlen(title) + 1];
		strcpy(ttl, title);
		return 1;
	}
	else return 0;
}

int Album::getSongs(jnickg::adt::List<Song> & sng) const
{
	sng = songs;
}

// Adds a song to the album
int Album::addSong(const Song & song)
{
	songs.add_to_end(song);
}

// Copies to ts a string representation of the instance
int Album::toStr(char * & ts) const
{
	if(title)
	{
		if(ts) delete ts;
		ts = new char[strlen(title) + 1];
		strcpy(ts, title);
		return 1;
	}
	else return 0;
}

// Iterates through songs and prints each
std::ostream& Album::print(std::ostream & out) const
{
	out << "ALBUM: " << title << std::endl;
	out << "SONGS:" << std::endl;
	songs.print(out);
	return out;
}

Album& Album::operator=(const Album & right)
{
	right.getTitle(title);
	right.getSongs(songs);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Album* const album)
{
	album->print(out);
	return out;
}
