#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	string data;
	stack<string> id;
	node* left;
	node* right;

};

node* NewNode(string data,string name)
{
	node* NewNodePtr = new node();
	NewNodePtr->data = data;
	NewNodePtr->id.push(name);
	NewNodePtr->left = NewNodePtr->right = NULL;
	return NewNodePtr;
}
node* insert(node* root, string data,string name)
{
	if (root == NULL)
	{
		root = NewNode(data,name);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data,name);
	}
	else
	{
		root->right = insert(root->right, data,name);
	}
	return root;
}
void inorder(node* rootptr)
{
	if (rootptr == NULL)
		return;
	inorder(rootptr->left);
	cout << rootptr->data << endl;
	while(!rootptr->id.empty()){
        cout<<rootptr->id.top()<<endl;
        rootptr->id.pop();
	}
	inorder(rootptr->right);
}
string getFileName(string filename)
{
	string name;
	name = filename.substr(filename.find_last_of("\\")+1, filename.find_last_of(".")-filename.find_last_of("\\")-1);

	return name;
}

node* previousSearch(node* root, string word)
{
    if (root == NULL || root->data == word)
      return root;

    if (root->data < word)
        return previousSearch(root->right,word);

    return previousSearch(root->left,word);
}

int main()
{  string files[] = {"C:\\Users\\lenovo\\Downloads\\questions\\0.txt","C:\\Users\\lenovo\\Downloads\\questions\\1.txt"};
node* root = NULL;
node* mainRoot = root;
for (int i =0; i<sizeof(files)/sizeof(files[0]);i++){
    if(i==0){
    vector<string> file_words;
	string word;
	ifstream file;
	string filename = files[i];
	file.open(filename);
	string name = getFileName(filename);
	while (file >> word)
	{   if(word[word.size()-1]=='?'){
	word.pop_back();
	}
	    if(file_words.size() != 0){
            sort(file_words.begin(),file_words.end());
            bool found = binary_search(file_words.begin(),file_words.end(),word);
            if (!found){
            file_words.push_back(word);
		    root = insert(root, word,name);
            }
            else{continue;}
	}
	else{
	    file_words.push_back(word);
		root = insert(root, word,name);}

	}

	file.close();
    }
    else{
    vector<string> file_words;
	string word;
	ifstream file;
	string filename = files[i];
	file.open(filename);
	string name = getFileName(filename);
	while (file >> word)
	{   if(word[word.size()-1]=='?'){
	word.pop_back();
	}
	    node* previousOne = previousSearch(root, word);
	    if( previousOne!= NULL){
            previousOne ->id.push(name);
            continue;
	}
	   else{ if(file_words.size() != 0){
            sort(file_words.begin(),file_words.end());
            bool found = binary_search(file_words.begin(),file_words.end(),word);
            if (!found){
            file_words.push_back(word);
		    root = insert(root, word,name);
            }
            else{continue;}
	}
	else{
	    file_words.push_back(word);
		root = insert(root, word,name);}

	}}

	file.close();
    }
    }
inorder(root);
	return 0;

}
