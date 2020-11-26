/************************************************************************//**
 * @file                                                                        
 ***************************************************************************/

#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

#ifndef __MUSICLIST__H__
#define __MUSICLIST__H__
/*!
* @brief allows easy manipulation to list in terms of artist and album
*/
class musicList
{
 public:
     musicList();
     ~musicList();
     bool insertCD( string artistName, string albumName, string songList);
     bool removeCD( string artistName, string albumName);
     bool findArtist( string artistName, bool partial = false);
     bool findAlbum( string albumName, bool partial = false);
     int countAlbums();
     int countSongs();
     void outputCollection(ostream &out );
     void outputCDs( ostream &out );
     void printMenu();

     
 private:
     void parseSongs(list<string> &songs, string songList);
 /*!
  * @brief this struct hold the info for each CD and the address of the next CD
  */
     struct node
     {
         string artist;/*!<the name of the artist */
         string album;/*!<the name of the album*/
         list<string> songs;/*!<the string that holds the song names*/
         node *next;/*!<points to the next items in the list*/
     };
    node *headptr;/*!<the pointer to the first items in the list*/
    

    
};
#endif
