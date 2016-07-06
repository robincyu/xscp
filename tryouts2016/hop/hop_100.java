import java.util.Scanner;

public class Solution {
    
    public static void main(String[] args)
    {
        long pre[] = new long [200005];
        
        try(Scanner inputUser = new Scanner(System.in);)
        {
            int n = inputUser.nextInt();
            int m = inputUser.nextInt();
            
            for (int i = 0; i < n; i++)
            {
                int tmp = inputUser.nextInt();
                if (i < 2)
                    pre[i] = tmp;
                else
                    pre[i] = pre[i-2] + tmp;
            }
            
            while (m-- > 0)
            {
                int l = inputUser.nextInt();
                int r = inputUser.nextInt();
                l--; r--;
                if (l < 2)
                    System.out.printf("%d\n", pre[r]);
                else
                    System.out.printf("%d\n", pre[r] - pre[l-2]);
            }
        }
        catch(Exception e)
        {
        }
    }
}
