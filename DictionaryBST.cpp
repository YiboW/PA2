#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
  }

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  std::pair<std::set<std::string>::iterator,bool> ret;
  ret = setOfNode.insert(word);

  if(ret.second==false)
	return false;
  else
  	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  std::set<std::string>::iterator it = setOfNode.find(word);
  if(it != setOfNode.end())
	return true;
  else
  	return false;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
