import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Day_6 {

	public static void main(String[] args) {
		char[] chars;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			
			chars = br.readLine().toCharArray();
			System.out.println("Part 1: " + markerIndex(chars,4));
			System.out.println("Part 2: " + markerIndex(chars,14));
		}
		catch (Exception e) {
			System.out.println(e);
			}
		  
	}
	
	public static int markerIndex(char[] chars, int length) {
		Map<Character, Integer> map = new HashMap<>();
		for(int i = 0; i < chars.length; i++ ) 
	    {
	      if(map.containsKey(chars[i])) {
	        int counter = map.get(chars[i]);
	        map.put(chars[i], ++counter);
	      } else map.put(chars[i], 1);
	      
	      if(map.size() == length) return i+1;
	      
	      else if(i >= length-1) {
	    	  int counter = map.get(chars[i-(length-1)]);
	    	  if(counter > 1) map.put(chars[i-(length-1)], --counter); 
	    	  else map.remove(chars[i-(length-1)]);
	      }
	    }
		return length;
	}
}
