#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

struct node
{
	string data;
	stack<string> id;
	node* left;
	node* right;

};

node* NewNode(string data, string name)
{
	node* NewNodePtr = new node();
	NewNodePtr->data = data;
	NewNodePtr->id.push(name);
	NewNodePtr->left = NewNodePtr->right = NULL;
	return NewNodePtr;
}
node* insert(node* root, string data, string name)
{
	if (root == NULL)
	{
		root = NewNode(data, name);
	}
	else if (data <= root->data)
	{
		root->left = insert(root->left, data, name);
	}
	else
	{
		root->right = insert(root->right, data, name);
	}
	return root;
}
void inorder(node* rootptr)
{
	if (rootptr == NULL)
		return;
	inorder(rootptr->left);
	cout << rootptr->data << endl;
	inorder(rootptr->right);
}
string getFileName(string filename)
{
	string name;
	name = filename.substr(0, filename.find("."));

	return name;
}


int main()
{
	string word;
	ifstream file;
	node* root = NULL;
	string filename = "test.txt";
	file.open(filename);
	string name = getFileName(filename);
	while (file >> word)
	{
		root = insert(root, word, name);
	}
	file.close();
	inorder(root);


	return 0;

}

