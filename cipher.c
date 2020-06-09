/*
* Name : Dipesh kabariya
* student_no : 991550231
* Description:-
* This a Simple C Program which will help you talk to your friend secretly
* in cipher codes just enter your message in and send the
* encrypted message to your friend and reverse
* it with decrption but need the same key.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


/*As C go From top we need to define the function so we can use
 * in Main Method */
void encipher(char messages[],char key[]);
void decipher(char encrypted[],char key[]);
void Check();
int main(){
	printf("------------------------------------------- *WELCOME TO
		       	KEYBOARD CIPHER APP* --------------------
			-------------------------\n\n");
	char message[100];
	char key[100];

	/*Ask the user for a sentence or word to encrypt*/
	printf("Please enter a sentence or word you
		       	want to encrypt (Alphabets Only): \n");
	/*Get the users input (the plain text)*/
	scanf("%100s",message); /* get the message*/
	Check(message);
	printf("Please enter the Key:\n");
	scanf("%100s",key);/* get the key*/
	Check(key);
	/*Calling the encipher function*/
	encipher(message, key);

	/*Print the actual encryption*/

	printf("\n");

	return 0;
	/*End of Main method*/
}

/*Input Checker for alphabetic word*/
void Check(char Input[100]) {

	for (int i = 0; i < strlen(Input); i++)
	{
		if (isalpha(Input[i]) == 0) {
			printf("You entered the following
					character %c :Please
					enter Alphabet Only.\n", Input[i]);

			scanf("%100s", Input);

			for (int i = 0; i < strlen(Input); i++) {
				if (isalpha(Input[i]) == 0)
				{
					printf("U Enter two
		wrong inputs! Terminating the program see you again.. :( \n");
					exit(0);
				}
			}
		}
	}

}


/*simple modules method taken from stackflow*/
int MOD(int dividend, int divisor)
{
	int m = dividend % divisor;
	return m + (m < 0 ? divisor : 0);
}

/*Start of Encipher by taking the input from user*/

void encipher(char messages[],char key[])
{
	/*some block variable used in the loops*/
	char k[100];
	int key_lenght=strlen(key);
	int msg_lenght=strlen(messages);


	char lower_key[100];
	/*for loop for convert the message to lower text*/
	for (int i =0; i<msg_lenght;i++){
		lower_key[i]=tolower(key[i]);
	}
	/* if statement for repeating the key*/
	if(key_lenght<msg_lenght){
		for(int i=0 ; i<msg_lenght;i++)
		{
			lower_key[key_lenght+i]=lower_key[i];
		}
	}

	/*printing the encriphered text with loop*/
	printf("\n ---Encipher--- \n");
	printf("\n message: \t");
	for (int i =0; i<msg_lenght;i++)
	{
		printf("%c",messages[i]);
	}
	/*printing the key with loop*/
	printf("\n key: \t\t");
	for(int i =0; i<msg_lenght;i++)
	{
		printf("%c",lower_key[i]);
	}
	/*loop for actual encryption method*/
	for(int i=0;i<msg_lenght;i++)
	{
		char lower_msg = tolower(messages[i]);
		k[i]= (((lower_msg-97) + (lower_key[i]-97)) % 26) + 97;
		k[msg_lenght] = '\0';

	}

	/*printing the enciphered text with loop */
	printf("\nEncrypted Msg: \t");
	for(int i =0; i<strlen(k);i++)
	{
		printf("%c",k[i]);
	}
	printf("\n\n");

	/*calling decipher method*/
	decipher(k,lower_key);
}




void decipher(char encrypted[],char key[])
{
	char encrypt[100];
	int msg_lenght=strlen(encrypted);

	/*printing the Decipher text with loop*/
	printf("---- Decipher ---- \n");
	/*printing the enciphered text with loop */
	printf(" enc: \t\t");
	for (int i =0; i<msg_lenght;i++)
	{
		printf("%c",encrypted[i]);
	}
	/*printing the key with loop*/
	printf("\n key: \t \t");
	for (int i =0; i<msg_lenght;i++)
	{
		printf("%c",key[i]);
	}
	/*loop for actual decryption method */
	for (int i =0;i<msg_lenght;i++)
	{
		int temp=(((encrypted[i]-97) - (key[i]-97)));
		int temp_mod=MOD(temp,26);
		encrypt[i]=temp_mod+97;
		encrypt[strlen(encrypted)] = '\0';
	}
	encrypt[msg_lenght]= '\0';


	/*printing the decipher text  with loop */
	printf("\ndecrypted:\t");

	for (int i =0; i<strlen(encrypt);i++){
		printf("%c",encrypt[i]);
	}
}
/*End of Decipher method */


