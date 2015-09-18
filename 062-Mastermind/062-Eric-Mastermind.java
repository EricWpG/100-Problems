import java.util.Scanner;

public class mastermindGame {
  
  static final int MAX_GUESSES = 10;
  
  public static void main(String[] args) {
    
    Scanner userInput = new Scanner(System.in);
    int random = (int)(Math.random() * 9999);
    String answer = String.format("%04d", random);
    // Uncomment this to see the answer     System.out.println(answer);
    System.out.println("Guess a sequence of 4 digits and try to solve the puzzle. You have "+MAX_GUESSES+" guesses.");
    int guesses = 0;
    String currentGuess;
    
    while (guesses < MAX_GUESSES){
      guesses += 1;
      System.out.print("Guess #" + guesses + " : " );
      currentGuess = userInput.nextLine();
      if (currentGuess.equals(answer){
        System.out.println("Congratulations, you got it right!");
        System.exit(1);
      }
      System.out.println(giveHints(currentGuess, answer));
    }
    System.out.println("You lose, try again.");
    
  }
  
  public static String giveHints(String input, String answer){
    
    if (input.length() != 4){
      return ("The number you entered is invalid, but I'm still deducting a guess.");
    }
    
    int right = 0;
    int misplaced = 0;
    
    for (int i=0;i<4;i++){
      if (input.charAt(i) == answer.charAt(i)){
        right += 1;
      }else{
        for (int j=0;j<4;j++){
          if (j != i){
            if (input.charAt(i) == answer.charAt(j)){
              misplaced += 1;
              break;
            }
          }
        }
      }
    }
    
    int wrong = 4 - (right + misplaced);
    
    return ("You got " + right + " right, " + wrong + " wrong and " + misplaced + " misplaced.");
    
  }
  
}
