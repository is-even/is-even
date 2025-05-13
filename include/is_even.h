#ifndef IS_EVEN_H
#define IS_EVEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Any method must return 1 if true, 0 if false, -1 if an error occurred
 */

#define IS_EVEN_ERROR -1
#define IS_EVEN_FALSE 0
#define IS_EVEN_TRUE 1

/*
 * Method0: Standard way to test if a number is even.
 */
int method0(int n);
/*
 * Method1: Test if a number is even with & operator.
 */
int method1(int n);
/*
 * Method2: Test if the last number of the string representation
 * of a number is even. Only needs to test numbers between 0 and 9.
 */
int method2(int n);
/*
 * Method3: Test if a number is odd and returns the opposite.
 */
int method3(int n);
/*
 * Method4: Test if exists a number that, multiplied by 2, gives the number to test.
 * If the multiplication results in a number bigger than the number to test, returns false.
 * Only works with positive numbers.
 */
int method4(int n);
/*
 * Method5: Subtract 2 while the number is greater then 0.
 * If the final result is 0 return true, else return false.
 * Only works with positive numbers
 */
int method5(int n);
/*
 * Method6: Divide the number to test by 2.0 (double) and test if the result is the same
 * dividing by 2 (integer):
 */
int method6(int n);
/*
 * Method7: Creates a .c source file that contains code to check wether a number is even
 * or not. Compiles it, calls it and returns the exit status of the program.
 */
int method7(int n);
/*
 * Method8: Since the sum of two even numbers is still an even number, generate an even number
 * and add the number to test. If it is even, then the number to test is even.
 */
int method8(int n);
/*
 * Method9: A very simple implementation of AI model based on Naive Bayes classification.
 * It fills a dataset with random generated numbers, stores the least significant
 * bit and the actual parity of the numbers.
 */
int method9(int n);

// Functions declarations
int method0(int n)
{
	return n % 2 == 0;
}

int method1(int n)
{
	return (n & 1) == 0;
}

int method2(int n)
{
	int length = snprintf(NULL, 0, "%d", n);
	char *buff = malloc(sizeof(char) * length + 1);
	if (buff == NULL) {
		return IS_EVEN_ERROR;
	}
	sprintf(buff, "%d", n);
	int is_even = 0;
	if (buff[length - 1] == '0' || buff[length - 1] == '2' ||
		buff[length - 1] == '4' || buff[length - 1] == '6' ||
		buff[length - 1] == '8') {
		is_even = IS_EVEN_TRUE;
	}
	free(buff);
	return is_even;
}

int method3(int n)
{
	int is_odd(int n)
	{
		return n % 2 == 1;
	}
	
	return !is_odd(n);
}

int method4(int n)
{
	int is_even = 0;
	for (int i = 0; i * 2 <= n; i++) {
		if (i * 2 == n) {
			is_even = IS_EVEN_TRUE;
		}
	}
	return is_even;
}

int method5(int n)
{
	while (n > 0) {
		n -= 2;
	}
	return n == 0 ? IS_EVEN_TRUE : IS_EVEN_FALSE;
}

int method6(int n)
{
	double floating_point_res = n / 2.0;
	n /= 2;
	return n == floating_point_res;
}

int method7(int n)
{
	// TODO refactor this and check for errors (also check if gcc is installed)
	const char *src_code = 
	"#include<stdlib.h>\n\n" 
	"int main(int argc, char *argv[])\n{\n" 
	"\tif (argc != 2)\n\t\treturn -1;\n" 
	"\treturn atoi(argv[1]) % 2 == 0;\n" 
	"}";
	const char *src_file_name = "method7.c";
	FILE *source = fopen(src_file_name, "w+");
	if (source == NULL) {
		return IS_EVEN_ERROR;
	}
	int written = fwrite(src_code, sizeof(char), strlen(src_code), source);
	fclose(source);
	if (written != strlen(src_code)) {
		remove(src_file_name);
		return IS_EVEN_ERROR;
	}
	char *gcc_command = "gcc method7.c -o";
	char *executable_name = NULL;
	#if defined (_WIN32)
		executable_name = "method7.exe";
	#else 
		executable_name = "method7";
	#endif
	char command[1024];
	memset(command, 0, sizeof(command));
	strcat(command, gcc_command);
	strcat(command, executable_name);
	
	system(command);
	remove(src_file_name);
	int exit_code = IS_EVEN_ERROR;
	#if defined(_WIN32) || defined(_WIN64)
		sprintf(command, "%s %d", executable_name, n);
		int status = system(command);
		exit_code = status == 1 ? IS_EVEN_TRUE : (status == 0 ? IS_EVEN_FALSE : IS_EVEN_ERROR);
	#elif defined(__unix__) || defined(__MACH__)
		sprintf(command, "./%s %d", executable_name, n);
		int status = system(command);
		status = WEXITSTATUS(status);
		exit_code = status == 1 ? IS_EVEN_TRUE : (status == 0 ? IS_EVEN_FALSE : IS_EVEN_ERROR);
	#endif
	remove(executable_name);
	return exit_code;
}

int method8(int n)
{
	int random_even_number = 0;
	do {
		random_even_number = rand();
	} while (random_even_number % 2 != 0);
	
	return (n + random_even_number) % 2 == 0;
}

int method9(int n)
{
	int number_of_samples = 10;
	int columns = 2;
	int dataset[number_of_samples][columns];
	int evenCounter = 0;
	int oddCounter = 0;
	int lsb_evenCounter = 0;
	int lsb_oddCounter = 0;
	// init dataset
	for (int i = 0; i < number_of_samples; i++) {
		/*
		 * Generate a random number and use the least significant
		 * bit as feature.
		 */
		int random = rand();
		dataset[i][0] = random & 1;
		dataset[i][1] = random % 2 == 0 ? IS_EVEN_TRUE : IS_EVEN_FALSE;
		if (dataset[i][1] == IS_EVEN_TRUE) {
			evenCounter++;
			if (dataset[i][0] == (n & 1)) {
				lsb_evenCounter++;
			}
		} else {
			oddCounter++;
			if (dataset[i][0] == (n & 1)) {
				lsb_oddCounter++;
			}
		}
	}
	// Calculate P(even)
	double pEVEN = (double) evenCounter / number_of_samples;
	// Calculate P(odd)
	double pODD = (double) oddCounter / number_of_samples;
	// Calulate P(lsb(n) | even)
	double pLSB_EVEN =  evenCounter ? (double) lsb_evenCounter / evenCounter : 0;
	// Calculate P(lsb(n) | odd)
	double pLSB_ODD = oddCounter ? (double) lsb_oddCounter / oddCounter : 0;
	double score_even = pLSB_EVEN * pEVEN;
	double score_odd = pLSB_ODD * pODD;
	if (score_even > score_odd) {
		return IS_EVEN_TRUE;
	} else {
		return IS_EVEN_FALSE;
	}
}

#endif // IS_EVEN_H