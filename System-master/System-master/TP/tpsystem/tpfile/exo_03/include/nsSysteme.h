/**
 *
 * @File : nsSysteme.h
 * 2011
 * @Synopsis : espace de noms qui contient les prototypes des wrappers
 *             des fonctions systeme
 *
 *
 **/
#if !defined __NSSYSTEME_H__
#define      __NSSYSTEME_H__

#include <cstddef>        // size_t

#include <sys/types.h>    // ssize_t
                                                    
#include <sys/stat.h>     // struct stat, stat(), fstat()

#include <unistd.h>


#include "string.h"

#include "CExc.h"

//  Declarations des fonctions concernant les fichiers
//  =========================================================

namespace nsSysteme
{
   void        Stat    (const char * file_name, struct stat * buf)
                             throw (CExc);

    void        Close  (int fd)
                             throw (CExc);


    int         Open   (const char * pathname, int flags)
                             throw (CExc);
    int         Open   (const char * pathname, int flags, ::mode_t mode)
                             throw (CExc);
    std::size_t Read   (int fd, void * buf, std::size_t count)
                             throw (CExc);

    void        Stat   (const char * file_name, struct stat * buf)
                             throw (CExc);

      
} // nsSysteme

namespace nsFctShell {
 
   void FileCopy (const char * const Destination,  
                  const char * const Source, 
                  const size_t NbBytes) 
                  throw (nsSysteme::CExc);

} // nsFctShell


//  Definitions courtes des fonctions concernant les fichiers
//  =========================================================

inline
void nsSysteme::Stat (const char * file_name, struct stat * buf)
    throw (CExc)
{
    if (::stat (file_name, buf))
        throw CExc ("stat()", std::string("fichier :")+ file_name);

} // Stat()

inline void nsSysteme::Close (int fd) throw (CExc)
{
    if (::close (fd)) throw CExc ("close()", fd);

} // Close()

inline 
std::size_t nsSysteme::Read (int fd, void * buf, std::size_t count)
    throw (CExc)
{
    ::ssize_t Res;
    if (-1 == (Res = ::read (fd, buf, count)))
        throw CExc ("read()", fd);

    return Res;

} // Read()

inline std::ssize_t nsSysteme::Write (int fd, const void *buf, std::size_t count)throw(CExc)
{
  ::ssize_t Res;
  if (-1 == (Res = ::write(fd, buf, count)))
    throw CExc ("write()", fd);

  return Res;

} //Write()


#endif    /* __NSSYSTEME_H__ */
