#include <iostream>
#include <cstring>
#include <fstream>
/**
1. Adott a szoveg.txt állomány, amely szöveget tartalmaz több sorban (az első sorban minden szóban van egy szám is). A szavak egy vagy több szóközzel vannak elválasztva egymástól. Oldjuk meg az alábbi feladatokat, megírva és meghívva minden alpontnak legalább egy függvényt. A feldolgozás soronként történjen, egy karakterláncba olvassunk be egy sort, azon dolgozzunk, az eredményt pedig egy állomány különböző soraiba írjuk be.
*/

int a(char *t);
void nextchar(char *t, int &i, char c);
void toendofchar(char* t, int& i);
/**
b. A második sor minden szavának első betűjét írjuk át nagy betűre!
c. Töröljük a harmadik sor leghosszabb szavának hosszával egyező hosszúságú szavakat!
d. Határozzuk meg az állomány szavainak számát!
e. Írjuk meg azt a függvényt, amely kicseréli egy szám egy adott számjegyének összes előfordulását egy másik számjegyre. A függvénynek 3 paramétere van, a megváltoztatott számot az első paraméterében küldi vissza. Ha nem találja meg a cserélendő számjegyet, az eredeti számot téríti vissza. A meghíváskor az első paraméter egy szám, amelyet az első alpontban számoltunk ki, a második és harmadik paraméter két számjegy a billentyűzetről beolvasva. (A feladatot karakterláncokkal kell megoldani, az atoi és az itoa függvények használatával!!!).
*/
using namespace std;

int main()
{
	ifstream in("szoveg.txt");
	char t[255];
	in.getline(t,255);
	cout <<a(t);
	return 0;
}

void nextchar(char* t, int& i, char c)
{
	while(t[i] != c && strlen(t) > i) {
		i++;
	}
}

void toendofchar(char* t, int& i)
{
	char c = t[i];

	while(t[i] == c) {
		i++;
	}
}
/**
a. Határozzuk meg a számok összegét az első sorból!
*/
//megy
int a(char* t)
{
	int i=0,x;
	int n = 0;
	nextchar(t, i, ' ');
	char tmp[255], word[255];
	strcpy(tmp, t);
	tmp[strlen(t)]=' ';
	tmp[strlen(t)+1]=0;

	while (strlen (tmp)) {
		nextchar(tmp, i, ' ');
		toendofchar(tmp, i);
		strncpy(word, tmp, i);
		x=i;
		for(; i && word[i]==' '; i--) ;
		word[i] = 0;
		n+=atoi(word);
		strcpy(word,tmp+x);
		strcpy(tmp,word);
		i=0;
	}
	return n;
}
