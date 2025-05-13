#include <is_even.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: is_even <number_to_test>");
		return 1;
	}
	
	srand(time(NULL));
	
	int number_to_test = atoi(argv[1]);
	int method_counter = 0;
	int is_even = 0;
	
	is_even = method0(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method1(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method2(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method3(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method4(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method5(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method6(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method7(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method8(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	is_even = method9(number_to_test);
	printf("Method %d\n-- Number to test: %d\n-- Is even: %s\n", method_counter++, number_to_test, is_even < 0 ? "error" : (is_even == 0 ? "false" : "true"));
	
	return 0;
}