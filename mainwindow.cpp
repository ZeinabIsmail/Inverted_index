#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <bits/stdc++.h>
#include "QFile"
#include "QTextStream"
#include "QTextStream"
#include "QGroupBox"
#include "QHBoxLayout"
#include "QDebug"
#include "QListWidgetItem"
#include "QMessageBox"
#include "QFileDialog"
#include "QDir"
#include "QProgressBar"
#include "QProgressDialog"
using namespace std;

struct node
{
    string data;
    stack<string> id;
    node* left;
    node* right;

};

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

string replaceStrChar(string str, const string replace, const string ch)
{
    size_t found = str.find_first_of(replace);

    while (found != string::npos)
    {
        str.replace(found , 1, ch);
        found = str.find_first_of(replace, found + 1);
    }

    return str;
}

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

node* root = NULL;
string dir;
vector <string> files;

void MainWindow::on_UploadpushButton_clicked()
{
QProgressDialog filesprogress("Building The Inverted Index", "Cancel", 0, files.size(), this);
    filesprogress.setWindowModality(Qt::WindowModal);
    filesprogress.setMinimum(0);
    filesprogress.setMaximum(files.size());
    filesprogress.show();
    node* mainRoot = root;
for (int i =0 ; i< files.size(); i++){
    filesprogress.setValue(i);

           if (filesprogress.wasCanceled())
               break;
    if(i==0){
    vector<string> file_words;
    string word;
    ifstream file;
    string filename = files[i];
    file.open(filename);
    string name = getFileName(filename);
    while (file >> word)
    {
        if(word[word.size()-1]=='?'){
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
}

void MainWindow::on_SearchpushButton_clicked()
{   ui->statusbar->show();
    QProgressBar *from_directory = new QProgressBar(this);
    ui ->statusbar->addWidget(from_directory);
    from_directory->setFormat("%p% Searched");
    from_directory->setMinimum(0);
    ui ->listWidget ->clear();
    QString word = ui -> enterwordsearch -> text();
    string x = word.toStdString();
    stack<string> s1 =searchbst(root,x);
    int size_=s1.size();
    QString dsize = QString::number(size_);
    from_directory->setMaximum(size_);
    ui ->label_3->setText(dsize);
     for(int i=0;i<size_;i++)
     {   from_directory->setValue(i+1);
         QString labelText = QString::fromStdString(s1.top())+".txt";
         QListWidgetItem *item = new QListWidgetItem;
         item->setText(labelText);
         item->setIcon(QIcon("C:/Users/lenovo/Desktop/Data Structure Project/download.png"));
         item->setCheckState(Qt::Unchecked);
         ui->listWidget->addItem(item);
         s1.pop();

     }
     ui->statusbar->removeWidget(from_directory);}
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{  dir = files[0];
    string directory_uploaded_from = dir.substr(0,dir.find_last_of("\\"));
   if(item->checkState()==Qt::Checked){
      QString filename = QString::fromStdString(dir.substr(0,dir.find_last_of("\\")+1) + item->text().toStdString());
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Error","file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui ->textEdit->setPlainText(text);
    file.close();
    ui->filetextname->setText("     "+item->text()+" "+":");
   }
   if(item->checkState()==Qt::Unchecked){
    ui ->textEdit->setPlainText(" ");
    ui->filetextname->setText("     ");
   }

}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    QStringList fileNames;
    if (dialog.exec())
         fileNames = dialog.selectedFiles();
    QString mine = fileNames.join(" ");
    QProgressBar *from_directory = new QProgressBar(this);
      ui ->statusbar->addWidget(from_directory);
      from_directory->setFormat("%p% Uploaded");
    from_directory->setMaximum(fileNames.size());
    from_directory->setMinimum(0);
for(int i=0;i<fileNames.size();i++){
    files.push_back(fileNames[i].toStdString());
        from_directory->setValue(i+1);

}

for(int i=0;i<fileNames.size();i++){
    files[i] = replaceStrChar(files[i],"\/","\\");
}

ui->statusbar->removeWidget(from_directory);}

void MainWindow::on_pushButton_2_clicked()
{
    dir.clear();
    root=NULL;
    files.clear();
    ui ->textEdit->clear();
    ui ->listWidget->clear();
    ui ->filetextname->clear();
    ui ->enterwordsearch->clear();
    ui -> label_3 ->clear();
    ui ->lineEdit->clear();
    ui->statusbar->update();

}

void MainWindow::on_pushButton_3_clicked()
{   ui->statusbar->show();
    QProgressBar *from_directory = new QProgressBar(this);
    ui ->statusbar->addWidget(from_directory);
   from_directory->setFormat("%p% Uploaded");
    string direct , finalDir;
        direct = (ui ->lineEdit->text()).toStdString();
        QDir source (QString::fromStdString(direct));
        QStringList dirfiles;

        dirfiles = source.entryList(QStringList()<<"*.txt",QDir::Files);

        from_directory->setMaximum(dirfiles.size());
        from_directory->setMinimum(0);
        for(int i=0;i<dirfiles.size();i++){
            files.push_back(direct + "\\" + dirfiles[i].toStdString());
           from_directory->setValue(i+1);
           from_directory->show();
        }

}
