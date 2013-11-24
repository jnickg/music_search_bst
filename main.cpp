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

	std::cout << "Creating two playlists: \'Easy grooves\' and \'Pop music\'." << std::endl;
	m.createPlaylist("Pop music");
	m.createPlaylist("Easy grooves");

	std::cout << "\n\n\nADDING SONGS!\n\n" << std::endl;

	std::cout << "\nCreating new song: Thriller, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Thriller", "Michael Jackson", "Thriller", 507);
	std::cout << &tmpS << std::endl;
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Thriller\' to two playlists: \'Pop music\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");

	std::cout << "\n\nCreating new song: Wanna Be Startin\' Somethin\', by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Wanna Be Startin\' Somethin\'", "Michael Jackson", "Thriller", 185);
	std::cout << &tmpS << std::endl;
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \"Wanna Be Startin\' Somethin\'\" to two playlists: \'Pop music\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");


	std::cout << "\n\nCreating new song: Beat It, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("Beat It", "Michael Jackson", "Thriller", 221);
	std::cout << &tmpS << std::endl;
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Beat It\' to two playlists: \'Pop music\' and \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	m.addtoPlaylist(tmpS, "Pop music");

	std::cout << "\n\nCreating new song: ABC 123, by Michael Jackson" << std::endl;
	tmpS.setSongFrom("ABC 123", "Michael Jackson", "The Jackson 5", 260);
	std::cout << &tmpS << std::endl;
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);

	std::cout << "\n\nCreating new song: Hotel California, by Eagles" << std::endl;
	tmpS.setSongFrom("Hotel California", "Eagles", "Eagles Greatest Hits", 313);
	std::cout << &tmpS << std::endl;
	std::cout << "Copying Song to the music library" << std::endl;
	m.cpyToLib(tmpS);
	std::cout << "Adding \'Hotel California\' to:  \'Easy grooves\'" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");
	std::cout << "Adding \'Hotel California\' to:  \'Easy grooves\' AGAIN (should only show up once)" << std::endl;
	m.addtoPlaylist(tmpS, "Easy grooves");

	std::cout << "\n\n\nATTEMPTING TO READ FROM LIBRARY\n\n" << std::endl;

	std::cout << "\n\nTrying to pull songs by Michael Jackson..." << std::endl;
	if(m.getByArtist("Michael Jackson", tmpL))
	{
		std::cout << "Attempting to print the pulled list of songs by Michael Jackson.\n" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tPull somehow failed!" << std::endl;

	std::cout << "\n\nTrying to pull songs from album: \'Thriller\'" << std::endl;
	if(m.getByAlbum("Thriller", tmpL))
	{
		std::cout << "Attempting to print the pulled album \'Thriller\'\n" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tPull somehow failed!" << std::endl;

	std::cout << "\n\nTrying to pull songs from playlist: \'Easy grooves\'" << std::endl;
	if(m.getByPlaylist("Easy grooves", tmpL))
	{
		std::cout << "Attempting to print the pulled playlist \'Easy grooves\'\n" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tPull somehow failed!" << std::endl;

	std::cout << "\n\nTrying to pull songs from non-existent playlist: \'Speedcore\' (nobody likes speedcore)" << std::endl;
	if(m.getByPlaylist("Speedcore", tmpL))
	{
		std::cout << "Failure check failed.\nAttempting to print the pulled playlist \'Speedcore\'" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tFailure check succeeded. Nobody likes Speedcore." << std::endl;

	std::cout << "\n\nTrying to pull songs from non-existent album: \'Making Mirrors\' (nobody REALLY likes Gotye)" << std::endl;
	if(m.getByAlbum("Making Mirrors", tmpL))
	{
		std::cout << "Failure check failed.\nAttempting to print the pulled album \'Making Mirrors\'" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tFailure check succeeded. Nobody likes Gotye." << std::endl;


	std::cout << "\n\nTrying to pull songs by non-existent artist Robin Thickie (you call that art?)" << std::endl;
	if(m.getByArtist("Robin Thickie", tmpL))
	{
		std::cout << "Failure check failed.\nAttempting to print the pulled list of songs by Robin Thickie" << std::endl;
		tmpL.print(std::cout);
	}
	else std::cout << "\tFailure check succeeded. Nobody likes Robin Thickie." << std::endl;


	std::cout << "\n\n\nEND UNIT TESTING.\nTERMINATING PROGRAM.\n" << std::endl;

	return 0;
}
