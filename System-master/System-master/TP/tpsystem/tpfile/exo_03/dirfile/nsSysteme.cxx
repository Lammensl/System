/**
 *
 * @File : nsSysteme.cxx
 *
 *
 * @Synopsis : definition des wrappers non inline des fonctions syst,
 *		definition des fonctions shell	
 *
**/

#include <string>
#include <fcntl.h>       // O_CREAT, open()
#include <sys/types.h>   // mode_t
#include <cstddef>       // size_t
#include "CExc.h"
#include "nsSysteme.h"

using namespace std;     // string

//Definitions des fonctions systeme
////////////////////////////////////////////////////////////////////


int nsSysteme::Open (const char * pathname, int flags, ::mode_t mode)
    throw (CExc)
{
    int Res;
    if (!(flags & O_CREAT)) 
        throw CExc ("Open()",string (" fichier :") + pathname +
                       ". Un parametre de trop");
    if (-1 == (Res = ::open (pathname, flags, mode)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()

int nsSysteme::Open (const char * pathname, int flags)
    throw (CExc)
{
    int Res;
    if (flags & O_CREAT) 
        throw CExc ("Open()",string (" fichier :") + pathname +
                    ". Il manque un parametre");
    if (-1 == (Res = ::open (pathname, flags)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()


//Definitions des fonctions shell
////////////////////////////////////////////////////////////////////

void nsFctShell::FileCopy (const char * const Destination,
                       const char * const Source, const size_t NbBytes, 
		       const bool         syn /*= false*/)
                                             throw (nsSysteme::CExc)
{
    const int fdSource = nsSysteme::Open (Source, O_RDONLY);
    const int fdDest   = nsSysteme::Open (Destination, 
                               O_CREAT | O_TRUNC | O_WRONLY
			       | (syn ? O_SYNC : 0),
                               0700);


    char Tampon [NbBytes];

    for (; nsSysteme::Write (fdDest, Tampon, nsSysteme::Read (fdSource, Tampon, NbBytes)); );

    nsSysteme::Close (fdSource);
    nsSysteme::Close (fdDest);

} // FileCopy()

