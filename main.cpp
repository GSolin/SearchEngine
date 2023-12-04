/* George Solinareos - 19563448 */
#include	<algorithm>
#include	<fstream>
#include	<iomanip>
#include	<iostream>
#include	<map>
#include	<stdlib.h>
#include	<string>
#include	<vector>
using namespace std;
#include	"AVL_ADT.h"
#include	"LibraryFunctions.h"





int main() {
	cout << setw(16) << " " << "| WELCOME TO THE AVL TREE SEARCH ENGINE |\n" << endl;
	AvlTree<DATA, string> tree;

	int selection = -1;
	do {
		cout << setfill(' ');
		cout                       << setw(46) << "-------------------\n"
			                        << setw(45) << "SELECT A FUNCTION\n"
			                       << setw(46) << "-------------------\n" << endl
			<< "1. Record a single file to library" << setw(6) << " "	 << "7. Search for word\n"
			<< "2. Record multiple files to library" << setw(5) << " "   << "8. Record a single file to library (with phrases)\n"
			<< "3. Print index dictionary" << setw(15) << " "			 << "9. Remove filler words from dictionary\n"
			<< "4. Print AVL Tree" << setw(22) << " "					<< "10. Delete words based on minimum frequency\n"
			<< "5. Save library to file" << setw(16) << " "				<< "11. Display dictionary; Descending by frequency\n"
			<< "6. Read library from a file" << setw(13) << " "  		 << "0. Exit program\n"

			<< "\nSelect an option: ";
		cin >> selection;
		cout << endl;

		switch (selection) {
		case 1:		recordSingleFile(tree);		break;
		case 2:		recordMultipleFiles(tree);	break;
		case 3:		printIndex(tree);			break;
		case 4:		tree.AVL_Print();			break;
		case 5:		saveToFile(tree);			break;
		case 6:		readFromFile(tree);			break;
		case 7:		searchForWord(tree);		break;
		case 8:		recordPhraseLibrary(tree);	break;
		case 9:		deleteFiller(tree);			break;
		case 10:	lowFreqWord(tree);			break;
		case 11:	frequencyPriority(tree);	break;
		}
							
	} while (selection != 0);

	cout << "\nTHANK YOU FOR USING THE AVL TREE SEARCH ENGINE, GOODBYE\n";

	return 0;
}