/* George Solinareos - 19563448 */

Assignment 2 - AVL Library 
Documentation


Part 1: Introduction
--------------------
This assignment presents a general approach to the understanding of a search engine and its operations. Search engine operations
such as searching for a word, predicting the phrase, and ordering results by popularity are some of the key features that must be implemented through
the use of an AVL tree as provided for this assignment. The problems presented by this assignment involve utilising and manipulating an AVL Tree data
structure to achieve these functions.


Part 2: Algorithms
------------------
The most significant algorithms utilised in this assignment are:
	1. Insertion: The function used for inserting data items into the AVL Tree

			Pseudo Code (context of reading from a single file)
			---------------------------------------------------
			read file
			loop following process until end of file
				get word(key)
				if(no duplicates in tree found)
					set frequency to 1
					set the file name and location within file
					Insert data structure into AVL Tree

			Insertion function
			Create Node pointer that points to node:
			Initialise node with default values and the inserted data

			If there is no root, set inserted data as the top of the new tree
			Else, if data is smaller than root, move to left branch of root
			Else, if data is larger than root, move to right branch of root
			Repeat this process until the inserted data becomes a leaf

			Once the data has been entered, check for any imbalances
			Restructure the avl tree to maintain an appropriate height
			difference between the left and right hand side

			Return the top of the tree to the pointer within the first insert function

			Finished


	2. Reading a library text file: This file locates a specific text file that will
		be read as a text file containing a saved library from a previous run of the
		program. The program will read the text file and add every entry into its library

		Pseudo Code
		---------------------------------------------------
		Open and initialise input file stream

		Loop through every word in the file until a '*' is reached
			Deliminator to remove char brace or asterisks
			If the deliminator has an asterisks
				end of file has been reached; therefore break
			Store everything in front to a string character until a comma is reached (data key)
			Store the number as frequency
			Deliminate closing brace, opening brace, and opening bracket
			Loop through every location until a closing brace is found
				Store everything in front to a string until a comma is found (location text)
				Store word number
				Deliminate closing bracket
				Deliminate either an opening bracket or a closing brace
			With all data gathered, insert into AVL Tree
			Increment the counter
			Deliminate \n character

		Output the total count of words read

		Finished


Part 3: Data Structures
-----------------------
The main data structures utilised in this assignment were:
	1. AVL Tree:		The primary data structure of the program that stores all the words/phrases and acts as a library for the search engine
	2. DATA struct:		Represents a "node" of the AVL Tree; stores data such as the key word/phrase, its frequency, and its location within a text file
	3. Vector:			The vector was mainly used to store another data structure "pairs" which hold the locations of the key words/phrases. 
							Within these vectors are stored pairs. Vector was also used in some other functions such as storing every recorded 
							word to be utilised with inserting phrases,and storing words which are marked for deletion from the library.
	4. Pair:			Pair is used to store: the text file which the word was found in, and, the number of the word in the file in which it appeared in
	5. Priority Queue:	Used only for the search engine function. Stores all instances and similarities of an inputted word and organises them based on
							frequency before being displayed in that order


Part 4: Complexity Analysis
---------------------------
For the following chapter, a function will be stated along with its complexity (e.g. (logn), n^2, 2n, etc):
	Building the library:	n(logm)
		In terms of insertion alone, the amount of operations should be equivalent to the total amount of words read inside a text file
		If we are to take into account all operations including building the data before inserting it into the AVL_Tree then we end up with a
		complexity of about:
							n10(logm)
		Where "10" represents the total amount of actions taken for each word read inside of a file

	Rebuilding a dictionary from an add-on file:	n(6(6)4(logm))
		N is the equivalent to a single entry from the text file and the following numbers represent the steps taken to add that
		entry into the dictionary. The 6 encased inside the brackets refers to reading the file locations and word numbers of an entry.
		M refers to the total amount of words already in the dictionary as search operations will get longer as the tree grows in size.



Part 5: Conclusion
------------------
The most crucial aspect of this assignment was how to achieve all of the previously mentioned features of a search engine as efficiently as possible.
Some experiments with the AVL_Tree saw over 17,000 entries being added into the tree and that is only from one movie script. Storing and guessing every possible
combination of words that can relate to a near infinite amount of sites on the internet is a much more grueling task in comparison.

If an AVL tree ever did reach such a large state, algorithm efficiency would play a huge impact in affecting the speed of the search engine itself. In this assignment,
I have altered and added to the AVL Tree provided by us to achieve these search functions that a regular search engine would have. Besides the AVL Tree, I have written
along side it code that can read from a file/s (with or without phrases), print an index dictionary showing word frequency and their location, removing words from the
tree based upon their overall frequency, and saving a tree to a text file to be later loaded into a fresh library.