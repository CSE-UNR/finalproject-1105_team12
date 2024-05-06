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
void renderOut(int rows, int columns, int image[][columns], FILE* fp);//Glen
void brightAndDim();//Jaidunn
void Crop(int* rows, int* columns, int image[][MAX_2D_COLUMNS]);//Jaidunn
int editMenu();//Jaidunn
void actualSize(int* rows, int* columns, int image[][MAX_2D_COLUMNS], FILE* fp);//Glen
void rotate90Deg();//Jaidunn and Glen
void saveimage(int rows, int columns, int image[][columns], FILE* fpe);

int main(){
	int image[MAX_2D_ROWS][MAX_2D_COLUMNS], rows = 0, columns = 0;
	int userChoice;
	char choice, filename[MAXNAME], writefilepointer, y, n;
	FILE* fpIn,* fpOut;
	FILE* fpedit;
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
			printf("successfully loaded file\n");
			actualSize(&rows, &columns, image, fpIn);
			loadIn(rows, columns, image, fpIn);
			break;
		case 2:
			fpOut = fopen(TEST_OUT,"w");
			if(fpOut == NULL){
				printf("Could not open file to read");
				break;
			}
			renderOut(rows, columns, image, stdout);
			break;
		case 3:
			switch(editMenu()){
			case 1:
				printf("Does nothing right now");
			break;
			case 2:
				brightAndDim();
			break;
			case 3:
				printf("Does nothing right now");
			break;
			}
			printf("Would you like to save the edited image to the file? y - yes, n - no\n");
			printf("Enter your choice \n");
			scanf(" %c", &choice);
			if(choice == y){
			printf("What is the name of the file you would like to save the image to?\n");
			scanf("%s", filename);
			fpedit = fopen(filename, "w");
			if(fpedit == NULL){
				printf("Could not save to file");
				}
			printf("successfully grabbed image!\n");
			void saveimage(int rows, int columns, int image[][columns], FILE* fpe);
			}
			if(choice == n){
			printf("okay");
			}
			else if{
			printf("Input invalid");
			}
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
	int k;
	
	for(int i = 0; i < MAX_2D_ROWS; i++){
		while(fscanf(fp, "%d" , &k) == 1){
			*rows++;
		}
		for(int j = 0; j < MAX_2D_COLUMNS; j++){
			while(fscanf(fp, "%d" , &k) == 1){
				*columns++;
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
void brightAndDim(){
	char imageConvert[SIZE];
	int input, rows, columns;
	printf("1.Dim\n");
	printf("2.Brighten\n");
	printf("Choose input; \n");
	scanf("%d", &input);
	if(input == 1){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
		imageConvert +1;
		}
			}
				}
	if(input == 2){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
		imageConvert -1;
		}
			}
				}
	else{
	printf("Input invalid");
	}
}
void crop(int* rows, int* columns, int image[][MAX_2D_COLUMNS]){
int newrows, newcolumns;
void actualSize(int* rows, int* columns, int image[][MAX_2D_COLUMNS], FILE* fp);
	printf("image size; row 1-%lf, columns 1-%lf" rows, columns);
	printf("Enter your parameters; (from row 1-%lf, columns 1-%lf)" rows, columns);
	scanf("%d,%d", &newrows, &newcolumns);
	for(int i = 0; i < newrows; i++){
		for(int j = 0; j < newcolumns; j++){
		}
			}
	printf(" ");
}

void saveimage(int rows, int columns, int image[][columns], FILE* fpe){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fscanf(fpe, "%d" , &image[i][j]);
		}
	}
}
	
	
	
	
	
