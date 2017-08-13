#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ---------------------------
 GROUP 14 - RAIL FENCE CIPHER
----------------------------- */



void encrypt(char *S,int key,int n){
	/*-- create rail maxtrix --*/
	char R[key][n];
	/*-- fill with _ chars --*/
	for(int i=0; i<key; i++) for(int j=0; j<n; j++) R[i][j]='_';
	/*-- add plaintext in zig-zag order --*/
	int multi=1;
	for(int j=0,i=0; j<n ;j++,i+=1*multi){
		if(i==0){
			multi=1;
		}
		else if(i==key-1){
			multi=-1;
		}
		R[i][j]=S[j];
	}
	/*-- display ciphertext */
	printf("%s", "Ciphertext : ");
	for(int i=0; i<key; i++){
		for(int j=0; j<n; j++){
			if(R[i][j]!='_'){
				printf("%c", R[i][j]);
			}
		}
	}
}

void decrypt(char *S,int key,int n){
	/*-- create rail maxtrix --*/
	char R[key][n];
	/*-- fill with _ chars --*/
	for(int i=0; i<key; i++) for(int j=0; j<n; j++) R[i][j]='_';
	/*-- mark zig-zag path with # char --*/
	int multi=1;
	for(int j=0,i=0; j<n ;j++,i+=1*multi){
		if(i==0)
			multi=1;
		else if(i==key-1)
			multi=-1;
		R[i][j]='#';
	}
	/*-- fill the # values with ciphertext values --*/
	int z=0;
	for(int i=0; i<key; i++){
		for(int j=0; j<n; j++){
			if(R[i][j]=='#')
				R[i][j]=S[z++];
		}
	}
	/*-- display plaintext --*/
	printf("%s", "Plaintext : ");
	for(int j=0; j<n; j++){
		for(int i=0; i<key; i++){
			if(R[i][j]!='_'){
				printf("%c", R[i][j]);
			}
		}
	}
}


int main(int args0, char **args1){
	char S[100];
	int key,n,choice;
	while(choice!=3){
		printf("\n------------------\n");
		printf("---- RAIL-FENCE CIPHER ----\n");
		printf("------------------\n");
		printf("1 : Encryption\n");
		printf("2 : Decryption\n");
		printf("3 : Quit\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Plaintext : ");
				fflush(stdin);
				fgets(S,100,stdin);
				printf("Enter key (positive integer) : ");
				scanf("%d",&key);
				n=strlen(S)-1;
				encrypt(S,key,n);
				break;

			case 2:
				printf("Enter Ciphertext : ");
				fflush(stdin);
				fgets(S,100,stdin);
				printf("Enter key (positive integer) : ");
				scanf("%d",&key);
				n=strlen(S)-1;
				decrypt(S,key,n);
				break;
			case 3:
				printf("Exit success\n");
				break;
			default:
				printf("Invalid choice\n");
				break;
		}

	}
	return 0;
}