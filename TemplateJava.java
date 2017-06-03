import java.util.*;
import java.io.*;

public class Template {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("EnterFile.txt"));
        if (args.length > 0) {
            System.setOut(new PrintStream(new FileOutputStream("SubmitFile.txt")));
        }
        int T = Integer.parseInt(sc.next());
        //
        for (int t = 1; t <= T; t++) {
            //
        }
        sc.close();
    }
}