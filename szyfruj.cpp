#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string cezar(int przesuniecie, string alfabet){
    string kawalek = alfabet.substr(0,przesuniecie);
    alfabet.erase(alfabet.begin(),alfabet.begin()+przesuniecie);
    return alfabet+kawalek;
}
string szyfruj(string SZYFROWANY, string KLUCZ ,string alfabet){
    string CEZAR_TEMP;
	string ZAMIENIONY;
	string WYNIK;
    char ARR[300][300];
    for(int i=0;i<alfabet.size();i++){
    	int k = (int)alfabet[i];
        CEZAR_TEMP = cezar(i,alfabet);
        for(int j=0;j<alfabet.size();j++){
        	int l = (int)alfabet[j];
            ARR[k][l] = CEZAR_TEMP[j];
        }
    }
    for(int i=0;i<SZYFROWANY.size();i++){
    	ZAMIENIONY += KLUCZ[i%KLUCZ.size()];
	}
	for(int i=0;i<SZYFROWANY.size();i++){
		char TEMP1 = ZAMIENIONY[i];
		char TEMP2 = SZYFROWANY[i];
		WYNIK += ARR[TEMP1][TEMP2];
	}
	return WYNIK;
    

}
string deszyfruj(string DESZYFROWANY, string KLUCZ,string alfabet){
	string ZAMIENIONY;
	string cezar_temp;
	string WYNIK;
	char arr[300][300];
	for(int i=0;i<DESZYFROWANY.size();i++){
    	ZAMIENIONY += KLUCZ[i%KLUCZ.size()];
	}
    for(int i=0;i<alfabet.size();i++){
    	int k = (int)alfabet[i];
        cezar_temp = cezar(i,alfabet);
        for(int j=0;j<alfabet.size();j++){
        	int l = (int)alfabet[j];
            arr[l][cezar_temp[j]] = k;
        }
    }
    for(int i=0;i<DESZYFROWANY.size();i++){
		char TEMP1 = ZAMIENIONY[i];
		char TEMP2 = DESZYFROWANY[i];
		WYNIK += arr[TEMP1][TEMP2];
	}
	return WYNIK;
    
}
int main(int argc, char *argv[])
{
	ifstream input_jawny("jawny.txt");
	ifstream input_klucz("klucz.txt");
	ofstream output("szyfrogram.txt");
	stringstream buffer_jawny;
	stringstream buffer_klucz;
	buffer_jawny<<input_jawny.rdbuf();
	buffer_klucz<<input_klucz.rdbuf();
	string alfabet = " /!#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz~";
	output << szyfruj(buffer_jawny.str(),buffer_klucz.str(),alfabet);

    return 0;
}

