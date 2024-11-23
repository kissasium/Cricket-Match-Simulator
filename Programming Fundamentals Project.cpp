//                                    ***********!!!!!!!          KISSA   ZAHRA       !!!!!!!***********                                                                                             
//                                    ***********!!!!!!!            I21-0572          !!!!!!!***********                                                                                             
//                                    ***********!!!!!!!            SECTION F         !!!!!!!***********                                      
//                                    ***********!!!!!!!          FINAL PROJECT       !!!!!!!***********



#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

void DisplayGame();
void DisplayTeam(string[], string[], int); // prototyping
int TossGame(int);
int batting_random();
int Bowler_random();
void LetTheGameBegin(int toss, string team_1[], string team_2[], int);
float oversbowled(int, int);
int no_of_wichket(int);
float runrate(int, float);
int BattingBoard(string battingTeam[], string bowlingTeam[], string not_out_players[], int scoreTeam[], float run_rate, float number_of_overs, float average[], int number_of_batsman, int number_of_4[], int number_of_6[]);
int calculate_total_score(int scoreTeam[]);
void Bowling_Board(string bowlingTeam[], int Wickets_Taken[]);
void LiveScoreCard(string battingTeam[], float float_over_num, int scoreTeam[], string bowlingTeam[], float run_rate, int FacingBall, int batting_num, int number_of_ballers);
void match(int number_of_overs, string bowlingTeam[11], int **total_number_of_balls_1, int *scoreTeam, string battingTeam[11], int *Wickets_Taken, float *average, string not_out_players[11], float &run_rate, int &number_of_batsman, int &t_wickets, int number_of_4[], int number_of_6[]);
void ManOfTheMatch(int scoreTeam[], int scoreTeam2[], string team_1[], string team_2[]);
void BowlerOfTheMatch(int Wickets_Taken[] ,int Wickets_Taken2[],string team_1[], string team_2[]);

int main()
{
    srand(time(NULL)); // to generate a new number everytime

    DisplayGame(); // display game

    int enter_key;
    cout << "              Press ENTER to continue " << endl; // game start
    getchar();

    // file handling wala kam.
    int number_of_overs;
    number_of_overs = rand()%10+1; // storing overs

    ofstream overs("confriguation.txt"); // creating and opening a file
    overs << number_of_overs;
    overs.close();

    string overs_read;
    ifstream reading_overs("confriguation.txt"); // read from file
    while (getline(reading_overs, overs_read))
    {
        cout << "The game will be of " << overs_read << " overs" << endl;
    }

    overs.close(); // file close

    int team_memebers = 11;
    string *team_1;
    team_1 = new string[team_memebers]; // arrays for team members
    string *team_2;
    team_2 = new string[team_memebers];

    cout << "Enter the names of team 1:" << endl;
    for (int i = 0; i < team_memebers; i++)
    {
        cin >> team_1[i];
    }

    cout << "Enter the names of team 2:" << endl;                    // enter the name of the team 2 
    for (int i = 0; i < team_memebers; i++)
    {
        cin >> team_2[i];
    }

    DisplayTeam(team_1, team_2, team_memebers); // function for displaying teams

    cout << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "                     TOSS TIME                      " << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;

    int toss_game = 0;
    int toss;
    toss = TossGame(toss_game); // toss function

    cout << endl; // game start
    getchar();

    LetTheGameBegin(toss, team_1, team_2, number_of_overs); // game is strting
    
    delete[] team_1;
    delete[] team_2;
    
    team_1 = nullptr;
    team_2 = nullptr;
}

void DisplayGame()                        // design
{
    cout << "---------------------------------------------------" << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "                                                    " << endl;
    cout << "              WELCOME TO CRICKET GAME               " << endl;
    cout << "                                                    " << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "                                                    " << endl;
    cout << "     There will be 2 teams of 11 players each       " << endl;
    cout << "     Who ever will win the toss, will bat first     " << endl;
    cout << "                                                    " << endl;
    cout << "|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

void DisplayTeam(string team_1[], string team_2[], int team_memebers)           // display the teams 
{

    cout << "Team 1"
         << "\t"
         << "Team 2" << endl;
    for (int i = 0; i < team_memebers; i++)
    {
        cout << team_1[i] << "\t" << team_2[i];
        cout << endl;
    }

    cout << endl;
}

int TossGame(int toss_game)             // toss function
{
    toss_game = rand() % 2 + 1; // if toss_game = 1 so team 1 will win else team 2 will win

    if (toss_game == 1)
    {
        cout << "Team 1 has won the toss and will bat first." << endl;
    }
    else
    {
        cout << "Team 2 has won the toss and will bat first." << endl;
    }

    return toss_game;
}

int batting_random() // to generate a random number between -1 and 6
{
    int ball_prob = rand() % 100 + 1;
    if (ball_prob <= 10) // probabilit of out
    {                                                             // 10% has chance to out 
        return -1;
    }
    else
    {
        int runs_returned = 0;
        runs_returned = (rand() % 7);
        return (runs_returned); // probability of runs
    }
}

int Bowler_random()
{
    int ball_prob = rand() % 100 + 1;
    if (ball_prob <= 50) // probabilit of out      
    {                                                 // bowlers have 50% chance to be out 
        return -1;
    }
    else
    {
        int runs_returned = 0;
        runs_returned = (rand() % 7); // to generate a number between 0 and 6
        return (runs_returned);       // probability of runs
    }
}

float oversbowled(int i, int j) //   sub function for ball overs;
{
    float x = 0.1 * (j + 1) + i; // 6+1
    if ((j + 1) != 6)                                      // as soon as it reaches 0.6 over this will return the next whole number 
        return x;
    else
        return i + 1;
}

int no_of_wichket(int num_of_wickets) // sub function for wickets
{
    return 1 + num_of_wickets;                               // like a++
}

float RunRate(int sum_for_runrate, float float_over_num) // sub function to calculate run rate
{
    return sum_for_runrate / float_over_num;                       // formula to calculate the run rate
}

int calculate_total_score(int scoreTeam[])
{
    int sum = 0;
    for (int i = 0; i < 11; i++)
    {
        sum = sum + scoreTeam[i];
    }

    return sum;
}

// sub Function for live score card
void LiveScoreCard(string battingTeam[], float float_over_num, int scoreTeam[], string bowlingTeam[], float run_rate, int FacingBall, int batting_num, int number_of_ballers)
{
    cout << "---------------------------------" << endl;
    cout << "|     Player           Runs"
         << "\t|" << endl;
    cout << "|       " << battingTeam[FacingBall] << "                " << batting_num << "\t|" << endl;
    cout << "|                          "
         << "\t|" << endl;
    cout << "|           Over " << float_over_num << "\t \t|" << endl;
    cout << "|           Runs " << scoreTeam[FacingBall] << "\t \t|" << endl;
    cout << "|                          "
         << "\t|" << endl;
    cout << "|           Bowler: " << bowlingTeam[number_of_ballers] << " \t \t|" << endl;
    cout << "|           Run Rate: " << run_rate << " \t|" << endl;
    cout << "---------------------------------" << endl;
}

void match(int number_of_overs, string bowlingTeam[11], int **total_number_of_balls_1, int *scoreTeam, string battingTeam[11], int *Wickets_Taken, float *average, string not_out_players[11], float &run_rate, int &number_of_batsman, int &t_wickets, int number_of_4[], int number_of_6[])
{
    int shift = 0;
    int just_standing_there = 1; // the    one who will be  switched
    int FacingBall = 0;
    int number_of_ballers = 10;
    int wicket_taken = 0;
    float float_over_num = 0.0;
    int batting_num = 0;
    int sum_for_runrate = 0;
    int Sixs = 0;
    int Fours = 0;
    for (int i = 0, k = 1; i < number_of_overs && number_of_batsman < 10; i++, k++)
    {
        if (t_wickets >= 10)
        {
            break;
        }

        if (k % 5 == 0) // baller will be switch
        {
            number_of_ballers--;
            cout << "Baller swtich, new baller is: " << bowlingTeam[number_of_ballers] << endl;
            wicket_taken = 0;
        }

        if (number_of_ballers < 6) // if baller is less than 6 so it will start from again
        {
            number_of_ballers = 10;
        }

        for (int j = 0; j < 6; j++) // for ball 1
        {

            float_over_num = oversbowled(i, j);
            cout << "PLease press Enter to ball. " << endl;
            getchar();

            system("clear"); // will clear the mess on the terminal

            if (number_of_batsman < 6)
            {
                batting_num = batting_random();
            }

            else
            {
                batting_num = Bowler_random();
            }

            total_number_of_balls_1[i][j] = batting_num; // storing the data of each ball in 2-d array for team 1
            
            if(batting_num == 6)
            {
                number_of_6[FacingBall]+=1;
            }
            
            if(batting_num == 4)
            {
                number_of_4[FacingBall]+=1;
            }
            
            if (total_number_of_balls_1[i][j] != -1)
            {
                sum_for_runrate = sum_for_runrate + total_number_of_balls_1[i][j]; // calculation sum for run rate
            }

            if (batting_num != -1)
            {
                scoreTeam[FacingBall] = scoreTeam[FacingBall] + batting_num; // to calculate the total number of runs by a spefic player
            }

            run_rate = RunRate(sum_for_runrate, float_over_num);

            if (batting_num != -1)
            {

                LiveScoreCard(battingTeam, float_over_num, scoreTeam, bowlingTeam, run_rate, FacingBall, batting_num, number_of_ballers);
                average[FacingBall] = scoreTeam[FacingBall] / ((i + 1) * (j + 1));
            }

            if (batting_num > 0)
            {
                // i have to do sum
                if ((batting_num == 1) || (batting_num == 3) || (batting_num == 5)) // players switching
                {
                    shift = FacingBall;
                    FacingBall = just_standing_there;
                    just_standing_there = shift;
                }

                if (j == 5) // switching player after 1 over
                {
                    shift = FacingBall;
                    FacingBall = just_standing_there;
                    just_standing_there = shift;
                }
            }

            else // if -1 then player will be out
            {
                ++t_wickets;
                ++wicket_taken;
                Wickets_Taken[number_of_ballers] = wicket_taken;
                cout << "---------------------------------" << endl;
                cout << "|      "
                     << " \t \t \t|" << endl;
                cout << "|         " << battingTeam[FacingBall] << " is out \t \t|" << endl;
                cout << "|      "
                     << " \t \t \t|" << endl;
                cout << "|        His score is: " << scoreTeam[FacingBall] << " \t|" << endl;
                cout << "|      "
                     << " \t \t \t|" << endl;
                cout << "|        Bowler: " << bowlingTeam[number_of_ballers] << "\t \t|" << endl;
                cout << "---------------------------------" << endl;
                average[FacingBall] = float(scoreTeam[FacingBall]) / ((i + 1) * (j + 1));
                not_out_players[FacingBall] = "Out";
                if (FacingBall <= just_standing_there)
                {
                    FacingBall = just_standing_there;
                }

                FacingBall++;
                Wickets_Taken[number_of_ballers] = wicket_taken;
                if (t_wickets >= 10)
                {
                    break;
                }

                if (FacingBall == just_standing_there)
                {
                    FacingBall++;
                    if (t_wickets >= 10)
                    {
                        break;
                    }
                }
                cout << battingTeam[FacingBall] << " is entering the pitch " << endl;
                number_of_batsman = no_of_wichket(number_of_batsman); // these are number of batsman out
            }
        }
    }
}

void LetTheGameBegin(int toss, string team_1[], string team_2[], int number_of_overs)
{

    int BattingMen = 0;
    int **total_number_of_balls_1 = new int *[number_of_overs];

    for (int i = 0; i < number_of_overs; i++)
    {
        total_number_of_balls_1[i] = new int[6]; // will have 6 colums and many rows according to number of overs
    }

    for (int i = 0; i < number_of_overs; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total_number_of_balls_1[i][j] = 0;
        }
    }

    int **total_number_of_balls_2 = new int *[number_of_overs];
    for (int i = 0; i < number_of_overs; i++)
    {
        total_number_of_balls_2[i] = new int[6]; // will have 6 colums and many rows according to number of overs
    }

    for (int i = 0; i < number_of_overs; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total_number_of_balls_2[i][j] = 0;
        }
    }

    string battingTeam[11];                                 // batting team will be stored here
    string bowlingTeam[11];

    if (toss == 1)                            // so team 1 has won the match 
    {
        for (int i = 0; i < 11; i++)
        {
            battingTeam[i] = team_1[i];
            bowlingTeam[i] = team_2[i];
        }
    }
    else
    {
        for (int i = 0; i < 11; i++)
        {
            battingTeam[i] = team_2[i];
            bowlingTeam[i] = team_1[i];
        }
    }

    cout << battingTeam[0] << " " << battingTeam[1] << " will come for batting." << endl;          // dislaying the name of the 1st and second player 
    cout << battingTeam[0] << " will face ball first." << endl;
    cout << bowlingTeam[10] << " from Team 2 will ball first " << endl;               // from team 2 last bowler will come

    int number_of_batsman = 0;                  // no of batsman that are out 
    int scoreTeam[11] = {};
    int scoreTeam2[11] = {};                   // calcualte the score of a specific player 
    int sum_for_runrate = 0;                 
    float run_rate_1 = 0.0;   
    float run_rate_2 = 0.0;                
    float average[11];                               // to calculate the averhae run rate 
    float average2[11];
    int t_wickets = 0;
    int t_wickets2 = 0;
    int Wickets_Taken[11] = {};                           // to calculate the  number of the wickets that are out 
    int Wickets_Taken2[11] = {};
    string not_out_players[11];
    string not_out_players2[11];                                // string to score not out and out player 
    for (int i = 0; i < 11; i++)
    {
        not_out_players[i] = "Not Out";  // at the start all players are NOT OUT
        not_out_players2[i] = "Not Out"; // at the start all players are NOT OUT
    }

    int number_of_4_for_1[11] = {};
    int number_of_6_for_1[11] = {}; // here
    int number_of_4_for_2[11] = {};
    int number_of_6_for_2[11] = {};
    
    match(number_of_overs, bowlingTeam, total_number_of_balls_1, scoreTeam, battingTeam, Wickets_Taken, average, not_out_players, run_rate_1 , number_of_batsman, t_wickets, number_of_4_for_1, number_of_6_for_1);
    number_of_batsman = 0;

    cout << "****************Press Enter to start Second inning****************" << endl;
    getchar();

    match(number_of_overs, battingTeam, total_number_of_balls_1, scoreTeam2, bowlingTeam, Wickets_Taken2, average2, not_out_players2, run_rate_2, number_of_batsman, t_wickets2, number_of_4_for_2, number_of_6_for_2); // match function calling for team 2

    cout << "Press Enter to Display batting card and bowling card inning" << endl;
    getchar();

    system("clear");
    cout << "The scoreboard for team 1 " << endl;
    int team_1_result =  BattingBoard(battingTeam, bowlingTeam, not_out_players, scoreTeam,run_rate_1 , number_of_overs, average, t_wickets, number_of_4_for_1, number_of_6_for_1);
    Bowling_Board(bowlingTeam, Wickets_Taken);
    
    cout << endl;
    cout << endl;
    
    cout << "The scoreboard for team 2 " << endl;
    int team_2_result =  BattingBoard(bowlingTeam, battingTeam, not_out_players2, scoreTeam2,run_rate_2, number_of_overs, average2, t_wickets2, number_of_4_for_1, number_of_6_for_2);
    Bowling_Board(battingTeam, Wickets_Taken2);
    
    cout << "Press Enter to mover further" << endl;
    getchar();
    system("clear");
   cout << "Summary of the Match" << endl;
   cout << endl;
    if(team_1_result > team_2_result)
    {
        cout << "Team 1 has won the match. YAYAYYAYA" << endl;
        //ManOfTheMatch(scoreTeam,scoreTeam2,team_1, team_2);
        //BowlerOfTheMatch(Wickets_Taken, Wickets_Taken2,team_1, team_2);
    }
    
    else 
    {
       cout << "Team 2 has won the match. YAYAYAYAYYA" << endl;
      // ManOfTheMatch(scoreTeam,scoreTeam2, team_1, team_2);
      // BowlerOfTheMatch(Wickets_Taken,Wickets_Taken2,team_1, team_2);
    }
    
     ManOfTheMatch(scoreTeam,scoreTeam2, team_1, team_2);
     BowlerOfTheMatch(Wickets_Taken,Wickets_Taken2,team_1, team_2);
     
     
     cout << "***************    MATCH HAS ENDED    ***************" << endl;

}

int BattingBoard(string battingTeam[], string bowlingTeam[], string not_out_players[], int scoreTeam[], float run_rate, float number_of_overs, float average[], int number_of_batsman, int number_of_4[], int number_of_6[] )
{
    int sum_output = 0;
    sum_output = calculate_total_score(scoreTeam);

    cout << endl;
    cout << endl;
    cout << "Batting Board" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "|                                                                        " << endl;
    cout << "| Batting Team"
         << "\t"
         << "Out/Not-Out"
         << "\t"
         << "Score"
         << "\t"
         << "6s"
         << "\t"
         << "4s"
         << "\t"
         << "     Average" << endl;

    for (int i = 0; i < 11; i++)
    {
        cout << "| " << battingTeam[i] << "\t \t" << not_out_players[i] << "\t \t" << scoreTeam[i] << " \t" << number_of_6[i] << "\t"<< number_of_4[i]<<"\t \t" << average[i] << " \t \t" << endl;
    }
    cout << "| " << endl;
    cout << "| Run Rate: " << run_rate << endl;
    cout << "| Total Score: " << sum_output << endl;
    cout << "| Wickets: " << number_of_batsman << endl;
    cout << "--------------------------------------------------------------------" << endl;
    
    return sum_output;
}

void Bowling_Board(string bowlingTeam[], int Wickets_Taken[])
{

    cout << endl;
    cout << endl;
    cout << "Bowling Board" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "|                                                                        " << endl;
    cout << "| Batting Team"
         << "\t"
         << "Wickets Taken" << endl;

    for (int i = 10; i >= 0; i--)
    {
        cout << "| " << bowlingTeam[i] << "\t \t" << Wickets_Taken[i] << "\t \t" << endl;
    }
    cout << "| " << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void ManOfTheMatch(int scoreTeam[], int scoreTeam2[], string team_1[], string team_2[])
{
        int max_1 = scoreTeam[0];
        int max_2 = scoreTeam2[0];
        int max = 0;
        int store_index_1 = 0;
        int store_index_2 = 0;
        int index =0;
        int i;
        int j;
        for( i =1; i<11; i++)
        {
              if(scoreTeam[i] > max_1)
              {
                 max_1 = scoreTeam[i];
                 store_index_1 = i;
              }
        }
        
        for(j =1; j<11; j++)
        {
              if(scoreTeam2[j] > max_2)
              {
                 max_2 = scoreTeam2[j];
                 store_index_2 = j;
              }
        }
        
        if(max_2 > max_1)
        {
             index = store_index_2;
             cout << "Man of the match is " << team_2[index] << ", runs: " << scoreTeam2[index] << endl;
        }
        else 
        {
             index = store_index_1;
             cout << "Man of the match is " << team_1[index] << ", runs: " << scoreTeam[index] << endl;
        }

        
        
}
void BowlerOfTheMatch(int Wickets_Taken[] ,int Wickets_Taken2[],string team_1[], string team_2[])
{
         
        int max_1 = Wickets_Taken[0];
        int max_2 = Wickets_Taken2[0];
        int max = 0;
        int store_index_1 = 0;
        int store_index_2 = 0;
        int index =0;
        int i;
        int j;
        for( i =1; i<11; i++)
        {
              if(Wickets_Taken[i] > max_1)               //  comparing arrays and finding 
              {
                 max_1 = Wickets_Taken[i];
                 store_index_1 = i;
              }
        }
        
        for(j =1; j<11; j++)
        {
              if(Wickets_Taken2[j] > max_2)
              {
                 max_2 = Wickets_Taken2[j];
                 store_index_2 = j;
              }
        }
        
        if(max_2 > max_1)
        {
             index = store_index_2;
             cout << "Bowler of the match is " << team_2[index] << ", Wickets taken " << Wickets_Taken2[index] <<endl;
        }
        else 
        {
             index = store_index_1;
             cout << "Bowler of the match is " << team_1[index] << ", wickets taken: "<< Wickets_Taken[index] <<endl;
        }
}






















