/*************************************************************************//**
 * @file
 * @brief All function created by Sam Coffin are within.
 *****************************************************************************/

#include "CSC215DB.h"
#include "musicList.h"
#include <string>
#include <fstream>


/*************************************************************************//**
 * @author Samuel Coffin
 *
 * @par Description:
 * This function is the menu. It is called once a list is inputed from the
 * database. It handels the rest of the program depending on the option
 * selected. At the top of the menu the number of albums and songs must be
 * displayed.  Then the following menu will be printed.
 *   1)   Print Albums/Cd's" << endl;
 *   2)   Print Albums/Cd's to file" << endl;
 *   3)   Print collection" << endl;
 *   4)   Print collention to file" << endl;
 *   5)   Find Artist" << endl;
 *   6)   Find album / cd" << endl;
 *   7)   Find partial artist" << endl;
 *   8)   Find partial album / cd" << endl;
 *   9)   Remove album or CD from collection" << endl;
 *   10)   Exit Program" << endl;
 *
 * Option 1 will print albums/cd to terminal window
 * Option 2 will print albums/cd to file
 * Option 3 wil print music collection to terminal window
 * Option 4 will print collection to file\
 * Option 5 will Find a full name artist (case sensitive)
 * Option 6 will Find a full album name (case sensitive)\
 * Option 7 will find all the artists with a partial name
 * Option 8 will find all the albums with a partial name\
 * Option 9 will remove a artist/album from the collection
 * Option 10 will clean up and exit the program
 ****************************************************************************/
void musicList::printMenu( )
{
    // The menu choice
    int choice;
    // The number of Songs in linked list
    int songs = 0;
    // The number of Albums in the linked list
    int albums = 0;
    // The following two parameters are used if searching for album/artist
    string albumName;
    string artistName;
    // Output File Name
    string fileName;
    // These are used for the find functions.
    bool partial = false;
    bool found = false;
    ofstream fout;
    
    //Menu
    do
    {
        songs = countSongs();
        albums = countAlbums();
        // Outputs the amount of albums and songs
        cout << "cd/songs" << setw ( 10 ) << albums << "/" << songs << endl;
        cout << " 1)   Print Albums/Cd's" << endl;
        cout << " 2)   Print Albums/Cd's to file" << endl;
        cout << " 3)   Print collection" << endl;
        cout << " 4)   Print collention to file" << endl;
        cout << " 5)   Find Artist" << endl;
        cout << " 6)   Find album / cd" << endl;
        cout << " 7)   Find partial artist" << endl;
        cout << " 8)   Find partial album / cd" << endl;
        cout << " 9)   Remove album or CD from collection" << endl;
        cout << "10)   Exit Program" << endl;
        cout << "Option: ";
        cin >> choice;
        cin.clear(); // clears flag
        // This ignors the carrage return so the getline command work correctly
        cin.ignore ( 1 );
        cout << endl;
        
        switch ( choice )
        {
            // This case will output the CD's to the terminal
            case 1:
                outputCDs ( cout );
                break;
                
            // This will output the CD's to a file.
            case 2:
                cout << "Enter Your Filename: ";
                getline ( cin, fileName );
                fout.open ( fileName );
                
                // Checks checks if the file does not open
                if ( !fout )
                {
                    cout << "File did not open" << endl;
                    break;
                }
                
                outputCDs ( fout );
                fout.close();
                break;
                
            // Outputs Collection to terminal
            case 3:
                outputCollection ( cout );
                break;
                
            // Outputs Collection to a file
            case 4:
                cout << "Enter Your Filename: ";
                getline ( cin, fileName );
                fout.open ( fileName );
                
                // Makes sure file opened
                if ( !fout )
                {
                    cout << "File did not open" << endl;
                    break;
                }
                
                outputCollection ( fout );
                fout.close();
                break;
                
            // Searches for full artist name and outputs to screen
            case 5:
                cout << "Artist Name: ";
                getline ( cin, artistName );
                
                if ( !findArtist ( artistName, partial ) )
                {
                    cout << "Unable to match full artist name" << endl;
                }
                
                break;
                
            // Searches for full Album Name outputs to screen
            case 6:
                cout << "Album Name: ";
                getline ( cin, albumName );
                
                if ( !findAlbum ( albumName, partial ) )
                {
                    cout << "Unable to match full album name" << endl;
                }
                
                break;
                
            // Searches for partial artist Name outputs to screen
            case 7:
                cout << "Enter partial artist name: ";
                getline ( cin, artistName );
                
                if ( !findArtist ( artistName, partial = true ) )
                {
                    cout << "Unable to match partail artist name" << endl;
                }
                
                break;
                
            // Searches for partial album Name outputs to screen
            case 8:
                cout << "Enter partial album name: ";
                getline ( cin, albumName );
                
                if ( !findAlbum ( albumName, partial = true ) )
                {
                    cout << "Unable to match partial album name" << endl;
                }
                
                break;
                
            // prompt for full artist and album name and removes from list
            case 9:
                cout << "Enter full artist name: ";
                getline ( cin, artistName );
                
                // Checks to make sure artist exists
                if ( !findArtist ( artistName, partial ) )
                {
                    cout << "Did not find specific artist to remove" << endl;
                    break;
                }
                
                cout << "Enter full album name: ";
                getline ( cin, albumName );
                
                // checks to make sure album exists
                if ( !findAlbum ( albumName, partial ) )
                {
                    cout << "Did not find specific album to remove" << endl;
                    break;
                }
                
                // removes artist and album if above conditions are true
                removeCD ( artistName, albumName );
                break;
                
            case 10:
            
                // will increment through linked list till headptr = nullptr
                while ( headptr != nullptr )
                {
                    artistName = headptr ->artist;
                    albumName = headptr ->album;
                    removeCD ( artistName, albumName );
                }
                
                break;
                
            default:
                cout << "Not a proper choice. Please try again" << endl;
                break;
        }
        
        
        cout << endl;
    }
    while ( choice != 10 );
    
    return ;
    
}

/*************************************************************************//**
 * @author Samuel Coffin
 *
 * @par Description:
 * This function will find a full or partial album name.  Once called from
 * the menu it will search the linked list for the album name. It is case
 * sensitive. If the album is found it will output both the artist and album
 * name to the terminal. If not found it will return a false
 *
 *
 * @param[in]  albumName - This is the album name that is requested.
 * @param[in]  partial -  If true the function will search for partial album
 *
 * @return success - success returns true if album found false if not found
 *
 ****************************************************************************/
bool musicList::findAlbum ( string albumName, bool partial )
{

    node *temp = headptr;
    string Name;
    // this is used to determine if album was found
    bool success = false;
    
    // looks for full and partial through entire linked list
    while ( temp != nullptr )
    {
    
        // looks for full album and outputs to terminal window
        if ( !partial && temp ->album == albumName )
        {
            cout << "artist: " << temp ->artist << endl;
            cout << "album: " << temp ->album  << endl;
            cout << endl;
            success = true;
        }
        
        // looks for part album and outputs to terminal window
        else if ( partial && temp ->album.find ( albumName ) != string::npos )
        {
            cout << "artist: " << temp ->artist << endl;
            cout << "album: " << temp ->album   << endl;
            cout << endl;
            success = true;
        }
        
        temp = temp ->next;
    }
    
    return success;
    
}

/*************************************************************************//**
 * @author Samuel Coffin
 *
 * @par Description:
 * This function simply counts the number of songs that are in the linked list
 * It is accomplished by creating a temp pointer and iterivaly counts the songs
 * in each album.  Once completed the function will return the number of songs
 *
 * @return numberSongs -- returns number of Songs
 ****************************************************************************/
int musicList::countSongs()
{
    // keeps track of number songs
    int numberSongs = 0;
    node *temp = headptr;
    
    // this will increment through linked list
    while ( temp != nullptr )
    {
        // counts the number of songs in each node
        for ( list<string>::iterator i = temp->songs.begin(); i
                != temp->songs.end();
                ++i )
        {
            numberSongs = numberSongs + 1;
        }
        
        temp = temp -> next;
    }
    
    // simply returns number of songs.
    return numberSongs;
}



