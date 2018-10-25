  #include <string>
  #include <exception>

  
  #include "string.h"

  #include "CExc.h"
  #include "nsSysteme.h"  // wrappers système

  // a verifier avec le man 2 ou man 3  de la fonction systeme les #include a rajouter
  
  using namespace nsSysteme; // wrappers système
  using namespace std;
  
  int main (int argc, char * argv []) {
    try {

    // ecrivez le corps de l'exercice courant
    
    }
    catch (const CExc & Exc) {
      cerr << Exc << endl;
      return errno;
    }
    catch (const exception & Exc) {
      cerr << "Exception : " << Exc.what () << endl;
      return 1;
    }  
    catch (...) {
       cerr << "Exception inconnue recue dans la fonction main()" << endl;
       return 1;
    }
  }// main()
