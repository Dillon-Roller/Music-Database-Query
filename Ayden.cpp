/*************************************************************************//**
 * @file
 * @brief All function done by Ayden Drabek. Functions include countAlbums,
 *  removeCD, and findArtist.
 *****************************************************************************/
#include "CSC215DB.h"
#include "musicList.h"

/**************************************************************************//**
  
 * @author Ayden Drabek
 *
 * @par Description: 
 *  countAlbum goes through the linked listed counting how many different 
 *  albums there are. Once it has gone through the whole list it returns the 
 *  number of albums it has found.
 * 
 *
 * @returns albumcount - number of albums in the list
 *
 *****************************************************************************/
int musicList::countAlbums()
{
    int albumcount = 0;
    node *temp = headptr;
    
    while ( temp != nullptr )
    {
        albumcount = albumcount + 1;
        temp = temp -> next;
    }
    
    return albumcount;
    
}
/**************************************************************************//**
 * @author Ayden Drabek
 *
 * @par Description: 
 *  findArtist searches through the linked list looking for the artist that is 
 *  specified by the user. 
 *
 * @param[in]  artistName is passed in so the function knows what artist it is 
 *             trying to find in the list.
 * @param[out] partial is passed in to let the function know if the name being
 *             passed in is a full name ( partial = true ) or only part of a 
 *             name ( partial = false ).
 *
 * @returns true if the artist name was found in the list.
 * @returns false if the artist name was not found in the list.
 *
 *****************************************************************************/
bool musicList::findArtist ( string artistName, bool partial )
{
    bool found=false;
    node *temp = headptr;
    //walks through the list 
    while ( temp != nullptr )
    {
        //checks to see if name is a partial and if its found
        if ( partial == true && temp ->artist.find ( artistName )!=string::npos)
        {
            cout << "artist :" << temp ->artist <<endl;
            cout<<"album :"<< temp ->album << endl;
            found=true;
        }
        //checks to see if name is a full name and if it found
        else if ( partial == false && temp ->artist == artistName )
        {
            cout << "artist :" << temp ->artist <<endl;
            cout<<"album :"<< temp ->album << endl; 
            found=true;
        }
        
        temp = temp ->next;
    }
    if(found==true)
    {
        return true;
    }
    return false;
}
/**************************************************************************//**
 * @author Ayden Drabek
 *
 * @par Description:  
 *  remove CD first check to make sure the list isnt already empty if it is 
 *  returns. If it is not it check to see if the CD that the user wishs to 
 *  remove is in the front of the list if it is it checks to see if its the 
 *  last item and removes it. If its not the first item it traverses through 
 *  the list looking for the CD. Once it is found or the end of the list is 
 *  reached it checks to see if the artist and album are correct and deletes them.
 *
 * @param[in]  artistName is passed in so the function knows what artist it is 
 *             trying to remove from the list.
 * @param[out] albumName is passed in so the function knows what artist it is 
 *             trying to remove from the list.
 *
 * @returns true if the artist name was found in the list.
 * @returns false if the artist name was not found in the list.
 *
 *****************************************************************************/
bool musicList::removeCD ( string artistName, string albumName )
{
    //allocates newnode
    node *newnode = nullptr;
    newnode = new ( nothrow ) node;
    if ( newnode == nullptr )
    {
        return false;
    }
    
    node *cur = headptr, *prev = headptr;
    //sets newnode values equal to passed in values
    newnode->next = nullptr;
    newnode->artist = artistName;
    newnode->album = albumName;
    
    //remove from empty list
    if ( headptr == nullptr )
    {
        cout << "Empty";
        return true;
    }
    
    //front and last item
    if ( artistName == headptr->artist && albumName == headptr->album )
    {
        //last item
        if ( headptr->next == nullptr )
        {
            headptr = nullptr;
            delete newnode;
            return true;
        }
        
        headptr = headptr->next;
        delete newnode;
        return true;
        
    }
    
    //searches for artist and album(traversal)
    while ( cur != nullptr && artistName > cur->artist )
    {
        prev = cur;
        cur = cur->next;
    }
    
    while ( cur != nullptr && artistName == cur->artist &&
            albumName > cur->album )
    {
        prev = cur;
        cur = cur->next;
    }
    
    //middle/end
    if ( artistName == cur->artist && albumName == cur->album )
    {
        prev->next = cur->next;
        delete cur;
        return true;
    }
    
    
    return false;
}