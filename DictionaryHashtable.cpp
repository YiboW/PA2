#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  std::pair<std::unordered_set<std::string>::iterator,bool> ret;
  ret = setOfHashNode.insert(word);

  if(ret.second==false)
	return false;
  else
  	return true;

}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  std::unordered_set<std::string>::const_iterator it = setOfHashNode.find(word);
  if(it != setOfHashNode.end())
	return true;
  else
  	return false;
  
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
