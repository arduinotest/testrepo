#include <stdio.h>
#include <stdlib.h>

// -------------- Start of Unit Test Code ------------------

// KRAVSPEC: Funktionen för a+b ska inte ge overflow eller underflow.
// Ska fungera för alla kombinationer av heltal -100 till 100.

// Tillvägagångssätt:
// 1) Ta reda på alla test cases ur kravspecen.
// 2) Anropa funktionen för alla test cases.
// 3) Analysera funktions-resultaten utifrån kravet.
// 4) Översätta funktions-resultaten till logiska lyckades eller misslyckades.

/*Här är först själva funktionen som ska testas. */
short add_numbers(short a, short b){
    return a + b;
}
/*Syfte med test_condition är att testa kravet för ett unikt testfall för ett unit-test*/
short test_condition_add_numbers(short a, short b, short aReturned){
    return ((a<0)&&(b<0)&&(aReturned>0)) || ((a>0)&&(b>0)&&(aReturned<0));
}
/*Här kommer unit testet*/
short unit_test_add_numbers(){
    short i = 0, j = 0;
    short lFail = 0;
    for(i=-100; i<100; i++)         // I vårt fall är det praktiskt att rada upp testfallen
        for(j=-100; j<100; j++)     // systematiskt med for-loopar.
            lFail |= test_condition_add_numbers(i,j,add_numbers(i,j));
    return lFail;
}
int main(){
    // Här kan vi exempelvis ha en loop med unit tester om vi skrivit dem systematiskt
    // och pipea ut utskriften till ett rapport-dokument som antingen är ett försteg
    // till eller en färdig test-rapport, beroende på hur avancerad testplanen är.

    if(unit_test_add_numbers() != 0)
        printf("unit_test_add_numbers failed!\n\r");
    else
        printf("unit_test_add_numbers succeeded!\n\r");
    return getchar();
}
//----------------- End of Unit Test Code -----------------
