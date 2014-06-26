
/*
 * Node Class
 */

public class Node {
	
	/*
	 * number is the value of each node
	 * end is whether it is the end of a string or not
	 * leftChild is the left node of the current node
	 * rightChild is the right node of the current node
	 */
	
	private int number;
	private boolean end;
	private Node leftChild;
	private Node rightChild;
	
	/*
	 * Node constructor
	 */
	
	public Node(){
		// Default Constructor (no need for this in the program)
	}
	
	public Node(int newNum){
		this.number = newNum;
		this.end = false;
		this.leftChild = null;
		this.rightChild = null;
	}
	
	public void setEnd(boolean wordEnd){
		this.end = wordEnd;
	}
		
	public Node getRightChild(){
		return this.rightChild;
	}
	
	public Node getLeftChild(){
		return this.leftChild;
	}
	
	public void setNumber(int num){
		this.number = num;
	}
	
	public int getNumber(){
		return this.number;
	}
	
	public boolean getEnd(){
		return this.end;
	}
	
	/*
	 * leftChild always stands for 1
	 */
	
	public Node setLeftChild(){
		this.leftChild = new Node(1);
		return this.leftChild;
	}
	
	/*
	 * rightChild always stands for 0
	 */
	
	public Node setRightChild(){
		this.rightChild = new Node(0);
		return this.rightChild;
	}

}
