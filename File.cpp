#include "File.h"

                      
bool RFile::FetchText(std::string filePath, std::vector<std::string>& wordCache)
{
	if (filePath.empty()) return false;

	//Opening the file based on the given file path.
	std::ifstream file(filePath);
	if (!file.fail())
	{
		std::string foundWord{};
		while (file >> foundWord)
		{
			//Caching all found words in the file.
			wordCache.push_back(foundWord);
		}
	}
	else { std::cerr << "[-] Failed to open file at " << filePath << std::endl; return false; }
}

void RFile::SearchDocument(std::vector<std::string>& dictionaryCache, std::vector<std::string>& documentCache)
{
	if (dictionaryCache.empty() && documentCache.empty()) return;

	int errorCount = 0;
	for (int i{}; i < documentCache.size(); i++)
	{
		bool realWordFound = false;
		for (int j{}; j < dictionaryCache.size(); j++)
		{
			if (documentCache.at(i) == dictionaryCache.at(j)) 
			{ 
				realWordFound = true;
				break; 
			}
		}
		if (!realWordFound)
		{
			std::cout << documentCache.at(i) << ": " << " Does not exist." << "\n";
			errorCount++;
		}
	}
	std::cout << "Found " << errorCount << " misspellings" << std::endl;
}