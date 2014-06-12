import java.util.HashMap;

/*
 * Trie class
 */
public class Trie {

	private Node root; // root of the trie

	/*
	 * Constructs a new trie with empty root node
	 */

	public Trie() {
		root = new Node((char) 0);
	}

	/*
	 * Insert new word in the trie
	 * 
	 * @param newWord
	 */

	public void insertWord(String newWord) {

		int len = newWord.length();

		// point curr to the root
		Node curr = root;

		for (int i = 0; i < len; i++) {
			char c = newWord.charAt(i);

			// get the HashMap<K,V> of the current node
			HashMap<Character, Node> child = curr.getChildren();

			/*
			 * If the key exists, move the curr pointer to the value of the key
			 * Else create new node, put the new K-V pair into the HashMap and
			 * move the curr pointer
			 */

			if (child.containsKey(c)) {
				curr = child.get(c);
			} else {
				Node newNode = new Node(c);
				child.put(c, newNode);
				curr = newNode;
			}
		}

		// At the end of the word, mark it as end of the word
		curr.setWordEnd(true);

	}

	/*
	 * Search for the Longest Matched Prefix from the Trie
	 */

	public String getLongestPrefixMatch(String searchWord) {

		String output = "";
		Node curr = root;
		int len = searchWord.length();
		int matchPrev = 0;
		int i = 0;

		for (i = 0; i < len; i++) {
			char ch = searchWord.charAt(i);
			HashMap<Character, Node> child = curr.getChildren();

			/*
			 * If the key exists, add it to the return string, move pointer If
			 * node is an end point, Checkpoint the node by incrementing
			 * matchPrev
			 * 
			 * @param searchWord
			 */

			if (child.containsKey(ch)) {
				output += ch;
				curr = child.get(ch);

				if (curr.getEnd())
					matchPrev = i + 1;
			} else {
				break;
			}

		}

		// Handle the case of No Prefix Matched
		if (!curr.getEnd() && matchPrev == 0)
			return "No Match Found";

		// Handle the case when No Exact Prefix is matched but Prefix Exists
		if (!curr.getEnd())
			return output.substring(0, matchPrev);

		// Handle the case when Exact Prefix is Matched
		return output;

	}

}
