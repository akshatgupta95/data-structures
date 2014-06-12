
public class OutputTest {
	
	public static void main(String[] args) {
		Trie tree = new Trie();
		tree.insertWord("z");
		tree.insertWord("za");
		tree.insertWord("zap");
		tree.insertWord("zapp");
		tree.insertWord("zappo");
		tree.insertWord("am");
		tree.insertWord("ammo");
		
		System.out.println(tree.getLongestPrefixMatch("amm")); // am
	}

}
