#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

using namespace std;

int main (int argc, char * argv []) {
    if(argc < 2) {
	cerr << "Usage: " << argv[0] << " <nomDeFicher>\n";
	return(1);
    }
    struct stat statStruct;
    const int valRet = stat(argv[1],&statStruct);
    if ( -1==valRet) {
	std :: cerr << " Erreur : " << argv[1] << " "
		    << strerror (errno) << "\n" ;
	return(errno);
    }
    cout << argv[1] << " taille " << statStruct . st_size << "\n";
    return(0);
}
