#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sys/types.h>
#include <dirent.h>


using namespace std;

typedef std::vector<std::string> stringvec;

void read_directory(const std::string& name, stringvec& v , char portal )
{
    DIR* dirp = opendir(name.c_str());
    struct dirent* dp;
    while ((dp = readdir(dirp)) != NULL ) 
    {
        string d = "\"";
        string current = d + portal + ":" + name +"/"+ dp->d_name + d;
        v.push_back(current);
    }
    v.erase(v.begin());
    v.erase(v.begin());
    closedir(dirp);
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

string dirctory_format(string dir)
{
    const string ss = "/";
    string finalDir = replaceStrChar(dir, "\\", ss);
    finalDir.replace(0, 2, "");

        return finalDir;
}
int main()
{ 
    string dir , finalDir;
    cin >> dir;
    char mainPortal = dir[0];
    finalDir = dirctory_format(dir);
    stringvec v;
    read_directory(finalDir, v , mainPortal);
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = replaceStrChar(v[i], "/", "\\\\");
    }
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<std::string>(std::cout, "\n"));
}
