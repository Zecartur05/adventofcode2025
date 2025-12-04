#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main() {
   ifstream inputFile("input.txt");
   int valor = 0;
   string word;
   while(inputFile >> word){
      int f = 0;
      
      int aux = 0;
      for(size_t i=0;i<word.length()-1;i++){                   //solucao manhosa
         int n = word[i] - '0'; //converter char em numero
         f = (f < n) ? n : f;
         int s = 0;
         for(size_t j = 1+i; j<word.length();j++){
            int n2 = word[j] - '0'; //converter char em numero
            s = (s < n2) ? n2 : s;
         }
         int temp = aux;
         aux = (f*10)+s;
         aux = (aux > temp) ? aux : temp;
      }
      cout << "aux: "<< aux <<endl;
      valor += aux;
   }
   cout << valor << endl;
   inputFile.close();
   return 0;
}