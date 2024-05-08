//Final Group Project
//Glen Seidel & Jaidunn McKenzie
//Erinstagram!

#include<stdio.h>
#include<stdbool.h>

#define MAX_2D_ROWS 500
#define MAX_2D_COLUMNS 500
#define SIZE 5
#define TEST_IN "test_image.txt"//these will be taken out when closer to done
#define TEST_OUT "test_image_out.txt"
#define MAXNAME 20

void loadIn(int rows, int columns, int image[][columns], FILE* fp);//Glen
void renderOut(int rows, int columns, int image[][columns],char imageConvert[SIZE]);//Glen
void brightAndDim(int rows, int columns, int image[][columns],char imageConvert[SIZE]);//Jaidunn
void crop(int rows, int columns, int image[][columns]);//Jaidunn
int editMenu();//Jaidunn
void actualSize(int* rows, int* columns, FILE* fp);//Glen
void rotate90Deg();//Jaidunn and Glen
void saveimage(int rows, int columns, int image[][columns], FILE* fpe);

int main(){
	int image[MAX_2D_ROWS][MAX_2D_COLUMNS], rows, columns;
	int userChoice;
	char choice, filename[MAXNAME], writefilepointer, y, n, imageConvert[SIZE];
	FILE* fpIn,* fpOut;
	FILE* fpedit;
	
	imageConvert[0] = ' ';
	imageConvert[1] = '.';
	imageConvert[2] = 'o';
	imageConvert[3] = 'O';
	imageConvert[4] = '0';
	
	do{
	printf("**ERINSTAGRAM**\n");
	printf("1:Load a new image\n");
	printf("2:Display the current image\n");
	printf("3:Edit the current image\n");
	printf("4:Exit the program\n");
	printf("Enter a number to continue: ");
	scanf(" %d", &userChoice);
	
	switch(userChoice){
		case 1:
			fpIn = fopen(TEST_IN,"r");
			if(fpIn == NULL){
				printf("Could not open file to read");
				break;
			}
			
			actualSize(&rows, &columns, fpIn);
			loadIn(rows, columns, image, fpIn);
			printf("successfully loaded file\n");
			break;
		case 2:
			fpOut = fopen(TEST_OUT,"w");
			if(fpOut == NULL){
				printf("Could not open file to write\n");
				break;
			}
			renderOut(rows, columns, image, imageConvert);
			break;
		case 3:
			switch(editMenu()){
			case 1:
				crop(rows, columns, image);
			break;
			case 2:
				brightAndDim(rows, columns, image,imageConvert);
			break;
			case 3:
				printf("Does nothing right now\n");
			break;
			}
			printf("Would you like to save the edited image to the file?\n y - yes, n - no\n");
			printf("Enter your choice \n");
			scanf(" %c", &choice);
			if(choice == 'y'){
			printf("What is the name of the file you would like to save the image to? (with a .txt ending)\n");
			scanf("%s", filename);
			fpedit = fopen(filename, "w");
			if(fpedit == NULL){
				printf("Could not save to file");
				break;
				}
			saveimage(rows,columns, image, fpedit);
			printf("successfully grabbed image!\n");
			saveimage(rows, columns, image, fpedit);
			}
			if(choice == 'n'){
			printf("okay\n");
			}
			break;
		case 4:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid Option\n");
			break;
	}
	
	}while(userChoice != 4);
	return 0;
}

void loadIn(int rows, int columns, int image[][columns], FILE* fp){
	char temp[rows][columns];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fp, "%d" , &image[i][j]);
			image[i][j+1] = '\n';
		}
	}
}
void renderOut(int rows, int columns, int image[][columns],char imageConvert[SIZE]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			switch(image[i][j]){
				case 0:
					printf("%c" , imageConvert[0]);
					break;
				case 1:
					printf("%c" , imageConvert[1]);
					break;
				case 2:
					printf("%c" , imageConvert[2]);
					break;
				case 3:
					printf("%c" , imageConvert[3]);
					break;
				case 4:
					printf("%c" , imageConvert[4]);
					break;
				case '\n':
					printf("\n");
					break;
			}
		}
	}
}
void actualSize(int* rows, int* columns, FILE* fp){
	char temp[MAX_2D_ROWS][MAX_2D_COLUMNS];
	*rows = 0;
	*columns = 0;
	*rows+=1;
	for(int i = 0; i < MAX_2D_ROWS; i++){
		for(int j = 0; j < MAX_2D_COLUMNS; j++){
			if(fscanf(fp, "%c" , &temp[i][j]) == 1){
				if(temp[i][j] == '\n'){
					*rows+=1;
					*columns = 0;
				}
				else if((temp[i][j] == '0')||(temp[i][j] == '1')||(temp[i][j] == '2')||(temp[i][j] == '3')||(temp[i][j] == '4')){
					*columns+=1;
				}
			}
		}
	}
	
	 
}
	
int editMenu(){
	int options;
	printf("1.Crop image\n");
	printf("2.Dim/Brighten image\n");
	printf("3.Rotate 90 degrees\n");
	printf("Enter your choice ");
	scanf("%d", &options);
	
	return options;
}
void brightAndDim(int rows, int columns, int image[][columns],char imageConvert[SIZE]){
	int input;
	printf("1.Dim\n");
	printf("2.Brighten\n");
	printf("Choose input; \n");
	scanf("%d", &input);
	if(input = '1'){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%c" , imageConvert[image[i][j]+1]);
		}
	}
				}
	if(input = '2'){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			printf("%c" , imageConvert[image[i][j]-1]);
		}
	}
				}
	else{
	printf("Input invalid");
	}
}
void crop(int rows, int columns, int image[][columns]){
int newrows, newcolumns, i, j;
	printf("image size; row 1-%d, columns 1-%d\n" ,rows, columns);
	printf("Enter row choice: \n");
	scanf("%d", &newrows);
	printf("enter columns choice: \n");
	scanf("%d", &newcolumns);
	for(i = 0; i < newrows; i++){
		for(j = 0; j < newcolumns; j++){
		}
			}
	printf("%c", image[i][j]);
}

void saveimage(int rows, int columns, int image[][columns], FILE* fpe){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fpe, "%d" , &image[i][j]);
		}
	}
}
	
	
	
	
	
