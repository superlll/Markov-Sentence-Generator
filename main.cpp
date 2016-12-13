#include <iostream>
#include <map>
#include <deque>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <string>
#include <cstdio>
#include <sstream>
#include <ctime>
#include <fstream>


using namespace std;


     int NPREF  =  2;         //number of prefix
     int MAXGEN  =  50000 ; //The max of the sentence

typedef deque<string> Prefix; 
map<Prefix,vector<string> > statetab; // combine prefix and suffix

char  NONWORD[] = " "; // initial prefix

void add(Prefix &prefix, const string &s)
{
     if(prefix.size() == NPREF) // when number of prefix equal to NPREF ,W1,w2 change into w2，w3
     {
          statetab[prefix].push_back(s);
          prefix.pop_front();
     }
     prefix.push_back(s);
}

void build(Prefix &prefix, istream &in)//create statistics
{
     string buf;
     while(in >> buf)
          add(prefix,buf);
}

bool IncludeCh(string str, char ch) {
    int i;
    bool has = false;
    for(i = 0; str[i]; ++i) {
        if(str[i] == ch) 
            return true;
    }
    return false;
}

void generate(int nwords)
{
     Prefix prefix;
     int i;
     int j = 0;
     srand(time(NULL));
     string str1, str2;
     cout << "please input prefix 1: " ;
     cin >> str1;
     add(prefix, str1);
     cout << "please input prefix 2: " ;
     cin >> str2;
     add(prefix, str2);
     cout << str1 << " " << str2 << " ";

     for(i = 0; i < nwords; i++)
     {
          vector<string> & suf = statetab[prefix];
          //cout<<"prefix:"<<prefix[0]<<" suf "<<suf[0]<<endl;
          const string &w = suf[rand() % suf.size()];
          if(w == NONWORD)
               break;
			cout << w <<" ";
		  if(IncludeCh(w,'.'))  
		  { 
			  j++;
		//	  cout<<"j:"<<j<<endl;
		  }
		  if(j>=3) break;
          prefix.pop_front();
          prefix.push_back(w);
     }

     cout<<endl;
}

string readFileInfoString(char * filename)
{
    ifstream ifile(filename);
    ostringstream buf;
    char ch;
    while(buf&&ifile.get(ch))
    buf.put(ch);  //return the string which combined with the buf
    return buf.str();
}

int main()
{
     int nwords = MAXGEN;
     Prefix prefix;
    char * fn = "example.txt";
    string str;
    str = readFileInfoString(fn);
//    cout << "read: " << str << endl; 

//     string sentence = "Show your flowchars and conceal your tables and I will be mystified. Show your tables and your flowcharts will be obvious. (end)";
     istringstream in(str); //input in C++ style 
     //freopen("mkov.txt","r",stdin);
     for(int i = 0; i < NPREF; i++)
          add(prefix,NONWORD);
     build(prefix,in);
     add(prefix,NONWORD);
     generate(nwords);
     return 0;
}
