#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;


int main() {
   ifstream inputFile("input.txt");
   unsigned long long valor = 0;
   string word;
   while(inputFile >> word){
      unsigned long long tamanho_final = 12;
      int drop = word.length() - tamanho_final;
      stack<unsigned long long> pilha;
      for(size_t i = 0; i<word.length(); ++i){
         unsigned long long n = word[i] - '0'; //converter char em numero
         while (drop > 0 && !pilha.empty() && pilha.top() < n) {
            pilha.pop();
            drop--;
         }
         pilha.push(n);
      }
      
      string numero_str = "";
        
      while(!pilha.empty()) {
         numero_str += to_string(pilha.top());
         pilha.pop();
      }

      reverse(numero_str.begin(), numero_str.end());
      if (numero_str.length() > tamanho_final) {
         numero_str = numero_str.substr(0, tamanho_final);
      }

      valor += stoull(numero_str);
   }
   cout << valor << endl;
   inputFile.close();
   return 0;
}