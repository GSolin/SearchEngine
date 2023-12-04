/* George Solinareos - 19563448 */
#pragma once
struct DATA
{
	// Word || Frequency || Appearances
	string	key;
	int		frequency;
	vector<pair<string, int>> fileInfo;
	
	// Operator overloading for the priority queue
	bool operator<(const DATA& d) const {
		return frequency < d.frequency;
	}
};

// Used for displaying the amount of words read in a file
int totalCount;

/* print:				Function used for printing the contents of a DATA structure.
						Mostly parsed through to other functions as a function pointer	*/
void print(DATA ss) {
	cout << left << setfill('.') << setw(15) << ss.key
		 << right << setw(8) << ss.frequency << endl;
	for (int i = 0; i < ss.fileInfo.size(); ++i) {
		cout << "(" << ss.fileInfo[i].first << ", " << ss.fileInfo[i].second << ")" << endl;
	}
	cout << endl;
}

/* printIndex:			Prints a header at the top of the index dictionary				*/
void printIndex(AvlTree<DATA, string> &tree) {
	if (!tree.AVL_Empty()) {
		cout << setfill(' ')
			<< "--------------------" << endl
			<< left << setw(8) << "| INDEX DICTIONARY |" << endl
			<< "--------------------" << endl;
		tree.AVL_Traverse(print);
	}
	else
		cout << "No library to print!\n";
}

/* filterWord:			Every word that is recorded from a file is filtered of any
						capital letters or punctuation. This avoids double entries
						(e.g Cat, cat)													*/
string filterWord(string text) {
	text.erase(remove_if(text.begin(), text.end(), ispunct), text.end());
	for_each(text.begin(), text.begin() + 1, [](char& c) {
		c = tolower(c);
		});
	return text;
}

/* searchForWord:		Asks the user for the word they wish to search for before
						parsing it through to the main function inside AVL_ADT that
						searches for nodes similar to their input						*/
void searchForWord(AvlTree<DATA, string> &tree) {
	if (!tree.AVL_Empty()) {
		priority_queue<DATA> ordered;
		cout << "Insert word to search for (input # to end): ";
		string filter;
		cin >> filter;
		do {
			cout << endl;
			tree.AVL_NodeSimilarity(ordered, filter);
			for (int i = 0; i < ordered.size(); i++) {
				print(ordered.top());
				ordered.pop();
			}
			cout << endl;
			cin >> filter;
		} while (filter != "#");
	}
	else
		cout << "Library is empty!" << endl;
}

/* recordPhraseLibrary:	Asks user to input the name of a file to read and add
						to the library. The difference between this and the other
						file reading functions is that this records phrases as node
						as well as singular words										*/
void recordPhraseLibrary(AvlTree<DATA, string>& tree) {
	ifstream inputFile;
	string txtFile;

	cout << "Enter your text file to read (instream.txt OR beemoviescript.txt)\n";
	cin >> txtFile;

	inputFile.open(txtFile);
	if (inputFile.fail()) {
		cout << "Failed to open file";
		exit(1);
	}

	vector<string> recordedWords;

	cout << "Now reading " << txtFile << endl;
	string wordSearch;
	while (inputFile >> wordSearch) {
		wordSearch = filterWord(wordSearch);
		recordedWords.push_back(wordSearch);
	}
	recordedWords.push_back("0"); recordedWords.push_back("0");

	int position = 1;
	DATA newItem;
	for (int i = 0; i < recordedWords.size()-2; i++) {
		string phrase;
		// Phrase: 1 word
		phrase += recordedWords[i];
		newItem.key = phrase;
		if (!tree.AVL_Check(phrase, position, txtFile)) {
			pair<string, int> current;
			vector<pair<string, int>> temp;
			newItem.frequency = 1;
			current.first = txtFile;
			current.second = position;
			temp.push_back(current);
			newItem.fileInfo = temp;
			tree.AVL_Insert(newItem);
		}

		// Phrase: 2 words
		if (recordedWords[i + 1] != "0") {
			phrase += " " + recordedWords[i + 1];
			newItem.key = phrase;
			if (!tree.AVL_Check(phrase, position, txtFile)) {
				pair<string, int> current;
				vector<pair<string, int>> temp;
				newItem.frequency = 1;
				current.first = txtFile;
				current.second = position;
				temp.push_back(current);
				newItem.fileInfo = temp;
				tree.AVL_Insert(newItem);
			}
		}

		if (recordedWords[i + 2] != "0") {
			//Phrase: 3 words
			phrase += " " + recordedWords[i + 2];
			newItem.key = phrase;
			if (!tree.AVL_Check(phrase, position, txtFile)) {
				pair<string, int> current;
				vector<pair<string, int>> temp;
				newItem.frequency = 1;
				current.first = txtFile;
				current.second = position;
				temp.push_back(current);
				newItem.fileInfo = temp;
				tree.AVL_Insert(newItem);
			}
		}

		position++;
	}

	totalCount = tree.AVL_Count();
	cout << "Total words in dictionary: " << totalCount << endl;
	inputFile.close();
}

/* deleteFiller:		Removes filler/basic words from the dictionary that will
						inevitably have a high frequency within text files
						(e.g. a, the, is, to, etc.)										*/
void deleteFiller(AvlTree<DATA, string> &tree) {
	string marked[] = { "the", "a", "an", "will", "be", "there", "their",
					   "where", "why", "who", "what", "whats", "when", "you", "youre",
					   "your", "youll", "his", "him", "her", "is", "it", "its",
					   "how", "do", "while", "for", "if", "to", "we", "i", "of"
						"this", "and", "that", "of", "are", "our"};

	if (!tree.AVL_Empty()) {
		int x = sizeof(marked) / sizeof(marked[0]);;
		int d = 0;
		for (int i = 0; i < x; i++) {
			if (tree.AVL_Delete(marked[i]))
				d++;
		}
		cout << "Total amount of words deleted: " << d << endl;
	}
	else
		cout << "No library!\n";
	
}

/* recordSingleFile:	Asks user to input the name of a file to read and add
						to the library													*/
void recordSingleFile(AvlTree<DATA, string> &tree) {
	ifstream inputFile;
	string txtFile;

	cout << "Enter your text file to read (instream.txt OR beemoviescript.txt)\n";
	cin >> txtFile;

	inputFile.open(txtFile);
	if (inputFile.fail()) {
		cout << "Failed to open file";
		exit(1);
	}
	cout << "Now reading " << txtFile;
	int position = 1;
	string wordSearch;
	DATA newItem;
	while (inputFile >> wordSearch) {
		wordSearch = filterWord(wordSearch);
		newItem.key = wordSearch;
		if (!tree.AVL_Check(wordSearch, position, txtFile)) {
			pair<string, int> current;
			vector<pair<string, int>> temp;
			newItem.frequency = 1;
			current.first = txtFile;
			current.second = position;
			temp.push_back(current);
			newItem.fileInfo = temp;
			tree.AVL_Insert(newItem);
		}
		position++;
	}

	totalCount = tree.AVL_Count();
	cout << "Total words in dictionary: " << totalCount << endl;
	inputFile.close();
}

/* recordMultipleFiles:	Reads all the text files found within a directory and
						adds them all to the library									*/
void recordMultipleFiles(AvlTree<DATA, string> &tree) {
	string files[] = { "textFiles/instream1.txt", "textFiles/instream2.txt",
					   "textFiles/instream3.txt", "textFiles/instream4.txt",
					   "textFiles/instream5.txt", "textFiles/instream6.txt"};

	ifstream inputFile;

	int x = sizeof(files) / sizeof(files[0]);
	for (int i = 0; i < x; i++) {
		int count = 0;
		inputFile.open(files[i]);
		cout << "Now reading " << '"' << files[i] << '"' << endl;
		if (inputFile.fail()) {
			cout << "Failed to open file";
			exit(1);
		}
		int position = 1;
		string wordSearch;
		DATA newItem;
		while (inputFile >> wordSearch) {
			wordSearch = filterWord(wordSearch);
			newItem.key = wordSearch;
			if (!tree.AVL_Check(wordSearch, position, files[i])) {
				vector<pair<string, int>> temp;
				pair<string, int> current;
				newItem.frequency = 1;
				current.first = files[i];
				current.second = position;
				temp.push_back(current);
				newItem.fileInfo = temp;
				tree.AVL_Insert(newItem);
			}
			position++;
			count++;
		}
		inputFile.close();

		cout << "Words counted: " << count << endl;
	}

	totalCount = tree.AVL_Count();
	cout << "Total words in dictionary: " << totalCount << endl;
}

/* saveToFile:			Saves the generated library to a text file to be
						read/used during another instance of the program				*/
void saveToFile(AvlTree<DATA, string>& tree) {
	if (!tree.AVL_Empty()) {
		tree.AVL_SaveLibrary();
	}
	else
		cout << "No library to save!\n";
	
}

/* readFromFile:		Generates a library by reading a saved library
						output file														*/	
void readFromFile(AvlTree<DATA, string>& tree) {
	int count = 0;
	ifstream inLibrary;
	inLibrary.open("outstream.txt");
	if (inLibrary.fail()) {
		cout << "Failed to read library\n";
		exit(1);
	}
	
	string line;
	while (!inLibrary.eof()){
		char deliminator;
		DATA newItem;
		vector<pair<string, int>> temp;
		inLibrary.get(deliminator);						// [
		if (deliminator == '*')
			break;
		getline(inLibrary, newItem.key, ',');			// Word
		inLibrary >> newItem.frequency;					// Frequency
		inLibrary.get(deliminator);						// ]
		inLibrary.get(deliminator);						// [
		inLibrary.get(deliminator);						// (
		while (deliminator != ']') {
			pair<string, int> current;
			string	fl;
			int		num;
			getline(inLibrary, fl, ',');				// Location
			inLibrary >> num;							// Word Count
			current.first = fl; current.second = num;
			temp.push_back(current);
			inLibrary.get(deliminator);					// )
			inLibrary.get(deliminator);					// ( OR ]
		}
		newItem.fileInfo = temp;
		tree.AVL_Insert(newItem);
		count++;
		inLibrary.get(deliminator);					// \n
	}

	cout << "Total words read from file: " << count << endl;

	return;
}

/* lowFrequencyWord:	Asks the user to input a minimum frequency requirement
						for every word in the library. Removes every word that
						falls beneath this requirement									*/
void lowFreqWord(AvlTree<DATA, string>& tree) {
	if (!tree.AVL_Empty()) {
		int frequency;
		int d = 0;
		cout << "Select minimum frequency" << endl
			<< "Any words that fall below the minimum will be removed" << endl
			<< "Frequency: ";
		cin >> frequency;
		vector<string> choppingBlock;
		tree.AVL_Mark(frequency, choppingBlock);
		for (int i = 0; i < choppingBlock.size(); i++) {
			if (tree.AVL_Delete(choppingBlock[i]))
				d++;
		}
		cout << "\nTotal words deleted: " << d << endl;
	}
	else
		cout << "No library!\n";
	
}

/* frequencyriority:	Prints the library in order of descending frequency				*/
void frequencyPriority(AvlTree<DATA, string>& tree) {
	priority_queue<DATA> ordered;
	tree.AVL_PriorityQueue(ordered);
	for (int i = 0; i < ordered.size(); i++) {
		print(ordered.top());
		ordered.pop();
	}
	return;
}