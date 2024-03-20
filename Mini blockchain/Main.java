import java.util.*;
import com.google.gson.*;

public class Main {

	public static Boolean isChainValid() {
		Block currentBlock;
		Block previousBlock;
		String hashTarget=new String(new char [difficulty]).replace('\0','0');
		for(int i=1;i<blockchain.size();i++) {
			currentBlock=blockchain.get(i);
			previousBlock=blockchain.get(i-1);
			if(!currentBlock.hash.equals(currentBlock.calculateHash())) {
				System.out.print("Current hashes not equal!");
				return false;
			}
			if(!previousBlock.hash.equals(currentBlock.previousHash)) {
				System.out.println("Previous hashes not equal");
				return false;
				
			}
			if(!currentBlock.hash.substring(0, difficulty).equals(hashTarget)) {
				System.out.println("This block hasn't been mined");
				return false;
			}
		}
		
		return true;
	}
	
	public static ArrayList<Block> blockchain=new ArrayList<Block>();
	public static int difficulty=2;
	
	public static void main(String[] args) {
		blockchain.add(new Block("1000$","0"));
		System.out.println("Trying to Mine block 1... ");
		blockchain.get(0).mineBlock(difficulty);
		System.out.println();
		blockchain.add(new Block("2000$",blockchain.get(blockchain.size()-1).hash));
		System.out.println("Trying to Mine block 2... ");
		blockchain.get(1).mineBlock(difficulty);
		System.out.println();
		blockchain.add(new Block("5000$",blockchain.get(blockchain.size()-1).hash));
		System.out.println("Trying to Mine block 3... ");
		blockchain.get(2).mineBlock(difficulty);
		System.out.println();
		
		System.out.println("Valid blockchain: " + isChainValid());
	
		
		

	}

}