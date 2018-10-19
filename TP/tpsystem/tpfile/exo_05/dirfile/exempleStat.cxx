#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main (int argc, char * argv []) {
	    if(argc < 2) {
		    	cerr << "Usage: " << argv[0] << " <nomDeFicher>\n";
				return(1);
	    }
	        struct stat statStruct;
	     	stat(argv[1],&statStruct);
		cout << argv[1] << " taille " << statStruct . st_size << "\n";			    return(0);
}
