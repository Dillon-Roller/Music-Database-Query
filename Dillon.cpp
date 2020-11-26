/*************************************************************************//**
 * @file
 * @brief All function done by Dillon Roller. Contains constructor,
 * destructor, insertCD, output CDs, output collection and parsesongs
 *****************************************************************************/

#include "CSC215DB.h"
#include "musicList.h"

/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * Constructor for the program. Initializes headptr for that music list.
 *
 ****************************************************************************/

musicList::musicList()
{
    headptr = nullptr;
}

/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * Destructor for the program. Cleans up the music list when the program
 * ends. It traverses the music list and deletes each individual node until
 * it's empty
 *
 ****************************************************************************/
musicList::~musicList()
{   
    node* temp = headptr;
    while ( headptr != nullptr ) 
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr;
    }
}

/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * This function takes in the artist, album, and list of songs, and adds them
 * to a new node that is then inserted into the music list. 
 *
 * @param[in]  artistName - artist's name
 * @param[in]  albumName -  album's name
 * @param[in]  songList - list of songs seperated by commas
 * 
 * @return false - dynamic allocation of node failed and info was not inserted
 * @returns true - successfully inserted into list
 *
 ****************************************************************************/

bool musicList::insertCD( string artistName, string albumName, string songList ) 
{
    node* newnode = new(nothrow)node;
    //dynamic allocation failed
    if ( newnode == nullptr )
        return false;

    node *cur = headptr, *prev = headptr;
    newnode->next = nullptr;
    newnode->artist = artistName;
    newnode->album = albumName;
    parseSongs( newnode->songs, songList );
    //empty
    if ( headptr == nullptr ) 
    {
        headptr = newnode;
        return true;
    }
    //comes before first
    if ( newnode->artist < headptr->artist ) 
    {
        newnode->next = headptr;
        headptr = newnode;
        return true;
    }
    //if artists are same, compare artists
    if ( newnode->artist == headptr->artist ) 
    {
        if ( newnode->album <= headptr->album ) 
        {
            newnode->next = headptr;
            headptr = newnode;
            return true;
        }
    }
    //find appropriate spot
    while( cur != nullptr && newnode->artist > cur->artist ) 
    {
        prev = cur;
        cur = cur->next;
    }
    while ( cur != nullptr && newnode->artist == cur->artist && 
        newnode->album > cur->album ) 
    {
        prev = cur;
        cur = cur->next;
    }
    newnode->next = cur;
    prev->next = newnode;
    return true;
}

/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * Outputs all the artists and albums in alphabetical order to a stream that 
 * is passed in
 *
 * @param[in]  out - output stream to output data to
 * 
 ****************************************************************************/
void musicList::outputCDs( ostream &out ) 
{
    node *temp = headptr;
    //prints out just the artist and album for each node in list
    while ( temp != nullptr ) 
    {
        out << temp->artist << " - " << temp->album << endl;
        out << endl;
        temp = temp->next;
    }
}
/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * Outputs entire collection in alphabetical order to output stream
 *
 * @param[in]  out - output stream to output data to
 *
 ****************************************************************************/
void musicList::outputCollection( ostream &out ) 
{
    node *temp = headptr;
    //iterator for stl list
    list<string>::iterator i; 
    //prints out info in nodes
    while ( temp != nullptr ) 
    {
        out << temp->artist << " - " << temp->album << endl;
        for ( i = temp->songs.begin(); i != temp->songs.end(); ++i )
            out << "      " << *i << endl;
        out << endl;
        temp = temp->next;
    }
}

/*************************************************************************//**
 * @author Dillon Roller
 *
 * @par Description:
 * This function parses the CSL of songs and put them into the stl song list
 *
 * @param[in]  songs - STL list that will hold all the songs for each album
 * @param[in]  songList - c++ string that holds the all the songs seperated
 *                         by commas
 *
 ****************************************************************************/
void musicList::parseSongs( list<string> &songs, string songList ) 
{
    int beg = 0;
    int i;
    //goes through list of songs
    for ( i = 0; i < songList.size(); i++ ) 
    {
        //inserts a substr from beginning index to ',' index - 1
        //into the stl list. beginning index is then set to
        // ',' index + 1
        if ( songList[i] == ',' ) 
        {
            songs.push_back( songList.substr( beg, i - beg ) );
            beg = i + 1;
        }
    }
    //adds last song in CSL to stl list
    songs.push_back( songList.substr( beg ) );
    //sorts songs lexicographically
    songs.sort();
}