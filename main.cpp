#include <cstring>
#include <cstdlib>
#include <iostream>
#include "MusicLib.h"


// This implementation of main is simply a test of the data structures implemented
int main(void)
{
	MusicLib m;
	Song tmpS;
	jnickg::adt::List<Song> tmpL;

	m.createPlaylist("Pop music");
	m.createPlaylist("Easy grooves");

	std::cout << "Creating new song: Thriller, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Thriller", "Michael Jackson", "Thriller", 507);
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Thriller\' to two playlists: \'Pop music!\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");

	std::cout << "Creating new song: Wanna Be Startin\' Somethin\', by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Wanna Be Startin\' Somethin\'", "Michael Jackson", "Thriller", 185);
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \"Wanna Be Startin\' Somethin\'\" to two playlists: \'Pop music!\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");


	std::cout << "Creating new song: Beat It, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Beat It", "Michael Jackson", "Thriller", 221);
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Beat It\' to two playlists: \'Pop music!\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");

	std::cout << "Creating new song: ABC 123, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("ABC 123", "Michael Jackson", "The Jackson 5", 260);
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);

	std::cout << "Creating new song: Hotel California, by Eagles" << std::endl;
	tmpS.setSongFrom("Hotel California", "Eagles", "Eagles Greatest Hits", 313);
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Hotel California\' to:  \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");

	std::cout << "Trying to pull songs by Michael Jackson" << std::endl;
	m.getByArtist("Michael Jackson", tmpL);
	std::cout << "Attempting to print the pulled list of songs by Michael Jakcson." << std::endl;
	tmpL.print(std::cout);

	std::cout << "Trying to pull songs from album: \'Thriller\'" << std::endl;
	m.getByAlbum("Thriller", tmpL);
	std::cout << "Attempting to print the pulled album \'Thriller\'" << std::endl;
	tmpL.print(std::cout);

	std::cout << "Trying to pull songs from playlist: \'Easy grooves\'" << std::endl;
	m.getByPlaylist("Easy grooves", tmpL);
	std::cout << "Attempting to print the pulled playlist\'Easy grooves\'" << std::endl;
	tmpL.print(std::cout);

	return 0;
}
