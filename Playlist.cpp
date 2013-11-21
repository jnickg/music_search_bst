#include "Playlist.h"

// Default constructor
Playlist::Playlist(void)
{
	title = NULL;
}

// Gives the Playlist a title
Playlist::Playlist(char* t)
{
	title = new char[strlen(t) + 1];
	strcpy(title, t);
}

// Default destructor
Playlist::~Playlist(void)
{
	delete title;
	title = NULL;
}

int Playlist::setTitle(char* t)
{
	if(title) delete title;
	title = new char[strlen(t) + 1];
	strcpy(title, t);
	return 1;
}

int Playlist::retrieve(char* name, Playlist & found)
{
	if(0==strcmp(title, name))
	{
		found = *this;
		return 1;
	}
	else return 0;
}

// Copies this's title to ttl
int Playlist::getTitle(char * & ttl) const
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

int Playlist::getSongs(jnickg::adt::List<Song> & rtn) const
{
	jnickg::adt::List<Song> r;
	int worked = songs.toList(r);
	rtn = r;
	return worked;
}

// Adds a song to the Playlist
int Playlist::addSong(const Song & song)
{
	songs.add(song);
}

// Copies to ts a string representation of the instance
int Playlist::toStr(char * & ts) const
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
std::ostream& Playlist::print(std::ostream & out) const
{
	out << "Playlist: " << title << std::endl;
	out << "SONGS:" << std::endl;
	songs.print(out);
	return out;
}

Playlist& Playlist::operator=(const Playlist & right)
{
	if(title) delete title;
	title = new char[strlen(right.title) + 1];
	strcpy(title, right.title);

	songs = right.songs;
	return *this;
}

bool Playlist::operator<(const Playlist & right) const
{
	if(strcmp(title, right.title) < 0) return true;
	else return false;
}

bool Playlist::operator>(const Playlist & right) const
{
	if(strcmp(title, right.title) > 0) return true;
	else return false;
}

bool Playlist::operator==(const Playlist & right) const
{
	if (strcmp(title, right.title)==0) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& out, const Playlist* const playlist)
{
	playlist->print(out);
	return out;
}
