#include <stdio.h>
#include <stdlib.h>

/*
 * Συνάρτηση: is_safe
 * Περιγραφή: Ελέγχει αν ο αριθμός (num) μπορεί να τοποθετηθεί στο κελί (row, col) 
 *            χωρίς να παραβιάζει τους κανόνες του Sudoku.
 * Λειτουργία: Σαρώνει την αντίστοιχη γραμμή, στήλη και το υπο-τετράγωνο 3x3.
 * Επιστρέφει: 1 αν η τοποθέτηση είναι έγκυρη (ασφαλής), 0 αν ο αριθμός υπάρχει ήδη.
 */

int is_safe(int num, int col, int row, int **board) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == num) {
			return 0;
		}
	}

	for (int i=0; i<9; i++) { 
		if (board[i][col]==num) { 
			return 0;
		}
	}

	int startRow = (row/3) * 3;
	int startCol = (col/3) * 3;

	for (int r=startRow; r<startRow +3; r++) {
		for (int c=startCol; c<startCol +3; c++) { 
			if (board[r][c] == num) {
				return 0;
			}
		}
	}

 return 1;
}


/*
 * Συνάρτηση: solve
 * Περιγραφή: Επιλύει το παζλ Sudoku χρησιμοποιώντας τον αλγόριθμο Οπισθοδρόμησης (Backtracking).
 * Λειτουργία: Ψάχνει το πρώτο κενό κελί (0) και δοκιμάζει αριθμούς (1-9). Αν ο αριθμός 
 *             είναι έγκυρος (μέσω της is_safe), καλεί αναδρομικά τον εαυτό της. Αν υπάρξει 
 *             αδιέξοδο, αναιρεί την επιλογή (το ξανακάνει 0) και δοκιμάζει τον επόμενο.
 * Επιστρέφει: 1 αν το Sudoku λύθηκε επιτυχώς, 0 αν δεν υπάρχει λύση.
 */

int solve(int **board) { 
	for (int r=0; r<9; r++) { 
		for (int c=0; c<9; c++) {
			if (board[r][c] == 0) {
				for(int num=1; num<=9; num++) {
					if(is_safe(num,c,r,board) == 1) { 
						board[r][c] = num; 
						 if(solve(board) == 1) {
						  return 1;
						 }
						board[r][c]=0;
					}
				}
			 return 0;
			}
		}
	}	
		



return 1;				
}

int main(int argc,char *argv[]) {
 if (argc != 2) {
	printf("Σφάλμα: Δεν ορίστηκε αρχείο εισόδου στην γραμμή εντολών\n");
	return 1;
  }
  FILE *file; 
  file = fopen(argv[1], "r");

  if(file == NULL) { 
	printf("Σφάλμα: Το αρχείο δεν βρέθηκε ή δεν μπορεί να ανοίξει\n");
	return 1;
  }

  int **board;
  board = (int**)malloc(9 * sizeof(int *));
  
  for (int i=0; i<9; i++) {
	board[i] = (int*)malloc(9 * sizeof(int));
  }

  for (int r=0; r<9; r++) {
	for (int c=0; c<9; c++) {
		char ch  = fgetc(file);
		if (ch < '0' || ch > '9') {
			printf("Σφάλμα: Μη αποδεκτός χαρακτήρας στο αρχείο\n");
			return 1;
		} else {
			board[r][c] = ch - '0';
		}
	}
	fgetc(file);
  }

  for (int r=0; r<9; r++) { //ελεγος στηλων
	int counter[10] = {0};
	for (int c=0; c<9; c++) {
		int val = board[r][c];
		if (val != 0) {
		if (counter[val] > 0) {
			printf("Σφάλμα: Στην γραμμή %d ο αριθμός %d υπάρχει δύο φορές\n",r+1,val);
			return 1;
		} else {
			counter[val]++;
		}
		}
	}
  }

  for (int r=0; r<9; r++) {  //ελεγος γραμμων
	int counter[10] = {0};
	for (int c=0; c<9; c++) {				
		int val = board[c][r];
		if (val !=0) { 
		 if (counter[val] > 0) {
			printf("Σφάλμα: Στην στήλη %d ο αριθμός %d υπάρχει δύο φορές\n",c+1,val);
			return 1;
		 } else {
			counter[val]++;
		 }
		}
  	}
  }
  
  for (int boxRow = 0; boxRow<9; boxRow += 3) {
	  for (int boxCol = 0; boxCol < 9; boxCol += 3) {
		int counter[10] ={0};
		for (int r = boxRow; r < boxRow +3; r++) {
			for (int c = boxCol; c < boxCol + 3; c++) {
				int val = board[r][c];
				if (val != 0) {
					if (counter[val] > 0) {
						printf("Σφάλμα: Στο τετράγωνο 3χ3 ο αριθμος %d υπάρχει δύο φορές\n", val);
						return 1;
					} else { 
						counter[val]++;
					}
				}
			}
		}
	}
  }

  if (solve(board) == 1) { 
	printf("Η λύση του sudoku είναι:\n");
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			printf("%d", board[r][c]);
		}
	printf("\n");
	}
  } else { 
	printf("Σφάλμα: Το sudoku δεν έχει λύση.\n");
  }


  fclose(file);
  for(int i =0; i<9; i++) { 
	free(board[i]);
  }
  free(board);



return 0;
} 
