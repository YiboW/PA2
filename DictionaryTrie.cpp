#include "util.h"
#include "DictionaryTrie.h"


Node::Node(char data2){
	this->data = data2;
	this->ifEnd=0;
	this->left=this->equal=this->right=NULL;
}
/*
bool Node::insert(std::string word, unsigned int i){
	char ch = word.at(i);
	Node *temp = this;
	if(!temp)
		temp = new Node(word.at(i));
	if(ch < temp->data)
		temp->left->insert(word, i);
	else if(temp->data < ch)
		temp->right->insert(word, i);
	else {
		if(i < word.length() - 1)
			temp->equal->insert(word,i + 1);
		else
			temp->ifEnd = 1;
	}
	return true;

}
*/
bool Node::find(std::string word, unsigned int i){
	char ch = word.at(i);	
	if(!this)
		return false;
	if(ch < this->data)
		return this->left->find(word, i);
	else if(this->data < ch)
		return this->right->find(word, i);
	else {
		if(i==word.length() - 1)
			return this->ifEnd;
		return this->equal->find(word, i+1);
	}
}

void Node::insert(Node** temp, std::string word, unsigned int i){
	char ch = word.at(i);
	//Node *temp = this;
	if(!(*temp))
		*temp = new Node(word.at(i));
	if(ch < (*temp)->data)
		insert(&((*temp)->left),word, i);
	else if((*temp)->data < ch)
		insert(&((*temp)->right),word, i);
	else {
		if(i < word.length() - 1)
			insert(&((*temp)->equal),word,i + 1);
		else
			(*temp)->ifEnd = 1;
	}

}



/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = NULL;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  //check if word is an empty string
  if(word.empty())
	return false;
  //check if already exist
  //check if word has special char
  for(unsigned int i = 0; i < word.length(); i++){
  	char ch = word.at(i);
	//check if space char
	if(ch==32)
		continue;
	else if(ch>64 && ch<91)//check if upper case
		continue;
	else if(ch>96 && ch<123)//check if lower case
		continue;
	else
		return false;//return false because it has special char
  }
  //check if duplicate
  if(find(word))
	return false;
  //insert
  root->insert(&root,word,0);
  return true;
  
/*	
  if(!root){
	root = new Node(word.at(0));
	Node *temp = root;
 	for(unsigned i = 1; i<word.length();i++){
		temp->equal=new Node(word.at(i));
		temp=temp->equal;
	}
	temp->ifEnd = 1;
		 
  	return true;
  } else {
	//root->insert;
  }
  
  */
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  //check if invalid string
  if(word.empty())
	return false;
  //check if root is null
  if(!root)
	return false;
   


  Node *temp = root;
  return temp->find(word,0);
  /*for(unsigned i = 0; i < word.length(); i++){
	if(word.at(i) < temp->data){
		if(!temp->left->data)
			return false;
		else
			temp = temp->left;
	} else if(temp->data < word.at(i)){
		if(!temp->right->data)
			return false;
		else
			temp = temp->right;
	} else {
		if(i == word.length()-1)
			return temp
	}
  */
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/*
 * Return the most similar word of equal length to the query, based
 * on their Hamming distance. 
 * In case of ties, return the word with the highest frequency (you may
 * assume there will always be one should a tie happen.)
 * In case there isn't any word of equal length to the query in the
 * trie, return an empty string.
 */
std::string DictionaryTrie::checkSpelling(std::string query)
{
  return "";
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}
