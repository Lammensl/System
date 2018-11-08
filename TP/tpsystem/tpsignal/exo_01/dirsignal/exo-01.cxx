/**
 * @File : exo_01.cxx
 *
 * @Authors : A. B. Dragut
 *
 * @Version : V1.1
 *
 * @Synopsis : affichage de la liste de tous les signaux avec 
 *             leur explication (sauf temps reel), et deroutement 
 *             conditionne par un argument de la ligne de commande
 *             soit vers un traitant particulier, soit ignore, soit
 *             vers le traitant par defaut 
 *
 **/
#include <string>
#include <exception>
#include <csignal>      // _sys_siglist

#include <iostream>
#include <iomanip>      // setw()
#include <sstream>

#include "CExc.h"
#include "nsSysteme.h"

using namespace nsSysteme;  // Signal()
using namespace std;

namespace {
    void Derout (int NumSig) {
      cout << "Signal " << _sys_siglist [NumSig]  << " recu numero : " << NumSig << endl;
    } // Derout()

} // namespace anonyme

int main(int argc, char * argv []) {
  try {
    if (2 != argc || 
	(argv[1][0] != 'D' && argv[1][0] != 'I' && argv[1][0] != 'P')) 
	throw CExc ("main()",string ("Usage : ") + argv [0] + " {P|I|D} ");

    for (int NumSig = 1; NumSig < CstSigMax; ++NumSig) {
      if(NumSig != SIGKILL &&
	 NumSig != SIGSTOP) {
	switch(argv[1][0]) {
	case 'P':
	  Signal (NumSig, Derout);
	  cout << "Signal numero " << setw(2) << NumSig  
	       << " signifiant " << _sys_siglist [NumSig]  << " deroute, traitement Particulier.\n";
	  break;
	case 'I':
	  Signal (NumSig, SIG_IGN);
	  cout << "Signal numero " << setw(2) << NumSig  
	       << " signifiant " << _sys_siglist [NumSig]  << " Ignore, aucun traitement.\n";
	  break;
	case 'D':
	  Signal (NumSig, SIG_DFL);
	  cout << "Signal numero " << setw(2) << NumSig  
	       << " signifiant " << _sys_siglist [NumSig]  
	       << " mis au traitement par Defaut.\n";
	  break;
	default:
	  cout << "Option " << argv[1][0] << "inconnue.\n";
	  break;
	}
      }
      else {
	cout << "Omettant le signal " << _sys_siglist [NumSig] << "\n";
      }
    }
    cout << "Deroutement acheve.\n";
      
      
    for (;;);
    
    return 0;
  }
  catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
  }
  catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
  }
  catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
  }
  
}  // main()
