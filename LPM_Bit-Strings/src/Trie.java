/*
 * Trie class
 */

public class Trie {
    
	private Node root; // points to the root of the Trie
    
	public Trie() {
        
		// set root to be -1 to distinguish among other nodes
		root = new Node(-1);
	}
    
	/*
	 * An Int to Int Array converter
	 *
	 * @param number
	 */
    
	public int[] Int2Array(int number) {
        
		String numString = Integer.toString(number);
		int lenArray = numString.length();
		int[] numArr = new int[lenArray];
        
		for (int i = 0; i < lenArray; i++) {
			String temp = "" + numString.charAt(i);
			numArr[i] = Integer.parseInt(temp);
		}
        
		return numArr;
        
	}
    
	/*
	 * Insert number in the Trie Structure
	 *
	 * @param num
	 */
    
	public void insertNumber(int num) {
        
		int[] arr = Int2Array(num);
		Node curr = root;
		Node left = null;
		Node right = null;
        
		for (int i = 1; i < arr.length; i++) {
            
			int newBit = arr[i];
            
			// left and right the child nodes of curr
			left = curr.getLeftChild();
			right = curr.getRightChild();
            
			/*
			 * We want 1 to always be on the left and 0 to be on the right
			 */
            
			if (newBit == 1) {
				if (left != null)
					curr = left;
				else {
					curr = curr.setLeftChild();
				}
			}
            
			if (newBit == 0) {
				if (right != null)
					curr = right;
				else {
					curr = curr.setRightChild();
				}
			}
            
		}
        
		// Set the marker to true at the end
		curr.setEnd(true);
        
	}
    
	/*
	 * Get the Longest Prefixed Matched
	 *
	 * @param searchNum
	 */
    
	public String getLongestPrefixMatch(int searchNum) {
        
		int[] newNum = Int2Array(searchNum);
		int len = newNum.length;
		Node curr = root;
		String output = "";
		int prevMatch = 0;
        
		// Handle the case when the Trie is empty
		if (curr.getLeftChild() == null && curr.getRightChild() == null) {
			return "No Prefix Matched as Trie is empty";
		}
        
		/*
		 * Java recognizes 001 as 0, so always start the bit string with '9' so
		 * that Java does not ignore any 0 in the beginning. But we don't want a
		 * 9 in the actual array so start the counter at 1
		 */
        
		for (int i = 1; i < len; i++) {
			int bit = newNum[i];
			if (curr.getLeftChild() != null || curr.getRightChild() != null) {
				output += bit;
				if (curr.getLeftChild() != null && curr.getRightChild() == null)
					curr = curr.getLeftChild();
				else if (curr.getRightChild() != null
                         && curr.getLeftChild() == null)
					curr = curr.getRightChild();
				else {
					if (bit == 0)
						curr = curr.getRightChild();
					else
						curr = curr.getLeftChild();
				}
                
				if (curr.getEnd())
					prevMatch = i + 1;
			} else {
				break;
			}
            
		}
        
		if (!curr.getEnd()) {
			return output.substring(0, prevMatch);
		}
        
		return output;
	}
    
	public static void main(String[] args) {
        
		// Start all numbers with 9 or any number except 0 and 1
		Trie dict = new Trie();
		dict.insertNumber(9100);
		dict.insertNumber(9101);
		dict.insertNumber(9010);
		System.out.println(dict.getLongestPrefixMatch(901001)); // 010
	}
    
}
