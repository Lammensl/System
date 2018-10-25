/**
 *
 * @File : exo_02.cxx, Fichiers
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : la mise en place du main()
 *             et de la bibliotheque libSys
 *             fonction Stat() 
 *
 **/
#include <string>
#include <exception>

#include <sys/stat.h>       // struct stat
//#include "string.h"

#include "CExc.h"

#include "nsSysteme.h"      // Stat()

using namespace nsSysteme;  // Stat()
using namespace std;


int main (int argc, char * argv [])
{
    try  {
//
//debut de l'exo courant
// 



if (2 != argc)
	throw CExc (string ("main)"),string("Usage ") +
                   argv [0] + " <nomFic>");


    struct stat S;
    Stat (argv[1], & S);
    cout << argv[1] << " taille " << S.st_size << "\n"
         << argv[1] << " nb liens en dur " << S.st_nlink << "\n"
         << argv[1] << " derniere modif " << ctime(&(S.st_mtime)) << "\n";
    return 0;


}
//
//fin de l'exo courant
//
    
    catch (const CExc & Exc)
    {
        cerr <<Exc<< endl;
        return errno;
    }
    catch (const exception & Exc)
    {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
    }

}  // main()
