#include "alignment.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void read_fasta(string& id, string& seq, istream& input)
{
  std::string line;
  int seq_count = 0;
  id.clear();
  while( std::getline( input, line ).good() ){
    if (line[0] == '>') { // ID
      if (seq_count++ > 1) {
	std::cerr << "Ignoring extra sequence: " << line << std::endl;
      }
      else {
	id = line.substr(1);
      }
    }
    else if (!line.empty() && seq_count <= 1){
      seq += line;
    }
  }
  //std::cout << "loaded " << id << std::endl;
}


int main(int argc, char** argv)
{

  Alignment align;
  string filename, input1, input2;
  fstream file1, file2;
  string seq1, seq2, id1, id2;

  if (argc != 3) {
    std::cerr << "usage: " << argv[0] << " <fasta file1> <fasta file2>" << std::endl;
    exit(1);
  }
  file1.open(argv[1]);
  file2.open(argv[2]);
  if (!file1 || !file2){
    std::cerr << "Error: could not open FASTA file." << std::endl;
    exit(1);
  }  
  read_fasta(id1,seq1,file1);
  read_fasta(id2,seq2,file2);
  file1.close();
  file2.close();    
  align.initialize(seq1,seq2);
  std::cout << std::endl;
  std::cout << "    FILE 1: " << argv[1] << std::endl;
  std::cout << "SEQUENCE 1: " << id1 << std::endl;
  std::cout << "            length=" << seq1.length() << " bases\n" << std::endl;
  std::cout << "    FILE 2: " << argv[2] << std::endl;
  std::cout << "SEQUENCE 2: " << id2 << std::endl;
  std::cout << "            length=" << seq2.length() << " bases\n" << std::endl;
  std::cout << " ALIGNMENT: " << align.distance() << std::endl;
  //align.print_alignment();
  exit(0);
}



