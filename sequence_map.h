/*
TITLE: SEQUENCE_MAP.H
NAME : INGMAR FJOLLA
PROFESSOR: ANITA RAJA
HW 2 Question 2 Part 1
THE purpose of this part of the project is to define a class SequenceMap (capitalization is important)
that will be used for the rest of the programs in the project. We are to implement the big 5, and a few
other functions 


*/


#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SequenceMap
{
	public:
		//Big Five

		//Zero-parameter constructor
		SequenceMap() = default;

		//Copy-constructor
		SequenceMap(const SequenceMap &rhs) = default;

		//Copy-assignment
		SequenceMap& operator=(const SequenceMap &rhs) = default;

		//Move constructor
		SequenceMap(SequenceMap &&rhs) = default;

		//Move assignment
		SequenceMap& operator=(SequenceMap &&rhs) = default;

		//End of Big Five
		/*
		A constructor SequenceMap(const string &a_rec_seq, const string &an_enz_acro),that constructs a 
		SequenceMap from two strings (note that after the constructor is called the vector enzyme_acronyms_ will 
		contain just one element, the an_enz_acro).
		*/
		SequenceMap(const string &a_rec_seq, const string &an_enz_acro): recognition_sequence_(a_rec_seq)
		{
			
			enzyme_acronyms_.push_back(an_enz_acro);
		}
		
		/*
		bool operator<(const SequenceMap &rhs) const, that operates based on the regular 
		string comparison between the recognition_sequence_ strings (this will be a one line function).
		*/
		bool operator<(const SequenceMap &rhs) const
		{
			return (recognition_sequence_ < rhs.recognition_sequence_) ? true : false;
			
		}
		//Overloading the == operator to see if lhs and rhs recognition_seqeunce_ are equal
		//part 4b needs this
		bool operator==(const SequenceMap &rhs) const{
			return (recognition_sequence_ == rhs.recognition_sequence_) ? 1 : 0;
		}

		/*
		Overload the << operator in order to print out the enzyme_acronyms vector, for a
 		given recognition sequence. Refer to assignment 1 for example of overloading the
 		operator signature.
		*/
		friend std::ostream &operator<<(std::ostream &out, const SequenceMap &a_seq_map) 
		{
			 //makes sure its not empty 
  			for(auto i = 0; i < a_seq_map.enzyme_acronyms_.size(); i++){

				if(i == a_seq_map.enzyme_acronyms_.size() - 1){
					out << a_seq_map.enzyme_acronyms_[i];
				}

				else 
				{
					out << a_seq_map.enzyme_acronyms_[i] << " ";
				}
			}
			//out << endl;
  			return out;

  		}

  		/*
		 void Merge(const SequenceMap &other_sequence). This function assumes that 
		 the object’s recognition_sequence_ and other_sequence.recognition_sequence_ are equal 
		 to each other. The function Merge() merges the other_sequence.enzyme_acronym_ with the object’s
		 enzyme_acronym_. The other_sequence object will not be affected.
  		*/
  		void Merge(const SequenceMap &other_sequence)
  		{
  			if(recognition_sequence_ == other_sequence.recognition_sequence_){
				for(size_t i = 0; i < other_sequence.enzyme_acronyms_.size(); i++){
					//Add the contents of other_sequence.enzyme_acronyms into the calling object's vecto4
					enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
				}
			}
  		
  		}

	private:
		string recognition_sequence_ ; 
		vector<string> enzyme_acronyms_;



};

#endif