/************************************************************************//**
 * @file                                                                        
 ***************************************************************************/
#include "CSC215DB.h"
using std::cerr;
using std::endl;


/*************************************************************************//**
 * @author Roger Schrader
 * 
 * @par Description: 
 *      When this function is called, you haved detected an error in the 
 *      mysql function calls.  Output the specified error number and exit
 *      the program.
 * 
 * @param[in]  con - the connection pointer to the mysql database
 * 
 ****************************************************************************/
void finishWithError(MYSQL *con)
{
    // output the error message
    cerr << mysql_error(con) << endl;

    // close the connection and exit the program
    mysql_close(con);
    exit(1);
}

/*************************************************************************//**
 * @author Roger Schrader
 * 
 * @par Description: 
 *      This function will establis a connection to a database. It calls
 *      the function to first initialize the connection (con) and then 
 *      uses the username, password and which database to connect to. If
 *      an error occurs, the catch all function finshWithError is called.
 * 
 * @param[out]  con - the connection pointer to the mysql database
 * 
 ****************************************************************************/
void mysqlMusic(MYSQL *&con )
{
    // creates a pointer that will be used to connect to database
    // if an error occurs, call generic error function
    con = mysql_init(nullptr);
    if (con == nullptr)
        finishWithError(con);

    // connects to the specified database with options of host,username,
    // password and the database to use. If an error occurs call generic
    // error function
    if (mysql_real_connect(con, HOST, USERNAME, PASSWORD,
        DATABASE, 0, nullptr, 0) == nullptr)
        finishWithError(con);
}