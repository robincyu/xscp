import java.util.Scanner;

public class Reproduction {
	
	public static void main(String[] args)
	{
		boolean isprime[] = new boolean [1000020];
		int primes[] = new int [1000020];
		int dans[] = new int [64];
		int prime_count = 0;
		isprime[0] = false;
		isprime[1] = false;
		for (int i = 2; i < 1000020; i++)
			isprime[i] = true;
		for (int i = 2; i < 1000020; i++)
		{
			if (isprime[i])
			{
				primes[prime_count] = i;
				prime_count++;
				for (int j = 2*i; j < 1000020; j+=i)
					isprime[j] = false;
			}
		}
		
		try(Scanner inputUser = new Scanner(System.in);)
		{
			int tc = inputUser.nextInt();
			
			while (tc-- > 0)
			{
				long n = inputUser.nextLong();
				int k = inputUser.nextInt();
				int count = 0;
				
				for (int i = 0; i < prime_count && n > 1 && count+1 < k; i++)
				{
					while (n % primes[i] == 0 && count+1 < k)
					{
						dans[count] = primes[i];
						count++;
						n /= primes[i];
					}
				}

				if (n > 1 && count+1 == k)
				{
					System.out.printf("%d", n);
					for (int i = 0; i < count; i++)
					{
						System.out.printf(" %d", dans[i]);
					}
					System.out.printf("\n");
				}
				else
					System.out.printf("-1\n");
			}
		}
		catch(Exception e)
		{
		}
	}
}
