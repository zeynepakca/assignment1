#include <iostream>
#include <string>
#include <fstream>
#include<cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void relprob(ofstream&, string, float&, float&, float&, float&);
void relbigram(ofstream&, string);
void DNAstrings(ofstream&, float, float, float, float, float, float);

int var( string file, float xbar, float numlin)
{

  ifstream input(file);
  string line;
  float sumofsquares = 0 ;
  while(getline( input, line ) ) {
    if (line.length() != 0) {
      sumofsquares +=  ((line.length() - xbar)*(line.length() - xbar))  ;
    }
  }
  float variance = sumofsquares / numlin;
  return variance;
}


int stddev( float vari) {
  float stddevi = sqrt(vari) ;
  return stddevi;
}

int main(int argc, char** argv)
{
//   while (fileName.empty())
// {
//   cout << "Enter file name: ";
//   char c[255];
//   cin.getline(c, 255);
//   fileName = string(c);
// }
//http://www.cplusplus.com/forum/beginner/20370/
  if (argc < 2) {
    cout << "Must include file name!" << endl;
    return 1;
  }
  string fn = argv[1];

  ifstream input(fn);
  string line;
  float total = 0  ;
  float NumberofLines = 0 ;

  while(getline( input, line ) ) {
    total += line.length() ;
    if (line.length() != 0) {
      NumberofLines +=1 ;
    }
  }

  float mean =  total / NumberofLines;

  float variance = var(fn, mean, NumberofLines) ;
  // DNAstrings(mean, variance);

  ofstream myfile;
  myfile.open ("zeynepakca.txt");
  myfile << "Zeynep Akca" << endl;
  myfile << "ID: 2304726" << endl;
  myfile << "sum: " << total << endl;
  myfile << "number of lines: " << NumberofLines << endl;
  myfile << "mean: " << mean << endl;
  myfile << "variance: " << var(fn, mean, NumberofLines) << endl;
  myfile << "standard deviation:" << stddev(variance) << endl;

  float rela, relc, relg, relt;
  relprob(myfile, fn, rela, relc, relg, relt);
  relbigram(myfile, fn);
  DNAstrings(myfile, mean, variance, rela, relc, relg, relt);
  myfile.close();

  return 0;
}

void relprob(ofstream& fout, string file, float& rela, float& relc, float& relg, float& relt) {

  ifstream fin;
  fin.open(file);

  char nucle_name;
  int a = 0;
  int c = 0;
  int t = 0;
  int g = 0;
  int total_numberofchar = 0 ;
  // float rela, relc, relg, relt ;
  while(fin.get(nucle_name)) {
    if (nucle_name ==  'A' or nucle_name == 'a') {
         a +=1;
      }

    else if (nucle_name ==  'C' or nucle_name == 'c') {
        c +=1;
      }
    else if (nucle_name ==  'T' or nucle_name == 't') {
        t +=1;
      }
    else if (nucle_name ==  'G' or nucle_name == 'g') {
        g +=1;
      }
  }
  total_numberofchar = a + c + t + g ;
  rela = (float)a / total_numberofchar ;
  relc = (float)c / total_numberofchar ;
  relg = (float)g / total_numberofchar ;
  relt = (float)t / total_numberofchar ;
  fout << "relative probability of A: " << rela <<endl;
  fout << "relative probability of C: " <<relc <<endl;
  fout << "relative probability of G: " <<relg <<endl;
  fout << "relative probability of T: " <<relt <<endl;

}

void relbigram(ofstream& fout, string file) {
  ifstream fin;
  fin.open(file);
  int AA = 0;
  int AC = 0;
  int AT = 0;
  int AG = 0;
  int CA = 0;
  int CC = 0;
  int CT = 0;
  int CG = 0;
  int TA = 0;
  int TC = 0;
  int TT = 0;
  int TG = 0;
  int GA = 0;
  int GC = 0;
  int GT = 0;
  int GG = 0;
  int total_bigram = 0;
  float relAA, relAC, relAT, relAG, relCA, relCC, relCT, relCG, relTA, relTC, relTT, relTG, relGA, relGC, relGT, relGG;
  char first;
  char second;
  char intermediary;
  while(fin.get(second)) {
    first = intermediary;
    intermediary = second;

    if (first == 'A' or first == 'a' ) {
        if (second == 'A' or second == 'a') {
          AA +=1;
        }
        else if (second == 'C' or second == 'c'){
          AC += 1;
        }
        else if (second == 'T' or second == 't'){
          AT += 1;
        }
        else if (second == 'G' or second == 'g'){
          AG += 1;
        }
    }

    if (first == 'C' or first == 'c' ) {
        if (second == 'A' or second == 'a') {
          CA +=1;
        }
        else if (second == 'C' or second == 'c'){
          CC += 1;
        }
        else if (second == 'T' or second == 't'){
          CT += 1;
        }
        else if (second == 'G' or second == 'g'){
          CG += 1;
        }
    }

    if (first == 'T' or first == 't' ) {
        if (second == 'A' or second == 'a') {
          TA +=1;
        }
        else if (second == 'C' or second == 'c'){
          TC += 1;
        }
        else if (second == 'T' or second == 't'){
          TT += 1;
        }
        else if (second == 'G' or second == 'g'){
          TG += 1;
        }
    }

    if (first == 'G' or first == 'g' ) {
        if (second == 'A' or second == 'a') {
          GA +=1;
        }
        else if (second == 'C' or second == 'c'){
          GC += 1;
        }
        else if (second == 'T' or second == 't'){
          GT += 1;
        }
        else if (second == 'G' or second == 'g'){
          GG += 1;
        }
    }

  }
    total_bigram = AA + AC + AT + AG + CA + CC + CT + CG + TA + TC + TT + TG + GA + GC + GT + GG ;
    relAA = (float) AA /  total_bigram;
    relAC = (float) AC /  total_bigram;
    relAT = (float) AT /  total_bigram;
    relAG = (float) AG /  total_bigram;
    relCA = (float) CA /  total_bigram;
    relCC = (float) CC /  total_bigram;
    relCT = (float) CT /  total_bigram;
    relCG = (float) CG /  total_bigram;
    relTA = (float) TA /  total_bigram;
    relTC = (float) TC /  total_bigram;
    relTT = (float) TT /  total_bigram;
    relTG = (float) TG /  total_bigram;
    relGA = (float) GA /  total_bigram;
    relGC = (float) GC /  total_bigram;
    relGT = (float) GT /  total_bigram;
    relGG = (float) GG /  total_bigram;

    //cout << "total bigram:" << total_bigram << endl;
    //std::cout << "CC number" << CC << endl;
    fout << "probability of nucleotide bigram AA: " << relAA <<endl;
    fout << "probability of nucleotide bigram AC: " << relAC <<endl;
    fout << "probability of nucleotide bigram AT: " << relAT <<endl;
    fout << "probability of nucleotide bigram AG: " << relAG <<endl;
    fout << "probability of nucleotide bigram CA: " << relCA <<endl;
    fout << "probability of nucleotide bigram CC: " << relCC <<endl;
    fout << "probability of nucleotide bigram CT: " << relCT <<endl;
    fout << "probability of nucleotide bigram CG: " << relCG <<endl;
    fout << "probability of nucleotide bigram TA: " << relTA <<endl;
    fout << "probability of nucleotide bigram TC: " << relTC <<endl;
    fout << "probability of nucleotide bigram TT: " << relTT <<endl;
    fout << "probability of nucleotide bigram TG: " << relTG <<endl;
    fout << "probability of nucleotide bigram GA: " << relGA <<endl;
    fout << "probability of nucleotide bigram GC: " << relGC <<endl;
    fout << "probability of nucleotide bigram GT: " << relGT <<endl;
    fout << "probability of nucleotide bigram GG: " << relGG <<endl;
}


void DNAstrings (ofstream& fout, float m, float var,
                 float rela, float relc, float relg, float relt) {
    float relaa = rela;
    float relac = relc;
    float relat = relt;
    float relag = relg;
  for (int i = 0; i < 1000; i++) {
    double a = (double) rand() / (RAND_MAX + 1.0);
    double b = (double) rand() / (RAND_MAX + 1.0);
    double c = sqrt(-2 *log(a)) * cos(2*3.14*b);
    int d = sqrt(var)*c + m;
    double z = 0;
    string str = "";
    string strA = "A";
    string strC = "C";
    string strT = "T";
    string strG = "G";

    for(int k = 0; k < d; k++){
      z = (double) rand() / (RAND_MAX + 1.0);

      if (z < relaa){
          str.append(strA);
      }
      else if (z < relaa + relac) {
          str.append(strC);
      }
      else if (z < relaa + relac + relat) {
          str.append(strT);
      }
      else {
          str.append(strG);
      }
    }
    fout << "line " << (i+1) << ":  " << str << endl;
  }
}



// Resources
// https://stackoverflow.com/questions/8642135/c-how-randomly-with-given-probabilities-choose-numbers



// http://www.cplusplus.com/doc/tutorial/files/
