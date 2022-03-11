This is a C++ project simulating "Huffman coding", algorithm for data compression.

 - How does it work?

Compressing: 

 - I read the file to be compressed and I create a binary tree from it.
	A tree is made out of nodes. Every node contains a symbol and a number of times that
	symbol has occurred in the file.
	Only the leaves of the tree contain symbols. The nodes without symbols keep only the
	number of occurrences of symbols of nodes that are children of this node.

	example: abbcc ->

		      (5)
	
	      (3)	   (2, b)

	(1,a)	(2, c)

	the more occurrences of a symbol the shorter is the path from the root.

	Every symbol has assigned substitution out of zeros and ones. Left node add to the path 
	1, right node adds 0.
	a -> 11, b -> 0, c -> 10
	
	Every symbol with shorted string of 0&1 gets zeros on the front to reach the max depth of
	the tree.
	So b -> 00 (one 0 on the front)
	This is for when we read the 0&1 all the letters to have the same length of 0&1
	abbcc -> 11001010
	
	every 8 bits of info are transformed into decimal number system. A 0 is always added at the end.
	11001010 -> 202 0

	The final file with compressed information starts with the tree transformed into string.
	followed by the file data.

	(5(3(1a)(2c))(2b))	
	202 0

	The tree is saved for decompression of the file.

Decompression:

	First we parse the tree into c++ tree data structure. 
	Then we parse the data and for every n posl of 0&1 (where n = depth of the tree)
	The go through the nodes until we reach a leaf with the compressed symbol.

	Final result is a new file with the original data.


	
	

