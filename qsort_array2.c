/* Die per Preprozessor eingebundenen Standardbibliotheken: */
#include <stdio.h>	//Standard Ein-und Ausgabe.h
#include <stdlib.h>	//Standardbibliothek.h

/*	x_qsort Algorithmus:
	@Author: A. Brockmeier
	Quellen:
	http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/022_c_algorithmen_003.htm
& 	IT-Handbuch für Fachinformatiker S.493f (Arrays in C).
	Dieses Programm ist eine Erweiterung der jeweiligen Codebeispiele als Übung.  
*/
int ein, i;
int sizeArray;

int array_in();
void array_out(int[]);

/*	Funktions deklaration:
(void -> Methode ohne Rückgabewert!)
@name: x_qsort 
@params: zwei Pointer auf je ein Array-Element (Typ Integer) */ 
void x_qsort(int*, int*);

int array_in(){
	int werte[sizeArray];
	// Ausgabe zur Aufforderung des Benutzers eine Zahl zur festlegung der Arraygröße einzugeben.
		printf ("Bitte bestimmen Sie die Größe des Arrays: ");
		// Lesen der eingegebenen Zahl und speichern in der Variablen sizeArray:
		scanf ("%d", &sizeArray);
		// Benutzer INFO
		printf ("Der Array hat %d Elemente.\n", sizeArray);
		// Ausgabe zur Aufforderung des Benutzers die Werte der Array-Elemente einzugeben:
		printf ("Bitte %d Werte eingeben!\n", sizeArray);
// For-Schleife  für die Eingabe der Array-Elemente (0...sizeArray)
		for (i = 0; i < sizeArray; i++) {
			printf ("%d. Element:", i + 1);
			// die Eingabe wird in der Variable ein "zwischengespeichert",
			scanf ("%d", &ein);
			// und elementweise an den Array übergeben.
			werte[i] = ein;
			}
}

void array_out(int *werte){

}


/* Implementierung der x_qsort Funktion:
	@params:	("*links":Pointer auf die Anfangsadresse vom Array "werte",
				 "*rechts": Pointer auf die Endadresse vom Array "werte".)
*/
void x_qsort(int *links, int *rechts){
	/*ptr1 und ptr2 übernehmen die Adressen,
	 w, x vom Typ Integer werden deklariert.*/
	int *ptr1 = links;
	int *ptr2 = rechts;
	int w, x;
	
	/* x bekommt die Anfangsadresse der
    * Mitte von links und rechts.
    * Anstatt der Bitverschiebung hätten Sie
    * auch einfach »geteilt durch 2« rechnen können.
    */
	x = *(links + ((rechts - links) >> 1));
		
	// Zum Verständnis des Algorithmus eine Ausgabe der Elemente vor denen geteilt wird.
	printf("Teilung nach Array-Element: x = %d\n",x);
		
	/* do ... 
	while solange der Zeiger ptr1 wird jetzt so lange inkrementiert,
	bis er auf ein Element zeigt, das größer als oder gleich dem Element von x ist.
	ebenso wird der ptr2 solange dekrementiert, bis er auf ein Element zeigt,
	das kleiner dem Element von x ist.
	*/
	do {
		while (*ptr1 < x) ptr1++;
		while (*ptr2 > x) ptr2--;
		
		// die Abbruchbedingung in Form einer if-Abfrage.
		if(ptr1 > ptr2)
			break;
		
	// Ausgabe der Elemente der Zeiger links, bzw. rechts:
	printf("[links vom Element: %d\nrechts vom Element: %d]\n",*links,*rechts);
		
		// Die Pointer werden mithilfe der Variablen w vertauscht.
		w = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = w;
	// Die Pointer werden auf einander zubewegt.
	} while(++ptr1 <= --ptr2);
	
	// "Rekursionsaufruf Fall: links < ptr2!"
	if(links < ptr2) x_qsort(links, ptr2);
	
	// "Rekursionsaufruf Fall: ptr1 < rechts!"
	if(ptr1 < rechts) x_qsort(ptr1, rechts);
	
	// DEBUG INFO:
	printf("Rekursionsaufruf!\n");
}
/* Die main Funktion (auch void also ohne Rückgabewert) mit den Variablen:  
	@params:	sizeArray (Integer Variable für die größe des Arrays),
				werte[sizeArray] (Array vom Typ Integer mit der Größe sizeArray),
				ein (Variable vom Typ Integer zur übergabe der Werte der einzelnen Array-Elemente),
				i, j, k (Variablen vom Typ Integer für die for-Schleifen),
				min, max (Integer Variablen für die Ausgabe der min, max Werte des Arrays). 

*/
int main(void) {



//int a;
int j, k, min, max;
int werte[sizeArray];
// Eine Abfrage zur Auswahl verschiedener Programmfunktionen:
printf("Bitte wählen Sie eine Aktion aus!\n");
printf("Um einen Array zu Sortieren bitte die (1) eingeben.\n");
printf("Um einen Array mit einer natürlichen Zahl zu multipliziern bitte die (2) eingeben.\n");
printf("\n");

printf("Bitte Auswahl treffen:\n");

int a;
scanf("%d", &a);

switch(a) {
	// case 1: Array Sortieren:
	case 1:
		
		
		array_in();

		// Initialisierung der min/max Werte mit dem "ersten" Element des Arrays [0]. 
		min = werte[0];
		max = werte[0];
		// Anfang der Ausgabe des vollständigen (eingegebenen)Arrays:
		printf ("Ihre Werte: [");
		// mit der For-Schleife die alle Elemente des Arrays durchläuft:
		for (j = 0; j < sizeArray; j++) {
			printf ("%d", werte[j]);
			/* Diese If-Abfrage sorgt dafür, dass die Anzahl der Kommata
			im Array bei der Ausgabe korrekt sind.*/
			if (j + 1 < sizeArray) {
				printf (", ");
			}
			/* In einem Schritt (innerhalb der selben For-Schleife) werden das größte,
			bzw. das kleinste Element des Arrays bestimmt. */
			if (werte[j] > max)
				max = werte[j];
			if (werte[j] < min)
				min = werte[j];
			}
		// Eine Menge printf für die Formatierung, zur Info für den Benutzer und zum Debuggen.
		printf ("]");
		printf ("\n");
		printf ("Kleinster Wert: %d\n", min);
		printf ("Größter Wert: %d\n", max);
		printf ("\n");
		printf ("DEBUG - MODUS: ON !\n");

		/* 	Aufruf der x_qsort Funktion (...endlich :-)
			@params:Wert der Anfangsadresse, bzw. Wert des letzten Elements im Array 
		 	werden mit übergeben.*/
		x_qsort(werte, werte + sizeArray);

		// printf für die Formatierung, zur Info für den Benutzer und zum Debuggen.
		printf ("DEBUG - MODUS: OFF ! \n");
		printf ("\n");
		printf ("Ihr Array wurde sortiert: [");

		// nochmal eine For-Schleife für die Ausgabe des sortierten Arrays!
		for (k = 1; k <= sizeArray ; k++) {
			printf ("%d", werte[k]);
			/* Sorgt dafür, dass die Anzahl der Kommata
			im sortierten Array bei der Ausgabe korrekt sind.*/
			if (k < sizeArray) {
			printf (", ");
			}
		}	
		// letzte Formatierungen...
		printf ("]");
		printf ("\n");
		break;
	//case 2:
	//	setjmp 

	}
// Erfolreiches Beenden der Main-Funktion!
return EXIT_SUCCESS;
}
/* Und fertig ist meine erste eigene Implementierung des qsort-Algorithmus!
PS: Sollten Sie in der Praxis vorhaben, den qsort()-Algorithmus einzusetzen, 
können Sie auch den Quicksort-Algorithmus qsort() verwenden,
der in der Standard-Headerdatei <stdlib.h> implementiert ist. ;-)
*/