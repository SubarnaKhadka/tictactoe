#include <iostream>
#include <time.h>
#include <stdlib.h>;
using namespace std;

class tictactoe{	
   private:
		char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		int choice;		
   public:
       void show_board();
       void get_x_player_choice();
       void get_o_player_choice();
       void get_computer_choice();
       int count_board(char symbol);
       char check_winner();
       void computer_vs_player();
       void player_vs_player();
       void fordelay(int);
};

void tictactoe::computer_vs_player(){
	system("cls");
	string player_name;
	cout << "\n\n\n\n\n\t\t\t\t\t\t " << "Enter Your Name: ";
	cin >> player_name;
	while(true){
		system("cls");
		show_board();
		if(count_board('X') == count_board('O')){
			cout << "\n\n\t\t\t\t"<<  player_name << "'s Turn."<<endl;
			get_x_player_choice();
		}
		else{
			get_computer_choice();
		}
		char winner = check_winner();
		if(winner == 'X'){
			system("cls");
			show_board();
			cout << "\n\n\t\t\t\t" << player_name << " Won The Game."<< endl;
			break;
		}
		else if (winner == 'O'){
			system("cls");
			show_board();
			cout << "\n\n\t\t\t\t" << "Computer Won The Game." << endl;
			break;
		}
		else if( winner == 'D'){
		system("cls");
		show_board();
			cout << "\n\n\t\t\t\t "  << " Game is Draw." << endl;
			break;
		}
	}
}
void tictactoe::player_vs_player(){
	system("cls");
	calculate:
		system("Color A");
	string x_player_name, o_player_name;
	cout << "\n\n\n\n\n\t\t\t\t\t\t " << "Enter X Player Name: ";
	cin >> x_player_name;
	cout  << "\n\n\t\t\t\t\t\t " << "Enter O Player Name: ";
	cin >> o_player_name;
	if(x_player_name.compare(o_player_name) != 0 ){
	while(true){
		system("cls");
		show_board();
		if(count_board('X') == count_board('O')){
			cout << "\n\n\t\t\t\t" << x_player_name << "'s Turn." << endl;
			get_x_player_choice();
		}
		else{
			cout << "\n\n\t\t\t\t" << o_player_name << "'s Turn." << endl;
			get_o_player_choice();
		}
		char winner = check_winner();
		if(winner == 'X'){
			system("cls");
			show_board();
			cout << "\n\n\t\t\t\t" << x_player_name << " Won The Game " << endl;
			break;
		}
		else if(winner == 'O'){
			system("cls");
			show_board();
			cout << "\n\n\t\t\t\t" << o_player_name << " Won The Game " << endl;
			break;
	}
	else if(winner == 'D'){
		system("cls");
		show_board();
			cout << "\n\n\t\t\t\t Game is Draw. " << endl;
			break;
 }
   }
}
else{
	cout  << "\n\n\t\t\t\t\t\t " << "Please Enter Different Name!!!!";
	system("Color 4");
	goto calculate;
	
}
cout << "\n\n\n\n";
}

void tictactoe::get_computer_choice(){
	srand(time(0));
	do{
		choice = rand() % 10;
	} while(board[choice] != ' ');
	board[choice] = 'O';
}
void tictactoe::get_x_player_choice(){
	while(true){
	cout << "\n\n\t\t\t\t" << "Select Your Position (1-9): ";
	cin >> choice;
	choice--;
	if(choice < 0 || choice > 8){
	cout << "\n\t\t\t\t" << "Please Select Your Choice From (1-9)." << endl;
	}	
	else if(board[choice] != ' '){
	cout << "\n\t\t\t\t" << "Please Select An Empty Position ";
	}
	else{
		board[choice] = 'X';
		break;
	}
	}
}
void tictactoe::get_o_player_choice(){
	while(true){
	cout << "\n\n\t\t\t\t" << "Select Your Position (1-9): ";
	cin >> choice;
	choice--;
	if(choice < 0 || choice > 8){
		cout << "\n\t\t\t\t" << "Please Select Your Choice From (1-9)." << endl;
	}	
	else if(board[choice] != ' '){
		cout << "\n\t\t\t\t" << "Please Select An Empty Position ";
	}
	else{
		board[choice] = 'O';
		break;
	}
	}
}

int tictactoe::count_board(char symbol){
	int total = 0;
	for(int i = 0; i< 9; i++){
		if(board[i]== symbol)
		total += 1;
		
	}
	return total;
}

char tictactoe::check_winner(){
	//checking winner  horizontally
	if(board[0] == board[1] && board[1] == board[2]&& board[0] != ' ')
	return board[0];
		if(board[3] == board[4] && board[4] == board[5]&& board[3] != ' ')
	return board[3];
		if(board[6] == board[7] && board[7] == board[8]&& board[6] != ' ')
	return board[6];
	//checking winner  vertically
	
	if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
	return board[0];
	if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
	return board[1];
	if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
	return board[2];
	
	//checking winner  diagonally
	if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
	return board[0];
	if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
	return board[2];
	if(count_board('X') + count_board('O') < 9)
	 return 'C';
	 else
	 return 'D';
		
	
	
	
}

void tictactoe::show_board(){
	cout << "\n\n\t\t\t"<< "  " << "  |  "<< "  |  "<< endl;
	cout << "\t\t\t"<< "  " << board[0] << " |  " << board[1] << " |  " <<board[2] << endl;
    cout << "\t\t\t"<< "  " << "  |  " << "  |  " << endl;
	cout << "\t\t  "<< "-----------------------" << endl;
   	cout << "\t\t\t"<< "  " << "  |  "<< "  |  "<< endl;
	cout << "\t\t\t"<< "  " <<board[3] << " |  " << board[4] << " |  " <<board[5] << endl;
	cout << "\t\t\t"<< "  " << "  |  " << "  |  " << endl;
	cout << "\t\t  "<< "-----------------------" << endl;
	cout << "\t\t\t"<< "  " << "  |  "<< "  |  "<< endl;
	cout << "\t\t\t"<< "  " <<board[6] << " |  " << board[7] << " |  " <<board[8] << endl;
    cout << "\t\t\t"<< "  " << "  |  " << "  |  " << endl;
}
void tictactoe::fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


int main(){
	system("color A");
	tictactoe t;
	int modes;
	cout << "\n\n\n\n\n\t\t\t\t\t\t      START GAME";
	cout << "\n\n\t------------------------------------------------------------------------------------------------";
	cout <<"\n\n\t\t\t\t\t\t" << "1. Computer VS Player."<<endl;
	cout <<"\n\t\t\t\t\t\t" << "2. Player VS Player." << endl;
	cout << "\n\n\n\t\t\t\t\t\tSelect Game Mode: " , 
	cin>> modes;
	cout << "\n\n\n\t\t\t\t\t\t LOADING  ";
	 for(int i=0;i<=7;i++)
        {
            t.fordelay(120000000);
            printf(". ");
        }
		switch(modes){
		case 1 :
		t.computer_vs_player();
			break;
		case 2 :
		t.player_vs_player();
			break;
		default:
			cout << "Please Select Valid Game Mode. " << endl;
			break;
	}
		
	return 0;
}
