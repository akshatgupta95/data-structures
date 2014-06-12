import java.util.HashMap;

/*
 * Node class
 */

public class Node {

	/*
	 * letter stores the actual letter of the string in the node wordEnd stores
	 * whether the node represents if the node is the end point of the a word
	 * children is a HashMap which stores a K-V pair K -> letter of the word and
	 * V -> pointer to the child node
	 */
	private char letter;
	private boolean wordEnd;
	private HashMap<Character, Node> children;

	/*
	 * Node Constructor
	 */

	public Node(char newLetter) {
		this.letter = newLetter;
		this.wordEnd = false;
		children = new HashMap<Character, Node>();
	}

	public char getLetter() {
		return this.letter;
	}

	public boolean getEnd() {
		return this.wordEnd;
	}

	public HashMap<Character, Node> getChildren() {
		return this.children;
	}

	public void setWordEnd(boolean marker) {
		this.wordEnd = marker;
	}

}
