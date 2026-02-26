#pragma once

/*
   Put an explination.
*/

#include <iostream>
#include <fstream>
#include <vector>

struct RFile
{   
	std::vector<std::string> dictionaryWords;
	std::vector<std::string> documentWords;

	/*
	   Opens a text file based on the given path, and caches the words into 
	   the passed vector.
	*/
	 bool FetchText(std::string filePath, std::vector<std::string>& wordCache);

	 /*
	    Checks the document words for misspellings.
	 */
	 void SearchDocument(std::vector<std::string>& dictionaryCache, std::vector<std::string>& DocumentCache);

	RFile() :
	dictionaryWords(), documentWords()
	{ }
};