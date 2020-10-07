/*
TITLE: test_tree_mod.cc
NAME : INGMAR FJOLLA
PROFESSOR: ANITA RAJA
HW 2 Question 2 Part 2c
This wil act as the main file for part2c of our homework.
WE have to get the same output as part 2b, but instead 
our avl tree will be implementing doble rotations. no real differences in this file
but "avl_tree_p2c.h" will have modficiations


*/
#include "avl_tree_p2c.h"
#include "sequence_map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

namespace 
{

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) 
{
  // Code for running Part2(b)  
    // Code for running Part2(b)  
   //start with opening file 
  //and getting rid of first few lines
  ifstream ourfile;
  ourfile.open(db_filename);
  string garbage_lines;
  for(auto i =0 ; i<10; i++)
  {
    getline(ourfile,garbage_lines);
  }

  //now get the rest
  string lines;
  while(getline(ourfile,lines))
  {
    stringstream parsing;
    parsing.str(lines);

    string an_enzyneacronym; //string for the enzyme
    getline(parsing, an_enzyneacronym, '/'); //works by stopping at the first instance of slash

    string an_recognitionsequence; //string for recognition sequence //sometimes more than one
    //second while loop 
    while(getline(parsing,an_recognitionsequence, '/'))
    {
      if(an_recognitionsequence.size() >0)
      {
        SequenceMap our_avl_sequence(an_recognitionsequence, an_enzyneacronym);

        a_tree.insert(our_avl_sequence);
      }
    }

    //cout<<lines;
  }
    //now we have strings and we create SequenceMap object to insert into tree
    /**************
    end of parsing and populating tree
    ************/
    //number 2 after parser
    //a_tree.printTree(); DEBUG LINE 
  cout << "2: " << a_tree.numberOfNodes() << "\n";

    //number 3a for avg depth
  cout << "3a: " << a_tree.avgDepth() << "\n";

    //number 3b
  cout<<"3b: " << a_tree.avgDepthRatio()<<"\n";

  //number 4
  //Open file and store it in an ifstream object

  ifstream sequences_file(seq_filename);
  string entire_line_2;
  int total_queries = 0;
  //Loop through every line in the file
  while(getline(sequences_file, entire_line_2))
  {
    //Create sequence map object
    SequenceMap temp_map(entire_line_2, "");
    if((temp_map == a_tree.find(temp_map)))
    {    //Every call of find() will count the number of recursive calls
      total_queries++;    //Increment total number of successful queries
    }
  }
  //4a shows total number of seucseful queries found
  cout << "4a: " << total_queries << "\n";
  
  ///4b
  // Prints the average number of recursion calls, i.e. #total number of
  // recursion calls / number of queries.
  cout<<"4b: "<< float(a_tree.getRecursiveFinds() / total_queries) << endl;

  ///part 5
  string trash;
  a_tree.makerecursionzero();
  ifstream sequences_file_2(seq_filename);
    string entire_line_3 = "";
    int successful_removes = 0;

    while( getline(sequences_file_2, entire_line_3) )
    {
      SequenceMap temp_map_1(entire_line_3, "");

      if( a_tree.contains(temp_map_1) )
      {
        a_tree.remove(temp_map_1);
        successful_removes++;
      }

      //go to every other sequence
      getline(sequences_file_2, trash);
    }
  cout << "5a: " << successful_removes << "\n";
  //Number 5b - print the average number of recursive calls for remove()
  //float average_number_of_remove_calls = a_tree.getRecursiveRemoves() / successful_removes;
  cout << "5b: " << float(a_tree.getRecursiveRemoves() / successful_removes) << "\n";

  cout << "6a: " << a_tree.numberOfNodes() << endl;
  cout << "6b: " << a_tree.avgDepth() << endl;
  cout << "6c: " << a_tree.avgDepthRatio() << endl;
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  TestTree(db_filename, seq_filename, a_tree);

  return 0;
}
