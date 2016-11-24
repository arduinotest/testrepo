#include <stdio.h>
#include <stdlib.h>

// -------------- Start of Unit Test Code ------------------

// KRAVSPEC: Funktionen f�r a+b ska inte ge overflow eller underflow.
// Ska fungera f�r alla kombinationer av heltal -100 till 100.

// Tillv�gag�ngss�tt:
// 1) Ta reda p� alla test cases ur kravspecen.
// 2) Anropa funktionen f�r alla test cases.
// 3) Analysera funktions-resultaten utifr�n kravet.
// 4) �vers�tta funktions-resultaten till logiska lyckades eller misslyckades.

/*H�r �r f�rst sj�lva funktionen som ska testas. */
short add_numbers(short a, short b){
    return a + b;
}
/*Syfte med test_condition �r att testa kravet f�r ett unikt testfall f�r ett unit-test*/
short test_condition_add_numbers(short a, short b, short aReturned){
    return ((a<0)&&(b<0)&&(aReturned>0)) || ((a>0)&&(b>0)&&(aReturned<0));
}
/*H�r kommer unit testet*/
short unit_test_add_numbers(){
    short i = 0, j = 0;
    short lFail = 0;
    for(i=-100; i<100; i++)         // I v�rt fall �r det praktiskt att rada upp testfallen
        for(j=-100; j<100; j++)     // systematiskt med for-loopar.
            lFail |= test_condition_add_numbers(i,j,add_numbers(i,j));
    return lFail;
}
int main(){
    // H�r kan vi exempelvis ha en loop med unit tester om vi skrivit dem systematiskt
    // och pipea ut utskriften till ett rapport-dokument som antingen �r ett f�rsteg
    // till eller en f�rdig test-rapport, beroende p� hur avancerad testplanen �r.

    if(unit_test_add_numbers() != 0)
        printf("unit_test_add_numbers failed!\n\r");
    else
        printf("unit_test_add_numbers succeeded!\n\r");
    return getchar();
}
//----------------- End of Unit Test Code -----------------
