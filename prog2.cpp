/*************************************************************************//**
 * @file
 *
 * @mainpage Program 2 - Music Database Query
 *
 * @section course_section Course Information
 *
 * @authors Samuel Coffin
 * @authors Ayden Drabek
 * @authors Dillon Roller
 *
 * @date October 30, 2017
 *
 * @par Professor:
 *      Schrader, Roger
 *
 * @par Course:
 *         CSC215 - Section 1 - 1:00pm
 *
 * @par Location:
 *         Mineral Industry M222 (MWF), Electrical Engineering EEP254
 *
 * @section program_section Program Information
 *
 * @details Most of the below information comes straight from the Program 2
 * write up. WhWhen your program starts up, you will retrieve all the music data 
 * from the MySQL databasent.  Your first prompt will allow you to select which
 * table you pull your data from. These tables will be pre-populated.  The 
 * number will preselect a SQL statement that pulls all the data from the 
 * database.  These sql statements are pre- written and have constant c strings 
 * declared in csc215db.h. 
 *
 * The program is run with no command arguments.  If an integer is not within
 * the ramge of 0-7 inclusive, an output message will appear and exit the 
 * program. The following options are available for selection
 * 0. selects a table with no data
 * 1. selects a table with a single CD for data
 * 3. selects a table with many records always inserting at the front of list
 * 4. selects a table with many records that focus on insertion in middle of list
 * 5. selects table that contains almost all music jumbled up
 * 6. selects small sample of music. These options are jumbled up
 * 7. selectts table that is combined of 5 & 6. Thes options are jumbled up.
 * 
 * The linked list is already defined and will satisfy all the querying the music
 * There is one linked list header file and three source files each labeled with
 * team member names. MusicList.h will contain the class defenition for linked 
 * list. Several functions are requred in order to complete the program.
 *
 * The following functions are requried and taken from the program write up.
 *
 * musicList – sets up an empty list.*
 *
 * ~musicList – cleans up the dynamically allocated nodes in the linked list.
 *
 * insertCD – this function will insert a node that represents a CD.  This
 * function returns true if it was successfully inserted false otherwise. All 
 * nodes will be in ascending order based on the artist name then the album name. 
 * It has three arguments in the following order: the artist name, the album 
 * name, and a comma separated list of all songs found on the Album / CD.
 *
 * removeCD – this function will remove a node from the linked list that matches
 * the name and album supplied. A value of true will be returned if a node was 
 * removed and a value of false if it didn’t find the node to be removed. It has
 * two arguments in the following order: the artist name, the album name and an 
 * exact match must occur on both values for the CD to be removed from the 
 * collection.  You do not need to worry about removing the CD from the database.
 *
 * searchArtists – this function will traverse the list searching for a CD 
 * artist that matches the first parameter, the artistname.  This is a case
 * sensitive search.  The default is to do full match on the name. This behavior
 * can be changed by passing in a second parameter of false.  In this case a
 * partial match will be done on the artist name using the first parameter for 
 * the searching criteria.
 *
 * searchAlbum– this function will traverse the list searching for a album name
 * that matches the first parameter, the album name.  This is a case sensitive 
 * search.  The default is to do full match on the name. This behavior can be
 * changed by passing in a second parameter of false.  In this case a partial
 * match will be done on the album name using the first parameter for the
 * searching criteria.
 *
 * countAlbums – returns the number of Albums / CDs in this collection
 *
 * countSongs – returns the number of songs in your entire collection.
 *
 * printCD – outputs the collection of Albums / CDs   to the given ostream 
 * (monitor or file) that is a parameter to the function.  Every CD will be 
 * written to the designated stream with the artist name being first followed by
 * the album name on one line.  You must provide a separator that makes it easy
 * to recognize the two parts.
 *
 * printCollection– outputs the collection of CDs to the given ostream 
 * (monitor or file) that is a parameter to the function. Every Album CD will be
 * written to the designated stream with the artist name being first followed by
 * the album.  You must provide a separator that makes it easy to recognize the
 * two parts.  After this line, all songs will be outputted in ascending order 
 * being indented at least 5 spaces, One song per line
 *
 * splitSongs – this will split the comma separated songs and place them into 
 * the STL list in ascending order (not by track number). The ordering is done 
 * by name. This function is in the private section and can be called by any 
 * function in the musicList class.
 * 
 * After the CD's are inserted the menu fucntion will be called. The following
 * options will be available.
 * 
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
 * 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      Placed include directory for mysql includes into c++ compile general
 *             "Additional Include Directories"<br>
 *             ex: c:\\mysql\\include<br>
 *      <br>
 *      Placed library directory for mysql libs into c++ linker general
 *             "Additional Library Directories"<br>
 *             ex: c:\\mysql\\lib<br>
 *      <br>
 *      Placed library directory for mysql libs into c++ linker input
 *             "Additional Dependancies"<br>
 *             ex c:\\mysql\\lib\\libmysql.lib <br>
 *      <br>
 *      Copied the mysql dll into base folder.<br>
 *             c:\\mysql\\lib\\libmysql.dll into project solution folder.<br>
 *
 *
 * @par Usage:
   @verbatim
   c:\> prog2.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug Remove CD does not reassign headptr when deleting from begining of menu
 * @bug Remove CD incorrectly removes from middle of list
 *
 * @todo create your list to begin
 *
 * @par Modifications and Development Timeline:
   @verbatim
   <a href="https://gitlab.mcs.sdsmt.edu/csc215f17prog2/teamXX/commits/master>
   Gitlab commit Log</a>
   @endverbatim
 *
 ****************************************************************************/



#include "CSC215DB.h"
#include "musicList.h"
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std;

/*************************************************************************//**
 * @author Samuel Coffin
 *
 * @par Description:
 * This function is main. The main funcition will handle the reading from the
 * data base. It reads in the songs from the database and then calls the
 * functions necessary to put them in a linked list.  At the end of main the
 * print menu function will be called and the options availabe will be handled
 * in said function.
 *
 * @returns 0 program ran successful.
 ****************************************************************************/

int main()
{
    int num;                // the number of rows from the database
    // this is also how many you should have in your
    // linked list after you add everything.
    int caseNum;            // the number for which sql statement to use
    
    musicList music;        //Music list
    
    MYSQL *con;             // mysql connection resource
    MYSQL_RES *result;      // a pointer to all results from query
    MYSQL_ROW row;          // a row from a mysql query
    
    // prompt & error for which sql statemen to use
    cout << "Enter which sql statement to use: ";
    cin >> caseNum;
    
    if ( caseNum < 0 || caseNum > 7 )
    {
        cout << "Invalid Case Number" << endl;
        exit ( 1 );
    }
    
    // initialze the database connection and select the table
    mysqlMusic ( con );
    
    // request the music data from the database
    if ( mysql_query ( con, sqlStatement[caseNum] ) )
    {
        finishWithError ( con );
    }
    
    // retrieve the data from the database
    result = mysql_store_result ( con );
    
    if ( result == nullptr )
    {
        finishWithError ( con );
    }
    
    // find out how man rows are in your data set
    // good to check your size of list to this value
    num = ( int ) mysql_num_rows ( result );
    cout << "You have " << num << " rows to process" << endl;
    cout << endl << endl;
    
    
    // get each tuple (CD) from the result set
    // and add it to our linked list
    while ( ( row = mysql_fetch_row ( result ) ) )
    {
        //inserts data from sql into list
        music.insertCD ( row[0], row[1], row[2] );
    }
    
    // free up the memory from the resulting set
    mysql_free_result ( result );
    // shutdown the database connection
    mysql_close ( con );
    // finish the program
    
    //call menu
    
    music.printMenu();
	return 0;
}