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

void loadIn(int rows, int columns, int image[][columns], FILE* fp);//Glen
void renderOut(int rows, int columns, int image[][columns], FILE* fp);//Glen
void brightAndDim();//Jaidunn
void Corp();//Jaidunn
void editMenu();//Jaidunn
void actualSize(int* rows, int* columns, int image[][MAX_2D_COLUMNS], FILE* fp);//Glen
void rotate90Deg();//Jaidunn and Glen

int main(){
	int image[MAX_2D_ROWS][MAX_2D_COLUMNS], rows = 0, columns = 0;
	int userChoice;
	FILE* fpIn,* fpOut;
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
			actualSize(&rows, &columns, image, fpIn);
			loadIn(rows, columns, image, fpIn);
			printf("sescfully loaded file\n");
			break;
		case 2:
			fpOut = fopen(TEST_OUT,"w");
			if(fpOut == NULL){
				printf("Could not open file to read\n");
				break;
			}
			renderOut(rows, columns, image, stdout);
			break;
		case 3:
			printf("crently does nothing\n");
			break;
		case 4:
			printf("Goodby!\n");
			break;
		default:
			printf("Invalid Option\n");
			break;
	}
	
	}while(userChoice != 4);
	return 0;
}

void loadIn(int rows, int columns, int image[][columns], FILE* fp){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fp, "%d" , &image[i][j]);
		}
	}
}
void renderOut(int rows, int columns, int image[][columns], FILE* fp){
	char imageConvert[SIZE];
	imageConvert[0] = ' ';
	imageConvert[1] = '.';
	imageConvert[2] = 'o';
	imageConvert[3] = 'O';
	imageConvert[4] = '0';
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fprintf(fp, "%d" , imageConvert[image[i][j]]);
		}
	}
}
void actualSize(int* rows, int* columns, int image[][MAX_2D_COLUMNS], FILE* fp){
	char temp[MAX_2D_ROWS][MAX_2D_COLUMNS];
	int allarray = 0;
	*rows = 0;
	*columns = 0;
	*rows++;
	for(int i = 0; i < MAX_2D_ROWS; i++){
		for(int j = 0; j < MAX_2D_COLUMNS; j++){
			if(fscanf(fp, "%c" , &temp[i][j]) == 1){
				if(temp[i][j] == '\n'){
					*rows++;
				}
				else if((temp[i][j] == '0')||(temp[i][j] == '1')||(temp[i][j] == '2')||(temp[i][j] == '3')||(temp[i][j] == '4')){
					allarray++;
				}
			}
		}
	}
	*columns = (allarray / *rows);
}
