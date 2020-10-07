/*
TITLE: query_tree.cc
NAME : INGMAR FJOLLA
PROFESSOR: ANITA RAJA
HW 2 Question 2 Part 2a
THE purpose of this part of the project is to create a parser 
to read in this database and construct an AVL tree. This acts as the main


*/


// Main file for Part2(a) of Homework 2.

#include "avl_tree_p2a.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace{

// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.

template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) 
{
  // Code for running Part2(a)
  // You can use public functions of TreeType. For example:
  // a_tree.insert(10);
  // a_tree.printTree();

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

    //now we have strings and we create SequenceMap object to insert into tree
    

    //cout<<lines;
  }

  //a_tree.printTree();
  input_part_ofproject(a_tree);
}
}

  // namespace


// 
// @a_tree: an input tree of the type TreeType.
//the method here will be to get three strings from user
//then create the sequence map objects, put them in a vector,
//tehn find them and print them
//ASSUMPTION IS THAT THEY ACTUALLY ARE PUTTING IN REAL SEQUENCE NO ERROR TESING???
// I had some issues wih this part of the project, mainly i did not understand what 
//was wrong with gradescope, but i literally wrote it for only 3 inputs which 
//was my understanding taht it was being given in sequences of 3 
template <typename TreeType>
void input_part_ofproject(TreeType &a_tree)
{
  //all this is trash because i was coding it wrong
  // string first, second, third;
  // cin>>first>>second>>third;
  // //cout<<first<<second<<third;

  // SequenceMap one(first,"");
  // SequenceMap two(second,"");
  // SequenceMap three(third,"");
  // std::vector<SequenceMap> v;
  // v.push_back(one);
  // v.push_back(two);
  // v.push_back(three);

  // for(int i =0;i<v.size();i++ )
  // {
  //   cout<<a_tree.find(v[i]) <<endl;
  // }

  string let_me_try_this;
  while(cin>>let_me_try_this)
  {
    SequenceMap thing(let_me_try_this,"");
    cout<<a_tree.find(thing)<<endl;
  }


}


int
main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string db_filename(argv[1]);
  cout << "Input filename is " << db_filename << endl;
  // Note that you will replace AvlTree<int> with AvlTree<SequenceMap>
  //FOr my own purposes, this is an avl tree with type sequence map objects, interesting
  //similar to 235 things we did with zoorecord etc -- remember for project
  AvlTree<SequenceMap> a_tree;
  QueryTree(db_filename, a_tree);
  return 0;
}
