/****************************************************************************
name: Most Frequent Words
author: Terry
date: 2019-08-16
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue> 			// for priority_queue<T>
#include <boost/timer.hpp>  // for timer
using namespace std;

int main(int argc, char* argv[])
{
	boost::timer time; 		// record the elapsed time
	string word;            // the word in the file
	map <string, int> freq; // hash map for the words
	map <string, int>::const_iterator wordsit; // iterator for the hash map

	fstream test_file;      // test file from input argv
	test_file.open(argv[1], ios::in); 

	if (!test_file.is_open())    // open attempt failed
	{
		cerr << "Error message : Unable to open "<< argv[1] << endl; 
		return 1; 				 // exit
	}
	else
	{
		// Create a hash table and load file into string
		while (test_file >> word)
		{
			freq[word]++;
		}
		test_file.close();		// close the file
	}

	cout<<"There are "<<freq.size()<< " different words in this file." <<endl;  

	// Get the top 10 frequent words
	priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>> > most_words; 
    for (wordsit = freq.begin(); wordsit != freq.end(); wordsit++)
    {  
        most_words.push(make_pair(wordsit->second,wordsit->first));  
        if (most_words.size()>10)  
        {  
            most_words.pop();  
        }  
    }  

	// Print out ten most frequent words
	cout<<"The most ten frequent words are: \n"<<endl;
	cout.width(8);
    cout<<"Words"<<":";
	cout.width(6);
	cout<<"Times"<<endl;  
    most_words.pop();

    while(!most_words.empty())  
    {  
		cout.width(8);
        cout<<most_words.top().second<<":";
		cout.width(6);
		cout<<most_words.top().first<<endl;  
        most_words.pop();  
    } 

	// Print out elapsed time
    cout<<"\nTime elapsed :"<<time.elapsed()<<"s"<<endl;  
	return 0;
}