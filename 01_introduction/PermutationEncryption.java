import java.util.Scanner;
public class PermutationEncryption
{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    try{
      while(sc.hasNext()){
        String key[] = sc.nextLine().split(" ");
        if(key[0]=="0")
          break;
        String text = sc.nextLine();
        int keyLength = Integer.parseInt(key[0]);
        int textLength = text.length();
        int extraSpaces = keyLength-textLength%keyLength;
        if(textLength%keyLength!=0){
          for(int i=0; i<extraSpaces; i++)
            text+=" ";
          textLength+=extraSpaces;
        }
        int sections = textLength/keyLength;
        String output = "";
        for(int i=0; i<sections; i++){
          String temp = text.substring(i*keyLength, (i+1)*keyLength);
          for(int j=1; j<key.length; j++){
            output+=temp.charAt(Integer.parseInt(key[j])-1);
          }
        }
        System.out.println("'"+output+"'");
      }
    }catch(Exception e){}
    sc.close();
  }
}
