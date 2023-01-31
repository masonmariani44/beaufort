#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	//declare variables
	char key[129];
	char message[129];
	int key_len = 0;

	//get key
	fgets(key, 128, stdin);
	key_len = strlen(key);

	//get input to be encrypted
	int i = 0;
	int key_i = 0;
	char char_swap = 'a';
	while(fgets(message, 128, stdin) != NULL) {
		i = 0;

		//encrypt
		while (message[i] != '\n') {
			if (message[i] == ' ') {
				message[i] = ' ';
			}
			else {
				char_swap = (key[key_i] - message[i]) % 26;
				char_swap = (char_swap < 0 ? char_swap + 26 : char_swap) + 65;
				message[i] = char_swap;
				key_i = (key_i+1) % (key_len-1);
			}

			//iterate
			i++;
		}
		//print
		printf("%s", message);
	}
	return 0;
}