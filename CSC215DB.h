/************************************************************************//**
 * @file                                                                        
 ***************************************************************************/
#include <my_global.h>
#include <mysql.h>
#include <iostream>

#ifndef __CSC215DB__H__
#define __CSC215DB__H__

/**
 * @brief The servers fqdn for the database server
 */
#define HOST "services1.mcs.sdsmt.edu"
/**
 * @brief The username to connect to the database with
 */
#define USERNAME "CSC215"
/**
 * @brief The password for the given username above
 */
#define PASSWORD "MuSiC215"
/**
 * @brief The name of the database to use
 */
#define DATABASE "db_csc215Music"

/**
 * @brief 7 sql statements that target different areas for the linked list
 *        being developed
 */
const char sqlStatement[8][50] = {	"SELECT artist,album,songs FROM nodata",
                                    "SELECT artist,album,songs FROM empty",
                                    "SELECT artist,album,songs FROM front",
                                    "SELECT artist,album,songs FROM middle",
                                    "SELECT artist,album,songs FROM end",
                                    "SELECT artist,album,songs FROM mixed1",
                                    "SELECT artist,album,songs FROM mixed2",
                                    "SELECT artist,album,songs FROM mixed3"
                               };

void finishWithError(MYSQL *con);
void mysqlMusic(MYSQL *&con);

#endif
