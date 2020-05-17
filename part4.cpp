
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
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
	else if(data == root->data)
    {
        root->id.push(name);
    }
	else if (data < root->data)
	{
		root->left = insert(root->left, data,name);
	}
	else
	{
		root->right = insert(root->right, data,name);
	}
	return root;
}

stack<string> searchbst (node* root,string word)
{
    stack<string> qq ;
    if(root==NULL)
        return qq;
    else if(root->data == word)
        return root->id ;
    else if(root->data < word)
        return searchbst(root->right,word);
    else
        return searchbst(root->left,word);
}
void breadthfirst (node* root)
{
    if(root==NULL) return ;
    queue<node *> q ;
    q.push(root);
    while(!q.empty())
    {
        node* current = q.front();
        cout<<current->data<<' ' ;
        int n = current->id.size();
          for (int i=0;i<n;i++)
    {
        cout<<(current->id.top())<<' ';
        current->id.pop();
    }
    cout<<endl;
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }

}

int main()
{
   node* root = NULL ;
    root = insert(root,"the", "1");
    root = insert(root,"monkey","1");
    root= insert(root,"is", "1");
    root=insert(root,"my","1");
    root=insert(root,"favorite","1");
    root=insert(root,"animal", "1");
    root=insert(root,"the","2");
    root=insert(root,"monkey","2");
    root=insert(root,"is","2");
    root=insert(root,"the","2");
    root=insert(root,"best","2");
    root=insert(root,"animal","2");
    root=insert(root,"this","3");
    root=insert(root,"day","3");
    root=insert(root,"is","3");
    root=insert(root,"my","3");
    root=insert(root,"day","3");
   string x ;
    cin>>x;
    stack<string> s1 =searchbst(root,x);
    int size_=s1.size();
    vector<string>v1 ;
     for(int i=0;i<size_;i++)
     {
         v1.push_back(s1.top());
         s1.pop();
     }
    sort(v1.begin(),v1.end());
    v1.erase(unique(v1.begin(),v1.end()),v1.end());
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<' ';
    }

return 0;
}
